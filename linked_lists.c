#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_lists.h"

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

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


int compare_song(struct song_node * one, struct song_node * two){
  if(strcmp(one->artist, two->artist) < 0){
    return -1;
  }else if(strcmp(one->artist, two->artist) > 0){
    return 1;
  }else{
    if(strcmp(one->name, two->name) < 0){
      return -1;
    }
    else{
      return 1;
    }
  }
}

struct song_node * insert_order( struct song_node * head, char name[100], char artist[100]){
  struct song_node * add = malloc(SIZE);
  strcpy(add->name, name);
  strcpy(add->artist, artist);

  if(head == NULL || compare_song(add, head) < 0){
    return insert_front(head, name, artist);
  }else if((head->next) == NULL){ //at last node
    if(compare_song(add, head) < 0){ //if the added song is before last one
      return insert_front(head, name, artist);
    }else{ // if it is the next node
      head->next = add;
      add->next = NULL;
      return head;
    }
  }else{

    struct song_node * current = head;

    while((current->next != NULL) && (compare_song(add, current->next) > 0)){ //while there is a next node and the song next to the current takes precedence,
      current = current->next;
    }
    if(current->next){ //not null
      add->next = current->next;
      current->next = add;
    }else{ //at the very end
      current->next = add;
      add->next = NULL;
    }

    return head;
  }
}


int length(struct song_node *n) {
  int counter = 0;
  while(n) {
    counter++;
    n = n -> next;
  }
  return counter;
}

struct song_node * find_node(struct song_node *n, char name[100], char artist[100]){
  while (n){
    if(strcmp(n -> name, name) == 0 && strcmp(n -> artist, artist) == 0) {
      return n;
    }
    n = n -> next;
  }
  return NULL;
}

struct song_node * find_song(struct song_node *n, char artist[100]) {
  while (n){
    if(strcmp(n -> artist, artist) == 0) {
      return n;
    }
    n = n -> next;
  }
  return NULL;
}
struct song_node * remove_node (struct song_node *n, char * name, char * artist ){
  struct song_node * previous = NULL;
  struct song_node * head = n;
  struct song_node * current = n;
  while (n){
    if (strcmp(n -> name, name) == 0 && strcmp (n -> artist, artist) == 0){
      if (previous == NULL){ //first node
	     free(n);
	     return head -> next;
      }
      else if (n -> next == NULL){ //last node
	     previous -> next = NULL;
	     free(n);
	     return head;
      }
      free (n);
      previous -> next = current -> next;
      return head;
    }
    previous = n;
    n = n -> next;
    current = n;
  }
  return head;
}


struct song_node * free_list(struct song_node *n) {
  while (n) {
    struct song_node *holder = n->next;
    free(n);
    n = holder;
  }
  return n;
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
