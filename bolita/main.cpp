#include <iostream>

using namespace std;
int nueces [6];
int p,m,n,mov,aux,cont;

int buscar(){///devuelve la posicion de la bolita
    cont =1;
    while (cont<=4){
        if (nueces[cont]==1){
            return (cont);
        }
        cont ++;
    }
}
void mover(int i, int j){
       aux = nueces [i];
       nueces[i] = nueces[j];
       nueces[j] = aux;

}
void hacer (int mov){

if (mov==1){
    mover(1,2);
}
if (mov==2){
    mover(1,3);
}
if (mov==3){
    mover(1,4);
}
if (mov==4){
    mover(2,3);
}
if (mov==5){
    mover(2,4);
}
if (mov==6){
    mover(3,4);
}
}

void leer(){
    cin >> p;///posicion de la bolita
    nueces[p]=1;///el valor de la posicion de la bolita es 1
    cin >> m;///numero de movimientos
    n=1;
    while (n<=m) {
        cin >> mov;
        hacer(mov);
        n++;
        }

        cout << buscar() << "\n";
}






int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
