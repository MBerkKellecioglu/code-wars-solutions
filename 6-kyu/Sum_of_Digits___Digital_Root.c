#include<stdio.h>

int recDigit(int p){
  
  int i;
  
  for(i = 0; p>9; i++){
    
    p = p / 10;
  }
  
  i = i + 1;
  
  return i;
}

int digital_root(int n){
  
  printf("%d\n",n);
  int i, k, sum=0,j;
  
  i = recDigit(n);
  
  if(n<10){
    return n;
  }
  
  for(j = 0; j<i; j++){
    k = n % 10;
    sum = k + sum;
    n = n / 10;
  }
  
  if(sum>9){
    while(sum>9){
      n = sum;
      sum = 0;
      i = recDigit(n);
      for(j = 0; j<i; j++){
        k = n % 10;
        sum = k + sum;
        n = n / 10;
      }
    }
  }
  
  return sum;
  
}