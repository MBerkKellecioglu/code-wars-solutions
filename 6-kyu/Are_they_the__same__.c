#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int howmany(const int *p, size_t k, size_t flag){

  int count=0;
  
  size_t i;
  
  for(i = 0; i<k; i++){
    if(flag != i){
      if(p[flag] == p[i]){
        count++;
      }
    }
  }
  
  return count + 1;
}

bool comp(const int *a, const int *b, size_t n)
{
   int count, count1=0;
   size_t i,j;
  
   for(i = 0; i<n; i++){
     count = howmany(a,n,i);
     count1 = 0;
     for(j = 0; j<n; j++){
       if(a[i] == sqrt(b[j])){
       count1++;
       }
     }
     if(count1 != count){
       return false;
     }
   }
  return true;
}