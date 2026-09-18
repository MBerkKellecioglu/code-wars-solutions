#include<stdio.h>

int persistence(int n){
  
  int sum = 1, count = 0;
  
  if(n < 10){
    return 0;
  }
  
  while(n > 0){
    sum *= n % 10;
    n /= 10;
  }
  
  n = sum;
  
  count++;
  
  if(n > 9){
    while(sum >9){
      n = sum;
      sum = 1;
      count++;
      while(n > 0){
        sum*= (n % 10);
        n/= 10;
      }
    }
  }
  
  return count;
  
}