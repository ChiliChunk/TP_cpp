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
                cout << "Id trouvé, suppression en cours ;)\n";
                TNoeud * nodePrec = currentNode->precedent;
                TNoeud * nodeSuiv = currentNode->suivant;
                if (nodePrec == nullptr){
                    list->queue = nodeSuiv;
                }
                if(nodeSuiv == nullptr){
                    list->tete = nodePrec;
                }
                else if (nodePrec != nullptr && nodeSuiv != nullptr){
                    nodePrec->suivant = nodeSuiv;
                    nodeSuiv->precedent = nodePrec;
                }
                return currentNode->contenu;
            }
            else{
                currentNode = currentNode->suivant;
            }
        }
        return nullptr;
    }
    else{
        return nullptr;
    }
}

void afficheList(const TList * list){
    cout << "affichage de la queue a la tete\n";
    if (list->queue == nullptr){
        cout << "aucun element dans la liste";
    }
    else{
        TNoeud * currentNode = list->queue;
        while(currentNode != nullptr){
            affiche(currentNode->contenu);
            currentNode = currentNode->suivant;
        }
    }
}

int main(){
    TList * t = new TList();
    TPersonne * p = new_personne();
    ajoute(t , p);   
    TPersonne * p2 = new_personne();
    ajoute(t , p2);   
    afficheList(t);
    supprime(t,p->id);
    afficheList(t);
}