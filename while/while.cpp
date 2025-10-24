#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "Masukkan angka 28 untuk berhenti: ";
    cin >> angka;

    while (angka != 28) {
        cout << "Kamu memasukkan: " << angka << endl;
        cout << "Masukkan angka lagi 28 untuk berhenti: ";
        cin >> angka;
    }

    cout << "ALAMAKKK KETEBAKK!";
	return 0;
}
