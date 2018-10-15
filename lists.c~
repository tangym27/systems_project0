#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

int SIZE = sizeof(struct node);

void print_list(struct node *n){
  int i = 0;
  struct node * node = n;
  printf("Node #: i, next node\n");
  while (node){
    printf("Node %d: %d, %p -> \n", i, node->i, node->next);
    node = node->next;
    i++;
  }
  printf("[NULL]\n");
}

struct node * insert_front(struct node *n, int i){
  struct node *head = malloc(SIZE);
  head -> i = i;
  head -> next = n;
  return head;  
}

struct node * free_list(struct node *n) {
  struct node *holder = n;
  struct node *pos = n;
  while(pos) {
    free(holder);
    pos = pos -> next;
    holder = pos;
  }
  return pos;
}



