#ifndef CONSTP_HPP_
#define CONSTP_HPP_
#include <vector>
#include <iomanip>
#include <iostream>
#include <array>


typedef struct Cell
{
    int val = -1;
    std::vector<int> cand = {1,2,3,4,5,6,7,8,9};
}Cell_t;



class ConstP {
    
   
    public:
    std::array<std::array<Cell_t,9>,9> inner_state;
    ConstP(std::string _s);
    void print();
    bool removeBox(size_t i, size_t j);
    bool removeRow(size_t i, size_t j);
    bool removeCol(size_t i, size_t j);
    bool removeFromPeers(size_t i, size_t j);
    bool removeFromPeers(size_t i, size_t j, int num);
    void createInner(std::string s);
    void rule2();
    bool isValueUniqueInRow(size_t i, size_t j, int num);
    bool isValueUniqueInCol(size_t i, size_t j, int num);
    bool isValueUniqueInBox(size_t i, size_t j, int num);
    bool isValueInRow(size_t i,size_t j, int num);
    bool isValueInColumn(size_t i,size_t j, int num);
    bool isValueInBox(size_t i,size_t j, int num);
    bool isValidPlace(size_t i,size_t j, int num);
    
    private:
    
   
};




#endif