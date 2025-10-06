#include <iostream>
using namespace std;

int main()
{
    int n, target;
    int nilai[100];

    cout << "SISTEM PENCARIAN NILAI MAHASISWA" << endl;

    cout << "Masukkan jumlah mahasiswa dalam kelas: ";
    cin >> n;

    cout << "Masukkan nilai mahasiswa satu per satu:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Nilai mahasiswa ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> target;

    cout << "\n Mengecek daftar nilai mahasiswa...\n";

    bool ditemukan = false;
    int posisi = -1;

    for (int i = 0; i < n; i++)
    {
        cout << " Mengecek nilai mahasiswa ke-" << i + 1 << " (" << nilai[i] << ")...\n";

        if (nilai[i] == target)
        {
            ditemukan = true;
            posisi = i;
            cout << "Nilai ditemukan!" << endl;
            cout << "Mahasiswa dengan nilai " << target << " berada pada urutan ke-" << posisi + 1 << " dalam daftar." << endl;
            break;
        }
    }

    if (!ditemukan)
    {
        cout << "Nilai " << target << " tidak ditemukan di antara data mahasiswa." << endl;
        cout << "Mungkin mahasiswa tersebut belum mengumpulkan tugas, atau nilainya berbeda." << endl;
    }

    cout << "Pencarian selesai." << endl;

    return 0;
}
