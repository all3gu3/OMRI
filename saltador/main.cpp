#include <bits/stdc++.h>

using namespace std;
int N, n, ni, S, a, Sr;
bool alegre;
int arr[3002];
int cubeta[10002];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=1; i<=N; i++){
        for(int y=1; y<=3002; y++){
            arr[y]=0;
        }
        for(int y=1; y<=10002; y++){
            cubeta[y]=0;
        }
        cin >> n;
        S=0;
        Sr=0;

        alegre=true;
        Sr=(((n-1)*n)/2);///lo que deberían sumar las diferencias si es alegre
        for (int x=1; x<=n; x++){
            cin >> ni;
            arr[x]=ni;///Guarda la secuencia
        }
        for (int x=1; x<n; x++){
            arr[x]=abs(arr[x+1]-arr[x]);
            cubeta[arr[x]]++;///Agrego uno a la cubeta en la posición de la diferencia
            S=(S+arr[x]);
        }
        if(S==Sr){///La suma de las diferencias es igual a la sumatoria hasta n-1
            for(int x=1; x<n; x++){
                if(cubeta[x] != 1){
                    alegre=false;
                    ///*Si la cubeta sempre tiene unos significa que tiene 1,2,3,4... hasta n-1, entonces alegre siempre será verdadero xd*
                }
            }
        }
        else{///O sea que la suma no da :c
            alegre=false;
        }


        if(alegre==true){
            cout << "Alegre" << "\n";
        }
        if(alegre==false){
            cout << "No alegre" << "\n";
        }
    }



    return 0;
}
