#include <stddef.h>

size_t countBits(unsigned value){
  
  size_t count = 0;
  unsigned control = 1;
  
	
  while(control <= value){
    if((control & value) > 0){
      count++;
    }
    control = control << 1;
  }
  
  return count;
}