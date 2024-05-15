#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;

struct Mahasiswa {
    string nama;
    string jenisKelamin;
    int umur;
    int nim;
};

struct Mahasiswa history[100];
int jumlah_mahasiswa = 0;

void inputMahasiswa() {
    if (jumlah_mahasiswa < 100){
        struct Mahasiswa mahasiswa;

        cout << "Nama Lengkap   : ";
        getline(cin, mahasiswa.nama);
        cout << "Jenis Kelamin  : ";
        cin >> mahasiswa.jenisKelamin;
        cout << "Umur           : ";
        cin >> mahasiswa.umur;
        cout << "Nim            : ";
        cin >> mahasiswa.nim;

        history[jumlah_mahasiswa] = mahasiswa;
        jumlah_mahasiswa++;

        cout << endl;
        cout << "Data berhasil disimpan" << endl;
        getchar(); 
        system("cls");
    }
    else {
        cout << "Data penuh"<< endl;
    }
}

void DataMahasiswa() {
    for (int i = 0; i < jumlah_mahasiswa; ++i) {
        cout << endl;
        cout << "--------------------------------" << endl;
        cout << "|Nama          : " << history[i].nama<<endl;
        cout << "|Jenis Kelamin : " << history[i].jenisKelamin<<endl;
        cout << "|Umur          : " << history[i].umur<<endl;
        cout << "|Nim           : " << history[i].nim<<endl;
        cout << "--------------------------------" << endl;
    }
}

void hapusMahasiswa() {
    int nim;
    cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
    cin >> nim;
    int index = -1; 
    for (int i = 0; i < jumlah_mahasiswa; ++i) {
        if (history[i].nim == nim) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < jumlah_mahasiswa - 1; ++i) {
            history[i] = history[i + 1];
        }
        jumlah_mahasiswa--;
        cout << "Data mahasiswa dengan NIM " << nim << " berhasil dihapus." << endl;
    } else {
        cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }
}


int main() {
    int pilihan, exit = 0;
    do {
        cout << "Masukkan Pilihan" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Keluar" << endl;
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                system("cls");
                inputMahasiswa();
                break;
            case 2:
                system("cls");
                DataMahasiswa();
                getchar(); 
                system("cls");
                break;
            case 3:
                system("cls");
                hapusMahasiswa();
                getchar(); 
                system("cls");
                break;

            case 4:
                exit = 1;
                break;
            default:
                cout << "Masukkan pilihan 1, 2, atau 3" << endl;
        }
    } while (exit != 1);
    return 0;
}
