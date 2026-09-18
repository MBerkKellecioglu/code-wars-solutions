#include<math.h>


long long findNb(long long m){
  
  long long sum = 0, k = 0;
  
  long long temp;
  
  temp = m;
  
  while(k < temp){
    temp -= pow(k,3);
    if(temp == 0){
      return k;
    }
    k++;
  }
  
  return -1;

  
}