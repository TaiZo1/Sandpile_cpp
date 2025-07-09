#include "sandpile.hpp"

#include <fstream>
#include <ctime>



int main(){
    mt19937 G(time(nullptr));
    Sandpile s(8,8,5);
    std::cout << "The sand height at (1,1) is " << s(2,1) << std::endl;
    std::cout << "The full configuration is:" << std::endl << s;

    cout << "The number of neighbors of (0,0) is " << s.voisins({0,0}).size() << endl;

    cout << "The number of neighbors of (1,2) is " << s.voisins({1,2}).size() << endl;

    ofstream Fichier("output_stable.txt");

    s.stabil();

    Fichier << s.nb_total_ebouls() << endl;
    Fichier << s;

    Sandpile t(100,100,4);

    t.stabil();

    cout << t << endl;

    t.add_random_grain(G,3);



    return 0;
}
