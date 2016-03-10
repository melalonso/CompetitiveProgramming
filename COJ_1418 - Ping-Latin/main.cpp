#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <iterator>

using namespace std;

/*
    ACCEPTED.
*/

char vowel[] = {'a','A','e','E','i','I','o','O','u','U'};

bool is_vowel(char c){
    for (int i=0;i<10;i++){
        if (c==vowel[i]) return true;
    }
    return false;
}

bool is_letter(char c){
    return (c>='A' && c<='Z') || (c>='a' && c<='z');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    string line,w;
    while(getline(cin,line)){
        w="";
        for (int i=0; i<line.size(); i++){
            if (is_letter(line[i])) w += line[i];
            else{
                if (w.size() && is_vowel(w[0]))
                    cout << w << "ay";
                else if(w.size())
                    cout << w.substr(1,w.size()-1) << w[0] << "ay";
                w="";
                cout << line[i];
            }
        }

        if (w.size() && is_vowel(w[0])) cout << w << "ay";
        else if(w.size()) cout << w.substr(1,w.size()-1) << w[0] << "ay";
        cout << endl;
    }
    return 0;
}
