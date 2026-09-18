#include <stdlib.h>
#include <stdio.h>

struct interval {
    int first;
    int second;
};



int sum_intervals_rec(struct interval *v, size_t n, int tsum){
  
  size_t i, j;
  
  int sum = 0, temp;
  
  struct interval *b = (struct interval*)malloc(sizeof(struct interval)*n);
  
  for(i = 0; i < n; i++){
    b[i].first = v[i].first;
    b[i].second = v[i].second;
  }
  
  for(i = 0; i < n - 1; i++){
    if(b[i].first == 0 && b[i].second == 0){
      continue;
    }
    for(j = i  + 1; j < n; j++){
      if(b[j].first == 0 && b[j].second == 0){
        continue;
      }
      else if(b[i].first >= b[j].first && b[i].second <= b[j].second){
        b[i].first = b[j].first;
        b[i].second = b[j].second;
        b[j].first = 0;
        b[j].second = 0;
      }
      else if(b[j].first >= b[i].first && b[j].second <= b[i].second){
        b[j].first = 0;
        b[j].second = 0;
      }
      else if(b[i].second < b[j].first){
        continue;
      }
      else if(b[j].second < b[i].first){
        continue;
      }
      else if(b[i].second >= b[j].first && b[j].second > b[i].second){
        b[i].second = b[j].second;
        b[j].first = 0;
        b[j].second = 0;
      }
      else if(b[j].second >= b[i].first && b[i].second > b[j].second){
        b[i].first = b[j].first;
        b[j].first = 0;
        b[j].second = 0;
      }
    }
  }
  
  for(i = 0; i < n; i++){
    temp = b[i].second - b[i].first;
    sum = sum + temp;
  }
  
  if(tsum == sum){
    return sum;
  }
  
  return sum_intervals_rec(b,n,sum);
  
}


int sum_intervals(struct interval *v, size_t n){
  int sums = sum_intervals_rec(v,n,0);
  
  return sums;
}