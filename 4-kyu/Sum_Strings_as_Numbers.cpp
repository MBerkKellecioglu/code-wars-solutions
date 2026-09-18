#include <string>
#include <iostream>

std::string sum_strings(const std::string& a, const std::string& b){
  
  int sum, carry = 0;
  
  std::string sol, a_cpy, b_cpy;
  
  a_cpy = a;
  
  b_cpy = b;
  
  std::cout << a_cpy << std::endl;
  std::cout << b_cpy << std::endl;
  
  if(a_cpy.size() < b_cpy.size()){
    while(a_cpy.size() < b_cpy.size()) a_cpy.insert(0, "0");
    
  }
  else if(b_cpy.size() < a_cpy.size()){
    while(b_cpy.size() < a_cpy.size()) b_cpy.insert(0, "0");
  }
  
  for(int i = a_cpy.size() - 1; i >= 0; i--){
    sum = (a_cpy[i] - '0') + (b_cpy[i] - '0') + carry;
    if(sum >= 10){
      sum = sum % 10;
      carry = 1;
    }
    else{
      carry = 0;
    }
    sol.insert(0,std::to_string(sum));
  }
  
  if(carry == 1){
    sol.insert(0,"1");
  }
  
  return sol;
}