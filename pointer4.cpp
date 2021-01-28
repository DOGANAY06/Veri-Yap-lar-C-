#include <iostream>
using namespace std;
int main(){
    int ar=58;
	int *pa=&ar;
	int **q=&pa;
	cout<<ar<<endl;
	cout<<*pa<<endl;
	cout<<**q<<endl;
}

