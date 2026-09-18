#include<string.h>
#include<stdlib.h>
#include<stdio.h>

char *human_readable_time (unsigned seconds, char *time_string){
  unsigned int temp1, temp2,k;
  char temparr1[10];
  char temparr2[10];
  char temparr3[10];
  
  strcpy(time_string,"");
  
  printf("%s", time_string);

  temp1 = seconds / 3600;
  k = temp1*3600;
  seconds = seconds - k;
  
  if(temp1>9){
    sprintf(temparr1,"%u",temp1);
    strcat(time_string,temparr1);
  }
  else{
    sprintf(temparr1,"0%u",temp1);
    strcat(time_string,temparr1);
  }

  temp2 = seconds / 60;
  k = temp2*60;
  seconds = seconds - k;
   if(temp2>9){
    sprintf(temparr2,":%u",temp2);
    strcat(time_string,temparr2);
  }
  else{
    sprintf(temparr2,":0%u",temp2);
    strcat(time_string,temparr2);
  }
  
  
  if(seconds>9){
    sprintf(temparr3,":%u",seconds);
    strcat(time_string,temparr3);
  }
  else{
    sprintf(temparr3,":0%u",seconds);
    strcat(time_string,temparr3);
  }
  
  return time_string;
  
}