#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_
#include <iostream>


class Customer {
    
    public:
        Customer();
        Customer(std::string _name, int _ssn):name(_name),ssn(_ssn){}
        std::string name;
    private:
        
        int ssn;
    

};

#endif