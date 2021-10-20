#include <map>
#include <stdlib.h>
#include <iostream>
int main(){

   std::map<int , int > hist;

   for(size_t i=0 ; i<34; i++){
       hist[i]=0;
   } 
    for (size_t i = 0; i < 10000;i++){
        int num = rand()%34;
        for(auto & x : hist){
            if(x.first == num){
                x.second++;
            }
        }
    }
    for(auto & x : hist){
        std::cout<< x.first << " occured "<< x.second<< " times" <<std::endl;
    }

}