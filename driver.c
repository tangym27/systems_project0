#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "linked_lists.h"
#include "library.h"

int main(){
  srand(time(NULL));
  int SIZE = sizeof(struct song_node);

  printf("-------------------------------------\n");
  printf("-------------------------------------\n");
  printf("| TESTING OUT LINKED LIST FUNCTIONS |\n");
  printf("-------------------------------------\n");
  printf("-------------------------------------\n");


  struct song_node *head = malloc(SIZE);
  struct song_node *n1 = malloc(SIZE);
  struct song_node *n2 = malloc(SIZE);
  strcpy( head -> name , "Roar" );
  strcpy( head ->artist , "Katy Perry");
  head -> next =  n1;

  strcpy( n1 -> name , "Love Story" );
  strcpy( n1 -> artist , "Taylor Swift");
  n1 -> next = NULL;


  printf("\n---Testing print_list---\n");
  print_list(head);

  printf("\n---Testing insert_front---\n");
  printf("Add node [Halo, Beyonce]\n");
  head = insert_front(head, "Halo", "Beyonce");
  print_list(head);


  printf("\n---Testing insert_order---\n");
  printf("Add node [Hello, Adele] \n");
  head = insert_order(head, "Hello", "Adele");
  print_list(head);
  printf("Add node [Mercy, Shawn Mendes]\n");
  head = insert_order(head, "Mercy", "Shawn Mendes");
  print_list(head);
  printf("Add node [The Z Song, Zeps] \n");
  head = insert_order(head, "The Z Song", "Zeps");
  print_list(head);
  printf("Add node [Blank Space, Taylor Swift] \n");
  head = insert_order(head, "Blank Space", "Taylor Swift");
  print_list(head);
  printf("Add node [Perfect, Ed Sheeran] \n");
  head = insert_order(head, "Perfect", "Ed Sheeran");
  print_list(head);


  printf("\n---Testing find_node (given artist and song)---\n");
  printf("Looking for [Blank Space, Taylor Swift] (there)\n");
  print_song(find_node(head, "Blank Space", "Taylor Swift"));
  printf("Looking for [Style, Taylor Swift] (not there)\n");
  print_song(find_node(head, "Style", "Taylor Swift"));

  printf("\n---Testing find_song (given artist)---\n");
  printf("Looking for Taylor Swift (there)\n");
  print_song(find_song(head, "Taylor Swift"));
  printf("Looking for Saylor Twift (not there)\n");
  print_song(find_song(head, "Saylor Twift"));

  printf("\n---Testing random ---\n");
  printf("Looking for literally anything!\n");
  print_song(random_node(head));
  printf("Looking for literally anything again!\n");
  print_song(random_node(head));

  printf("\n---Testing remove ---\n");
  printf("Removing [The Z Song, Zeps] \n");
  remove_node(head, "The Z Song", "Zeps");
  print_list(head);
  printf("Removing [The L Song, Leps] \n");
  remove_node(head, "The L Song", "Leps");
  print_list(head);

  printf("\n---Testing free ---\n");
  print_list(free_list(head));

  printf("-------------------------------------\n");
  printf("-------------------------------------\n");
  printf("| TESTING OUT LIBRARY FUNCTIONS     |\n");
  printf("-------------------------------------\n");
  printf("-------------------------------------\n");

  struct library *lib = calloc(1, sizeof(struct library));
  add_song(lib, "Hello", "Adele");
  add_song(lib, "Heart Attack ", "Demi Lovato");
  add_song(lib, "Stone Cold ", "Demi Lovato");
  add_song(lib, "Warrior", "Demi Lovato");

  add_song(lib, "NonStop", "Drake");
  add_song(lib, "Material Girl ", "Madonna");
  add_song(lib, "Stressed Out", "Michelle & Shafali");
  add_song(lib, "Getaway Car", "Taylor Swift");

  printf("---Testing out print_lib\n" );
  print_lib(lib);

  printf("---Testing find node lib---\n");
  printf("Looking for [Stone Cold, Demi Lovato] (there)\n");
  print_song(search_lib(lib, "Stone Cold ", "Demi Lovato"));
  printf("Looking for [Not Stone Cold, Demi Lovato] (not there)\n");
  print_song(search_lib(lib, "Not Stone Cold", "Demi Lovato"));

  printf("---Testing find song lib---\n");
  printf("Find Demi Lovato (exists), print out the list she is in)\n");
  print_list(search_lib_art(lib, "Demi Lovato"));
  printf("Find Not Demi Lovato (does not exist), print out the lit she is in)\n");
  print_list(search_lib_art(lib, "Not Demi Lovato"));

  printf("---Testing entry finder---\n");
  printf("Find all entries 'A'\n");
  entries_let(lib, 'A');
  printf("Find all entries 'M'\n");
  entries_let(lib, 'M');

  printf("---Testing all songs ---\n");
  printf("Get all songs from Demi Lovato\n");
  all_songs(lib, "Demi Lovato");


  printf("---Testing shuffle ---\n");
  shuffle(lib);

  printf("---Testing remove---\n");
  printf("Removed [Hello, Adele] (there)\n");
  remove_song(lib, "Hello", "Adele");
  printf("Removed [Goodbye, Adele] (not there)\n");
  remove_song(lib, "Goodbye", "Adele");
  print_lib(lib);

  printf("---Testing free---\n" );
  free_library(lib);
  print_lib(lib);

  return 0;
}
//hi
