#include <iostream>
#include "customer.hpp"
#include "Shop.hpp"

int main(){
    Shop s;
    Customer c1 = Customer("kalle",5);
    Customer c2 = Customer("dave",6);
    s.addCustomer(c1);
    s.addCustomer(c2);
    s.printCustomers();
    
    return 0;
}

