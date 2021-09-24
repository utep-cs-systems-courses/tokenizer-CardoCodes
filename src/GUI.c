#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"
int main(){
  //init history
  List* list = init_history();
  
  while(1){
    puts("Commands: q = quit program, h = print history");
    puts("Enter a sentance to tokenize: ");

    char *userInput = (char*)malloc(sizeof(char*));
    fgets(userInput, 100, stdin);

    if(strcmp(userInput, "q\n") == 0){
      puts("Program Terminated");
      break;
    }
    else if(userInput[0] == '!'){
      int x = userInput[1];
      printf("getting history at pos:  %d\n", x);
      printf("H[%d] %s\n", x, get_history(list, x));
    }
    else if(strcmp(userInput,"h\n") == 0){
      puts("---------History--------");
      print_history(list);
      free_history(list);
    }
    else{
      puts("----------Tokens--------");
      char ** tkns = tokenize(userInput);
      print_tokens(tkns);
      add_history(list, userInput);
      puts("-------Free Tokens------");
      free_tokens(tkns);
    }
  }
}
