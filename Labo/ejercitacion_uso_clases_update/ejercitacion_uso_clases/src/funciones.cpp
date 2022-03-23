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

bool pertenece_set(set<int> s, int n){
    bool res= false;
    for (int i : s) {
        if (i == n){return true;}
    }
    return res;
}

bool pertenece_char(vector<char> s, int n){
    bool res= false;
    for (char i : s) {
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
    vector<int> a;
    for(int & i : s){
        if (cantidad_apariciones(s,i)<2) { a.push_back(i); }
    }
    return vector<int>(a);
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> c;
    for(int x : a){
        if (b.count(x)==1){c.insert(x);}
    }
    return set<int>(c);
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res = map<int, set<int>>(); // TODO: preguntar: al ser un set ya al insertar lo va a hacer 1 sola vez??
    for (int i = 0; i < s.size(); i++) {
        res[(s[i] % 10)].insert(s[i]);
    }
    return res;
}


// Ejercicio 9
char letra_asociada(vector<pair<char,char>> tr, char c){
    for (int i = 0; i < tr.size(); ++i) {
        if (tr[i].first==c){return tr[i].second;}
    }
}

vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> final;
    vector<char> traducibles;
    for(auto & i : tr){
        traducibles.push_back(i.first);
    }
    for(char c : str){
        if (pertenece_char(traducibles,c)){final.push_back(letra_asociada(tr,c));}
        else {final.push_back(c);}

    }
    return vector<char>(final);
}

bool hayInterseccionLU(set<LU> a, set<LU> b) {
    bool res = false;
    for (LU x : a) {
        if (b.count(x) == 1) {
            return true;
        }
    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    bool res = false;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            if (hayInterseccionLU(s[i].libretas(),s[j].libretas()) && s[i].libretas()!=s[j].libretas()){
                return true;
            }
        }
    }
    return res;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> mp;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
                if (s[i].libretas()==s[j].libretas() &&
                    (s[i].adjunto() && s[j].adjunto()) &&
                    s[j].fecha() <= s[i].fecha()){
                    mp[s[i].libretas()] = s[j];
                }
            }
        }
    return map<set<LU>, Mail>(mp);
}
