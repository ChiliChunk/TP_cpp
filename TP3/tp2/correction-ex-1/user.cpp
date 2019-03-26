#include "person.h"

using namespace std;

int main() {

    CPersonne p1 {"1","Trojahn","Cassia","cassia.trojahn@irit.fr"};
    cout << p1 << endl; 
    CPersonne p2 = p1; // constructeur par copie
    cout << p2 << endl;    
   
    CPersonne p3;
    p3 = p1; // affectation par copie par affectation (operator=)
    cout << p3 << endl;
    
    CPersonne p4 = move(CPersonne("2","Arnaud","Marie","marie@cc.fr")); // constructor move
    cout << p4 << endl; 
    
    CPersonne p5;
    p5 = CPersonne("3","Clemente","Gilles","gilles@cc.fr"); // affectation move
    cout << p5 << endl;
    return 0; 
}
