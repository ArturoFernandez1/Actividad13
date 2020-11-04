#include <iostream>
#include "arreglo.h"

using namespace std;

int main(){

    Arreglo<string> myArray;
    //Inserción de 4 strings, usando los métodos insertarInicio() e insertarFinal()
    myArray.insertarInicio("Manzana");
    myArray.insertarFinal("Pera");
    myArray.insertarInicio("Uva");
    myArray.insertarFinal("Fresa");
    //Mostramos los elementos mediante mostrar()
    myArray.mostrar();
    cout << endl;
    //Inserción de un elemento en la posición 2
    myArray.insertar("Ciruela", 2);
    //Mostramos los elementos mediante mostrar()
    myArray.mostrar();
    cout << endl;
    //Eliminamos dos elementos, uno al inicio y otro al final, mediante eliminarInicio() y eliminarFinal()
    myArray.eliminarInicio();
    myArray.eliminarFinal();
    //Eliminamos elemento en la posición 1
    myArray.eliminar(1);
    //Mostramos los elementos mediante mostrar()
    myArray.mostrar();
    cout << endl;

    return 0;
}