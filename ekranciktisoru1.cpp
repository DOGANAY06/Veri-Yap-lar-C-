#include <iostream>
using namespace std;
void F1(int* temp){ *temp = 99; }
int main()
{
int *p1, *p2;
p1 = new int;
*p1 = 50;
p2 = p1;
F1(p2);
cout << *p1 << " " << *p2 << endl;
p1 = new int;
*p1 = 88;
cout << *p1 << " " << *p2 << endl;
delete p1;
delete p2;
system("pause");
return 0;
}
