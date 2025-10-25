#include <iostream>
#include <list>
#include <string>
using namespace std;

const int SIZE = 5;

struct Mahasiswa {
    int nim;
    string nama;
};

int hashFunction(int nim) {
    return nim % SIZE;
}

int main() {
    list<Mahasiswa> table[SIZE];

    // Input data mahasiswa
    Mahasiswa data[5] = {
        {101, "Andi"},
        {106, "Budi"},
        {111, "Citra"},
        {116, "Dewi"},
        {121, "Eka"}
    };

    // Proses memasukkan data ke tabel hash
    for (int i = 0; i < 5; i++) {
        int index = hashFunction(data[i].nim);
        table[index].push_back(data[i]);
    }

    // Menampilkan isi tabel hash
    cout << "Isi Hash Table (Separate Chaining):" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        if (table[i].empty()) {
            cout << "EMPTY" << endl;
        } else {
            list<Mahasiswa>::iterator it;
            for (it = table[i].begin(); it != table[i].end(); ++it) {
                cout << "(" << it->nim << ", " << it->nama << ") -> ";
            }
            cout << "NULL" << endl;
        }
    }

    // Contoh pencarian data
    int cari;
    cout << "\nMasukkan NIM yang ingin dicari: ";
    cin >> cari;

    int idx = hashFunction(cari);
    bool ditemukan = false;

    list<Mahasiswa>::iterator it;
    for (it = table[idx].begin(); it != table[idx].end(); ++it) {
        if (it->nim == cari) {
            cout << "Mahasiswa ditemukan: " << it->nama << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Mahasiswa dengan NIM tersebut tidak ditemukan." << endl;
    }

    return 0;
}
