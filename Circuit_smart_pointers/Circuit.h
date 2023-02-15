#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

struct Connection {
        double volts; 
};

class Component  {
    
    protected:
        std::string name;
        shared_ptr<Connection> in; 
        shared_ptr<Connection> out;
        
    public:
        Component(std::string const& name, shared_ptr<Connection>& p, shared_ptr<Connection>& n);
        virtual ~Component();
        virtual void print()const;
        double get_voltage()const;                 
        virtual double get_current()const = 0;
        std::string get_name()const; 
        virtual void update(double const time) = 0; 
};

class Battery : public Component { 

    private:
        double volt;
        double current;

    public:
        Battery(std::string const& name, double charge, shared_ptr<Connection>& p, shared_ptr<Connection>& n);       
        ~Battery() ;
        void update(double const) override;
        double get_current()const override;
};

class Resistor : public Component {

    private:
        double ohm;
        double current;

    public:
        Resistor(std::string const& name, double ohm, shared_ptr<Connection>& p, shared_ptr<Connection>& n);
        ~Resistor(); 
        double get_ohm() const;
        double get_current()const override;
        void update(double const time) override; 
};

class Capacitor : public Component {

    private:
        double farad;
        double storage;
    public:
        Capacitor(std::string const& name, double farad, shared_ptr<Connection>& p, shared_ptr<Connection>& n);
        ~Capacitor(); 
        double get_farad() const;
        double get_storage() const;
        void update(double const time) override; 
        double get_current()const override;
};

#endif //CIRCUIT_H















































