#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int fpContador;
int fPrimos[100];
int dContador;
int Divi[1000];


int sortInt ( const void *a, const void *b){
    return( *(int *)a - *(int *)b );
}

void imprime(int primos []){
   int i=1;
   while(primos[i]){
      cout << primos[i] << " ";
      i++;
  }
  cout << endl;
  cout << " Total: " <<i-1 << endl;
}

void FactorePrimosOri(int v){
      int i;  // contador
      int c;  // numero sin factorizar
      int raiz;  // numero sin factorizar
      c=v;
      while( ( c % 2 ) == 0 ){   // busca todo los 2
          c= c / 2;
          fpContador++;  // Este es el indice del arreglo, y también lleva la cuenta de cuantos factores primos se van encontrando
          fPrimos[fpContador]=2; // Este arreglo va a contener los factores primos
      }

      i=3;
      raiz=((int) sqrt(c))+1;  //busca todos los impares (da solo primos)
      while( i <= raiz && c>0){
          if (  (c % i) ==0 ){
              c = c / i;
              fpContador++;
              fPrimos[fpContador]= i;
          }else {
              i=i+2;
          }
      }

      if ( c > 1 ){      // coloca el ultimo factor que seguro es un primo. Esto se sabe por que el último número que sobra a fuerzas tiene que ser un primo
          fpContador++;
          fPrimos[fpContador]= c;
      }

    return;
}


void Divisores(){
   int inicio=1, fin=1, desde;
   int i, j;
   Divi[1]=1;
   for(i=1; i<=fpContador; i++){
       if(fPrimos[i]!= fPrimos[i-1]){
           desde=1;                            // apunta a todos los divisores
       }else{
           desde=inicio;                       // apunta los divisores de la ultima iteraccion
       }
       for(j=desde;j<=fin;j++){   // genera los divisores
              Divi[fin+j-desde+1]=fPrimos[i]* Divi[j];
       }
       inicio=fin+1;                          // actualiza los apuntadores para la proxima iteraccion
       fin=fin+j-desde;
   }
   // ordena los divisores solo en caso de que sea necesario sto es opcional
   qsort(Divi,fin+1,sizeof(Divi[1]), sortInt);
}

int main()
{
    long long int N;

    cin>> N;
    FactorePrimosOri(N);
    cout <<endl<< "Divisores Primos"<< endl;
    imprime(fPrimos);

    cout <<endl<< "Todos los Divisores"<< endl;
    Divisores();
    imprime(Divi);

    return 0;
}
