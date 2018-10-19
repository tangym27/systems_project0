#ifndef LIBRARY_H
#define LIBRARY_H

#include "linked_lists.h"

struct library {
    struct song_node * table[27];
};


void print_lib(struct library *lib);
int get_ind(char s);
void add_song(struct library *lib, char name[100], char artist[100]);
struct song_node * search_lib(struct library *lib, char name[100], char artist[100]);
struct song_node * search_lib_art(struct library *lib, char artist[100]);
void entries_let(struct library *lib, char s);
void all_songs(struct library *lib, char *artist);
void shuffle(struct library *lib);
void remove_song(struct library *lib, char name[], char artist[]);
void free_library(struct library *lib);



#endif
