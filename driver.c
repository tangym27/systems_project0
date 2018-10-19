#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "linked_lists.h"
#include "library.h"

int main(){
  srand(time(NULL));
  int SIZE = sizeof(struct song_node);
  struct song_node *head = malloc(SIZE);
  struct song_node *n1 = malloc(SIZE);
  struct song_node *newer = malloc(SIZE);
  struct library *lib = calloc(1, sizeof(struct library));
  strcpy( head -> name , "c" );
  strcpy( head ->artist , "bb");
  head -> next =  n1;
  strcpy( n1 -> name , "a" );
  strcpy( n1 -> artist , "dd");
  n1 -> next = NULL;
  printf("---Testing print_list---\n");
  print_list(head);

  printf("---Testing order_alpha---\n");
  printf("After adding node in order: \n");
  print_list(insert_order(head, "a", "bb"));

  printf("---Testing add song nodes---\n");
  add_song(lib, "hello", "ADELE");
  add_song(lib, "Stone Cold ", "Demi Lovato");
  add_song(lib, "NonStop", "Drake");
  //print_list(head);
  //printf("%s\n\n\n\n\n", "BUHURILUFJRLUHFRIUHFLIURHFIURH");
  //free_list(head);
  //print_list(head);
  //print_lib(lib);
  printf("---Testing find node libb---\n");
  print_list(search_lib(lib, "Stone Cold ", "Demi Lovato"));
  print_list(search_lib(lib, "hello", "ADELE"));

  printf("---Testing find song libb---\n");
  print_list(search_lib_art(lib, "Demi Lovato"));
  print_list(search_lib_art(lib, "ADELE"));

  printf("---Testing entry finder---\n");
  entries_let(lib, 'A');
  printf("---Testing all songs ---\n");
  add_song(lib, "Warrior", "Demi Lovato");
  all_songs(lib, "Demi Lovato");
  print_lib(lib);
  printf("---Testing shuffle ---\n");
  shuffle(lib);
  printf("---Removed hello ---\n");

  remove_song(lib, "hello", "ADELE");
  print_lib(lib);
  //printf("%s\n","free" );
  //free_library(lib);
  //print_lib(lib);
  return 0;
}
// srand(time(NULL));
// printf("%s\n", "LINKED LISTS FUNCTIONALITY" );
// struct song_node *head = malloc(SIZE);
// struct song_node *n1 = malloc(SIZE);
// struct song_node *newer = malloc(SIZE);
// strcpy( head -> name , "c" );
// strcpy( head ->artist , "bb");
// head -> next =  n1;
// strcpy( n1 -> name , "a" );
// strcpy( n1 -> artist , "dd");
// n1 -> next = NULL;
// // strcpy(newer -> name, "b");
// // strcpy(newer -> artist, "bb");
// // newer -> next = NULL;
//
// printf("---Testing print_list---\n");
// print_list(head);
//
// printf("---Testing order_alpha---\n");
// printf("After adding node in order: \n");
// print_list(insert_order(head, "a", "bb"));
//
// return 0;
