#include <bits/stdc++.h>

using namespace std;

int n,m;
char c;
string laCadena;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    getline(cin,laCadena);
    if(!((laCadena[0]>='A')&&(laCadena[0]<='Z')||(laCadena[0]>='a')&&(laCadena[0]<='z'))){
        cout<<"El primer caracter no es letra\n";
    }
    if(!((laCadena[1]>='A')&&(laCadena[1]<='Z')||(laCadena[1]>='a')&&(laCadena[1]<='z'))){
        cout<<"El segundo caracter no es letra\n";
    }
    if(!((laCadena[2]>='A')&&(laCadena[2]<='Z')||(laCadena[2]>='a')&&(laCadena[2]<='z'))){
        cout<<"El tercer caracter no es letra\n";
    }
    if(laCadena[3]!='-'){
        cout<<"El cuarto caracter no es guion\n";
    }
    if(!((laCadena[4]>='0')&&(laCadena[4]<='9'))){
        cout<<"El quinto caracter no es digito\n";
    }
    if(!((laCadena[5]>='0')&&(laCadena[5]<='9'))){
        cout<<"El sexto caracter no es digito\n";
    }
    if(!((laCadena[6]>='0')&&(laCadena[6]<='9'))){
        cout<<"El septimo caracter no es digito\n";
    }

    return 0;
}
