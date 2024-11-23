#include "Lista.h"

//CONSTRUCTORES
Lista::Lista():Root(nullptr), tipoLista(Default) {}

Lista::~Lista()
{
	Nodo* actual = Root;
	
	if (Root == nullptr) {
		return;
	}

	switch (tipoLista) {
	case Lista_Lineal:
	case Lista_D_Lineal:
		while (actual != nullptr) {
			Nodo* siguiente = actual->GetNext();
			delete actual;
			actual = siguiente;
		}

		break;
	case Lista_Circular:
	case Lista_D_Circular:
		do {
			Nodo* siguiente = actual->GetNext();
			delete actual;
			actual = siguiente;
		} while (actual != Root);

		break;
	default:
		break;
	}

	Root = nullptr;
}

//METODOS
void Lista::SetRoot(Nodo* _root)
{
	this -> Root = _root;
}

void Lista::SetRoot(int _root)
{
	Nodo* newRoot = new Nodo(_root, Root, nullptr);
	Root = newRoot;
}

Nodo* Lista::GetRoot()
{
	return Root;
}

void Lista::Swap(Nodo* izquierdo, Nodo* derecho)
{
	int valueIzq = izquierdo->GetValue();
	int valueDer = derecho->GetValue();
	izquierdo->SetValue(valueDer);
	derecho->SetValue(valueIzq);
}

void Lista::GetValue(int _position, int index)
{
	Nodo* temp = Root;

	if (Root == nullptr) {
		std::cout << "La Lista esta Vacia" << std::endl;
		system("pause");
		return;
	}

	if (_position > index-1) {
		std::cout << "ERROR: Posicion Elegida esta Fuera de Rango" << std::endl;
		system("pause");
		return;
	}

	if (_position < 0) {
		std::cout << "ERROR: Introduzca un Index Valido" << std::endl;
		system("pause");
		return;
	}

	for (int i = 0; i < _position; i++) {
		temp = temp->GetNext();
	}

	if (temp != nullptr) {
		std::cout << "El Valor del Nodo " << _position << " es " << temp->GetValue() << std::endl;
	}
	system("pause");
}

void Lista::Push(int _n)
{
	Nodo* newNodo = new Nodo(_n, nullptr, nullptr);
	Nodo* temp = Root; 

	switch (tipoLista) {
	case Lista_Lineal:
		if (Root == nullptr) {
			Root = newNodo;
		} else {
			while (temp->GetNext() != nullptr) { //Pasa por cada nodo hasta que detecta uno vacio/nulo
				temp = temp->GetNext();
			}
			temp->SetNext(newNodo); //Escribe el newNodo con SetNext
		}

		break;
	case Lista_Circular:
		if (Root == nullptr) {
			Root = newNodo;
			newNodo->SetNext(Root); //Apunta a si mismo
		} else {
			while (temp->GetNext() != Root) { //Pasa por cada nodo hasta que detecta Root ("Inicio de lista")
				temp = temp->GetNext();
			}
			temp->SetNext(newNodo); //Sets el newNodo
			newNodo->SetNext(Root); //Cambiamos el newNodo para que apunte a Root
		}

		break;
	case Lista_D_Lineal:
		if (Root == nullptr) {
			Root = newNodo;
		} else {
			while (temp->GetNext() != nullptr) { //Pasa por cada nodo hasta que detecta uno vacio/nulo
				temp = temp->GetNext();
			}
			temp->SetNext(newNodo); //Escribe el newNodo con SetNext
			newNodo->SetLast(temp); //Hacemos que newNodo apunte al anterior
		}

		break;
	case Lista_D_Circular:
		if (Root == nullptr) {
			Root = newNodo;
			newNodo->SetNext(Root);
			newNodo->SetLast(Root); //Apuntan a si mismo
		} else {
			while (temp->GetNext() != Root) { //Pasa por cada nodo hasta que detecta Root ("Inicio de lista")
				temp = temp->GetNext();
			}
			temp->SetNext(newNodo); //Ultimo nodo apunta a newNodo
			newNodo->SetLast(temp); //newNodo apunta al nodo anterior
			newNodo->SetNext(Root); //newNodo apunta al siguiente (Root)
			Root->SetLast(newNodo); //Root apunta a newNodo de regreso
		}

		break;
	default:
		std::cout << "ERROR: No se Eligio un Tipo de Lista" << std::endl;
		break;
	}
}

