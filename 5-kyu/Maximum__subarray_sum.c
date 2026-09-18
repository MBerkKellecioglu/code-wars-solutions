#include <stddef.h>

int maxSequence(const int* array, size_t n) {
  
  int max = 0, sum;
  size_t i;
  size_t j;
  
  if(n == 0){
    return 0;
  }
  
  for(i = 0; i < n - 1; i++){
    sum = array[i];
    for(j = i + 1; j < n; j++){
      sum = sum + array[j];
      if(sum > max){ 
         max = sum;
      }
    }
  }
  
  return max;

}