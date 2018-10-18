#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//struct node { int i; struct node *next; };

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};
struct library{
  struct song_node *table[26];
};


int SIZE = sizeof(struct song_node);

void print_list(struct song_node *n){
  int i = 0;
  struct song_node * node = n;
  //printf("Node #: i, next node\n");
  while (node){
    printf("%s, %s -> ",node->name, node->artist);
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
  if (length(n) !=0){
    int random_index = rand() % length(n);
    int num = 0;
    while(n != NULL && num < random_index) {
      n = n -> next;
      num++;
    }
    return n;
  }
  return NULL;
}


/* struct node * free_list(struct song_node *n) { */
/*   struct song_node *holder = n; */
/*   struct song_node *pos = n; */
/*   while(pos) { */
/*     free(holder); */
/*     pos = pos -> next; */
/*     holder = pos; */
/*   } */
/*   return pos; */
/* } */

/*NEWEWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
COOOOOOOOOOOOOOOOOOOOOOODDDDDDDDDDDDDDDDDDDDDDDDDDDDWWWWWWWWWEEEEEEEEEE
EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE



EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE*/

//song_node *table[26];
// void print_arr(struct song_node *arr[]){
//   for (int i=0; i<26; i++){
//     print_list(arr[i]);
//   }
// }
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
  printf("%d\n", rem );
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

void remove_song(struct library *lib, char name ){

}

int main(){
  // srand();
  srand(time(NULL));
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
  // strcpy(newer -> name, "b");
  // strcpy(newer -> artist, "bb");
  // newer -> next = NULL;

  printf("---Testing print_list---\n");
  print_list(head);

  printf("---Testing order_alpha---\n");
  printf("After adding node in order: \n");
  print_list(insert_order(head, "a", "bb"));

  printf("---Testing add song nodes---\n");
  //printf("%s\n", );
  add_song(lib, "hello", "ADELE");
  add_song(lib, "Stone Cold ", "Demi Lovato");
  add_song(lib, "NonStop", "Drake");

  // for (int i=0; i<26; i++){
  //   print_list(table[i]);
  // }
  print_lib(lib);
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
  return 0;
}
