

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
typedef struct Cell {
  int val = -1;
  std::vector<int> cand{1, 2, 3, 4, 5, 6, 7, 8, 9};
} Cell_t;

std::vector<std::vector<Cell_t>> inner_state(9,std::vector<Cell_t>(9));
std::vector<std::vector<Cell_t>> inner_state2;

/* int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, {5, 2, 0, 0, 0, 0, 0, 0, 0},
                  {0, 8, 7, 0, 0, 0, 0, 3, 1}, {0, 0, 3, 0, 1, 0, 0, 8, 0},
                  {9, 0, 0, 8, 6, 3, 0, 0, 5}, {0, 5, 0, 0, 9, 0, 6, 0, 0},
                  {1, 3, 0, 0, 0, 0, 2, 5, 0}, {0, 0, 0, 0, 0, 0, 0, 7, 4},
                  {0, 0, 5, 2, 0, 6, 3, 0, 0}}; */
/* int grid[9][9] = {
                    {7, 0, 3, 1, 0, 0, 9, 0, 4},
                    {4, 0, 5, 0, 0, 0, 0, 7, 3},
                    {0, 2, 0, 3, 0, 4, 1, 0, 5},
                    {6, 7, 0, 0, 3, 0, 0, 8, 9},
                    {0, 3, 1, 6, 4, 0, 0, 5, 0},
                    {0, 0, 0, 0, 2, 0, 0, 1, 0},
                    {0, 0, 0, 4, 0, 0, 2, 0, 8},
                    {0, 0, 6, 2, 0, 8, 5, 0, 0},
                    {0, 0, 4, 7, 5, 0, 6, 9, 0}
                    };
 */
int grid [9][9] = 
{{8,5,0,0,0,2,4,0,0}, 
 {7,2,0,0,0,0,0,0,9},
 {0,0,4,0,0,0,0,0,0},
 {0,0,0,1,0,7,0,0,2},
 {3,0,5,0,0,0,9,0,0},
 {0,4,0,0,0,0,0,0,0},
 {0,0,0,0,8,0,0,7,0},
 {0,1,7,0,0,0,0,0,0},
 {0,0,0,0,3,6,0,4,0}};
  
/* int grid [9][9]=
{{0,0,6,0,9,0,2,0,0},
{0,0,0,7,0,2,0,0,0},
{0,9,0,5,0,8,0,7,0},
{9,0,0,0,3,0,0,0,6},
{7,5,0,0,0,0,0,1,9},
{1,0,0,0,4,0,0,0,5},
{0,1,0,3,0,9,0,8,0},
{0,0,0,2,0,1,0,0,0},
{0,0,9,0,8,0,1,0,0}}; */

/* 
int grid[9][9] = {
                    {7, 0, 3, 1, 0, 0, 9, 0, 4},
                    {4, 0, 5, 0, 0, 0, 0, 7, 3},
                    {0, 2, 0, 3, 0, 4, 1, 0, 5},
                    {6, 7, 0, 0, 3, 0, 0, 8, 9},
                    {0, 3, 1, 6, 4, 0, 0, 5, 0},
                    {0, 0, 0, 0, 2, 0, 0, 1, 0},
                    {0, 0, 0, 4, 0, 0, 2, 0, 8},
                    {0, 0, 6, 2, 0, 8, 5, 0, 0},
                    {0, 0, 4, 7, 5, 0, 6, 9, 0}
                    }; */



/* int grid[9][9] = {{0 ,0, 0, 0, 0, 5, 0, 8, 0},
{0 ,0 ,0 ,6 ,0 ,1 ,0 ,4 ,3},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0 ,1 ,0 ,5 ,0 ,0 ,0 ,0 ,0},
{0 ,0, 0, 1, 0, 6, 0, 0, 0},
{3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,5},
{5 ,3, 0, 0, 0, 0, 0, 6, 1},
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4},
{0 ,0, 0, 0, 0, 0, 0, 0, 0}}; */

