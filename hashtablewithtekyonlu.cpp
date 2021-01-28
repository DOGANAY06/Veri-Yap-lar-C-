#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct veri
{
	int k,v;
}LISTE;
LISTE a[9];
int h(int x) //hash fonksiyonu
{
	return x%10; //hash function 
}

int put(LISTE data) //hash ekleme islemi 
{
	if(a[h(data.k)].k ==-1 ) //eleman yeri bossa datanýn dügüm degeri -1 e esitmi 
	{
	   a[h(data.k)] = data;
	   return 1;	
	}
	else{
		int indis =h(data.k); //hash fonksiyonunda gelen degeri indise atadým 
		while(a[indis].k!=-1)
		{
			indis++; //indisi artýr bir sonraki degere koy
		}
		a[indis]=data.v;
	}
}

int bastir()
{
	for(int i=0;i<9;i++)
	{
		cout<<a[i].k<<" "<<a[i].v<<endl;
	}
}

int get(int k) //hash arama islemi search  
{
	if(a[h(k)].k==-1) //olmayan deger araniyor
 	{
		return -1;
	}
	return a[h(k)].v;
}

int main()
{
	for(int i=0;i<9;i++)
	{
		a[i].k=-1;
	}
	LISTE data;
	data.k = 1;
	data.v = 423;
	put(data);
	data.k= 8;
	data.v = 342;
	put(data);
	data.k=4;
	data.v=35;
	put(data);
	
	bastir();
}
