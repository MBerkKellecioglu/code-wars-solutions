#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

size_t get_count(const char *s){
  
  int i;
  int count = 0;
  
  for(i = 0; i<strlen(s); i++){
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
      count++;
    }
  }
  
  return count;

}