#include<string.h>
#include<stdio.h>
#include<stdlib.h>

char* printerError(char *s) {
    
  unsigned long i;
  int count = 0;
  int count2 = 0;
  
  char *arr2 = (char*)malloc(sizeof(char)*60);
  
  strcpy(arr2, s);
  
  for(i = 0; i<strlen(arr2); i++){
    if(arr2[i]> 'm'){
      printf("%c", arr2[i]);
      count++;
    }
    count2++;
  }

  char *arr = (char*)malloc(sizeof(char)*100);
  
  sprintf(arr,"%d/%d", count, count2);
  
  return arr;
  
}