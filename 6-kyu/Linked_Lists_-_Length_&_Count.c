#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct Node {
	struct Node *next;
	int value;
};


size_t list_length (const struct Node *list){
  
  struct Node *ptr;
  
  ptr = list;
  
  int count = 0;
  
  while(ptr != NULL){
    ptr = ptr->next;
    count++;
  }
  
  return count;
  
}



size_t list_count (const struct Node *list, int search_val){
 struct Node *ptr;
  
  ptr = list;
  
  int count = 0;
  
  while(ptr != NULL){
    if(ptr->value == search_val){
      count++;
    }
    ptr = ptr->next;
  }
  
  return count;
  
}