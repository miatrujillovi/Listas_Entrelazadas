#include "Nodo.h"

Nodo::Nodo():Value(0),nextNodo(nullptr), lastNodo(nullptr) {}

Nodo::Nodo(int _value, Nodo* _nextNodo, Nodo* _lastNodo) : Value(_value), nextNodo(_nextNodo), lastNodo(_lastNodo) {}

bool Nodo::operator>(Nodo* other)
{
	return this->Value > other->GetValue();
}

//METODOS
int Nodo::GetValue()
{
	return Value;
}

void Nodo::SetValue(int _value)
{
	this -> Value = _value;
}

Nodo* Nodo::GetNext()
{
	return nextNodo;
}

void Nodo::SetNext(Nodo* _nodo)
{
	this -> nextNodo = _nodo;
}

Nodo* Nodo::GetLast()
{
	return lastNodo;
}

void Nodo::SetLast(Nodo* _nodo)
{
	this ->lastNodo = _nodo;
}
