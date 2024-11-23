#pragma once

class Nodo
{
private:
	int Value;
	Nodo* nextNodo;
	Nodo* lastNodo;

public:
	//CONSTRUCTORES
	Nodo(); //Implicito
	Nodo(int _value, Nodo* _nextNodo, Nodo* _lastNodo); //Parametros

	//SOBRECARGAS
	bool operator>(Nodo* other); //Para realizar Comparaciones de los Valores de los Nodos

	//METODOS
	int GetValue();
	void SetValue(int _value);
	Nodo* GetNext();
	void SetNext(Nodo* _nodo);
	Nodo* GetLast();
	void SetLast(Nodo* _nodo);
};