void Lista::ReadList()
{
	Nodo* temp = Root;

	if (Root == nullptr) {
		std::cout << "La Lista esta Vacia." << std::endl;
		system("pause");
		return;
	}

	switch (tipoLista) {
	case Lista_Lineal:
		while (temp != nullptr) { //Continuara hasta que detecte el final de la lista
			std::cout << temp->GetValue() << ", ";
			temp = temp->GetNext();
		}
		std::cout << "NO existen mas datos..." << std::endl;
		system("pause");

		break;
	case Lista_Circular:
		do {
			std::cout << temp->GetValue() << ", ";
			temp = temp->GetNext();
		} while (temp != Root); //Continuara hasta que detecte que llegamos a Root (Inicio de Lista)
		std::cout << "No Existen mas Datos" << std::endl;
		system("pause");

		break;
	case Lista_D_Lineal:
		while (temp != nullptr) { //Continuara hasta que detecte el final de la lista
			std::cout << temp->GetValue() << ", ";
			temp = temp->GetNext();
		}
		std::cout << "NO existen mas datos..." << std::endl;
		system("pause");

		break;
	case Lista_D_Circular:
		do {
			std::cout << temp->GetValue() << ", ";
			temp = temp->GetNext();
		} while (temp != Root); //Continuara hasta que detecte que llegamos a Root (Inicio de Lista)
		std::cout << "NO existen mas datos..." << std::endl;
		system("pause");

		break;
	default:
		std::cout << "ERROR: No se Eligio un Tipo de Lista" << std::endl;;
		break;
	}
}

void Lista::ClearList()
{
	this->~Lista(); //Llamamos al destructor
	std::cout << "Se ha Limpiado la Lista" << std::endl;
	system("pause");
}

