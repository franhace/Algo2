using namespace std;
#include "Diccionario.hpp"

template<class T>
class Multiconjunto{
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x);
    bool operator<=(Multiconjunto<T> otro);

private:
    Diccionario<T, int> _dicc;
};

template<class T>
Multiconjunto<T>::Multiconjunto(): _dicc() {

}

template<class T>
void Multiconjunto<T>::agregar(T x) {
//    if (_dicc.def(x)) _dicc.definir(x, _dicc.obtener(x)+1);
//    else _dicc.definir(x, 1);
    // lo mismo escrito mas resumido y mas inentendible o entendible?
    _dicc.def(x) ? _dicc.definir(x, _dicc.obtener(x)+1) : _dicc.definir(x, 1);
}

template<class T>
int Multiconjunto<T>::ocurrencias(T x) {
    return _dicc.def(x ) ? _dicc.obtener(x) : 0;
}

template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) {
    bool res = true;
    for (int i = 0; i < _dicc.claves().size(); ++i) {
        if (otro._dicc.def(_dicc.claves()[i])) {
            if (this->ocurrencias((_dicc.claves()[i])) >  otro.ocurrencias((_dicc.claves()[i]))) { return false; }
    }}
    return res;
}