#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *rot13(const char *src){
  
  int temp, temp2;
  size_t i;
  
  char *arr = (char *)malloc(sizeof(char)*strlen(src));
  strcpy(arr,src);
  

  for(i = 0; i < strlen(src); i++){
    if('a' <= arr[i] && 'z' >= arr[i]){
      if(arr[i] + 13 > 'z'){
        temp = 'z' - arr[i];
        temp2 = 13 - temp;
        arr[i] = 'a' + temp2 - 1;
      }
      else{
        arr[i] = arr[i] + 13;
      }
    }
    if('A' <= arr[i] && 'Z' >= arr[i]){
      if(arr[i] + 13 > 'Z'){
        temp = 'Z' - arr[i];
        temp2 = 13 - temp;
        arr[i] = 'A' + temp2 - 1;
      }
      else{
        arr[i] = arr[i] + 13;
      }
    }
  }
  
  return arr;
}