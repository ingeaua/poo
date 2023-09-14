#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

/// CLASA FILM

/// to do nu facem stergere la constructor

///

class Film{
private:

    string Nume;
    string Categorie;
    string Limba;
    char RatingVarsta;
    int Durata;
    float RatingIMDB;

public:

    /// getters
    string getNume(){return this->Nume;}
    string getCategorie() {return this->Categorie;}
    string getLimba() {return this->Limba;}
    char getRatingVarsta(){return this->RatingVarsta;}
    int getDurata(){return this->Durata;}
    float getRatingIMDB(){return this->RatingIMDB;}

    /// setters
    void setNume(string Nume){this->Nume = Nume;}
    void setCategorie(string Categorie) {this->Categorie = Categorie;}
    void setLimba(string Limba) {this->Limba = Limba;}
    void setRatingVarsta(char RatingVarsta) {this->RatingVarsta = RatingVarsta;}
    void setDurata(int Durata){this->Durata = Durata;}
    void setRatingIMDB(float RatingIMDB){this->RatingIMDB = RatingIMDB;}

    /// constructori & destructor
    Film(string Nume, string Categorie, string Limba, char RatingVarsta, int Durata, float RatingIMDB);
    Film(const Film &obj);
    Film();
    Film(string Categorie, string Limba, char RatingVarsta, int Durata);
    Film(string Categorie, string Limba, int Durata);
    ~Film(){};

    /// supraincarcare =, <<, >>
    Film& operator= (const Film& obj);
    friend ostream& operator<< (ostream& out, const Film& obj);
    friend ofstream& operator<< (ofstream& out, const Film& obj);
    friend istream& operator>> (istream& in, Film& obj);
    friend ifstream& operator>>(ifstream& in, Film& obj);

    /// supraincarcare restul operatorilor

    Film& operator++();  // ++Film
    Film operator++(int);  // Film++

    Film operator+(int a);  // Film + a
    friend Film operator+(int a, Film obj);  // a + Film

    Film operator-(int a);  // Film - a
    friend Film operator-(int a, Film obj);  // a - Film

    operator string();  // cast explicit

    bool operator==(const Film &obj); // op ==

    bool operator<(const Film& obj); // op <

};

/// CLASA SERIE

class Serie{
private:

    string Nume;
    string Categorie;
    string Limba;
    char RatingVarsta;
    int NrSezoane;
    float RatingIMDB;

public:

    /// getters
    string getNume(){return this->Nume;}
    string getCategorie() {return this->Categorie;}
    string getLimba() {return this->Limba;}
    char getRatingVarsta(){return this->RatingVarsta;}
    int getNrSezoane(){return this->NrSezoane;}
    float getRatingIMDB(){return this->RatingIMDB;}

    /// setters
    void setNume(string Nume){this->Nume = Nume;}
    void setCategorie(string Categorie) {this->Categorie = Categorie;}
    void setLimba(string Limba) {this->Limba = Limba;}
    void setRatingVarsta(char RatingVarsta) {this->RatingVarsta = RatingVarsta;}
    void setNrSezoane(int Nrsezoane){this->NrSezoane = NrSezoane;}
    void setRatingIMDB(float RatingIMDB){this->RatingIMDB = RatingIMDB;}

    /// constructori & destructor
    Serie(string Nume, string Categorie, string Limba, char RatingVarsta, int NrSezoane, float RatingIMDB);
    Serie(const Serie &obj);
    Serie();
    Serie(string Categorie, string Limba, char RatingVarsta, int NrSezoane);
    Serie(string Categorie, string Limba, int NrSezoane);
    ~Serie(){};

    /// supraincarcare =, <<, >>
    Serie& operator= (const Serie& obj);
    friend ostream& operator<< (ostream& out, const Serie& obj);
    friend ofstream& operator<< (ofstream& out, const Serie& obj);
    friend istream& operator>> (istream& in, Serie& obj);
    friend ifstream& operator>> (ifstream& im, Serie& obj);

    // supraincarcare restul operatorilor

    Serie& operator++();  // ++Serie
    Serie operator++(int);  // Serie++

    Serie operator+(int a);  // Serie + a
    friend Serie operator+(int a, Serie obj);  // a + Serie

    Serie operator-(int a);  // Serie - a
    friend Serie operator-(int a, Serie obj);  // a - Serie

    operator string();  // cast explicit

    bool operator==(const Serie &obj); // op ==

    bool operator<(const Serie& obj); // op <

};

/// CLASA ANGAJAT

class Angajat{
private:

    static int ContorID;
    const int IDAngajat;
    int Salariu;
    string Nume;
    string Prenume;
    string Email;

public:

    /// getters
    int getIDAngajat(){return this->IDAngajat;}
    string getNume(){return this->Nume;}
    string getEmail(){return this->Email;}
    string getPrenume(){return this->Prenume;}
    int getSalariu(){return this->Salariu;}

    /// setters
    void setEmail(string Email){this->Email = Email;}
    void setNume(string Nume){this->Nume = Nume;}
    void setPrenume(string Prenume){this->Prenume = Prenume;}
    void setSalariu(int Salariu){this->Salariu = Salariu;}


    /// constructori & destructor
    Angajat(int Salariu, string Nume, string Prenume, string Email);
    Angajat(const Angajat &obj);
    Angajat();
    Angajat(string Nume, string Prenume, string Email);
    Angajat(int Salariu, string Nume, string Prenume);
    ~Angajat(){};


    /// supraincarcare =, <<, >>
    Angajat& operator= (const Angajat& obj);
    friend ostream& operator<< (ostream& out, const Angajat& obj);
    friend ofstream& operator<< (ofstream& out, const Angajat& obj);
    friend istream& operator>> (istream& in, Angajat& obj);
    friend ifstream& operator>> (ifstream& in, Angajat& obj);

    // supraincarcare restul operatorilor

    Angajat& operator++();  // ++Angajat
    Angajat operator++(int);  // Angajat++

    Angajat operator+(int a);  // Angajat + a
    friend Angajat operator+(int a, Angajat obj);  // a + Angajat

    Angajat operator-(int a);  // Angajat - a
    friend Angajat operator-(int a, Angajat obj);  // a - Angajat

    operator int();  // cast explicit

    bool operator==(const Angajat &obj); // op ==

    bool operator<(const Angajat& obj); // op <

};

/// CLASA ABONAT

class Abonat{
private:

    static int ContorID;
    const int IDCont;
    char* TipCont;
    int NumarProfiluri;
    string* NumeProfiluri;
    int* MinuteVizionateProfil;
    bool* ProfilCopil;
    string Email;
    string Parola;
    bool ContActiv;

public:

    /// getters
    bool getContActiv(){return this->ContActiv;}
    const int* getMinuteVizionateProfil()const{return this->MinuteVizionateProfil;}
    const char* getTipCont()const{return this->TipCont;}
    string getEmail(){return this->Email;}
    string getParola(){return this->Parola;}
    int getNumarProfiluri(){return this->NumarProfiluri;}
    const string* getNumeProfiluri()const{return this->NumeProfiluri;}
    const bool* getProfilCopil()const{return this->ProfilCopil;}

    /// setters
    void setContActiv(bool ContActiv){this->ContActiv = ContActiv;}
    void setMinuteVizionateProfil(int* MinuteVizionateProfil);
    void setTipCont(char* TipCont);
    void setParola(string Parola){this->Parola = Parola;}
    void setEmail(string Email){this->Email = Email;}
    void setNumarProfiluri(int NumarProfiluri){this->NumarProfiluri = NumarProfiluri;}
    void setNumeProfiluri(string* NumeProfiluri);
    void setProfilCopil(bool* ProfilCopil);

    /// constructori & destructor
    Abonat(char* TipCont, int NumarProfiluri, string* NumeProfiluri, int* MinuteVizionateProfil,
    bool* ProfilCopil, string Email, string Parola, bool ContActiv);
    Abonat(const Abonat& obj);
    Abonat();
    Abonat(char* TipCont, string Email, string Parola, bool ContActiv);
    Abonat(char* TipCont, int NumarProfiluri, string* NumeProfiluri, string Email, string Parola, bool ContActiv);
    ~Abonat();

    /// supraincarcare =, <<, >>
    Abonat& operator=(const Abonat& obj);
    friend ostream& operator<<(ostream& out, const Abonat& obj);
    friend ofstream& operator<<(ofstream& out, const Abonat& obj);
    friend istream& operator>>(istream& in, Abonat& obj);
    friend ifstream& operator>>(ifstream& in, Abonat& obj);

