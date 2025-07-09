#pragma once 

#include <utility>
#include <vector>
#include <list>
#include <iostream>
#include <numeric>
#include <random>


using upair=std::pair<unsigned, unsigned>;

class Sandpile;

std::ostream& operator<<(std::ostream&, const Sandpile&);
Sandpile operator+(const Sandpile&, const Sandpile&);


class Sandpile{
    private:
        unsigned m;
        unsigned n;
        std::vector<unsigned> terrain;
        std::vector<unsigned> nb_ebouls;
        std::list<upair> next_ebouls;

        void incr_and_test(upair p){
            seth(p,geth(p)+1);
            if(geth(p) >= 4){
                next_ebouls.push_back(p);
            }
        }

    public:
        Sandpile(int m0, int n0, int k=4);

    // Accessors

        unsigned operator()(int i, int j) const{
            return terrain[i+j*m];
        }

        unsigned geth(upair p) const{
            return terrain[p.first + (p.second)*m];
        }

        void seth(upair p,unsigned k) {
            terrain[p.first + (p.second)*m] = k;
        }

    // Methods

        std::list<upair> voisins(upair p) const;

        void eboul(upair p);

        int stabil();

        int nb_total_ebouls() const{
            return std::accumulate(nb_ebouls.begin(), nb_ebouls.end(),0);
        }

        int add_random_grain(mt19937& G, int k=1){
            std::uniform_int_distribution<int> Ui(0,m-1);
            std::uniform_int_distribution<int> Uj(0,n-1);


            for(int l = 0; l<k; l++){
                int i = Ui(G);
                int j = Uj(G);
                upair p = upair(i,j);
                incr_and_test(p);
            } 

            return stabil();
        }

    // friend

        friend std::ostream& operator<<(ostream& , const Sandpile&);

        friend Sandpile operator+(const Sandpile& S1, const Sandpile& S2){
            int n = S1.n;
            int m = S1.m;
            Sandpile res(m,n,0);
            for(int i =0; i<m; i++){
                for(int j=0; j<n; j++){
                    res.terrain[i+m*j]= S1.terrain[i+m*j] + S2.terrain[i+m*j];
                }
            }
            res.stabil();
            std::fill(res.nb_ebouls.begin(),res.nb_ebouls.end(),0);
            return res;
        }
}; 
