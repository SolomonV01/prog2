#include <iostream>

using namespace std;

void dealer(int old_total, int old_ace, int cards, double probability, int deck[], double dealer_probability[])

int numdeck = 1;
int upcard;


int main() {

    int ch, i, j, deck[11]
    double dealer_probability
    for (i = 1; i<= 9; i++)
        deck[i] = 4 * numdeck;
    deck[10] = 16 * numdeck;
    deck[0] = 52 * numdeck;
    cerr << "1. Dealer Probabilities\n";
    cerr << "2. Player Hand\n";
    cin >> ch;
    if (ch == 1) {
        for (i = 1; i <= 10; i++) {
            cout << "Up card = " << i << "\n";
            deck[i]--;
            deck[0]--;
            dealer(i, (i == 1 ? 1:0), 1, 1.0, deck, dealer_probability)
            for (j = 0; j <= 6; j++)
                cout << j << "\t" << dealer_probability[j] << "\n";
            deck[i]++;
            deck[0]++;
        }
    }
    else if (ch == 2) {
        cerr << "Player Card 1:"
    }
    
}

double player_stand(int ptotal, int pace, int cards, int deck) {
    double ev_stand, dealer_probability[7];
    if ((ptotal == 1) && (pace == 1) && (cards == 2)) {
        if ((upcard > 1) && (upcard < 10)) //winning bj
            return 1.5;
        else {
            dealer(upcard, (upcard == 1 ? 1:0), 1.0, deck, dealer_probability);

            return 1.5*(dealer_probability[0] + dealer_probability[1] + dealer_probability[2] + dealer_probability[3] + dealer_probability[4] + dealer_probability[6]);
        }
    }
    else if (ptotal > 21) //player bust
        return -1.0;
    else {
        ((ptotal <= 11) && (pace > 0)) //soft
            ptotal += 10;
        dealer (upcard, (upcard == 1 ? 1:0), 1, 1.0, deck, dealer_probability);
        ev_stand = dealer_probability[6];
        ev_stand -= dealer_probability[5];
        for (int i = 0; i <= 4; i++) {
            if (ptotal > i + 17)
                ev_stand += dealer_probability[i];
            else if (ptotal < i + 17)
                ev_stand -= dealer_probability[i];
        }

    }
    return
}

/*
Dealer probablility
0 = 17
1 = 18
2 = 19
3 = 20
4 = 21
5 = bj
6 = bust
*/

void dealer(int old_total, int old_ace, int cards, double probability, int deck[], double dealer_probability[]) {
    int i, next_card, new_total, new_ace;
    if (cards == 1) {
        for (i = 0; i <= 6; i++)
            dealer_probability[i] = 0.0;
    }
    for (next_card = 1; next_card <= 10, next_card++) {
        prob *= (double) deck[next_card] / (double)deck[0];
        deck[next_card]--;
        deck[0]--;
        new_total = old_total + next_card;
        new_ace = old_ace + (next_card == 1 ? 1 : 0);
        if ((cards == 1) && (new_total == 11) && (new_ace == 1)) //blackjack
            dealer_probability[5] += probability;
        else if (new_total > 21)
            dealer_probability[6] += probability;
        else if (new_total >= 17)
            dealer_probability[new_total - 17] += probability;
        else if ((new_total >= 7) && (new_total <= 11) && (new_ace > 0))
            dealer_probability[new_total - 7] += probability;
        else
            dealer(new_total, new_ace, cards+1, probability, deck, dealer_probability);
        deck[0]++;
        deck[next_card]++;
        prob /= (double) deck[next_card] / (double)deck[0];
    }
}