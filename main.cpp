#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Mahasiswa
{
    string nama;
    string jenisKelamin;
    int umur;
    int nim;
};

struct Node
{
    Mahasiswa data;
    Node *next;
};

Node *head = nullptr;
int jumlah_mahasiswa = 0;

string toLowerCase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string toUpperCase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

void insertMahasiswa(const Mahasiswa &mahasiswa)
{
    Node *newNode = new Node();
    newNode->data = mahasiswa;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    jumlah_mahasiswa++;
}

void deleteMahasiswa(int nim)
{
    if (head == nullptr)
    {
        cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
        return;
    }

    if (head->data.nim == nim)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        jumlah_mahasiswa--;
        cout << "Data mahasiswa dengan NIM " << nim << " berhasil dihapus." << endl;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr && temp->next->data.nim != nim)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }
    else
    {
        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        jumlah_mahasiswa--;
        cout << "Data mahasiswa dengan NIM " << nim << " berhasil dihapus." << endl;
    }
}

void displayMahasiswa()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << endl;
        cout << "--------------------------------" << endl;
        cout << "|Nama          : " << toLowerCase(temp->data.nama) << endl;
        cout << "|Jenis Kelamin : " << toUpperCase(temp->data.jenisKelamin) << endl;
        cout << "|Umur          : " << temp->data.umur << endl;
        cout << "|Nim           : " << temp->data.nim << endl;
        cout << "--------------------------------" << endl;
        temp = temp->next;
    }
}

void inputMahasiswa()
{
    if (jumlah_mahasiswa < 100)
    {
        Mahasiswa mahasiswa;
        cout << "Nama Lengkap   : ";
        getline(cin, mahasiswa.nama);

        bool validInput = false;
        while (!validInput)
        {
            cout << "Jenis Kelamin (pria/wanita) : ";
            cin >> mahasiswa.jenisKelamin;
            mahasiswa.jenisKelamin = toLowerCase(mahasiswa.jenisKelamin);
            if (mahasiswa.jenisKelamin == "pria" || mahasiswa.jenisKelamin == "wanita")
            {
                validInput = true;
            }
            else
            {
                cout << "Input jenis kelamin tidak valid. Harap masukkan 'pria' atau 'wanita'." << endl;
            }
        }

        cout << "Umur           : ";
        cin >> mahasiswa.umur;
        cout << "Nim            : ";
        cin >> mahasiswa.nim;

        insertMahasiswa(mahasiswa);

        cout << endl;
        cout << "Data berhasil disimpan" << endl;
        getchar();
        system("cls");
    }
    else
    {
        cout << "Data penuh" << endl;
    }
}

void hapusMahasiswa()
{
    int nim;
    cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
    cin >> nim;
    deleteMahasiswa(nim);
}

void DataMahasiswa()
{
    displayMahasiswa();
    getchar();
    system("cls");
}

int main()
{
    int pilihan, exit = 0;
    do
    {
        cout << "Masukkan Pilihan" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Keluar" << endl;
        cin >> pilihan;
        cin.ignore();
        switch (pilihan)
        {
        case 1:
            system("cls");
            inputMahasiswa();
            break;
        case 2:
            system("cls");
            DataMahasiswa();
            break;
        case 3:
            system("cls");
            hapusMahasiswa();
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
