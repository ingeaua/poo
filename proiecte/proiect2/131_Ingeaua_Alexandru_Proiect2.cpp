#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class IOInterface{
public:

    virtual void afisare(ostream& out) const = 0;
    virtual void citire(istream& in) = 0;

    virtual void afisare(ofstream& out) const = 0;
    virtual void citire(ifstream& in) = 0;

};

/// --------------------------------
/// --------------------------------
/// --------------------------------

class Utilizator : public IOInterface {
protected:

    string Email;
    string DisplayName;
    string Parola;

public:

    Utilizator();
    Utilizator(string Email, string Parola, string DisplayName);
    Utilizator(const Utilizator& user);

    Utilizator& operator= (const Utilizator& user);

    friend ostream& operator<< (ostream& out, const Utilizator& user);
    friend istream& operator>> (istream& in, Utilizator& user);

    friend ofstream& operator<< (ofstream& out, const Utilizator& user);
    friend ifstream& operator>> (ifstream& in, Utilizator& user);

    virtual void afisare(ostream &out) const;
    virtual void citire(istream &in);

    virtual void afisare(ofstream& out) const;
    virtual void citire(ifstream& in);

    string getDisplayName() const {return this->DisplayName;}
    string getEmail() const {return this->Email;}
    string getParola() const {return this->Parola;}

    void setDisplayName(string DisplayName) {this->DisplayName = DisplayName;}
    void setEmail(string Email) {this->Email = Email;}
    void setParola(string Parola) {this->Parola = Parola;}
    
    virtual int getMinuteAscultate() const = 0;
    virtual int pretAbonamentLunar() = 0;
    virtual int salariuLunar() = 0;
    virtual int getTipCont() const = 0;
    virtual void addAlbum() = 0;
    virtual int getChartSpot() const = 0;

    virtual ~Utilizator() {}

};

Utilizator::Utilizator(){

    this->Email = "ANONIM";
    this->DisplayName = "ANONIM";
    this->Parola = "ANONIM";

}

Utilizator::Utilizator(string Email, string Parola, string DisplayName){

    this->Email = Email;
    this->Parola = Parola;
    this->DisplayName = DisplayName;

}

Utilizator::Utilizator(const Utilizator& user){

    this->Email = user.Email;
    this->Parola = user.Parola;
    this->DisplayName = user.DisplayName;

}

Utilizator& Utilizator::operator= (const Utilizator& user){

    if (this != &user)
    {
        this->Email = user.Email;
        this->Parola = user.Parola;
        this->DisplayName = user.DisplayName;
    }

    return *this;

}

void Utilizator::afisare(ostream& out) const {

    out << "Email: " << this->Email << endl;
    out << "Parola: " << this->Parola << endl;
    out << "Nume utilizator: " << this->DisplayName << endl;
}

void Utilizator::citire(istream& in){
    cout << "Introduceti Email: ";
    in >> this->Email;
    cout << "Introduceti Parola: ";
    in >> this->Parola;
    cout << "Introduceti nume utilizator: ";
    in >> this->DisplayName;
}

ostream& operator<< (ostream& out, const Utilizator& user){

    user.afisare(out);

    return out;

}

istream& operator>> (istream& in, Utilizator& user){

    user.citire(in);

    return in;

}

ofstream& operator<< (ofstream& out, const Utilizator& user) {

    user.afisare(out);

    return out;

}

ifstream& operator>> (ifstream& in, Utilizator& user) {

    user.citire(in);

    return in;
}

void Utilizator::afisare(ofstream& out) const {

    out << this->Email << endl;
    out << this->DisplayName << endl;
    out << this->Parola << endl;

}

void Utilizator::citire(ifstream& in) {

    in >> this->Email;
    in >> this->DisplayName;
    in >> this->Parola;

}

/// --------------------------------
/// --------------------------------
/// --------------------------------

class Melodie : public IOInterface{
private:

    string Nume;
    int Durata;
    string Gen;
    bool Explicit;

public:

    Melodie();
    Melodie(string Nume, int Durata, string Gen, bool Explicit);
    Melodie(const Melodie& copie);

