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

SistemaDeMensajes::~SistemaDeMensajes() {
    for (auto & _conn : _conns) {
        delete _conn;
    }
    for (auto & _prox : _proxs) {
        delete _prox;
    }
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    _conns[id] = nullptr;
}

Proxy *SistemaDeMensajes::obtenerProxy(int id) {
    _proxs.push_back(new Proxy(_conns[id]));
    return _proxs[_proxs.size()-1];
}

