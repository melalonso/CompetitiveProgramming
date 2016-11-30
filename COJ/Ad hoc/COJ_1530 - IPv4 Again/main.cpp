#include <iostream>
#include <sstream>
using namespace std;

/*
    ACCEPTED.
    CASE 1..1.1
*/

int main()
{
    int cases,N,largo;
    string ip,str_n;
    stringstream stream1;
    bool valid;
    cin >> cases;
    while(cases--){
        cin>>ip;
        largo=0;
        valid = 1;
        for(int i =0;i<ip.size();i++){
            str_n = "";
            largo++;
            while(i<ip.size() && ip.at(i)!='.'){
                str_n += ip.at(i);
                i++;
            }
            stream1.clear();
            stream1.str(str_n);
            stream1 >> N;
            stream1.clear();
            if (N<0 || N>255){
                valid = false;
                break;
            }
            N = -1;
        }
        cout << (valid && (largo==4 || largo==6)  ? "SI\n" : "NO\n");
    }
    return 0;
}