    Melodie& operator= (const Melodie& copie);

    friend ostream& operator<< (ostream& out, const Melodie& song);
    friend istream& operator>> (istream& in, Melodie& song);

    friend ofstream& operator<< (ofstream& out, const Melodie& song);
    friend ifstream& operator>> (ifstream& in, Melodie& song);

    void afisare(ostream& out) const;
    void citire(istream& in);

    void afisare(ofstream& out) const;
    void citire(ifstream& in);

    int getDurata() const {return this->Durata;}
    void setDurata(int Durata) {this->Durata = Durata;}

};

Melodie::Melodie(){

    this->Nume = "ANONIM";
    this->Durata = 0;
    this->Gen = "ANONIM";
    this->Explicit = 0;
}

Melodie::Melodie(string Nume, int Durata, string Gen, bool Explicit){

    this->Nume = Nume;
    this->Durata = Durata;
    this->Gen = Gen;
    this->Explicit = Explicit;
}

Melodie::Melodie(const Melodie& copie){

    this->Nume = copie.Nume;
    this->Durata = copie.Durata;
    this->Gen = copie.Gen;
    this->Explicit = copie.Explicit;
}

Melodie& Melodie::operator= (const Melodie& copie){

    if (this != &copie)
    {
        this->Nume = copie.Nume;
        this->Durata = copie.Durata;
        this->Gen = copie.Gen;
        this->Explicit = copie.Explicit;
    }

    return *this;
}

void Melodie::afisare(ostream& out) const {

    out << "Nume: " << this->Nume << endl;
    out << "Durata: " << this->Durata / 60 << ":";
    (this->Durata % 60 < 10) ? cout << "0" << this->Durata % 60 : cout << this->Durata % 60;
    out << endl <<"Gen: " << this->Gen << endl;
    out << "Explicit: " << this->Explicit;

}

void Melodie::citire(istream& in){

    cout << "Introduceti nume: ";
    in >> this->Nume;
    cout << "Introduceti durata (in secunde): ";
    in >> this->Durata;
    cout << "Introduceti gen: ";
    in >> this->Gen;
    cout << "Este explicita (1/0): ";
    in >> this->Explicit;

}

ostream& operator<< (ostream& out, const Melodie& song){

    song.afisare(out);

    return out;
}

istream& operator>> (istream& in, Melodie& song){

    song.citire(in);

    return in;

}

ofstream& operator<< (ofstream& out, const Melodie& song) {

    song.afisare(out);

    return out;

}

ifstream& operator>> (ifstream& in, Melodie& song) {

    song.citire(in);

    return in;

}

void Melodie::afisare(ofstream& out) const {

    out << this->Nume << endl;
    out << this->Durata << endl;
    out << this->Gen << endl;
    out << this->Explicit << endl;

}

void Melodie::citire(ifstream& in) {

    in >> this->Nume;
    in >> this->Durata;
    in >> this->Gen;
    in >> this->Explicit;

}

/// --------------------------------
/// --------------------------------
/// --------------------------------

class Album : public IOInterface {
private:

    string Nume;
    int NumarMelodii;
    vector <Melodie> ListaMelodii;

public:

    Album();
    Album(string Nume, int NumarMelodii, vector <Melodie> ListaMelodii);
    Album(const Album& album);

    Album& operator= (const Album& album);

    friend ostream& operator<<(ostream& out, const Album& album);
    friend istream& operator>>(istream& in, Album& album);

    friend ofstream& operator<<(ofstream& out, const Album& album);
    friend ifstream& operator>>(ifstream& in, Album& album);

    void afisare(ostream& out) const;
    void citire(istream& in);

    void afisare(ofstream& out) const;
    void citire(ifstream& in);

    int getLungimeAlbum() const;

    void addMelodie();

};

Album::Album(){

    this->Nume = "ANONIM";
    this->NumarMelodii = 0;
}

Album::Album(string Nume, int NumarMelodii, vector <Melodie> ListaMelodii) {

    this->Nume = Nume;
    this->NumarMelodii = NumarMelodii;
    for (int i = 0; i < NumarMelodii; i++)
    {
        this->ListaMelodii[i] = ListaMelodii[i];
    }
}

