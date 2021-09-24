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
  int count = 0; //keep count of words
  while(1){
    str = word_start(str);// move to first char
    if(str[1] == '\0')
      break;
    count++;//increment count

    str = word_terminator(str); //move to terminator
    if(str[0] == '\0')
      break;
  }
  //print word count
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
  //get the amount of words and allocate memory
  int words = count_words(str);
  char **tokens = (char**)malloc((words+1)*sizeof(char*));

  //variables used in code
  char *begin;
  char *end;
  int len = 0;
  char **ptr = tokens;
  int i = 0;

  //while loop to copy string into tokens[i]
  while(i < words){
    //calculate len of word
    begin = word_start(str);
    end = word_terminator(begin);
    len = end - begin;

    //copy string into tokenizer
    tokens[i] = copy_str(begin, len+1);
    str = word_terminator(end);
    i++;
  }

  //null terminator at end
  tokens[i] = '\0';
  return tokens;
}

void print_tokens(char **tokens){
  //print tokens as long as not null
  //prevent segmentation fault
  for(int t=0; tokens[t]!= NULL; t++){
    printf("[%d] %s\n", t, tokens[t]);
  }
}

void free_tokens(char **tokens){
  
  int t = 0; //keep track of tokens
  while(tokens[t]){
    printf("%s", tokens[t]);
    free(tokens[t]);
    t++;
  } 
  free(tokens); //free all tokens
}
