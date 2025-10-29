#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>  // biar bisa akses fungsi WinAPI kalau mau nanti
using namespace std;

int main()
{
    string nama[100], nim[100], kelas[100];
    int jumlah = 0;
    int pilih;
    do
    {
        cout << "======== Data Mahasiswa ========" << endl;
        cout << "pilih aja yang kamu mau \n 1. tambah data \n 2. tampilkan data \n 3. cari data \n 4. ubah data \n 5. hapus data \n";
        cout << " 6. menyimpan file\n 7. membuka file \n 8. keluar\n";
        cout << "pilih : " << endl;
        cin >> pilih;

        if (pilih == 1)
        {
            cin.ignore();
            cout << "Masukkan Nama Mahasiswa: ";
            getline(cin, nama[jumlah]);
            cout << "Masukkan NIM Mahasiswa: ";
            getline(cin, nim[jumlah]);
            cout << "Masukkan kelas: ";
            getline(cin, kelas[jumlah]);
            jumlah++;
            cout << "Data berhasil ditambahkan!" << endl;
        }
        else if (pilih == 2)
        {
            cout << "\n=== Daftar Mahasiswa ===" << endl;
            for (int i = 0; i < jumlah; i++)
            {
                cout << i + 1 << ". " << nama[i] << " kelas " << kelas[i] << " (" << nim[i] << ")" << endl;
            }
            if (jumlah == 0)
                cout << "Belum ada data!" << endl;
        }
        else if (pilih == 3)
        {
            cin.ignore();
            string cari;
            bool ditemukan = false;

            cout << "Masukkan nama atau NIM yang ingin dicari: ";
            getline(cin, cari);

            cout << "\n===== Hasilnya =====" << endl;
            for (int i = 0; i < jumlah; i++)
            {
                if (nama[i].find(cari) != string::npos || nim[i].find(cari) != string::npos)
                {
                    cout << i + 1 << ". " << nama[i] << " | NIM: " << nim[i] << " | kelas: " << kelas[i] << endl;
                    ditemukan = true;
                }
            }
            if (!ditemukan)
            {
                cout << "Data ga ada!" << endl;
            }
        }
        else if (pilih == 4)
        {
            cin.ignore();
            string ubah;
            bool ditemukan = false;

            cout << "Masukkan nama atau NIM yang ingin diubah: ";
            getline(cin, ubah);

            for (int i = 0; i < jumlah; i++)
            {
                if (nama[i] == ubah || nim[i] == ubah)
                {
                    cout << "\nData ditemukan:" << endl;
                    cout << "Nama : " << nama[i] << endl;
                    cout << "NIM  : " << nim[i] << endl;
                    cout << "Kelas: " << kelas[i] << endl;

                    cout << "\nMasukkan data baru:" << endl;
                    cout << "Nama baru : ";
                    getline(cin, nama[i]);
                    cout << "NIM baru  : ";
                    getline(cin, nim[i]);
                    cout << "Kelas baru: ";
                    getline(cin, kelas[i]);

                    cout << "Data berhasil diubah!" << endl;
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan)
            {
                cout << "Data tidak ditemukan!" << endl;
            }
        }
        else if (pilih == 5)
        {
            cin.ignore();
            string hapus;
            bool ditemukan = false;

            cout << "Masukkan nama atau NIM yang ingin dihapus (harus sama persis): ";
            getline(cin, hapus);

            for (int i = 0; i < jumlah; i++)
            {
                if (nama[i] == hapus || nim[i] == hapus)
                {
                    cout << "\nData ditemukan:" << endl;
                    cout << "Nama : " << nama[i] << endl;
                    cout << "NIM  : " << nim[i] << endl;
                    cout << "Kelas: " << kelas[i] << endl;

                    char konfirmasi;
                    cout << "\nYakin ingin menghapus data ini? (y/n): ";
                    cin >> konfirmasi;

                    if (konfirmasi == 'y' || konfirmasi == 'Y')
                    {
                        // geser semua data setelahnya ke depan
                        for (int j = i; j < jumlah - 1; j++)
                        {
                            nama[j] = nama[j + 1];
                            nim[j] = nim[j + 1];
                            kelas[j] = kelas[j + 1];
                        }
                        jumlah--;
                        cout << "Data berhasil dihapus!" << endl;
                    }
                    else
                    {
                        cout << "Data batal dihapus." << endl;
                    }

                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan)
            {
                cout << "Data tidak ditemukan!" << endl;
            }
        }
        else if (pilih == 6)
        {
            ofstream file("data_mahasiswa.txt");
            if (!file)
            {
                cout << "Gagal membuka file untuk menyimpan!" << endl;
            }
            else
            {
                for (int i = 0; i < jumlah; i++)
                {
                    file << nama[i] << ";" << nim[i] << ";" << kelas[i] << endl;
                }
                file.close();
                cout << "Data berhasil disimpan ke file 'data_mahasiswa.txt'!" << endl;
            }
        }
        else if (pilih == 7)
        {
            ifstream file("data_mahasiswa.txt");
            if (!file)
            {
                cout << "File tidak ditemukan!" << endl;
            }
            else
            {
                jumlah = 0; // kosongin dulu data lama
                string baris;
                while (getline(file, baris))
                {
                    stringstream ss(baris);
                    getline(ss, nama[jumlah], ';');
                    getline(ss, nim[jumlah], ';');
                    getline(ss, kelas[jumlah], ';');
                    jumlah++;
                }
                file.close();
                cout << "Data berhasil dibaca dari file!" << endl;
            }
        }

        else if (pilih == 8)
        {
            cout << "Keluar dari program..." << endl;
        }
        else
        {
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilih != 8);
    return 0;
}