void Lista::Pop(int index)
{
	if (Root == nullptr) {
		std::cout << "La Lista esta Vacia" << std::endl;
		system("pause");
		return;
	}

	Nodo* temp = Root;
	Nodo* last = nullptr;
	int valor;

	switch (tipoLista) {
	case Lista_Lineal:
		if (index == 1) {
			valor = Root->GetValue();
			std::cout << "El Ultimo Nodo Vale " << valor << std::endl;
			this->~Lista();
			std::cout << "Se Elimino el Unico Nodo de la Lista" << std::endl;
			system("pause");
			return;
		}
		if (Root->GetNext() == nullptr) { //Si el siguiente nodo es nulo...
			valor = Root->GetValue(); //Obtiene el valor del ultimo nodo
			std::cout << "El Ultimo Nodo Vale " << valor << std::endl;
			delete Root;
			Root = nullptr;
			system("pause");
			return;
		} else { //Si hay mas de un nodo
			while (temp->GetNext() != nullptr) { //Mientras que el siguiente nudo NO sea nulo...
				last = temp;
				temp = temp->GetNext();
			}
			valor = temp->GetValue();
			std::cout << "El Ultimo Nodo Vale " << valor << std::endl;
			delete temp;
			last->SetNext(nullptr);
			system("pause");
		}

		break;
	case Lista_Circular:
		if (index == 1) {
			valor = Root->GetValue();
			std::cout << "El Ultimo Nodo Vale " << valor << std::endl;
			this->~Lista();
			std::cout << "Se Elimino el Unico Nodo de la Lista" << std::endl;
			system("pause");
			return;
		}
		if (Root->GetNext() == Root) {
			valor = Root->GetValue();
			std::cout << "El Ultimo Nodo Vale " << valor << std::endl;
			delete Root;
			Root = nullptr;
			system("pause");
			return;
		} else {
			while (temp->GetNext() != Root) {
				last = temp;
				temp = temp->GetNext();
			}
			valor = temp->GetValue();
			std::cout << "El Ultimo Nodo Vale " << valor << std::endl;
			delete temp;
			last->SetNext(Root);
			system("pause");
		}

		break;
	case Lista_D_Lineal:
		if (index == 1) {
			valor = Root->GetValue();
			std::cout << "El Ultimo Nodo Vale " << valor << std::endl;
			this->~Lista();
			std::cout << "Se Elimino el Unico Nodo de la Lista" << std::endl;
			system("pause");
			return;
		}
		if (Root->GetNext() == nullptr) {
			valor = Root->GetValue();
			std::cout << "El Ultimo Nodo Vale " << valor << std::endl;
			delete Root;
			Root = nullptr;
			system("pause");
			return;
		} else {
			while (temp->GetNext() != nullptr) {
				temp = temp->GetNext();
			}
			valor = temp->GetValue();
			std::cout << "El Ultimo Nodo Vale " << valor << std::endl;
			temp->GetLast()->SetNext(nullptr);
			delete temp;
			system("pause");
		}

		break;
	case Lista_D_Circular:
		if (index == 1) {
			valor = Root->GetValue();
			std::cout << "El Ultimo Nodo Vale " << valor << std::endl;
			this->~Lista();
			std::cout << "Se Elimino el Unico Nodo de la Lista" << std::endl;
			system("pause");
			return;
		}
		if (Root->GetNext() == Root) {
			valor = Root->GetValue();
			std::cout << "El Ultimo Nodo Vale " << valor << std::endl;
			delete Root;
			Root = nullptr;
			system("pause");
			return;
		} else {
			while (temp->GetNext() != Root) {
				temp = temp->GetNext();
			}
			valor = temp->GetValue();
			std::cout << "El Ultimo Nodo Vale " << valor << std::endl;
			temp->GetLast()->SetNext(Root);
			Root->SetLast(temp->GetLast());
			delete temp;
			system("pause");
		}

		break;
	default:
		std::cout << "ERROR: No se Eligio un Tipo de Lista" << std::endl;
		break;
	}
}

void Lista::Queue(int index)
{
	if (Root == nullptr) {
		std::cout << "La Lista esta Vacia" << std::endl;
		system("pause");
		return;
	}

	Nodo* temp = Root;
	Nodo* last = nullptr;
	int valor;

	switch (tipoLista) {
	case Lista_Lineal:
		if (index == 1) {
			valor = Root->GetValue();
			std::cout << "El Primer Nodo Vale " << valor << std::endl;
			this->~Lista(); //Llamamos al destructor
			std::cout << "Se Elimino el Unico Nodo de la Lista" << std::endl;
			system("pause");
			return;
		} else {
			temp = Root;
			valor = temp->GetValue();
			std::cout << "El Primer Nodo Vale " << valor << std::endl;
			Root = Root->GetNext();
			delete temp;
			std::cout << "Eliminaste el Primer Nodo de la Lista" << std::endl;
			system("pause");
		}

		break;
	case Lista_Circular:
		if (index == 1) {
			valor = Root->GetValue();
			std::cout << "El Primer Nodo Vale " << valor << std::endl;
			this->~Lista(); //Llamamos al destructor
			std::cout << "Se Elimino el Unico Nodo de la Lista" << std::endl;
			system("pause");
			return;
		} else {
			valor = Root->GetValue();
			std::cout << "El Primer Nodo Vale " << valor << std::endl;
			last = Root;
			while (last->GetNext() != Root) {
				last = last->GetNext();
			}
			last->SetNext(Root->GetNext());
			temp = Root;
			Root = Root->GetNext();
			delete temp;
			std::cout << "Eliminaste el Primer Nodo de la Lista" << std::endl;
			system("pause");
		}

		break;
	case Lista_D_Lineal:
		if (index == 1) {
			valor = Root->GetValue();
			std::cout << "El Primer Nodo Vale " << valor << std::endl;
			this->~Lista(); //Llamamos al destructor
			std::cout << "Se Elimino el Unico Nodo de la Lista" << std::endl;
			system("pause");
			return;
		} else {
			valor = Root->GetValue();
			std::cout << "El Primer Nodo Vale " << valor << std::endl;
			Root->GetNext()->SetLast(nullptr);
			temp = Root;
			Root = Root->GetNext();
			delete temp;
			std::cout << "Eliminaste el Primer Nodo de la Lista" << std::endl;
			system("pause");
		}

		break;
	case Lista_D_Circular:
		if (index == 1) {
			valor = Root->GetValue();
			std::cout << "El Primer Nodo Vale " << valor << std::endl;
			this->~Lista(); //Llamamos al destructor
			std::cout << "Se Elimino el Unico Nodo de la Lista" << std::endl;
			system("pause");
			return;
		} else {
			valor = Root->GetValue();
			std::cout << "El Primer Nodo Vale " << valor << std::endl;
			last = Root;
			while (last->GetNext() != Root) {
				last = last->GetNext();
			}
			last->SetNext(Root->GetNext());
			Root->GetNext()->SetLast(last);
			Root = Root->GetNext();
			delete temp;
			std::cout << "Eliminaste el Primer Nodo de la Lista" << std::endl;
			system("pause");
		}

		break;
	default:
		std::cout << "ERROR: No se Eligio un Tipo de Lista" << std::endl;
		break;
	}
}

