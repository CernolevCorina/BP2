#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <cstdio>

#define MAXLEN 25

using namespace std;

struct Node
{
    char nume[MAXLEN];
    Node *next;
};

Node *newNode(char name[MAXLEN])
{
    Node *newElement = (Node *)malloc(sizeof(struct Node));
    strcpy(newElement->nume, name);
    newElement->next = NULL;
    return newElement;
}

bool isEmpty(Node *lista)
{
    return lista == NULL;
}

void inserare(Node *&lista, char nume[MAXLEN])
{
    Node *newElement = newNode(nume);
    if (isEmpty(lista))
    {
        lista = newElement;
        lista->next = lista;
    }
    else
    {
        Node *l = lista;
        while (l->next != lista)
        {
            l = l->next;
        }
        l->next = newElement;
        newElement->next = lista;
    }
}

void afisareLista(Node *lista)
{
    Node *l = lista;
    if (isEmpty(l))
    {
        cout << "Lista este vida" << endl;
        return;
    }
    else
    {
        while (l->next != lista)
        {
            cout << l->nume << " ";
            l = l->next;
        }
        cout << l->nume << endl;
    }
}

void sterge(Node *&lista, char nume[MAXLEN])
{
    if (isEmpty(lista))
    {
        cout << "Lista este vida. Nu putem efectua stergerea" << endl;
        return;
    }
    if (strcmp(lista->nume, nume) == 0 && lista->next == lista)
    {
        free(lista);
        lista = NULL;
        return;
    }
    Node *ultim = lista;
    Node *nod;
    if (strcmp(lista->nume, nume) == 0)
    {
        while (ultim->next != lista)
        {
            ultim = ultim->next;
        }
        ultim->next = lista->next;
        free(lista);
        lista = ultim->next;
        return;
    }
    while (ultim->next != lista && strcmp(ultim->next->nume, nume) != 0)
    {
        ultim = ultim->next;
    }
    if (strcmp(ultim->next->nume, nume) == 0)
    {
        nod = ultim->next;
        ultim->next = nod->next;
        free(nod);
    }
    else
    {
        cout << "Nu exista un astfel de nume pentru stergere" << endl;
    }
}

void joc(Node *&lista, int &n)
{
    if (isEmpty(lista) || lista->next == lista)
    {
        cout << "Jocul nu poate incepe. Prea putini copii" << endl;
        return;
    }
    do
    {
        int x, z;
        Node *l = lista;
        cout << "In joc sunt " << n << " copii" << endl;
        afisareLista(lista);
        cout << "Va incepe copilul cu numarul de ordine: ";
        cin >> x;
        int i = 1;
        while (i < x)
        {
            i++;
            l = l->next;
        }
        cout << "Va incepe: " << l->nume << endl;
        cout << "Numaram pana la: ";
        cin >> z;
        int j = 1;
        while (j < z)
        {
            j++;
            cout << l->nume << " ";
            l = l->next;
        }
        cout << "Din joc a iesit: " << l->nume << endl;
        sterge(lista, l->nume);
        n--;
    } while (lista->next != lista);
    cout << "Jocul a fost castigat de: " << lista->nume;
}

int main()
{
    Node *lista = NULL;
    int n;
    char nume[MAXLEN];
    cout << "Numarul de copii in joc: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Numele copilului " << i + 1 << ": ";
        scanf("%s", nume);
        inserare(lista, nume);
    }
    joc(lista, n);
    return 0;
}
