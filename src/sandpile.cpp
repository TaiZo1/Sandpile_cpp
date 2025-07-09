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


ostream& operator<<(ostream& o, const Sandpile& S){
    for(int j =0; j<S.n; j++){
        for(int i =0; i<S.m; i++){
            o << S(i,j);
        }
        o << endl;
    }

    return o;
};
