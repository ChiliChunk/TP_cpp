#include "list.hpp"


bool ajoute (TList * list ,TPersonne * pers){
    // add the test on the id here
    if (list->queue != nullptr){
        TNoeud * currentNode = list->queue;
        while (currentNode != nullptr){
            if (currentNode->contenu->id == pers->id){
                cout << "Id déjà présent, annulation\n";
                return false;
            }
            else{
                currentNode = currentNode->suivant;
                cout << "Id différents";
            }
        }
    }

    //init the new node
    TNoeud * noeud = new TNoeud;
    noeud->contenu = pers;

    //add the node in  the list
    if (list->queue == nullptr){ // first element of the list
        list->queue = noeud;
        list->tete = noeud;
    }
    else{
        list->tete->suivant = noeud;
        noeud->precedent = list->tete;
        list->tete = noeud;
    }
    return true;
}

TPersonne * supprime(TList * list , const string id){
    if (list->queue != nullptr){
        TNoeud * currentNode = list->queue;
        while (currentNode != nullptr){
            if (currentNode->contenu->id == id){
                cout << "Id trouvé, supprimement en cours ;)\n";
                if (currentNode->predent == nullptr){ // pas de précédent => MAJ la queue de la list
                    list->queue->currentNode->suivant
                }
                else{
                    currentNode->precedent->suivant = currentNode->suivant
                    currentNode->suivant->precedent = currentNode->precedent
                }
                if (currentNode->suivant == nullptr){ // pas de suivant => MAJ la tete de la list
                    list->tete = currentNode->precedent
                }
            }
            else{
                currentNode = currentNode->suivant;
            }
        }
    }
    else{
        return nullptr
    }
}

int main(){
    TList * t = new TList();
    TPersonne * p = new_personne();
    ajoute(t , p);   
    TPersonne * p2 = new_personne();
    ajoute(t , p2);   
    
}