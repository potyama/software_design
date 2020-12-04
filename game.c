#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


#define WORD_FILE               "./dict"
#define WORD_LEN                50
#define MIN_LETTERS_IN_A_WORD   5

typedef struct {
    int schoolGrade;
    int countRepeatYear;
    int myTurn;
    int myGakka;
} t_PlayerStatus;

typedef struct {
    int sumScores;
    int diffScore;
} t_PlayerScore;


void  getWord(char *word) {
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
    
    if(player.myGakka==1){
        printf("You are mechanical engineering student");
    }
    else if(player.myGakka==2){
        printf("You are electrical engineering student");
    }
    else if(player.myGakka==3){
        printf("You are electrical control engineering student");
    }
    else if(player.myGakka==4){
        printf("You are information and computer engineering student");
    }
    else if(player.myGakka==5){
        printf("You are civil engineering student");
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\n");
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

int levelOne(t_PlayerStatus player){
	srand((unsigned)time(NULL));
    int cnt=0;
    int a,b,ans;
    int repeat;
    printf("This is level one questions\n");

    switch (player.schoolGrade){
        case 1:
		    repeat=10;
            break;

        case 2:
		    repeat=4;
            break;

        case 3:
        	repeat=1;
            break;
    }

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
    int repeat;
    printf("This is level two question\n");

    switch (player.schoolGrade){
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
    int repeat;
    char word[WORD_LEN], answer[WORD_LEN];
    char dummy;



    switch (player.schoolGrade){
    case 3:
        repeat=6;
        break;
    case 4:
        repeat=3;
        break;
    case 5:
        repeat=1;
        break;
    }
    printf("e.g. \nap--e  -> apple\n\nApple -> Apple\n\n");
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

void finishMessage(){
    printf("Good Bye:)\n");
}


int main(){
    t_PlayerStatus player = {3, 0, 1};
    t_PlayerScore first = {};
    int gakka;
    printf("Select Your Gakka : \n");
    printf("1:Mechanical 2:Electrical 3:Control 4:Information 5:Civil \n");
    scanf("%d", &gakka);

    t_PlayerStatus player.myGakka = gakka;
    checkStatus(player);

    while(player.schoolGrade < 4){
        int isFlag = tryExam(first, player);
        updateStatus(&player, isFlag);
        checkStatus(player);
    }
    finishMessage();
}