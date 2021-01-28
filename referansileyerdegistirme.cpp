#include <iostream>
using namespace std;
void Yerdegistir(char& y, char& z) {
char temp = y;
y = z;
z = temp;
}
int main() {
char a = 'y';
char b = 'n';
Yerdegistir(a, b);
cout << a << b << endl;
return 0;
system("pause");
}