void Lista::Erase(int _position, int index)
{
	if (Root == nullptr) {
		std::cout << "La Lista esta Vacia" << std::endl;
		system("pause");
		return;
	}

	Nodo* temp = Root; //Puntero Temporal
	Nodo* last = nullptr;

	int contador = 0;

	switch (tipoLista) {
	case Lista_Lineal:
		if (_position > index-1) {
			std::cout << "ERROR: Posicion Fuera de Rango" << std::endl;
			system("pause");
			return;
		}
		if (_position < 0) {
			std::cout << "ERROR: Introduzca un Index Valido" << std::endl;
			system("pause");
			return;
		}
		if (index == 1) {
			this->~Lista();
			std::cout << "Se Elimino el Unico Nodo de la Lista" << std::endl;
			system("pause");
			return;
		}
		if (_position == 0) {
			Root = Root->GetNext();
			std::cout << "El Nodo se ha Eliminado Exitosamente (0)" << std::endl;
			system("pause");
			delete temp;
			return;
		}
		for (int i = 0; temp != nullptr && i < _position; i++) {
			last = temp;
			temp = temp->GetNext();
		}
		std::cout << "El Nodo se ha Eliminado Exitosamente" << std::endl;
		system("pause");
		last->SetNext(temp->GetNext());
		delete temp;

		break;
	case Lista_Circular:
		if (_position > index-1) {
			std::cout << "ERROR: Posicion Fuera de Rango" << std::endl;
			system("pause");
			return;
		}
		if (_position < 0) {
			std::cout << "ERROR: Introduzca un Index Valido" << std::endl;
			system("pause");
			return;
		}
		if (index == 1) {
			this->~Lista();
			std::cout << "Se Elimino el Unico Nodo de la Lista" << std::endl;
			system("pause");
			return;
		}
		if (_position == 0) {
			Nodo* ultimo = Root;
			for (; ultimo->GetNext() != Root; ultimo = ultimo->GetNext()); //For extraño que recorre nodos extrañamente
			temp = Root;
			Root = Root->GetNext();
			ultimo->SetNext(Root);
			delete temp;
			std::cout << "El Nodo se ha Eliminado Exitosamente (0)" << std::endl;
			system("pause");
			return;
		}
		for (contador = 0; temp->GetNext() != Root && contador < _position; contador++) {
			last = temp;
			temp = temp->GetNext();
		}
		std::cout << "El Nodo se ha Eliminado Exitosamente" << std::endl;
		last->SetNext(temp->GetNext());
		delete temp;
		system("pause");

		break;
	case Lista_D_Lineal:
		if (_position > index-1) {
			std::cout << "ERROR: Posicion Fuera de Rango" << std::endl;
			system("pause");
			return;
		}
		if (_position < 0) {
			std::cout << "ERROR: Introduzca un Index Valido" << std::endl;
			system("pause");
			return;
		}
		if (index == 1) {
			this->~Lista();
			std::cout << "Se Elimino el Unico Nodo de la Lista" << std::endl;
			system("pause");
			return;
		}
		if (_position == 0) {
			Root = Root->GetNext();
			if (Root != nullptr) {
				Root->SetLast(nullptr);
			}
			delete temp;
			std::cout << "El Nodo se ha Eliminado Exitosamente (0)" << std::endl;
			system("pause");
			return;
		}
		for (int i = 0; temp != nullptr && i < _position; i++) {
			last = temp;
			temp = temp->GetNext();
		}
		last->SetNext(temp->GetNext());
		if (temp->GetNext() != nullptr) {
			temp->GetNext()->SetLast(last);
		}
		delete temp;
		std::cout << "El Nodo se ha Eliminado Exitosamente" << std::endl;
		system("pause");

		break;
	case Lista_D_Circular:
		if (_position > index-1) {
			std::cout << "ERROR: Posicion Fuera de Rango" << std::endl;
			system("pause");
			return;
		}
		if (_position < 0) {
			std::cout << "ERROR: Introduzca un Index Valido" << std::endl;
			system("pause");
			return;
		}
		if (index == 1) {
			this->~Lista();
			std::cout << "Se Elimino el Unico Nodo de la Lista" << std::endl;
			system("pause");
			return;
		}
		if (_position == 0) {
			Nodo* ultimo = Root;
			for (; ultimo->GetNext() != Root; ultimo = ultimo->GetNext()); //For extraño que recorre nodos extrañamente
			Root = Root->GetNext();
			Root->SetLast(ultimo);
			ultimo->SetNext(Root);
			delete temp;
			std::cout << "El Nodo se ha Eliminado Exitosamente (0)" << std::endl;
			system("pause");
			return;
		}
		for (contador = 0; temp->GetNext() != Root && contador < _position; contador++) {
			last = temp;
			temp = temp->GetNext();
		}
		last->SetNext(temp->GetNext());
		temp->GetNext()->SetLast(last);
		delete temp;
		std::cout << "El Nodo se ha Eliminado Exitosamente" << std::endl;
		system("pause");

		break;
	default:
		std::cout << "ERROR: No se Eligio un Tipo de Lista" << std::endl;;
		break;
	}
}

