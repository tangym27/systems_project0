#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "linked_lists.h"

int SIZE = sizeof(struct song_node);

// print the entire list given a node
void print_list(struct song_node *n){
  while (n){
    printf("[%s, %s] -> ", n->name, n->artist);
    n = n->next;
  }
  printf("[NULL]\n");
}

// prints out the name and artist of a given node
void print_song(struct song_node *n){
  if (!n){
    printf("I AM SORRY, IT DOES NOT EXIST.\n");
  }
  else {
    printf("Result: [%s, %s]\n", n->name, n->artist);
  }
}

// will construct a node and place it to the front of a given node
struct song_node * insert_front(struct song_node *n, char name[100], char artist[100]){
  struct song_node *head = malloc(SIZE);
  strcpy( head -> name , name );
  strcpy( head ->artist , artist);
  head -> next = n;
  return head;
}

// helper function to insert_order (will indicate when a node should precedent the other)
int compare_song(struct song_node * one, struct song_node * two){
  if(strcmp(one->artist, two->artist) < 0){
    return -1;
  }else if(strcmp(one->artist, two->artist) > 0){
    return 1;
  }else{
    if(strcmp(one->name, two->name) < 0){
      return -1;
    }
      return 1;
  }
}

// will add a new node in order when given a previous node (head)
struct song_node * insert_order( struct song_node * head, char name[100], char artist[100]){
  struct song_node * add = malloc(SIZE);
  strcpy(add->name, name);
  strcpy(add->artist, artist);

  if(head == NULL || compare_song(add, head) < 0){ //if the given node is empty or new node is firt
    return insert_front(head, name, artist);
  }else if((head->next) == NULL){ // when tracker is at last node
    if(compare_song(add, head) < 0){ //if the added song is before tracked one
      return insert_front(head, name, artist);
    }else{ // if the added song is after the tracked one
      head->next = add;
      add->next = NULL;
      return head;
    }
  }else{
    struct song_node * current = head; // track positions
    while((current->next != NULL) && (compare_song(add, current->next) > 0)){ //check for next node and current one is before
      current = current->next;
    }
    if(current->next){ //next is not null
      add->next = current->next;
      current->next = add;
    }else{ // tracker node is at the end (so null)
      current->next = add;
      add->next = NULL;
    }
    return head;
  }
}

// returns the length of the linked list
int length(struct song_node *n) {
  int counter = 0;
  while(n) {
    counter++;
    n = n -> next;
  }
  return counter;
}

// will find a node given a linked list, a song, and an artist
struct song_node * find_node(struct song_node *n, char name[100], char artist[100]){
  while (n){
    if(strcmp(n -> name, name) == 0 && strcmp(n -> artist, artist) == 0) {
      return n;
    }
    n = n -> next;
  }
  return NULL;
}

// will find the first song by a specified artist
struct song_node * find_song(struct song_node *n, char artist[100]) {
  while (n){
    if(strcmp(n -> artist, artist) == 0) {
      return n;
    }
    n = n -> next;
  }
  return NULL;
}

// given a linked list, it will rremove a node of said name and artist if it exit
struct song_node * remove_node (struct song_node *n, char * name, char * artist ){
  int length0 = length(n);
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
  if (length0 == length(head)){
    printf("THAT NODE WAS NOT THERE TO BEGIN WITH!\nSTILL:");
  }
  return head;
}

// empties/frees the entire list
struct song_node * free_list(struct song_node *n) {
  while (n) {
    struct song_node *holder = n->next;
    printf("BYE BYE: ");
    print_song(n);
    free(n);
    n = holder;
  }
  return n;
}

// Return a pointer to a random element in the list.
struct song_node * random_node(struct song_node * n){
    int random_index = (rand()%length(n));
    while(n && random_index > 0){
        random_index--;
        n = n->next;
    }
    return n;
}
