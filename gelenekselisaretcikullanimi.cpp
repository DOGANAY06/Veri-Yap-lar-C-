#include <iostream>
using namespace std;
void Yerdegistir(char *Ptr1, char *Ptr2){ //y ve n geldi 
char temp = *Ptr1; //geciciye y atad�k 
*Ptr1 = *Ptr2; // n y ye atad�k 
*Ptr2 = temp;  //n =y yi atad�k 
}
int main() {
char a = 'y';
char b = 'n';
Yerdegistir(&a, &b);
cout << a << b << endl;  //n ve y sonucu ortaya �ikar
system("pause");
return 0;
}
