#include <vector>
#include "algobot.h"
#include <set>
#include <map>

using namespace std;

// Ejercicio 1
bool pertenece(vector<int> s, int n){
    bool res= false;
    for (int i : s) {
        if (i == n){return true;}
    }
    return res;
}

vector<int> quitar_repetidos(vector<int> s) {
    vector<int> final;
    for (int & i : s) {
        if (!pertenece(final,i)){final.push_back(i);}
    }
    return vector<int>(final);
}



// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> r;
    vector<int> res;
    for (int & i : s) {
        r.insert(i);
    }
    for (int j : r) {
        res.push_back(j);
    }
    return vector<int>(res);
}

// Ejercicio 3

int cantidad_apariciones(vector<int> s, int e) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == e) {
            res++;
        }
    }
    return res;
}

bool mismos_elementos(vector<int> a, vector<int> b) {
    bool res = false;
    set<int> a1;
    set<int> b1;
    for (int i : a) {
        a1.insert(i);
    }
    for (int i : b) {
        b1.insert(i);
    }
    if (a1==b1){return true;}
    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    return true;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int,int> res;
    set<int> r;
    vector<int> evaluados;
    for (int i = 0; i < s.size(); ++i) {
        int evaluado = s[i];
        if (!pertenece(evaluados,evaluado)) {
            int apa = cantidad_apariciones(s,evaluado);
            res[s[i]]=apa;
        }
    }
    return map<int, int>(res);
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    return vector<int>();
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    return set<int>();
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    return map<int, set<int>>();
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    return vector<char>();
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    return true;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}
