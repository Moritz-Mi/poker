#include <iostream>
#include <string>

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
        Card *cards[52];
        Deck(){
            for (size_t i = 0; i < 13; i++)
            {
                cards[i] = new Card(i+1, 0);
                cards[13+i] = new Card(i+1, 1);
                cards[26+i] = new Card(i+1, 2);
                cards[39+i] = new Card(i+1, 3);
            }
        }
        void shuffle(){

        }
    private:
};

int main()
{
    std::cout << "Hello World!" << std::endl;
    return 0;
}