Album::Album(const Album& album){

    this->Nume = album.Nume;
    this->NumarMelodii = album.NumarMelodii;
    this->ListaMelodii = album.ListaMelodii;

}

Album& Album::operator= (const Album& album){

    if (this != &album)
    {
        this->Nume = album.Nume;
        this->NumarMelodii = album.NumarMelodii;
        this->ListaMelodii.clear();
        for (int i = 0; i < this->NumarMelodii; i++)
        {
            this->ListaMelodii.push_back(album.ListaMelodii[i]);
        }
    }

    return *this;
}

void Album::afisare(ostream& out) const {

    out << "Nume album: " << this->Nume << endl;
    out << "Lista celor " << this->NumarMelodii << " melodii:";
    for (int i = 0; i < NumarMelodii; i++)
    {
        out << endl << endl << i + 1 << ". ";
        out << this->ListaMelodii[i];
    }
    out << endl;

}

void Album::citire(istream& in) {

    cout << "Introduceti nume album: ";
    in >> this->Nume;
    cout << "Introduceti numar melodii: ";
    in >> this->NumarMelodii;
    this->ListaMelodii.clear();
    for (int i = 0; i < NumarMelodii; i++)
    {
        Melodie aux;
        cout << endl << "Melodia " << i+1 << ":" << endl;
        cin >> aux;
        this->ListaMelodii.push_back(aux);
    }

}


ostream& operator<< (ostream& out, const Album& album){

    album.afisare(out);

    return out;

}

istream& operator>> (istream& in, Album& album){

    album.citire(in);

    return in;

}

ofstream& operator<<(ofstream& out, const Album& album){

    album.afisare(out);

    return out;

}

ifstream& operator>>(ifstream& in, Album& album) {

    album.citire(in);

    return in;

}

void Album::afisare(ofstream& out) const {

    out << this->Nume << endl;
    out << this->NumarMelodii << endl;
    for (int i = 0; i < NumarMelodii; i++)
    {
        out << this->ListaMelodii[i];
    }

}

void Album::citire(ifstream& in) {

    in >> this->Nume;
    in >> this->NumarMelodii;
    this->ListaMelodii.clear();
    for (int i = 0; i < this->NumarMelodii; i++)
    {
        Melodie aux;
        in >> aux;
        this->ListaMelodii.push_back(aux);
    }

}

int Album::getLungimeAlbum() const {

    int lungime = 0;

    for (int i = 0; i < this->NumarMelodii; i++)
    {
        lungime += this->ListaMelodii[i].getDurata();
    }

    return lungime;
}

void Album::addMelodie() {

    Melodie Aux;
    cin >> Aux;
    this->ListaMelodii.push_back(Aux);
    this->NumarMelodii++;

}

/// --------------------------------
/// --------------------------------
/// --------------------------------

class Artist : virtual public Utilizator {
protected:

    int NumarUrmaritori;
    int AscultatoriLunari;
    int NumarAlbume;
    vector <Album> ListaAlbume;
    const int TipCont = 2;

public:

    Artist();
    Artist(string Email, string Parola, string DisplayName,
    int NumarUrmaritori, int AscultatoriLunari, int NumarAlbume, vector <Album> ListaAlbume);
    Artist(const Artist& artist);
    Artist& operator= (const Artist& artist);

    void afisare(ostream& out) const;
    void citire(istream& in);

    void afisare(ofstream& out) const;
    void citire(ifstream& in);

    void addAlbum();

    int getTipCont() const {return this->TipCont;}

    int pretAbonamentLunar();
    int salariuLunar();
    int getMinuteAscultate() const {return -1;}
    int getChartSpot() const {return -1;}

    virtual ~Artist() {}

    /// nu avem << si >> pentru ca sunt mosteniste de la utilizator si cand il apelezi se duce pe ele si dupa apeleaza afisare care e virtuala si apoi
    /// merge in jos pana la afisarea din obiectu de tip curent si apoi aia se apeleaza (same la citire)

};

Artist::Artist(){

    this->NumarUrmaritori = 0;
    this->AscultatoriLunari = 0;
    this->NumarAlbume = 0;
}

