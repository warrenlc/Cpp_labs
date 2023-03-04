#include "List.h"
#include <iostream>
//List constructors
List::List()
    : head{nullptr} {}

List::List(List const& rhs) :head{nullptr} { // Copy Constructor
    if (rhs.head != nullptr) {
        this->head = new Node{rhs.head->get_value(), nullptr};
        Node* tmp;
        Node* cur; 
        // loop over 'this' and rhs at same time
        for ( tmp = this->head, cur = rhs.head->get_next();
                cur != nullptr;
                tmp = tmp->get_next(), cur = cur->get_next()) {
            tmp->set_next(new Node{cur->get_value(), nullptr});
        }
    }
}

List& List::operator=(const List& other) { // Copy assignment operator
    List tmp{other};
    std::swap(head, tmp.head);
    return *this;
}

List::List(List && other) : List{} { // Move constructor
    std::swap( head, other.head);
}

List& List::operator=(List && other) { // Move assignment operator
    std::swap(head, other.head);
    return *this;
}

List::~List() { // Destructor
    clear();    
}

//List class member functions
bool List::is_empty() const {
    return head == nullptr;
}

void List::push(int val) { //adds val to 'front' of list
    this->head = new Node(val, this->head);
}

void List::push_back(int val) { //adds val to 'back' of list
    Node* tmp{head};
    if (head == nullptr) {
        head->set_next(new Node(val, nullptr));
        return;
    }
    
    while (tmp != nullptr) {
        tmp = (tmp)->get_next();
    }
    Node* node{new Node{val, nullptr}};
    node->set_next(nullptr);
    tmp = node;
}

int List::pop() { // removes last element from list
    int value{-1};
    if (head != nullptr) {
        value = head->get_value();
        Node* tmp{head};
        head = head->get_next();
        delete tmp;
    }
    else {
        throw std::range_error("Empty list. Cannot pop.");
    }
    return value;
}

int List::size()const{
    int size{0};
    for (Node* cur{head}; cur != nullptr; cur = cur->get_next()) {
        size++;
    }
    return size;
}

bool List::contains(int val)const {
    for (Node* cur{head}; cur != nullptr; cur = cur->get_next()) {
        if (cur->get_value() == val) {
            return true;
        }
    }
    return false;
}

int List::value_at(int index)const {
    if (is_empty()) {
        return -1;
    }
    int count{0};
    Node* cur{head};
    while (count != index) {
        cur = cur->get_next();
        count++;
    }
    return cur->get_value();
}

int List::index_of(int val)const {
    int index{0};
    for (Node* cur{head}; cur != nullptr; cur = cur->get_next()) {
        if (cur->get_value() == val) {
            return index;
        }
        index++;
    }
    return -1; // return -1 if the value is not found
}

void List::insert(int val) {
    if (is_empty() || value_at(0) >= val) {
        push(val);
        return;
    }
    Node* current{head};
    current->insert_between(val, head);
}

void List::print_list() const {
    if (head == nullptr) {
        std::cout << "{ }\n";
        return;
    }
    Node* cur{head};
    std::cout << "{ ";
    while (cur->get_next() != nullptr) {
        std::cout << cur->get_value() << ", ";
        cur = cur->get_next();
    }
    std::cout << cur->get_value() << " }\n";
}

void List::remove_at(int index) {
    if (index > size() - 1) {
        return;
    }
    if (index == 0) {          // removing first Node
        Node* tmp{head};
        head = head->get_next();
        delete tmp;
        return;
    }
    if (index == size() - 1) { // removing last Node
        Node* next_last{head};
        while (next_last->get_next()->get_next() != nullptr) {
            next_last = next_last->get_next();
        }
        delete next_last->get_next();
        next_last->set_next(nullptr);
        return;
    }
    else {
        int count{1};
        Node* cur{head};
        Node* n{cur->get_next()};
        while (count != index) {
            n = n->get_next();
            cur = cur->get_next();
            count++;
        }
        n = n->get_next();
        delete cur->get_next();
        cur->set_next(n);
    }
}

void List::clear() {
    while (head != nullptr) {
        Node* tmp{head};
        head = head->get_next();
        delete tmp;
    }
}

bool List::operator==(const List& rhs) const {
    Node* tmp{this->head};
    Node* cur{rhs.head};
    
    for (tmp = this->head, cur = rhs.head; 
            cur != nullptr; 
            tmp = tmp->get_next(), cur = cur->get_next() ) {   
        if (tmp->get_value() != cur->get_value()) {
                return false;
                }
        if (tmp->get_next() == nullptr && cur->get_next() != nullptr) {
            return false;
        }
        if (tmp->get_next() != nullptr && cur->get_next() == nullptr) {
            return false;
        }
            }   
    return true;
}

bool List::operator!=(const List& rhs) const {
    return !(operator==(rhs));
}

bool List::sorted()const { // Returns true if the list is sorted
    int iter{size()};
    for (int i{0}; i < iter-1; ++i) {
        if ( value_at(i) > value_at(i + 1) ) {
            return false;
        } 
    }
    return true;
}

// Node class definitions

// Node constructor
List::Node::Node(int v, List::Node* n=nullptr)
    :value{v}, next{n}{}

// Node member functions
List::Node* List::Node::get_next() const{
    return next;
}

int List::Node::get_value() const{
    return value;
}

void List::Node::set_next(List::Node* n) {
    next = n;
}

void List::Node::insert_between(int x, List::Node* current) {
    // Recursively insert Node between two other Nodes
    if (current->next == nullptr) {
        Node* k{new List::Node(x)};
        current->next = k;
    }
    else {
        Node* tmp{current->next};
        if (current->value <= x && x <= current->next->value) {
            Node* k{new List::Node(x)};
            k->next = tmp;
            current->next = k;
       }
        else {
            insert_between(x, current->next);
        }
    }
}

