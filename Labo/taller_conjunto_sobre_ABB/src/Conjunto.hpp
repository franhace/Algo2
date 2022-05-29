
template <class T>
Conjunto<T>::Conjunto() : _raiz(NULL), _cardinal(0), _elQueSigue(NULL) {
}

template <class T>
void Conjunto<T>::inorder_tree_destruction(Nodo* nodo){
    //From Cormen's book
    if(nodo != NULL){
        inorder_tree_destruction(nodo->izq);

        inorder_tree_destruction(nodo->der);
        // Delete en orden
        delete(nodo);
    }
}

template <class T>
Conjunto<T>::~Conjunto() {
    // Completar
    inorder_tree_destruction(_raiz);
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* nodo = _raiz;
    //From Cormen's book
    //cout << "Pertenece " << clave << " ? : " ;
    while (nodo != NULL && nodo->valor != clave){
        //cout << "nodo->valor:" << nodo->valor << endl;
        //cout << "nodo->izq:" << nodo->izq << endl;
        //cout << "nodo->der:" << nodo->der << endl;
        if (clave < nodo->valor){
            nodo = nodo->izq;
        } else {
            nodo = nodo->der;
        }
    }
    //cout << (nodo != NULL) << endl;
    return nodo != NULL;
}

template<class T>
void Conjunto<T>::insertar(const T& clave) {
    if (pertenece(clave)){
        // Elemento ya existe
        return;
    }

    Nodo* nuevo = new Nodo(clave);
    Nodo* anterior = NULL;
    Nodo* nodo = _raiz;
    //From Cormen's book
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
        // Arbol vacio
        _raiz = nuevo;
    } else if (nuevo->valor < anterior->valor){
        anterior->izq = nuevo;
    } else {
        anterior->der = nuevo;
    }

    _cardinal += 1;

    return;
}

template <class T>
void Conjunto<T>::transplantar(Nodo* u, Nodo* v) {
    if(u->parent == NULL){
        _raiz = v;
    } else if (u == u->parent->izq){
        u->parent->izq = v;
    } else {
        u->parent->der = v;
    }
    if (v != NULL){
        v->parent = u->parent;
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    // Si existe, 3 casos:
    // * Es hoja
    // * Tiene un hijo
    // * Tiene dos hijos
    Nodo* nodo = _raiz;
    //From Cormen's book
    // recorre el arbol hasta encontrar nodo->valor == clave
    while (nodo != NULL && (nodo->valor) != clave){
        if (clave < nodo->valor){
            nodo = nodo->izq;
        } else {
            nodo = nodo->der;
        }
    }
    if (nodo == NULL){
        // No pertenece al conjunto
        return;
    }

    if (nodo->izq == NULL){
//        cout << "NULL a izquierda" << endl;
        transplantar(nodo, nodo->der);
    } else if (nodo->der == NULL) {
//        cout << "NULL a derecha" << endl;
        transplantar(nodo, nodo->izq);
    } else {
//        cout << "Ambos hijes" << endl;
        // Busco el nodo minimo
        Nodo* minimo = nodo->der;

        //From Cormen's book
        while (minimo->izq != NULL){
            minimo = minimo->izq;
//            cout << "3. minimo en el while: " << minimo->valor << endl;
//            cout << "3. minimo parent en el while: " << minimo->parent->valor << endl;
        }
//        cout << "Minimo > value: " << minimo->valor << endl;
//        cout << "Minimo > parent > value: " << minimo->parent->valor << endl;
//        cout << "nodo > value: " << nodo->valor << endl;
        if (minimo->parent != nodo){
//            cout << "minimo->parent != nodo" << endl;
            transplantar(minimo, minimo->der);
            minimo->der = nodo->der;
            minimo->der->parent = minimo;
        }
        transplantar(nodo, minimo);
        minimo->izq = nodo->izq;
//        cout << "Luego de transplante, nodo>izq>valor " << nodo -> izq -> valor << endl;
        minimo->izq->parent = minimo;

    }

    delete(nodo);
    _cardinal -= 1;
}

template <class T>
void Conjunto<T>::inorder_tree_walk_search_next(Nodo* nodo, const T& clave) {
    //From Cormen's book
    if(nodo != NULL){
        inorder_tree_walk_search_next(nodo->izq, clave);
        //cout << "Elem: " << (nodo->valor) << endl;
        if(_elQueSigue == NULL && (nodo->valor > clave)){
            _elQueSigue = nodo->valor;
            return;
        }
        inorder_tree_walk_search_next(nodo->der, clave);
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    _elQueSigue = NULL;
    Nodo* nodo = _raiz;
    //cout << "El que sigue a " << clave << endl;
    inorder_tree_walk_search_next(nodo, clave);
    return _elQueSigue;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* nodo = _raiz;
    //From Cormen's book
    while (nodo->izq != NULL){
        nodo = nodo->izq;
    }
    return nodo->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* nodo = _raiz;
    //From Cormen's book
    while (nodo->der != NULL){
        nodo = nodo->der;
    }
    return nodo->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal;
}

template <class T>
void Conjunto<T>::mostrar_inorder(){
    inorder_tree_walk(_raiz);
}

template <class T>
void Conjunto<T>::inorder_tree_walk(Nodo* nodo){
    //From Cormen's book
    if(nodo != NULL){
        inorder_tree_walk(nodo->izq);
        cout << (nodo->valor) << endl;
        inorder_tree_walk(nodo->der);
    }
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    inorder_tree_walk(_raiz);
}

