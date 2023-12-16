#include "tubes.h"
using namespace std;

void opening(){
    cout<<("")<<endl;
	cout<<(" =======================================")<<endl;
	cout<<(" |                                     |")<<endl;
	cout<<(" |           Selamat datang di         |")<<endl;
	cout<<(" |          kiw kiw E-commerce         |")<<endl;
	cout<<(" |                                     |")<<endl;
	cout<<(" =======================================")<<endl;
	cout<<("")<<endl;
}

void menu(){
	cout<<(" ============== M E N U ================")<<endl;
	cout<<(" ---------------------------------------")<<endl;
	cout<<(" | 1.Tambah Toko                       |")<<endl;
	cout<<(" | 2.Tambah Produk                     |")<<endl;
    cout<<(" | 3.Hubungkan toko dengan produk      |")<<endl;
	cout<<(" | 4.Cari Detail Toko                  |")<<endl;
	cout<<(" | 5.Cari Detail Produk                |")<<endl;
	cout<<(" | 6.Cari Detail Produk di suatu Toko  |")<<endl;
	cout<<(" | 7.Hapus Toko                        |")<<endl;
	cout<<(" | 8.Hapus Produk                      |")<<endl;
	cout<<(" | 9.Hapus Produk di suatu  Toko       |")<<endl;
	cout<<(" | 10.Tampil List Toko                 |")<<endl;
	cout<<(" | 11.Tampil List Produk               |")<<endl;
	cout<<(" | 12.Tampil List Toko & Produk        |")<<endl;
	cout<<(" | 13.Jumlah Produk di Toko            |")<<endl;
	cout<<(" =======================================")<<endl;
	cout<<("")<<endl;
	cout<<(" Ketik angka dari menu yang akan dijalankan: ");
	cout<<("")<<endl;
}

void createLT(ListToko &L){ //done
    L.firstToko = NULL;
}
void createLI(ListItem &L){//done
    L.firstItem = NULL;
}

bool isEmptyToko(ListToko L){//done
    return (L.firstToko==NULL);
}
bool isEmptyRelation(list_relation L){
    return (L.firstRelation==NULL);//done
}
bool isEmptyItem(ListItem L){//done
    return L.firstItem==NULL;
}
adr_toko createNewElmToko( infotype_toko x){
    adr_toko P= new elm_toko;//done
    P->info = x;
    P->next_toko = NULL;
    P->items.firstRelation=NULL;
    return P;
}
adr_relation createNewElmRelation(adr_item item){
    adr_relation R = new elm_relation;
    R->next_item = item;
    R->next_relation= NULL;
    return R;

}
adr_relation buatRelasi( adr_item x) {

    adr_relation R = new elm_relation;
    R->next_item = x ;
    R->next_relation = NULL;
    return R;
}
adr_item createNewElmItem(infotype_item x){
    adr_item P = new elm_item;
    P->info=x;
    P->next = NULL; //done
}

void insertLastToko(ListToko &L, adr_toko P ){//done
    if (isEmptyToko(L)) {
        L.firstToko = P;
    } else {
        adr_toko q =L.firstToko;
        while (q->next_toko != NULL) {
            q = q->next_toko;
        }
        q->next_toko = P;
    }

}
void insertLastRel(list_relation &L, adr_relation P){
    adr_relation Q = L.firstRelation;
    if (Q==NULL){
        L.firstRelation = P;
    }else{
        while ((Q->next_relation)!= NULL){
            Q = Q->next_relation;
        }
        Q->next_relation = P;
    }

}
void insertLastItem(ListItem &L, adr_item P){

    if (!isEmptyItem(L)){
        adr_item Q;
        Q = L.firstItem;
        while (Q->next!= NULL){
            Q = Q->next;
        }
        Q->next= P;
    }else{
        L.firstItem = P;
    }
}
void connectTokotoItem(ListToko &L, ListItem P, string namaToko, string jenisItem, string namaItem, string ukuranItem, string warnaItem ){
    // cari toko
    adr_toko foundToko = findTokobyNama(L,namaToko);

    //cari item
    adr_item foundItem = findItem(P,jenisItem,namaItem,ukuranItem,warnaItem);

    //hubungkan kalau ketemu
    if (foundItem!=NULL && foundToko !=NULL){
        adr_relation relasiBaru = createNewElmRelation(foundItem);
        insertLastRel((foundToko->items),relasiBaru);
    }


}
/*
adr_toko delFirstToko(ListToko L){
    adr_toko P = L.firstToko;
    adr_relation Q = P->items.firstRelation;
    if (L.firstToko==NULL){
        cout<<"Kosong "<<endl;
    }else{
        if (P->next_toko ==NULL){
            L.firstToko =NULL;
        }else{
            L.firstToko = P->next_toko;
            while (Q != NULL){
                delLastRel(L);
            }
            P->next_toko = NULL;

        }
    }
    return P;//belum beres eror T_T
}
*/

