#include <bits/stdc++.h>

using namespace std;
int arr[1002];///dos millones y medio :c
long long int a, b, ax, m, bx, divi;
int N;
bool sqfree;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int x=1; x<=N; x++){
        cin >> a >> b;
        sqfree=true;

        ///ESTE for ENCUENTRA LOS FACTORES DE a; SI a TIENE ALGÚN FACTOR REPETIDO, ENTONCES sqfree=false Y EL CICLO TERMINA
        ///GUARDA CADA FACTOR EN LA CUBETA; SI ALGUNO SE REPITE DESPUÉS DE COMPARAR b, ENTONCES NO ES sqfree
        for(int y=2; y<=((a/2)+1); y++){
            if((a%y)==0){///F si es factor de y
                arr[y]++;///Aumenta 1 a la presencia del factor xd
                divi=(a/y);
                if((divi%y)==0){
                    if(((divi)/y)>0){///Es obvio que no es sqfree
                        sqfree=false;
                        y=(a);
                    }
                }
            }
        }
        ///SI ES QUE HABÍA UN FACTOR QUE SE REPITA, NTONCES YA QUEDÓ GUARDADO XD
        ///EL SIGUIENTE FOR SÓLO ENTRA SI sqfree ES VERDADERO AÚN
        if(sqfree==true){
            ///BUSCAR UN FACTOR QUE SE REPITA
            for(int y=2; y<=((b/2)+1); y++){
                if((b%y)==0){///F si es factor de y
                    arr[y]++;///Aumenta 1 a la presencia del factor xd
                    divi=(b/y);
                    if((divi%y)==0){
                            if(((divi)/y)>0){///Si se repite el factor en b
                            sqfree=false;
                            y=(b);///adiós ciclo c:
                            }///Si la división da al menos 1
                        }
                    if(arr[y]>1){///Si el factor ya se repitió
                        sqfree=false;
                            y=(b);///adiós ciclo c:
                        }
                }
            }///La del for :v
            ///SI AL FINAL DEL FOR DE b NO CAMBIÓ sqfree ENTONCES ES sqfree
        }///La del if sqfree TRUE
        if(sqfree==true){
            cout << "SI" << "\n";
        }
        if(sqfree==false){
            cout << "NO" << "\n";
        }

        ///*LIMPIAR ARREGLITO*
        if(a>b){
            a=m;
        }
        else{
            b=m;
        }

        for(int y=2; y<=((m/2)+1); y++){
            arr[y]=0;
        }
        m=0;

    }///LA DEL FOR N

    return 0;
}
