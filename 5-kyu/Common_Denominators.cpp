#include <iostream>
#include <string>

class Fracts{

public:
  static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst);
  static unsigned long long GCD(unsigned long long n1, unsigned long long n2);
  static unsigned long long LCM(unsigned long long n1, unsigned long long n2);
  
};


std::string Fracts::convertFrac(std::vector<std::vector<unsigned long long>> &lst){
  
  unsigned long long lcm, temp;
  
  std:: string sol = "", temp_s = "";
  
  lcm = LCM(lst.at(0).at(1), lst.at(1).at(1));
  
  for(int i = 2; i < lst.size(); i++){
    lcm = LCM(lcm, lst.at(i).at(1));
  }
  
  for(int i = 0; i < lst.size(); i++){
    temp = lcm / lst.at(i).at(1);
    temp = lst.at(i).at(0)*temp;
    sol += "(";
    temp_s = std::to_string(temp);
    sol += temp_s;
    sol += ",";
    temp_s = std::to_string(lcm);
    sol += temp_s;
    sol += ")";
  }
  
  return sol;
  
}

unsigned long long Fracts::GCD(unsigned long long n1, unsigned long long n2){
  
  unsigned long long temp;
  
  if(n2 > n1){
    temp = n1;
    n1 = n2;
    n2 = temp;
  }
  
  while((n1 % n2) > 0){
    temp = n1 % n2;
    n1 = n2;
    n2 = temp;
  }
  
  return n2;
}

unsigned long long Fracts::LCM(unsigned long long n1, unsigned long long n2){
  
  return n1*n2 / GCD(n1,n2);
}