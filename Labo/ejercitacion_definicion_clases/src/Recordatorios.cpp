#include <iostream>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    // Completar declaraciones funciones
    Fecha(int mes, int dia);
    int mes();
    int dia();
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif

  private:
    //Completar miembros internos
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia){}

int Fecha::mes() {
    return mes_;
}


#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    // Completar iguadad (ej 9)
    return igual_dia;
}



#endif

// Ejercicio 11, 12

// Clase Horario


// Ejercicio 13

// Clase Recordatorio


// Ejercicio 14

// Clase Agenda

