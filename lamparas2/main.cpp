#include <bits/stdc++.h>


using namespace std;
///00000000000000000000000000000000        // 1  2  3  4  5  6  7  8  9  10  11  12  13  14  15...
int B0[112];///Todas encendidas xd         // 1  1  1  1  1  1  1  1  1  1   1   1   1   1   1...
int B1[112];/// 2,3 ///Todas apagadas xd   // 0  0  0  0  0  0  0  0  0  0   0   0   0   0   0...
int B2[112];/// 2 /// 3,1                  // 0  1  0  1  0  1  0  1  0  1   0   1   0   1   0...
int B3[112];/// 3 /// 2,1                  // 1  0  1  0  1  0  1  0  1  0   1   0   1   0   1...
int B4[112];/// 4                          // 0  1  1  0  1  1  0  1  1  0   1   1   0   1   1...
int B4_1[112];/// 4,1                      // 1  0  0  1  0  0  1  0  0  1   0   0   1   0   0...
int B2_4[112];/// 2,4                      // 0  0  1  1  1  0  0  0  1  1   1   0   0   0   1...
int B3_4[112];/// 3,4                      // 1  1  0  0  0  1  1  1  0  0   0   1   1   1   0...
int N, cont, on, off, s, arr, m, may, ONi, OFFi, posb, l;
int possible[10];
int Ordpossible[10];
int vpossible[10];



void ImpArr()///Imprime cada areglo xdxd
{
    if (arr==1){
    for (int x=1; x<=N; x++){
                cout << B1[x];
            }
            cout << " ";
    }
    if (arr==2){
    for (int x=1; x<=N; x++){
                cout << B2[x];
            }
            cout << " ";
    }
    if (arr==3){
    for (int x=1; x<=N; x++){
                cout << B3[x];
            }
            cout << " ";
    }
    if (arr==4){
    for (int x=1; x<=N; x++){
                cout << B4[x];
            }
            cout << " ";
    }
    if (arr==5){
    for (int x=1; x<=N; x++){
                cout << B4_1[x];
            }
            cout << " ";
    }
    if (arr==6){
    for (int x=1; x<=N; x++){
                cout << B2_4[x];
            }
            cout << " ";
    }
    if (arr==7){
    for (int x=1; x<=N; x++){
                cout << B3_4[x];
            }
            cout << " ";
    }
    if (arr==8){
    for (int x=1; x<=N; x++){
                cout << B0[x];
            }
            cout << " ";
    }
}

void compON()
{
    if (B1[ONi]==0){
        possible[1]=0;
    }
    if (B2[ONi]==0){
        possible[2]=0;
    }
    if (B3[ONi]==0){
        possible[3]=0;
    }
    if (B4[ONi]==0){
        possible[4]=0;
    }
    if (B4_1[ONi]==0){
        possible[5]=0;
    }
    if (B2_4[ONi]==0){
        possible[6]=0;
    }
    if (B3_4[ONi]==0){
        possible[7]=0;
    }
    if (B0[ONi]==0){
        possible[8]=0;
    }
}
void compOFF()
{
    if (B1[OFFi]==1){
        possible[1]=0;
    }
    if (B2[OFFi]==1){
        possible[2]=0;
    }
    if (B3[OFFi]==1){
        possible[3]=0;
    }
    if (B4[OFFi]==1){
        possible[4]=0;
    }
    if (B4_1[OFFi]==1){
        possible[5]=0;
    }
    if (B2_4[OFFi]==1){
        possible[6]=0;
    }
    if (B3_4[OFFi]==1){
        possible[7]=0;
    }
    if (B0[OFFi]==1){
        possible[8]=0;
    }
}

