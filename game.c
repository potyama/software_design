#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int school_grade;
    int count_repeat_year;
    int my_turn;
} board;

typedef struct {
    int sum_points;
    int diff_point;
} point;


void checkGrade(board person){
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("You're currently a %d year student.\nYou repeated your grade %d time(s). This is your %d time(s).\n", person.school_grade, person.count_repeat_year, person.my_turn);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\n");
}

int tryExam(point add_point, board player){
    srand((unsigned)time(NULL));
    int cnt=0;
    int a,b,loop_i,ans;
    printf("Let's try!\n\n");

    for(int i = 0;i < 10; i++){
        loop_i = 0;
        switch (rand()%4){
            case 0:{
                a = ((rand() % 10 * player.school_grade) + 1);
                b = ((rand() % 10 * player.school_grade) + 1);

                printf("%d + %d = ?\n", a, b);
                scanf("%d", &ans);
                if(a + b == ans)cnt++;

                break;
                }
            case 1:{
                a = ((rand() % 10 * player.school_grade) + 1);
                b = ((rand() % 10 * player.school_grade) + 1);

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

    add_point.sum_points = cnt * 10;
    add_point.diff_point = add_point.sum_points - 40;

    printf("Your marks is %d.\nYou are %d away from failing.\n\n", add_point.sum_points, add_point.diff_point);

    if(add_point.sum_points >= 60){
        printf("Congrats! You went up a grade!\n Let's keep at it for the next one too!");
        printf("\n\n");
        return TRUE;
    }
    printf("Oh my... Looks like you gonna have to repeat the year.\nDon't worry!\nLet's get better for the next one!", add_point.sum_points, add_point.diff_point);
    printf("\n\n");

    return FALSE;
}

void updateGrade(board *main_character, int isFlag){
    if(isFlag){
        main_character->school_grade++;
        main_character->my_turn++;
    }else{
        main_character->count_repeat_year++;
        main_character->my_turn++;
    }
}

void finishMessage(){
    printf("Good Bye:)\n");
}


int main(){
    board player = {1, 0, 1};
    point first = {};
    checkGrade(player);

    while(player.school_grade < 5){
        int isFlag = tryExam(first, player);
        updateGrade(&player, isFlag);
        checkGrade(player);
    }
    finishMessage();
}