    // supraincarcare restul operatorilor
    string operator[](int i);

    Abonat& operator++();  // ++Abonat
    Abonat operator++(int);  // Abonat++

    Abonat operator+(Film film);  // Abonat + a
    friend Abonat operator+(Film film, Abonat obj);  // a + Abonat

    Abonat operator-(Film film);  // Abonat - a
    friend Abonat operator-(Film film, Abonat obj);  // a - Abonat

    operator int();  // cast explicit

    bool operator==(const Abonat &obj); // op ==

    bool operator<(const Abonat& obj); // op <


};

void Abonat::setMinuteVizionateProfil(int* MinuteVizionateProfil)
{
    if (this->MinuteVizionateProfil != NULL)
    {
        delete[] this->MinuteVizionateProfil;
    }
    this->MinuteVizionateProfil = new int[this->NumarProfiluri];
    for (int i = 0; i < this->NumarProfiluri; i++)
    {
        this->MinuteVizionateProfil[i] = MinuteVizionateProfil[i];
    }

}

void Abonat::setTipCont(char* TipCont)
{
    if (this->TipCont != NULL)
    {
        delete[] this->TipCont;
    }
    this->TipCont = new char[strlen(TipCont)+1];
    strcpy(this->TipCont, TipCont);
}

void Abonat::setNumeProfiluri(string* NumeProfiluri)
{
    if (this->NumeProfiluri != NULL)
    {
        delete[] this->NumeProfiluri;
    }
    this->NumeProfiluri = new string[this->NumarProfiluri];
    for (int i = 0; i < this->NumarProfiluri; i++)
    {
        this->NumeProfiluri[i] = NumeProfiluri[i];
    }
}

void Abonat::setProfilCopil(bool* ProfilCopil)
{
    if (this->ProfilCopil != NULL)
    {
        delete[] this->ProfilCopil;
    }
    this->ProfilCopil = new bool[this->NumarProfiluri];
    for (int i = 0; i < this->NumarProfiluri; i++)
    {
        this->ProfilCopil[i] = ProfilCopil[i];
    }
}


Film::Film(string Nume, string Categorie, string Limba, char RatingVarsta, int Durata, float RatingIMDB)
{
    this->Nume = Nume;
    this->Categorie = Categorie;
    this->Limba = Limba;
    this->RatingVarsta = RatingVarsta;
    this->Durata = Durata;
    this->RatingIMDB = RatingIMDB;
}

Film::Film(const Film &obj)
{
    this->Nume = obj.Nume;
    this->Categorie = obj.Categorie;
    this->Limba = obj.Limba;
    this->RatingVarsta = obj.RatingVarsta;
    this->Durata = obj.Durata;
    this->RatingIMDB = obj.RatingIMDB;
}

Film::Film()
{
    this->Nume = "ANONIM";
    this->Categorie = "NECUNOSCUT";
    this->Limba = "NECUNOSCUT";
    this->RatingVarsta = '-';
    this->Durata = 0;
    this->RatingIMDB = 0.0;
}

Film::Film(string Categorie, string Limba, char RatingVarsta, int Durata)
{
    this->Categorie = Categorie;
    this->Limba = Limba;
    this->RatingVarsta = RatingVarsta;
    this->Durata = Durata;
    this->RatingIMDB = 0.0;
}

Film::Film(string Categorie, string Limba, int Durata)
{
    this->Categorie = Categorie;
    this->Limba = Limba;
    this->RatingVarsta = '-';
    this->Durata = Durata;
    this->RatingIMDB = 0.0;
}

Film& Film::operator= (const Film& obj)
{
    if (this != &obj)
    {
        this->Nume = obj.Nume;
        this->Categorie = obj.Categorie;
        this->Limba = obj.Limba;
        this->RatingVarsta = obj.RatingVarsta;
        this->Durata = obj.Durata;
        this->RatingIMDB = obj.RatingIMDB;
    }

    return *this;
}

ostream& operator<< (ostream& out, const Film& obj)
{
    out << "Nume: " << obj.Nume << endl;
    out << "Categorie: " << obj.Categorie << endl;
    out << "Limba: " << obj.Limba << endl;
    out << "Rating varsta: " << obj.RatingVarsta << endl;
    out << "Durata: " << obj.Durata << " minute" << endl;
    out << "Rating IMDb: " << obj.RatingIMDB << endl;

    return out;
}

istream& operator>> (istream& in, Film& obj)
{
    cout << "Introduceti informatii despre film:" << endl;
    cout << "Nume: ";
    in >> obj.Nume;
    cout << "Categorie: ";
    in >> obj.Categorie;
    cout << "Limba: ";
    in >> obj.Limba;
    cout << "Rating varsta: ";
    in >> obj.RatingVarsta;
    cout << "Durata: ";
    in >> obj.Durata;
    cout << "Rating IMDb: ";
    in >> obj.RatingIMDB;

    return in;
}

ifstream& operator>> (ifstream& in, Film& obj)
{
    in >> obj.Nume;
    in >> obj.Categorie;
    in >> obj.Limba;
    in >> obj.RatingVarsta;
    in >> obj.Durata;
    in >> obj.RatingIMDB;

    return in;
}

ofstream& operator<< (ofstream& out, const Film& obj)
{
    out << obj.Nume << endl;
    out << obj.Categorie << endl;
    out << obj.Limba << endl;
    out << obj.RatingVarsta << endl;
    out << obj.Durata << endl;
    out << obj.RatingIMDB << endl;

    return out;
}

Film& Film::operator++()
{
    this->RatingIMDB += 1.0;
    return *this;
}

Film Film::operator++(int)
{
    Film copie;
    copie = *this;
    this->RatingIMDB += 1.0;

    return copie;
}

Film Film::operator+(int a)
{
    Film copie;
    copie = *this;
    copie.Durata += a;

    return copie;

}

Film operator+(int a, Film obj)
{
    obj.Durata += a;

    return obj;
}

Film Film::operator-(int a)
{
    Film copie;
    copie = *this;
    copie.Durata -= a;

    return copie;
}

Film operator-(int a, Film obj)
{
    obj.Durata -= a;

    return obj;
}

Film::operator string()
{
    return this->Nume;
}

bool Film::operator==(const Film &obj)
{
    return this->Nume == obj.Nume && this->Durata == obj.Durata;
}

bool Film::operator<(const Film& obj)
{
    return this->Durata < obj.Durata;
}

///

Serie::Serie(string Nume, string Categorie, string Limba, char RatingVarsta, int NrSezoane, float RatingIMDB)
{
    this->Nume = Nume;
    this->Categorie = Categorie;
    this->Limba = Limba;
    this->RatingVarsta = RatingVarsta;
    this->NrSezoane = NrSezoane;
    this->RatingIMDB = RatingIMDB;
}

Serie::Serie(const Serie &obj)
{
    this->Nume = obj.Nume;
    this->Categorie = obj.Categorie;
    this->Limba = obj.Limba;
    this->RatingVarsta = obj.RatingVarsta;
    this->NrSezoane = obj.NrSezoane;
    this->RatingIMDB = obj.RatingIMDB;
}

Serie::Serie()
{
    this->Nume = "ANONIM";
    this->Categorie = "NECUNOSCUT";
    this->Limba = "NECUNOSCUT";
    this->RatingVarsta = '-';
    this->NrSezoane = 0;
    this->RatingIMDB = 0.0;
}

Serie::Serie(string Categorie, string Limba, char RatingVarsta, int NrSezoane)
{
    this->Categorie = Categorie;
    this->Limba = Limba;
    this->RatingVarsta = RatingVarsta;
    this->NrSezoane = NrSezoane;
    this->RatingIMDB = 0.0;
}

Serie::Serie(string Categorie, string Limba, int NrSezoane)
{
    this->Categorie = Categorie;
    this->Limba = Limba;
    this->RatingVarsta = '-';
    this->NrSezoane = NrSezoane;
    this->RatingIMDB = 0.0;
}

Serie& Serie::operator= (const Serie& obj)
{
    if (this != &obj)
    {
        this->Nume = obj.Nume;
        this->Categorie = obj.Categorie;
        this->Limba = obj.Limba;
        this->RatingVarsta = obj.RatingVarsta;
        this->NrSezoane = obj.NrSezoane;
        this->RatingIMDB = obj.RatingIMDB;
    }

    return *this;
}

