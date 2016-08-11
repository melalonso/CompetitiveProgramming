#include <iostream>
#include <bitset>
#include <vector>
#include <stdio.h>

#define ll long long
#define vi vector<int>

using namespace std;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

int ans[] = {0,0,2 ,4 ,6 ,16 ,12 ,64 ,24 ,36 ,48 ,1024 ,60 ,4096 ,192 ,144 ,
120 ,65536 ,180 ,262144 ,240 ,576 ,3072 ,4194304 ,360 ,1296 ,12288 ,900 ,960
,FALTA29,720,FALTA31, 840 ,9216 ,196608 ,5184 ,1260 ,FALTA37, 786432 ,36864 ,1680 ,FALTA41, 2880 ,FALTA43, 15360 ,
3600 ,12582912, FALTA47, 2520 ,46656 ,6480 ,589824 ,61440 ,FALTA53, 6300 ,82944 ,6720 ,2359296 ,FALTA58, FALTA59, 5040 ,
FALTA61,FALTA62, 14400 ,7560};



void sieve(ll upperbound){
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i=2; i <= _sieve_size; i++) if (bs[i]){
        for (ll j = i*i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

ll numDiv(ll N){
    ll PF_index = 0, PF = primes[PF_index], ans = 1;
    while (PF*PF <= N){
        ll power = 0;
        while (N%PF==0){N/=PF; power++;}
        ans *= (power+1);
        PF = primes[++PF_index];
    }
    if (N!=1) ans *= 2;
    return ans;
}

int main()
{
    /*
    sieve(10000000);
    for (int i=2; i<=64; i++){
        for (int j=2; j<=10000000; j++){
            if (numDiv(j)==i){
                printf("%d ,", j);
                break;
            }
        }
    }*/
    printf("%d\n\n",sizeof(ans)/sizeof(int));
    int cases,n;
    freopen("input","r",stdin);
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }

    return 0;
}
