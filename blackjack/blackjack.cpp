#include <iostream>

using namespace std;

double player_stand(int ptotal, int pace, int cards, int deck);
double player_hit(int ptotal, int pace, int cards, int deck[]);
double max2 (double x, double y);
double player_double(int ptotal, int pace, int deck[])
double player_split(int ptotal, int pace, int deck[]) 
void dealer(int old_total, int old_ace, int cards, double probability, int deck[], double dealer_probability[]);

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
    cerr << "3. Whole Game\n"
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
        cerr << "Player Card 1: ";
        cin >> pc1;
        cerr << "Player Card 2: ";
        cin >> pc2;
        cerr << "Player Card 3: ";
        cin >> upcard;
        deck[pc1]--;
        deck[pc2]--;
        deck[upcard]--;
        deck[0] -= 3;
        ev_stand = player_stand(pc1 + pc2 (pc1 == 1 ? 1:0) + (pc2 == 1 ? 1:0), 2, deck);
        ev_hit = player_hit(pc1 + pc2 (pc1 == 1 ? 1:0) + (pc2 == 1 ? 1:0), 2, deck);
        ev_double = player_double(pc1 + pc2 (pc1 == 1 ? 1:0) + (pc2 == 1 ? 1:0), deck);
        if (pc1 == pc2)
            ev_split = player_split(pc1, (pc1 == 1 ? 1:0), deck);
        else  
            ev_split = -1.0;
        cerr << "EV stand =\t" << ev_stand << "\n";
        cerr << "EV hit =\t" << ev_hit << "\n";
        cerr << "EV double =\t" << ev_double << "\n";
        cerr << "EV split =\t" << ev_split << "\n";
    }
    else if (ch == 3) {
        double probability = 1.0;
        double total_probability = 0.0;
        double total_ev = 0.0;
        double max_ev;
        int basic_strategy[11][11][11];
        for (pc1 = 1; pc1 <= 10; pc1++) {
            probability *= (double) deck[pc1] / (double) deck[0];
            deck[pc1]--;
            deck[0]--;
            for (pc2 = pc1; pc2 <= 10; pc2++) {
                probability *= (pc1 == pc2 ? 1:2) * (double) deck[pc2] / (double) deck[0];
                deck[pc2]--;
                deck[0]--;

                for (upcard = 1, ipcard <= 10; upcard++) {
                    total_probability += probability;
                    probability *= (double) deck[upcard] / (double) deck[0];
                    deck[upcard]--;
                    deck[0]--;
                    ev_stand = player_stand(pc1 + pc2 (pc1 == 1 ? 1:0) + (pc2 == 1 ? 1:0), 2, deck);
                    ev_hit = player_hit(pc1 + pc2 (pc1 == 1 ? 1:0) + (pc2 == 1 ? 1:0), 2, deck);
                    ev_double = player_double(pc1 + pc2 (pc1 == 1 ? 1:0) + (pc2 == 1 ? 1:0), deck);
                    if (pc1 == pc2)
                        ev_split = player_split(pc1, (pc1 == 1 ? 1:0), deck);
                    else  
                        ev_split = -1.0;
                    max_ev = max2(max(ev_hit, ev_stand), max2(ev_double, ev_split));
                    if (max_ev == ev_stand)
                        basic_strategy[pc1][pc2][upcard] = 1;
                    else if (max_ev == ev_hit)
                        basic_strategy[pc1][pc2][upcard] = 2;
                    else if (max_ev == ev_double)
                        basic_strategy[pc1][pc2][upcard] = 3;
                    else
                        basic_strategy[pc1][pc2][upcard] = 4;
                    
                    total_ev += probability * max_ev;
                    printf("%i, %i, %i, %f, %f, %f\n", pc1, pc2, upcard, ev_stand, ev_hit, ev_double, ev_split);
                    
                    deck[0]++;
                    deck[upcard]++;
                    probability /= (double) deck[upcard] / (double) deck[0];
                }
                deck[0]++;
                deck[pc2]++;
                probability /= (pc1 == pc2 ? 1:2) * (double) deck[pc2] / (double) deck[0];
            }
            deck[0]++;
            deck[pc1]++;
            probability /= (double) deck[pc1] / (double) deck[0];
        }
        printf("Total Probability = \t%f\n", total_probability);
        printf("Game Expected Value = \t%f\n", total_ev);
        printf("Hard Totals\n");
        char codes[] = "XSHDP";
        for (pc1 = 2, pc1 <= 9; pc1++) {
            for (pc2 = pc1 + 1; pc2 <= 10; pc2++) {
                printf("%i, %i\t", pc1, pc2);
                for (upcard = 2; upcard <= 10; upcard++)       
                    printf("%c", codes[basic_strategy[pc1][pc2][upcard]]);
                printf("%c\n", codes[basic_strategy[pc1][pc2][1]]);
                    
            }
        }
        printf("Soft Totals\n");
        for (pc2 = 2; pc2 <= 10; pc2++) {
            printf("%i, %i\t", 1, pc2);
            for (upcard = 2; upcard <= 10; upcard++)
                printf("%c", codes[basic_strategy[1][pc2][upcard]]);
            printf("%c\n", codes[basic_strategy[1][pc2][1]]);
                    
        }
        printf("Pairs\n");
        for (pc2 = 1; pc2 <= 10; pc2++) {
            printf("%i, %i\t", pc2, pc2);
            for (upcard = 2; upcard <= 10; upcard++)
                printf("%c", codes[basic_strategy[pc2][pc2][upcard]]);
            printf("%c\n", codes[basic_strategy[pc2][pc2][1]]);         
        }
    }
}

