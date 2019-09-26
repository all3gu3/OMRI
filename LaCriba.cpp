#include <iostream>
#include <math.h>

using namespace std;

short criba[100000000];

void imprime(int n){
    int i;
    cout << endl << "Números Primos" << endl;
    for(i=2;i<=n;i++){
        if (criba[i]==0){
             cout << i << " ";
        }
    }
    cout << endl;
}
void procesa(int n ){
    int i,j;
    int raiz;
    raiz=(int) sqrt(n);
    for(i=2; i<= raiz; i++){
	  if (criba[i]==0){
         for(j=i*i; j<=n; j+=i){
           criba[j]=1;
         }
	  }
    }
}

int main()
{
    int N;
    cin >> N;
    procesa(N);
    imprime(N);
    return 0;
}
