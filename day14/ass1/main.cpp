#include <iostream>
#include <bitset>

struct Output {
    unsigned speed : 4;
    unsigned front : 3;
    unsigned rear : 3;
    unsigned left : 3;
    unsigned right: 3;
}__attribute__((packed));

struct CarStuff{
    unsigned light1 :1;
    unsigned light2 :1;
    unsigned light3 :1;
    unsigned doors1 :1;
    unsigned doors2 :1;
    unsigned doors3 :1;
    unsigned doors4 :1;
    unsigned windows1 :1;
    unsigned windows2 :1;
    unsigned windows3 :1;
    unsigned windows4 :1;
    unsigned seat1 :1;
    unsigned seat2 :1;
    unsigned seat3 :1;
    unsigned seat4 :1;
    unsigned seat5 :1;
    
}__attribute__((packed));

void readInfo(uint16_t info){
  /*   uint16_t seatMask = 0b1111100000000000;
    uint16_t windMask = 0b0000011110000000;
    uint16_t doorMask = 0b0000000001111000;
    uint16_t lightMask = 0b000000000000111; */
    auto i = reinterpret_cast<CarStuff*>(&info);
    std::cout << "Seat status "<< std::bitset<5>((info)>>11)<< std::endl;
    std::cout << "Window status "<< std::bitset<4>(info>>7)<< std::endl;
    std::cout << "Door status "<< std::bitset<4>(info>>3)<< std::endl;
    std::cout << "Light status "<< std::bitset<3>(info)<< std::endl;
    
    std::cout << std::boolalpha<< "Light status "<< bool(i->light1) << std::endl;
    std::cout << "Light status "<< i->light2 << std::endl;
    std::cout << "Light status "<< i->light3 << std::endl;
    std::cout << sizeof(i);
}

Output encode(unsigned int &speed, unsigned int &front, unsigned int &rear, unsigned int &left, unsigned int &right){
    Output out;
    out.speed = (speed/20);
    out.front = (front/150);
    out.rear = (rear/150);
    out.left = (left/150);
    out.right = (right/150);
    return out;
}

int main(){
    uint16_t info = 0b1011101001011011;
    readInfo(info);
    unsigned int a = 200;
    unsigned int b = 3000;
    unsigned int c = 900;
    Output o = encode(a,b,c,c,b);
    std::cout << sizeof(o)<< std::endl;
    std::cout << o.front << std::endl;
    std::cout << o.left << std::endl;
    std::cout << o.speed << std::endl;
    return 0;
}