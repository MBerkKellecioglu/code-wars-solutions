#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *factors(int lst){
  
  int count = 0;
  int i;
  char temparr[100];
  
  char *arr = (char*)malloc(sizeof(char) * 200);
  
  
  
  for(i = 2; i<=lst; i++){
    count = 0;
      while(lst % i == 0){
        count++;
        lst = lst / i;    
      }
      if(count == 1){
        sprintf(temparr,"(%d)",i);
        strcat(arr,temparr);
      }
      if(count>1){
      	sprintf(temparr,"(%d**%d)", i, count);
        strcat(arr,temparr);
      }
    }
   
  
  return arr;
}