void Lista::SearchOnList()
{
	if (Root == nullptr) {
		std::cout << "La Lista esta Vacia" << std::endl;
		system("pause");
		return;
	}

	Nodo* temp = Root;
	char opt;
	int valor;

	while (true) {
		system("CLS");
		std::cout << "Abriendo Simulacion de Nodos..." << std::endl;
		valor = Root->GetValue();
		std::cout << "El Nodo Actual Vale " << valor << std::endl;
		std::cout << "Escriba 'a' para Pasar al Nodo Anterior. Escriba 'd' para Pasar al Nodo Siguiente. Escriba 'x' para Salir de la Simulacion" << std::endl;
		std::cin >> opt;

		switch (opt) {
		case 'a':
			Root = temp->GetLast();
			valor = Root->GetValue();
			std::cout << "El Nodo Anterior Vale " << valor << std::endl;
			temp = Root;
			system("pause");

			break;
		case 'd':
			Root = temp->GetNext();
			valor = Root->GetValue();
			std::cout << "El Nodo Siguiente Vale " << valor << std::endl;
			temp = Root;
			system("pause");

			break;
		case 'x':
			std::cout << "Cerrando Simulacion de Nodos..." << std::endl;
			system("pause");
			return;

			break;
		default:
			std::cout << "Entrada Invalida. Solo se Aceptan los Valores: a, d, x" << std::endl;
			system("pause");
			break;
		}
	}

}