ostream& operator<< (ostream& out, const Serie& obj)
{
    out << "Nume: " << obj.Nume << endl;
    out << "Categorie: " << obj.Categorie << endl;
    out << "Limba: " << obj.Limba << endl;
    out << "Rating varsta: " << obj.RatingVarsta << endl;
    out << "NrSezoane: " << obj.NrSezoane << endl;
    out << "Rating IMDb: " << obj.RatingIMDB << endl;

    return out;
}

istream& operator>> (istream& in, Serie& obj)
{
    cout << "Introduceti informatii despre serie:" << endl;
    cout << "Nume: ";
    in >> obj.Nume;
    cout << "Categorie: ";
    in >> obj.Categorie;
    cout << "Limba: ";
    in >> obj.Limba;
    cout << "Rating varsta: ";
    in >> obj.RatingVarsta;
    cout << "NrSezoane: ";
    in >> obj.NrSezoane;
    cout << "Rating IMDb: ";
    in >> obj.RatingIMDB;

    return in;
}

ifstream& operator>> (ifstream& in, Serie& obj)
{
    in >> obj.Nume;
    in >> obj.Categorie;
    in >> obj.Limba;
    in >> obj.RatingVarsta;
    in >> obj.NrSezoane;
    in >> obj.RatingIMDB;

    return in;
}

ofstream& operator<< (ofstream& out, const Serie& obj)
{
    out << obj.Nume << endl;
    out << obj.Categorie << endl;
    out << obj.Limba << endl;
    out << obj.RatingVarsta << endl;
    out << obj.NrSezoane << endl;
    out << obj.RatingIMDB << endl;

    return out;
}

Serie& Serie::operator++()
{
    this->RatingIMDB += 1.0;
    return *this;
}

Serie Serie::operator++(int)
{
    Serie copie;
    copie = *this;
    this->RatingIMDB += 1.0;

    return copie;
}

Serie Serie::operator+(int a)
{
    Serie copie;
    copie = *this;
    copie.NrSezoane += a;

    return copie;

}

Serie operator+(int a, Serie obj)
{
    obj.NrSezoane += a;

    return obj;
}

Serie Serie::operator-(int a)
{
    Serie copie;
    copie = *this;
    copie.NrSezoane -= a;

    return copie;
}

Serie operator-(int a, Serie obj)
{
    obj.NrSezoane -= a;

    return obj;
}

Serie::operator string()
{
    return this->Nume;
}

bool Serie::operator==(const Serie &obj)
{
    return this->Nume == obj.Nume && this->NrSezoane == obj.NrSezoane;
}

bool Serie::operator<(const Serie& obj)
{
    return this->NrSezoane < obj.NrSezoane;
}

///

Angajat::Angajat(int Salariu, string Nume, string Prenume, string Email):IDAngajat(ContorID++){

    this->Salariu = Salariu;
    this->Nume = Nume;
    this->Prenume = Prenume;
    this->Email = Email;
}

Angajat::Angajat(const Angajat &obj):IDAngajat(ContorID++){

    this->Salariu = obj.Salariu;
    this->Nume = obj.Nume;
    this->Prenume = obj.Prenume;
    this->Email = obj.Email;
}

Angajat::Angajat():IDAngajat(ContorID++){

    this->Salariu = 0;
    this->Nume = "NEINITIALIZAT";
    this->Prenume = "NEINITIALIZAT";
    this->Email = "NEINITIALIZAT";

}

Angajat::Angajat(string Nume, string Prenume, string Email):IDAngajat(ContorID++){

    this->Salariu = 0;
    this->Nume = Nume;
    this->Prenume = Prenume;
    this->Email = Email;
}

Angajat::Angajat(int Salariu, string Nume, string Prenume):IDAngajat(ContorID++){

    this->Salariu = Salariu;
    this->Nume = Nume;
    this->Prenume = Prenume;
    this->Email = "NEINITIALIZAT";
}

Angajat& Angajat::operator=(const Angajat& obj)
{
    if (this != &obj)
    {
        this->Salariu = obj.Salariu;
        this->Nume = obj.Nume;
        this->Prenume = obj.Prenume;
        this->Email = obj.Email;
    }

    return *this;
}

ostream& operator<<(ostream& out, const Angajat& obj)
{
    out << "ID: " << obj.IDAngajat << endl;
    out << "Nume: " << obj.Nume << endl;
    out << "Prenume: " << obj.Prenume << endl;
    out << "Email: " << obj.Email << endl;
    out << "Salariu: " << obj.Salariu << endl;

    return out;
}

istream& operator>>(istream& in, Angajat& obj)
{
    cout << "Introduceti informatii despre angajat:" << endl;
    cout << "Nume: ";
    in >> obj.Nume;
    cout << "Prenume: ";
    in >> obj.Prenume;
    cout << "Email: ";
    in >> obj.Email;
    cout << "Salariu: ";
    in >> obj.Salariu;

    return in;
}

ifstream& operator>>(ifstream& in, Angajat& obj)
{
    in >> obj.Nume;
    in >> obj.Prenume;
    in >> obj.Email;
    in >> obj.Salariu;

    return in;
}

ofstream& operator<< (ofstream& out, const Angajat& obj)
{
    out << obj.Nume << endl;
    out << obj.Prenume << endl;
    out << obj.Email << endl;
    out << obj.Salariu << endl;

    return out;
}

Angajat& Angajat::operator++()
{
    this->Salariu += 100;
    return *this;
}

Angajat Angajat::operator++(int)
{
    Angajat copie;
    copie = *this;
    this->Salariu += 100;

    return copie;
}

Angajat Angajat::operator+(int a)
{
    Angajat copie;
    copie = *this;
    copie.Salariu += a;

    return copie;

}

Angajat operator+(int a, Angajat obj)
{
    obj.Salariu += a;

    return obj;
}

Angajat Angajat::operator-(int a)
{
    Angajat copie;
    copie = *this;
    copie.Salariu -= a;

    return copie;
}

Angajat operator-(int a, Angajat obj)
{
    obj.Salariu -= a;

    return obj;
}

Angajat::operator int()
{
    return this->Salariu;
}

bool Angajat::operator==(const Angajat &obj)
{
    return this->ContorID == obj.ContorID;
}

bool Angajat::operator<(const Angajat& obj)
{
    return this->Salariu < obj.Salariu;
}

///

Abonat::Abonat(char* TipCont, int NumarProfiluri, string* NumeProfiluri, int* MinuteVizionateProfil,
bool* ProfilCopil, string Email, string Parola, bool ContActiv):IDCont(ContorID++){

    this->TipCont = new char[strlen(TipCont)+1];
    strcpy(this->TipCont, TipCont);

    this->NumarProfiluri = NumarProfiluri;

    this->NumeProfiluri = new string[NumarProfiluri];
    for (int i = 0; i < this->NumarProfiluri; i++)
    {
        this->NumeProfiluri[i] = NumeProfiluri[i];
    }

    this->MinuteVizionateProfil = new int[NumarProfiluri];
    for (int i = 0; i < this->NumarProfiluri; i++)
    {
        this->MinuteVizionateProfil[i] = MinuteVizionateProfil[i];
    }

    this->ProfilCopil = new bool[NumarProfiluri];
    for (int i = 0; i < this->NumarProfiluri; i++)
    {
        this->ProfilCopil[i] = ProfilCopil[i];
    }

    this->Email = Email;
    this->Parola = Parola;
    this->ContActiv = ContActiv;

}

Abonat::Abonat(const Abonat& obj):IDCont(ContorID++){

    this->TipCont = new char[strlen(obj.TipCont)+1];
    strcpy(this->TipCont, obj.TipCont);

    this->NumarProfiluri = obj.NumarProfiluri;

    this->NumeProfiluri = new string[obj.NumarProfiluri];
    for (int i = 0; i < this->NumarProfiluri; i++)
    {
        this->NumeProfiluri[i] = obj.NumeProfiluri[i];
    }

    this->MinuteVizionateProfil = new int[obj.NumarProfiluri];
    for (int i = 0; i < this->NumarProfiluri; i++)
    {
        this->MinuteVizionateProfil[i] = obj.MinuteVizionateProfil[i];
    }

    this->ProfilCopil = new bool[obj.NumarProfiluri];
    for (int i = 0; i < this->NumarProfiluri; i++)
    {
        this->ProfilCopil[i] = obj.ProfilCopil[i];
    }

    this->Email = obj.Email;
    this->Parola = obj.Parola;
    this->ContActiv = obj.ContActiv;

}

