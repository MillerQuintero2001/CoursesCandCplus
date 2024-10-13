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
#include <stdbool.h>
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
bool isFlush(card* hand);
bool isStraight(card* hand);
bool isStraightFlush(card* hand);
bool isRoyalFlush(card* hand);
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
            (emptyDeck+index)->suits = i;
            (emptyDeck+index)->pips = j;
            index++;
        } 
    }
}

/** Function responsible of shuffle the deck in a pseudo-random way using Fisher-Yates algorithm */
void shuffleDeck(card* deck){
    for (uint8_t i = DECK_SIZE - 1; i > 0; i--) {
        // Generate a random index between 0 and i
        uint8_t r = rand() % (i + 1);
        // Swap cards
        card temporalCard = deck[i];
        deck[i] = deck[r];
        deck[r] = temporalCard;
    }
}

/** Function that takes the first 7 cards of the shuffle deck */
void giveHand(card* deck, card* hand){
    for(uint8_t i = 0; i < HAND_SIZE; i++){
        *(hand+i) = *(deck+i);
    }
}

/** Function to know if a hand is a flush */
bool isFlush(card* hand){
    /* Array to save how many cards are of each suit, the positions are
    0 = SPADES, 1 = HEARTS, 2 = DIAMONDS, 3 = CLUBS*/
    uint8_t play[4] = {0};
    for(uint8_t j = 0; j < HAND_SIZE; j++){
        play[(hand+j)->suits]++;
        if(play[(hand+j)->suits] >= 5){
            return true;
        }
        else{
            continue;
        }
    }
    return false;
}

/** Function to check if a hand is a straight */
bool isStraight(card* hand){
    /* Create an array of fourteen elements, because ACE in straight can function as 1 and as 14*/
    uint8_t play[14] = {0};
    for(uint8_t j = 0; j < HAND_SIZE; j++){
        uint8_t pip = (*(hand+j)).pips-1;
        play[pip]++;
        // If is an ACE, is necessary also add one to the card number 14 position
        if(pip == 0){
            play[13]++;
        }
        else{
            continue;
        }
    }
    for(uint8_t k = 0; k < 10; k++){
        uint8_t consecutivePipCounter = 0;
        for(uint8_t i = k; i < k + 5; i++){
            if(*(play+i) >= 1){
                consecutivePipCounter++;
                if(consecutivePipCounter >= 5){
                    return true;     
                }
                else{
                    continue;
                }
            }
            // If there is no more consecutive pips, is time to break this iteration
            else{
                break;
            }
        }
    }
    return false;
}

/** Function to check if a hand is a straight flush */
bool isStraightFlush(card* hand){
    if(isFlush(hand)){
        uint8_t playSuits[4][14] = {0};
        for(uint8_t i = 0; i < HAND_SIZE; i++){
            uint8_t pip = (*(hand+i)).pips-1;
            playSuits[(hand+i)->suits][pip]++;
            // If is an ACE, is necessary also add one to the card number 14 position
            if(pip == 0){
                playSuits[(hand+i)->suits][13]++;
            }
            else{
                continue;
            }
        }
        // Now, is necessary verify in there is one suit with a straight
        for(uint8_t j = SPADES; j <= CLUBS; j++){
            for(uint8_t k = 0; k < 10; k++){
                uint8_t consecutivePipCounter = 0;
                for(uint8_t n = k; n < k + 5; n++){
                    if(playSuits[j][n] >= 1){
                        consecutivePipCounter++;
                        if(consecutivePipCounter >= 5){
                            return true;     
                        }
                        else{
                            continue;
                        }
                    }
                    // If there is no more consecutive pips, is time to break this iteration
                    else{
                        break;
                    }
                }
            }
        }
        return false;
    }
    else{
        return false;
    }
}

/** Function to check if a hand is a straight flush */
bool isRoyalFlush(card* hand){
    if(isFlush(hand)){
        uint8_t playSuits[4][14] = {0};
        for(uint8_t i = 0; i < HAND_SIZE; i++){
            uint8_t pip = (*(hand+i)).pips-1;
            playSuits[(hand+i)->suits][pip]++;
            // If is an ACE, is necessary also add one to the card number 14 position
            if(pip == 0){
                playSuits[(hand+i)->suits][13]++;
            }
            else{
                continue;
            }
        }

        /* Now it's time to check if the flush is a royal (10, Jack = 11, Queen = 12, King = 13 and Ace = 14)
        for that reason is only necessary check the last 5 position in each suit */
        for(uint8_t j = SPADES; j < CLUBS; j++){
            uint8_t consecutivePipCounter = 0;
            for(uint8_t k = 9; k < 14; k++){
                if(playSuits[j][k] >= 1){
                    consecutivePipCounter++;
                    if(consecutivePipCounter == 5){
                        return true;
                    }
                    else{
                        continue;
                    }
                }
                else{
                    break;
                }
            }
        }
        return false;
    }
    else{
        return false;
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
        play[(hand+i)->pips-1]++;
    }

    uint8_t noPair = 0, onePair = 0, twoPair = 0, threeKind = 0, fullHouse = 0, fourKind = 0;
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
    if(isRoyalFlush(hand)){
        return 9;
    }
    else if(isStraightFlush(hand)){
        return 8;
    }
    else if(fourKind){
        return 7;
    }
    else if(fullHouse){
        return 6;
    }
    else if(isFlush(hand)){
        return 5;
    }
    else if(isStraight(hand)){
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
    uint32_t noPair = 0, onePair = 0, twoPair = 0, threeKind = 0, straight = 0, flush = 0, fullHouse = 0, fourKind = 0, straightFlush = 0, royalFlush = 0;
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
                straight++;
                break;
            }
            case(5):{
                flush++;
                break;
            }
            case(6):{
                fullHouse++;
                break;
            }
            case(7):{
                fourKind++;
                break;
            }
            case(8):{
                straightFlush++;
                break;
            }
            case(9):{
                royalFlush++;
                break;
            }
            default:{
                ;           // NOP action
                break;
            }
        }
    }
    printf("No-pair hand probability: \t\t%9.6f%%.\n", ((double)noPair/((double)samples))*100.00);
    printf("One-pair hand probability: \t\t%9.6f%%.\n", ((double)onePair/((double)samples))*100.00);
    printf("Two-pair hand probability: \t\t%9.6f%%.\n", ((double)twoPair/((double)samples))*100.00);
    printf("Three-kind hand probability: \t\t%9.6f%%.\n", ((double)threeKind/((double)samples))*100.00);
    printf("Straight hand probability: \t\t%9.6f%%.\n", ((double)straight/((double)samples))*100.00);
    printf("Simple flush hand probability: \t\t%9.6f%%.\n", ((double)flush/((double)samples))*100.00);
    printf("Full-house hand probability: \t\t%9.6f%%.\n", ((double)fullHouse/((double)samples))*100.00);
    printf("Four-kind hand probability: \t\t%9.6f%%.\n", ((double)fourKind/((double)samples))*100.00f);
    printf("Straight flush hand probability: \t%9.6f%%.\n", ((double)straightFlush/((double)samples))*100.00);
    printf("Royal flush hand probability: \t\t%9.6f%%.\n", ((double)royalFlush/((double)samples))*100.00);
}

/** Function to print a single card */
void printCard(card singleCard){
    const char* suits[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    const char* pips[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    printf("Card: %s of %s.\n", pips[singleCard.pips-1], suits[singleCard.suits]);
}