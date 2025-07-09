#include "sandpile.hpp"

#include <fstream>
#include <ctime>



int main(){
    mt19937 G(time(nullptr));
    Sandpile s(8,8,5);
    std::cout << "La hauteur de sable en (1,1) est " << s(2,1) << std::endl;
    std::cout << "La configuration complète est :" << std::endl << s;

    cout << "Le nombre de voisins de (0,0) est " << s.voisins({0,0}).size() << endl;

    cout << "Le nombre de voisins de (1,2) est " << s.voisins({1,2}).size() << endl;

    ofstream Fichier("stab_8x8_5.txt");

    s.stabil();

    Fichier << s.nb_total_ebouls() << endl;
    Fichier << s;

    Sandpile t(100,100,4);

    t.stabil();

    cout << t << endl;

    t.add_random_grain(G,3);



    return 0;
}
