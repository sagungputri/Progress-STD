#include <iostream>
#include "tubes.h"
using namespace std;

int main()
{
    opening();
    menu();
    //test
    ListToko L;
    int i;
    adr_toko Toko;
    infotype_toko info_toko;
    createLT(L);

    //aman
    for (i=0; i<3;i++){
        cin>>info_toko.nama_toko;
        cin>>info_toko.lokasi_toko;
        cin>>info_toko.rating_toko;
        Toko = createNewElmToko(info_toko);
        insertLastToko(L,Toko);
    }

    findToko(L);
    findToko(L);


}
