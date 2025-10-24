#include <iostream>
using namespace std;

int main (){
	int umur;
	cout << "umur?";
	cin >> umur;

if (umur >= 18) {
    if (umur >= 60) {
        cout << "Kamu sudah lansia";
    } else {
        cout << "Kamu dewasa";
    }
} else {
    cout << "Kamu masih anak-anak";
}
return 0;
}
