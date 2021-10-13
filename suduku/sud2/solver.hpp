#ifndef SOLVER_HPP_
#define SOLVER_HPP_
#include <iomanip>
#include <iostream>
#include <vector>

typedef struct Cell{
   std::vector<int> cand {1,2,3,4,5,6,7,8,9};
}Cell_t;

void removeBox(size_t i, size_t j);
void removeRow(size_t i, size_t j);
void removeCol(size_t i, size_t j);
void print();
void createInnerSt();


#endif