bool removeBox(size_t i, size_t j);
bool removeRow(size_t i, size_t j);
bool removeCol(size_t i, size_t j);
bool removeFromPeers(size_t i, size_t j);
bool findNextUnassignedPlace(size_t &i, size_t &j);
bool solveSudoku();
bool isValueInRow(size_t i,size_t j, int num);
bool isValueInColumn(size_t i,size_t j, int num);
bool isValueInBox(size_t i,size_t j, int num);
bool isValidPlace(size_t i,size_t j, int num);
bool isValueUniqueInRow(size_t i, size_t j, int num);
bool isValueUniqueInCol(size_t i, size_t j, int num);
bool isValueUniqueInBox(size_t i, size_t j, int num);
void rule2();


void createInnerState() {
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
      if (grid[i][j]) {
        inner_state[i][j].cand.clear();
        inner_state[i][j].val = grid[i][j];
      }
      if (inner_state[i][j].val > -1) {
        removeFromPeers(i, j);
      }
    }
  }
}

void createInnerState2(std::string s){
  for(auto m =0 ; m< s.size(); m++){

        if(s[m]!='.'){
            //std::cout << s[m]<<std::endl;
            inner_state[(m/9)][(m%9)].val = s[m] - '0';
            inner_state[(m/9)][(m%9)].cand.clear();
            removeFromPeers(m/9 , m%9  );
        }
    }
}

bool removeFromPeers(size_t i, size_t j) {
 return removeBox(i, j) && removeRow(i, j) &&  removeCol(i, j) ;
  
  
}

void print() {
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
      std::cout << std::setw(10);
      if (inner_state[i][j].val > -1) {
        std::cout << inner_state[i][j].val;
        
      }else if(inner_state[i][j].cand.size()>0 && inner_state[i][j].val== -1 ){
      for (size_t k = 0; k < inner_state[i][j].cand.size(); k++) {
        std::cout << inner_state[i][j].cand.at(k);
      }}
      std::cout << ",";
    }
    std::cout << std::endl;
  }
}

void print2() {
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
      std::cout << std::setw(10);
      if (inner_state2[i][j].val > -1) {
        std::cout << inner_state2[i][j].val;
      }
      for (size_t k = 0; k < inner_state2[i][j].cand.size(); k++) {
        std::cout << inner_state2[i][j].cand.at(k);
      }
      std::cout << ",";
    }
    std::cout << std::endl;
  }
}

bool removeCol(size_t i, size_t j) {
  int num = inner_state[i][j].val;
  for (size_t k = 0; k < 9; k++) {
    if ( (j==k) ||(inner_state[i][k].val > -1)) {
      continue;
    } else{
      for (size_t m = 0; m < inner_state[i][k].cand.size(); m++) {
        if (inner_state[i][k].cand.at(m) == num) {
          
          inner_state[i][k].cand.erase((inner_state[i][k].cand.begin() + m));
          if (inner_state[i][k].cand.size() == 1 ) {
           if(isValidPlace(i,k,inner_state[i][k].cand.at(0))){
            inner_state[i][k].val = inner_state[i][k].cand.at(0);
            inner_state[i][k].cand.clear();
             return removeFromPeers(i, k);
            
           }
           return false;
          }
          rule2();
        /*  for(size_t n = 0; n < inner_state[i][k].cand.size(); n++){
            int uni = inner_state[i][k].cand[n];
            if(isValueUniqueInCol(i,k,uni) || isValueUniqueInRow(i,k,uni)|| isValueUniqueInBox(i,k,uni)){
              inner_state[i][k].val = uni;
              inner_state[i][k].cand.clear();
              return removeFromPeers(i,k);
            }
          } */
        }
      }
    }
  }
  return true;
}

bool removeRow(size_t i, size_t j) {
  int num = inner_state[i][j].val;
  for (size_t k = 0; k < 9; k++) {
    if ((i==k)|| (inner_state[k][j].val > -1)) {
      continue;
    } else  {
      for (size_t m = 0; m < inner_state[k][j].cand.size(); m++) {
        if (inner_state[k][j].cand.at(m) == num) {
          inner_state[k][j].cand.erase(inner_state[k][j].cand.begin() + m);
          if (inner_state[k][j].cand.size() == 1  ) {
           if(isValidPlace(k,j,inner_state[k][j].cand.at(0))){
            inner_state[k][j].val = inner_state[k][j].cand.at(0);
            inner_state[k][j].cand.clear();
            return removeFromPeers(k, j);
            
           }
          return false;
          }
          rule2();
          /* for(size_t n = 0; n < inner_state[k][j].cand.size(); n++){
            int uni = inner_state[k][j].cand[n];
            if(isValueUniqueInCol(k,j,uni) || isValueUniqueInRow(k,j,uni)|| isValueUniqueInBox(k,j,uni)){
              inner_state[k][j].val = uni;
              inner_state[k][j].cand.clear();
              return removeFromPeers(k,j);
            }
          } */
        }
      }
    }
  }
  return true;
}

