#include <iostream>
#include <locale.h>

using namespace std;
 
typedef struct dugum
{
	struct dugum *ileri;
	int tepe; //tepe noktasý 
}dugum;

dugum *veri[30]; //listede 20 eleman olmalý  

int ziyaret[30]; //20 elemanda hiç boþta düðüm kalmadan ziyaret edilmeli

int n;
void graf_oku();

void ekle(int u,int v); //listeye ekleme iþlemi için 

void DFS(int a);
 
int main()
{
	setlocale(LC_ALL, "Turkish"); //türkçe harfler kullanmak icin
    cout<<"***************Graf Derinlik öncelikli gezme programýmýza hosgeldiniz************"<<endl;
	graf_oku();
	for(int i=0;i<n;i++)
		ziyaret[i]=0;	
	
	DFS(0);
}
void DFS(int i)
{
    dugum *p;
   
	cout<<"\n"<<i; //her seferinde gelen ziyaret edilmiþ düðümü bir alt satýra giderek ekranda yazdýrýr 
	p=veri[i]; //veri sayisinin içinde bulunan ziyaret edilen tüm elemanlar ifade ediyor
    //toplamda ziyaret edilecek eleman sayisi düðüm sayisina eþittir
	ziyaret[i]=1; //dugum ziyaret edildiyse 1
    while(p!=NULL) //boþ olana kadar dugumu oku 
	{
      i =p->tepe;
		
		if(!ziyaret[i]) //ziyaret edilmediyse
			DFS(i); //recursive olarak baþa dön özyinelemeli
		p =p->ileri; //ziyaret edildiyse ilerle diðer düðüme
	}
}
 
void graf_oku()
{
    int baglanti,u,v,i;
    cout<<"Bu gezme islemini yapabilmeniz icin oncelikle dugumlerden olusan bir grafýnýz olmalý"<<endl;
    cout<<"Grafda dügümden dügüme gecis islemi komsu 2 graf arasýndaki baglantidir"<<endl;
    cout<<"Ornek olarak 6 dügümden, 9 baglantidan olusan bizim grafimizi kullanabilirsiniz \n";
    cout<<"Graf Baglantilari:\n0-1\n0-2\n0-3\n1-3\n2-3\n1-5\n3-4\n3-5\n4-5"<<endl;
    cout<<"Kac dügümlü graf yapacaksýn karar verdin mi  ? = "<<endl;
	cin>>n;
 
	for(i=0;i<n;i++) //boþta düðüm kalmamasý için dfs gezinme iþlemi sonucu köse sayýsý kadar çýkar
	{
		veri[i]=NULL;
		
		cout<<"Graf kac kenardan olusacak "<<endl;
		cin>>baglanti;
		cout<<"Graf dugumlerine komsu matrisler eklemen gerekiyor bunun icin 0-9 arasinda rakamlar sec"<<endl;
		cout<<"Ýki komsu matrisi yazarken aralarýna bosluk koymayý unutmayýn !"<<endl;
		for(i=0;i<baglanti;i++) //baglanti kenar sayisi
		{
			cout<<"Komsuluk matrisi,hangi kenardan kenara (u v)"<<endl;
			cin>>u>>v;
			ekle(u,v); //grafa eklenerek baðlanti ve düðümler graf oluþturmasý için fonksiyonu çaðýrdýk
		}
	}
	
}
 
void ekle(int u,int v)
{
    dugum *p,*x;
    
	x =new dugum; //hafýzada düðüm için yer açýyorum
	x->tepe = v;  //baðlantili kýsmý ekledim
	x->ileri = NULL;  //tepeye eklendikten sonra boþ gösterek ileri yer
	
 
  
    if(veri[u]==NULL)  //listeye ekleme iþlemi yapýlýr
	{
		veri[u]=x; 
	}
    else{
		
		p=veri[u]; //listeyi p dugumune ata 
		
		while(p->ileri!=NULL) //listede boþ eleman gösterene kadar ilerle 
			p=p->ileri;
		p->ileri=x;	 //boþ eleman gösterdiðinde ekle yeni gelen deðeri
	}
}
