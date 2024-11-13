#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

extern int player_total, dealer_total, aceCount;

void displayRules();
void initDeck();
void shuffler();
string getCard();
int charToInt(string card);
void dealerOption();
void playerTurn();
void checkWinner(int player_total, int dealer_total);
void dealerTurn();
int playerOption(char choice);
void dealerOption();
int adjustForAce(int total);