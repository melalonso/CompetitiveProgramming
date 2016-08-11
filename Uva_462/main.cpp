#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>

#define iterate(map) for(it_type it = map.begin(); it != map.end(); it++)
#define rev_iterate(map) for(it_type2 it = map.rbegin(); it != map.rend(); ++it)

using namespace std;

typedef vector<int> vi;
typedef map<char, vi>::iterator it_type;
typedef map<char, vi>::reverse_iterator it_type2;

// Map to have the four suits and
// the amount of cards plus
// a space for ace, king, queen, jack.
map<char,vi> suits;

bool valuableCard(char c){
    return c=='A' || c=='K' ||
        c=='Q' || c=='J';
}

bool stopped(){
    int cnt=0;
    iterate(suits){
        if (it->second[1] || // contains and ace
            (it->second[2] && it->second[0]>1) ||
            (it->second[3] && it->second[0]>2)
            ) cnt++;
    }
    return cnt==4;
}

int main()
{
    int value;
    char card[2];
    string line;
    freopen("input","r",stdin);
    ofstream out("salida2");

    while(getline(cin,line)){
        suits['S'] = suits['H'] = vi(5);
        suits['D'] = suits['C'] = vi(5);
        value = 0;
        stringstream s(line);
        while(s>>card){
            suits[card[1]][0]++;
            if(valuableCard(card[0])){
                if (card[0]=='A'){
                    value+= 4;
                    suits[card[1]][1] = 1;
                }
                else if (card[0]=='K'){
                    value+= 3;
                    suits[card[1]][2] = 1;
                }
                else if (card[0]=='Q'){
                    value+= 2;
                    suits[card[1]][3] = 1;
                }
                else{
                    value+= 1;
                    suits[card[1]][4] = 1;
                }
            }
        }

        // Rules for decrementing one.
        iterate(suits){
            if ( (it->second[2]==1 && it->second[0]==1)||// K y 0 cards
                 (it->second[3]==1 && it->second[0]<3) || // Q y <2 cards
                 (it->second[4]==1 && it->second[0]<4)    // J y <3 cards
                ) value--;
        }

        if (value>=16 && stopped() ){
            //printf("BID NO-TRUMP\n");
            out << "BID NO-TRUMP\n";
        }
        else{
            // points 5, 6 & 7.
            iterate(suits)
                if ( it->second[0] == 2) value += 1;
                else if ( it->second[0] == 1 || it->second[0] == 0) value += 2;


            if (value<14){
                //printf("PASS\n");
                out << "PASS\n";
            }
            else{
                //printf("BID ");
                out << "BID ";
                char c;
                int max = 0;
                rev_iterate(suits){
                    if (it->second[0]>max){
                        max = it->second[0];
                        c = it->first;
                    }
                }
                //printf("%c\n",c);
                out << c << "\n";
            }
        }
    }
    return 0;
}
