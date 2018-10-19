#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked_lists.h"
#include "library.h"


void print_lib(struct library *lib){
  for (int i=0; i<26; i++){
    print_list(lib->table[i]);
  }
}
// int get_ind(char s[]){
//   int rem= 0;
// //print_list(lib->table[artist]);
//   if (s[0] >= 65 && s[0] <= 90){
//     rem = s[0]-65;
//   }
//   else{
//     rem = s[0]-97;
//   }
//   return rem;
// }
int get_ind(char s){
  int rem= 0;
//print_list(lib->table[artist]);
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
void add_song(struct library *lib, char name[100], char artist[100]){
//   int rem= 0;
// //print_list(lib->table[artist]);
//   if (artist[0] >= 65 && artist[0] <= 90){
//     printf("%s\n","CAP" );
//     rem = artist[0]-65;
//   }
//   else{
//     rem = artist[0]-97;
//   }
   int rem = get_ind(artist[0]);
   if (lib->table[rem] == NULL){
       //table[rem] = (struct song_node *) malloc(sizeof(struct song_node));
       lib->table[rem] = insert_front(lib->table[rem], name, artist);

 }
  //printf("%s\n", (table[rem]));
  else{
  insert_order(lib->table[rem], name, artist);}
}

struct song_node * search_lib(struct library *lib, char name[100], char artist[100]){
  int rem = 0;
  rem = get_ind(artist[0]);
  return find_node(lib->table[rem], name, artist);
}
struct song_node * search_lib_art(struct library *lib, char artist[100]){
  int rem = 0;
  rem = get_ind(artist[0]);
  return find_song(lib->table[rem], artist);
}

void entries_let(struct library *lib, char s){
  int rem = get_ind(s);
  //printf("%d\n", rem );
  print_list(lib->table[rem]);
}
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

  // int i = 0;
  // while (!find_song(lib->table[i], lib->table[i]->artist)){
  //       i ++;
  // }
  // remove_node(find_node(lib->table[i], name, lib->table[i]->artist ),name, lib->table[i]->artist);
  // print_lib(lib);
void remove_song(struct library *lib, char name[], char artist[]){
    int i = get_ind(*artist);
    lib->table[i] = remove_node(lib->table[i], name, artist);
}

void free_library(struct library *lib){
    for(int i = 0; i < 27; i++){
        free_list(lib->table[i]);
    }
    free(lib);
}