Abonat::Abonat():IDCont(ContorID++){

    this->TipCont = new char[strlen("NEINITIALIZAT")+1];
    strcpy(this->TipCont, "NEINITIALIZAT");
    this->NumarProfiluri = 1;

    this->NumeProfiluri = new string[1];
    this->NumeProfiluri[0] = "NEINITIALIZAT";

    this->MinuteVizionateProfil = new int[1];
    this->MinuteVizionateProfil[0] = 0;

    this->ProfilCopil = new bool[1];
    this->ProfilCopil[0] = 0;

    this->Email = "NEINITIALIZAT";
    this->Parola = "NEINITIALIZAT";
    this->ContActiv = true;

}

Abonat::Abonat(char* TipCont, string Email, string Parola, bool ContActiv):IDCont(ContorID++){

    this->TipCont = new char[strlen(TipCont)+1];
    strcpy(this->TipCont, TipCont);

    this->Email = Email;
    this->Parola = Parola;
    this->ContActiv = ContActiv;

}

Abonat::Abonat(char* TipCont, int NumarProfiluri, string* NumeProfiluri, string Email, string Parola, bool ContActiv):IDCont(ContorID++){

    this->TipCont = new char[strlen(TipCont)+1];
    strcpy(this->TipCont, TipCont);

    this->NumarProfiluri = NumarProfiluri;

    this->NumeProfiluri = new string[NumarProfiluri];
    for (int i = 0; i < this->NumarProfiluri; i++)
    {
        this->NumeProfiluri[i] = NumeProfiluri[i];
    }

    this->Email = Email;
    this->Parola = Parola;
    this->ContActiv = ContActiv;

}

Abonat::~Abonat()
{
    if (this->TipCont != NULL)
    {
        delete[] this->TipCont;
        this->TipCont = NULL;
    }
    if (this->NumeProfiluri != NULL)
    {
        delete[] this->NumeProfiluri;
        this->NumeProfiluri = NULL;
    }
    if (this->MinuteVizionateProfil != NULL)
    {
        delete[] this->MinuteVizionateProfil;
        this->MinuteVizionateProfil = NULL;
    }
    if (this->ProfilCopil != NULL)
    {
        delete[] this->ProfilCopil;
        this->ProfilCopil = NULL;
    }
}

Abonat& Abonat::operator=(const Abonat& obj)
{
    if (this != &obj)
    {
        if (this->TipCont != NULL)
        {
            delete[] this->TipCont;
            this->TipCont = NULL;
        }
        if (this->NumeProfiluri != NULL)
        {
            delete[] this->NumeProfiluri;
            this->NumeProfiluri = NULL;
        }
        if (this->MinuteVizionateProfil != NULL)
        {
            delete[] this->MinuteVizionateProfil;
            this->MinuteVizionateProfil = NULL;
        }
        if (this->ProfilCopil != NULL)
        {
            delete[] this->ProfilCopil;
            this->ProfilCopil = NULL;
        }

        this->TipCont = new char[strlen(obj.TipCont)+1];
        strcpy(this->TipCont, obj.TipCont);

        this->NumarProfiluri = obj.NumarProfiluri;

        this->NumeProfiluri = new string[obj.NumarProfiluri];
        for (int i = 0; i < this->NumarProfiluri; i++)
        {
            this->NumeProfiluri[i] = obj.NumeProfiluri[i];
        }
        this->MinuteVizionateProfil = new int[obj.NumarProfiluri];
        for (int i = 0; i < this->NumarProfiluri; i++)
        {
            this->MinuteVizionateProfil[i] = obj.MinuteVizionateProfil[i];
        }
        this->ProfilCopil = new bool[obj.NumarProfiluri];
        for (int i = 0; i < this->NumarProfiluri; i++)
        {
            this->ProfilCopil[i] = obj.ProfilCopil[i];
        }

        this->Email = obj.Email;
        this->Parola = obj.Parola;
        this->ContActiv = obj.ContActiv;
    }

    return *this;
}
ostream& operator<<(ostream& out, const Abonat& obj)
{
    out << "Email: " << obj.Email << endl;
    out << "Parola: " << obj.Parola << endl;
    if (obj.ContActiv)
    {
        out << "Contul este activ" << endl;
    }
    else
    {
        out << "Contul nu este activ" << endl;
    }
    out << "ID: " << obj.IDCont << endl;
    out << "Tip cont: " << obj.TipCont << endl;
    out << "Numar Profiluri: " << obj.NumarProfiluri << endl;
    for (int i = 0; i < obj.NumarProfiluri; i++)
    {
        out << endl;
        out << "Nume profil " << i + 1 << ": " << obj.NumeProfiluri[i] << endl;
        out << "Minute vizionate pe profilul " << obj.NumeProfiluri[i] << ": " << obj.MinuteVizionateProfil[i] << endl;
        out << "Profilul " << obj.NumeProfiluri[i];
        if (obj.ProfilCopil[i])
            cout << " este profil copil" << endl;
        else
            out << " este profil adult" << endl;
    }

    return out;
}

istream& operator>>(istream& in, Abonat& obj)
{
    cout << "Introduceti informatii relevante despre cont:" << endl;
    cout << "Introduceti email: ";
    in >> obj.Email;
    cout << "Introduceti parola: ";
    in >> obj.Parola;
    if (obj.TipCont != NULL)
    {
        delete[] obj.TipCont;
    }
    char aux[25];
    cout << "Alegeti tipul contului, optiunile sunt BASIC, STANDARD si PREMIUM: ";
    in >> aux;
    while(aux[0] != 'b' && aux[0] != 'B' && aux[0] != 's' && aux[0] != 'S' && aux[0] != 'p' && aux[0] != 'P')
    {
        cout << "Acest tip de cont nu exista, introduceti o varianta corecta: ";
        in >> aux;
    }
    if (aux[0] == 'b' || aux[0] == 'B')
    {
        obj.TipCont = new char[6];
        strcpy(obj.TipCont,"Basic");
    }
    else if (aux[0] == 's' || aux[0] == 'S')
    {
        obj.TipCont = new char[9];
        strcpy(obj.TipCont,"Standard");
    }
    else if (aux[0] == 'p' || aux[0] == 'P')
    {
        obj.TipCont = new char[8];
        strcpy(obj.TipCont, "Premium");
    }
    cout << "Introduceti numarul de profiluri: ";
    in >> obj.NumarProfiluri;
    if (obj.NumeProfiluri != NULL)
    {
        delete[] obj.NumeProfiluri;
    }
    obj.NumeProfiluri = new string[obj.NumarProfiluri];
    if (obj.MinuteVizionateProfil != NULL)
    {
        delete[] obj.MinuteVizionateProfil;
    }
    obj.MinuteVizionateProfil = new int[obj.NumarProfiluri];
    if (obj.ProfilCopil != NULL)
    {
        delete[] obj.ProfilCopil;
    }
    obj.ProfilCopil = new bool[obj.NumarProfiluri];
    for (int i = 0; i < obj.NumarProfiluri; i++)
    {
        cout << "Introduceti numele profilului " << i + 1 << ": ";
        in >> obj.NumeProfiluri[i];
        obj.MinuteVizionateProfil[i] = 0;
        cout << "Este profilul pentru un copil?(y/n): ";
        char copil;
        in >> copil;
        if (copil == 'y' || copil == 'Y')
        {
            obj.ProfilCopil[i] = 1;
        }
        else
        {
            obj.ProfilCopil[i] = 0;
        }
    }

    return in;
}

ifstream& operator>>(ifstream& in, Abonat& obj)
{
    in >> obj.Email;
    in >> obj.Parola;
    if (obj.TipCont != NULL)
    {
        delete[] obj.TipCont;
    }
    char aux[10];
    in >> aux;
    obj.TipCont = new char[strlen(aux)+1];
    strcpy(obj.TipCont, aux);
    in >> obj.NumarProfiluri;
    if (obj.NumeProfiluri != NULL)
    {
        delete[] obj.NumeProfiluri;
    }
    obj.NumeProfiluri = new string[obj.NumarProfiluri];
    if (obj.MinuteVizionateProfil != NULL)
    {
        delete[] obj.MinuteVizionateProfil;
    }
    obj.MinuteVizionateProfil = new int[obj.NumarProfiluri];
    if (obj.ProfilCopil != NULL)
    {
        delete[] obj.ProfilCopil;
    }
    obj.ProfilCopil = new bool[obj.NumarProfiluri];

    for (int i = 0; i < obj.NumarProfiluri; i++)
    {
        in >> obj.NumeProfiluri[i];
        in >> obj.MinuteVizionateProfil[i];
        in >> obj.ProfilCopil[i];
    }

    return in;
}

