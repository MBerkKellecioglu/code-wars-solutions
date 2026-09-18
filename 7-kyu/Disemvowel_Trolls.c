#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *disemvowel(const char *str){
  
  char *arr = (char*)malloc(sizeof(char)*strlen(str));
  
  int j = 0;
  
  size_t i;
  
  for(i = 0; i < strlen(str); i++){
    if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' &&str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'O' && str[i] != 'U' && str[i] != 'I'){
      arr[j] = str[i];
      j++;
    }
  }
  
  arr[j] = '\0';
  
  return arr;
}