void Lista::FillList(int min, int max, int size)
{
	int valor = 0;
	srand((unsigned)time(NULL)); //Toma el Tiempo del Sistema
	for (int i = 0; i < size; i++) {
		valor = rand() % (max - min + 1) + min;
		Push(valor);
	}

	std::cout << "Se Ha Creado la Lista Aleatoria Correctamente" << std::endl;
	system("pause");
	return;
}

void Lista::BubbleSort()
{
	//Advertencia si solo hay un Nodo en la Lista
	if (Root->GetNext() == nullptr) {
		std::cout << "Solo Existe un Nodo en la Lista. No es posible Ordenar." << std::endl; system("pause");
		return;
	}

	//Variables Temporales
	Nodo* temp = Root; Nodo* nextNode = temp->GetNext();

	switch (tipoLista) {
	//Caso de Listas Lineales
	case Lista_Lineal:
	case Lista_D_Lineal:
		//Ciclo que se detendra cuando el siguiente nodo sea Nulo
		while (nextNode != nullptr) {
			//Si se cumple la condicion, intercambia los valores con Swap
			if (temp->GetValue() > nextNode->GetValue()) {
				Swap(temp, nextNode);
			}
			//Cambia las Variables Temporales a los Siguientes Nodos
			temp = nextNode;
			nextNode = nextNode->GetNext();
		}

		break;

	//Caso de Listas Circulares
	case Lista_Circular:
	case Lista_D_Circular:
		//Ciclo que se detendra cuando el siguiente nodo sea Root
		while (nextNode != Root) {
			//Si se cumple la condicion, intercambia los valores
			if (temp->GetValue() > nextNode->GetValue()) {
				Swap(temp, nextNode);
			}
			//Cambia las Variables Temporales a los Siguientes Nodos
			temp = nextNode;
			nextNode = nextNode->GetNext();
		}

		break;
	default:
		std::cout << "ERROR: No se Eligio un Tipo de Lista" << std::endl;
		system("pause");
		break;
	}
}

void Lista::InsertionSort()
{
	//Advertencia si solo hay un Nodo en la Lista
	if (Root->GetNext() == nullptr) {
		std::cout << "Solo Existe un Nodo en la Lista. No es posible Ordenar." << std::endl; system("pause");
		return;
	}

	//Variables Temporales
	Nodo* temp = Root; Nodo* nextNode = Root->GetNext();

	switch (tipoLista){
	//Caso de Listas Lineales
	case Lista_Lineal:
	case Lista_D_Lineal:
		//Ciclo que se detendra cuando el nextNode sea Nulo
		while (nextNode != nullptr) {
			temp = Root; //temp se iguala a Root en cada iteracion para poder compararlo con los demas Nodos
			// Ciclo que se detendra hasta que detecte que temp sea igual a nextNode
			while (temp != nextNode) {
				if (temp->GetValue() > nextNode->GetValue()) {
					Swap(temp, nextNode);
				}
				temp = temp->GetNext(); //Se mueve al siguiente Nodo
			}
			nextNode = nextNode->GetNext(); //Se mueve al siguiente Nodo para empezar otra iteracion de comparaciones
		}

		break;

	//Caso de Listas Circulares
	case Lista_Circular:
	case Lista_D_Circular:

		//Ciclo que se detendra cuando el nextNode sea Root
		do {
			temp = Root;
			while (temp != nextNode) {
				if (temp->GetValue() > nextNode->GetValue()) {
					Swap(temp, nextNode);
				}
				temp = temp->GetNext();
			}
			nextNode = nextNode->GetNext();
		} while (nextNode != Root);

		break;
	default:
		std::cout << "ERROR: No se Eligio un Tipo de Lista" << std::endl;
		system("pause");
		break;
	}
}

