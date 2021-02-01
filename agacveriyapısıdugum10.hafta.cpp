#include <iostream>
#include <stdlib.h>
using namespace std;

struct dugum
{
  int data;
  struct dugum *sol;
  struct dugum *sag;
};
//d�g�m ekleme i�lemi
struct dugum *dugum_ekleme (struct dugum *tree, int val)
{
  struct dugum *ptr, *nodeptr, *parentptr;
  ptr = (struct dugum *) malloc (sizeof (struct dugum));
  ptr->data = val;
  ptr->sol = NULL;
  ptr->sag = NULL;
  if (tree == NULL) //eleman yoksa k�k eleman eklenecek �nce
  {
    tree = ptr;
    tree->sol = NULL;
    tree->sag = NULL;
	}
  else  //i�inde eleman varsa
    { 
    parentptr = NULL;
    nodeptr = tree; 
    while (nodeptr != NULL) //NULL eleman� g�rene kadar devam et
	{
	parentptr = nodeptr;   
	if (val < nodeptr->data) //gelen data olan datadan k�c�kse 
	    nodeptr = nodeptr->sol; //sola ekleme islemi yap�lacak
	else
	    nodeptr = nodeptr->sag; //gelen data  b�y�ksek saga ekleme islemi yap�alcak 
	}
      if (val < parentptr->data)
	parentptr->sol = ptr;
      else
	parentptr->sag = ptr;
    }
  return tree;
}

struct dugum *dugum_ara (struct dugum *tree, int aranan) //dugum arama i�lemi i�in kullan�l�r
{
  struct dugum *cur;
  if (tree == NULL)
    {
      printf ("\n Agac Bos ");
      return (tree);
    }
  cur = tree; //k�k� e�itledik 
  if (cur->data == aranan)  //datalar� kontrol ettik aranana esit mi 
    return (cur); //esitse ilk k�k d�ner 
  while (cur != NULL && aranan != cur->data)  //aranan e�it de�ilse son k�ke gelene kadar devam eder 
    {
      cur = (aranan < cur->data) ? cur->sol : cur->sag;
    }
  if (cur != NULL)  //eger a�ac bo�sa 
    return (cur);
  else
    return NULL;
}
void postorder_gezinme (struct dugum *tree)
  {
    if (tree != NULL)
      {
	postorder_gezinme (tree->sol);
	postorder_gezinme (tree->sag);
	printf ("%d\t", tree->data);
      }
  }
struct dugum *dugum_sil (struct dugum *tree,int val)
{ //d���m silme islemi 
  struct dugum *cur, *parent, *suc, *psuc, *ptr;
  if (tree->sol == NULL)
    {
      printf ("\n Agac Bos ");
      return (tree);
    }
  parent = tree;
  cur = tree->sol;
  while (cur != NULL && val != cur->data)
    {
      parent = cur;
      cur = (val < cur->data) ? cur->sol : cur->sag;
    }
  if (cur == NULL)
    {
      printf ("\n Silinecek eleman agacta yok ! ");
      return (tree);
    }
  if (cur->sol == NULL)
    ptr = cur->sag;
  else if (cur->sag == NULL)
    ptr = cur->sol;
  else				// inb
    {// in�order gezinme ile cocuk ve aile dugumleri bul
psuc = cur;cur = cur->sol;
while(suc->sol!=NULL)
{psuc = suc;suc = suc->sol;}
if(cur==psuc)
{// Durum 1
suc->sol = cur->sag;}
else
{// Durum 2
suc->sol = cur->sol;psuc->sol = suc->sag;suc->sag = cur->sag;}
ptr = suc;
}
// ptr yi aile dugume bagla
if(parent->sol == cur) parent->sol=ptr;
else parent->sag=ptr;
free(cur); return tree; }
/*int main()
{
	struct dugum *tree=NULL;
	int sayi;
	int i=0;
	char karakter;
	/*while(i<7) //7 tane dugumlu struct
	{
		cout<<"Sayi giriniz \n";
		cin>>sayi;
		root = dugumEkle(root,sayi);
		i++;
	}
	do{
		cout<<"Hangi sekilde islemi yapmak istersiniz\n D���m Ekleme='a'\nD�g�m silme='d'\nGezinme='p'\n"<<
		"D�g�m arama='s'\nCikis='C'";
		cin>>karakter;
		switch(karakter){
		case 'a':
			cout<<"Sayi giriniz \n";
			cin>>sayi;
			dugum_ekleme(*struct dugum tree,sayi);
			break;
		/*case 'I':
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
}*/

