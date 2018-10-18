#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "linked_lists.h"
#include "library.h"

int main(){
  srand(time(NULL));
  printf("%s\n", "LINKED LISTS FUNCTIONALITY" );
  struct song_node *head = malloc(SIZE);
  struct song_node *n1 = malloc(SIZE);
  struct song_node *newer = malloc(SIZE);
  strcpy( head -> name , "c" );
  strcpy( head ->artist , "bb");
  head -> next =  n1;
  strcpy( n1 -> name , "a" );
  strcpy( n1 -> artist , "dd");
  n1 -> next = NULL;
  // strcpy(newer -> name, "b");
  // strcpy(newer -> artist, "bb");
  // newer -> next = NULL;

  printf("---Testing print_list---\n");
  print_list(head);

  printf("---Testing order_alpha---\n");
  printf("After adding node in order: \n");
  print_list(insert_order(head, "a", "bb"));

  return 0;

}
