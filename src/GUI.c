#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
int main(){
  char input[256];
  char *pass = input;

  while(1){
    puts(">");
    fgets(input,256,stdin);
    fflush(stdout);
    if(input[0] == 'q'){
      break;
    }
    
    puts(input);
    pass = input;
    
    char* start = word_start(pass);
    char* end = word_terminator(start);

    printf("char*= %c\n", *start);
    printf("count = %i\n",count_words(start));
  }
  return 0;
}
