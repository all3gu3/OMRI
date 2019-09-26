#include <bits/stdc++.h>

using namespace std;

int mi,sec;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>mi>>sec;
    for(int x=1; x<=45; x++){
        sec++;
        if(sec==60){
            mi++;
            sec=0;
        }
        if(mi>12){
            mi=1;
        }
    }
    cout<<mi<<" "<<sec<<"\n";
    return 0;
}
