#ifndef SHAPE_HPP_
#define SHAPE_HPP_
#include <iostream>
#include <cmath>

class Shape {
    protected:
        int area, peri;
        
    public:
        Shape () {}
        virtual ~Shape() = 0;
        void print(); 
        bool operator <(const Shape &s);
        bool operator >(const Shape &s);
        bool operator ==(const Shape &s);
};

class Circle : public Shape {

    public:
        Circle(int r){area = r*r*3 , peri= 2*r*3;}
        ~Circle() = default;
};

class Triangle : public Shape{
    public:
        Triangle(int side , int height){area = side*height/2, peri = 3*side;}
        ~Triangle() = default;
};

class Rectangle : public Shape {

    public:
        Rectangle(int a, int b ){area = a*b, peri = 2*a+ 2*b;}
        ~Rectangle() = default;
};

class Square : public Shape {

    public:
        Square(int a){area = a*a, peri = 4*a;}
        ~Square() = default;
};
#endif