#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
int main(){
  char input[256];
  puts("$");
  fgets(input, 100, stdin);
  printf("%s\n", input);

  char **tkn = tokenize(input);
  print_tokens(tkn);
  free_tokens(tkn);
  return 0;
}
