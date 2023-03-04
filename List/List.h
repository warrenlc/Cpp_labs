#ifndef LIST_H
#define LIST_H

class List {

    private:
        class Node; // Forward declare Node class
        Node* head;
    public: 
        // Constructors and Destructor
        List();
        List(const List& other);
        List(List&& other);
        List& operator=(const List& other);
        List& operator=(List&& other);
        ~List();
        
        // Member functions
        bool is_empty() const;
        void push(int val);
        void push_back(int val);
        int pop();
        int size()const;
        bool contains(int val)const;
        int value_at(int index)const;
        int index_of(int val)const;
        void insert(int val);
        void print_list()const;
        void remove_at(int index);
        void clear();
        bool operator==(const List& rhs) const;
        bool operator!=(const List& rhs) const;
        
        /* Functions below are used for testing. 
            The list is sorted, but after implementation
            of insert() function, in order to check if the
            sorting functionality is working properly, It
            was worthwhile to check if a list is sorted.
            Normally I would label such a function as private
            but then access in list_test.cc would be prohbited.
            */
        bool sorted()const;
        
    private:

        class Node {
            
            private:
                int value;
                Node* next;
            
            public:
                // Constructor
                Node(int v, Node* n);
                
                // Member functions
                Node* get_next() const;
                int get_value() const;
                void set_next(Node* n);
                void insert_between(int val, Node* current);
        };
};
#endif // LIST_H

