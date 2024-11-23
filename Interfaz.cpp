#include "Interfaz.h"

Interfaz::Interfaz() {}

Interfaz::~Interfaz() {}

void Interfaz::Agregar()
{
    if (lista.tipoLista == Default) {
        system("CLS");
        std::cout << "ERROR: Tiene que Seleccionar un Tipo de Lista" << std::endl;
        Menu();
    }
    else {
        int valor;
        char terminar = ' ';
        while (terminar != 'n') {
            while (true) {
                std::cout << "Introduzca el Valor Numerico del Nodo: " << std::endl;
                std::cin >> valor;
                if (std::cin.fail()) {
                    CinInputs();
                }
                else {
                    char ch;
                    std::cin.get(ch);
                    if (ch == '\n') {
                        break;
                    }
                    else {
                        CinInputs();
                    }
                }
            }
            contador++;
            lista.Push(valor);
            std::cout << "Nodo Creado Correctamente. ";
            while (true) {
                std::cout << "Desea Agregar Mas? y/n" << std::endl;
                std::cin >> terminar;

                if (terminar == 'y' || terminar == 'n') {
                    break;
                }
                else {
                    std::cout << "Entrada Invalida. Por Favor solo Ingrese y (Si) o n (No)" << std::endl;
                }
            }
        }
    }
}

void Interfaz::TipoLista()
{
    int seleccionLista = 0;
    char nuevaLista;
    while (true) {
        std::cout << "Crear una Nueva Lista implica Borrar la Existente. Desea continuar? y/n" << std::endl;
        std::cin >> nuevaLista;

        if (nuevaLista == 'y' || nuevaLista == 'n') {
            break;
        }
        else {
            std::cout << "Entrada Invalida. Por Favor solo Ingrese y (Si) o n (No)" << std::endl;
        }
    }

    if (nuevaLista == 'y') {
        system("CLS");
        contador = 0;
        std::cout << "1. Lista Ligada Lineal" << std::endl;
        std::cout << "2. Lista Ligada Circular" << std::endl;
        std::cout << "3. Lista Doblemente Ligada Lineal" << std::endl;
        std::cout << "4. Lista Doblemente Ligada Circular" << std::endl;

        while (true) {
            std::cout << "Seleccione el Tipo de Lista de que Desea: " << std::endl;
            std::cin >> seleccionLista;
            if (seleccionLista < 0) {
                std::cout << "Opcion NO Valida" << std::endl;
                system("pause");
                break;
            }
            if (std::cin.fail()) {
                CinInputs();
            }
            else {
                char ch;
                std::cin.get(ch);
                if (ch == '\n') {
                    break;
                }
                else {
                    CinInputs();
                }
            }
        }

        switch (seleccionLista) {
        case 1:
            contador = 0;
            lista.ClearList();
            lista.tipoLista = Lista_Lineal;
            break;
        case 2:
            contador = 0;
            lista.ClearList();
            lista.tipoLista = Lista_Circular;
            break;
        case 3:
            contador = 0;
            lista.ClearList();
            lista.tipoLista = Lista_D_Lineal;
            break;
        case 4:
            contador = 0;
            lista.ClearList();
            lista.tipoLista = Lista_D_Circular;
            break;
        default:
            std::cout << "Opcion NO Valida" << std::endl;
            system("pause");
            break;
        }
    }
}

void Interfaz::ValoresRandom()
{
    if (lista.tipoLista == Default) {
        system("CLS");
        std::cout << "ERROR: Tiene que Seleccionar un Tipo de Lista" << std::endl;
        Menu();
    }

    system("CLS");
    int min, max, size;
    while (true) {
        std::cout << "Escriba la Cantidad de Nodos que Desea: ";
        std::cin >> size;
        if (std::cin.fail()) {
            CinInputs();
        }
        else {
            char ch;
            std::cin.get(ch);
            if (ch == '\n') {
                break;
            }
            else {
                CinInputs();
            }
        }
    }
    while (true) {
        std::cout << "\nEscriba el Valor Minimo que Quiere que Tengan los Nodos: ";
        std::cin >> min;
        if (std::cin.fail()) {
            CinInputs();
        }
        else {
            char ch;
            std::cin.get(ch);
            if (ch == '\n') {
                break;
            }
            else {
                CinInputs();
            }
        }
    }
    while (true) {
        std::cout << "\nEscriba el Valor Maximo que Quiere que Tengan los Nodos: ";
        std::cin >> max;
        if (std::cin.fail()) {
            CinInputs();
        }
        else {
            char ch;
            std::cin.get(ch);
            if (ch == '\n') {
                break;
            }
            else {
                CinInputs();
            }
        }
    }
    contador += size;

    lista.FillList(min, max, size);

}

