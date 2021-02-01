#include <iostream>

using namespace std;

void hareket(int disks, int kule1, int kule3, int kule2)
{
if (disks == 1) {
printf("%d -> %d\n", kule1, kule3);
return;
}
hareket(disks - 1, kule1, kule2, kule3);
printf("%d -> %d\n", kule1, kule3);
hareket(disks - 1, kule2, kule3, kule1);
}




int main()
{
int disks;
cout<<"Disk sayisi giriniz =\n";
cin>>disks;
hareket(disks, 1, 3, 2);
return 0;
} 

