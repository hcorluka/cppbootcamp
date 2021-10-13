#include <iostream>
#include <stdlib.h>

int main(){
    unsigned int y;
    unsigned int z;
    unsigned int x;
    unsigned int r;
    std::cout << "Enter x size of array" << std::endl;
    std::cin >> x;

    std::cout << "Enter y size of array" << std::endl;
    std::cin >> y;

    std::cout << "Enter z size of array" << std::endl;
    std::cin >> z;
   
    std::cout << "Enter size of random number" << std::endl;
    std::cin >> r;
   
   
   
    unsigned int ***Array3D = new unsigned int **[x];
    for (size_t i = 0 ; i < x ; i ++) {
        Array3D[i] = new unsigned int *[y];
        for (size_t j = 0; j <y; j++){
            Array3D[i][j] = new unsigned int [z];
            for(size_t k = 0; k < z; k++){
                *(*(*(Array3D+i)+j)+k) = rand()%r;
                std::cout << Array3D[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    for (size_t i = 0 ; i < x ; i ++) {
        
        for (size_t j = 0; j <y; j++){
           delete[] Array3D[i][j]; 
            
            
        }
        delete[] Array3D[i];
    }
    delete[] Array3D;

return 0;

}