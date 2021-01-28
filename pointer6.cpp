#include <iostream>
using namespace std;
int main (){
int deger1 = 5, deger2 = 15;
int *p1, *p2;
p1 = &deger1; // p1 = deger1 in adresi =5
p2 = &deger2; // p2 = deger2 in adresi =15
cout<<p1<<endl<<p2<<endl;
*p1 = 10; // p1 ile işaret edilen hucredeki deger p1=10
*p2 = *p1; // p2 ile işaret edilen hücredeki deger p1 ile isaret //edilen hücredeki değere eşitleniyor
//2 side 10 olur 
cout<<deger1<<endl<<deger2<<endl;
p1 = p2; // p1 = p2 (işaretçiler eşitlendi) artık p1 deger2 yi isaret ediyor //ayni yeri göstericek 
cout<<p1<<endl<<p2<<endl;
*p1 = 20; // p1 in isaret ettiği deger 20 olarak guncellendi
cout<<*p1<<endl<<*p2<<endl;
cout << "deger1==" << deger1 <<endl<<"deger2==" << deger2<<endl;
cout<<"deger1 adresi: "<<&deger1<<endl<<"deger2 adresi: "<<&deger2<<endl;
system("pause");
return 0;
}
