#include <stdlib.h>

long long *tribonacci(const long long signature[3], size_t n) {

  long long *arr = (long long*)malloc(sizeof(long long)*n);
  size_t i;
  
    arr[0] = signature[0];
    arr[1] = signature[1];
    arr[2] = signature[2];
    
    if(n == 0){
      return NULL;
    }
      
  for(i = 3; i<n; i++){
    arr[i] = arr[i-3] + arr[i-2] + arr[i-1];
  }
  
  return arr;
}