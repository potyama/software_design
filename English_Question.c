#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TRUE                    1
#define FALSE                   0

#define WORD_FILE               "./dict"
#define WORD_LEN                50
#define MIN_LETTERS_IN_A_WORD   5

void  getWord(char *word);
int   play(char *word);
void  showStatus(char *word);

int   main(void) {
  char  word[WORD_LEN];

  srand((unsigned int)time(NULL));

  while(1) {
    getWord(word);
    play(word);
  }

  return 0;
}

void  getWord(char *word) {
  FILE  *fp;
  long  dictionaryFileSize;
  long  pos;
  int   wordLength;
  int   succeedGettingWord;

  if ((fp = fopen(WORD_FILE, "r")) == NULL) {
      fprintf(stderr,"FATAL:Failed to read the file:%s\n", WORD_FILE);
      exit(1);
  }
  fseek(fp,0,SEEK_END);
  dictionaryFileSize = ftell(fp);
  succeedGettingWord = FALSE;
  while (!succeedGettingWord) {
      pos = rand()%dictionaryFileSize;
      fseek(fp, pos, SEEK_SET);
      fgets(word, WORD_LEN, fp);
      if (fgets(word, WORD_LEN, fp) != NULL) {
          wordLength = strlen(word) - 1;
          word[wordLength] = '\0';
          if (wordLength >= MIN_LETTERS_IN_A_WORD){
              succeedGettingWord = TRUE;
          }
      }
  }
  fclose(fp);
}

int   play(char *word) {
  char  answer[WORD_LEN];
  char  dummy;
  int   count = 0;
  int   guessed = FALSE;

  printf("\n");
  showStatus(word);
  scanf("%s%c", answer, &dummy);
  while (word[count] != '\0') {
    if (answer[count] != word[count]) {
      guessed = FALSE;
      break;
    } else {
      guessed = TRUE;
    }
    count++;
  }
  printf("\n");
  if (guessed){
      printf("o! %s\n",word);
  }else{
      printf("x! The correct answer is '%s'\n",word);
  }
  return (guessed);
}

void  showStatus(char *word)
{
  int   count = 0;

  putchar('\n');
  while (*word != '\0'){
    if (count != 2 && count != 3) {
      putchar(*word);
    } else {
      putchar('-');
    }
    count++;
    word++;
  }
  putchar('\n');
}