void Interfaz::ObtenerValor()
{
    int index = 0;
    while (true) {
        std::cout << "Introduzca el Indice del Nodo: ";
        std::cin >> index;
        if (std::cin.fail()) {
            CinInputs();
        }
        else {
            char ch;
            std::cin.get(ch);
            if (ch == '\n') {
                break;
            }
            else {
                CinInputs();
            }
        }
    }
    lista.GetValue(index, contador);
}

void Interfaz::Ordenamientos()
{

    if (lista.tipoLista == Default) {
        std::cout << "ERROR: Tiene que Seleccionar un Tipo de Lista" << std::endl;
        system("pause");
        Menu();
    }

    system("CLS");
    std::cout << "1. Ordenamiento Burbuja" << std::endl;
    std::cout << "2. Ordenamiento por Insercion" << std::endl;
    std::cout << "3. Ordenamiento por Seleccion" << std::endl;
    std::cout << "4. Ordenamiento por Mezcla" << std::endl;
    std::cout << "5. Ordenamiento Rapido" << std::endl;

    int select;
    while (true) {
        std::cout << "Seleccione el Tipo de Ordenamiento que Desea: ";
        std::cin >> select;
        if (std::cin.fail()) {
            CinInputs();
        }
        else {
            char ch;
            std::cin.get(ch);
            if (ch == '\n') {
                break;
            }
            else {
                CinInputs();
            }
        }
    }

    switch (select) {
    case 1:
        std::cout << "Su Lista Actual es: "; lista.ReadList(); std::cout << std::endl;
        MeasureTime("BubbleSort", [&]() {
            lista.BubbleSort();
         });
        std::cout << "La Lista se ha Terminado de Ordenar: "; lista.ReadList(); std::cout << std::endl;
        break;
    case 2: 
        std::cout << "Su Lista Actual es: "; lista.ReadList(); std::cout << std::endl;
        MeasureTime("InsertionSort", [&]() {
            lista.InsertionSort();
        });
        std::cout << "La Lista se ha Terminado de Ordenar: "; lista.ReadList(); std::cout << std::endl;
        break;
    case 3:
        std::cout << "Su Lista Actual es: "; lista.ReadList(); std::cout << std::endl;
        MeasureTime("SelectionSort", [&]() {
            lista.SelectionSort();
         });
        std::cout << "La Lista se ha Terminado de Ordenar: "; lista.ReadList(); std::cout << std::endl;
        break;
    case 4:
        std::cout << "Su Lista Actual es: "; lista.ReadList(); std::cout << std::endl;
        if (lista.tipoLista == Lista_Circular || lista.tipoLista == Lista_D_Circular) {
            lista.DetectCircular();
        }
        MeasureTime("MergeSort", [&]() {
            lista.MergeSort(lista.GetRoot());
         });
        if (lista.tipoLista == Lista_Circular || lista.tipoLista == Lista_D_Circular) {
            lista.ConnectCircular();
        }
        std::cout << "La Lista se ha Terminado de Ordenar: "; lista.ReadList(); std::cout << std::endl;
        break;
    case 5:
        std::cout << "Su Lista Actual es: "; lista.ReadList(); std::cout << std::endl;
        if (lista.tipoLista == Lista_Circular || lista.tipoLista == Lista_D_Circular) {
            lista.DetectCircular();
        }
        MeasureTime("QuickSort", [&]() {
            lista.QuickSort(lista.GetRoot());
         });
        if (lista.tipoLista == Lista_Circular || lista.tipoLista == Lista_D_Circular) {
            lista.ConnectCircular();
        }
        std::cout << "La Lista se ha Terminado de Ordenar: "; lista.ReadList(); std::cout << std::endl;
        break;
    default:
        std::cout << "Opcion NO Valida" << std::endl;
        system("pause");
        break;
    }
}

