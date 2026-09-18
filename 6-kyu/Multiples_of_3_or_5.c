#include<stdlib.h>

int solution(int number){
  
  
	int i,j,k;
  
  int x,y,z;
  
  int sum1 = 0, sum2 = 0, sum3 = 0;
  
  if(number == 0){
    return 0;
  }
  
  i = number / 3;
  
  int *arr3 = (int *)malloc(sizeof(int)*i+1);
  
  for(z = 1; z<=i; z++){
    if(z % 5 == 0){
      continue;
    }
    arr3[z] = 3 * z;
     printf("%d\n", arr3[z]);
    sum1 += 3 * z;
  }
  
  j = number / 5;
  
  int *arr5 = (int *)malloc(sizeof(int)*j+1);
  
  for(y = 1; y<=j; y++){
    if(y % 3 == 0){
      continue;
    }
    
    arr5[y] = 5 * y;
    printf("%d\n", arr5[y]);
    
    sum2 += 5 * y;
  }
  
  if(number>15){
     k = number / 15;
  
     int *arr15 = (int *)malloc(sizeof(int)*k+1);
  
    for(x = 1; x<=k; x++){
      arr15[x] = x * 15;
      printf("%d\n", arr15[x]);
      sum3 += x * 15;
    }
  }
  
  if(number % 3 == 0){
    sum1 -= i * 3;
  }
  
  if(number % 5 == 0){
    sum1 -= j * 5;
  }
  
  if(number % 15 == 0){
    sum1 -= k * 15; 
  }
  
  printf("%d\n", sum1 + sum2 + sum3);
  return sum1 + sum2 + sum3;

}