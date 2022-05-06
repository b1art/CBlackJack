#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#define MAX_TIME 2 //2000 for windows
void displayMenu();
void startGame();
void displayRules();

void callGambler(int points, int sum, char card, int i, int score[]);
void callDealer(int points, int sum, char card, int i, int score[]);

void saveScore(int sum, int i, int score[]);
void displayScore(int score[], int gamblers);

void dealCard(char *card, int *points, int *sum);
void chooseCardSuit(char *suit);
void clearScreen();
void saveScore(int sum, int i, int score[]){
    score[i] = sum;
}
int main() {

}
int getch (void) //only for mac
{
    int ch;
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON|ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}
void displayMenu(){
    char option, answer;
    int valid;

    clearScreen();

    printf("# Blackjack # \n\n");
    printf("1) Start\n");
    printf("2) Rules\n");
    printf("3) Exit\n\n");

    do{
        valid = 1;

        option = getch();

        if(option != '1' && option != '2' && option != '3')
            valid = 0;
    }while(!valid);

    switch(option){
        case '1':
            startGame();
            sleep(MAX_TIME); //Sleep for windows

            printf("\nPRESS ENTER TO RETURN TO THE MENU");

            do{
                answer = getch();
            }while(answer != 13);

            displayMenu();
            break;
        case '2':
            displayRules();
            break;
        case '3':
            exit(0);
    }
}

void startGame(){}

void displayRules(){

    int answer;

    clearScreen();

    printf("* The cards have the same number of points as their values (indepedent of the suit).\n");
    printf("* A (ace) has value 1, on the other hand, K (king), Q (queen) and J (jack) have value 10.\n");
    printf("* Each GAMBLER (user), as well as the DEALER (software), begin with two cards.\n");
    printf("* There is a 'Hit or Stand' option for every additional card.\n");
    printf("* If you hit, you get one more card and it goes on until: you stop (stand), lose (bust) or win (blackjack).\n");
    printf("* The goal is to get the maximum score in the table, with the upper limite of 21, 22+ points and you bust.\n");
    printf("* At the end, the player with maximum score wins, however a tie can also occur.\n");

    printf("\nPRESS ENTER TO RETURN TO THE MENU");

    do{
        answer = getch();
    }while(answer != 13);

    displayMenu();
}

void callDealer(int points, int sum, char card, int i, int score[]){}

void callGambler(int points, int sum, char card, int i, int score[]){
    char answer;

    printf("GAMBLER %d\n\n", i+1);
    sleep(1000);

    dealCard(&card, &points, &sum);
    sleep(MAX_TIME);

    while(sum < 21){
        dealCard(&card, &points, &sum);
        sleep(MAX_TIME);

        if(sum >= 21){
            if(sum > 21)
                printf("You have busted...");
            else
                printf("BLACKJACK!");

            sleep(MAX_TIME);
            clearScreen();
            break;
        }

        printf("Hit or Stand? H/S");

        do{
            answer = toupper(getch());
        }while(answer != 'H' && answer != 'S');

        if(answer == 'S'){
            printf("\n\nYou have stood...");
            sleep(MAX_TIME);
            clearScreen();
            break;
        }

        printf("\n\n");
    }

    saveScore(sum, i, score);




}

void dealCard(char *card, int *points, int *sum){
    char cards[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'}, suit[8];
    int aux;

    aux = rand()%13;

    *card = cards[aux];

    if(aux == 0){
        *points = 1;
    }
    else
    if(aux >= 9){
        *points = 10;
    }
    else{
        *points = aux+1;
    }

    *sum += *points;

    chooseCardSuit(suit);

    if(*card == '0')
        printf("10 of %s\n", suit);
    else
        printf("%c of %s\n", *card, suit);

    printf("Accumulated score: %i points\n\n", *sum);
}

void chooseCardSuit(char suit[]){
    char suits[] = {'d', 's', 'h', 'c'};
    int aux;

    aux = rand()%4;

    switch(suits[aux]){
        case 'd':
            strcpy(suit, "Diamonds");
            break;
        case 's':
            strcpy(suit, "Spades");
            break;
        case 'h':
            strcpy(suit, "Hearts");
            break;
        case 'c':
            strcpy(suit, "Clubs");
    }
}

void clearScreen(){
    system("cls");
}