void Interfaz::EliminarEspecifico()
{
    int index = 0;
    while (true) {
        std::cout << "Introduzca el Indice del Nodo: ";
        std::cin >> index;
        if (std::cin.fail()) {
            CinInputs();
        }
        else {
            char ch;
            std::cin.get(ch);
            if (ch == '\n') {
                break;
            }
            else {
                CinInputs();
            }
        }
    }
    lista.Erase(index, contador);
    contador--;
    std::cout << "Se Elimino Correctamente" << std::endl;
}

void Interfaz::CinInputs()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Entrada Invalida. Solo se Aceptan Valores Numericos" << std::endl;
}

void Interfaz::MeasureTime(const std::string& functionName, const std::function<void()>& func)
{
    auto start = std::chrono::high_resolution_clock::now(); //Empieza a contar el tiempo
    func(); // Llama a la funcion
    auto end = std::chrono::high_resolution_clock::now(); //Termina de contarlo

    // Calcula la duracion en milisegundos
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Tiempo de ejecucion de " << functionName << ": " << duration.count() << " ms" << std::endl;
}

void Interfaz::Menu()
{
	int opt = 0;

    while (opt != 12) {
        std::cout << "1. Crear Tipo de Lista" << std::endl;
        std::cout << "2. Agregar Nodo" << std::endl;
        std::cout << "3. Rellenar Lista con Valores Aleatorios" << std::endl;
        std::cout << "4. Obtener Valor de un Nodo" << std::endl;
        std::cout << "5. Leer Lista" << std::endl;
        std::cout << "6. Limpiar Lista" << std::endl;
        std::cout << "7. Algoritmos de Ordenamiento" << std::endl;
        std::cout << "8. Obtener Ultimo Valor y Eliminar" << std::endl;
        std::cout << "9. Obtener Primer Valor y Eliminar" << std::endl;
        std::cout << "10. Eliminar un Nodo Especifico" << std::endl;
        std::cout << "11. (Solo Disponible para Doblemente Ligada Circular) Simulacion de Recorridos de Nodos" << std::endl;
        std::cout << "12. Salir" << std::endl;

        while (true) {
            std::cout << "Escriba la Opcion a Seleccionar: ";
            std::cin >> opt;
            if (std::cin.fail()) {
                CinInputs();
            } else {
                char ch;
                std::cin.get(ch);
                if (ch == '\n') {
                    break;
                }
                else {
                    CinInputs();
                }
            }
        }
        
        switch (opt) {
        case 1:
            TipoLista();

            break;
        case 2:
            Agregar();

            break;
        case 3:
            ValoresRandom();
                
            break;
        case 4:
            ObtenerValor();

            break;
        case 5:
            lista.ReadList();
            break;
        case 6:
            lista.ClearList();
            std::cout << "Lista Eliminada" << std::endl;
            break;
        case 7:
            Ordenamientos();
            break;
        case 8:
            lista.Pop(contador);
            contador--;
            std::cout << "Se Elimino Correctamente" << std::endl;
            break;
        case 9:
            lista.Queue(contador);
            contador--;
            std::cout << "Se Elimino Correctamente" << std::endl;
            break;
        case 10:
            EliminarEspecifico();

            break;
        case 11:
            if (lista.tipoLista != Lista_D_Circular) {
                std::cout << "ERROR: Funcion solo Disponible para Tipo de Lista Doblemente Circular." << std::endl;
                system("pause");
                break;
            } else {
                lista.SearchOnList();
            }

            break;
        case 12:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opcion NO Valida" << std::endl;
            system("pause");
            break;
        }
        system("CLS");
	}
}
