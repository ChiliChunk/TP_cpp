#include "CList.hpp"
using namespace std;       

CList::CList(){
  tete = nullptr;
  queue = nullptr;
}

CList::CList(CNoeud* n1,CNoeud* n2){
  tete = n1;
  queue = n2;
  n1->pred = n2;
  n2->suiv = n1;
  n1->suiv = nullptr;
  n2->pred = nullptr;
}

int main(){
  cout <<"test";
}