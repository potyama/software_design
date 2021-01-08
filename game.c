#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define Mecha 101
#define Elect 102
#define Denshi 103
#define Jouhou 104
#define Civil 105

#define WORD_FILE               "./dict"
#define WORD_LEN                50
#define MIN_LETTERS_IN_A_WORD   5

typedef struct {
    int schoolGrade;
    int countRepeatYear;
    int myTurn;
} t_PlayerStatus;

typedef struct {
    int sumScores;
    int diffScore;
} t_PlayerScore;


void getWord(char *word){
    int wordLength;
    int succeedGettingWord;
    long dictionaryFileSize;
    long pos;
    FILE *fp;

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


void checkStatus(t_PlayerStatus player){
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("You're currently a %d year student.\nYou repeated your grade %d time(s). This is your %d time(s).\n", player.schoolGrade, player.countRepeatYear, player.myTurn);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\n");

    if(player.schoolGrade == 5){
        printf("Good Bye:)\n");
    }

}

void showStatus(char *word)
{
    int   count = 0;

    printf("\n");
    while (*word != '\0'){
        if (count != 2 && count != 3) {
            printf("%c", *word);
        }else{
            printf("-");
        }
        count++;
        word++;
    }
    printf("\n");
}

int chooseRepeat(t_PlayerStatus player){
    int repeat;
    switch (player.schoolGrade){
        case 1:
	        repeat=10;
            break;
        case 2:
            repeat=6;
            break;
        case 3:
            repeat=3;
            break;
        case 4:
            repeat=1;
            break;
    }
    return repeat;
}

int levelOne(t_PlayerStatus player){
	srand((unsigned)time(NULL));
    int cnt=0;
    int a,b,ans;
    printf("This is level one questions\n");

    int repeat = chooseRepeat(player);

	for(int i=0; i<repeat; i++){
		switch (rand()%2){
            case 0:{
                a = ((rand() % 10 * player.schoolGrade) + 1);
                b = ((rand() % 10 * player.schoolGrade) + 1);

                printf("%d + %d = ?\n", a, b);
                scanf("%d", &ans);
                if(a + b == ans)cnt++;

                break;
            }

            case 1:{
                a = ((rand() % 10 * player.schoolGrade) + 1);
                b = ((rand() % 10 * player.schoolGrade) + 1);

                printf("%d - %d = ?\n", a, b);
                scanf("%d", &ans);

                if(a - b == ans)cnt++;

                break;
            }
        }
	}
    printf("level one count is %d\n", cnt);
    return cnt;
}

int levelTwo(t_PlayerStatus player){
	srand((unsigned)time(NULL));
    int cnt=0;
    int a,b,ans;
    printf("This is level two question\n");

    int repeat = chooseRepeat(player);

	for(int i=0; i<repeat; i++){
		switch (rand()%2){
            case 0: {
                a = ((rand() % 10) + 1);
                b = ((rand() % 10) + 1);

                printf("%d * %d = ?\n", a, b);
                scanf("%d", &ans);

                if(a * b == ans)cnt++;

                break;
                }

            case 1:{
                a = ((rand() % 10) + 1);
                b = ((rand() % 10) + 1);
		        int c = a * b;

                printf("%d / %d = ?\n", c, a);
                scanf("%d", &ans);
                if(b == ans)cnt++;

                break;
            }
        }
	}
    printf("level two count is %d\n", cnt);
    return cnt;
}

int levelThree(t_PlayerStatus player){
    int cnt = 0;
    int guessed = FALSE;
    char word[WORD_LEN], answer[WORD_LEN];
    char dummy;

    int repeat = chooseRepeat(player);

    printf("e.g. \nap--e  -> apple\n\nAp--e -> Apple\n\n");
	for(int i=0; i<repeat; i++){
        getWord(word);
        showStatus(word);
        scanf("%s%c", answer, &dummy);

        while (word[cnt] != '\0') {
            if (answer[cnt] != word[cnt]) {
                guessed = FALSE;
                break;
            }else{
                guessed = TRUE;
            }
            cnt++;
        }
        printf("\n");
        if (guessed){
            printf("Correct! nice :)\n '%s'\n",word);
        }else{
            printf("What a pity... :( The correct answer is '%s'\n",word);
        }
    }
    printf("level three count is %d\n", cnt);

    return cnt;
}

int tryExam(t_PlayerScore scores, t_PlayerStatus player){
    srand((unsigned)time(NULL));
    int total=0;
    int a,b,ans;
    printf("Let's try!\n\n");

    switch(player.schoolGrade){
        case 1:{
            int numOne = levelOne(player);
            total = numOne;
			break;
		}
		case 2:{
			int numOne = levelOne(player);
            int numTwo = levelTwo(player);
            total = numOne + numTwo;
            break;
        }
        case 3:{
            int numOne = levelOne(player);
            int numTwo = levelTwo(player);
            int numThree = levelThree(player);
            total = numOne + numTwo + numThree;
            break;
        }
        default:{
            total = 10;
        }
	}

    scores.sumScores = total * 10;
    scores.diffScore = scores.sumScores - 40;

    printf("Your marks is %d.\nYou are %d away from failing.\n\n", scores.sumScores, scores.diffScore);

    if(scores.sumScores >= 60){
        printf("Congrats! You went up a grade!\n Let's keep at it for the next one too!");
        printf("\n\n");
        return TRUE;
    }
    printf("Oh my... Looks like you gonna have to repeat the year.\nDon't worry!\nLet's get better for the next one!");
    printf("\n\n");

    return FALSE;

}


void updateStatus(t_PlayerStatus *player, int isFlag){
    if(isFlag){
        player->schoolGrade++;
        player->myTurn++;
    }else{
        player->countRepeatYear++;
        player->myTurn++;
    }
}


int main(){
    t_PlayerStatus player = {4, 0, 1};
    t_PlayerScore first = {};
    checkStatus(player);

    while(player.schoolGrade < 5){
        int isFlag = tryExam(first, player);
        updateStatus(&player, isFlag);
        checkStatus(player);
    }

}
