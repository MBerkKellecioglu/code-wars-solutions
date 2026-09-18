#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool is_pangram(const char *str_in){
  
  size_t i;
  size_t j;
  
  char *doub = (char*)malloc(sizeof(char)*strlen(str_in));
  
  int arr[26][2];
  
  int k = 97;
  
  
  for(i = 0; i<strlen(str_in); i++){
    doub[i] = tolower(str_in[i]);
  }
  
  for(i = 0; i < 26; i++){
    arr[i][0] = k;
    arr[i][1] = 0;
    k++;
  }
  
  for(i = 0; i<strlen(str_in); i++){
    for(j = 0; j < 26; j++){
      if(doub[i] == arr[j][0]){
        arr[j][1] = 1;
      }
    }
  }
  
  for(i = 0; i < 26; i++){
    if(arr[i][1] == 0){
      return false;
    }
  }
  
  return true;
}