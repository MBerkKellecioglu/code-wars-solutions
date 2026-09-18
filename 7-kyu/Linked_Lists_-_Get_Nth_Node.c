#include <stddef.h>

struct List {
	struct List *next;
	int data;
};


struct List *get_nth_node (const struct List *list, size_t n){
  
  struct List *ptr = list;
  
  struct List *temp = list;
  
  size_t count = 0;
  
  size_t i;
  
  if(list == NULL){
    return NULL;
  }
  
  if(n == 0){
    return list;
  }
  
  while(ptr != NULL){
    ptr = ptr->next;
    count++;
  }
  
  if(n>=count){
    return NULL;
  }
  
  for(i = 0; i<n; i++){
    temp = temp->next;
  }
  
  return temp;
}