bool removeBox(size_t i, size_t j) {
  int iStart = i - i % 3;
  int jStart = j - j % 3;
  int num = inner_state[i][j].val;
  for (size_t row = 0; row < 3; row++) {
    for (size_t col = 0; col < 3; col++) {
      if (inner_state[iStart + row][jStart + col].val > -1) {
        continue;
      } else {
        for (size_t m = 0;
             m < inner_state[iStart + row][jStart + col].cand.size(); m++) {
          if (inner_state[iStart + row][jStart + col].cand.at(m) == num) {
            inner_state[iStart + row][jStart + col].cand.erase(
                inner_state[iStart + row][jStart + col].cand.begin() + m);
            if (inner_state[iStart + row][jStart + col].cand.size() == 1 ){
             if(isValidPlace((iStart +row),(jStart+col),inner_state[iStart + row][jStart + col].cand.at(0))) {
              inner_state[iStart + row][jStart + col].val =
                  inner_state[iStart + row][jStart + col].cand.at(0);
              inner_state[iStart + row][jStart + col].cand.clear();
               return removeFromPeers(iStart + row, jStart + col);
              
              }
              return false;
            }
            rule2();
          /*  for(size_t n = 0; n < inner_state[iStart + row][jStart + col].cand.size();n++ ){
             int uni = inner_state[iStart + row][jStart + col].cand[n];
             if(isValueUniqueInBox(iStart + row,jStart + col,uni)||isValueUniqueInBox(iStart + row,jStart + col,uni)||isValueUniqueInBox(iStart + row,jStart + col,uni)){
               inner_state[iStart + row][jStart + col].val =uni;
               inner_state[iStart + row][jStart + col].cand.clear();
               return removeFromPeers(iStart + row,jStart + col);
             }
           } */
          }
        }
      }
    }
  }
  return true;
}

bool findNextUnassignedPlace(size_t &i, size_t &j){
  
  for(i = 0; i<9 ; i++){
    for(j = 0; j<9; j++){
      if(inner_state[i][j].val == -1){
        return true;
      }
    }
    
  }
/* /*   return false; */
/*     int k = -1;
    int m = -1;
    int candS = 10;
    for(i= 0; i<9 ; i++ ){
        for(j=0; j<9 ;j++){
           /* if(inner_state[i][j].val ==-1 && inner_state[i][j].cand.size()==2){ 
                
                return true;
           } */
/*             if(inner_state[i][j].val == -1 && inner_state[i][j].cand.size()<candS){
                k=i;
                m=j;
                candS =inner_state[i][j].cand.size();

            }
           
        }
    
    }
    
    
    if(k==-1 && m ==-1){
      return false;
    }else{
      i=k;
      j=m;
      return true;
    } */
    return false; 
} 

bool solveSudoku(){
    inner_state2 = inner_state;
    
    size_t i,j;
    int m = 0;
    if(!findNextUnassignedPlace(i,j)){
        return true;
    }
    for(size_t k=0 ; k  < inner_state[i][j].cand.size(); k++){
      if(isValidPlace(i,j,inner_state[i][j].cand.at(k))){
        /* std::vector<int> tmp; 
        tmp.push_back(inner_state[i][j].cand.at(k)); */
        //print();
        inner_state[i][j].val = inner_state[i][j].cand.at(k);
        inner_state[i][j].cand.clear();
        
        if(!removeFromPeers(i,j)){
          inner_state = inner_state2;
          /* inner_state[i][j].cand = inner_state2[i][j].cand;
          inner_state[i][j].val = inner_state2[i][j].val; */
          continue;
        }
        
            if(solveSudoku()){
            return true;
        }else{
        //tmp.erase(tmp.begin());
        inner_state = inner_state2;
        /* inner_state[i][j].cand = inner_state2[i][j].cand;
        inner_state[i][j].val = inner_state2[i][j].val; */
        }
        
       }
        
    }
    return false;
}
bool isValidPlace(size_t i,size_t j, int num){
    return !isValueInBox(i,j,num) && !isValueInRow(i,j,num)&& !isValueInColumn(i,j,num) ;
}

