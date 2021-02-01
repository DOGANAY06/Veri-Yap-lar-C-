#include <iostream>
using namespace std;

int exp(int n){
    int two=1;
    for (int i=0; i<n; ++i){
        two *= 2;
    }
    two = two-1;
    return two;
}

int main()
{
    int disk;
    int start=1;
    int middle=2;
    int last=3;
    cout << "Please enter the number of disks: ";
    cin >> disk;
    cout << endl;

    if ( disk <= 0) cout << "You entered an invalid number." << endl;

    else if ( disk % 2 == 0 ){
        for ( int j=1; j<=exp(disk); j++){

            cout << "Move disk " << "1" << " from tower A to tower B." << endl;
            cout << "Move disk " << "2" << " from tower A to tower C." << endl;
            cout << "Move disk " << "3" << " from tower B to tower C." << endl;

        }
    }
    else if( disk % 2 == 1){
        for ( int j=1; j<=exp(disk); j++){

            cout << "Move disk " << "1" << " from tower A to tower C." << endl;
            cout << "Move disk " << "2" << " from tower A to tower B." << endl;
            cout << "Move disk " << "3" << " from tower C to tower B." << endl;

        }
    }

    return 0;
}
