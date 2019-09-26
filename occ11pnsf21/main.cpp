#include <bits/stdc++.h>

using namespace std;

long long int a,b,c,res=0;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b>>c;
    res=a*100;
    res+=b*200;
    res+=c*500;
    cout<<res<<endl;
    return 0;
}
