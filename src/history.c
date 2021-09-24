#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history(){
  List *list;
  list = (List*) malloc(sizeof(List)*1);
  list->root = (Item*) malloc(sizeof(Item)*1);
  return list;
}

void add_history(List *list, char *str){
  Item *root = list->root;
  Item *newRoot = (Item*)malloc(sizeof(Item)*1);
  int newID = 0;

  //if root is empty id will be 0
  if(root->str == NULL){
    root->id = 0;
    root->str = str;
    root->next = NULL;
    return;
  }

  //if root is not empty assign next root and increment ID
  while(root->next != NULL){
    root = root->next;
    newID++;
  }

  //assign new root
  newRoot->id = newID;
  newRoot->str = str;
  newRoot->next = NULL;
  root->next = newRoot;
}

char *get_history(List* list, int id){
  Item *root = list->root;
  //while the root is not null
  while(root != NULL){
    //if the id's match return the string
    if(root-> id == id){
      return root->str;
    }
    //go next root
    root = root->next;
  }
}

void print_history(List *list){
  //create temp of list root
  Item *temp = list->root;

  //while loop to print all strings
  while(temp->next != NULL){
    printf("\n%s", temp->str);
    temp = temp->next;
  }
}

void free_history(List *list){
  //create temp of list root
  Item *temp = list->root;

  //same as print history but we free instead of printing
  while(temp->next != NULL){
    free(temp);
    temp = temp->next;
  }
  free(list);
}
