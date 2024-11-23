#pragma once
#include "Nodo.h"
#include <iostream>
#include <random>
#include <cmath>
#include <chrono>

enum LISTTYPE {
	Lista_Lineal = 0,
	Lista_Circular = 1,
	Lista_D_Lineal = 3,
	Lista_D_Circular = 4,
	Default
};

class Lista
{
private:
	Nodo* Root;

	//METODOS
	void SetRoot(Nodo* _root);
	void SetRoot(int _root);

public:
	//CONSTRUCTORES
	Lista(); //Implicito
	~Lista(); //Destructor

	LISTTYPE tipoLista;

	//METODOS
	Nodo* GetRoot();
	void Swap(Nodo* izquierdo, Nodo* derecho); //Cambia Valores de Lugar
	void GetValue(int _position, int index); //Regresa el Valor de un Nodo
	void Push(int _n); //Agrega Nuevo Nodo al Final de Lista
	void ReadList(); //Leer Lista
	void ClearList(); //Eliminar Lista
	void Pop(int index); //Elimina el Ultimo Nodo y Regresa su Valor
	void Queue(int index); //Elimina el Primer Nodo y Regresa su Valor
	void Erase(int _position, int index); //Elimina y Reasigna
	void SearchOnList(); //Solo disponible para LDC y recorre nodos de Last y Next
	void FillList(int min, int max, int size); //Funcion que Rellena la Lista con Valores Randomizados en un Tamaño Establecido
	void BubbleSort(); //Ordenamiento Burbuja
	void InsertionSort(); //Ordenamiento por Insercion
	void SelectionSort(); //Ordenamiento por Seleccion
	Nodo* MergeSort(Nodo* actual); //Ordenamiento por Mezcla
	Nodo* SearchMiddle(Nodo* temp); //Busca los dos Punteros Centrales de una Lista
	Nodo* SortAndMerge(Nodo* izq, Nodo* der); //Ordena y Junta Distintas Recursiones
	void DetectCircular(); //Corta la Conexion Circular
	void ConnectCircular(); //Reconecta la Conexion Circular
	Nodo* QuickSort(Nodo* actual);//Ordenamiento Rapido
	void PivotPartition(Nodo* head, Nodo* pivot, Nodo*& menores, Nodo*& mayores);
	Nodo* SortAndQuick(Nodo* menores, Nodo* pivot, Nodo* mayores);
};

