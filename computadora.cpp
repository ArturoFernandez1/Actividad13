#include "computadora.h"

using namespace std;

Computadora::Computadora() {}

Computadora::Computadora(const std::string &so, const std::string &cpu, float ram, float almacenamiento)
{
    this->so = so;
    this->cpu = cpu;
    this->ram = ram;
    this->almacenamiento = almacenamiento;
}

void Computadora::setSO(const std::string &so)
{
    this->so = so;
}
std::string Computadora::getSO()
{
    return so;
}
void Computadora::setCPU(const std::string &cpu)
{
    this->cpu = cpu;
}
std::string Computadora::getCPU()
{
    return cpu;
}
void Computadora::setRAM(float ram)
{
    this->ram = ram;
}
float Computadora::getRAM()
{
    return ram;
}
void Computadora::setAlmacenamiento(float almacenamiento)
{
    this->almacenamiento = almacenamiento;
}
float Computadora::getAlmacenamiento()
{
    return almacenamiento;
}

ostream &operator<<(std::ostream &out, const Computadora &c)
{
    out << left;
    out << setw(20) << c.so;
    out << setw(24) << c.cpu;
    out << setw(10) << c.ram;
    out << setw(8) << c.almacenamiento;
    out << endl;

    return out;
}

istream &operator>>(istream &in, Computadora &c)
{
    cout << "Sistema operativo: ";
    getline(cin, c.so);

    cout << "CPU: ";
    getline(cin, c.cpu);

    cout << "RAM: ";
    cin >> c.ram;

    cout << "Almacenamiento: ";
    cin >> c.almacenamiento;

    cout << endl;

    return in;
}

bool Computadora::operator==(const Computadora &c) const
{
    return this->so == c.so;
}