Artist::Artist(string Email, string Parola, string DisplayName, int NumarUrmaritori, int AscultatoriLunari, int NumarAlbume, vector <Album> ListaAlbume):
    Utilizator(Email, Parola, DisplayName) {

    this->NumarUrmaritori = NumarUrmaritori;
    this->AscultatoriLunari = AscultatoriLunari;
    this->NumarAlbume = NumarAlbume;
    this->ListaAlbume = ListaAlbume;
}

Artist::Artist(const Artist& artist){

    Utilizator::operator=(artist);
        this->NumarUrmaritori = artist.NumarUrmaritori;
        this->AscultatoriLunari = artist.AscultatoriLunari;
        this->NumarAlbume = artist.NumarAlbume;
        this->ListaAlbume.clear();
        for (int i = 0; i < artist.NumarAlbume; i++)
        {
            ListaAlbume.push_back(artist.ListaAlbume[i]);
        }

}

Artist& Artist::operator= (const Artist& artist) {

    if (this != &artist)
    {
        Utilizator::operator=(artist);
        this->NumarUrmaritori = artist.NumarUrmaritori;
        this->AscultatoriLunari = artist.AscultatoriLunari;
        this->NumarAlbume = artist.NumarAlbume;
        this->ListaAlbume.clear();
        for (int i = 0; i < artist.NumarAlbume; i++)
        {
            ListaAlbume.push_back(artist.ListaAlbume[i]);
        }
    }

    return *this;

}

void Artist::afisare(ostream& out) const {

    Utilizator::afisare(out);
    out << "Numar urmaritori: " << this->NumarUrmaritori << endl;
    out << "Ascultatori lunari: " << this->AscultatoriLunari << endl;
    out << "Artistul are " << this->NumarAlbume << " albume: " << endl;

    for (int i = 0; i < this->NumarAlbume; i++)
    {
        out << endl << i+1 << ". ";
        out << this->ListaAlbume[i];
    }

}

void Artist::citire(istream& in) {

    Utilizator::citire(in);
    cout << "Introduceti numar urmaritori: ";
    in >> this->NumarUrmaritori;
    cout << "Introduceti ascultatori lunari: ";
    in >> this->AscultatoriLunari;
    cout << "Introduceti numar albume: ";
    in >> this->NumarAlbume;
    this->ListaAlbume.clear();
    for (int i = 0; i < this->NumarAlbume; i++)
    {
        cout << endl << i+1 << ". ";
        Album aux;
        in >> aux;
        ListaAlbume.push_back(aux);
    }

}

void Artist::afisare(ofstream& out) const {

    out << this->TipCont << endl;
    Utilizator::afisare(out);
    out << this->NumarUrmaritori << endl;
    out << this->AscultatoriLunari << endl;
    out << this->NumarAlbume << endl;
    for (int i = 0; i < this->NumarAlbume; i++)
    {
        out << this->ListaAlbume[i];
    }

}

void Artist::citire(ifstream& in) {

    Utilizator::citire(in);
    in >> this->NumarUrmaritori;
    in >> this->AscultatoriLunari;
    in >> this->NumarAlbume;
    this->ListaAlbume.clear();
    for (int i = 0; i < this->NumarAlbume; i++)
    {
        Album aux;
        in >> aux;
        ListaAlbume.push_back(aux);
    }

}

void Artist::addAlbum() {

    Album album;
    cin >> album;
    this->ListaAlbume.push_back(album);
    this->NumarAlbume++;

}

int Artist::pretAbonamentLunar(){

    return 10 * this->NumarAlbume + 40;

}

int Artist::salariuLunar() {

    return this->AscultatoriLunari / 40;

}

/// --------------------------------
/// --------------------------------
/// --------------------------------

class Ascultator : virtual public Utilizator {
protected:

    int NumarUrmariri;
    int MinuteAscultate;
    int Varsta;
    const int TipCont = 1;

public:

    Ascultator();
    Ascultator(string Email, string Parola, string DisplayName, int NumarUrmariri, int MinuteAscultate, int Varsta);
    Ascultator(const Ascultator& listener);

