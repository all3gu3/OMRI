#include <bits/stdc++.h>

using namespace std;

string laCadena;
int t,n,nav,k,s,h;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    getline(cin,laCadena);
    t=laCadena.length();
    k=t/2;
    s=k;
    h=k;
    nav=k;
    for(int x=0; x<=s; x++){
        for(int y=1; y<=k; y++){
            cout<<" ";
        }
        for(int y=k; y<=nav; y++){
            cout<<laCadena[y];
        }
        cout<<"\n";
        k--;
        nav++;
    }

    ///abcba
    return 0;
}
