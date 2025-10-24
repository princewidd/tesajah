#include <iostream>
using namespace std;

int main() {
    int menu;
    cout << "Menu:\n1. Nasi Goreng Komplit plit plitt \n2. Mie Ayam JUMBOOOO\n3. Sate Ayam Semrawut\n";
    cout << "Pilih menu (1-3): ";
    cin >> menu;

    switch (menu) {
        case 1: cout << "Harga: Rp32.000"; break;
        case 2: cout << "Harga: Rp25.000"; break;
        case 3: cout << "Harga: Rp35.000"; break;
        default: cout << "Menu tidak tersedia!";
    }
	cout << "\nJan lupa bayar\n terimakasih";
return 0;
}