double player_stand(int ptotal, int pace, int cards, int deck) {
    double ev_stand, dealer_probability[7];
    if ((ptotal == 11) && (pace == 1) && (cards == 2)) {
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
    return ev_stand;
}

double player_hit(int ptotal, int pace, int cards, int deck[]) {
    int next_card;
    double probability, ev_stand, ev_hit, ev_hit_again;
    ev_hit = 0.0;
    for (next_card = 1; next_card <= 10; next_card++) {
        probability = (double) deck[next_card] / (double) deck[0];
        deck[next_card]--;
        deck[0]--;
        ev_stand = player_stand(ptotal + next_card, pace + (next_card == 1 ? 1:0), cards + 1, deck);
        if (ptotal + next_card < 17)
            ev_hit_again = player_hit(ptotal + next_card, pace + (next_card == 1 ? 1:0), cards + 1, deck);
        else   
            ev_hit_again = -1;
        ev_hit += probability * max (ev_stand, ev_hit_again);
    }
    return ev_hit;
}

double player_double(int ptotal, int pace, int deck[]) {
    int next_card;
    double probability, ev_double;
    ev_double = 0.0;
    if (ptotal > 11)
        ev_double = -1;
    else {
        for (next_card = 1; next_card <= 10; next_card++) {
            prob = (double) deck[next_card] / (double) deck[0];
            ev_double += probability * player_stand(ptotal + next_card, pace + (next_card == 1 ? 1:0), 3, deck);
            deck[next_card]--;
            deck[0]--;
            
        }  
    }
    return 2 * ev_double;
}

double player_split(int ptotal, int pace, int deck[]) {
    int next_card;
    double probability, ev_split, ev_hit;
    ev_split = 0.0;
    for (next_card = 1; next_card <= 10; next_card++) {
        probability = (double) deck[next_card] / (double) deck[0];
        ev_stand = player_stand(ptotal + next_card, pace + (next_card == 1 ? 1:0), 3, deck);
        if (ptotal == 1)
            ev_hit = -1.0;
        else
            ev_hit = player_hit(ptotal + next_card, pace + (next_card == 1 ? 1:0), 2, deck);
        ev_split += probability * max(ev_stand, ev_hit);
        deck[next_card]--;
        deck[0]--;
    }  
    return 2 * ev_split;
}

double max2 (double x, double y) {
    if (x > y)
        return x;
    else 
        return y;
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
        probability *= (double) deck[next_card] / (double)deck[0];
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