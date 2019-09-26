#include <bits/stdc++.h>

using namespace std;

int P, Ch, G, res, sob, aux;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> P >> Ch >> G;
    res=G;
    sob=G;
    if (Ch%2 != 0){
        res=(res+((Ch+1)/2));
        sob=(sob+2);
    }
    else{
        res=(res+(Ch/2));
    }
    if (sob>=P){
        cout << res;
    }
    else{
        aux=P-sob;///Lo que falta es en cuartos
        if (aux<=4){
            cout << res+1;///falta solo una pizza o menos
        }
        else{
           if(aux%4==0){
            res=(res+(aux/4));
            cout << res;
           }
           else{
            res=(res+((aux+4)/4));
            cout << res;
           }
        }
    }

    return 0;
}
