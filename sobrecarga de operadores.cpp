#include <iostream>
#include <algorithm>
using namespace std;
///
/// Las estrucuras en C permiten crear tipos de datos perzonalizados conmas de una variable por ejemplo vamos a
/// crear un tipo variable punto para definir un punto en un plano carteciano y este nuevo tipo le llamaremos
/// "Punto" y contra una valor de "x" y otro de "y"
///
///  struct Punto{
///    int x;      /// variable contenida llamada "x"
///    int y;      /// variable contenida llamada "y"
///  };

///  Declaramemos un variable llamada "pto1" y "pto2" del tipo "Punto"
///
///     Punto pto1;
///     Punto pto2;
///
///  Declaramemos un arreglo llamado "puntos" con 12 elementos del tipo "Punto"
///
///  Punto puntos[12];

///  Para hacer uso de la variable "x" y "y" debemos utilizar <nombre variable>.<nombre variable contenida>
///  vamos asignar la coordenada (1,3) a la variable pto1
///     pto1.x=1;
///     pto1.y=3;


///  Para hacer uso de la variable "x" y "y" en arreglos
///  debemos utilizar <nombre variable>[indice].<nombre variable contenida>
///  vamos asignar la coordenada (2,4) a la variable puntos con indice 3
///     puntos[3].x=2;
///     puntos[3].y=4;

///  Tambien podemos asignar tanto a una variable como a a un arreglo de la siguiente forma
///    pto1={2,3}  // pto1.x=2 y pto1.y=3
///    puntos[5]={2,3}  // puntos.x=2 y puntos.y=3


///   para copiar una variable basta con hacer la asignacion, ejemplo
///   lo que tenga "pto1" lo copiaremos en "pto2"
///
///        pto2=pt1;

///   y lo que tiene  puntos[3] lo copiaremos a punto[4];
///
///        puntos[4]=puntos[3];
///
///   Ahora si queremos compara una variable con otra debemos establecer como se hara esta comparacion
///   por ejemplo si quiero comparar  quie es menor ejemplo if (pto1<pt2)
///   como la estrutua "Punto"  se forma de 2 variables, nosotros debemos establecer la forma de comparacion
///   en nuestro ejemplo podria ser la distancia que existe entre nuestro punto y la coordenada cero (0,0)
///

struct Punto{
    int x;      /// variable contenida llamada "x"
    int y;      /// variable contenida llamada "y"
    /// A qui se indica como se debe comportar nuestra variable cuando utilizamos el operador menor que
    /// como se puede apreciar el operador "menor que" recibe un paramtro del mismo tipo en nuestro ejemplo
    /// llamador otro, con el que es comparado
    /// esto nos sirve para ordenar
    const bool operator< (const Punto &otro) const {
         bool ret_val=false;
         int distancia, distanciaOtro;
         distancia= x*x + y*y;
         distanciaOtro=otro.x*otro.x +otro.y*otro.y;
         ret_val= distancia < distanciaOtro;
         return ret_val;
    }
    /// si queremos agregar una operacion por ejemplo de suma tambien la debemos definir
    /// en nuestro ejemplo haremos que la suma deje en "x" la suma de llas 2 x y en "y" la suma
    /// de las dos Y

    Punto operator+ (const Punto &otro) const {
         Punto  ret_val;
         ret_val.x=x+otro.x;
         ret_val.y=y+otro.y;
         return ret_val;
    }

    /// si queremos agregar una operacion por ejemplo de suma tambien la debemos definir
    /// en nuestro ejemplo haremos que la suma deje en "x" la suma de llas 2 x y en "y" la suma
    /// de las dos Y

    void operator++ () { /// para ++Punto
          x++;
          y++;
    }

    void operator++ (const int unused) { /// para Punto++
          x++;
          y++;
    }

};

/// si usted desea usar mas  operadores con nuestra estructura "Punto" los  debe declara y definri su comportamineto

Punto pto1, pto2;

Punto puntos[12];
int i=0;

void imprime(){
    cout << endl;
    i=1;
    while (i<=10){
        cout << "Punto: "<< i<< " ("<<puntos[i].x <<", "<< puntos[i].y<<")"<< endl;
        i++;
    }

}

int main()
{
    pto1={1,1};
    pto2.x=2;
    pto2.y=2;
    if (pto1 < pto2){
        cout << "pto1 es menor que pto2" << endl;
    }else {
        cout <<" pto1 NO es menor que pto2" << endl;
    }
    /// llenaremos el arreglo de puntos
    i=1;
    while (i<=10){
       puntos[i]={11-i,11-i};  /// puntos[1]={10,10}, puntos[2]={9,9},...  puntos[1]={1,1}
       i++;
    }
    cout<<endl<<"Puntos desordenados";
    imprime();

    /// ordenaremos los puntos y los imprimiremos

    sort(puntos+1,puntos+11);

    cout<<endl<<"Puntos ordenados" ;
    imprime();

    /// agregando la operacion de +
    Punto pto3=pto1+pto2;
    cout << endl<<"pto1+pt2= ("<<pto3.x<<", "<<pto3.y<<")"<<endl;

    /// agregando la operacion de ++
    ++pto3;
    cout << endl<<"pto3++ = ("<<pto3.x<<", "<<pto3.y<<")"<<endl;
    pto3++;
    cout << endl<<"pto3++ = ("<<pto3.x<<", "<<pto3.y<<")"<<endl;
    return 0;
}
