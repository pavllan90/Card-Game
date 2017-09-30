#ifndef CARD_H
#define CARD_H

class card
{
public:
    card();
    card(int nom, int mas);
    card(const card &a);
    ~card();
    int nominal;
    int mast;
};

#endif // CARD_H
