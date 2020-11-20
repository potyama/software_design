#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int schoolGrade;
    int countRepeatYear;
    int myTurn;
} t_PlayerStatus;

typedef struct {
    int sumScores;
    int diffScore;
} t_PlayerScore;


void checkStatus(t_PlayerStatus player){
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("You're currently a %d year student.\nYou repeated your grade %d time(s). This is your %d time(s).\n", player.schoolGrade, player.countRepeatYear, player.myTurn);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\n");
}

int tryExam(t_PlayerScore scores, t_PlayerStatus player){
    srand((unsigned)time(NULL));
    int cnt=0;
    int a,b,ans;
    printf("Let's try!\n\n");

    for(int i = 0;i < 10; i++){
        switch (rand()%4){
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
            case 2: {
                a = ((rand() % 10) + 1);
                b = ((rand() % 10) + 1);

                printf("%d * %d = ?\n", a, b);
                scanf("%d", &ans);

                if(a * b == ans)cnt++;

                break;
                }

            case 3:{
                a = ((rand() % 10) + 1);
                b = ((rand() % 10) + 1);
		        int c = a * b;

                printf("%d / %d = ?\n", c, a);
                scanf("%d", &ans);
                if(b == ans)cnt++;
                }
        }
    }

    scores.sumScores = cnt * 10;
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
    t_PlayerStatus player = {1, 0, 1};
    t_PlayerScore first = {};
    checkStatus(player);

    while(player.schoolGrade < 5){
        int isFlag = tryExam(first, player);
        updateStatus(&player, isFlag);
        checkStatus(player);
    }
    finishMessage();
}
