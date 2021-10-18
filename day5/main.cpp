#include "shape.hpp"

int main(){

    
    Shape *circ1 = new Circle(5);
    Shape *circ2 =  new Circle(100);
    
    Shape *triang1 = new Triangle(2,23);
    Shape *triang2 = new Triangle(3,5);

    Shape *rectangle1 = new Rectangle(23,1);
    Shape *rectangle2 = new Rectangle(2,1);
    Shape *rectangle3 = new Rectangle(2,1);
    
    circ1->print();
    circ2->print();
    triang1->print();
    triang2->print();
    rectangle1->print();
    rectangle2->print();
    rectangle3->print();
    Shape *shapes [7] ={circ1,circ2,triang1,triang2,rectangle1,rectangle2,rectangle3};
    
    for (size_t i = 0; i < 7; i++) {
        for (size_t j = i + 1; j < 7; j++) {
            if (*shapes[i] > *shapes[j]) std::cout << i << " is greater than " << j << std::endl;
            if (*shapes[i] == *shapes[j]) std::cout << i << " is equal than " << j << std::endl;
            if (*shapes[i] < *shapes[j]) std::cout << i << " is less than " << j << std::endl;

        }    
    }
    for(size_t i=0;i<7;i++){
        delete shapes[i];
    }
    return 0;


}