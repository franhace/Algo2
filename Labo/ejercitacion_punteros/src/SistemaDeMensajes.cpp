#include "SistemaDeMensajes.h"

// Completar...
SistemaDeMensajes::SistemaDeMensajes() {
    for (auto & _conn : _conns) {
        _conn = nullptr;
    }}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    _conns[id] = new ConexionJugador(ip);
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id];
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    ConexionJugador(ipJugador(id)).enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}
