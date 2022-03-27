#include <utility>

using namespace std;

// Ejercicio 15

// Juego

using Pos = pair<int, int>;

char ARRIBA = '^';
char ABAJO = 'v'; 
char DERECHA = '<';
char IZQUIERDA = '>';

class Juego {
  // Completar
public:
    Juego(uint casilleros, Pos pos_inicial);
    Pos posicion_jugador();
    uint turno_actual();
    void mover_jugador(char dir);
    void ingerir_pocion(uint movimientos, uint turnos);

private:
    uint c_; // tño grilla
    Pos p_; // pos jugador
    uint m_; // movimientos disponibles en turno
    uint t_; // que turno va
    vector<pair<uint, uint>> // (turnos que dura pocion, cuantos movimientos)
};

Juego::Juego(uint casilleros, Pos pos_inicial) : c_(casilleros), p_(pos_inicial){}

Pos Juego::posicion_jugador() {
    return p_;
}

uint Juego::turno_actual() {
    return t_;
}

void Juego::mover_jugador(char dir) {
    Pos a_donde_va;
    if (dir==ARRIBA){a_donde_va = make_pair(-1,0);}
    else if (dir==ABAJO){a_donde_va = make_pair(1,0);}
    else if (dir==DERECHA){a_donde_va = make_pair(0,1);}
    else{a_donde_va = make_pair(0,-1);}
    if ((posicion_jugador().first+a_donde_va.first>c_) || (posicion_jugador().first+a_donde_va.first<0)
        || (posicion_jugador().second+a_donde_va.first>c_) || (posicion_jugador().first+a_donde_va.second<0))
        {cout << "pos invalida" << endl;}
    else
    {
        if ((p_.first += a_donde_va.first >= 0) || (p_.first += a_donde_va.first < c_))
        {
            if ((p_.first += a_donde_va.second >= 0) || (p_.first += a_donde_va.second < c_)) {
                p_.first += a_donde_va.first;
                p_.second += a_donde_va.second;
            }}
    }
void Juego::ingerir_pocion(uint movimientos, uint turnos) {

}
