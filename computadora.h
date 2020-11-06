#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include<iostream>
#include<iomanip>

class Computadora
{
private:
    std::string so;
    std::string cpu;
    float ram;
    float almacenamiento;

public:
    Computadora();
    Computadora(const std::string &so, const std::string &cpu, float ram, float almacenamiento);
    void setSO(const std::string &so);
    std::string getSO();
    void setCPU(const std::string &cpu);
    std::string getCPU();
    void setRAM(float ram);
    float getRAM();
    void setAlmacenamiento(float almacenamiento);
    float getAlmacenamiento();
    friend std::ostream& operator<<(std::ostream &out, const Computadora& c);
    friend std::istream& operator>>(std::istream &in, Computadora& c);
    bool operator==(const Computadora&) const;
};

#endif