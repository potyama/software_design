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

int levelOne(t_PlayerStatus player){
	srand((unsigned)time(NULL));
    int cnt=0;
    int a,b,ans;
    int repeat;
    printf("This is level one questions\n");

	if(player.schoolGrade==1) {
		repeat=10;
	}
	else if(player.schoolGrade==2) {
		repeat=4;
	}
	else if(player.schoolGrade==3) {
		repeat=1;
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

	if(player.schoolGrade==2) {
		repeat=6;
	}
	else if(player.schoolGrade==3){
		repeat=3;
	} 
	else if(player.schoolGrade==4){
		repeat=1;
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
    t_PlayerStatus player = {1, 0, 1};
    t_PlayerScore first = {};
    checkStatus(player);

    while(player.schoolGrade < 3){
        int isFlag = tryExam(first, player);
        updateStatus(&player, isFlag);
        checkStatus(player);
    }
    finishMessage();
}