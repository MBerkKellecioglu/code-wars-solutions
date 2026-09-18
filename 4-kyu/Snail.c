#include <stdlib.h>

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols) {
  
   
  int *snake = (int*)malloc(sizeof(int)*rows*cols);
  
  int dir = 0, top = 0, right = cols - 1, left = 0, down = cols - 1, k = 0, i;
  
  
  while(top <= down && left <= right){
    
    if(dir == 0){
      for(i = left; i <= right; i++){
        snake[k] = mx[top][i];
        k++;
      }
      top += 1;
    }
    else if(dir == 1){
      for(i = top; i <= down; i++){
        snake[k] = mx[i][right];
        k++;
      }
      right -= 1;
    }
    else if(dir == 2){
      for(i = right; i >= left; i--){
        snake[k] = mx[down][i];
        k++;
      }
      down -= 1;
    }
    else if(dir == 3){
      for(i = down; i >= top; i--){
        snake[k] = mx[i][left];
        k++;
      }
      left += 1;
    }
    dir = (dir + 1) % 4;
  }
  
  *outsz = k;
  
  
  return snake;
  
}