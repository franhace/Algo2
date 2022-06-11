#include "string_map.h"

template <typename T>
string_map<T>::string_map() : _size(0){
    // COMPLETAR
    _raiz = new Nodo;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.


template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // COMPLETAR
    borrar_sigs(_raiz);
    delete(_raiz->definicion);

    for(const string key : keys(d._raiz, "")){
        pair<string, T> elem;
        elem.first = key;
        elem.second = d.at(key);
        insert(elem);
    }
    return *this;
}

template <typename T>
set<string> string_map<T>::keys() {
    const set<string> keys = keys(_raiz, "");
    return keys;
}

template <typename T>
set<string> string_map<T>::keys(Nodo* actual, string key) {
    set<string> out;
    int i = 0;
    string c;
    if(actual->definicion != nullptr){
        out.insert(key);
    }

    for(Nodo* sig : actual->siguientes){
        if(sig != nullptr){
            c = char(i);
            for(string key : keys(sig, key + c)){
                out.insert(key);
            }
        }
        i++;
    }
    return out;
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
    borrar_sigs(_raiz);
    delete(_raiz);
}

template<typename T>
string_map<T>::Nodo::~Nodo() {
    delete(definicion);
    definicion = nullptr;
    int tam = siguientes.size();
    for(int i=0; i<tam; i++){
        if(siguientes[i] != nullptr){
            siguientes[i] = nullptr;
        }
    }

}

template <typename T>
T& string_map<T>::operator[](const string& key){
    // COMPLETAR
    if (!count(key)){
        insert(make_pair(key, T()));
    }
    return at(key);
}


template <typename T>
int string_map<T>::count(const string& key) const{
    // COMPLETAR
    Nodo* actual = _raiz;
    for(char i : key){
        int j = int(i);
        if((actual->siguientes)[j] == nullptr){
            return 0;
        }
        else{
            actual = actual->siguientes[j];
        }
    }
    if(actual->definicion == nullptr){
        return 0;
    }
    else{
        return 1;
    }

}

template <typename T>
const T& string_map<T>::at(const string& key) const {
    // COMPLETAR
    Nodo* actual = _raiz;
    for(char i : key){
        int j = int(i);
        actual = actual->siguientes[j];
    }
    return *(actual->definicion);
}

template <typename T>
T& string_map<T>::at(const string& key) {
    // COMPLETAR
    Nodo* actual = _raiz;
    int j;
    for(char i : key){
        j = int(i);
        actual = actual->siguientes[j];
    }
    return *(actual->definicion);
}

template<typename T>
void string_map<T>::insert(const pair<string, T> &tupla) {
    // COMPLETAR
    string key = tupla.first;
    T valor = tupla.second;
    Nodo* actual = _raiz;
    for(char i : key){
        int j = int(i);
        if(actual->siguientes[j] == nullptr){
            actual->siguientes[j] = new Nodo();
        }
        actual = actual->siguientes[j];
    }
    if(actual->definicion == nullptr){
        _size+=1;
    }else{
        delete(actual->definicion);
    }
    actual->definicion = new T(valor);
}

template <typename T>
void string_map<T>::borrar_sigs(Nodo* actual) {
    // COMPLETAR
    for(Nodo* sig : actual->siguientes){
        if(sig != nullptr){
            borrar_sigs(sig);
            delete(sig);
        }
    }
}

template <typename T>
void string_map<T>::erase(const string& key) {
    // COMPLETAR
    Nodo* actual = _raiz;
    Nodo* prev;
    bool actual_sin_sig, prev_sin_sig;
    bool sin_def;
    int j;
    for(char i : key){
        j = int(i);
        prev = actual;
        actual = actual->siguientes[j];
    }

    actual_sin_sig = true;
    for(Nodo* sig : actual->siguientes){
        if(sig != nullptr){
            actual_sin_sig = false;
        }
    }
    if(actual->definicion != nullptr) {
        _size -= 1;
    }
    if(actual == _raiz){
        // do nothing
    }
    else{
        sin_def = true;
        sin_def = prev->definicion == nullptr;
        if(sin_def){
            prev_sin_sig = true;
            for(Nodo* sig : prev->siguientes){
                if(sig != nullptr && sig != actual){
                    prev_sin_sig = false;
                }
            }
            if(prev_sin_sig && actual != _raiz){
                erase(key.substr(0, key.size() - 1));

            }
        }
        if(actual_sin_sig){
            (prev->siguientes)[j] = nullptr;
            delete(actual);
        }
        else{
            delete(actual->definicion);
            actual->definicion = nullptr;
        }
    }
}

template <typename T>
int string_map<T>::size() const{
    // COMPLETAR
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    // COMPLETAR
    return _size == 0;
}