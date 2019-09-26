#include <bits/stdc++.h>

using namespace std;

int n,res=0;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int x=1; x<=n; x++){
        res+=(x*x);
    }
    cout<<res<<endl;
    return 0;
}
