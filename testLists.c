#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int _SIZE = sizeof(struct node);
//struct node { int i; struct node *next; };


int main(){
  struct node *head = malloc(_SIZE);  
  struct node *n1 = malloc(_SIZE);

  head -> i = 1;
  head -> next = n1;
  n1 -> i =  2;
  n1 -> next = NULL;

  printf("---Testing print_list---\n");
  print_list(head);

  printf("---Testing insert_front---\n");
  printf("After adding node at the front: \n");
  print_list(insert_front(head, 5));

  printf("---Testing free_list---\n");
  printf("After freeing list: %p\n", free_list(head));
  return 0;
}