#include "solver.hpp"

void createInnerState(){
for(size_t i = 0 ; i<9 ; i++){
    for (size_t j = 0; j<9; j++){
        if(grid[i][j]){
            inner_state[i][j].cand = {grid[i][j]};
        }
        if(inner_state[i][j].cand.size()==1){
            removeCol(i,j);
            removeRow(i,j);
            removeBox(i,j);
        }
        
    }
}
}

void print(){
    for(size_t i = 0 ; i<9 ; i++){
        for (size_t j = 0; j<9; j++){
            std::cout << std::setw(10);
            for (size_t k = 0; k < inner_state[i][j].cand.size(); k++)
            {
                
                std::cout << inner_state[i][j].cand.at(k);
            }
            std::cout <<",";
                        
        }
        std::cout <<std::endl;
    }
}
void removeCol(size_t i, size_t j){
    if(inner_state[i][j].cand.size()==1){
        int num = inner_state[i][j].cand.at(0);
        for(size_t k = 0 ; k < 9 ; k++){
            if ((j==k) ||(inner_state[i][k].cand.size()==1)){
                continue;
            }else{
                for(size_t m = 0; m < inner_state[i][k].cand.size();m++){
                    if(inner_state[i][k].cand.at(m)==num){
                        inner_state[i][k].cand.erase(inner_state[i][k].cand.begin() + m);
                    }
                }
            }
        }
    }
}
void removeRow(size_t i, size_t j){
    if(inner_state[i][j].cand.size()==1){
        int num = inner_state[i][j].cand.at(0);
        for(size_t k = 0 ; k < 9 ; k++){
            if ((i==k) ||(inner_state[k][j].cand.size()==1)){
                continue;
            }else{
                for(size_t m = 0; m < inner_state[k][j].cand.size();m++){
                    if(inner_state[k][j].cand.at(m)==num){
                        inner_state[k][j].cand.erase(inner_state[k][j].cand.begin() + m);
                    }
                }
            }
        }
    }
}

void removeBox(size_t i, size_t j){
    int iStart = i - i%3;
    int jStart = j - j%3;
    int num = inner_state[i][j].cand.at(0);
    for(size_t row =0; row < 3; row++){
        for(size_t col = 0; col <3 ;col++){
            if(inner_state[iStart+row][jStart+col].cand.size()==1){
                continue;
            }else{
                for(size_t m = 0; m < inner_state[iStart+row][jStart+col].cand.size();m++){
                    if(inner_state[iStart+row][jStart+col].cand.at(m)==num){
                        inner_state[iStart+row][jStart+col].cand.erase(inner_state[iStart+row][jStart+col].cand.begin() + m);
            }
        }

    }


    }

}
}