adr_relation delFirstRel(list_relation L){
    adr_relation P = L.firstRelation;
    if (L.firstRelation==NULL){
        cout<<"Kosong "<<endl;
    }else{
        if (P->next_relation ==NULL){
            L.firstRelation =NULL;
        }else{
            L.firstRelation = P->next_relation;
            P->next_relation = NULL;
        }
    }
    return P;//belum beres
}
adr_item delFirstItem(ListItem L){
    adr_item P = L.firstItem;

    if (isEmptyItem(L)){
        cout<< "Tidak ada produk"<<endl;
    }else {

        if (L.firstItem->next==NULL){
             P = L.firstItem;
            L.firstItem =NULL;
        }else{
            P = L.firstItem;
            L.firstItem = P ->next;
            P->next = NULL;

        }
    }
    return P;
}
adr_toko delAfterToko(ListToko L, adr_toko Prev){
    adr_toko P;
    P = Prev->next_toko;
    Prev->next_toko = P->next_toko;
    P->next_toko =NULL;
    //blm beres
}
adr_relation delAfterRel(list_relation L, adr_relation Prev){
    adr_relation P;
    P = Prev->next_relation;
    Prev->next_relation = P->next_relation;
    P->next_relation =NULL;
    //belom berss
}
adr_item delAfterItem(ListItem L, adr_item prec){
    adr_item P;
    P = prec->next;
    prec->next = P->next;
    P->next =NULL;
    //belom beres
}
adr_toko delLastToko(ListToko L){
    adr_toko p,q;
     if (L.firstToko== NULL){
        p = NULL;
    }else if (L.firstToko->next_toko == NULL){
        p = L.firstToko;
        L.firstToko = NULL;
    }else{
        p = L.firstToko;
        q = L.firstToko;
        while (p->next_toko != NULL){
            q = p;
            p = p->next_toko;
        }
        q ->next_toko = NULL;
    }
    return p;
}//blm beres (blm hapus relasinya



adr_relation delLastRel(list_relation L){
    adr_relation p,q;
     if (L.firstRelation== NULL){
        p = NULL;
    }else if (L.firstRelation->next_relation== NULL){
        p = L.firstRelation;
        L.firstRelation = NULL;
    }else{
        p = L.firstRelation;
        q = L.firstRelation;
        while (p->next_relation != NULL){
            q = p;
            p = p->next_relation;
        }
        q ->next_relation = NULL;
    }
    return p;
}//belum beres
adr_item delLasItem(ListItem L){
    if (isEmptyItem(L)){
        cout<<"Tidak ada produk"<<endl;
        return NULL;
    }else{
        adr_item P;
        adr_item Q = L.firstItem;
        while (Q->next != NULL) {
            P = Q;
            Q = Q->next;
        }
        P->next = NULL;
        return Q;
    }
}

adr_toko findTokobyNama(ListToko L, string nama){
    adr_toko P= L.firstToko;

     while (P != NULL) {
                if (P->info.nama_toko == nama) {
                    return P;
                }
                    P = P->next_toko;

    }
    return NULL;
}


