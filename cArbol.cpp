#include <iostream>
using namespace std;

class cArbol
{
public:
	cArbol();
	cArbol *crearArbol(cArbol *, int);
	cArbol *izq, *der;
	int dato;
	// -> Metodos para imprimir de diferentes maneras
	void imprimirPosOrden(cArbol *);
	void imprimirPreOrden(cArbol *);
	void imprimirInOrden(cArbol *);
};

cArbol::cArbol()
{
	izq = der = NULL;
	dato = 0;
}
cArbol *cArbol::crearArbol(cArbol *root, int i)
{
	if (root == NULL)
	{
		root = new cArbol();
		root->dato = i;
	}
	else if (i < root->dato)
	{
		// recursividad
		root->izq = crearArbol(root->izq, i);
	}
	else if (i > root->dato)
	{
		root->der = crearArbol(root->der, i);
	}
	return root;
}
void cArbol::imprimirPreOrden(cArbol *root)
{
	cArbol *aux;
	aux = root;
	if (aux != NULL)
	{
		cout << aux->dato << " -> ";
		imprimirPreOrden(aux->izq);
		imprimirPreOrden(aux->der);
	}
}
void cArbol::imprimirPosOrden(cArbol *root)
{
	cArbol *aux;
	aux = root;
	if (aux != NULL)
	{
		imprimirPosOrden(aux->izq);
		imprimirPosOrden(aux->der);
		cout << aux->dato << " -> ";
	}
}
void cArbol::imprimirInOrden(cArbol *root)
{
	cArbol *aux;
	aux = root;
	if (aux != NULL)
	{
		imprimirInOrden(aux->izq);
		cout << aux->dato << " -> ";
		imprimirInOrden(aux->der);
	}
}
int main()
{
	cArbol *root = NULL;
	cArbol *obj = new cArbol();
	int valor, size;
	cout << "Cuantos valores quieres en tu lista ?" << endl;
	cout << ": ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "Dame un valor para ingresar" << endl;
		cin >> valor;
		root = obj->crearArbol(root, valor);
	}
	int opc;
	cout << "Que quieres hacer ahora?" << endl;
	do
	{

		cout << "\n(1) In Orden\n(2) Para Pre Orden\n(3) Pos Orden\n(4) para salir\n: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			obj->imprimirInOrden(root);
			break;
		case 2:
			obj->imprimirPreOrden(root);
			break;
		case 3:
			obj->imprimirPosOrden(root);
			break;
			case 4:
			break;
		default:
			break;
		}

	} while (opc != 4);

	return 0;
}