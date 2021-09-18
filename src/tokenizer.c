#include <stdlib.h>
#include <stdio.h>

int space_char(char c){

  if(c == ' ' || c == '\t' || c == '\n' && c != '\0') //true if c is space, tab, nonzero
    return 1;
  return 0;
}

int non_space_char(char c){
  if(!space_char(c)) //using first function, we can identify non space chars
    return 1;
  else return 0;
}

char *word_start(char *str){
  while(*str){
    // printf("word_start %c\n",*str);
    if(non_space_char(*str)){
      //printf("returning a string\n");
      return str;}
    str++;
  }
  printf("Coming to null");
  return NULL;
}

char *word_terminator(char *word){
  while(word){
    if(space_char(*word))
      return word;
    word++;
  }
  return NULL;
}

int count_words(char *str){
  if(word_start(str) == 0)
    return 0;
  if(*word_terminator(word_start(str)) == 0)
    return 1;
  return count_words(word_terminator(word_start(str)))+1;
}

char *copy_str(char *inStr, short len){
  char *copy = (char*)malloc(len+1);
  size_t counter;
  for(counter = 0; counter < len; counter++){
    copy[counter] = inStr[counter];
  }
  copy[counter] = '\0';
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

