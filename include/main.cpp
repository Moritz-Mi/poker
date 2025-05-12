#include <iostream>
#include <string>
#include <time.h>

using namespace std;

const static int DECKS = 1;

string getCardString(int value, int suit){
    string out = "";
    switch (value){
        case 0: out += "A"; break;
        case 1: out += "2"; break;
        case 2: out += "3"; break;
        case 3: out += "4"; break;
        case 4: out += "5"; break;
        case 5: out += "6"; break;
        case 6: out += "7"; break;
        case 7: out += "8"; break;
        case 8: out += "9"; break;
        case 9: out += "10"; break;
        case 10: out += "J"; break;
        case 11: out += "Q"; break;
        case 12: out += "K"; break;
    }
    switch (suit){
        case 0: out += "Cl"; break;
        case 1: out += "Di"; break;
        case 2: out += "He"; break;
        case 3: out += "Sp"; break;
    }
    return out;
}

class Card
{
public:
    Card(int value, int suit)
    {
        this->value = value;
        this->suit = suit;
    };

    string toString(){
        return getCardString(value, suit);
    }
private:
    int value;
    int suit;
};

class Deck
{
    public:
        Deck(){
            srand(time(NULL));
            for (size_t i = 0; i < 13; i++)
            {
                cards[i] = new Card(i+1, 0);
                cards[13+i] = new Card(i+1, 1);
                cards[26+i] = new Card(i+1, 2);
                cards[39+i] = new Card(i+1, 3);
            }
            shuffle();
        }
        void shuffle(){
            for (int i = 0; i < DECK_SIZE; i++)
            {
                drawn[i] = false;
            }
            for (int i = 0; i < RANDS; i++)
            {
                int r1 = rand() % DECK_SIZE;
                int r2 = rand() % DECK_SIZE;
                Card *temp = cards[r1];
                cards[r1] = cards[r2];
                cards[r2] = temp;
            }
            
        }
        Card* draw(){
            int r = rand() % DECK_SIZE;
            while (drawn[r])
            {
                r = rand() % DECK_SIZE;
            }
            drawn[r] = true;
            return cards[r];
        }
    private:
    const static int DECK_SIZE = 52;
    const static int RANDS = 200;
    Card *cards[DECK_SIZE];
    bool drawn[DECK_SIZE];
};

class Player
{
    public:
        Player(){
            onhand = 0;
        }
        void draw(Deck *deck){
            hand[onhand] = deck->draw();
            onhand++;
        }
        Card* getHand(int index){
            return hand[index];
        }
    private:
        Card *hand[5];
        int onhand;
};

class GameState
{
    public:
        virtual void enter() = 0;
        virtual void handleInput(Game &game) = 0;
        virtual void update(Game &game) = 0;
        virtual void exit() = 0;
        virtual ~GameState() = default;
};

class Game
{
    private:
        GameState *currentState;
    public:
    
};

int main()
{
    std::cout << "Hello World!" << std::endl;
    return 0;
}
