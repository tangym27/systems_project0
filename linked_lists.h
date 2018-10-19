#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

struct song_node {
 	char name[100];
 	char artist[100];
 	struct song_node *next;
};

void print_list(struct song_node *n);
void print_song(struct song_node *n);

struct song_node * insert_front(struct song_node *n, char name[100], char artist[100]);
int compare_song(struct song_node * one, struct song_node * two);
struct song_node * insert_order( struct song_node * head, char name[100], char artist[100]);
int length(struct song_node *n);
struct song_node * find_node(struct song_node *n, char name[100], char artist[100]);
struct song_node * find_song(struct song_node *n, char artist[100]);
struct song_node * remove_node (struct song_node *n, char * name, char * artist );
struct song_node * free_list(struct song_node *n);
struct song_node * random_node(struct song_node *n);


#endif