void Relleno()
///RELLENA LOS ARREGLOS CON LAS CONFUGURACIONES DE CADA MOVIMIENTO POSIBLE
{
    for (int x=1; x<=110; x++){
        B0[x]=1;
    }

    for(int x=1;x<=110; x=(x+2)){///Arreglos pares e impares
        B2[x]=0;
        B2[x+1]=1;
        ////////////
        B3[x]=1;
        B3[x+1]=0;
    }
    B4[1]=0;
    for(int x=2; x<=110; x=(x+3)){///0110110110
        B4[x]=1;
        B4[x+1]=1;

    }
    B4_1[1]=1;
    for(int x=2; x<=110; x=(x+3)){///1001001001
        B4_1[x]=0;
        B4_1[x+1]=0;
        B4_1[x+2]=1;
    }

    /// B2_4 00111000111000111000111
    B2_4[1]=0;
    B2_4[2]=0;
    for(int x=3; x<=110; x=(x+6)){
       B2_4[x]=1;
       B2_4[x+1]=1;
       B2_4[x+2]=1;
    }
    /// B3_4 11000111000111000111000
    B3_4[1]=1;
    B3_4[2]=1;
    for(int x=6; x<=110; x=(x+6)){
       B3_4[x]=1;
       B3_4[x+1]=1;
       B3_4[x+2]=1;
    }
}

void Sal()///Determina cuales arreglos imprimir :D
{
    l=((8-posb)+1);///posicion en Ordpossible
           for (int i=1; i<=posb; i++){
                for (int y=1; y<=8; y++){
                    ///Encontrar al Ordpossible que es igual en la posicion x vpossible
                    if (vpossible[y]==Ordpossible[l]){
                        arr=y;
                        ImpArr();
                        cout << "\n";
                        y=9;
                    }
                }
                l++;
           }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int x=1; x<=8; x++){
        possible[x]=1;
    }
    Relleno();
    cin >> N;
    cin >> cont;
    ///ENCENDIDAS
    for(int x=1; x<=100; x++){/// INGRESA LAS LÁMPARAS QUE DEBEN ESTAR ENCENDIDAS
        cin >> ONi;
        if (ONi==(-1)){
            x=101;
        }
        else{
            compON();
        }
    }

    ///APAGADAS
    for(int x=1; x<=100; x++){/// INGRESA LAS LÁMPARAS QUE DEBEN ESTAR APAGADAS
        cin >> OFFi;
        if (OFFi==(-1)){
            x=101;
        }
        else{
            compOFF();
        }
    }

    ///possible ya tiene los posibles con 1 (los valores por posición ya están)
    ///ORDENAR
    m=1;
    if (cont==1){
        possible[5]=0;
        possible[6]=0;
        possible[7]=0;
        possible[8]=0;
    }
    if (cont==2){
        possible[4]=0;
    }
    if (cont==3){
        possible[7]=0;
    }
    for (int x=5; x>=1; x--){///OBTIENE VALORES DE LOS ARREGLOS SUMÁNDOLOS
        if ((B1[x]==1)&&(possible[1]==1)){
            vpossible[1]=(vpossible[1]+m);
            Ordpossible[1]=(Ordpossible[2]+m);
        }
        if ((B2[x]==1)&&(possible[2]==1)){
            vpossible[2]=(vpossible[2]+m);
            Ordpossible[2]=(Ordpossible[2]+m);
        }
        if ((B3[x]==1)&&(possible[3]==1)){
            vpossible[3]=(vpossible[3]+m);
            Ordpossible[3]=(Ordpossible[3]+m);
        }
        if ((B4[x]==1)&&(possible[4]==1)){
            vpossible[4]=(vpossible[4]+m);
            Ordpossible[4]=(Ordpossible[4]+m);
        }
        if ((B4_1[x]==1)&&(possible[5]==1)){
            vpossible[5]=(vpossible[5]+m);
            Ordpossible[5]=(Ordpossible[5]+m);
        }
        if ((B2_4[x]==1)&&(possible[6]==1)){
            vpossible[6]=(vpossible[6]+m);
            Ordpossible[6]=(Ordpossible[6]+m);
        }
        if ((B3_4[x]==1)&&(possible[7]==1)){
            vpossible[7]=(vpossible[7]+m);
            Ordpossible[7]=(Ordpossible[7]+m);
        }
        if ((B0[x]==1)&&(possible[8]==1)){
            vpossible[8]=(vpossible[8]+m);
            Ordpossible[8]=(Ordpossible[8]+m);
        }
        m=(m*2);
    }
    ///Guarda los valores de cada arreglo posible. Los imposibles son 0 ._.
    sort(Ordpossible+1, Ordpossible+9);///ordena los valores de las posibilidades.

    for (int i=8; i>=1; i--){
       if (possible[i]==1){
            posb++;
       }
    }
    cout << posb << "\n";
    Sal();


    return 0;
}
