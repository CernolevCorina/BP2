#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace std;

struct participant
{
    int nr;
    char tara[20];
};

struct nod
{
    participant inf;
    nod *urm;
};

void creareListaPart(nod *x, nod *&sant1)
{
    ifstream readFile;
    readFile.open("concurenti.txt", ios::in);
    if (!readFile)
    {
        cout << "No such file";
    }
    else
    {
        while (!readFile.eof())
        {

            x = sant1;
            readFile >> x->inf.nr >> x->inf.tara;

            sant1 = new nod();
            sant1->urm = x;

            cout << "Numarul: " << x->inf.nr;
            cout << "\nTara: " << x->inf.tara << endl;
        }
    }
    readFile.close();
};

int Back()
{
    nod *element = sant1 ->urm;
    while (element != sant2)
    {

    }
}

nod *sant1 = new nod();
nod *sant2 = new nod();
nod *stiva = new nod();
nod *x = new nod();
int main()
{
    sant1->urm = sant2;

    creareListaPart(x, sant1);


    return 0;
}
