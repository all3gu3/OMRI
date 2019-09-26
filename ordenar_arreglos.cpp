#include <iostream>
#include <algorithm>


using namespace std;
///
/// Un arreglo consiste en tener muchas variables con un mismo nombre
/// los arreglos inician en la posicion cero y por recomendacion siempre
/// debemos agregar 2 elementos:
/// ejemplo si queremos una arreglo para almacenar las letras del abecedario
///   char letras[28]
/// Si queremos un arreglo para almacenar los numeros de los meses
///   int meses[14]
/// Si queremos almacenar 1000 valores numericos en un arreglo
///   int numeros[1000];
/// Para denotar un elemento de un arreglo usaremos un indice numerico
/// ejemplo quiero colocar un 87 en el elemento 32 y un 50 enel elemento 25
///    numeros[32]=87;
///    numeros[50]=25;
/// En el indice tambien puedo poner el resultado de una operación
/// Ejemplo en el elemento 2+2 osea 4 voy a colocar el valor de 6
///    numeros[2+2]= 6
///
/// Para ordenar usaremos la funcion sort que ordenara en el arreglo
/// los datos dentro del rango  [primerElemento,UltimoElemento)
/// Ejemplo ordenar los numeros los elementos del 1 al 10  [1,10)
///   sort(numeros+1, numeros+11);//numeros apunta al elemento 0
/// Ejemplo para ordenar los elementos del 6 al 10  [6,10)
///   sort(numeros+6, numeros+11);
/// si queremos invertir el orden de los elementos  de un arreglo hacemos
/// dentro de un rango [primerElemento,UltimoElemento)
/// Ejemplo para invertir el orden de los elementos del 1 al 10
///   sort(numeros+1, numeros+11);
/// si queremos ordenar un arreglos en orden inverso debemos realizar
/// 2 operaciones primero ordenar y depues invertir el orden del arreglo
/// Ejemplo ordenar los elementos de un arreglo de 1 a 10 de mayoy a menor
///    sort(numeros+1, numeros+11);
///    reverse(numeros+1, numeros+11);
///
int numeros[1000000]; /// arreglo de  numeros de un milos de elementos
int i;                /// indice para ser utilizado en los arreglos
int N;
int main()
{
    /// voy a leer N valores y los guardare enel arreglo
    cin >> N;
    i=1;
    while (i<=N){
        cin >> numeros[i];
        i++;
    }


/// ordenar los datos
///  recuerde que el rango va de [1, N+1)
    sort(numeros+1, numeros+N+1 );

/// impresion de los valores
     i=1;
     while (i<=N)    {
         cout << numeros[i] << " ";
         i++;
     }
     cout << endl;

/// usando for
///  cin >> N;
///  for (i=1; i<N; i++){
///      cin >> numeros[i];
///  }

/// ordenar los datos
///  recuerde que el rango va de [1, N+1)
    sort(numeros+1, numeros+N+1 );

///
/// usando for
/// for(i=1;i<=N; i++){
///   cout << numeros[i] << " ";
/// }


/// vamor a ordenar los datos de mayor a menor
///  recuerde que el rango va de [1, N+1)
    sort(numeros+1, numeros+N+1 );
    reverse(numeros+1, numeros+N+1 );

/// impresion de los valores
     i=1;
     while (i<=N)    {
         cout << numeros[i] << " ";
         i++;
     }
     cout << endl;
///
/// usando for
/// for(i=1;i<=N; i++){
///   cout << numeros[i] << " ";
/// }





    return 0;
}
