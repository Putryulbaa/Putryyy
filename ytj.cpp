#include <iostream>
using namespace std;

struct KTP {
    int NIK;
    string nama;
    string alamat;
    KTP* next;
    KTP* prev;
};

KTP* head = NULL;
KTP* tail = NULL;

void tambahData(int NIK, string nama, string alamat) {
    KTP* newNode = new KTP();
    newNode->NIK = NIK;
    newNode->nama = nama;
    newNode->alamat = alamat;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    cout << "Data berhasil ditambahkan!\n";
}

void deleteData(int NIK) {
    if (head == NULL) {
        cout << "List kosong, tidak ada data yang dihapus.\n";
        return;
    }

    KTP* current = head;
    while (current != NULL && current->NIK != NIK) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Data dengan NIK " << NIK << " tidak ditemukan.\n";
        return;
    }

    if (current == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL; // list kosong setelah hapus
    } else if (current == tail) {
        tail = tail->prev;
        tail->next = NULL;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    cout << "Data dengan NIK " << NIK << " telah dihapus.\n";
}

void tampilData() {
    if (head == NULL) {
        cout << "List kosong.\n";
        return;
    }

    KTP* temp = head;
    cout << "\n=== Daftar Data KTP ===\n";
    while (temp != NULL) {
        cout << "NIK    : " << temp->NIK << endl;
        cout << "Nama   : " << temp->nama << endl;
        cout << "Alamat : " << temp->alamat << endl;
        cout << "---------------------------\n";
        temp = temp->next;
    }
}

void menu() {
    int pilih;
    do {
        cout << "\n==== MENU KTP ====\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Tampilkan Data\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            int NIK;
            string nama, alamat;
            cout << "Masukkan NIK: ";
            cin >> NIK;
            cin.ignore();
            cout << "Masukkan Nama: ";
            getline(cin, nama);
            cout << "Masukkan Alamat: ";
            getline(cin, alamat);
            tambahData(NIK, nama, alamat);
        }
        else if (pilih == 2) {
            int NIK;
            cout << "Masukkan NIK yang ingin dihapus: ";
            cin >> NIK;
            deleteData(NIK);
        }
        else if (pilih == 3) {
            tampilData();
        }
        else if (pilih == 4) {
            cout << "Keluar dari program.\n";
        }
        else {
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilih != 4);
}

int main() {
    menu();
    return 0;
}
