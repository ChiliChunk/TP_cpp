#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class CPersonne {
      private :
          std::string* id;
          std::string* nom;
          std::string* prenom;
          std::string* mail;
      public :
          CPersonne();
          CPersonne(std::string,std::string,std::string,std::string);
         
          CPersonne(const CPersonne&); // constructeur de copie
          CPersonne(CPersonne&&); // constructeur par 'move'
          CPersonne& operator=(const CPersonne&); // affectation par copie
          CPersonne& operator=(CPersonne&&); // affectation par 'move'

          std::string get_id() const;
          std::string get_nom() const;
          std::string get_prenom() const;
          std::string get_mail() const;

          virtual void affiche();

          void set_id(std::string id);
          void set_nom(std::string nom);
          void set_prenom(std::string prenom);
          void set_mail(std::string mail);

          ~CPersonne();

          friend bool operator==(CPersonne a,CPersonne b);
          friend bool operator<(CPersonne a,CPersonne b);
          friend bool operator>(CPersonne a,CPersonne b);
          friend std::ostream& operator<<(std::ostream& out,CPersonne a);
};

bool operator==(CPersonne a,CPersonne b);
std::ostream& operator<<(std::ostream& out,CPersonne a);
bool operator<(CPersonne a,CPersonne b);
bool operator>(CPersonne a,CPersonne b);

#endif

