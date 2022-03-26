#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : alto_(alto), ancho_(ancho) {};

uint Rectangulo::alto() {
    return alto_;
}

uint Rectangulo::ancho() {
    return ancho_;
}

float Rectangulo::area() {
    return (alto_*ancho_);
}

// Completar definición: ancho

// Completar definición: area

// Ejercicio 2

// Clase Elipse

class Elipse{
    public:
        Elipse(uint a, uint b);
        uint r_a();
        uint r_b();
        float area();
        float Pi = 3.14;

    private:
        int r_a_;
        int r_b_;
};

Elipse::Elipse(uint a, uint b): r_a_(a), r_b_(b) {}

uint Elipse::r_a() {
    return r_a_;
}

uint Elipse::r_b() {
    return r_b_;
}

float Elipse::area() {
    return Pi*r_a()*r_b();
}
// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
    return r_.ancho();
}

float Cuadrado::area() {
    return lado()*lado();
}

// Ejercicio 4

// Clase Circulo

class Circulo{
public:
    Circulo(uint radio);
    uint radio();
    float area();

private:
    Elipse r_;

};

Circulo::Circulo(uint radio) : r_(radio, radio) {}

uint Circulo::radio() {
    return r_.r_a();
}

float Circulo::area() {
    return r_.area();
}


// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

// ostream Elipse

ostream& operator<<(ostream& os, Elipse e){
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
}

// Ejercicio 6
ostream& operator<<(ostream& os, Cuadrado e){
    os << "Cuad(" << e.lado() << ")";
}

ostream& operator<<(ostream& os, Circulo e){
    os << "Circ(" << e.radio() << ")";
}