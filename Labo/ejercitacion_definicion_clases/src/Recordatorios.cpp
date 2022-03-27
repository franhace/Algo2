#include <iostream>
#include <string>
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
    void incrementar_dia();

  private:
    //Completar miembros internos
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia){}

int Fecha::mes() {
    return mes_;
}

int Fecha::dia() {
    return dia_;
}

ostream& operator << (ostream& os, Fecha f){
    os << "" << f.dia() << "/" << f.mes() << "";
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    // Completar iguadad (ej 9)
    return igual_dia && igual_mes;
}

#endif

void Fecha::incrementar_dia() {
    // caso que sea ultimo dia del mes
    if (this->dia() == dias_en_mes(this->mes())){
        dia_ = 1;
        if (mes_==11){mes_=0;}
        else {
            mes_ = mes_ + 1;
        }
    } else{
        dia_ = dia_ + 1;
    }
}
// Ejercicio 11, 12

// Clase Horario
class Horario{
public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator == (Horario h);
    bool operator < (Horario h);

private:
    int hora_;
    int min_;
};

Horario::Horario(uint hora, uint min) : hora_(hora), min_(min){}

uint Horario::hora() {
    return hora_;
}

uint Horario::min() {
    return min_;
}

bool Horario::operator==(Horario h) {
    bool igual_hora = this->hora() == h.hora();
    bool igual_min = this->min() == h.min();
    return igual_hora && igual_min;
}

bool Horario::operator<(Horario h) {
    return ((hora_ < h.hora()) or (hora_ == h.hora() && min_ < h.min()));
}

ostream& operator << (ostream& os, Horario h){
    os << h.hora() << ":" << h.min();
}
// Ejercicio 13

// Clase Recordatorio
class Recordatorio{
public:
    Recordatorio(Fecha f, Horario h, string s);
    string mensaje();
    Horario horario();
    Fecha fecha();
private:
    Horario h_;
    Fecha f_;
    string m_;


};

Recordatorio::Recordatorio(Fecha f, Horario h, string s) : f_(f), h_(h), m_(s) {}

string Recordatorio::mensaje() {
    return std::string(m_);
}

Horario Recordatorio::horario() {
    return h_;
}

Fecha Recordatorio::fecha() {
    return f_;
}

ostream& operator << (ostream& os, Recordatorio r){
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario();
}

// Ejercicio 14

// Clase Agenda

