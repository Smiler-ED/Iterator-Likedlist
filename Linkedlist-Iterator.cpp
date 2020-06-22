#include <iostream>

using namespace std;

//CLASE NODO INICIO

template <typename T>

class Node
{
	int dato;
	Node *siguiente;
public:
	Node(int dato_a);

	int getDato();
	void setDato(int dato_a);

	Node* getSiguiente();
	void setSiguiente(Node *siguiente_a);

};

Node::Node(int dato_a){
	dato = dato_a;
	siguiente = nullptr;
}


int Node::getDato()
{
    return dato;
}

void Node::setDato(int dato_a)
{
    dato = dato_a;
}

Node* Node::getSiguiente()
{
    return siguiente;
}

void Node::setSiguiente(Node* siguiente_a)
{
    siguiente = siguiente_a;
}

//CLASE NODO FIN



//CLASE LIKEDLIST INICIO
class LinkedList
{
	Node *head;
	int size;
public:
	LinkedList();
	LinkedList(int nElem);

	void insert(int nElem);
	void remove(int index);
	void print();

};
LinkedList::LinkedList(){
	head = nullptr;
	size = 0;
}

LinkedList::LinkedList(int nElem){
	head = new Node(nElem);
	size = 1;
}

void LinkedList::insert(int nElem){
	if(!size)
		head = new Node(nElem);
	else{
		Node *auxiliar = head;
		Node *previous = nullptr;

		while(auxiliar != nullptr and auxiliar->getDato() <= nElem){
			previous = auxiliar;
			auxiliar = auxiliar->getSiguiente();
		}

		Node *temp = new Node(nElem);
		if (previous == nullptr){
			temp->setSiguiente(head);
			head = temp;
		}
		else{
			temp->setSiguiente(auxiliar);
			previous->setSiguiente(temp);
		}
	}
	size++;
}

void LinkedList::remove(int index){
	Node *auxiliar = head;
	if(index != 0){
		for (int i = 0; i < index - 1; i++){
            auxiliar = auxiliar->getSiguiente();
        }
        Node *nodeRem = auxiliar->getSiguiente();
        auxiliar->setSiguiente(nodeRem->getSiguiente());
        auxiliar = nodeRem;
	}
	else
		head = head->getSiguiente();
	delete auxiliar;
	size--;
}

void LinkedList::print(){
	Node *cursor = head;
	cout << "{";
	for(int i=0; i<=size-1; i++){
		cout << cursor->getDato() << " ";
		cursor = cursor->getSiguiente();
	}
	cout << "}"<< endl;
}

//CLASE LIKEDLIST FIN
int main()
{
	/* code */
	LinkedList* LLlist = new LinkedList(7); //Inicia una nueva lista con 7

	cout << "Iniciando la lista con [7]\nA = ";
	LLlist->print();

	cout << "Insertar (5) en la lista [7] \nA = ";
	LLlist->insert(5);
	LLlist->print();

	cout << "Insertar (2) en la lista [5 7]\nA = ";
	LLlist->insert(2);
	LLlist->print();

	cout << "Remueve un valor segun el indice =1 \n";
	LLlist->remove(1);
	cout << "A = ";
	LLlist->print();

	return 0;
}
