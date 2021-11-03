#include "bruteForce.hpp"

bool solve(ConstP &p){
    ConstP pc = p;
    size_t i,j;
    if(!findNextUnassignedPlace(i,j,pc)){
        return true;
    }
    
    for(size_t k = 0; k < pc.inner_state[i][j].cand.size(); k++){
        

        if(!pc.removeFromPeers(i,j,pc.inner_state[i][j].cand[k])){
            pc=p;
            continue;
        }
        if(solve(pc)){
            p=pc;
            return true;
        }else {
            pc = p;
            
        }
    }
    return false;
}









bool findNextUnassignedPlace(size_t &i, size_t &j, ConstP &pc){
  
 /*  for(i = 0; i<9 ; i++){
    for(j = 0; j<9; j++){
      if(pc.inner_state[i][j].val == -1){
        return true;
      }
    }
    
  } */
/* /*   return false; */
    int k = -1;
    int m = -1;
    int candS = 10;
    for(i= 0; i<9 ; i++ ){
        for(j=0; j<9 ;j++){
           if(pc.inner_state[i][j].val ==-1 && pc.inner_state[i][j].cand.size()==2){ 
                
                return true;
           }
           if(pc.inner_state[i][j].val == -1 && pc.inner_state[i][j].cand.size()<candS){
                k=i;
                m=j;
                candS =pc.inner_state[i][j].cand.size();

            }
           
        }
    
    }
    
    
    if(k==-1 && m ==-1){
      return false;
    }else{
      i=k;
      j=m;
      return true;
    } 
    return false; 
} 