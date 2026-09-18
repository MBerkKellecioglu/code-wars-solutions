#include <inttypes.h>
#include <string.h>
#include <stdio.h>

char *to_binary (int32_t n, char binary[32 + 1]){
  
  int i, tempi, lenght, flag = 0;
  
  char tempc[100];
  
  int ibinary[100];
  
  if(n == 0){
    strcpy(binary,"0");
    return binary;
  }
  
  if(n < 0){
    n = n*(-1);
    n = n - 1;
    flag = 1;
  }

  for(i = 0; n > 0; i++){
    ibinary[i] = n%2;
    n = n/2;
  }
  
  lenght = i;
  
  for(i = 0; i < lenght/2; i++){
    tempi = ibinary[i];
    ibinary[i] = ibinary[lenght - i - 1];
    ibinary[lenght - i - 1] = tempi;
  }
  
  tempi = ibinary[0];
  sprintf(tempc,"%d", tempi);
  strcpy(binary,tempc);
  
  for(i = 1; i < lenght; i++){
    tempi = ibinary[i];
    sprintf(tempc,"%d", tempi);
    strcat(binary,tempc);
  }
  
  
  if(flag == 1){
    strcpy(tempc,"1");
    for(i = 0; i < 32 - strlen(binary) - 1; i++){
      strcat(tempc, "1");
    }
    for(i = 0; i < lenght; i++){
      if(ibinary[i] == 0){
        ibinary[i] = 1;
      }
      else{
        ibinary[i] = 0;
      }
    }
    
    strcpy(binary,tempc);
    strcpy(tempc,"");
    
    for(i = 0; i < lenght; i++){
      tempi = ibinary[i];
      sprintf(tempc,"%d",tempi);
      strcat(binary,tempc);
    }
    
  }
  
  return binary;
}