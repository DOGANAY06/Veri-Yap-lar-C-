#include <iostream>
using namespace std;
int main ()
{
int m = 10;
int &j = m; // j is a Referans variable
cout << "deger of m = "<< m <<" "<<&j<< endl;
//print 10
j = 18;
cout << "deger of m = " << m<<" "<<&j << endl;
// print 18
system("pause");
return 0;
}
