#include "sandpile.hpp"

Sandpile::Sandpile(int m0, int n0, int k): m(m0), n(n0), terrain(m0*n0,k),
    nb_ebouls(m0*n0,0), next_ebouls(){
        if(k>=4){
            for(int i=0; i<m; i++){
                for(int j =0; j<n; j++){
                    next_ebouls.push_back(upair(i,j));
                }
            }
        }
    };

std::list<upair> Sandpile::voisins(upair p) const {
    std::list<upair> res;
    int i = p.first;
    int j = p.second;
    if (j - 1 >= 0) res.push_back(upair(i, j - 1));
    if (i + 1 <= m - 1) res.push_back(upair(i + 1, j));
    if (j + 1 <= n - 1) res.push_back(upair(i, j + 1));
    if (i - 1 >= 0) res.push_back(upair(i - 1, j));
    return res;
};

void Sandpile::eboul(upair p) {
    if (geth(p) >= 4) {
        nb_ebouls[p.first + m * p.second]++;
        seth(p, geth(p) - 4);
        std::list<upair> liste_voisins = voisins(p);
        for (auto voisin : liste_voisins) {
            incr_and_test(voisin);
        }
    }
};

int Sandpile::stabil() {
    int nb = 0;
    while (!next_ebouls.empty()) {
        upair p = next_ebouls.front();
        eboul(p);
        next_ebouls.pop_front();
        nb++;
    }
    return nb;
};

int Sandpile::nb_total_ebouls() const {
    return std::accumulate(nb_ebouls.begin(), nb_ebouls.end(), 0);
};

int Sandpile::add_random_grain(std::mt19937& G, int k) {
    std::uniform_int_distribution<int> Ui(0, m - 1);
    std::uniform_int_distribution<int> Uj(0, n - 1);

    for (int l = 0; l < k; l++) {
        int i = Ui(G);
        int j = Uj(G);
        upair p = upair(i, j);
        incr_and_test(p);
    }
    return stabil();
};





std::ostream& operator<<(std::ostream& o, const Sandpile& S){
    for(int j =0; j<S.n; j++){
        for(int i =0; i<S.m; i++){
            o << S(i,j);
        }
        o << endl;
    }

    return o;
};
