#include <iostream> 
using namespace std;
 int main() { int n; 
 cout <<"Kac ogrenci ? ";
  cin >> n; 
  int *notlar = new int[n]; 
  for(int i=0; i < n; i++){ 
  int puan; 
  cout << (i+1)<<". Ogrenci notu : "; 
  cin >> puan; notlar[i] = puan; } 
  cout<<endl<<"Girdiginiz Notlar : "<<endl<<endl; 
  for(int i=0; i < n; i++){ 
  cout << (i+1)<<". Ogrenci notu : "<<notlar[i]<<endl; }
   delete [] notlar;
   system("pause");
    return 0; }
