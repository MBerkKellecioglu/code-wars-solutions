#include <stdlib.h>
#include <math.h>

int whatkind(const int *arr){
  int i, count = 0;
  
  for(i = 0; i<3; i++){
    if(abs(arr[i] % 2) == 1){
      count++;
    }
  }
  
  if(count>=2){
    return 1;
  }
  else{
    return 0;
  }
  
}

int find_outlier(const int *values, size_t count){
  
  int value;
  size_t i;
  
  
  
  if(whatkind(values)){
    for(i = 0; i<count; i++){
      if(values[i] % 2 == 0){
        value = values[i];
      }
    }
  }
  else{
    for(i = 0; i<count; i++){
      if(abs(values[i] % 2) == 1){
        value = values[i];
      }
    }
  }
  
  return value;
}