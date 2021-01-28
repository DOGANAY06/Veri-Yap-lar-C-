#include <iostream>
using namespace std;
int main()
{
int *A = new int[5];
for(int i=0; i<5; i++)
A[i] = i;
int *B = A; //A iþaretcisindeki alaný B ye verdik 
for(int i=0; i<5; i++)
cout<<B[i]<<endl; //A daki elemanlarý gösterir 
cout<<endl<<endl;
delete [] A; //A yý iade ettik 
for(int i=0; i<5; i++)
cout<<B[i]<<endl; //B yi ekrana yazdýk B boþ çünkü A yok
system("pause");
return 0;
}
