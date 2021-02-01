#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

struct node{
	int data;
	struct node *left; //sol dal  k�c�k olan kisim
	struct node *right;  //sag dal b�y�k olan kisim
};

struct node* kokdugum(int key) //agacyapisana k�k dugumu ekledik 
{ 
	struct node *root = new node(); //ilk dugum
	root->data = key;
	root->left=NULL;
	root->right =NULL;
	return root;
}

struct node* dugumEkle (struct node *root ,int key)
{
	if(root ==NULL) 
	{
		root =kokdugum(key); //kok dugum olusucak adres donucek ilk gelen sayiyi dondurduk
	}
	else //ilk degilse
	{
		if(key < root->data) //sayi kucu  kse data yani
		{
			root->left =dugumEkle(root->left,key) ;//her seferinde sol dala eklenecek 
		} //recursive donme islemi 
		else
		{ //say� buyuktur bu sayede sa� tarafa eklenecek
			root->right =dugumEkle(root->right,key);
		}
	}
	return root;
}

void preorder(struct node *root) //once k�k islemi 
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}	
}
void inorder(struct node *root) //ortada  k�k islemi 
{
	if(root!=NULL)
	{
		inorder(root->left); //en sola gel
		cout<<root->data<<" ";
		inorder(root->right); //en sag gel
		
	}	
}
void postorder(struct node *root) //sonda  k�k islemi 
{
	if(root!=NULL)
	{
		postorder(root->left); //en sola gel
		postorder(root->right); //en sag gel
		cout<<root->data<<" ";
	}	
}

//agacta ka� adet d���m var

int dugumSayisi(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return dugumSayisi(root->left)+1+ dugumSayisi(root->right); //soldan ba�la sa�adogru git
	}
}
int yukseklik(struct node *root)
{
	if(root==NULL)
	return 0;
	else
	{
		int sol,sag;
		sol = yukseklik(root->left);
		sag = yukseklik(root->right);
		
		if(sol>sag)
		return sol+1;
		else
		return sag+1;
	}
}
void yerDegistir(struct node *root)
{
	struct node *temp =NULL;
	if(root!=NULL) //d�g�m bo� de�eri g�sterene kadar dola� 
	{ //swap islemi yapt�k 
		yerDegistir(root->left);
		yerDegistir(root->right);
		temp = root->left;  //lefti tuttuk 
		root->left = root->right; //left d�g�m�ne right atadik 
		root->right = temp; //right d�g�m�ne lefti atadik 
		
	}
}
int main()
{
	struct node *root=NULL;
	int sayi;
	int i=0;
	char karakter;
	while(i<7) //7 tane dugumlu struct
	{
		cout<<"Sayi giriniz \n";
		cin>>sayi;
		root = dugumEkle(root,sayi);
		i++;
	}
	do{
		cout<<"Hangi sekilde agaci dolasmak istersiniz\n Preorder='p'\t,Inorder='I'\t,Postorder='o'\nCikis icin=C basiniz \n"<<
		"Ekli dugumu bulma 'k'\n Agacin yuksekligi 'h'\n Yer degistir='s'''";
		cin>>karakter;
		switch(karakter){
		case 'p':
			cout<<"PreOrder = ";
			preorder(root);
			break;
		case 'I':
			cout<<"Inorder = ";
			inorder(root);
			break;
		case 'o':
			cout<<"Post order = ";
			postorder(root);
			break;
		case 'k':
			cout<<dugumSayisi(root)<<endl;
			break;
		case 'h':
			cout<<"Agacin yuksekligi ="<<yukseklik(root)<<endl;
		case 's':
			yerDegistir(root);
			inorder(root);
		case 'C':
			cout<<"Cikis islemi";
			break;
		default:
			cout<<"Hatali secim \n";
			break;
	}
	}while(karakter!='C');
	cout<<"Iyi gunler";
	return 0;
}
