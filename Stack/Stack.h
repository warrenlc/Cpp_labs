#ifndef TEMP_STACK_H//STACK_H
#define TEMP_STACK_H//STACK_H

template <typename T> //Stack {
class Stack {
private:
  struct Node {
    T data;
    Node* next;
  };
    Node* top;

public:
  // Constructors // Destructors
  Stack();
  ~Stack();
  Stack(Stack const& other);
  Stack& operator=(Stack const& other);
  Stack(Stack&& other) = delete;
  Stack& operator=(Stack&& other) = delete;

  // Member functions
  void push(T data);
  T pop();
  void print_stack(Stack* const stack)const;
  void clear();
};

template<typename T>
Stack<typename T::value_type> make_stack(T const& container);



#include "Stack.tcc"
#endif













