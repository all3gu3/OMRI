#include <bits/stdc++.h>

using namespace std;

int res,ni,nj;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    res=INT_MIN;
    cin>>nj;
    for(int x=2; x<=10; x++){
        cin>>ni;
        res=max(res,(nj-ni));
        nj=ni;
    }
    cout<<res<<"\n";
    return 0;
}
