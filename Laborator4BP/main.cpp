#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int inf;
    Node *left;
    Node *right;
};

Node *creare();
void RSD(Node *root);
bool isEmpty(Node *root);
Node *newNode(int data);
int sumaTerminale(Node *root);
int suma2Suc(Node *root);
Node *newTree(Node *root);
bool par(int);
int sumaCifre(int);

int main()
{
    Node *root = creare();
    RSD(root);
    int sum = sumaTerminale(root);
    if (sum == 0)
    {
        cout << "\nIn arbore nu sunt noduri terminale cu valori pare" << endl;
    }
    else
    {
        cout << "\nSuma nodurilor terminale cu valori pare: " << sum << endl;
    }
    int sum1 = suma2Suc(root);
    if (sum1 == 0)
    {
        cout << "Nu exista noduri cu exact 2 descendenti si valori pozitive" << endl;
    }
    else
    {
        cout << "Suma nodurilor cu exact 2 descendenti si cu valori pozitive: " << sum1 << endl;
    }
    Node *newRoot = newTree(root);
    cout << "Parcurgerea RSD a arborelui nou creat: " << endl;
    RSD(newRoot);
    return 0;
}

Node *creare()
{
    int nr;
    cout << "Valoarea: ";
    cin >> nr;
    if (nr != 0)
    {
        Node *newElement = newNode(nr);
        cout << "Introduceti descendentul stang al nodului " << newElement->inf << " :" << endl;
        newElement->left = creare();
        cout << "Introduceti descendentul drept al nodului " << newElement->inf << " :" << endl;
        newElement->right = creare();
        return newElement;
    }
}

void RSD(Node *root)
{
    if (isEmpty(root))
    {
        return;
    }
    else
    {
        cout << root->inf << " ";
        RSD(root->left);
        RSD(root->right);
    }
}

bool isEmpty(Node *root)
{
    return root == NULL;
}

Node *newNode(int data)
{
    Node *newElement = (Node *)malloc(sizeof(Node));
    newElement->inf = data;
    newElement->left = NULL;
    newElement->right = NULL;
}

bool par(int nr)
{
    return nr % 2 == 0;
}

int sumaCifre(int nr)
{
    int s = 0;
    while (nr != 0)
    {
        s = s + nr % 10;
        nr = nr / 10;
    }
    return s;
}

int sumaTerminale(Node *root)
{
    if (isEmpty(root))
        return 0;
    if (root->left == NULL && root->right == NULL && par(root->inf))
    {
        return root->inf;
    }
    return sumaTerminale(root->left) + sumaTerminale(root->right);
}

int suma2Suc(Node *root)
{
    if (isEmpty(root))
        return 0;
    if (root->left != NULL && root->right != NULL && root->inf > 0)
    {
        return root->inf;
    }
    return sumaTerminale(root->left) + sumaTerminale(root->right);
}

Node *newTree(Node *root)
{
    if (isEmpty(root))
    {
        return NULL;
    }
    if (par(root->inf))
    {
        root->inf = sumaCifre(root->inf);
    }
    else if (!par(root->inf))
    {
        root->inf = -root->inf;
    }
    Node *newRoot = newNode(root->inf);
    newRoot->left = newTree(root->left);
    newRoot->right = newTree(root->right);
    return newRoot;
}
