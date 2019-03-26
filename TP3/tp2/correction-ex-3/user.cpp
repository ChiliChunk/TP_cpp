#include "deriv.h"
#include "../correction-ex-2/list.h"

using namespace std;

int main() {
  
    CPersonne* p2 = new CDeveloppeur("2","Clemente","Gilles","gilles.clemente@test.fr","L3-Info",1);
    CPersonne* p3 = new CDeveloppeur("3","Clemente","Cecile","cecile@test.fr","L3-Info",1);
    
    vector<CPersonne*> v {p2,p3}; 
    CPersonne* p1 = new CManager("1","Trojahn","Cassia","cassia.trojahn@irit.fr",v);
    
    CListe* liste = new CListe(nullptr,nullptr);
    
    liste->ajoute(p1);
    liste->ajoute(p2);
    liste->ajoute(p3);

    liste->affiche();
    
    delete liste; // liberation des ressources dans destructeur de list
    liste = nullptr;

    return 0; 
}
