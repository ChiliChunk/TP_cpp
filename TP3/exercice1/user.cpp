#include "list.h"

using namespace std;

int main() {

    CPersonne* p1 = new CPersonne("1","Trojahn","Cassia","cassia.trojahn@irit.fr");
    CPersonne* p2 = new CPersonne("2","Clemente","Gilles","gilles.clemente@test.fr");
    CPersonne* p3 = new CPersonne("3","Clemente","Pierre","pierre@test.fr");

    CListe* list = new CListe(nullptr,nullptr);

    list->ajoute(p1);
    list->ajoute(p2);
    list->ajoute(p3);

    list->affiche();

    CPersonne* pr = list->recherche("2");
    if (pr != nullptr) {
        cout << pr->get_prenom() << endl << endl; 
    }
 
    CPersonne* temp = list->supprime("1");
    delete temp;
    temp = nullptr;
    list->affiche();   

    delete list; // destructeur libere les ressources
    list = nullptr;

    return 0; 
}
