#ifndef SISTEMADEMENSAJES_H
#define SISTEMADEMENSAJES_H

#include "ConexionJugador.h"
#include "Proxy.h"
#include <string>
#include "vector"

#if EJ == 4 || EJ == 5
#include "Proxy.h"
#elif EJ == 6
#include "Proxy2.h"
#endif

using namespace std;

class SistemaDeMensajes {
  public:
    SistemaDeMensajes();
    ~SistemaDeMensajes();
    // Pre: 0 <= id < 4
    void registrarJugador(int id, string ip);
    // Pre: 0 <= id < 4
    bool registrado(int id) const;

    // Pre: registrado(id)
    void enviarMensaje(int id, string mensaje);
    void desregistrarJugador(int id);

    // Pre: registrado(id)
    string ipJugador(int id) const;

    Proxy* obtenerProxy(int id);

  private:
    ConexionJugador* _conns[4];
    vector<Proxy*> _proxs;
};

#endif
