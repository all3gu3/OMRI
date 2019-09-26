// Libreria que-carga-otras-librerias
#include <bits/stdc++.h>

using namespace std;

/*******
ANAGRAMAS

Se tiene un texto con abecedario ingles, con letras mayúsculas y minusculas (no numeros ni signos raros), como el que sigue;

el perro le mordio xd xD
#

Ese texto se finaliza con el caracter #

Se le conocen como anagramas a esas palabras dentro del texto que, al cambiarle mayusculas o minusculas o el orden, se forman otras.

el->le   son anagramas
xd->xD   son anagramas
el->perro no son anagramas

Se requiere una lista de las palabras que no son anagramas de ninguna otra palabra del texto.
**********/
/* otra entrada de ejemplo
ladder came tape soon leader acme RIDE lone Dreis peat
ScAlE orb eye Rides dealer NotE derail LaCeS drIed
noel dire Disk mace Rob dries
#
*/

int cube[30]; /// Cubeta con las letras del abecedario
int noImprimir[1002]; /// Marcaremos aqui con 1 las palabras que NO debes imprimir
string palabras[1002]; /// arreglo con las palabras que te pueden dar
int fin=0; /// navegador del arreglo de arriba

void borraCubeta(){
    int j = 0;
    while (j<26) {
        cube[j] = 0;
        j = j + 1;
    }
} // las funciones void no tienen return!!

/// Funcion que regresa verdadero si todos los elementos de la cubeta son 0
bool cubetaVacia(){
    int k = 0; /// creo un navegador de letras
    bool respuesta = true; /// suponemos que la cubeta si esta vacia
    while (k<26) {
        if (cube[k] != 0) { /// EP!!! cubeta no esta vacia
            respuesta = false;
        }
        k++;
    }
    return respuesta;
}

bool esAnagrama(string p, string q){
    int i = 0; /// creo un navegador de letras
    int ind; /// identificador de la letra (a->0, b->1, c->2, ..., z->26)
    borraCubeta(); /// vacia la cubeta
    while (i<p.length()) { /// navego letra por letra hasta el tamaño de p
        if (p[i]>='A' && p[i]<='Z') { /// Si la letra es mayuscula
            p[i] = (p[i] - 'A') + 'a'; /// la convierto a minuscula
        }
        ind = p[i] - 'a'; /// Calculo el identificador de la letra
        cube[ind] = cube[ind] + 1; /// le subo 1 a ese identificador
        i++; /// nos pasamos a la siguiente letra
    }
    /// ya que cubeteamos la palabra, la des-cubeteamos con la otra palabra
    i = 0; /// empezando desde la letra 0
    while (i<q.length()) { // navego letra por letra hasta el tamaño de q
        if (q[i]>='A' && q[i]<='Z') { // Si la letra es mayuscula
            q[i] = (q[i] - 'A') + 'a'; // la convierto a minuscula
        }
        ind = q[i] - 'a'; // Calculo el identificador de la letra
        cube[ind] = cube[ind] - 1; /// le resto el identificador de la letra
        i++; // nos pasamos a la siguiente letra
    }
    /// ya que descubeteamos, probamos si la cubeta esta vacia
    return cubetaVacia();
}

int main(){
    cin >> palabras[fin]; /// leemos la primer palabra
    while (palabras[fin].compare("#") != 0) { /// si ultima palabra leida es diferente a #
        fin++; /// hay que leer otra palabra
        cin >> palabras[fin]; /// la leemos
    }/// OJO!! al finalizar la ejecución, palabras[fin] == "#", solo tomaremos en cuenta de la 0 a la fin-1
    // salimos de aqui al finalizar la lectura
    /**
    Para comparar todas las palabras con todas las demas, lo haremos en orden lexicografico,
    es decir:
    Ver si es anagrama palabra 0 con la 1
    Ver si es anagrama palabra 0 con la 2
    Ver si es anagrama palabra 0 con la 3
    ...
    Ver si es anagrama palabra 0 con la (fin-1)

    Después
    Ver si es anagrama palabra 1 con la 2
    Ver si es anagrama palabra 1 con la 3
    Ver si es anagrama palabra 1 con la 4
    ...
    Ver si es anagrama palabra 1 con la (fin-1)

    Después
    Ver si es anagrama palabra 2 con la 3
    Ver si es anagrama palabra 2 con la 4
    Ver si es anagrama palabra 2 con la 5
    ...
    Ver si es anagrama palabra 3 con la (fin-1)
    **/
    /*La última comparación sería
    Ver si es anagrama palabra (fin-2) con la (fin-1)
    Nota que no tiene sentido ver la palabra (fin-1) con (fin-1) porque es la misma palabra....*/
    /**
    Si llamamos la primer palabra X y a la segunda palabra Y, entonces...
    **/
    int X = 0, Y;
    while (X <= fin-2) { /// X será desde la 0 hasta fin-2
        Y = X + 1; /// La primera Y siempre inicia en la X+1
        while (Y < fin){
            cout << "Estoy comparando <" << X << ", " << Y
                 << "> <" << palabras[X] << ", " << palabras[Y] << ">\n";
            if(esAnagrama(palabras[X], palabras[Y])){ /// si son anagramas entre si, ninguna de las 2 se debe imprimir
                cout << "Vaya! son anagramas!\n";
                noImprimir[X] = 1;
                noImprimir[Y] = 1;
            }//en el caso contrario, no hay nueva información y no hacemos nada
            Y = Y + 1; /// Avanzamos Y
        }
        cout << "Ufff, ya compare " << X << ", osease, <" << palabras[X] << "> con todas las demas palabras\n"
             << "-----------------------------------------------------------------\n\n";
        X = X + 1; /// Avanzamos X
    }
    cout << "Termine!\n";
    X = 0; /// Ahora verificamos que palabras imprimir y cuales no
    while (X < fin){
        if (noImprimir[X] != 1){ /// imprimelo!
            cout << palabras[X] << "\n";
        }
        X = X + 1;
    }
    return 0;
}
