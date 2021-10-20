#include <set>
#include <stdlib.h>
#include <iostream>
int main (){

std::multiset<int> mult;
std::multiset<int>::iterator itlow,itup;

for(size_t i = 0; i<1024; i++){
    mult.insert(rand());
}
int num = rand();
std::cout<<"Random number " << num<<std::endl;
itlow = mult.lower_bound(num);
itup = mult.upper_bound(num);

std::cout << "Lower value " << *(--itlow)<< std::endl;
std::cout << "Upper value " << *itup << std::endl;

for (std::multiset<int>::iterator it=mult.begin(); it!=mult.end(); ++it)
    std::cout << ' ' << *it;

}