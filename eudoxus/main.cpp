#include <iostream>

using namespace std;
long x,y,yaux;
int n,cont;
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);

   cin >> n;
   cont = 1;
   x = 1;
   y = 0;

   while (cont <= n){
    yaux = y;
    y = (x+y);
    x = y+yaux;
    cont++;
   }

   cout << x << " " << y;

    return 0;
}