void findToko(ListToko L) {

    string pilihanToko, namaToko, alamat;
    float rating;
    bool found = false;

    cout << "Cari deskripsi toko berdasarkan: " << endl;
    cout << "1. Nama" << endl;
    cout << "2. Lokasi" << endl;
    cout << "3. Rating" << endl;
    cout << "Pilihan:  ";
    cin >> pilihanToko;
    cout<<" "<<endl;

    adr_toko P = L.firstToko;

    if (pilihanToko == "1" || pilihanToko == "2" || pilihanToko == "3" || pilihanToko == "Nama" || pilihanToko == "Lokasi" || pilihanToko == "Rating") {
        if (pilihanToko == "1" || pilihanToko == "Nama") {
            cout << "Nama toko yang dicari: ";
            cin >> namaToko;

            cout<< " "<< endl;


            while (P != NULL) {
                if (P->info.nama_toko == namaToko) {
                    cout << "Deskripsi toko:" << endl;
                    cout << "Nama toko: " << P->info.nama_toko << endl;
                    cout << "Lokasi toko: " << P->info.lokasi_toko << endl;
                    cout << "Rating toko: " << P->info.rating_toko << endl;

                    cout<< " "<<endl;

                    found = true;
                }
                P = P->next_toko;
            }
            if (!found) {
            cout << "Toko tidak ditemukan" << endl;
            found = false;
            }

        } else if (pilihanToko == "2" || pilihanToko == "Lokasi") {
            cout << "Alamat toko yang dicari: ";
            cin >> alamat;

            while (P != NULL) {
                if (P->info.lokasi_toko == alamat) {
                    cout << "Deskripsi toko:" << endl;
                    cout << "Nama toko: " << P->info.nama_toko << endl;
                    cout << "Lokasi toko: " << P->info.lokasi_toko << endl;
                    cout << "Rating toko: " << P->info.rating_toko << endl;

                    cout<< " "<<endl;


                    found = true;
            }
            P = P->next_toko;
            }
            if (!found) {
            cout << "Toko tidak ditemukan" << endl;
            found = false;
            }


        } else if (pilihanToko == "3" || pilihanToko == "Rating") {
            cout << "Rating toko yang dicari: ";
            cin >> rating;

            while (P != NULL) {
                if (P->info.rating_toko == rating) {
                    cout << "Deskripsi toko:" << endl;
                    cout << "Nama toko: " << P->info.nama_toko << endl;
                    cout << "Lokasi toko: " << P->info.lokasi_toko << endl;
                    cout << "Rating toko: " << P->info.rating_toko << endl;

                    cout<< " "<<endl;

                    found = true;
                }
                P = P->next_toko;
            }
            if (!found) {
            cout << "Toko tidak ditemukan" << endl;
            found = false;
            }


        }
    } else {
        cout << "Tidak ada pilihan yang tepat" << endl;

    }
}





void showTokoAndItem(ListToko L){

}

void showTokoItem(ListToko L){


}

void showItem(ListItem L){
    adr_item P = L.firstItem;
    while (P!=NULL){
        cout<<"Jenis produk: "<<P->info.jenis<<endl;
        cout <<"Nama produk: "<<P->info.nama_item<<endl;
        cout<<"Ukuran: "<<P->info.ukuran_item<<endl;
        cout<<"Warna: "<<P->info.warna_item<<endl;
        cout<<" "<<endl;
        P= P->next;
    }

}
adr_item findItem(ListItem L,string jenis, string nama, string ukuran, string warna  ){
    adr_item P= L.firstItem;

     while (P != NULL) {
                if ((P->info.nama_item == nama)&&(P->info.jenis == jenis)&& (P->info.ukuran_item==ukuran)&& (P->info.warna_item==warna)) {
                    return P;
                }
                    P = P->next;
    }
    return NULL;
}

adr_item findItemInToko(ListToko L, string namaToko, string namaItem){

}
void showToko(ListToko L){ //blm cek
     adr_toko P= L.firstToko;
    while(P!=NULL){
        cout<<"Nama toko: "<<P->info.nama_toko<<endl;
        cout<<"Lokasi toko: "<<P->info.lokasi_toko<<endl;
        cout<<"Rating toko: "<<P->info.rating_toko<<endl;
        cout<<" ";
        P= P->next_toko;
    }
}
int countItemInToko(ListToko L){

}


