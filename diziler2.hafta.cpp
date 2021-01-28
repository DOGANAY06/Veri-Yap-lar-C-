#include <iostream>
 
using namespace std;
int main()
{
	int Dizi1[5]={10,11,12,13,14};
	char Okulum[] = "Karamanoglu Mehmetbey Universitesi";
	float Matris[2][4]={{1,2,3,4},{5,6,7,8}};

	for (int i = 0; i < 5; i++)
	{
	cout << Dizi1[i]<<endl;
	}
	cout << endl;
	

	for (int i = 0; i < 34; i++)
	{
	cout << Okulum[i];
	}
	cout << endl;
for (int i = 0; i < 2; i++)
	{
		cout<<endl;
		for (int j = 0; j< 4; j++)
	{
	cout << Matris[i][j];
	cout<<" " ;
	}
	}
	
	
	cout << endl<<endl;
	system("Pause");
    return 0;
}
