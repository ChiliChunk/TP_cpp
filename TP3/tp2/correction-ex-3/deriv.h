#ifndef DERIV_H
#define DERIV_H

#include "../correction-ex-1/person.h"
#include <vector>

class CDeveloppeur : public CPersonne {
      std::string projet_en_cours;
      short niveau;
      public :
        CDeveloppeur();
        CDeveloppeur(std::string, std::string, std::string,std::string,std::string, short);
        std::string get_projet() const;
        short get_niveau() const;
        void affiche() override;
        void set_projet(std::string);
        void set_niveau(short);
        ~CDeveloppeur();
};

class CManager : public CPersonne {
      std::vector<CPersonne*> list_developpeurs;
      public :
         CManager(); 
         CManager(std::string,std::string,std::string,std::string,std::vector<CPersonne*>);
         void affiche() override;
         std::vector<CPersonne*> get_developpeurs() const;
         void set_developpeurs(std::vector<CPersonne*>);
         ~CManager();
};

#endif
