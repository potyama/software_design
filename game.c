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
    int sum_dices;
    int diff_fail;
} dice;


void checkGrade(board person){
    printf("Your grade is %d,\nThe number of years of retention is %d,\nYour turn is %d.\n", person.school_grade, person.count_repeat_year, person.turn);
    printf("\n\n");
}

int shouldPromotion(dice addDice, board player){
    srand((unsigned)time(NULL));
    int cnt=0;

    for(int i = 0;i < 10; i++){
        int a = ((rand()% 10 * player.school_grade) + 1);
        int b = ((rand()% 10 * player.school_grade) + 1);
        int c;
        printf("%d + %d = ?\n", a, b);
        scanf("%d", &c);
        if(a + b == c)cnt++;
    }

    addDice.sum_dices = cnt * 10;

    if(addDice.sum_dices >= 60){
        printf("Your test score was %d. Difference is %d points.\nCongratulations. You've been promoted.\n", addDice.sum_dices, addDice.diff_fail);
        printf("\n\n");
        return TRUE;
    }
    printf("Your test score was %d. Difference is %d points.\nOops. You repeated a school year...   Cheer up! Work harder next time.\n", addDice.sum_dices, addDice.diff_fail);
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
    dice first = {};
    checkGrade(player);

    while(player.school_grade != 6){
        int isFlag = shouldPromotion(first, player);
        updateGrade(&player, isFlag);
        checkGrade(player);
    }
    message();
}
