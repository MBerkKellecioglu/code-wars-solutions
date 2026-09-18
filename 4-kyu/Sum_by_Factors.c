#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prime(int k){
  int i;
  if(k == 2){
    return 1;
  }
  for(i = 2; i<k; i++){
    if(k % i == 0){
      return 0;
    }
  }
  
  return 1;
}

char* sumOfDivided(int* lst, int l){
  
  int i, j, temp, size = 0, tempsum = 0, flag, count = 0, newsize;
  
  int *arr = (int*)malloc(sizeof(int)*1000000000);
  
  int *nondup = (int*)malloc(sizeof(int)*10000000);
  
  char *cha = (char*)malloc(sizeof(char)*10000);
  
  char *tempc = (char*)malloc(sizeof(char)*100);
  
  char *ky = (char*)malloc(sizeof(char));
  
  int *temparr = (int*)malloc(sizeof(int)*l);  
  
  for(i = 0; i < l; i++){
    if(lst[i] < 0){
      temp = lst[i]*(-1);
      temparr[i] = temp;
    }
    else{
      temparr[i] = lst[i];
    }
  }
 
  
  if(l == 0){
    return ky;
  }
  
  
  
  
  for(i = 0; i < l; i++){
    if(temparr[i] == 0){
      continue;
    }
    temp = temparr[i];
    for(j = 2; j <= temp; j++){
      if(prime(j)){
        if(temp % j == 0){
          arr[size] = j;
          size++;
          while(temp % j == 0){
            temp = temp / j;
          }
        }
      }
    }
  }
  
  nondup[0] = arr[0];
  
  for(i = 1; i < size; i++){
    for(j = 0; j < size; j++){
      if(arr[i] == nondup[j]){
        flag = 1;
        break;
      }
    }
    if(flag == 1){
      count++;
      flag = 0;
      continue;
    }
    else{
      nondup[i - count] = arr[i];
    }
  }
  
  newsize = size - count;
  
  for(i = 0; i < newsize - 1; i++){
    for(j = i + 1; j < newsize; j++){
      if(nondup[i] > nondup[j]){
        temp = nondup[i];
        nondup[i] = nondup[j];
        nondup[j] = temp;
      }
    }
  }
  
  for(i = 0; i < newsize; i++){
    for(j = 0; j < l; j++){
      if(lst[j] % nondup[i] == 0){
        tempsum += lst[j];
      }
    }
    if(i == 0){
      sprintf(tempc,"(%d %d)", nondup[i], tempsum);
      strcpy(cha,tempc);
    }
    else{
      sprintf(tempc,"(%d %d)", nondup[i], tempsum);
      strcat(cha,tempc);
    }
    tempsum = 0;
  }
  
  
  
  return cha;
 
}