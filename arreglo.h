#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
#include <string>

template <class T>
class Arreglo
{
private:
    T *arreglo;
    size_t tam;
    size_t cont;
    const static size_t MAX = 100;
    void expandir();

public:
    Arreglo();
    ~Arreglo();
    void insertarFinal(const T &e);
    void insertarInicio(const T &e);
    void insertar(const T &e, size_t p);
    void eliminarFinal();
    void eliminarInicio();
    void eliminar(size_t p);
    void mostrar();
    T operator[](size_t p);
    T *buscar(const T &e);
    size_t size();
    Arreglo<T *> buscar_todos(const T &e);
    friend Arreglo<T> &operator<<(Arreglo<T> &a, const T &e)
    {
        {
            a.insertarFinal(e);

            return a;
        }
    }
};

template <class T>
Arreglo<T>::Arreglo()
{
    this->arreglo = new T[MAX];
    this->cont = 0;
    this->tam = MAX;
}

template <class T>
Arreglo<T>::~Arreglo()
{
    delete[] arreglo;
}

template <class T>
void Arreglo<T>::insertarFinal(const T &e)
{
    if (this->cont == this->tam)
    {
        expandir();
    }

    this->arreglo[this->cont] = e;
    this->cont++;
}

template <class T>
void Arreglo<T>::eliminarFinal()
{
    if (this->cont == 0)
    {
        return;
    }

    this->cont--;
}

template <class T>
void Arreglo<T>::insertarInicio(const T &e)
{
    if (this->cont == this->tam)
    {
        expandir();
    }

    for (size_t i = this->cont; i > 0; i--)
    {
        this->arreglo[i] = this->arreglo[i - 1];
    }

    this->arreglo[0] = e;
    this->cont++;
}

template <class T>
void Arreglo<T>::eliminarInicio()
{
    if (this->cont == 0)
    {
        return;
    }

    for (size_t i = 0; i < this->cont - 1; i++)
    {
        this->arreglo[i] = this->arreglo[i + 1];
    }

    this->cont--;
}

template <class T>
void Arreglo<T>::insertar(const T &e, size_t p)
{
    if (p >= this->cont || this->cont == 0)
    {
        return;
    }

    if (this->cont == this->tam)
    {
        expandir();
    }

    for (size_t i = this->cont; i > p; i--)
    {
        this->arreglo[i] = this->arreglo[i - 1];
    }

    this->arreglo[p] = e;
    this->cont++;
}

template <class T>
void Arreglo<T>::eliminar(size_t p)
{
    if (p >= this->cont || this->cont == 0)
    {
        return;
    }

    if (this->cont == this->tam)
    {
        expandir();
    }

    for (size_t i = p; i < this->cont - 1; i++)
    {
        this->arreglo[i] = this->arreglo[i + 1];
    }

    this->cont--;
}

template <class T>
T *Arreglo<T>::buscar(const T &e)
{
    for (size_t i = 0; i < cont; i++)
    {
        if (e == arreglo[i])
        {
            return &arreglo[i];
        }
    }

    return nullptr;
}

template <class T>
Arreglo<T *> Arreglo<T>::buscar_todos(const T &e)
{
    Arreglo<T *> ptrs;

    for (size_t i = 0; i < cont; i++)
    {
        if (e == arreglo[i])
        {
            ptrs.insertarFinal(&arreglo[i]);
        }
    }

    return ptrs;
}

template <class T>
void Arreglo<T>::mostrar()
{
    for (size_t i = 0; i < this->cont; i++)
    {
        std::cout << this->arreglo[i] << " ";
    }
}

template <class T>
size_t Arreglo<T>::size()
{
    return this->cont;
}

template <class T>
void Arreglo<T>::expandir()
{
    T *temp = new T[tam + MAX];

    for (size_t i = 0; i < this->cont; i++)
    {
        temp[i] = this->arreglo[i];
    }

    delete[] this->arreglo;
    this->arreglo = temp;
    this->tam += this->MAX;
}

template <class T>
T Arreglo<T>::operator[](size_t p)
{
    return this->arreglo[p];
}

#endif