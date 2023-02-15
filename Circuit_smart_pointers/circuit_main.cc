#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>

#include "Circuit.h"

// Functions for running the simulation
 
void simulate(std::vector<shared_ptr<Component>>const& c, int iters, int print, double step);
void run_first_simulation(int, int, double, double);
void run_second_simulation(int, int, double, double);
void run_third_simulation(int, int, double, double);

using namespace std;

int main(int argc, char* argv[]) {                                                                                                      
     
     int run_iter{0};
     int print_iter{0};
     double time_interval{0};
     double battery_charge{0};
     
     if (argc != 5)  {
         std::cerr << "Must have 5 arguments! (including a.out)\n"
                   << "You entered " << argc
                   << " arguments."  << std::endl;
         return 1;
     }
     
     try {
         run_iter = std::stoi(argv[1]);
         print_iter = std::stoi(argv[2]);
         time_interval = std::stod(argv[3]);
         battery_charge = std::stod(argv[4]);
     }
     catch (std::invalid_argument const& int_error) {
         std::cerr << "Error!\n";
         std::cerr << "Entered arguments must be convertable to either int or double.\n";
         return 1;    
     }
  
     run_first_simulation(run_iter, print_iter, time_interval, battery_charge);
     std::cout << std::endl;
     
     run_second_simulation(run_iter, print_iter, time_interval, battery_charge);
     std::cout << std::endl;
     run_third_simulation(run_iter, print_iter, time_interval, battery_charge);
     std::cout << std::endl;
     return 0;
}

void simulate(std::vector<shared_ptr<Component>>const& c, int iters, int print, double step) {

    for (shared_ptr<Component> k : c) {
        std::cout.width(11); 
        std::cout << std::right 
                  << k->get_name(); 
        std::cout << "  ";
    }
    std::cout << std::endl; 
    for (long unsigned int i{0}; i < c.size(); ++i) {
        std::cout << std::setw(11) << std::right
                  << "Volt  Curr" << "  ";
    }

    std::cout << std::endl;
    int print_at{iters / print};
    for (int i{1}; i <= iters; ++i) {
        for (shared_ptr<Component> k : c) {
            k->update(step);     
            if (i % print_at == 0) {
                k->print();
            }
        }
        if (i % print_at == 0) {
            std::cout << std::endl;
        }
        
    }
}

void run_first_simulation(int run_iter, int print_iter, double time_interval, double batt_charge) {
    shared_ptr<Connection> p{new Connection()};
    shared_ptr<Connection> n{new Connection()};
    shared_ptr<Connection> r124{new Connection()};
    shared_ptr<Connection> r23{new Connection()};

    std::vector<shared_ptr<Component>> circuit;

    circuit.push_back(shared_ptr<Component>(new Battery("Bat", batt_charge, p, n)));
    circuit.push_back(shared_ptr<Component>(new Resistor("R1", 6.0, p, r124)));
    circuit.push_back(shared_ptr<Component>(new Resistor("R2", 4.0, r124, r23)));
    circuit.push_back(shared_ptr<Component>(new Resistor("R3", 8.0, r23, n)));
    circuit.push_back(shared_ptr<Component>(new Resistor("R4", 12.0, r124, n)));

    simulate(circuit, run_iter, print_iter, time_interval); 
}

void run_second_simulation(int run_iter, int print_iter, double time_interval, double batt_charge) {
    shared_ptr<Connection> p{new Connection()};
    shared_ptr<Connection> n{new Connection()};
    shared_ptr<Connection> l{new Connection()};
    shared_ptr<Connection> r{new Connection()};
    
    
    std::vector<shared_ptr<Component>> circuit;
    
    circuit.push_back(shared_ptr<Component>(new Battery("Bat", batt_charge, p, n)));
    circuit.push_back(shared_ptr<Component>(new Resistor("R1", 150, p, l)));
    circuit.push_back(shared_ptr<Component>(new Resistor("R2", 50, p, r)));
    circuit.push_back(shared_ptr<Component>(new Resistor("R3", 100, r, l)));
    circuit.push_back(shared_ptr<Component>(new Resistor("R4", 300, l, n)));
    circuit.push_back(shared_ptr<Component>(new Resistor("R5", 250, n, r)));

    simulate(circuit, run_iter, print_iter, time_interval);
}

void run_third_simulation(int run_iter, int print_iter, double time_interval, double batt_charge) {
    shared_ptr<Connection> p{new Connection()};
    shared_ptr<Connection> r{new Connection()};
    shared_ptr<Connection> n{new Connection()};
    shared_ptr<Connection> l{new Connection()};

    std::vector<shared_ptr<Component>> circuit;
    circuit.push_back(shared_ptr<Component> (new Battery("Bat", batt_charge, p, n)));
    circuit.push_back(shared_ptr<Component> (new Resistor("R1", 150, p, l)));
    circuit.push_back(shared_ptr<Component> (new Resistor("R2", 50, p, r)));
    circuit.push_back(shared_ptr<Component> (new Capacitor("C3", 1.0, l, r)));
    circuit.push_back(shared_ptr<Component> (new Resistor("R4", 300, l, n)));
    circuit.push_back(shared_ptr<Component> (new Capacitor("C5", 0.75, n, r)));
   
    simulate(circuit, run_iter, print_iter, time_interval);
    
}
































