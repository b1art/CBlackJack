#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int main() {}

void displayMenu(){}

void startGame(){}

void displayRules(){}

void callDealer(int points, int sum, char card, int i, int score[]){}

void callGambler(int points, int sum, char card, int i, int score[]){}

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