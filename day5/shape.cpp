#include "shape.hpp"
#include <iostream>

void Shape::print(){
    std::cout << "The area is "<< area << " and the perimeter is " << peri << std::endl;
}

bool Shape::operator <(const Shape &s){
    bool returnVal = false;
    if((this->area < s.area) || ((this->area == s.area) && (this->peri < s.peri))){
        returnVal = true;
    }
    return returnVal;
}

bool Shape::operator >(const Shape &s){
    bool returnVal = false;
    if((this->area > s.area) || (this->area == s.area && this->area > s.peri)){
        returnVal = true;
    }
    return returnVal;
}

bool Shape::operator==(const Shape &s){
    bool returnVal = false;
    if(this->area == s.area && this->peri == s.peri){
        returnVal = true;
    }
    return returnVal;
}

Shape::~Shape(){}