#include <iostream>
using namespace std;
int main()
{
int *A = new int[5];
for(int i=0; i<5; i++)
A[i] = i;
int *B = A; //A i�aretcisindeki alan� B ye verdik 
for(int i=0; i<5; i++)
cout<<B[i]<<endl; //A daki elemanlar� g�sterir 
cout<<endl<<endl;
delete [] A; //A y� iade ettik 
for(int i=0; i<5; i++)
cout<<B[i]<<endl; //B yi ekrana yazd�k B bo� ��nk� A yok
system("pause");
return 0;
}
