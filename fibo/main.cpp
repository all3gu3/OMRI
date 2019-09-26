#include <iostream>

using namespace std;

long A, B, V, Va, Vb;
int C, s, x, res;

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> A >> B >> C;
    Va = A;///x=0
    Vb = B;///x=1

    if (C==0){
    res = -1;
    }

    else {

        if ((A==C) || ((A%C)==0) || (A==0)){
            res = 0;
        }
        else if ((B==C) || ((B%C)==0) || (B==0)){
            res = 1;
        }

        else {
            x=2;
            s=0;
            while (x<=5000000) {
                V=(Va+Vb);///Se obtiene el valor de la función en x
                Va=Vb;///Transferencia de valores
                Vb=V;///
                if ((V%C)==0){///Si la función en x % C = 0
                   res = x;///Entonces x es el numerito
                   x=50000001;///
                   s=1;
                }

                else {
                x++;
                }
            }

            if (s==0){///si s = 0 entonces no se encontró solución para x < 5000000
            res = -1;
            }
        }///la funcion que calcula x si no es 0 o 1
    }
    cout << res;
    return 0;

}
