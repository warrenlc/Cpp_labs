#include "Circuit.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Component
Component::Component(std::string const& name, shared_ptr<Connection>& i, shared_ptr<Connection>& o)
    : name{name}, in{i}, out{o} {}

std::string Component::get_name()const {
    return name;
}

Component::~Component() {}

double Component::get_voltage()const {
    return std::abs(in->volts - out->volts);
}

void Component::print()const {
    std::cout << std::fixed << std::right 
              << std::setw(5) << std::setprecision(2)
              << get_voltage() << "  " 
              << get_current() << "  "; 
}

// Battery
Battery::Battery(std::string const& name, double volt, shared_ptr<Connection>& i, shared_ptr<Connection>& o)
    : Component{name, i, o},  volt{volt} {
        in->volts = volt;
        out->volts = 0;
        current = 0;
    }

Battery::~Battery() {}

double Battery::get_current()const {
    return current;
}

void Battery::update(double const) {
    in->volts = volt;   
    out->volts = 0.0;
}

// Resistor
Resistor::Resistor(std::string const& name, double ohm, shared_ptr<Connection>& i, shared_ptr<Connection>& o)
    : Component{name, i, o}, ohm{ohm} {}

Resistor::~Resistor() {}

void Resistor::update(double const time) {
    double diff{std::abs(in->volts - out->volts)};
    if (diff < 0) {
        diff = -1.0 * diff;
    }

    double to_move{(diff / ohm) * time};  
    if (in->volts > out->volts) {
        in->volts -= to_move;
        out->volts += to_move;
    }
    else {
        out->volts -= to_move;
        in->volts += to_move;
    }
}

double Resistor::get_ohm() const {
    return ohm;
}

double Resistor::get_current()const {
    return get_voltage() / ohm;
}

// Capacitor

Capacitor::Capacitor(std::string const& name, double farad, shared_ptr<Connection>& i, shared_ptr<Connection>& o)
    : Component{name, i, o}, farad{farad} {
        storage = 0.0;
    }

Capacitor::~Capacitor() {}

double Capacitor::get_farad() const{
    return farad;
}

double Capacitor::get_storage() const{
   return storage; 
}

void Capacitor::update(double const time) {
    double diff{in->volts - out->volts};
    if (diff < 0) {
        diff = -1.0 * diff;
    }
    double to_move{get_farad() * 
                  (diff - storage) * 
                   time};
    
    if (in->volts > out->volts) {
        in->volts -= to_move;
        out->volts += to_move;
    
    }
    else {
        in->volts += to_move;
        out->volts -= to_move;
    }
    storage += to_move;
}


double Capacitor::get_current()const {
    return farad * (std::abs(get_voltage() - storage));
}


