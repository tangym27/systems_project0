#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked_lists.h"
#include "library.h"

//print library
void print_lib(struct library *lib){
  for (int i=0; i<26; i++){
    print_list(lib->table[i]);
  }
}

//get index for the first letter (usually artist)
int get_ind(char s){
  int rem= 0;
  if (s >= 65 && s <= 90){
    rem = s-65;
  }
  else if (s>=97 && s<=122){
    rem = s-97;
  }
  else{
    rem = 26;
  }
  return rem;
}
//adding song based on name and artist
void add_song(struct library *lib, char name[100], char artist[100]){
   int rem = get_ind(artist[0]);
   //if empty
   if (lib->table[rem] == NULL){
       lib->table[rem] = insert_front(lib->table[rem], name, artist);
 }
  else{
  insert_order(lib->table[rem], name, artist);}
}

//returns pointer to a search for song and artist
struct song_node * search_lib(struct library *lib, char name[100], char artist[100]){
  int rem = 0;
  rem = get_ind(artist[0]);
  return find_node(lib->table[rem], name, artist);
}
//returns pointer to node after searching by artist
struct song_node * search_lib_art(struct library *lib, char artist[100]){
  int rem = 0;
  rem = get_ind(artist[0]);
  return find_song(lib->table[rem], artist);
}

//prints entries under certain letter
void entries_let(struct library *lib, char s){
  int rem = get_ind(s);
  //printf("%d\n", rem );
  print_list(lib->table[rem]);
}

//prints all songs from certain artist
void all_songs(struct library *lib, char *artist){
    int rem= get_ind(*artist);
    struct song_node *temp = lib->table[rem];
    while (temp){
        if (!strcmp(artist, temp->artist)){
            printf("%s\n",temp->name );
            temp = temp->next;
        } else {
            break;
        }
    }
}

//prints random list of nodes
void shuffle(struct library *lib){
  int i = rand() % 26;
  printf("%d\n", i);

  print_list(lib->table[0]);
  while( i>0){
    if (lib->table)
      print_list(random_node(lib->table[i]));
    i--;
  }
}

//removes song
void remove_song(struct library *lib, char name[], char artist[]){
    int i = get_ind(*artist);
    lib->table[i] = remove_node(lib->table[i], name, artist);
}

//free library 
void free_library(struct library *lib){
    for(int i = 0; i < 27; i++){
        free_list(lib->table[i]);
    }
    free(lib);
}
