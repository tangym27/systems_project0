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
  //printf("Node #: i, next node\n");
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

int length(struct song_node *n) {
  int counter = 0;
  while(n) {
    counter++;
    n = n -> next;
  }
  return counter;
}

struct song_node * find_node(struct song_node *n, char * name, char * artist){
  while (n){
    if(strcmp(n -> name, name) == 0 && strcmp(n -> artist, artist) == 0) {
      return n;
    }
    n = n -> next;
  }
  return NULL;
}

struct song_node * find_song(struct song_node *n, char * artist) {
  while (n){
    if(strcmp(n -> artist, artist) == 0) {
      return n;
    }
    n = n -> next;
  }
  return NULL;
}


// Return a pointer to random element in the list.
struct song_node * random_node(struct song_node *n) {
  int random_index = rand() % length(n);
  int num = 0;
  while(n != NULL && num < random_index) {
    n = n -> next;
    num++;
  }
  return n;
}

struct song_node * remove_node (struct song_node *n, char * name, char * artist ){
  struct song_node * previous = NULL;
  struct song_node * head = n;
  while (n){
    if (strcmp(n -> name, name) == 0 && strcmp (n -> artist, artist) == 0){
      if (previous == NULL){ //first node
	free(head);
	return n -> next;
      }
      else if (n -> next == NULL){ //last node
	previous -> next == NULL;
	free (n);
	return head;
      }
    }
  }
  return head;
}

struct song_node * order_alpha (struct song_node *add, struct song_node *begin){
  struct song_node *temp = begin;
  struct song_node *previous = NULL;
  printf("%d\n", (strcmp(add-> artist, temp-> artist)));
  while (strcmp(add-> artist, temp-> artist) >0 ){//&& temp->next!=NULL){
    printf("%s\n", "ufbiufhelbfui" );
    previous = temp;
    temp = temp ->next;
    if (temp->next==NULL){
      temp = NULL;
      break;
    }
    }
  if  (strcmp(add->artist, temp->artist) ==0){
    while (strcmp(add->name, temp->name)>0){
      previous = temp;
      temp= temp ->next;
    }
  }

  //add is the 1st one
  if (previous == NULL){
    printf("%s\n", "jkllllll");
    begin = insert_front(begin, add->artist, add ->name);
  }
  //add at end
  else if (temp== NULL){
    printf("%s\n", temp);
    printf("%s\n","gggggggggggg" );
    previous->next = add;
  }

  //if (temp -> next != NULL){
  //add to middle
  else{
    printf("%s\n", "fjdnifieiii");
    previous->next = add;
    add->next = temp;
  }
  return begin;
}
/* struct node * free_list(struct song_node *n) { */
/*   struct song_node *holder = n; */
/*   struct song_node *pos = n; */
/*   while(pos) { */
/*     free(holder); */
/*     pos = pos -> next; */
/*     holder = pos; */
/*   } */
/*   return pos; */
/* } */


int main(){
  // srand();
  struct song_node *head = malloc(SIZE);
  struct song_node *n1 = malloc(SIZE);
  struct song_node *newer = malloc(SIZE);
  strcpy( head -> name , "a" );
  strcpy( head ->artist , "aa");
  head -> next =  n1;
  strcpy( n1 -> name , "c" );
  strcpy( n1 -> artist , "dd");
  n1 -> next = NULL;
  strcpy(newer -> name, "d");
  strcpy(newer -> artist, "cc");
  newer -> next = NULL;

  printf("---Testing print_list---\n");
  print_list(head);

  printf("---Testing insert_front---\n");
  printf("After adding node at the front: \n");
  print_list(insert_front(head, "HI", "THERE"));
  printf("%d\n", length(head));
  print_list(head);

  printf("---Testing order_alpha---\n");
  printf("After adding node in order: \n");
  print_list(order_alpha(newer, head));

  return 0;
}
