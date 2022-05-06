#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

// Completar con las funciones del enunciado
// ej1
template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    typename Contenedor::const_iterator it = c.begin();
    typename Contenedor::const_iterator res = c.begin();
    while (it != c.end()){
        if (*it < *res) res = it;
        it++;
    }
    return *res;
}

// ej2
template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    typename Contenedor::const_iterator it = c.begin();
    typename Contenedor::value_type res = 0;
    int tot = 0;
    while (it != c.end()){
        res += *it;
        tot++;
        it++;
    }
    return res/tot;
};

// ej3
template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    Iterator res = desde;
    Iterator dsd = desde;
    while (dsd != hasta){
        if (*dsd < *res) res = dsd;
        dsd++;
    }
    return *res;
}


template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    typename Iterator::value_type res = 0;
    Iterator dsd = desde;
    int tot = 0;
    while (dsd != hasta){
        res += *dsd;
        tot++;
        dsd++;
    }
    return res/tot;
};

// ej 4
template<class Contenedor>
void filtrar(Contenedor& c, const typename Contenedor::value_type& elem) {
    typename Contenedor::iterator it = c.begin();
    while (it != c.end()) {
        if (*it == elem) c.erase(it--);
        it++;
    }
}

// ej 5
template<class Contenedor>
bool ordenado(Contenedor &c){
    typename Contenedor::const_iterator it = c.begin();
    typename Contenedor::const_iterator next = c.begin();
    next++;
    while ( next!= c.end()){
        if (*it>*next ) return false;
        it++;
        next++;
    }
    return true;
};

// ej 6
template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor & c,const typename Contenedor::value_type& elem){
        typename Contenedor::const_iterator it = c.begin();
        Contenedor a;
        Contenedor b;
    while (it!=c.end()){
        if (*it<elem) a.insert(a.end(),*it);
        else b.insert(b.end(),*it);
        it++;
    }
    return std::pair<Contenedor,Contenedor>(a,b);

}

// ej 7
template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res){
    typename Contenedor::const_iterator it_c1 = c1.begin();
    typename Contenedor::const_iterator it_c2 = c2.begin();
    while (it_c1 != c1.end() && it_c2 != c2.end()){
        if (*it_c1 < *it_c2) {
            res.insert(res.end(), *it_c1);
            it_c1++;
        }
        else {
            res.insert(res.end(), *it_c2);
            it_c2++;
        }
    }
    if (it_c1 == c1.end() and it_c2 != c2.end()) {
        while (it_c2 != c2.end()) {
            res.insert(res.end(), *it_c2);
            it_c2++;
        }
    } else {
        while (it_c1 != c1.end()) {
            res.insert(res.end(), *it_c1);
            it_c1++;
        }
    }

};
#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
