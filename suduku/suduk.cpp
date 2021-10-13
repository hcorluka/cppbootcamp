#include <iostream>
//int column[] ={1,2,0,4,5,6,7,8,9};
//int row[]  ={1,0,3,4,5,6,7,8,9};
bool isValueInColumn(int col,int num);
bool isValueInRow(int row,int num);
bool isValueInBox(int boxStartRow,int boxStartCol,int num);
void printGrid();
bool findEmptyPlace(int &row, int &col);
bool isValidPlace(int row, int col, int num);
bool solveSudoku();
int grid[9][9] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

int main(){

   /*  std::cout << isValueInColumn(2,3) << std::endl;
    std::cout << isValueInColumn(3,3) << std::endl; */
    std::cout << isValueInBox(0,3,8) << std::endl;
    std::cout << isValueInBox(0,3,2) << std::endl;
    printGrid();
    //std::cout << findEmptyPlace(0,0) << std::endl;
}
bool isValueInColumn(int col,int num) {
    for (size_t row = 0; row < 9;row++){
        if(grid[row][col] == num){
            return true;
        }
        
    }
    return false;
}

bool isValueInRow(int row, int num) {
    for (size_t col = 0; col < 9;col++){
        if(grid[row][col] == num){
            return true;
        }
        
    }
    return false;
}
bool isValueInBox(int boxStartRow,int boxStartCol,int num){
    for(size_t row = 0; row < 3;row++){
            
        for(size_t col = 0; col < 3;col++){
            if(grid[boxStartRow+row][boxStartCol+col]==num){
                return true;
            }
        }
    }
    return false;
}
void printGrid(){
    for(size_t row=0; row < 9; row++){
        for(size_t col = 0; col < 9; col++){
            std::cout << grid[row][col] << " ";
            if(col == 2||col== 5){
                std::cout<<"| ";
            }
            if(col == 8){
                std::cout << std::endl;
            }
        }
       if(row == 2||row == 5){
           std::cout<<"---------------------"<<std::endl;
       } 
    }
}
bool findEmptyPlace(int &row, int &col){
    for(row = 0; row < 9; row++){
        for(col = 0; col < 9; col++){
            if(grid[row][col] == 0){
                return true;
            }
        }
    }
    return false;
}
bool isValidPlace(int row, int col, int num){
    return !isValueInRow(row,num) && !isValueInColumn(col,num) && !isValueInBox((row-row%3),(col - col%3),num);                                
}
bool solveSudoku(){
    int row {0};
    int col {0};
    if(!findEmptyPlace(row,col)){
        return true;
    }
    for(int n = 1; n <= 9; n++){

    }
}