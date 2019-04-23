/*
Nama : Falah Rizqi Abdullah Fairuz
NPM : 140810180069
Kelas : A
Tanggal : 23 April 2019
UTS
*/

#include<iostream>
#include<string.h>
using namespace std;

struct element
{
    int nomor;
    char tim[20];
    char daerah[20];
    int gol = 0;
    element* next;
};

typedef element* pointer;
typedef pointer list;

void createList(list& first)
{
    first = NULL;
}

void createElement(pointer& baru)
{
    baru = new element;
    cout << "Nomor pendaftaran : "; cin >> baru->nomor;
    cout << "Nama tim : "; cin.ignore(); cin.getline(baru->tim, 20); 
    cout << "Daerah : "; cin.getline(baru->daerah, 20);
    baru->next = NULL;
}

void insertLast(list& first, pointer baru)
{
    pointer last;
    if (first == NULL)
    {
        first = baru;
    }

    else
    {
        last = first;
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = baru;
    }    
}

void search (list first, int key, int& found, pointer& cari)
{
    found = 0;
    cari = first;
    while(found == 0 && cari != NULL)
    {
        if (cari->nomor == key)
        {
            found = 1;
        }
        else
        {
            cari = cari->next;
        }
        
    }
    
}

void update(list& first, int& key)
{
    int found;
    pointer cari, update;
    search(first, key, found, cari);
    if(found)
    {
        update = new element;
        cout << "Update gol : "; cin >> update->gol;
        cari->gol = update->gol;
    }
    else
    {
        cout << "Tidak ditemukan" << endl;
    }
    
}

void sorting(list& first)
{
    int swapped;
    pointer bantu;
    pointer lbantu;

    if (first == NULL)
    {
        return;
    }
    do
    {
        swapped = 0;
        bantu = first;

         while(bantu->next != lbantu){
            if (bantu->gol < bantu->next->gol){
                swap(bantu,bantu->next);
                swapped = 1;
            }
            bantu = bantu->next;
        }
        lbantu = bantu;
    } while (swapped);
    
}

void traversal(list first)
{
    pointer bantu;
    if(first == NULL)
    {
        cout << "List Kosong" << endl;
    }
    else
    {
        bantu = first;
        cout << "No.\t|Tim\t\t|Daerah\t|Gol" << endl;
        do
        {
            cout << bantu->nomor << "\t " << bantu->tim << "\t\t " << bantu->daerah << "\t " << bantu->gol << endl; 
            bantu = bantu->next;
        } while (bantu != NULL);
        
    }
    
}

main()
{
    pointer p;
    list l;
    int k,n;
    createList(l);
    cout << "Banyak tim : "; cin >> n;
    for(int i = 0; i < n; i++)
    {
        createElement(p);
        insertLast(l,p);    
    }

    traversal(l);
    k = 1;
    for(int i = 0; i < n; i++)
    {
        cout << "Tim-" << k << " ";
        update(l,k);
        ++k;
    }
    // sorting(l);
    traversal(l);
}