#include <iostream>
using namespace std;
int main (){
int deger1 = 5, deger2 = 15;
int *p1, *p2;
p1 = &deger1; // p1 = deger1 in adresi =5
p2 = &deger2; // p2 = deger2 in adresi =15
cout<<p1<<endl<<p2<<endl;
*p1 = 10; // p1 ile i�aret edilen hucredeki deger p1=10
*p2 = *p1; // p2 ile i�aret edilen h�credeki deger p1 ile isaret //edilen h�credeki de�ere e�itleniyor
//2 side 10 olur 
cout<<deger1<<endl<<deger2<<endl;
p1 = p2; // p1 = p2 (i�aret�iler e�itlendi) art�k p1 deger2 yi isaret ediyor //ayni yeri g�stericek 
cout<<p1<<endl<<p2<<endl;
*p1 = 20; // p1 in isaret etti�i deger 20 olarak guncellendi
cout<<*p1<<endl<<*p2<<endl;
cout << "deger1==" << deger1 <<endl<<"deger2==" << deger2<<endl;
cout<<"deger1 adresi: "<<&deger1<<endl<<"deger2 adresi: "<<&deger2<<endl;
system("pause");
return 0;
}
