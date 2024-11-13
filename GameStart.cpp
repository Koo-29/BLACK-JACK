#include<iostream>
#include<vector>
#include "deck.h"
#include<string>
using namespace std;

char card_1,card_2,card_3,card_4;
int player_total,dealer_total;
char choice;
vector<char> player_drawCard;

void playerTurn(){
  card_1 = getCard();
  card_2 = getCard();
  cout << "Your's hand cards: " << card_1 << " " << card_2  << endl;
  player_total = charToInt(card_1) + charToInt(card_2);
  cout << "Your hand total value is " << player_total << endl;

}

void checkWinner(int player_total,int dealer_total){
  if ((player_total > 21 && dealer_total > 21 )|| player_total == dealer_total ){
    cout << "It's a tie!";
  }
  
  else if(player_total > dealer_total && player_total < 21){
    cout << "You wins!";
  }

  else if (player_total  < dealer_total && dealer_total < 21 ){
    cout << "Dealer wins!";
  }

  else if(player_total > 21 && dealer_total < 21){
    cout << "You are bust!";
  }
  else{
    cout << "Dealer bust!You wins!";
  }
  

}

void dealerTurn(){
  card_3 = getCard();
  card_4 = getCard();
  dealer_total = charToInt(card_3) + charToInt(card_4);
  cout << "Dealer's card "<<  "[Hidden]" <<" " << card_4 << endl;
}
void dealerOption() {
    cout << "Dealer reveals hidden card: " << card_3 << " and " << card_4 << endl;
    while (dealer_total < 17) {
        char new_card = getCard();
        cout << "Dealer hits and draws a new card " << new_card << endl;
        dealer_total += charToInt(new_card);
    }
    cout << "Dealer sits with a total value of " << dealer_total << endl;
    
}
int playerOption(char choice){
   if (choice == 'S'){
      cout << "You sit with " << card_1 << " " << card_2 ;
      for(int i = 0;i < player_drawCard.size();i++){
        cout << " " << player_drawCard[i]  ;
        if( i == player_drawCard.size() - 1){
          cout << "\n";
        }
      }
      
      cout << "\nYour total value is " << player_total <<endl;
    }
    if (choice == 'H'){
      char new_card = getCard();
      player_drawCard.push_back(new_card);
      cout << "You draw a new card " << new_card << endl;
      player_total += charToInt(new_card);
      cout << "Your new total value is " << player_total << endl;
    }
    return player_total;
}

int main(){
  string answer;
  
  initDeck();
  shuffler();
  dealerTurn();
  playerTurn();
  do{
    cout << "Do you want to hit(H) or sit(S) ? " ;
    cin >> choice;
    playerOption(choice);

    if (choice == 'S' || player_total > 21){
      break;
    }
  } while(true);
  dealerOption();
  checkWinner(player_total,dealer_total);

  
  
}