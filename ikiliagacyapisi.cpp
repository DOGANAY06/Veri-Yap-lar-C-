#include <iostream>

using namespace std;

struct node{
	int data;
	struct node *left; //sol dal  kücük olan kisim
	struct node *right;  //sag dal büyük olan kisim
};

struct node* kokdugum(int key) //agacyapisana kök dugumu ekledik 
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
		{ //sayý buyuktur bu sayede sað tarafa eklenecek
			root->right =dugumEkle(root->right,key);
		}
	}
	return root;
}

void preorder(struct node *root) //once kök islemi 
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}	
}
void inorder(struct node *root) //ortada  kök islemi 
{
	if(root!=NULL)
	{
		inorder(root->left); //en sola gel
		cout<<root->data<<" ";
		inorder(root->right); //en sag gel
		
	}	
}
void postorder(struct node *root) //sonda  kök islemi 
{
	if(root!=NULL)
	{
		postorder(root->left); //en sola gel
		postorder(root->right); //en sag gel
		cout<<root->data<<" ";
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
		cout<<"Hangi sekilde agaci dolasmak istersiniz\n Preorder='p'\t,Inorder='I'\t,Postorder='o'\nCikis icin=C basiniz \n";
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