    Ascultator& operator= (const Ascultator& listener);

    void afisare(ostream& out) const;
    void citire(istream& in);

    void afisare(ofstream& out) const;
    void citire(ifstream& in);

    int pretAbonamentLunar();
    int salariuLunar();

    int getTipCont() const {return this->TipCont;}
    int getMinuteAscultate() const {return this->MinuteAscultate;}

    void ascultaMelodie(const Melodie& melodie);

    void addAlbum() {};
    int getChartSpot() const {return -1;}

    virtual ~Ascultator() {}

};

Ascultator::Ascultator(): Utilizator() {

    this->NumarUrmariri = 0;
    this->MinuteAscultate = 0;
    this->Varsta = 0;

}

Ascultator::Ascultator(string Email, string Parola, string DisplayName, int NumarUrmariri, int MinuteAscultate, int Varsta):
    Utilizator(Email, Parola, DisplayName) {

    this->NumarUrmariri = NumarUrmariri;
    this->MinuteAscultate = MinuteAscultate;
    this->Varsta = Varsta;

}

Ascultator::Ascultator(const Ascultator& listener):Utilizator(listener) {

    this->NumarUrmariri = listener.NumarUrmariri;
    this->MinuteAscultate = listener.MinuteAscultate;
    this->Varsta = listener.Varsta;

}

Ascultator& Ascultator::operator=(const Ascultator& listener) {

    if (this != &listener)
    {
        Utilizator::operator=(listener);
        this->NumarUrmariri = listener.NumarUrmariri;
        this->MinuteAscultate = listener.MinuteAscultate;
        this->Varsta = listener.Varsta;

    }

    return *this;

}

void Ascultator::afisare(ostream& out) const {

    Utilizator::afisare(out);
    out << "Numar urmariri: " << this->NumarUrmariri << endl;
    out << "Minute ascultate: " << this->MinuteAscultate << endl;
    out << "Varsta: " << this->Varsta << endl;

}

void Ascultator::citire(istream& in) {

    Utilizator::citire(in);
    cout << "Introduceti numar urmariri: ";
    in >> this->NumarUrmariri;
    cout << "Introduceti numar minute ascultate: ";
    in >> this->MinuteAscultate;
    cout << "Introduceti varsta: ";
    in >> this->Varsta;

}

void Ascultator::afisare(ofstream& out) const {

    out << this->TipCont << endl;
    Utilizator::afisare(out);
    out << this->NumarUrmariri << endl;
    out << this->MinuteAscultate << endl;
    out << this->Varsta << endl;

}

void Ascultator::citire(ifstream& in) {

    Utilizator::citire(in);
    in >> this->NumarUrmariri;
    in >> this->MinuteAscultate;
    in >> this->Varsta;

}

int Ascultator::pretAbonamentLunar() {

    return 20;

}

int Ascultator::salariuLunar() {

    return -1;

}

void Ascultator::ascultaMelodie(const Melodie& melodie) {

    this->MinuteAscultate += melodie.getDurata();

}

/// --------------------------------
/// --------------------------------
/// --------------------------------

class PremiumUser: public Artist, public Ascultator {
private:

    int ChartSpot;
    const int TipCont = 3;

public:

    PremiumUser();
    PremiumUser(string Email, string Parola, string DisplayName, int NumarUrmaritori, int AscultatoriLunari, int NumarAlbume, vector <Album> ListaAlbume, int NumarUrmariri, int MinuteAscultate, int Varsta, int ChartSpot);
    PremiumUser(const PremiumUser& auxiliar);
    PremiumUser& operator= (const PremiumUser& auxiliar);

    void afisare(ostream& out) const;
    void citire(istream& in);

    void afisare(ofstream& out) const;
    void citire(ifstream& in);

    int getTipCont() const {return this->TipCont;}

    int pretAbonamentLunar();
    int salariuLunar();
    int getMinuteAscultate() const {return this->MinuteAscultate;}
    int getChartSpot() const {return this->ChartSpot;}

    void addAlbum();

    virtual ~PremiumUser() {}

};

/// se apeleaza baza si apoi parinti in ordinea de la mostenire (prima data baza pt ca e mostenire virtuala)

