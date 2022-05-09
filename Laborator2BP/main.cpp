#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nod
{
    double inf;
    Nod *urm;
};

Nod* newNod(double val) {
    Nod* newElement = (Nod*) malloc(sizeof(struct Nod));
    newElement->inf=val;
    newElement->urm=NULL;
    return newElement;
}

bool esteVida(Nod* lista) {
    return lista==NULL;
}

void adaugaNod(Nod *& lista, double n)
{
    Nod* newElement = newNod(n);
    if (esteVida(lista)) {
        lista=newElement;
    }
    else {
        Nod* l = lista;
        while(!esteVida(l->urm)) {
            l=l->urm;
        }
        l->urm=newElement;
    }
}

double average(Nod* lista)
{
    double sum = 0;
    int nr = 0;
    while(!esteVida(lista)) {
            if (lista -> inf > 0)
                {
                    sum = sum + lista->inf;
                    nr = nr + 1;
                }
            lista = lista ->urm;
    }
    return (sum/nr);
}

void afisareInvers (Nod* lista)
{
    Nod* l = lista;
    if (esteVida(l)) {
        return;
    }
    else {
        afisareInvers(l->urm);
        cout << l -> inf << " ";
    }
}

int main()
{
    Nod* lista = NULL;
    double n;
    cout<<"n=";
    cin>>n;
    while(n!=0) {
        adaugaNod(lista, n);
        cout<<"n=";
        cin>>n;
    }
    afisareInvers(lista);
    cout << "\n Media numerelor pozitive introduse este : " << average(lista);

    return 0;
}
