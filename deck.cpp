#include "deck.h"

vector<char> deck;

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
        cardInInt = 1;

    else
        cardInInt = card - '0';

    return cardInInt;
}