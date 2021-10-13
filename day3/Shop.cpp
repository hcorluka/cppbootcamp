#include <vector>
#include "customer.hpp"
#include "Shop.hpp"



void Shop::addCustomer(Customer c){
    custs.push_back(c);

}

void Shop::printCustomers(){
    for (size_t i = 0; i < custs.size(); i++){
        std::cout<< custs.at(i).name <<std::endl;
        
    }
    
}