#include "tubes.h"
using namespace std;

#include <iostream>


int main() {
    ListToko listToko;
    ListItem listItem;

    createLT(listToko);
    createLI(listItem);

    opening();

    int choice = -1;  // Initialize choice with a non-zero value to enter the loop
    while (choice != 0) {
        menu();
        cin >> choice;

        if (choice == 1) {
            // Tambah Toko
            infotype_toko tokoInfo;
            cout << "Masukkan nama toko: ";
            cin >> tokoInfo.nama_toko;
            cout << "Masukkan lokasi toko: ";
            cin >> tokoInfo.lokasi_toko;
            cout << "Masukkan rating toko: ";
            cin >> tokoInfo.rating_toko;

            adr_toko newToko = createNewElmToko(tokoInfo);
            insertLastToko(listToko, newToko);

            cout << "Toko berhasil ditambahkan!" << endl;
            showToko(listToko);
        } else if (choice == 2) {
            // Tambah Produk
            infotype_item itemInfo;
            cout << "Masukkan jenis produk: ";
            cin >> itemInfo.jenis;
            cout << "Masukkan nama produk: ";
            cin >> itemInfo.nama_item;
            cout << "Masukkan ukuran produk: ";
            cin >> itemInfo.ukuran_item;
            cout << "Masukkan warna produk: ";
            cin >> itemInfo.warna_item;

            adr_item newItem = createNewElmItem(itemInfo);
            insertLastItem(listItem, newItem);

            cout << "Produk berhasil ditambahkan!" << endl;
        } else if (choice == 3) {
            // Hubungkan Toko dengan Produk
            string namaToko, jenisItem, namaItem, ukuranItem, warnaItem;
            cout << "Masukkan nama toko: ";
            cin >> namaToko;
            cout << "Masukkan jenis produk: ";
            cin >> jenisItem;
            cout << "Masukkan nama produk: ";
            cin >> namaItem;
            cout << "Masukkan ukuran produk: ";
            cin >> ukuranItem;
            cout << "Masukkan warna produk: ";
            cin >> warnaItem;

            connectTokotoItem(listToko, listItem, namaToko, jenisItem, namaItem, ukuranItem, warnaItem);

            cout << "Hubungan toko dengan produk berhasil dibuat!" << endl;
            showTokoAndItem(listToko);
        }else if (choice ==4){
            //cari detail toko

        }

        else if (choice == 0) {
            cout << "Terima kasih telah menggunakan kiw kiw E-commerce!" << endl;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
