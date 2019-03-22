#include <iostream>


class CPersonne{
    std::string *nom, *prenom, *mail, *id;
    public:
        CPersonne();
        CPersonne(std::string,std::string,std::string,std::string);
        CPersonne(const CPersonne&);
        void setNom(std::string);
        void setPrenom(std::string);
        void setMail(std::string);
        void setId(std::string);
        std::string getNom() const;
        std::string getPrenom() const;
        std::string getMail() const;
        std::string getId() const;
        ~CPersonne();
        bool operator==( const CPersonne);
        friend std::ostream& operator<<(std::ostream& , CPersonne&);
        CPersonne& operator=(CPersonne&);
};