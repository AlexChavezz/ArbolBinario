#include <iostream>
using namespace std;

class cArbol {
public:
	cArbol();
	cArbol* crearArbol(cArbol* root, int i);
	void imprimirArbol(cArbol*);
	cArbol* izq,* der;
	int dato;
};

cArbol::cArbol() {
	izq = der = NULL;
	dato = 0;
}
cArbol* cArbol::crearArbol(cArbol* root, int i) {
	if (root == NULL) {
		root = new cArbol();
		root->dato = i;
	}
	else if (i < root->dato) {
		// recursividad 
		root->izq = crearArbol(root->izq, i);
	}
	else if (i > root->dato) {
		root->der = crearArbol(root->der, i);
	}
	return root;
}


void cArbol::imprimirArbol(cArbol* root) {
	cArbol* aux = root;
	if (aux != NULL) {
		/*//inorden
		imprimirArbol(aux->izq);
		cout << aux->dato << " -> ";
		imprimirArbol(aux->der);*/
		//posorden
		/*imprimirArbol(aux->izq);
		imprimirArbol(aux->der);
		cout << aux->dato << " -> ";
		cout << "Pre orden" << endl;*/
		cout << aux->dato << " -> ";
		imprimirArbol(aux->izq);
		imprimirArbol(aux->der);
	}
}
int main() {
	cArbol* root = NULL;
	cArbol* obj = new cArbol();
	int valor, size;
	cout << "Cuantos valores quieres en tu lista ?"<<endl;
	cout << ": ";
	cin >> size;
	for (int i = 0; i < size; i++) {
		cout << "Dame un valor para ingresar" << endl;
		cin >> valor;
		root = obj->crearArbol(root, valor);
	}/*
	root = obj->crearArbol(root, 900);
	root = obj->crearArbol(root, 300);
	root = obj->crearArbol(root, 500);
	root = obj->crearArbol(root, 1200);
	root = obj->crearArbol(root, 956);
	root = obj->crearArbol(root, 45);*/
	obj->imprimirArbol(root);
	return 0;
}

// duinamico cuantos numeros quieres en tu lista y dame los valores para el lunes para el viernes 