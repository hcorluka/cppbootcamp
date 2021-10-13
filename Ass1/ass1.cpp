#include <iostream>
#include <stdlib.h>


int main(){
    uint num;
    std::cout << "Enter a number" << std::endl;
    std::cin >> num;
    uint array [8][9][11];
    for (size_t i = 0 ;i < 8;i++){
        
        for(size_t j =0; j < 9; j++){

            for(size_t k = 0; k < 11; k++){
                array [i][j][k] = rand() % num;
                std::cout << array[i][j][k] << " ";

            }
            std::cout << std::endl;
        }
        std::cout << std::endl; 
    }
}