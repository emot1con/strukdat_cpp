#include <iostream>
using namespace std;

#define MAX 5 

string nama[MAX];  
int nilai[MAX];
int top = -1;

bool isEmpty()
{
    return top == -1;
}

bool isFull()
{
    return top == MAX - 1;
}

void push(string n, int v)
{
    if (isFull())
    {
        cout << "Stack penuh! Tidak dapat menambahkan data.\n";
        return;
    }
    top++;
    nama[top] = n;
    nilai[top] = v;
    cout << "Data mahasiswa " << n << " dengan nilai " << v << " berhasil ditambahkan.\n";
}

void pop()
{
    if (isEmpty())
    {
        cout << "Stack kosong! Tidak ada data yang bisa dihapus.\n";
        return;
    }
    cout << "Menghapus data mahasiswa " << nama[top] << " dengan nilai " << nilai[top] << ".\n";
    top--;
}

void peek()
{
    if (isEmpty())
    {
        cout << "Stack kosong!\n";
        return;
    }
    cout << "Mahasiswa teratas: " << nama[top] << " (Nilai: " << nilai[top] << ")\n";
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack kosong!\n";
        return;
    }

    cout << "\nDaftar Nilai Mahasiswa (dari atas ke bawah):\n";
    for (int i = top; i >= 0; i--)
    {
        cout << i + 1 << ". " << nama[i] << " - Nilai: " << nilai[i] << endl;
    }
}

int main()
{
    int pilih, n;
    string mhs;
    do
    {
        cout << "\n=== STACK NILAI MAHASISWA ===\n";
        cout << "1. Tambah Data (Push)\n";
        cout << "2. Hapus Data Teratas (Pop)\n";
        cout << "3. Lihat Data Teratas (Peek)\n";
        cout << "4. Tampilkan Semua Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            cout << "Masukkan nama mahasiswa: ";
            cin >> mhs;
            cout << "Masukkan nilai: ";
            cin >> n;
            push(mhs, n);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 5);

    return 0;
}
