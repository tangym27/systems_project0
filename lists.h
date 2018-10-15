struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node *);

struct song_node * insert_front(struct song_node *n, char name[100], char artist[100]){

