#include <iostream>
#include "arreglo.h"
#include "computadora.h"

using namespace std;

int main(){

    Arreglo<Computadora> computadoras;
    Computadora c1("Linux","AMD Ryzen 5 3600",12,256),
                c2("Windows", "Intel Core i5 10600k", 8, 512),
                c3("macOS","Intel Core i9 10900k", 32, 2048),
                c4("Linux","AMD Ryzen 5 3600",12,256),
                c5("Linux","AMD Ryzen 5 3600",12,256);

    computadoras << c1 << c2 << c3 << c4 << c5;

    Computadora c6("Windows","Intel Pentium II",.512,128);

    Computadora* ptrc1 = computadoras.buscar(c6);
    if (ptrc1 != nullptr){
        cout << *ptrc1 << endl;
    }
    else{
        cout << "El elemento no existe" << endl;
    }

    Computadora c7("Windows XP","Intel Pentium II",.512f,128);

    Computadora* ptrc2 = computadoras.buscar(c7);
    if (ptrc2 != nullptr){
        cout << *ptrc2 << endl;
    }
    else{
        cout << "El elemento no existe" << endl << endl;
    }

    Computadora c8("Linux","AMD Ryzen 2700x",32,2048);

    Arreglo<Computadora*> ptrsC = computadoras.buscar_todos(c8);

    if(ptrsC.size() > 0){
        for (size_t i = 0; i < ptrsC.size(); i++)
        {
            cout << *ptrsC[i] << endl;
        } 
    }
    else{
        cout << "No se hallaron coincidencias" << endl;
    }

    /*Arreglo<string> myArray;
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
    cout << endl;*/

    return 0;
}
