#include "game_Rules.h"
vector<char> player_drawCard;
vector<char> deck;
char card_1, card_2, card_3, card_4;

void initDeck()
{
  deck = {
      'A',
      '1',
      '2',
      '3',
      '4',
      '5',
      '6',
      '7',
      '8',
      '9',
      'J',
      'Q',
      'K',
      'A',
      '1',
      '2',
      '3',
      '4',
      '5',
      '6',
      '7',
      '8',
      '9',
      'J',
      'Q',
      'K',
      'A',
      '1',
      '2',
      '3',
      '4',
      '5',
      '6',
      '7',
      '8',
      '9',
      'J',
      'Q',
      'K',
      'A',
      '1',
      '2',
      '3',
      '4',
      '5',
      '6',
      '7',
      '8',
      '9',
      'J',
      'Q',
      'K',
      'A',
      '1',
      '2',
      '3',
      '4',
      '5',
      '6',
      '7',
      '8',
      '9',
      'J',
      'Q',
      'K',
      'A',
      '1',
      '2',
      '3',
      '4',
      '5',
      '6',
      '7',
      '8',
      '9',
      'J',
      'Q',
      'K',
      'A',
      '1',
      '2',
      '3',
      '4',
      '5',
      '6',
      '7',
      '8',
      '9',
      'J',
      'Q',
      'K',
      'A',
      '1',
      '2',
      '3',
      '4',
      '5',
      '6',
      '7',
      '8',
      '9',
      'J',
      'Q',
      'K',
  };
}

void shuffler()
{
  srand((unsigned)time(0));
  for (int i = 0; i < 104; i++)
    swap(deck[i], deck[rand() % 104]);
}

char getCard()
{
  char card = deck.front();
  deck.erase(deck.begin());
  return card;
}

int charToInt(char card)
{
  int cardInInt;
  if (card == 'J' || card == 'Q' || card == 'K')
  {
    cardInInt = 10;
  }

  else if (card == 'A')
    cardInInt = 11;

  else
    cardInInt = card - '0';

  return cardInInt;
}

int adjustForAce(int total)
{
  cout << aceCount;
  if (total > 21 && aceCount > 0)
  {
    total -= 10;
    aceCount--;
  }
  cout << aceCount;
  return total;
}

void playerTurn()
{
  card_1 = 'A';
  card_2 = '2';
  cout << "Your's hand cards: " << card_1 << " " << card_2 << endl;
  player_drawCard.push_back(card_1);
  player_drawCard.push_back(card_2);
  aceCount = (card_1 == 'A') + (card_2 == 'A');
  player_total = charToInt(card_1) + charToInt(card_2);
  player_total = adjustForAce(player_total);
  cout << "Your hand total value is " << player_total << endl;
}

void checkWinner(int player_total, int dealer_total)
{
  if ((player_total > 21 && dealer_total > 21) || player_total == dealer_total)
  {
    cout << "It's a tie!\n";
  }

  else if (player_total > dealer_total && player_total < 21)
  {
    cout << "You wins!\n";
  }

  else if (player_total < dealer_total && dealer_total < 21)
  {
    cout << "Dealer wins!\n";
  }

  else if (player_total > 21 && dealer_total < 21)
  {
    cout << "You are bust!\n";
  }
  else
  {
    cout << "Dealer bust! You wins!\n";
  }
}

void dealerTurn()
{
  card_3 = getCard();
  card_4 = getCard();
  dealer_total = charToInt(card_3) + charToInt(card_4);
  cout << "Dealer's card " << " [Hidden]" << " " << card_4 << endl;
}
void dealerOption()
{
  cout << "Dealer reveals hidden card: " << card_3 << " and " << card_4 << endl;
  while (dealer_total < 17)
  {
    char new_card = getCard();
    cout << "Dealer hits and draws a new card " << new_card << endl;
    dealer_total += charToInt(new_card);
  }
  cout << "Dealer sits with a total value of " << dealer_total << endl;
}
int playerOption(char choice)
{
  if (choice == 'S')
  {
    cout << "You sit with ";
    for (int i = 0; i < player_drawCard.size(); i++)
    {
      cout << " " << player_drawCard[i];
    }

    cout << "\nYour total value is " << player_total << endl;
  }
  if (choice == 'H')
  {
    char new_card = getCard();
    if (new_card == 'A')
      aceCount++;
    player_drawCard.push_back(new_card);
    cout << "You draw a new card " << new_card << endl;
    player_total += charToInt(new_card);
    player_total = adjustForAce(player_total);
    cout << "Your new total value is " << player_total << endl;
  }
  return player_total;
}

void displayRules()
{
  cout << "\n--- Blackjack Rules ---\n";
  cout << "1. The goal is to get as close to 21 without exceeding it.\n";
  cout << "2. Face cards are worth 10, aces can be 1 or 11.\n";
  cout << "3. You play against the dealer, who also aims for 21.\n";
  cout << "4. If you exceed 21, you bust and lose the round.\n";
  cout << "-----------------------\n"
       << endl;
}
