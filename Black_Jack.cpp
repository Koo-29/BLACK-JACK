#include "game_Rules.h"

int player_total = 0, dealer_total = 0, aceCount = 0, playerScore = 0, dealerScore = 0;
vector<string> player_drawCard;

int main()
{
  int option;
  char choice;
  bool run = true;
  while (run)
  {
    cout << "Welcome to Blackjack!" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. To See Rules" << endl;
    cout << "2. Play Game" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
      displayRules();
      break;

    case 2:
      initDeck();
      shuffler();
      do
      {
        dealerTurn();
        playerTurn();
        do
        {
          cout << "Do you want to hit(H) or sit(S) ? ";
          cin >> choice;
          playerOption(choice);

          if (choice == 'S' || player_total > 21)
          {
            player_drawCard.clear();
            break;
          }
        } while (true);
        dealerOption();
        checkWinner(player_total, dealer_total);
      } while (playerScore < 3 && dealerScore < 3);
      if (playerScore > dealerScore)
        cout << "You are the winner!\n";
      else
        cout << "You lost!\n";
      playerScore = 0, dealerScore = 0;
      break;

    case 3:
      cout << "Thank you for playing! Goodbye!" << endl;
      return 0;

    default:
      cout << "Invalid option. Please select 1, 2, or 3." << endl;
    }
  }
}