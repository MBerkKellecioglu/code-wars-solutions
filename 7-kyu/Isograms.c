#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool IsIsogram (const char *string) 
{
  size_t i,j;
  
  char arr[100];
  
  strcpy(arr,string);
  
  for(i = 0; i<strlen(arr) + 1; i++){
    arr[i] = tolower(arr[i]);
  }
  
  for(i = 0; i<strlen(arr); i++)
    for(j = i + 1; j<strlen(arr) + 1; j++){
      if(arr[i] == arr[j]){
        return false;
      }
      
    }
  return true;
}