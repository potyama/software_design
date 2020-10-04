#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int school_grade;
    int count_repeat_year;
    int turn;
} board;

typedef struct {
    int sum_points;
    int diff_point;
} grade;


void checkGrade(board person){
    printf("Your grade is %d,\nThe number of years of retention is %d,\nYour turn is %d.\n", person.school_grade, person.count_repeat_year, person.turn);
    printf("\n\n");
}

int shouldPromotion(grade add_point, board player){
    srand((unsigned)time(NULL));
    int cnt=0;
    int a,b,ans;

    for(int i = 0;i < 10; i++){
        switch (rand()%3){
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
            //case 2:
            default: {
                a = ((rand() % 10) + 1);
                b = ((rand() % 10) + 1);

                printf("%d * %d = ?\n", a, b);
                scanf("%d", &ans);

                if(a * b == ans)cnt++;

                break;
                }
/*
            case 3:
            do{
                a = ((rand() % 10) * player.school_grade + 1);
                b = ((rand() % 10) * player.school_grade + 2);
                printf("a=%d,b=%d\n",a,b);
            }while(a%b != 0);

                printf("%d / %d = ?\n", a, b);
                scanf("%d", &ans);
                if(a / b == ans)cnt++;

            break;*/
        }
    }

    add_point.sum_points = cnt * 10;
    add_point.diff_point = add_point.sum_points - 40;

    if(add_point.sum_points >= 60){
        printf("Your test score was %d. Difference is %d points.\nCongratulations. You've been promoted.\n", add_point.sum_points, add_point.diff_point);
        printf("\n\n");
        return TRUE;
    }
    printf("Your test score was %d. Difference is %d points.\nOops. You repeated a school year...   Cheer up! Work harder next time.\n", add_point.sum_points, add_point.diff_point);
    printf("\n\n");

    return FALSE;
}

void updateGrade(board *main_character, int isFlag){
    if(isFlag){
        main_character->school_grade++;
        main_character->turn++;
    }else{
        main_character->count_repeat_year++;
        main_character->turn++;
    }
}

void message(){
    printf("Good Bye:)\n");
}


int main(){
    board player = {1, 0, 1};
    grade first = {};
    checkGrade(player);

    while(player.school_grade < 5){
        int isFlag = shouldPromotion(first, player);
        updateGrade(&player, isFlag);
        checkGrade(player);
    }
    message();
}
