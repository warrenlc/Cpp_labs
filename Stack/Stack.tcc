#include "Stack.h"           

template <typename T>
Stack<T>::Stack() 
  : top{nullptr} {}

template <typename T>
Stack<T>::~Stack() {
  clear();
}

template <typename T>
Stack<T>::Stack(Stack<T> const& other) {
  if (other.top != nullptr) {
    this->top = new Node{other.top->data, nullptr};
    Node* tmp;
    Node* cur;

    for (tmp = this->top, cur = other.top->next;
         cur != nullptr;
         tmp = tmp->next, cur = cur->next) {
        tmp->next = new Node{cur->data, nullptr};
    }
  }
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack const& other) {
  Stack tmp{other};
  std::swap(top, tmp.top);
  return *this;
}

template <typename T>
void Stack<T>::push(T data) {
  if(top == nullptr) {
    top = new Node{data, nullptr};
  }
  else {
    Node *new_node{new Node{data, top}};
    top = new_node;
  }
}

template <typename T>
T Stack<T>::pop() {
  if (top != nullptr) {
    Node* temp{top};
    T data{temp->data};
    top = top->next;
    temp->next = nullptr;
    delete temp;
    return data;
  }
  else {
    throw std::range_error("Empty stack. Cannot pop");
    }
}

template<typename T>
void Stack<T>::print_stack(Stack* const stack)const {
  Node* temp{stack->top};
  std::cout << "Top";
  if (temp == nullptr) {
    std::cout << " --> nullptr\n";
  }
  else {
    while (temp != nullptr) {
        std::cout << " --> " << temp->data;
        temp = temp->next; 
    }
    std::cout << std::endl;
  }
}

template<typename T>
void Stack<T>::clear() {
  Node *current{top};
  while (current !=nullptr) {
    Node* next{current->next};
    delete current;
    current = next;
  }
  top = nullptr;
  current = nullptr;
}

template<typename T> 
Stack<typename T::value_type> make_stack(T const& container) {
    Stack<typename T::value_type> stack{};
    for (auto const& x : container) {
        stack.push(x);
    }
    return stack;
}

template<typename T>
Stack<typename T::value_type> make_stack(T* const& container) {
  Stack<typename T::value_type> stack{};
  for (auto const& x : container) {
    stack.push(x);
  }
  return stack;
}










