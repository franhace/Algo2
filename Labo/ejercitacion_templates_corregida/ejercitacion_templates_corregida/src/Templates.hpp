using namespace std;

// ej 1
template<class T>
T cuadrado(T x){
    return x * x;
}

// ej 2
template<class Contenedor, class Elem>
bool contiene(Contenedor a, Elem c) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == c) {
            return true;
        }
    }
    return false;
}

// ej 3
template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){
    if (a.size() >= b.size()) return false;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i]!=b[i]) return false;
    }
    return true;
}

// ej 4
template<class Contendor, class Elem>
Elem maximo(Contendor c){
    Elem maximo = c[0];
    for (int i = 0; i < c.size(); ++i) {
        if (maximo < c[i]) maximo = c[i];
    }
    return maximo;
}

