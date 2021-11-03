#include "constP.hpp"

ConstP::ConstP(std::string _s) { createInner(_s); }

void ConstP::createInner(std::string _s) {
  for (auto m = 0; m < _s.size(); m++) {
    if (_s[m] != '.') {
      removeFromPeers(m/9,m%9,(_s[m] - '0'));
    }
  }
}

void ConstP::print() {
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
      std::cout << std::setw(10);
      if (inner_state[i][j].val > -1) {
        std::cout << inner_state[i][j].val;

      } else if (inner_state[i][j].cand.size() > 0 &&
                 inner_state[i][j].val == -1) {
        for (size_t k = 0; k < inner_state[i][j].cand.size(); k++) {
          std::cout << inner_state[i][j].cand.at(k);
        }
      }
      std::cout << ",";
    }
    std::cout << std::endl;
  }
}

bool ConstP::removeFromPeers(size_t i, size_t j) {
  
  
  bool ret = removeBox(i, j) && removeRow(i, j) && removeCol(i, j);
  if (ret) {
    rule2();
  }
  return ret;
}

bool ConstP::removeFromPeers(size_t i, size_t j, int num) {
  bool ret = isValidPlace(i,j,num);
  if(ret){
  inner_state[i][j].val = num;
  inner_state[i][j].cand.clear();
  ret = true;
  ret = removeBox(i, j) && removeRow(i, j) && removeCol(i, j);
  }
  if (ret) {
    rule2();
  }
  return ret;
}

bool ConstP::removeCol(size_t i, size_t j) {
  int num = inner_state[i][j].val;
  bool ret = true;
  for (size_t k = 0; k < 9; k++) {
    if ((j == k) || (inner_state[i][k].val > -1)) {
      continue;
    } else {
      for (size_t m = 0; m < inner_state[i][k].cand.size(); m++) {
        if (inner_state[i][k].cand.at(m) == num) {
          inner_state[i][k].cand.erase((inner_state[i][k].cand.begin() + m));
         
          if (inner_state[i][k].cand.size() == 1) {
              ret = removeFromPeers(i,k,inner_state[i][k].cand.at(0));
                       
          }
          
        }
      }
    }
  }
  return ret;
}

bool ConstP::removeRow(size_t i, size_t j) {
  bool ret = true;
  int num = inner_state[i][j].val;
  for (size_t k = 0; k < 9; k++) {
    if ((i == k) || (inner_state[k][j].val > -1)) {
      continue;
    } else {
      for (size_t m = 0; m < inner_state[k][j].cand.size(); m++) {
        if (inner_state[k][j].cand.at(m) == num) {
          inner_state[k][j].cand.erase(inner_state[k][j].cand.begin() + m);
          
          if (inner_state[k][j].cand.size() == 1) {
             ret =  removeFromPeers(k,j,inner_state[k][j].cand.at(0));
       
          }
          
        }
      }
    }
  }
  return ret;
}

bool ConstP::removeBox(size_t i, size_t j) {
  int iStart = i - i % 3;
  int jStart = j - j % 3;
  int num = inner_state[i][j].val;
  bool ret = true;
  for (size_t row = 0; row < 3; row++) {
    for (size_t col = 0; col < 3; col++) {
      if (inner_state[iStart + row][jStart + col].val > -1 ||(iStart + row == i) && (jStart + col == j)) {
        continue;
      } else {
        auto &is = inner_state[iStart + row][jStart + col];
        for (size_t m = 0; m < is.cand.size(); m++) {
          if (is.cand.at(m) == num) {
            is.cand.erase(is.cand.begin() + m);
            
            if (is.cand.size() == 1) {
                ret = removeFromPeers(iStart + row,jStart + col, is.cand.at(0));
          
            }
            
          }
          
        }
      }
    }
  }
  return ret;
}
bool ConstP::isValidPlace(size_t i, size_t j, int num) {
  return !isValueInBox(i, j, num) && !isValueInRow(i, j, num) &&
         !isValueInColumn(i, j, num);
}

bool ConstP::isValueInColumn(size_t i, size_t j, int num) {
  for (j = 0; j < 9; j++) {
    if (inner_state[i][j].val == num) {
      return true;
    }
  }
  return false;
}

bool ConstP::isValueInRow(size_t i, size_t j, int num) {
  for (i = 0; i < 9; i++) {
    if (inner_state[i][j].val == num) {
      return true;
    }
  }
  return false;
}

bool ConstP::isValueInBox(size_t i, size_t j, int num) {
  int iStart = i - i % 3;
  int jStart = j - j % 3;
  for (size_t row = 0; row < 3; row++) {
    for (size_t col = 0; col < 3; col++) {
      if (inner_state[iStart + row][jStart + col].val == num) {
        return true;
      }
    }
  }
  return false;
}

void ConstP::rule2() {
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
      if (inner_state[i][j].cand.size() > 0) {
        for (size_t n = 0; n < inner_state[i][j].cand.size(); n++) {
          int uni = inner_state[i][j].cand[n];
          if (isValueUniqueInBox(i, j, uni) || isValueUniqueInCol(i, j, uni) ||
              isValueUniqueInRow(i, j, uni)) {
              removeFromPeers(i,j,uni);

          }
        }
      }
    }
  }
}

bool ConstP::isValueUniqueInRow(size_t i, size_t j, int num) {
  for (size_t k = 0; k < 9; k++) {
    if (k == i) {
      continue;
    }
    if (inner_state[k][j].val == num) {
      return false;
    } else {
      for (size_t n = 0; n < inner_state[k][j].cand.size(); n++) {
        if (inner_state[k][j].cand[n] == num) {
          return false;
        }
      }
    }
  }
  return true;
}

bool ConstP::isValueUniqueInCol(size_t i, size_t j, int num) {
  for (size_t k = 0; k < 9; k++) {
    if (k == j) {
      continue;
    }
    if (inner_state[i][k].val == num) {
      return false;
    } else {
      for (size_t n = 0; n < inner_state[i][k].cand.size(); n++) {
        if (inner_state[i][k].cand[n] == num) {
          return false;
        }
      }
    }
  }
  return true;
}

bool ConstP::isValueUniqueInBox(size_t i, size_t j, int num) {
  int iStart = i - i % 3;
  int jStart = j - j % 3;
  for (size_t row = 0; row < 3; row++) {
    for (size_t col = 0; col < 3; col++) {
      if ((iStart + row == i) && (jStart + col == j)) {
        continue;
      }
      if (inner_state[iStart + row][jStart + col].val == num) {
        return false;
      } else {
        for (size_t n = 0;
             n < inner_state[iStart + row][jStart + col].cand.size(); n++) {
          if (inner_state[iStart + row][jStart + col].cand[n] == num) {
            return false;
          }
        }
      }
    }
  }
  return true;
}