void Lista::SelectionSort()
{
	//Advertencia si solo hay un Nodo en la Lista
	if (Root->GetNext() == nullptr) {
		std::cout << "Solo Existe un Nodo en la Lista. No es posible Ordenar." << std::endl; system("pause");
		return;
	}

	// Variables Temporales
	Nodo* temp = Root; Nodo* minNode; Nodo* nextNode;

	switch (tipoLista) {
	//Caso de Listas Lineales
	case Lista_Lineal:
	case Lista_D_Lineal:
		//Ciclo que se detendra hasta que detecte que temp es Nulo
		while (temp != nullptr) {
			minNode = temp; //Igualamos a temp para las comparaciones de las iteraciones
			nextNode = temp->GetNext(); //Movemos el puntero al siguiente Nodo

			//Ciclo que se detendra hasta que el nextNode sea Nulo y se realicen todas sus iteraciones
			while (nextNode != nullptr) {
				if (nextNode->GetValue() < minNode->GetValue()) {
					minNode = nextNode;
				}
				nextNode = nextNode->GetNext();
			}
			Swap(temp, minNode);
			temp = temp->GetNext();
		}

		break;

	//Caso de Listas Circulares
	case Lista_Circular:
	case Lista_D_Circular:
		//Ciclo que que se detendra hasta que temp sea Root
		do {
			minNode = temp;
			nextNode = temp->GetNext();

			while (nextNode != Root) {
				if (nextNode->GetValue() < minNode->GetValue()) {
					minNode = nextNode;
				}
				nextNode = nextNode->GetNext();
			}

			Swap(temp, minNode);
			
			temp = temp->GetNext();
		} while (temp != Root);

		break;
	default:
		std::cout << "ERROR: No se Eligio un Tipo de Lista" << std::endl;
		system("pause");
		break;
	}
}

Nodo* Lista::MergeSort(Nodo* actual)
{
	//Variables Temporales
	Nodo* mid;
	Nodo* nextMid;
	Nodo* izquierda;
	Nodo* derecha;

	//Detiene la Recurrención al detectar un Nodo en la Lista o No la ejecuta si no Existen Nodos
	if (!actual || !actual->GetNext()) {
		return actual;
	}

	//Buscamos los Nodos* que dividen a la Mitad
	mid = SearchMiddle(actual);
	nextMid = mid->GetNext();

	//Una vez Divididos, Corta las Conexiones entre ellos.
	mid->SetNext(nullptr);
	if (tipoLista == Lista_D_Circular || tipoLista == Lista_D_Lineal) {
		nextMid->SetLast(nullptr);
	}

	//Vuelve a ejecutar Recursividad hasta obtener todas las Divisiones
	izquierda = MergeSort(actual);
	derecha = MergeSort(nextMid);

	//Reinstaura el Root si se Intercambio
	Root = izquierda;

	//Ordena y Junta las Divisiones
	return SortAndMerge(izquierda, derecha);
}

Nodo* Lista::SearchMiddle(Nodo* temp)
{
	if (!temp) return temp;

	Nodo* slow = temp;
	Nodo* fast = temp->GetNext();

	//Avanzamos fast dos nodos y slow un nodo hasta que fast alcance el final.
	while (fast != nullptr && fast->GetNext() != nullptr) {
		slow = slow->GetNext();
		fast = fast->GetNext()->GetNext();
	}

	return slow;
}

Nodo* Lista::SortAndMerge(Nodo* izq, Nodo* der)
{
	if (!izq) return der;
	if (!der) return izq;

	Nodo* resultado = nullptr;

	//Verifica cual es Value es Mayor
	if (izq->GetValue() <= der->GetValue()) {
		resultado = izq;
		resultado->SetNext(SortAndMerge(izq->GetNext(), der));

		if (tipoLista == Lista_D_Circular || tipoLista == Lista_D_Lineal) {
			if (resultado->GetNext()) {
				resultado->GetNext()->SetLast(resultado);
			}
		}
	}
	else {
		resultado = der;
		resultado->SetNext(SortAndMerge(izq, der->GetNext()));

		if (tipoLista == Lista_D_Circular || tipoLista == Lista_D_Lineal) {
			if (resultado->GetNext()) {
				resultado->GetNext()->SetLast(resultado);
			}
		}
	}

	return resultado;
}

