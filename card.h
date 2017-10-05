#ifndef CARD_H
#define CARD_H
#include <QString>

enum Suit
{
    diamonds, hearts, spades, clubs
};

enum Nominal
{
    ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king
};

class card
{
public:
    card();
    card(Nominal _nominal, Suit _suit);
    card(const card &a);
    ~card();
    QString suitToString();
    QString nominalToString();
    QString cardToString();
    Nominal getNominal();
    void setNominal(Nominal _nominal);
    Suit getSuit();
    void setSuit(Suit _suit);
private:
    Nominal nominal;
    Suit suit;
};

#endif // CARD_H