PremiumUser::PremiumUser() {

    this->ChartSpot = 0;

}

PremiumUser::PremiumUser(string Email, string Parola, string DisplayName, int NumarUrmaritori, int AscultatoriLunari, int NumarAlbume, vector <Album> ListaAlbume,
    int NumarUrmariri, int MinuteAscultate, int Varsta, int ChartSpot):
    Utilizator(Email, Parola, DisplayName),
    Artist(Email, Parola, DisplayName, NumarUrmaritori, AscultatoriLunari, NumarAlbume, ListaAlbume),
    Ascultator(Email, Parola, DisplayName, NumarUrmariri, MinuteAscultate, Varsta){

    this->ChartSpot = ChartSpot;

}

PremiumUser::PremiumUser(const PremiumUser& auxiliar): Utilizator(auxiliar), Artist(auxiliar), Ascultator(auxiliar) {

    this->ChartSpot = auxiliar.ChartSpot;

}

PremiumUser& PremiumUser::operator= (const PremiumUser& auxiliar) {

    if (this != &auxiliar)
    {
        Artist::operator=(auxiliar);
        this->NumarUrmariri = auxiliar.NumarUrmariri;
        this->MinuteAscultate = auxiliar.MinuteAscultate;
        this->Varsta = auxiliar.Varsta;
        this->ChartSpot = auxiliar.ChartSpot;
    }

    return *this;

}

void PremiumUser::afisare(ostream& out) const {

    Artist::afisare(out);
    out << "Numar urmariri: " << this->NumarUrmariri << endl;
    out << "Minute ascultate: " << this->MinuteAscultate << endl;
    out << "Varsta: " << this->Varsta << endl;
    out << "Loc clasament: " << this->ChartSpot << endl;

}

void PremiumUser::citire(istream& in) {

    Artist::citire(in);
    cout << "Introduceti numar urmariri: ";
    in >> this->NumarUrmariri;
    cout << "Introduceti numar minute ascultate: ";
    in >> this->MinuteAscultate;
    cout << "Introduceti varsta: ";
    in >> this->Varsta;
    cout << "Introduceti loc clasament: ";
    in >> this->ChartSpot;

}

void PremiumUser::afisare(ofstream& out) const {

    out << this->TipCont << endl;
    Utilizator::afisare(out);
    out << this->NumarUrmaritori << endl;
    out << this->AscultatoriLunari << endl;
    out << this->NumarAlbume << endl;
    for (int i = 0; i < this->NumarAlbume; i++)
    {
        out << this->ListaAlbume[i];
    }
    out << this->NumarUrmariri << endl;
    out << this->MinuteAscultate << endl;
    out << this->Varsta << endl;
    out << this->ChartSpot << endl;

}

void PremiumUser::citire(ifstream& in) {

    Artist::citire(in);
    in >> this->NumarUrmariri;
    in >> this->MinuteAscultate;
    in >> this->Varsta;
    in >> this->ChartSpot;

}

void PremiumUser::addAlbum() {

    Album album;
    cin >> album;
    this->ListaAlbume.push_back(album);
    this->NumarAlbume++;

}

int PremiumUser::pretAbonamentLunar() {

    return 40 + 15 * this->NumarAlbume;

}

int PremiumUser::salariuLunar() {

    return this->AscultatoriLunari / 30;

}

/// --------------------------------
/// --------------------------------
/// --------------------------------

class Aplicatie {
private:

    vector <Utilizator*> UserList;

public:

    void addUser();
    void printUserList();
    void deleteUser();

    void readData();
    void writeData();

    int getNumarUseri() const;
    string getNumeUser(int i) const;
    string getParolaUser(int i) const;
    string getEmailUser(int i) const;
    int getTipContUser(int i) const;
    int getMinuteAscultateUser(int i) const;
    int getChartSpotUser(int i) const; 

    void setNumeUser(int i, string Nume);
    void setParolaUser(int i, string Parola);
    void setEmailUser(int i, string Email);

    void addAlbumUser(int i);



};

