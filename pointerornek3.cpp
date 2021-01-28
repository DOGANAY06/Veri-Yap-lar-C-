#include <iostream>
using namespace std;
int main(){
	int a=100;
	int *p=&a;
	cout<<a<<" "<<&a <<endl;
	cout<<p<<" "<<&p<<endl; //işaret ettiği a değerinin yeri ve  işaret edilen p nin değeri 
	cout<<*p;  //p nin işaret ettiği sayı
	int ar=58;
	int pa=&ar;
	int q=&pa;
	cout<<ar<<endl;
	cout<<*pa<<endl;
	cout<<**q<<endl;
}

