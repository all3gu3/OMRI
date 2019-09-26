#include <iostream>

using namespace std;

long long int C, s, x, n, res, A, B, V, Va, Vb;

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> A >> B >> C;
    Va = A;///x=0
    Vb = B;///x=1
    res=-1;
    if (C==0){
        res=(-1);
    }
    else{
        if ((A==0) || (A==C) || ((A%C)==0)){
            res= 0;
        }
        else if ((B==0) || (B==C) || ((A%C)==0)){
            res= 1;
        }
        else {
            x=2;
            s=0;
            while (x<=5000000) {
                V=(Va+Vb);
                Va=Vb;
                Vb=V;
                if ((V%C)==0){
                   res= x;
                   x=50000001;
                   s=1;
                }
                else {
                x++;
                }
                }
            if (s==0){
                res=(-1);
            }
        }
    }

    cout << res;
    return 0;

}