ofstream& operator<<(ofstream& out, const Abonat& obj)
{
    out << obj.Email << endl;
    out << obj.Parola << endl;
    out << obj.TipCont << endl;
    out << obj.NumarProfiluri << endl;
    for (int i = 0; i < obj.NumarProfiluri; i++)
    {
        out << obj.NumeProfiluri[i] << endl;
        out << obj.MinuteVizionateProfil[i] << endl;
        out << obj.ProfilCopil[i] << endl;
    }

    return out;
}

string Abonat::operator[](int i)
{
    if (i >= 0 && i < NumarProfiluri)
    {
        return this->NumeProfiluri[i];
    }
    throw runtime_error("index invalid!");

}

Abonat& Abonat::operator++()
{
    for (int i = 0; i < this->NumarProfiluri; i++)
    {
        this->MinuteVizionateProfil[i]++;
    }
    return *this;
}

Abonat Abonat::operator++(int)
{
    Abonat copie;
    copie = *this;
    for (int i = 0; i < this->NumarProfiluri; i++)
    {
        this->MinuteVizionateProfil[i]++;
    }

    return copie;
}

Abonat Abonat::operator+(Film film)
{
    Abonat copie;
    copie = *this;
    for (int i = 0; i < this->NumarProfiluri; i++)
    {
        copie.MinuteVizionateProfil[i] += film.getDurata();
    }

    return copie;

}

Abonat operator+(Film film, Abonat obj)
{
    for (int i = 0; i < obj.NumarProfiluri; i++)
    {
        obj.MinuteVizionateProfil[i] += film.getDurata();
    }

    return obj;
}

Abonat Abonat::operator-(Film film)
{
    Abonat copie;
    copie = *this;
    for (int i = 0; i < this->NumarProfiluri; i++)
    {
        copie.MinuteVizionateProfil[i] -= film.getDurata();
    }

    return copie;
}

Abonat operator-(Film film, Abonat obj)
{
    for (int i = 0; i < obj.NumarProfiluri; i++)
    {
        obj.MinuteVizionateProfil[i] += film.getDurata();
    }

    return obj;
}

Abonat::operator int()
{
    return this->NumarProfiluri;
}

bool Abonat::operator==(const Abonat &obj)
{
    return this->ContorID == obj.ContorID;
}

bool Abonat::operator<(const Abonat& obj)
{
    return this->NumarProfiluri < obj.NumarProfiluri;
}

int Angajat::ContorID = 1;
int Abonat::ContorID = 0;

