#include <iostream>

bool isValueInColumn(int column, int num) {
    for (size_t i = 0; i < 9;i++){
        if(column[i]== num){
            return true;
        }
        
    }
    return false;
}

bool isValueInRow(int row, int num) {
    for (size_t i = 0; i < 9;i++){
        if(row[i]== num){
            return true;
        }
        
    }
    return false;
}
