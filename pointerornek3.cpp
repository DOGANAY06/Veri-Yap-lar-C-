#include <iostream>
using namespace std;
int main(){
	int a=100;
	int *p=&a;
	cout<<a<<" "<<&a <<endl;
	cout<<p<<" "<<&p<<endl; //i�aret etti�i a de�erinin yeri ve  i�aret edilen p nin de�eri 
	cout<<*p;  //p nin i�aret etti�i say�
	int ar=58;
	int pa=&ar;
	int q=&pa;
	cout<<ar<<endl;
	cout<<*pa<<endl;
	cout<<**q<<endl;
}

