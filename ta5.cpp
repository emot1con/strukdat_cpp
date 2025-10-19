#include <iostream>
#include <string>
using namespace std;

// Struktur Node BST
struct Node {
    string nama;
    float nilai;
    Node *left, *right;

    Node(string n, float nl) : nama(n), nilai(nl), left(nullptr), right(nullptr) {}
};

// Fungsi untuk menambahkan data mahasiswa ke BST (berdasarkan nilai)
Node* insertNode(Node* root, string nama, float nilai) {
    if (root == nullptr)
        return new Node(nama, nilai);

    if (nilai < root->nilai)
        root->left = insertNode(root->left, nama, nilai);
    else if (nilai > root->nilai)
        root->right = insertNode(root->right, nama, nilai);

    return root;
}

// Fungsi untuk mencari mahasiswa berdasarkan nilai
Node* searchNode(Node* root, float nilai) {
    if (root == nullptr || root->nilai == nilai)
        return root;
    else if (nilai < root->nilai)
        return searchNode(root->left, nilai);
    else
        return searchNode(root->right, nilai);
}

// Fungsi traversal inorder (menampilkan data terurut berdasarkan nilai)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << "Nilai : " << root->nilai << "\n";
    cout << "Nama  : " << root->nama << "\n";
    cout << "---------------------\n";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int pilih;
    string nama;
    float nilai;

    do {
        cout << "\n=== DATA NILAI MAHASISWA (BST) ===\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Cari Data Mahasiswa Berdasarkan Nilai\n";
        cout << "3. Tampilkan Semua Data (Inorder)\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            cout << "Masukkan Nama  : ";
            getline(cin, nama);
            cout << "Masukkan Nilai : ";
            cin >> nilai;
            root = insertNode(root, nama, nilai);
            cout << "Data berhasil ditambahkan!\n";

        } else if (pilih == 2) {
            cout << "Masukkan Nilai yang dicari: ";
            cin >> nilai;
            Node* hasil = searchNode(root, nilai);
            if (hasil != nullptr) {
                cout << "\nData ditemukan:\n";
                cout << "Nama  : " << hasil->nama << "\n";
                cout << "Nilai : " << hasil->nilai << "\n";
            } else {
                cout << "Data dengan nilai " << nilai << " tidak ditemukan.\n";
            }

        } else if (pilih == 3) {
            if (root == nullptr)
                cout << "Belum ada data mahasiswa.\n";
            else {
                cout << "\n=== Daftar Mahasiswa (Inorder) ===\n";
                inorder(root);
            }
        }

    } while (pilih != 4);

    cout << "Program selesai.\n";
    return 0;
}