void Aplicatie::addUser()
{
    cout << "Alegeti tipul de cont:" << endl;
    cout << "1. Ascultator" << endl;
    cout << "2. Artist" << endl;
    cout << "3. Utilizator Premium" << endl;
    int k;
    cin >> k;
    if (k == 1) {
        this->UserList.push_back(new Ascultator());
    }
    else if (k == 2) {
        this->UserList.push_back(new Artist());
    }
    else if (k == 3) {
        this->UserList.push_back(new PremiumUser());
    }
    cin >> *(this->UserList.back());

}

void Aplicatie::printUserList() {

    for (int i = 0; i < UserList.size(); i++)
    {
        cout << endl << "Utilizator " << i+1 << ": " << endl << endl;
        cout << *(this->UserList[i]) << endl << "----------------------" << endl;
    }

}

void Aplicatie::deleteUser() {

    cout << "Alegeti userul care sa fie sters" << endl;
    for (int i = 0; i < this->getNumarUseri(); i++)
    {
        cout << i+1 << ". " << this->getNumeUser(i) << endl;
    }
    int indexUser;
    cin >> indexUser;
    indexUser--;
    if (0 <= indexUser && indexUser < this->getNumarUseri())
    {
        delete this->UserList[indexUser];
        this->UserList.erase(this->UserList.begin() + indexUser);
    }
    else
    {
        system("CLS");
        cout << "Index invalid" << endl << endl;
    }

}

void Aplicatie::readData() {

    ifstream fin;
    fin.open("dateUtilizatori.txt");
    int nrConturi;
    fin >> nrConturi;
    for (int i = 0; i < nrConturi; i++)
    {
        int accType;
        fin >> accType;
        if (accType == 1) {
            this->UserList.push_back(new Ascultator());
        }
        else if (accType == 2) {
            this->UserList.push_back(new Artist());
        }
        else if (accType == 3) {
            this->UserList.push_back(new PremiumUser());
        }
        fin >> *(this->UserList.back());
    }

    fin.close();

}

void Aplicatie::writeData() {

    ofstream fout;
    fout.open("dateUtilizatori.txt");
    fout << this->UserList.size() << endl;
    for (int i = 0; i < this->UserList.size(); i++)
    {
        fout << *(this->UserList[i]);
    }

    fout.close();

}

int Aplicatie::getNumarUseri() const {return this->UserList.size();}

string Aplicatie::getNumeUser(int i) const {return this->UserList[i]->getDisplayName();}

string Aplicatie::getParolaUser(int i) const {return this->UserList[i]->getParola();}

string Aplicatie::getEmailUser(int i) const {return this->UserList[i]->getEmail();}

int Aplicatie::getTipContUser(int i) const {return this->UserList[i]->getTipCont();}

void Aplicatie::setNumeUser(int i, string Nume) {this->UserList[i]->setDisplayName(Nume);}

void Aplicatie::setEmailUser(int i, string Email) {this->UserList[i]->setEmail(Email);}

void Aplicatie::setParolaUser(int i, string Parola) {this->UserList[i]->setParola(Parola);}

int Aplicatie::getMinuteAscultateUser(int i) const {return this->UserList[i]->getMinuteAscultate();}

void Aplicatie::addAlbumUser(int i) {this->UserList[i]->addAlbum();}

int Aplicatie::getChartSpotUser(int i) const {return this->UserList[i]->getChartSpot();}

/// --------------------------------
/// --------------------------------
/// --------------------------------

