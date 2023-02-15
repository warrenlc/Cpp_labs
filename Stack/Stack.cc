#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include "Stack.h"


// Declarations for testing/display functions
void vector_int_test();
void vector_string_test();
void vector_double_test();
void list_int_test();
void list_string_test();
void list_double_test();
void deque_string_test();
void simple_operations();


// Main Function
int main() {
  vector_int_test();
  vector_string_test();
  vector_double_test();
  list_int_test();
  list_string_test();
  list_double_test();
  deque_string_test();
  return 0;
}


// Definitions for testing/display functions
void vector_int_test(){
  std::cout << "std::vector<int>\n";
  std::vector<int> v;
  v.push_back(3);
  v.push_back(4);

  Stack<int> stack{make_stack(v)};
  stack.print_stack(&stack);
  std::cout << std::endl;
  std::cout << "pop: \n";
  stack.pop();
  stack.print_stack(&stack);
  std::cout << std::endl;
}

void vector_string_test() {
  std::cout << "std::vector<std::string>\n";
  std::vector<std::string> s;
  s.push_back("Nelly");
  s.push_back("Tove");
  s.push_back("Warren");
  Stack<std::string> string_stack{make_stack(s)};
  string_stack.print_stack(&string_stack);
  std::cout << std::endl;
  std::cout << "pop:\n";
  string_stack.pop();
  string_stack.print_stack(&string_stack);
  std::cout << std::endl;
}

void vector_double_test() {
  std::cout << "std::vector<double>\n";
  std::vector<double> real;
  real.push_back(3.14159);
  real.push_back(2.71828);
  real.push_back(1.41428);
  Stack<double> double_stack{make_stack(real)};
  double_stack.print_stack(&double_stack);
  std::cout << std::endl;
  std::cout << "pop\n";
  double_stack.pop();
  double_stack.print_stack(&double_stack);
  std::cout << std::endl;
  
}

void list_int_test() {
  std::cout << "std::list<int>\n";
  std::list<int> primes;
  primes.push_back(31);
  primes.push_back(37);
  primes.push_back(41);
  Stack<int> prime_stack{make_stack(primes)};
  prime_stack.print_stack(&prime_stack);
  std::cout << std::endl;
  std::cout << "pop\n";
  prime_stack.pop();
  prime_stack.print_stack(&prime_stack);
  std::cout << std::endl;

}

void list_string_test() {
  std::cout << "std::list<std::string>\n";
  std::list<std::string> cities;
  cities.push_back("Stockholm");
  cities.push_back("Oslo");
  cities.push_back("Köpenhamn");
  Stack<std::string> city_stack{make_stack(cities)};
  city_stack.print_stack(&city_stack);
  std::cout << std::endl;
  std::cout << "pop: \n";
  city_stack.pop();
  city_stack.print_stack(&city_stack);
  std::cout << std::endl;
}

void list_double_test() {
  std::cout << "std::list<double>\n";
  std::list<double> doubles;
  doubles.push_back(3.234234234);
  doubles.push_back(4.2987234);
  doubles.push_back(12312.123123123123123);
  Stack<double> stacky{make_stack(doubles)};
  stacky.print_stack(&stacky);
  std::cout << std::endl;
  std::cout << "pop: \n";
  stacky.pop();
  stacky.print_stack(&stacky);
  std::cout << std::endl;
}

void deque_string_test() {
  std::cout << "std::deque<std::string>\n";
  std::deque<std::string> kings;
  kings.push_front("King of Spades");
  kings.push_front("King of Hearts");
  kings.push_front("King of Clubs");
  kings.push_front("King of Diamonds");
  Stack<std::string> king_stack{make_stack(kings)};
  king_stack.print_stack(&king_stack);
  std::cout << "pop: " << std::endl;
  king_stack.pop();
  king_stack.print_stack(&king_stack);
  std::cout << std::endl;
}

