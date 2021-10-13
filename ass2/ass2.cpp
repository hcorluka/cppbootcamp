#include <iostream>


int main(){
    
    std::cout << "Enter a keynumber between 0-26" << std::endl;
    int key;
    std::cin >> key;
    std::cout << "Enter a text" << std::endl;
    std::string text;
    std::cin >> text;
    std::cout << std::endl;
    std::string decipher;
    for(size_t i = 0; i<text.length(); i++){
        char c = text[i] - key;
        
        if( c >= 'A' && c <= 'Z'){
            std::cout << c;
        } else if(c < 'A') {
            
            
            std::cout << char (c + ('Z'-'A') + 1 );
       
   
    }
     std::cout << std::endl;
}
}