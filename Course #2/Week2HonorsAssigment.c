/** 
 * Author: Miller Quintero
 * Date: Jul 08, 2024
 * Title: Random Cards and Probabilities
 * Program: This programs generate a deck or cards using structures and pseudorandom algorithms, furthermore a probabilistic calculation, 
 * for simplicity, it no consider the joker cards
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE   52
#define HAND_SIZE   7

typedef enum {SPADES, HEARTS, DIAMONDS, CLUBS
}suit;

typedef struct{
    suit suits;
    short pips;
}card;

/* Headers Proto-type functions */
void generateDeck(card* emptyDeck);
void shuffleDeck(card* deck);
void giveHand(card* deck, card* hand);
uint8_t analizeHand(card* hand);
void calculateProbabilities(uint32_t samples);
void printCard(card deckCard);

int main(void){
    srand(time(NULL));
    calculateProbabilities(1000000);

    /* If you wanna see one random hand, you can dis-comment this part of the code */

    // card fullDeck[DECK_SIZE] = {0};
    // card hand[HAND_SIZE] = {0};
    // generateDeck(fullDeck);
    // shuffleDeck(fullDeck);
    // giveHand(fullDeck, hand);
    // printf("Now, after shuffle the deck and give the hand, we have in the hand:\n");
    // for(char k = 0; k < HAND_SIZE; k++){
    //     printf("#%hhu ", k+1);
    //     printCard(*(hand+k));
    // }
    return 0;
}

/** Function to generate the organized deck */
void generateDeck(card* emptyDeck){
    uint8_t index = 0;
    for(uint8_t i = SPADES; i <= CLUBS; i++){
        for(uint8_t j = 1; j <= 13; j++){
            (*(emptyDeck+index)).suits = i;
            (*(emptyDeck+index)).pips = j;
            index++;
        } 
    }
}

/** Function responsible of shuffle the deck in a pseudo-random way */
void shuffleDeck(card* deck){
    for(uint8_t i = 0; i < DECK_SIZE; i++){
        card temporalCard = *(deck+i);
        uint8_t r = rand()%DECK_SIZE;
        *(deck+i) = *(deck+r);
        *(deck+r) = temporalCard;
    }
}

/** Function that takes the first 7 cards of the shuffle deck */
void giveHand(card* deck, card* hand){
    for(uint8_t i = 0; i < HAND_SIZE; i++){
        *(hand+i) = *(deck+i);
    }
}

/** Function that analize the hand, to determine what type of hand it is */
uint8_t analizeHand(card* hand){
    /* This array will contain the number of times that a pip is repeated,
    for example, the position #5 of the array, contains the number of repetitions
    of the pip #5 in the hand */
    uint32_t play[13] = {0};
    for(uint8_t i = 0; i < HAND_SIZE; i++){
        // This instruction get the pip of the hand, and increment 1 in his corresponding 'play' array position
        play[(*(hand+i)).pips]++;
    }

    uint8_t noPair = 0, onePair = 0, twoPair = 0, threeKind = 0, fourKind = 0, fullHouse = 0;
    for (uint8_t k = 0; k < 13; k++){
        // If we have 4 equals pips, we have a fourKind hand
        if(play[k] == 4){
            fourKind++;
        }
        // If we have 3 equals pips, we have a threeKind hand
        else if(play[k] == 3){
            threeKind++;
        }
        // If we have 2 equals pips, we have a one pair
        else if(play[k] == 2){
            onePair++;
        }
        else{
            ;   //NOP
        }
    }

    // If we have two or more pairs, we have a two pair hand
    twoPair = (onePair >= 2)? 1:0;
    // If we have a three kind together with a one pair, we have a Full House hand
    fullHouse = ((threeKind == 1)&&(onePair == 1))? 1:0;

    //This is on priority order, starts with the best hand in our case, and ends up with no pair hand (the worst)
    if(fourKind){
        return 5;
    }
    else if(fullHouse){
        return 4;
    }
    else if(threeKind){
        return 3;
    }
    else if(twoPair){
        return 2;
    }
    else if(onePair){
        return 1;
    }
    // If we don't have any of the previous hand, we have a no-pair hand
    else{
        return 0;
    }
}

/** Function that calculates and prints the probabilities of every hand, in a simulation of #samples */
void calculateProbabilities(uint32_t samples){
    uint32_t noPair = 0, onePair = 0, twoPair = 0, threeKind = 0, fullHouse = 0, fourKind = 0;
    for(uint32_t n = 0; n < samples; n++){
        card deck[DECK_SIZE] = {0};
        card hand[HAND_SIZE] = {0};
        generateDeck(deck);
        shuffleDeck(deck);
        giveHand(deck,hand);
        switch(analizeHand(hand)){
            case(0):{
                noPair++;
                break;
            }
            case(1):{
                onePair++;
                break;
            }
            case(2):{
                twoPair++;
                break;
            }
            case(3):{
                threeKind++;
                break;
            }
            case(4):{
                fullHouse++;
                break;
            }
            case(5):{
                fourKind++;
                break;
            }
            default:{
                ;   // NOP
                break;
            }
        }
    }
    printf("The probability to get a no-pair hand is %.6f%%.\n", ((float)noPair/((float)samples))*100.00f);
    printf("The probability to get a one-pair hand is %.6f%%.\n", ((float)onePair/((float)samples))*100.00f);
    printf("The probability to get a two-pair hand is %.6f%%.\n", ((float)twoPair/((float)samples))*100.00f);
    printf("The probability to get a three-kind hand is %.6f%%.\n", ((float)threeKind/((float)samples))*100.00f);
    printf("The probability to get a full-house hand is %.6f%%.\n", ((float)fullHouse/((float)samples))*100.00f);
    printf("The probability to get a four-kind hand is %.6f%%.\n", ((float)fourKind/((float)samples))*100.00f);
}

/** Function to print a single card */
void printCard(card singleCard){
    const char* suits[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    const char* pips[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    printf("Card: %s of %s.\n", pips[singleCard.pips-1], suits[singleCard.suits]);
}