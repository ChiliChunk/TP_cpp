#include <iostream>


class CPersonne{
    std::string *nom, *prenom, *mail, *id;
    public:
        CPersonne();
        CPersonne(std::string,std::string,std::string,std::string);
        void setNom(std::string);
        void setPrenom(std::string);
        void setMail(std::string);
        void setId(std::string);
        std::string getNom() const;
        std::string getPrenom() const;
        std::string getMail() const;
        std::string getId() const;
};