bool isValueInColumn(size_t i,size_t j,int num){
    for(j=0 ; j<9 ;j++){
        if(inner_state[i][j].val==num){
            return true;
        }
    }
    return false;
}

bool isValueInRow(size_t i,size_t j,int num){
    for(i=0 ; i<9;i++){
        if(inner_state[i][j].val==num){
            return true;
        }
    }
    return false;
}

bool isValueInBox(size_t i,size_t j, int num){
    int iStart = i - i%3;
    int jStart = j - j%3;
    for(size_t row = 0 ; row < 3; row++){
        for(size_t col = 0; col < 3; col++){
            if(inner_state[iStart+row][jStart+col].val==num){
                return true;
            }
        }
    }
    return false; 
}

bool isValueUniqueInRow(size_t i, size_t j, int num){
 
    for (size_t k=0 ; k <9 ; k++){
      if(k==i){
        continue;
      }
      if(inner_state[k][j].val==num){
        return false;
      }
      else{
        for(size_t n =0 ; n< inner_state[k][j].cand.size(); n++){
          if(inner_state[k][j].cand[n]==num){
            return false;
          }
        }
      }
    }
  return true;
}

bool isValueUniqueInCol(size_t i, size_t j, int num){
  
    for (size_t k=0 ; k <9 ; k++){
      if(k==j){
        continue;
      }
      if(inner_state[i][k].val == num){
        return false;
      }
      else{
        for(size_t n =0 ; n< inner_state[i][k].cand.size(); n++){
          if(inner_state[i][k].cand[n]== num){
            return false;
          }
        }
      }
    }
  return true;
}

bool isValueUniqueInBox(size_t i,size_t j, int num){
    int iStart = i - i%3;
    int jStart = j - j%3;
    for(size_t row = 0 ; row < 3; row++){
        for(size_t col = 0; col < 3; col++){
            if((iStart+row == i) && (jStart+col == j) ){
              continue;
            }
            if(inner_state[iStart+row][jStart+col].val==num){
                return false;
            }else{
              for(size_t n = 0; n<inner_state[iStart+row][jStart+col].cand.size();n++){
                if(inner_state[iStart+row][jStart+col].cand[n]==num){
                  return false;
                }
              }
            }
        }
    }
    return true; 
}

void rule2(){
  for(size_t i= 0; i < 9 ; i++){
    for(size_t j= 0;j<9 ; j++){
      if(inner_state[i][j].cand.size()>0){
        for(size_t n = 0; n< inner_state[i][j].cand.size();n++){
          int uni = inner_state[i][j].cand[n];
          if(isValueUniqueInBox(i,j,uni)||isValueUniqueInCol(i,j,uni)||isValueUniqueInRow(i,j,uni)){
            inner_state[i][j].val = uni;
            inner_state[i][j].cand.clear();
            removeFromPeers(i,j);
          }
        }
      }
    }
  }
  
}


int main() {
  //SORRY RASHID FOR THIS MESS !!!!!!!!!!!
  
  //std::string s = "7.31..9.44.5....73.2.3.41.567..3..89.3164..5.....2..1....4..2.8..62.85....475.69.";
  std::string s =   "..6.9.2.....7.2....9.5.8.7.9...3...675.....191...4...5.1.3.9.8....2.1.....9.8.1.."; 
   
  //createInnerState();
  createInnerState2(s);
  //inner_state2 = inner_state;
  print();
  /* rule2();
  print();
  rule2();
  print(); */
  //print2();
  //std::cout << solveSudoku() << std::endl;
   /* size_t a,b;
  std::cout << findNextUnassignedPlace(a,b) << " " << a << " " <<b;  */
  //print();
  //print2();
  return 0;
}