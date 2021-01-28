#include <iostream>
using namespace std;
void Yerdegistir(char *Ptr1, char *Ptr2){ //y ve n geldi 
char temp = *Ptr1; //geciciye y atadýk 
*Ptr1 = *Ptr2; // n y ye atadýk 
*Ptr2 = temp;  //n =y yi atadýk 
}
int main() {
char a = 'y';
char b = 'n';
Yerdegistir(&a, &b);
cout << a << b << endl;  //n ve y sonucu ortaya çikar
system("pause");
return 0;
}
