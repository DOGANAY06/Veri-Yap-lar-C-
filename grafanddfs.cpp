#include <iostream>
#include <locale.h>

using namespace std;
 
typedef struct dugum
{
	struct dugum *ileri;
	int tepe; //tepe noktas� 
}dugum;

dugum *veri[30]; //listede 20 eleman olmal�  

int ziyaret[30]; //20 elemanda hi� bo�ta d���m kalmadan ziyaret edilmeli

int n;
void graf_oku();

void ekle(int u,int v); //listeye ekleme i�lemi i�in 

void DFS(int a);
 
int main()
{
	setlocale(LC_ALL, "Turkish"); //t�rk�e harfler kullanmak icin
    cout<<"***************Graf Derinlik �ncelikli gezme program�m�za hosgeldiniz************"<<endl;
	graf_oku();
	for(int i=0;i<n;i++)
		ziyaret[i]=0;	
	
	DFS(0);
}
void DFS(int i)
{
    dugum *p;
   
	cout<<"\n"<<i; //her seferinde gelen ziyaret edilmi� d���m� bir alt sat�ra giderek ekranda yazd�r�r 
	p=veri[i]; //veri sayisinin i�inde bulunan ziyaret edilen t�m elemanlar ifade ediyor
    //toplamda ziyaret edilecek eleman sayisi d���m sayisina e�ittir
	ziyaret[i]=1; //dugum ziyaret edildiyse 1
    while(p!=NULL) //bo� olana kadar dugumu oku 
	{
      i =p->tepe;
		
		if(!ziyaret[i]) //ziyaret edilmediyse
			DFS(i); //recursive olarak ba�a d�n �zyinelemeli
		p =p->ileri; //ziyaret edildiyse ilerle di�er d���me
	}
}
 
void graf_oku()
{
    int baglanti,u,v,i;
    cout<<"Bu gezme islemini yapabilmeniz icin oncelikle dugumlerden olusan bir graf�n�z olmal�"<<endl;
    cout<<"Grafda d�g�mden d�g�me gecis islemi komsu 2 graf aras�ndaki baglantidir"<<endl;
    cout<<"Ornek olarak 6 d�g�mden, 9 baglantidan olusan bizim grafimizi kullanabilirsiniz \n";
    cout<<"Graf Baglantilari:\n0-1\n0-2\n0-3\n1-3\n2-3\n1-5\n3-4\n3-5\n4-5"<<endl;
    cout<<"Kac d�g�ml� graf yapacaks�n karar verdin mi  ? = "<<endl;
	cin>>n;
 
	for(i=0;i<n;i++) //bo�ta d���m kalmamas� i�in dfs gezinme i�lemi sonucu k�se say�s� kadar ��kar
	{
		veri[i]=NULL;
		
		cout<<"Graf kac kenardan olusacak "<<endl;
		cin>>baglanti;
		cout<<"Graf dugumlerine komsu matrisler eklemen gerekiyor bunun icin 0-9 arasinda rakamlar sec"<<endl;
		cout<<"�ki komsu matrisi yazarken aralar�na bosluk koymay� unutmay�n !"<<endl;
		for(i=0;i<baglanti;i++) //baglanti kenar sayisi
		{
			cout<<"Komsuluk matrisi,hangi kenardan kenara (u v)"<<endl;
			cin>>u>>v;
			ekle(u,v); //grafa eklenerek ba�lanti ve d���mler graf olu�turmas� i�in fonksiyonu �a��rd�k
		}
	}
	
}
 
void ekle(int u,int v)
{
    dugum *p,*x;
    
	x =new dugum; //haf�zada d���m i�in yer a��yorum
	x->tepe = v;  //ba�lantili k�sm� ekledim
	x->ileri = NULL;  //tepeye eklendikten sonra bo� g�sterek ileri yer
	
 
  
    if(veri[u]==NULL)  //listeye ekleme i�lemi yap�l�r
	{
		veri[u]=x; 
	}
    else{
		
		p=veri[u]; //listeyi p dugumune ata 
		
		while(p->ileri!=NULL) //listede bo� eleman g�sterene kadar ilerle 
			p=p->ileri;
		p->ileri=x;	 //bo� eleman g�sterdi�inde ekle yeni gelen de�eri
	}
}
