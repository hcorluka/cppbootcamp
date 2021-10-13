#ifndef SHOP_HPP_
#define SHOP_HPP_
#include "customer.hpp"
#include <vector>

class Shop {
private:
    std::vector<Customer> custs;
public:
    Shop(/* args */){}
    ~Shop(){}
    void addCustomer(Customer c);
    void printCustomers();
};
#endif

