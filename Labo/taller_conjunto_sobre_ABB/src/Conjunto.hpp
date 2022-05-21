template <class T>
Conjunto<T>::Conjunto(): _raiz() {
    // Completar
}

template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* nodo = _raiz;
    while (nodo != nullptr && nodo->valor != clave){
        if (clave > nodo->valor) nodo = nodo->der;
        else nodo = nodo->izq;
    }
    return nodo != nullptr;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if (pertenece(clave)== false){
        Nodo* nuevo = new Nodo(clave);
        Nodo* anterior = NULL;
        Nodo* nodo = _raiz;

        while (nodo != NULL){
            anterior = nodo;
            if (nuevo->valor < nodo->valor){
                nodo = nodo->izq;
            } else {
                nodo = nodo->der;
            }
        }
        nuevo->parent = anterior;
        if (anterior == NULL){
            // ABB vacio
            _raiz = nuevo;
        } else if (nuevo->valor < anterior->valor){
            anterior->izq = nuevo;
        } else {
            anterior->der = nuevo;
        }

        _cardinal += 1;
    }

}

template <class T>
void Conjunto<T>::remover(const T&) {
    assert(false);
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    assert(false);
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* nodo = _raiz;
    while (nodo != nullptr){
        nodo = nodo->izq;
    }
    return nodo->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* nodo = _raiz;
    while (nodo != nullptr){
        nodo = nodo->der;
    }
    return nodo->valor;
}


template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    std::cout << "[";
    Nodo* actual = _raiz;
    while (actual->next) {
        std::cout << actual->value << ", ";
        actual = actual->next;
    }
    std::cout << actual->value << "]";
}


