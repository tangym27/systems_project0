#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct node { int i; struct node *next; };

struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};


int SIZE = sizeof(struct song_node);

void print_list(struct song_node *n){
  int i = 0;
  struct song_node * node = n;
  printf("Node #: i, next node\n");
  while (node){
    printf("Node %d: %s, %s -> \n", i, node->name, node->artist);
    node = node->next;
    i++;
  }
  printf("[NULL]\n");
}

struct song_node * insert_front(struct song_node *n, char name[100], char artist[100]){
  struct song_node *head = malloc(SIZE);
  strcpy( head -> name , name );
  strcpy( head ->artist , artist);
  head -> next = n;
  return head;  
}

/* struct node * free_list(struct node *n) { */
/*   struct node *holder = n; */
/*   struct node *pos = n; */
/*   while(pos) { */
/*     free(holder); */
/*     pos = pos -> next; */
/*     holder = pos; */
/*   } */
/*   return pos; */
/* } */


int main(){
  struct song_node *head = malloc(SIZE);  
  struct song_node *n1 = malloc(SIZE);

  strcpy( head -> name , "a" );
  strcpy( head ->artist , "bb");
  head -> next =  n1;
  strcpy( n1 -> name , "ab" );
  strcpy( n1 -> artist , "bbc");
  n1 -> next = NULL;

  printf("---Testing print_list---\n");
  print_list(head);

  printf("---Testing insert_front---\n");
  printf("After adding node at the front: \n");
  print_list(insert_front(head, "HI", "THERE"));

  return 0;
}

