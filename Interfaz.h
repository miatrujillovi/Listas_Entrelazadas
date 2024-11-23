#pragma once
#include "Lista.h"
#include <limits>
#include <functional>

class Interfaz
{
private:
	Lista lista;
	int contador = 0;

public:
	//CONSTRUCTOR
	Interfaz(); //Implicito
	~Interfaz(); //Destructor

	//METODO
	void Menu();
	void TipoLista();
	void Agregar();
	void ValoresRandom();
	void ObtenerValor();
	void Ordenamientos();
	void EliminarEspecifico();
	void CinInputs();
	void MeasureTime(const std::string& functionName, const std::function<void()>& func);
};

