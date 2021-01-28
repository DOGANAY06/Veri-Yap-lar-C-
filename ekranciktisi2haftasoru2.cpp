#include <iostream>
using namespace std;
int main( ){
int i, *p, *r, t[4]={0,1,2,3};
p = new int[4];
for(i=0; i<4; i++)
p[i] = 6*(i+1);
r = t;
for(i=3; i>=0; i--)
r[i] -= 1;
r[2] = 8;
for(i=0; i<4; i++)
t[i] = p[i] + r[i];
for(i=0; i<4; i++)
cout << t[i] << " ";
delete [] p;
system("pause");
return 0;
}
