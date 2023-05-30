#include <iostream>
using namespace std;

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

typedef struct smp
{
    char kontainer;
    alamatsimpul next;
    alamatjalur arc;
} simpul;

typedef struct jlr
{
    int kontainer_jalur;
    alamatjalur next_jalur;
    simpul *tujuan;
} jalur;

typedef struct
{
    simpul* first;
} graph;

void createEmpty(graph *G){
    (*G) .first =  NULL;
}

void addSimpul(char c, graph *G){
    simpul *baru;
    baru = new simpul;
        baru->kontainer = c;
        baru->next =  NULL;
        baru->arc =  NULL;

        if ((*G) .first ==  NULL){
            /* Jika graph kosong */
            (*G) .first = baru;
        }
        else {
            /* menambahkan simpul baru pada akhir graph */
            simpul *last = (*G) .first;
            while (last->next !=  NULL)
            {
                last = last->next;
            }

            last->next = baru;
        }
}

void addJalur(simpul *awal, simpul *tujuan, int beban){
    jalur *baru;
    baru = new jalur;
        baru->kontainer_jalur = beban;
        baru->next_jalur =  NULL;
        baru->tujuan = tujuan;

        if (awal->arc ==  NULL)
        {
            /* Jika list jalur kosong */
            awal->arc = baru;
        }
        else{
            /*menambahkan jalur baru pada akhir list jalur */
            jalur *last = awal->arc;
            while (last->next_jalur !=  NULL)
            {
                last = last->next_jalur;
            }

            last->next_jalur = baru;
        }
}

simpul* findSimpul(char c, graph G){
    simpul *hasil =  NULL;
    simpul *bantu = G.first;

    bool ketemu = false;
    while ((bantu !=  NULL) && (ketemu == false))
    {
        if (bantu->kontainer == c)
        {
            hasil = bantu;
            ketemu = true;
        }
        else{
            bantu = bantu->next;
        }
    }
    return hasil;
}

void delJalur(char ctujuan, simpul *awal){
    jalur *hapus = awal->arc;

    if (hapus !=  NULL){
        jalur *prev =  NULL;
        /* mencari jalur yang akan dihapus */
        bool ketemu =false;
        while ((hapus !=  NULL) && (ketemu == false))
        {
            if (hapus->tujuan->kontainer == ctujuan)
            {
                ketemu = true;
            }
            else {
                prev = hapus;
                hapus = hapus->next_jalur;
            }
        }

        if (ketemu == true){
            if(prev ==  NULL){
                /* hapus jalur pertama */
                awal->arc = hapus->next_jalur;
                hapus->next_jalur =  NULL;
            }
            else{
                if(hapus->next_jalur ==  NULL){
                    /* hapus jalur terakhir */
                    prev->next_jalur =  NULL;
                }
                else {
                    /* hapus jalur di tengah */
                    prev->next_jalur = hapus->next_jalur;
                    hapus->next_jalur =  NULL;
                }
            }

            delete hapus;
        }
        else {
            cout << "tidak ada jalur dengan simpul tujuan"<<endl;
        }   
    }
    else {
        cout << "tidak ada jalur dengan simpul tujuan" <<endl;
    }
}

void delAll(simpul *awal){
    jalur *bantu;
    bantu = awal->arc;
    jalur *hapus;

    while (bantu !=  NULL)
    {
        hapus = bantu;
        bantu = bantu->next_jalur;
        awal->arc = bantu;
        hapus->next_jalur =  NULL;
        delete hapus;
    }
    
}