void Lista::DetectCircular()
{
	Nodo* last;

	//CAMBIOS: Cortamos el tail que conectaba con head
	last = Root;
	while (last->GetNext() != Root) {
		last = last->GetNext();
	}
	last->SetNext(nullptr);  // Elimina la conexión circular

	if (tipoLista == Lista_D_Circular || tipoLista == Lista_D_Lineal) {
		Root->SetLast(nullptr);
	}
}

void Lista::ConnectCircular()
{
	Nodo* tail = Root;

	while (tail->GetNext() != nullptr) {
		tail = tail->GetNext();
	}
	tail->SetNext(Root);  // Reconectamos la conexion circular

	if (tipoLista == Lista_D_Circular || tipoLista == Lista_D_Lineal) {
		Root->SetLast(tail);
	}
}

Nodo* Lista::QuickSort(Nodo* actual)
{
	if (!actual || !actual->GetNext()) {
		return actual;
	}

	//Variables Temporales
	Nodo* menores = nullptr;
	Nodo* mayores = nullptr;

	Nodo* last = actual;
	while (last->GetNext() != nullptr) {
		last = last->GetNext();
	}
	Nodo* pivot = last;

	PivotPartition(actual, pivot, menores, mayores);

	Nodo* sortedMenores = QuickSort(menores);
	Nodo* sortedMayores = QuickSort(mayores);

	Nodo* resultado = SortAndQuick(sortedMenores, pivot, sortedMayores);

	Root = resultado;

	return resultado;
}

void Lista::PivotPartition(Nodo* head, Nodo* pivot, Nodo*& menores, Nodo*& mayores)
{
	Nodo* current = head;
	Nodo* nextNode = nullptr;
	Nodo* tailMenores = nullptr;
	Nodo* tailMayores = nullptr;

	while (current) {
		nextNode = current->GetNext();
		if (current != pivot) {
			if (current->GetValue() <= pivot->GetValue()) {
				if (!menores) {
					menores = current;
					tailMenores = menores;
				}
				else {
					tailMenores->SetNext(current);
					if (tipoLista == Lista_D_Circular || tipoLista == Lista_D_Lineal) {
						current->SetLast(tailMenores);
					}
					tailMenores = current;
				}
				tailMenores->SetNext(nullptr);
			}
			else {
				if (!mayores) {
					mayores = current;
					tailMayores = mayores;
				}
				else {
					tailMayores->SetNext(current);
					if (tipoLista == Lista_D_Circular || tipoLista == Lista_D_Lineal) {
						current->SetLast(tailMayores);
					}
					tailMayores = current;
				}
				tailMayores->SetNext(nullptr);
			}
		}
		current = nextNode;
	}
}

Nodo* Lista::SortAndQuick(Nodo* menores, Nodo* pivot, Nodo* mayores)
{
	Nodo* resultado = nullptr;
	Nodo* tailMenores = menores;

	if (menores) {
		while (tailMenores->GetNext()) {
			tailMenores = tailMenores->GetNext();
		}
		resultado = menores;
		tailMenores->SetNext(pivot);
		if (tipoLista == Lista_D_Circular || tipoLista == Lista_D_Lineal) {
			pivot->SetLast(tailMenores);
		}
	}
	else {
		resultado = pivot;
	}

	// Conecta el pivote con mayores
	pivot->SetNext(mayores);
	if (tipoLista == Lista_D_Circular || tipoLista == Lista_D_Lineal && mayores) {
		mayores->SetLast(pivot);
	}

	return resultado;
}
