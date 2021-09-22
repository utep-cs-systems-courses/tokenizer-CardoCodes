#include <stdlib.h>
#include <stdio.h>

int space_char(char c){

  if(c == ' ' || c == '\t' || c == '\0') //true if c is space, tab, or terminator
    return 1;
  return 0;
}

int non_space_char(char c){
  if(!space_char(c)) //using first function, we can identify non space chars
    return 1;
  else return 0;
}

char *word_start(char *str){
  while(non_space_char(str[0]) == 0)//loop until we see a non_space_char
    str++;
  return str;
}

char *word_terminator(char *word){
  while(non_space_char(word[0]) == 1)//loop util we see no longer see a non_space_char
    word++;
  return word;
}

int count_words(char *str){
  int count = 0;
  while(1){
    str = word_start(str);
    if(str[1] == '\0')
      break;
    count++;

    str = word_terminator(str);
    if(str[0] == '\0')
      break;
  }
  printf("# of words: %d\n", count);
  return count;
}

char *copy_str(char *inStr, short len){
  char *copy = malloc(len);
  int i = 0;
  while(len != 0){
    copy[i] = inStr[i];
    i++;
    len--;
  }
  copy[i] = '\0';
  return copy;
}

char **tokenize(char *str){
  int words = count_words(str);
  char **tokens = (char**)malloc((words+1)*sizeof(char*));
  char *begin;
  char *end;
  int len = 0;
  char **ptr = tokens;
  int i = 0;

  
  while(i < words){
    begin = word_start(str);
    end = word_terminator(begin);
    len = end - begin;
    tokens[i] = copy_str(begin,len+1);
    str = word_terminator(end);
    i++;
  }
  tokens[i] = '\0';
  return tokens;
}

void print_tokens(char **tokens){
  for(int t=0; tokens[t]!="\0";t++){
    printf("Tokens: %s \n", tokens[t]);
  }
}

void free_tokens(char **tokens){
  int t = 0;
  while(tokens[t]){
    printf("%s", tokens[t]);
    free(tokens[t]);
    t++;
  }
  free(tokens); //free all tokens
}
