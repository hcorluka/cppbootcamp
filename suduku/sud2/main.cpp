

#include <iomanip>
#include <iostream>
#include <vector>
typedef struct Cell {
  int val = -1;
  std::vector<int> cand{1, 2, 3, 4, 5, 6, 7, 8, 9};
} Cell_t;

Cell_t inner_state[9][9];
int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, {5, 2, 0, 0, 0, 0, 0, 0, 0},
                  {0, 8, 7, 0, 0, 0, 0, 3, 1}, {0, 0, 3, 0, 1, 0, 0, 8, 0},
                  {9, 0, 0, 8, 6, 3, 0, 0, 5}, {0, 5, 0, 0, 9, 0, 6, 0, 0},
                  {1, 3, 0, 0, 0, 0, 2, 5, 0}, {0, 0, 0, 0, 0, 0, 0, 7, 4},
                  {0, 0, 5, 2, 0, 6, 3, 0, 0}};
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
void removeBox(size_t i, size_t j);
void removeRow(size_t i, size_t j);
void removeCol(size_t i, size_t j);
void removeFromPeers(size_t i, size_t j);

void createInnerState() {
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
      if (grid[i][j]) {
        inner_state[i][j].cand = {};
        inner_state[i][j].val = grid[i][j];
      }
      if (inner_state[i][j].val > -1) {
        removeFromPeers(i, j);
      }
    }
  }
}

void removeFromPeers(size_t i, size_t j) {
  removeCol(i, j);
  removeRow(i, j);
  removeBox(i, j);
}

void print() {
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
      std::cout << std::setw(10);
      if (inner_state[i][j].val > -1) {
        std::cout << inner_state[i][j].val;
      }
      for (size_t k = 0; k < inner_state[i][j].cand.size(); k++) {
        std::cout << inner_state[i][j].cand.at(k);
      }
      std::cout << ",";
    }
    std::cout << std::endl;
  }
}
void removeCol(size_t i, size_t j) {
  int num = inner_state[i][j].val;
  for (size_t k = 0; k < 9; k++) {
    if ((j == k) || (inner_state[i][k].val > -1)) {
      continue;
    } else {
      for (size_t m = 0; m < inner_state[i][k].cand.size(); m++) {
        if (inner_state[i][k].cand.at(m) == num) {
          inner_state[i][k].cand.erase(inner_state[i][k].cand.begin() + m);
          if (inner_state[i][k].cand.size() == 1) {
            inner_state[i][k].val = inner_state[i][k].cand.at(0);
            inner_state[i][k].cand.clear();
            removeFromPeers(i, k);
          }
        }
      }
    }
  }
}

void removeRow(size_t i, size_t j) {
  int num = inner_state[i][j].val;
  for (size_t k = 0; k < 9; k++) {
    if ((i == k) || (inner_state[k][j].val > -1)) {
      continue;
    } else {
      for (size_t m = 0; m < inner_state[k][j].cand.size(); m++) {
        if (inner_state[k][j].cand.at(m) == num) {
          inner_state[k][j].cand.erase(inner_state[k][j].cand.begin() + m);
          if (inner_state[k][j].cand.size() == 1) {
            inner_state[k][j].val = inner_state[k][j].cand.at(0);
            inner_state[k][j].cand.clear();
            removeFromPeers(k, j);
          }
        }
      }
    }
  }
}

void removeBox(size_t i, size_t j) {
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
            if (inner_state[iStart + row][jStart + col].cand.size() == 1) {
              inner_state[iStart + row][jStart + col].val =
                  inner_state[iStart + row][jStart + col].cand.at(0);
              inner_state[iStart + row][jStart + col].cand.clear();
              removeFromPeers(iStart + row, jStart + col);
            }
          }
        }
      }
    }
  }
}

int main() {
  createInnerState();
  print();
}