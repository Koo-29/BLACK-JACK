#include<iostream>
#include<vector>
#include "deck.h"
using namespace std;

int card_1,card_2,card_3,card_4,player_total,dealer_total;
char choice;
void playerTurn(){
  card_1 = getCard();
  card_2 = getCard();
  cout << "Your's hand cards: " << endl;
  cout << card_1 << " " << card_2 << endl;
  player_total = charToInt(card_1) + charToInt(card_2);
  cout << "Your hand total value is " << player_total << endl;
  cout << "Do you want to Hit(H) or Sit(S)? ";
  cin.get(choice);
}

void checkWinner(int player_total,int dealer_total){
  if ((player_total > 21 && dealer_total > 21 )|| player_total == dealer_total ){
    cout << "It's a tie!";
  }
  
  if (player_total > dealer_total && player_total < 21){
    cout << "You wins!";
  }

  if (player_total  < dealer_total && dealer_total < 21 ){
    cout << "Dealer wins!";
  }

  if (player_total > 21){
    cout << "You are bust!";
  }
  if (dealer_total > 21){
    cout << "You wins, dealer bust!";
  }
}

void dealerTurn(){
  card_3 = getCard();
  card_4 = getCard();
  dealer_total = charToInt(card_3) + charToInt(card_4);
  cout << "Dealer's card \n";
  cout << "[Hidden]  " << card_4 << endl;
  
  while(dealer_total < 17){
    char new_card = getCard();
    cout << "Dealer hits and draws a new card "<< new_card << endl;
    dealer_total += charToInt(new_card);
  }

  cout << "Dealer stands with [Hidden] " << card_4 << endl;
  }

int option(char option){
   if (option == 'S'){
      cout << "You sit with " << card_1 << "and" << card_2 << endl;
      cout << "Your total value is " << player_total <<endl;
    }
    if (option == 'H'){
      char new_card = getCard();
      cout << "You draw a new card " << new_card << endl;
      player_total += charToInt(new_card);
      cout << "Your new total value is " << player_total << endl;
    }
    return player_total;
}

int main(){
  initDeck();
  shuffler();
  dealerTurn();
  playerTurn();
  checkWinner(player_total,dealer_total);


}