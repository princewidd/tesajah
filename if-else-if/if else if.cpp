#include <iostream>
using namespace std;

int main() {
    int total_belanja;

    cout << "Masukkan total belanja: ";
    cin >> total_belanja;

    if (total_belanja >= 100000) {
        cout << "Anda mendapat diskon 10%" << endl;
    }
    else if(total_belanja >= 50000) {
	   cout << "Anda mendapat diskon 5%" << endl;
    }
    else {
        cout << "gadapet diskon wlee" << endl;
    }
    
    cout << "Terimakasih";
return 0;
}
    