int main()
{
    Aplicatie app;

    app.readData();

    int k1 = 1;
    while (k1) {

        cout << "Bine ati venit! Alegeti o actiune." << endl;
        cout << "1. Login" << endl;
        cout << "2. Create" << endl;
        cout << "3. Admin" << endl;
        cout << "0. Exit" << endl;
        int comanda1;
        cin >> comanda1;
        if (comanda1 == 1)
        {
            system("CLS");
            cout << "Alegeti un cont:" << endl;
            for (int i = 0; i < app.getNumarUseri(); i++)
            {
                cout << i+1 << ". " << app.getNumeUser(i) << endl;
            }
            int indexUser;
            cin >> indexUser;
            indexUser--;
            if (0 <= indexUser && indexUser < app.getNumarUseri())
            {
                
                system("CLS");
                string mail, parola;
                cout << "Introduceti email: ";
                cin >> mail;
                cout << "Introduceti parola: ";
                cin >> parola;
                if (mail == app.getEmailUser(indexUser) && parola == app.getParolaUser(indexUser))
                {
                    system("CLS");
                    cout << "Autentificare cu succes" << endl << endl;
                    int currentAccType = app.getTipContUser(indexUser);
                    int k2 = 1;
                    while (k2)
                    {
                        cout << "Alege o optiune:" << endl << endl;
                        cout << "1. Schimba nume" << endl;
                        cout << "2. Schimba parola" << endl;
                        cout << "3. Schimba email" << endl;
                        if (currentAccType == 1)
                        {
                            cout << "4. Afiseaza minute ascultate" << endl;         
                        }
                        else if (currentAccType == 2)
                        {
                            cout << "4. Adauga album" << endl;
                        }
                        else
                        {
                            cout << "4. Afiseaza minute ascultate" << endl;
                            cout << "5. Adauga album" << endl;
                            cout << "6. Afiseaza loc clasament" << endl;  
                        }
                        cout << "0. Exit" << endl;
                        int comanda2;
                        cin >> comanda2;
                        system("CLS");
                        if (comanda2 == 1)
                        {
                            cout << "Introduceti noul nume: ";
                            string nume;
                            cin >> nume;
                            app.setNumeUser(indexUser, nume);
                        }
                        else if (comanda2 == 2)
                        {
                            cout << "Introduceti noua parola: ";
                            string parola;
                            cin >> parola;
                            app.setParolaUser(indexUser, parola);
                        }
                        else if (comanda2 == 3)
                        {
                            cout << "Introduceti noul email: ";
                            string email;
                            cin >> email;
                            app.setEmailUser(indexUser, email);
                        }
                        else if (comanda2 == 4 && (currentAccType == 1 || currentAccType == 3))
                        {
                            cout <<"Minute ascultate: " << app.getMinuteAscultateUser(indexUser) << endl << endl;
                        }
                        else if ((comanda2 == 4 && currentAccType == 2) || (comanda2== 5 && currentAccType == 3))
                        {
                            app.addAlbumUser(indexUser);
                            system("CLS");
                            cout << "Album adaugat cu succes" << endl << endl;
                        }
                        else if (comanda2 == 6 && currentAccType == 3)
                        {
                            cout << "Loc clasament: " << app.getChartSpotUser(indexUser) << endl << endl;
                        }
                        else if (comanda2 == 0)
                        {
                            k2 = 0;
                        }
                        else {

                            system("CLS");
                        }
                    }

                }
                else
                {
                    system("CLS");
                    cout << "Parola sau email gresite" << endl << endl;
                }
            }
            else
            {
                system("CLS");
                cout << "Index invalid" << endl << endl;
            }
            
        }
        else if (comanda1 == 2)
        {
            system("CLS");
            app.addUser();
            system("CLS");
            cout << "Cont adaugat cu succes" << endl << endl;
        }
        else if (comanda1 == 3)
        {
            system("CLS");
            cout << "Introduceti parola pentru modul admin: ";
            string parola;
            cin >> parola;
            if (parola == "admin")
            {
                int k2 = 1;
                system("CLS");
                while (k2)
                {
                    cout << "Alegeti o optiune:" << endl << endl;
                    cout << "1.Afisati lista useri" << endl;
                    cout << "2.Stergeti un utilizator" << endl;
                    cout << "0.Exit" << endl;
                    int comanda2;
                    cin >> comanda2;
                    system("CLS");
                    if (comanda2 == 1)
                    {
                        app.printUserList();
                        cout << endl;
                    }
                    else if (comanda2 == 2)
                    {
                        app.deleteUser();
                    }
                    else if (comanda2 == 0)
                    {
                        k2 = 0;
                    }
                }
            }
        
        }
        else if(comanda1 == 0)
        {
            k1 = 0;
        }
        else
        {
            system("CLS");
        }
    }


    app.writeData();

    return 0;
}
