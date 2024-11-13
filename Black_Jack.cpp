#include "game_Rules.h"

 int player_total = 0,dealer_total = 0;



int main(){
 

  char choice;
  
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