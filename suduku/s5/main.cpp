#include "constP.hpp"
#include "bruteForce.hpp"
#include <chrono>

int main(){
    std::string s =  //"...8.....789.1...6.....61....7....5.5.87.93.4.4....2....32.....8...7.439.....1...";
                      //"..6.9.2.....7.2....9.5.8.7.9...3...675.....191...4...5.1.3.9.8....2.1.....9.8.1..";  
                     "85...24..72......9..4.........1.7..23.5...9...4...........8..7..17..........36.4.";
                     
                      //"..............3.85..1.2.......5.7.....4...1...9.......5......73..2.1........4...9";
                         
    auto start_time = std::chrono::high_resolution_clock::now();
    ConstP cp(s);
    
    
    
    cp.print();
    solve(cp);
    cp.print(); 
    auto end_time = std::chrono::high_resolution_clock::now();
   
    std::chrono::duration<double, std::milli> duration_time = end_time - start_time;
    std::cout << "sudoku solved in " << duration_time.count() << "ms"<< std::endl;
    return 0 ;
}