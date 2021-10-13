#include <iostream>

    int lowRange = 1;
    int highRange = 128;
    int mid = 64;
    char c;

void rangeChange (char c){
        
        if(c =='l'){
            highRange = mid;
            mid = ((highRange - lowRange)/2 + lowRange);

        }else if (c =='h'){
            lowRange = mid;
            mid = ((highRange - mid)/2 + lowRange );
        }
    }

int main(){

   
    std::cout << "Hi is your number 64 higher or lower" << std::endl;
    
    std::cin >> c;

    for (int i = 1 ; i < 7 ; i++){
        rangeChange(c);
        std::cout << "Hi is your number " << mid << " higher or lower" << std::endl;
        std::cin >> c;
        
        
    }
    if( c == 'h' ){
            mid++;
    }
     std::cout << "Hi is your number " << mid << std::endl;

    return 0;

}