void delSimpul(char c, graph *G){
    simpul *hapus = (*G) .first;
    if(hapus !=  NULL){
        simpul *prev =  NULL;

        /* mencari simpul yang akan dihapus */
        bool ketemu = false;
        while ((hapus !=  NULL) && (ketemu = false))
        {
            if (hapus->kontainer == c)
            {
                ketemu = true;
            }
            else {
                prev = hapus;
                hapus = hapus->next;
            }
        }
        
        if (ketemu == true)
        {
            /* Jika simpul yang akan dihapus ada */
            /* hapus semua jalur dari simpul lain yang mengarah pada simpul yang dihapus */
            simpul *bantu;
            bantu = (*G) .first;

            /* memeriksa semua simpul dalam graf */
            while(bantu !=  NULL){
                /* jika simpul yang ditelusuri tidak sama dengan yang dihapus */
                if (bantu != hapus)
                {
                    /* hapus semua jalur yang mengarah pada simpul yang dihapus */
                    delJalur(hapus->kontainer, bantu);
                }

                bantu = bantu->next;
            }

            /* hapus semua jalur */
            delAll(hapus);

            if (prev ==  NULL)
            {
                /* hapus simpul pertama */
                (*G) .first = hapus->next;
                hapus->next =  NULL;
            }
            else {
                if (hapus->next ==  NULL)
                {
                    /* hapus simpul terakhir */
                    prev->next =  NULL;
                }
                else {
                    /* hapus simpul di tengah */
                    prev->next = hapus->next;
                    hapus->next =  NULL;
                }
            }

            delete hapus;
        }
        else {
            cout << "tidak ada simpul dengan info karakter masukan"<<endl;
        }
    }
    else {
        cout << "tidak ada simpul dengan info karakter masukan"<<endl;
    }
}

void printGraph(graph G){
    simpul *bantu = G.first;
    if (bantu !=  NULL)
    {
        while (bantu !=  NULL)
        {
            cout << "simpul : " << bantu->kontainer << endl;
            jalur *bantu_jalur = bantu->arc;

            while (bantu_jalur !=  NULL)
            {
                cout << " - ada jalur ke simpul " << bantu_jalur->tujuan->kontainer << " dengan beban: " << bantu_jalur->kontainer_jalur <<endl;

                bantu_jalur = bantu_jalur->next_jalur;
            }

            bantu = bantu->next;
        }
    }
    else {
        cout << "graf kosong"<<endl;
    }
}

int main(){
    graph G;
    createEmpty(&G);
    addSimpul('A', &G);
    addSimpul('B', &G);
    addSimpul('C', &G);
    addSimpul('D', &G);
    addSimpul('E', &G);
    addSimpul('F', &G);

    simpul *begin = findSimpul('A', G);
    simpul *end = findSimpul('B', G);

    if((begin !=  NULL) && (end !=  NULL)){
        addJalur(begin, end, 3);
    }

    begin = findSimpul('B', G);
    end = findSimpul('D', G);
    if((begin !=  NULL) && (end !=  NULL)){
        addJalur(begin, end, 3);
    }

    end = findSimpul('E', G);
    if((begin !=  NULL) && (end !=  NULL)){
        addJalur(begin, end, 7);
    }

    begin = findSimpul('C', G);
    end = findSimpul('A', G);
    if((begin !=  NULL) && (end !=  NULL)){
        addJalur(begin, end, 3);
    }

    begin = findSimpul('D', G);
    if((begin !=  NULL) && (end !=  NULL)){
        addJalur(begin, end, 8);
    }

    end = findSimpul('C', G);
    if((begin !=  NULL) && (end !=  NULL)){
        addJalur(begin, end, 3);
    }

    begin = findSimpul('E', G);
    end = findSimpul('D', G);
    if((begin !=  NULL) && (end !=  NULL)){
        addJalur(begin, end, 4);
    }

    end = findSimpul('F', G);
    if((begin !=  NULL) && (end !=  NULL)){
        addJalur(begin, end, 4);
    }

    begin = findSimpul('F', G);
    if((begin !=  NULL) && (end !=  NULL)){
        addJalur(begin, end, 4);
    }

    begin = findSimpul('F', G);
    end = findSimpul('D', G);
    if((begin !=  NULL) && (end !=  NULL)){
        addJalur(begin, end, 2);
    }

    cout << "==================="<<endl;
    printGraph(G);
    cout <<endl;
    cout << "==================="<<endl;

    begin = findSimpul('A', G);
    if(begin !=  NULL){
        delJalur('B', begin);
    }

    cout << "==================="<<endl;
    cout << "setelah dihapus"<<endl;
    printGraph(G);
    cout <<endl;
    cout << "==================="<<endl;

    return 0;
}