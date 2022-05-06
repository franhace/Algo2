using namespace std;
#include "Diccionario.hpp"

template<class T>
class Multiconjunto{
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x);

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