int main()
{
    Abonat listaConturi[10];
    Angajat listaAngajati[5];
    Film listaFilme[20];
    Serie listaSerii[15];

    ifstream abonatIn;
    abonatIn.open("abonati.txt");
    int cntCont;
    abonatIn >> cntCont;
    for (int i = 0; i < cntCont; i++)
    {
        abonatIn >> listaConturi[i];
    }

    ifstream angajatIn;
    angajatIn.open("angajati.txt");
    int cntAngajat;
    angajatIn >> cntAngajat;
    for (int i = 0; i < cntAngajat; i++)
    {
        angajatIn >> listaAngajati[i];
    }

    ifstream filmIn;
    filmIn.open("filme.txt");
    int cntFilm;
    filmIn >> cntFilm;
    for (int i = 0; i < cntFilm; i++)
    {
        filmIn >> listaFilme[i];
    }

    ifstream serieIn;
    serieIn.open("serii.txt");
    int cntSerie;
    serieIn >> cntSerie;
    for (int i = 0; i < cntSerie; i++)
    {
        serieIn >> listaSerii[i];
    }

    int k = 1;

    while (k == 1)
    {
        cout << "Bine ati venit, alegeti o actiune pentru a continua!";
        int comanda;
        cout << endl << "1-Login";
        cout << endl << "2-Creeaza cont nou";
        cout << endl << "3-Iesi din aplicatie" << endl;
        cin >> comanda;
        system("CLS");
        while (comanda == 1)
        {
            cout << "Alegeti tipul de cont pentru login:" << endl;
            cout << "1-Utilizator" << endl;
            cout << "2-Angajat" << endl;
            cout << "3-Admin" << endl << endl;
            cout << "4-Inapoi la meniu" << endl;
            int comanda2;
            cin >> comanda2;
            if (comanda2 == 1)
            {
                string email, parola;
                system("CLS");
                cout << "Introduceti email-ul: ";
                cin >> email;
                int contActual = -1;
                for (int i = 0; i < cntCont; i++)
                {
                    if (listaConturi[i].getEmail() == email)
                    {
                        contActual = i;
                        break;
                    }
                }
                if (contActual == -1)
                {
                    system("CLS");
                    cout << "Email-ul introdus nu este asociat niciunui cont" << endl << endl;
                    break;
                }
                int incercariRamase = 3;
                bool loggedIn = false;
                while (incercariRamase > 0)
                {
                    cout << "Introduceti parola: ";
                    cin >> parola;
                    if (listaConturi[contActual].getParola() == parola)
                    {
                        loggedIn = true;
                        system("CLS");
                        break;
                    }
                    else
                    {
                        if (incercariRamase == 3)
                        {
                            cout << endl << "Parola este gresita, mai aveti doua incercari." << endl;
                        }
                        else if(incercariRamase == 2)
                        {
                            cout << endl << "Parola este gresita, mai aveti o incercare." << endl;
                        }
                    }
                    incercariRamase--;
                }
                if (loggedIn == false)
                {
                    cout << endl << "Ati gresit parola de 3 ori";
                    cout << endl << "Doriti sa o schimbati?(y/n)";
                    char changePass;
                    cin >> changePass;
                    if (changePass == 'y' || changePass == 'Y')
                    {
                        cout << endl << "Introduceti noua parola: ";
                        string newPass;
                        cin >> newPass;
                        listaConturi[contActual].setParola(newPass);
                        cout << "Parola schimbata cu succes!";
                    }
                    system("CLS");
                    break;

                }
                else
                {
                    system("CLS");
                    cout << "V-ati logat cu succes!" << endl;
                    while (loggedIn)
                    {
                        cout << "Alegeti o actiune pentru a continua!";
                        int comanda3;
                        cout << endl << "1-Schimba datele contului";
                        cout << endl << "2-Afiseaza datele contului";
                        cout << endl << "3-Intra in profil";
                        cout << endl << "4-Creeaza profil nou";
                        cout << endl << "5-Iesi din cont" << endl;
                        cout << endl << "6-Sterge cont" << endl;
                        cin >> comanda3;
                        system("CLS");
                        if (comanda3 == 1)
                        {
                            cout << "Alegeti ce doriti sa schimbati:";
                            cout << endl << "1-Tipul contului";
                            cout << endl << "2-Email";
                            cout << endl << "3-Parola";
                            cout << endl << "4-Anulare" << endl;
                            int comanda4;
                            cin >> comanda4;
                            if (comanda4 == 1)
                            {
                                system("CLS");
                                char aux[25];
                                cout << "Alegeti tipul contului, optiunile sunt BASIC, STANDARD si PREMIUM: ";
                                cin >> aux;
                                while(aux[0] != 'b' && aux[0] != 'B' && aux[0] != 's' && aux[0] != 'S' && aux[0] != 'p' && aux[0] != 'P')
                                {
                                    cout << "Acest tip de cont nu exista, introduceti o varianta corecta: ";
                                    cin >> aux;
                                }
                                if (aux[0] == 'b' || aux[0] == 'B')
                                {
                                    char aux2[] = "Basic";
                                    listaConturi[contActual].setTipCont(aux2);
                                }
                                else if (aux[0] == 's' || aux[0] == 'S')
                                {
                                    char aux2[] = "Standard";
                                    listaConturi[contActual].setTipCont(aux2);
                                }
                                else if (aux[0] == 'p' || aux[0] == 'P')
                                {
                                    char aux2[] = "Premium";
                                    listaConturi[contActual].setTipCont(aux2);
                                }
                                system("CLS");
                                cout << "Tipul contului a fost schimbat cu succes!" << endl;

                            }
                            else if(comanda4 == 2)
                            {
                                system("CLS");
                                string email_nou;
                                cout << "Introduceti noul email: ";
                                cin >> email_nou;
                                listaConturi[contActual].setEmail(email_nou);
                                system("CLS");
                                cout << "Email actualizat cu succes" << endl;
                            }
                            else if(comanda4 == 3)
                            {
                                system("CLS");
                                string parola_nou;
                                cout << "Introduceti noua parola: ";
                                cin >> parola_nou;
                                listaConturi[contActual].setParola(parola_nou);
                                system("CLS");
                                cout << "Parola actualizata cu succes" << endl;
                            }
                            else if(comanda4 == 4)
                            {
                                system("CLS");
                                break;
                            }
                            else
                            {
                                cout << "Comanda introdusa este gresita, va rugam reincercati." << endl << endl;
                            }
                        }
                        else if(comanda3 == 2)
                        {
                            cout << listaConturi[contActual] << endl << endl;
                        }
                        else if(comanda3 == 3)
                        {
                            system("CLS");
                            int numarProfiluri = listaConturi[contActual].getNumarProfiluri();
                            cout << "Alegeti profilul:" << endl;
                            for (int i = 0; i < numarProfiluri; i++)
                            {
                                cout << i+1 << "-" << listaConturi[contActual].getNumeProfiluri()[i] << endl;
                            }
                            int profilActual;
                            cin >> profilActual;
                            profilActual--;
                            system("CLS");
                            bool loggedInProfile = 1;
                            while(loggedInProfile)
                            {
                                cout << "Sunteti pe profilul " << listaConturi[contActual].getNumeProfiluri()[profilActual] << endl;
                                cout << "Alegeti o actiune:" << endl << endl;
                                cout << "1-Alege un film pentru vizionare" << endl;
                                cout << "2-Alege o serie pentru vizionare" << endl << endl;
                                cout << "3-Schimba numele profilului" << endl;
                                cout << "4-Schimba tipul profilului" << endl << endl;
                                cout << "5-Mergi la pagina contului" << endl;
                                int comanda4;
                                cin >> comanda4;

                                if (comanda4 == 1)
                                {
                                    system("CLS");
                                    for (int i = 0; i < cntFilm; i++)
                                    {
                                        cout << i + 1 << "-" << listaFilme[i].getNume() << endl;
                                    }
                                    cout << endl << "Alegeti filmul din lista de mai sus: ";
                                    int filmAles;
                                    cin >> filmAles;
                                    filmAles--;
                                    if (filmAles >= 0 && filmAles < cntFilm)
                                    {
                                        system("CLS");
                                        int* auxMin = new int[listaConturi[contActual].getNumarProfiluri()];
                                        for (int i = 0; i < listaConturi[contActual].getNumarProfiluri(); i++)
                                        {
                                            auxMin[i] = listaConturi[contActual].getMinuteVizionateProfil()[i];
                                        }
                                        auxMin[profilActual] += listaFilme[filmAles].getDurata();
                                        listaConturi[contActual].setMinuteVizionateProfil(auxMin);
                                        cout << "Sper ca filmul v-a placut!" << endl << endl;
                                    }
                                    else
                                    {
                                        system("CLS");
                                        cout << "Film inexistent"<< endl << endl;
                                    }
                                }
                                else if (comanda4 == 2)
                                {
                                    system("CLS");
                                    for (int i = 0; i < cntSerie; i++)
                                    {
                                        cout << i + 1 << "-" << listaSerii[i].getNume() << endl;
                                    }
                                    cout << "Alegeti seria din lista de mai sus: ";
                                    int serieAleasa;
                                    cin >> serieAleasa;
                                    serieAleasa--;
                                    if (serieAleasa >= 0 && serieAleasa < cntSerie)
                                    {
                                        system("CLS");
                                        int* auxMin = new int[listaConturi[contActual].getNumarProfiluri()];
                                        for (int i = 0; i < listaConturi[contActual].getNumarProfiluri(); i++)
                                        {
                                            auxMin[i] = listaConturi[contActual].getMinuteVizionateProfil()[i];
                                        }
                                        auxMin[profilActual] += listaSerii[serieAleasa].getNrSezoane() * 8 * 40; /// deocamdata presupunem ca o serie are 8 ep si 40 min fiecare
                                        listaConturi[contActual].setMinuteVizionateProfil(auxMin);
                                        cout << "Sper ca seria v-a placut!" << endl << endl;
                                    }
                                    else
                                    {
                                        system("CLS");
                                        cout << "Serie inexistenta" << endl << endl;
                                    }
                                }
                                else if (comanda4 == 3)
                                {
                                    system("CLS");
                                    cout << "Introduceti noul nume: ";
                                    string numeNou;
                                    cin >> numeNou;
                                    string* aux = new string[listaConturi[contActual].getNumarProfiluri()];
                                    for (int i = 0; i < listaConturi[contActual].getNumarProfiluri(); i++)
                                    {
                                        aux[i] = listaConturi[contActual].getNumeProfiluri()[i];
                                    }
                                    aux[profilActual] = numeNou;
                                    listaConturi[contActual].setNumeProfiluri(aux);
                                    system("CLS");
                                    cout << "Numele profilului a fost schimbat cu succes!" << endl << endl;

                                }
                                else if (comanda4 == 4)
                                {
                                    bool* aux = new bool[listaConturi[contActual].getNumarProfiluri()];
                                    for (int i = 0; i < listaConturi[contActual].getNumarProfiluri(); i++)
                                    {
                                        aux[i] = listaConturi[contActual].getProfilCopil()[i];
                                    }
                                    aux[profilActual] = !aux[profilActual];
                                    listaConturi[contActual].setProfilCopil(aux);
                                    system("CLS");
                                    cout << "Tipul profilului a fost schimbat cu succes!" << endl << endl;
                                }
                                else if (comanda4 == 5)
                                {
                                    system("CLS");
                                    break;
                                }
                                else
                                {
                                    system("CLS");
                                    cout << "Comanda invalida!" << endl << endl;
                                }

                            }
                        }
                        else if(comanda3 == 4)
                        {
                            int nr_prof = listaConturi[contActual].getNumarProfiluri();
                            string* aux_nume = new string[nr_prof+1];
                            int* aux_minute = new int[nr_prof+1];
                            bool* aux_copil = new bool[nr_prof+1];

                            for (int i = 0; i < nr_prof; i++)
                            {
                                aux_nume[i] = listaConturi[contActual].getNumeProfiluri()[i];
                                aux_minute[i] = listaConturi[contActual].getMinuteVizionateProfil()[i];
                                aux_copil[i] = listaConturi[contActual].getProfilCopil()[i];
                            }

                            cout << "Introduceti numele profilului: ";
                            string nume;
                            cin >> nume;
                            aux_nume[nr_prof] = nume;
                            aux_minute[nr_prof] = 0;
                            cout << endl << "Este profilul pentru un copil?(y/n): ";
                            char copil;
                            cin >> copil;
                            if (copil == 'y' || copil == 'Y')
                            {
                                aux_copil[nr_prof] = 1;
                            }
                            else
                            {
                                aux_copil[nr_prof] = 0;
                            }
                            nr_prof++;
                            listaConturi[contActual].setNumarProfiluri(nr_prof);
                            listaConturi[contActual].setNumeProfiluri(aux_nume);
                            listaConturi[contActual].setMinuteVizionateProfil(aux_minute);
                            listaConturi[contActual].setProfilCopil(aux_copil);
                            system("CLS");
                            cout << "Profilul a fost adaugat cu succes!" << endl << endl;
                        }
                        else if (comanda3 == 5)
                        {
                            break;
                        }
                        else if (comanda3 == 6)
                        {
                            cout << "Sunteti sigur ca doriti sa va stergeti contul?(y/n)" << endl;
                            char varianta;
                            cin >> varianta;
                            system("CLS");
                            if (varianta == 'y')
                            {
                                for (int i = contActual; i < cntCont - 1; i++)
                                {
                                    listaConturi[i] = listaConturi[i+1];
                                }
                                cntCont--;
                                cout << "Contul a fost sters cu succes!" << endl;
                                break;
                            }
                            else
                            {
                                cout << "Ne bucuram ca v-ati razgandit!" << endl << endl;
                            }
                        }
                        else
                        {
                            cout << "Comanda introdusa este gresita, va rugam reincercati." << endl << endl;
                        }

                    }
                }
            }
            else if (comanda2 == 2)
            {
                string email;
                int id;
                system("CLS");
                cout << "Introduceti email-ul: ";
                cin >> email;
                int angajatActual = -1;
                for (int i = 0; i < cntAngajat; i++)
                {
                    if (listaAngajati[i].getEmail() == email)
                    {
                        angajatActual = i;
                        break;
                    }
                }
                if (angajatActual == -1)
                {
                    system("CLS");
                    cout << "Email-ul introdus nu este asociat niciunui angajat!" << endl << endl;
                    break;
                }
                bool workerIn = false;
                cout << "Introduceti-va ID-ul: ";
                cin >> id;
                if (id == listaAngajati[angajatActual].getIDAngajat())
                {
                    system("CLS");
                    cout << "V-ati logat cu succes!";
                    workerIn = true;
                    while (workerIn)
                    {
                        cout << "Alegeti actiunea dorita:" << endl;
                        cout << "1-Afisati informatii" << endl;
                        cout << "2-Schimbare email" << endl;
                        cout << "3-Iesire" << endl << endl;
                        int comanda3;
                        cin >> comanda3;
                        system("CLS");
                        if (comanda3 == 1)
                        {
                            cout << listaAngajati[angajatActual] << endl;
                        }
                        else if (comanda3 == 2)
                        {
                            string email_nou;
                            cout << "Introduceti noul email: ";
                            cin >> email_nou;
                            listaAngajati[angajatActual].setEmail(email_nou);
                            cout << endl;
                            system("CLS");
                            cout << "Email-ul a fost actualizat cu succes!" << endl;
                        }
                        else if(comanda3 == 3)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Comanda invalida" << endl;
                        }
                    }
                }
                else
                {
                    system("CLS");
                    cout << "ID-ul introdus nu este corect!";
                    break;
                }
            }
            else if (comanda2 == 3)
            {
                system("CLS");
                cout << "Introduceti parola: ";
                string parola;
                cin >> parola;
                if  (parola == "admin")
                {
                    bool adminIn = 1;
                    system("CLS");
                    while (adminIn)
                    {
                        cout << "Bine ati venit, rege!" << endl;
                        cout << "Alegeti comanda: " << endl << endl;
                        cout << "1-Afiseaza informatii" << endl;
                        cout << "2-Adauga informatii" << endl;
                        cout << "3-Schimba informatii" << endl;
                        cout << "4-Sterge informatii" << endl << endl;
                        cout << "5-Iesire" << endl << endl;

                        int comanda3;
                        cin >> comanda3;
                        system("CLS");
                        if (comanda3 == 1)
                        {
                            cout << "Alegeti ce informatii doriti sa afisati:" << endl << endl;
                            cout << "1-Angajati" << endl;
                            cout << "2-Abonati" << endl;
                            cout << "3-Filme" << endl;
                            cout << "4-Serii" << endl << endl;
                            int comanda4;
                            cin >> comanda4;
                            system("CLS");
                            int x = 5;
                            if (comanda4 == 1)
                            {
                                system("CLS");
                                for (int i = 0; i < cntAngajat; i++)
                                {
                                    cout << "Angajat " << i+1 << ":" << endl;
                                    cout << "-----" << endl;
                                    cout << listaAngajati[i] << endl;
                                }
                            }
                            else if(comanda4 == 2)
                            {
                                for (int i = 0; i < cntCont; i++)
                                {
                                    cout << "Cont " << i+1 << ":" << endl;
                                    cout << "-----" << endl;
                                    cout << listaConturi[i] << endl;
                                }
                            }
                            else if(comanda4 == 3)
                            {
                                for (int i = 0; i < cntFilm; i++)
                                {
                                    cout << "Film " << i+1 << ":" << endl;
                                    cout << "-----" << endl;
                                    cout << listaFilme[i] << endl;
                                }
                            }
                            else if (comanda4 == 4)
                            {
                                for (int i = 0; i < cntSerie; i++)
                                {
                                    cout << "Serie " << i+1 << ":" << endl;
                                    cout << "-----" << endl;
                                    cout << listaSerii[i] << endl;
                                }
                            }
                            else
                            {
                                cout << "Comanda invalida, va rugam reincercati." << endl << endl;
                            }
                        }
                        else if (comanda3 == 2)
                        {
                            cout << "Alegeti ce informatii doriti sa adaugati:" << endl << endl;
                            cout << "1-Angajat" << endl;
                            cout << "2-Abonat" << endl;
                            cout << "3-Film" << endl;
                            cout << "4-Serie" << endl << endl;
                            int comanda4;
                            cin >> comanda4;
                            system("CLS");
                            if (comanda4 == 1)
                            {
                                cin >> listaAngajati[cntAngajat];
                                cntAngajat++;
                            }
                            else if(comanda4 == 2)
                            {
                                cin >> listaConturi[cntCont];
                                cntCont++;
                            }
                            else if(comanda4 == 3)
                            {
                                cin >> listaFilme[cntFilm];
                                cntFilm++;
                            }
                            else if (comanda4 == 4)
                            {
                                cin >> listaSerii[cntSerie];
                                cntSerie++;
                            }
                            else
                            {
                                cout << "Comanda invalida, va rugam reincercati." << endl << endl;
                            }
                            system("CLS");

                        }
                        else if (comanda3 == 3)
                        {
                            cout << "Alegeti ce informatii doriti sa schimbati:" << endl << endl;
                            cout << "1-Angajati" << endl;
                            cout << "2-Filme" << endl;
                            cout << "3-Serii" << endl << endl;
                            int comanda4;
                            cin >> comanda4;
                            system("CLS");
                            if (comanda4 == 1)
                            {
                                cout << "Alegeti angajatul prin introducerea id-ului." << endl;
                                int angajatCurent = -1, idCautat;
                                for (int i = 0; i < cntAngajat; i++)
                                {
                                    cout << "ID: " << listaAngajati[i].getIDAngajat() << " - ";
                                    cout << listaAngajati[i].getNume() << " " << listaAngajati[i].getPrenume() << endl;
                                }
                                cin >> idCautat;
                                for (int i = 0; i < cntAngajat; i++)
                                {
                                    if (listaAngajati[i].getIDAngajat() == idCautat)
                                    {
                                        angajatCurent = i;
                                        break;
                                    }
                                }
                                if (angajatCurent != -1)
                                {
                                    system("CLS");
                                    cout << "Alegeti ce doriti sa modificati pentru angajatul cu urmatoarele date:" << endl;
                                    cout << listaAngajati[angajatCurent] << endl;
                                    cout << "1-Email" << endl;
                                    cout << "2-Nume" << endl;
                                    cout << "3-Prenume" << endl;
                                    cout << "4-Salariu" << endl << endl;
                                    int comanda5;
                                    cin >> comanda5;
                                    system("CLS");
                                    {
                                        if (comanda5 == 1)
                                        {
                                            cout << "Introduceti noul email: ";
                                            string emailNou;
                                            cin >> emailNou;
                                            listaAngajati[angajatCurent].setEmail(emailNou);
                                        }
                                        else if (comanda5 == 2)
                                        {
                                            cout << "Introduceti noul nume: ";
                                            string numeNou;
                                            cin >> numeNou;
                                            listaAngajati[angajatCurent].setNume(numeNou);
                                        }
                                        else if (comanda5 == 3)
                                        {
                                            cout << "Introduceti noul prenume: ";
                                            string prenumeNou;
                                            cin >> prenumeNou;
                                            listaAngajati[angajatCurent].setPrenume(prenumeNou);
                                        }
                                        else if (comanda5 == 4)
                                        {
                                            cout << "Introduceti noul salariu: ";
                                            int salariuNou;
                                            cin >> salariuNou;
                                            listaAngajati[angajatCurent].setSalariu(salariuNou);
                                        }
                                        else
                                        {
                                            cout << "Comanda invalida, va rugam reincercati." << endl << endl;
                                        }
                                    }
                                }
                                else
                                {
                                    cout << "Angajatul nu exista" << endl << endl;
                                }
                            }
                            else if(comanda4 == 2)
                            {
                                cout << "Alegeti filmul prin introducerea numelui: ";
                                string numeFilm;
                                int filmCurent = -1;
                                cin >> numeFilm;
                                for (int i = 0; i < cntFilm; i++)
                                {
                                    if (listaFilme[i].getNume() == numeFilm)
                                    {
                                        filmCurent = i;
                                        break;
                                    }
                                }
                                if (filmCurent != -1)
                                {
                                    cout << "Alegeti ce doriti sa modificati pentru filmul " << listaFilme[filmCurent].getNume() << ": " << endl;
                                    cout << "1-Rating IMDB" << endl;
                                    cout << "2-Nume film" << endl;
                                    int comanda5;
                                    cin >> comanda5;
                                    if (comanda5 == 1)
                                    {
                                        cout << "Introduceti noul rating: " << endl;
                                        float ratingNou;
                                        cin >> ratingNou;
                                        listaFilme[filmCurent].setRatingIMDB(ratingNou);
                                    }
                                    else if (comanda5 == 2)
                                    {
                                        cout << "Introduceti noul nume: " << endl;
                                        string numeNou;
                                        cin >> numeNou;
                                        listaFilme[filmCurent].setNume(numeNou);
                                    }
                                    else
                                    {
                                        cout << "Comanda invalida, va rugam reincercati." << endl << endl;
                                    }
                                }
                                else
                                {
                                    cout << "Filmul nu exista" << endl << endl;
                                }
                            }
                            else if (comanda4 == 3)
                            {
                                cout << "Alegeti seria prin introducerea numelui: ";
                                string numeSerie;
                                int serieCurenta = -1;
                                cin >> numeSerie;
                                for (int i = 0; i < cntSerie; i++)
                                {
                                    if (listaSerii[i].getNume() == numeSerie)
                                    {
                                        serieCurenta = i;
                                        break;
                                    }
                                }
                                if (serieCurenta != -1)
                                {
                                    cout << "Alegeti ce doriti sa modificati pentru seria " << listaSerii[serieCurenta].getNume() << ": " << endl;
                                    cout << "1-Rating IMDB" << endl;
                                    cout << "2-Numar sezoane" << endl;
                                    cout << "3-Nume" << endl;
                                    int comanda5;
                                    cin >> comanda5;
                                    if (comanda5 == 1)
                                    {
                                        cout << "Introduceti noul rating: " << endl;
                                        float ratingNou;
                                        cin >> ratingNou;
                                        listaSerii[serieCurenta].setRatingIMDB(ratingNou);
                                    }
                                    else if (comanda5 == 2)
                                    {
                                        cout << "Introduceti cate sezoane trebuie adaugate: " << endl;
                                        int nrSezoaneNoi;
                                        cin >> nrSezoaneNoi;
                                        int nrSezoane = nrSezoaneNoi + listaSerii[serieCurenta].getNrSezoane();
                                        listaSerii[serieCurenta].setNrSezoane(nrSezoane);
                                    }
                                    else if (comanda5 == 3)
                                    {
                                        cout << "Introduceti noul nume: ";
                                        string numeNou;
                                        cin >> numeNou;
                                        listaSerii[serieCurenta].setNume(numeNou);
                                    }
                                    else
                                    {
                                        cout << "Comanda invalida, va rugam reincercati." << endl << endl;
                                    }
                                }
                                else
                                {
                                    cout << "Seria nu exista" << endl << endl;
                                }
                            }
                            else
                            {
                                system("CLS");
                                cout << "Comanda invalida, va rugam reincercati." << endl << endl;
                            }
                        }
                        else if(comanda3 == 4)
                        {
                            cout << "Alegeti ce informatii doriti sa stergeti:" << endl << endl;
                            cout << "1-Angajat" << endl;
                            cout << "2-Film" << endl;
                            cout << "3-Serie" << endl << endl;
                            int comanda4;
                            cin >> comanda4;
                            system("CLS");
                            if (comanda4 == 1)
                            {
                                cout << "Alegeti angajatul prin introducerea id-ului." << endl;
                                int angajatCurent = -1, idCautat;
                                for (int i = 0; i < cntAngajat; i++)
                                {
                                    cout << "ID: " << listaAngajati[i].getIDAngajat() << " - ";
                                    cout << listaAngajati[i].getNume() << " " << listaAngajati[i].getPrenume() << endl;
                                }
                                cin >> idCautat;
                                for (int i = 0; i < cntAngajat; i++)
                                {
                                    if (listaAngajati[i].getIDAngajat() == idCautat)
                                    {
                                        angajatCurent = i;
                                        break;
                                    }
                                }
                                if (angajatCurent != -1)
                                {
                                    for (int i = angajatCurent; i < cntAngajat - 1; i++)
                                    {
                                        listaAngajati[i] = listaAngajati[i+1];
                                    }
                                    cntAngajat--;
                                    system("CLS");
                                    cout << "Angajat sters cu succes" << endl << endl;
                                }
                                else
                                {
                                    system("CLS");
                                    cout << "Id invalid" << endl << endl;
                                    break;
                                }
                            }
                            else if(comanda4 == 2)
                            {
                                cout << "Alegeti filmul prin introducerea numelui: ";
                                string numeFilm;
                                int filmCurent = -1;
                                cin >> numeFilm;
                                for (int i = 0; i < cntFilm; i++)
                                {
                                    if (listaFilme[i].getNume() == numeFilm)
                                    {
                                        filmCurent = i;
                                        break;
                                    }
                                }
                                if (filmCurent  != -1)
                                {
                                    for (int i = filmCurent; i < cntFilm; i++)
                                    {
                                        listaFilme[i] = listaFilme[i+1];
                                    }
                                    cntFilm--;
                                    system("CLS");
                                    cout << "Film sters cu succes" << endl << endl;
                                }
                                else
                                {
                                    system("CLS");
                                    cout << "Filmul nu exista" << endl << endl;
                                    break;
                                }
                            }
                            else if(comanda4 == 3)
                            {
                                cout << "Alegeti seria prin introducerea numelui: ";
                                string numeSerie;
                                int serieCurenta = -1;
                                cin >> numeSerie;
                                for (int i = 0; i < cntSerie; i++)
                                {
                                    if (listaSerii[i].getNume() == numeSerie)
                                    {
                                        serieCurenta = i;
                                        break;
                                    }
                                }
                                if (serieCurenta != -1)
                                {
                                    for (int i = serieCurenta; i < cntSerie - 1; i++)
                                    {
                                        listaSerii[i] = listaSerii[i+1];
                                    }
                                    cntSerie--;
                                    system("CLS");
                                    cout << "Serie stearsa cu succes!" << endl << endl;
                                }
                                else
                                {
                                    system("CLS");
                                    cout << "Serie stearsa cu succes" << endl << endl;
                                }
                            }
                            else
                            {
                                system("CLS");
                                cout << "Comanda invalida, va rugam reincercati." << endl << endl;
                            }
                        }
                        else if (comanda3 == 5)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Comanda gresita" << endl << endl;
                        }
                    }
                }
                else
                {
                    system("CLS");
                    cout << "Parola gresita" << endl << endl;
                }
            }
            else if(comanda2 == 4)
            {
                system("CLS");
                break;
            }
            else
            {
                system("CLS");
                cout << "Comanda introdusa este gresita, va rugam reincercati." << endl << endl;
            }
        }
        if (comanda == 2)
        {
            system("CLS");
            cin >> listaConturi[cntCont];
            cout << endl << "Contul a fost creat cu succes" << endl;
            cntCont++;
            system("CLS");
        }
        else if (comanda == 3)
        {
            k = 0;
            system("CLS");
            cout << "Va asteptam inapoi!";
        }
        else if (comanda != 1)
        {
            system("CLS");
            cout << "Comanda introdusa este invalida, va rugam reincercati" << endl;
        }
    }

    ofstream abonatOut;
    abonatOut.open("abonati.txt");
    abonatOut << cntCont << endl;
    for (int i = 0; i < cntCont; i++)
    {
        abonatOut << listaConturi[i];
    }

    ofstream angajatOut;
    angajatOut.open("angajati.txt");
    angajatOut << cntAngajat << endl;
    for (int i = 0; i < cntAngajat; i++)
    {
        angajatOut << listaAngajati[i];
    }

    ofstream filmOut;
    filmOut.open("filme.txt");
    filmOut << cntFilm << endl;
    for (int i = 0; i < cntFilm; i++)
    {
        filmOut << listaFilme[i];
    }

    ofstream serieOut;
    serieOut.open("serii.txt");
    serieOut << cntSerie << endl;
    for (int i = 0; i < cntSerie; i++)
    {
        serieOut << listaSerii[i];
    }

}
