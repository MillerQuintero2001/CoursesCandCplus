/** 
 * Author: Miller Quintero
 * Date: Jul 08, 2024
 * Title: Random Cards and Probabilities
 * Program: This programs generate card from a deck using structures and pseudorandom algorithms, furthermore a probabilistic calculation
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


typedef enum {JOKER,ACE,TWO,THREE,FOUR,FIVE,
SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING
}value;

typedef struct{
    value pips;
    short suit;
}card;

/* Headers Proto-type functions */
card randomCard(void);
void shuffleHand(card* hand);
double calculateProbabilities(void);
void printCard(card deckCard);

int main(void){
    srand(time(NULL));
    card hand[7] = {0};
    shuffleHand(hand);
    for(char j = 0; j < 7; j++){
        printf("#%hhu ", j+1);
        printCard(*(hand+j));
    }
    return 0;
}

card randomCard(void){
    card pseudoRandomCard;
    pseudoRandomCard.pips = rand()%KING + 1;
    pseudoRandomCard.suit = rand()%4 + 1;
    return pseudoRandomCard;
}

void shuffleHand(card* hand){
    for(int i = 0; i < 7; i++){
        *(hand+i) = randomCard();
    }
}

double calculateProbabilities(void){
    ;
}

void printCard(card deckCard){
    char* suit = NULL;
    char* value = NULL;
    bool jokerFlag = false;
    bool specialName = false;

    // Switch-case to get the suit
    switch (deckCard.suit){
        case(1):{
            suit = "Spades";
            break;
        }
        case(2):{
            suit = "Hearts";
            break;
        }
        case(3):{
            suit = "Diamonds";
            break;
        }
        case(4):{
            suit = "Clubs";
            break;
        }
        default:{
            suit = "Unknown";
            break;
        }
    }

    // Switch-case to get the number
    switch (deckCard.pips){
        case(JOKER):{
            value = "Joker";
            jokerFlag = true;
            break;
        }
        case(ACE):{
            value = "Ace";
            specialName = true;
            break;
        }
        case(JACK):{
            value = "Jack";
            specialName = true;
            break;
        }
        case(QUEEN):{
            value = "Queen";
            specialName = true;
            break;
        }
        case(KING):{
            value = "King";
            specialName = true;
            break;
        }
        default:{
            value = "Unknown";
            break;
        }
    }
    if(!jokerFlag){
        if(specialName){
            printf("Card: %s of %s.\n", value, suit);
        }
        else{
            printf("Card: %hhu of %s.\n", deckCard.pips, suit);
        }
    }
    else{
        printf("Card: %s.\n",value);
    }
}