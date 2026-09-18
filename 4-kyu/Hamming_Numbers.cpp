#include <cstdint>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

uint64_t min(vector<uint64_t> v){
  
  uint64_t min = v[0], r_ind;
  
  for(int i = 0; i < 3; i++){
    if(min > v[i]){
      min = v[i];
      r_ind = i;
    }
  }
  
  return r_ind;
}



uint64_t hamber(int n){
  
  int ham_expos[3] = {0 , 0 , 0};
  
  int ham_prime[3] = {2, 3, 5}; 
  
  vector<uint64_t> ham_num(1,1);
  
  vector<uint64_t> find_min;
  
  int temp_index, k = 1;
  
  while(k < n){
    for(int i = 0; i < 3; i++) find_min.push_back(ham_prime[i] * ham_num[ham_expos[i]]);
    
    temp_index = min(find_min);
    
    ham_num.push_back(find_min[temp_index]);
    
    for(int i = 0; i < 3; i++){
      if(find_min[i] == find_min[temp_index]) ham_expos[i] += 1;
    }
    
    find_min.clear();
    
    k++;
  }
  
  return ham_num[ham_num.size() - 1];
  
}