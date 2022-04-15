#include "Lista.h"

Lista::Lista() : _length(0), _head(nullptr), _last(nullptr){
    // Completar
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    // Completar
    Nodo* actual = _head;
    while (actual != nullptr){
        Nodo* prev = actual;
        actual = actual->next;
        delete(prev);
    }
}

Lista& Lista::operator=(const Lista& aCopiar) {
    // Completar
    // atenti: esto vale para casos donde ya hice una copia (o=aCopiar)
    // y donde todavia tengo en memoria los valores anteriores
    // pero habiendo modificado la lista aCopiar y volviendo a hacer (o=aCopiar)
    // tengo que "reinicializar" mi lista borrando sus elems y..
    while (_length > 0){
        this->eliminar(0);
    }
    // copio los elems de la lista aCopiar
    for (int i = 0; i < aCopiar._length; ++i) {
        this->agregarAtras(aCopiar.iesimo(i));
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    // Completar
    // definimos nuevo elem
    Nodo* agr = new Nodo;
    agr->prev = nullptr;
    agr->next = _head;
    agr->value = elem;
    if (_length>0) {
        _head->prev = agr;
        _head = agr;
    }
    // en caso de ser el unico lo definimos como last
    else {
        _head = agr;
        _last = _head;}
    _length++;
}

void Lista::agregarAtras(const int& elem) {
    // Completar
    // definimos nuevo elem
    Nodo* agr = new Nodo;
    agr->prev = _last;
    agr->next = nullptr;
    agr->value = elem;
    if (_length>0) {
        _last->next = agr;
        _last = agr;
    }
        // en caso de ser el unico lo definimos como last
    else {
        _last = agr;
        _head = _last;}
    _length++;
}

void Lista::eliminar(Nat i) {
    // Completar
    // asumo que siempre vale: 0 <= i <= _length-1;
    Nodo* actual = _head;
    if (_length==1){
        _head= nullptr;
        _last= nullptr;
    }
    // si es el primer elem, el que le sigue sera el 1ero oficial
    else if (i==0){
        _head->next->prev = nullptr;
        _head = _head->next;
    }
    // si es el ult elem, el que fuera el anterior sera el ult oficial
    else if (i==_length-1){
        actual = _last;
        _last->prev->next = nullptr;
        _last = _last->prev;
    }
    else { // en su defecto, linkeamos el anterior con el sig y vice versa
        int r = 0;
        while (r<i){
            actual = actual->next;
            r++;
        }
        actual->prev->next = actual->next;
        actual->next->prev = actual->prev;
    }
    // para evitar perdidas de memoria borramos el actual ( siempre es el que se borra )
    delete(actual);
    _length--;
}

int Lista::longitud() const {
    // Completar
    return _length;
}

const int& Lista::iesimo(Nat i) const {
    // Completar
    // asumo que siempre vale: 0 <= i <= _length-1;
    int r = 0;
    Nodo* actual = _head;
    while (r<i){
        actual = actual->next;
        r++;
    }
    return actual->value;
}

int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    // asumo que siempre vale: 0 <= i <= _length-1;
    int r = 0;
    Nodo* actual = _head;
    while (r<i){
        actual = actual->next;
        r++;
    }
    return actual->value;
}

void Lista::mostrar(ostream& o) {
    // Completar
//    cout << o << endl;
//    int r = 0;
//    vector<int> valores = {};
//    Nodo* actual = _head;
//    while (r<_length-1){
//        actual = actual->next;
//        int valor = actual->value;
//        valores.push_back(valor);
//        r++;
//    }
//    cout << "[";
//    for (int i = 0; i < valores.size(); ++i) {
//        cout << i;
//    }
//    cout << "]" << endl;
}
