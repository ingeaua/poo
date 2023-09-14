/* 
    Ingeaua Alexandru-Cristian 131 
    Compilator GCC - g++ 11.2.0
    Szmenteanca Eduard-Gabriel 
*/ 

#include <iostream>
#include <vector>
using namespace std;

class exceptiaDrum : public exception {
public:

    virtual const char* what() const throw()
    {
        return "Drumul trebuie sa aiba cel putin un tronson! Va rugam sa reintroduceti valoarea!";
    }

}exceptieTronson;

class exceptiaMea : public exception {
public:

    virtual const char* what() const throw()
    {
        return "Placeholder";
    }

}exceptieStandby;

class IOInterface {
public:

    virtual void afisare(ostream& out) const = 0;
    virtual void citire(istream& in) = 0;

};

class Drum : public IOInterface {
protected:

    string denumire;
    double lungime;
    int nrTronsoane;
    vector <bool> tronsonContractat; /// vector cu 0 daca e liber tronsonul
                                    /// si 1 daca nu este

public:

    virtual double costTronson() = 0;

    double getLungime(){return this->lungime;}
    string getDenumire(){return this->denumire;}

    Drum& operator= (Drum& obj)
    {
        if (this != &obj)
        {
            this->denumire = obj.denumire;
            this->lungime = obj.lungime;
            this->nrTronsoane = obj.lungime;
            this->tronsonContractat = obj.tronsonContractat;
        }

        return *this;
    }

    int getNrTronsoane() {return this->nrTronsoane;}
    bool getEsteTronsonContractat(int i) {return this->tronsonContractat[i];}

    void setTronsonContractat(int i) {this->tronsonContractat[i] = 1;}

    friend ostream& operator<< (ostream & out, const Drum& obj)
    {
        obj.afisare(out);

        return out;
    }

    friend istream& operator>> (istream& in, Drum & obj)
    {
        obj.citire(in);

        return in;
    }

    void afisare(ostream& out) const;
    void citire(istream& in);

    virtual ~Drum() {}



};

void Drum::afisare(ostream& out) const
{
    out << "Denumire drum: " << this->denumire << endl;
    out << "Lungime: " << this->lungime << endl;
    out << "Numar tronsoane: " << this->nrTronsoane << endl;
}

void Drum::citire(istream& in)
{
    cout << "Introduceti denumire drum: ";
    in >> this->denumire;
    cout << "Introduceti lungime drum: ";
    in >> this->lungime;
    int k = 1;
    cout << "Introduceti nume tronsoane: ";
    while (k)
    {
        try
        {
            in >> this->nrTronsoane;
            if (this->nrTronsoane < 1)
            {
                throw exceptieTronson;
            }
            break;
        }
        catch(exception& e)
        {
            cout << e.what() << endl;
        }
        
    }
    for (int i = 0; i < this->nrTronsoane; i++)
    {
        this->tronsonContractat.push_back(0);
    }
}

class DrumNational : public Drum {
private:

    int nrJudete;

public:

    double costTronson();

    DrumNational& operator= (DrumNational& obj)
    {
        if (this != &obj)
        {
            Drum::operator=(obj);
            this->nrJudete = obj.nrJudete;
        }

        return *this;
    }

    void afisare(ostream& out) const;
    void citire(istream& in);


};

double DrumNational::costTronson()
{
    return 3000 * (this->lungime / this->nrTronsoane);
}

void DrumNational::afisare(ostream& out) const
{
    Drum::afisare(out);
    out << "Numar judete: " << this->nrJudete << endl;
}

void DrumNational::citire(istream& in)
{
    Drum::citire(in);
    cout << "Introduceti numar judete: ";
    in >> this->nrJudete;
}

class DrumEuropean : public Drum {
private:

    int nrTari;

public:

    double costTronson();

    DrumEuropean& operator= (DrumEuropean& obj)
    {
        if (this != &obj)
        {
            Drum::operator=(obj);
            this->nrTari = obj.nrTari;
        }

        return *this;
    }

    void afisare(ostream& out) const;
    void citire(istream& in);


};

double DrumEuropean::costTronson()
{
    return 3000 * (this->lungime / this->nrTronsoane) + 500 * (this->nrTari);
}

void DrumEuropean::afisare(ostream& out) const
{
    Drum::afisare(out);
    out << "Numar tari: " << this->nrTari << endl;
}

void DrumEuropean::citire(istream& in)
{
    Drum::citire(in);
    cout << "Introduceti numar tari: ";
    in >> this->nrTari;
}


class Autostrada : public Drum {
private:

    int nrBenzi;

public:

    double costTronson();

    Autostrada& operator= (Autostrada& obj)
    {
        if (this != &obj)
        {
            Drum::operator=(obj);
            this->nrBenzi = obj.nrBenzi;
        }

        return *this;
    }

    void afisare(ostream& out) const;
    void citire(istream& in);


};

double Autostrada::costTronson()
{
    return 2500 * this->nrBenzi * (this->lungime / this->nrTronsoane);
}

void Autostrada::afisare(ostream& out) const
{
    Drum::afisare(out);
    out << "Numar benzi: " << this->nrBenzi << endl;
}

void Autostrada::citire(istream& in)
{
    Drum::citire(in);
    cout << "Introduceti numar benzi: ";
    in >> this->nrBenzi;
}

class Contract : public IOInterface {
private:

    static int cntID;
    const int id;
    string nume;
    string CIF;
    Drum* drumContractat; 
    int nrTronson;

public:

    Contract(): id(cntID++) {}
    void setDrum(Drum* drumContractat) {this->drumContractat = drumContractat;}
    void setTronson(int nrTronson) {this->nrTronson = nrTronson;}
    string getCIF() {return this->CIF;}

    friend ostream& operator<< (ostream & out, const Contract& obj)
    {
        obj.afisare(out);

        return out;
    }

    friend istream& operator>> (istream& in, Contract & obj)
    {
        obj.citire(in);

        return in;
    }

    void afisare(ostream& out) const;
    void citire(istream& in);

};

int Contract::cntID = 1;

void Contract::afisare(ostream& out) const
{
    out << "Id: " << this->id << endl;
    out << "Nume: " << this->nume << endl;
    out << "CIF: " << this->CIF << endl;
    out << "Drum contractat: " << *(this->drumContractat) << endl;
    out << "Tronson: " << this->nrTronson << endl;
}

void Contract::citire(istream& in)
{
    cout << "Introduceti nume contract: ";
    in >> this->nume;
    cout << "Introduceti CIF: ";
    in >> this->CIF;
    //// nr tronson si drum la citire in meniu
}

class Aplicatie {
private:

    static Aplicatie* instanta;
    vector <Contract> listaContracte;
    vector <Drum*> listaDrumuri;
    Aplicatie() = default;
    Aplicatie(Aplicatie&) = delete;

public:

    Aplicatie* getInstanta()
    {
        if (!this->instanta)
        {
            instanta = new Aplicatie();
        }

        return instanta;
    }

    ~Aplicatie()
    {
        for (int i = 0 ; i < this->listaDrumuri.size(); i++)
        {
            delete this->listaDrumuri[i];
        }
        /// vectorul se "sterge" singur ca e din stl
    }

    void startApp();
    void addDrum();
    void printDrumuri();
    void addContract();
    void printContracte();
    void lungimeTot();
    void lungimeAutostrada();
    void deleteContract();
    void calculeazacostTronsonDrum();



};

void Aplicatie::startApp()
{
    int k = 1;
    while (k)
    {
        cout << "------------------------------------" << endl;
        cout << "Bine ati venit, alegeti o optiune!" << endl;
        cout << "1. Cititi un drum" << endl;
        cout << "2. Afisti toate drumurile" << endl;
        cout << "3. Cititi un contract" << endl;
        cout << "4. Afisati toate contractele" << endl;
        cout << "5. Afisati lungime totala drumuri" << endl;
        cout << "6. Afisati lungime totala autostrazi" << endl;
        cout << "7. Sterge contracte cu o firma dupa CIF" << endl;
        cout << "8. Calculeaza costTronson total drum dupa denumire" << endl;
        cout << "9. Iesi din aplicatie" << endl;
        cout << "------------------------------------" << endl;
        int optiune;
        cin >> optiune;
        if (optiune == 1)
        {
            system("CLS");
            addDrum();
            system("CLS");
            cout << "Drumul a fost adaugat cu succes!" << endl << endl;
        }
        else if (optiune == 2)
        {
            printDrumuri();
        }
        else if (optiune == 3)
        {
            system("CLS");
            addContract();
            system("CLS");
            cout << "Contractul a fost adaugat cu succes!" << endl << endl;
        }
        else if (optiune == 4)
        {
            printContracte();
        }
        else if (optiune == 5)
        {
            system("CLS");
            lungimeTot();
        }
        else if (optiune == 6)
        {
            system("CLS");
            lungimeAutostrada();
        }
        else if (optiune == 7)
        {
            system("CLS");
            deleteContract();
        }
        else if (optiune == 8)
        {
            system("CLS");
            calculeazacostTronsonDrum();
        }
        else if (optiune == 9)
        {
            system("CLS");
            break;
            cout << "Multumim ca ne-ati folosit aplicatia!";
        }

    }
}

void Aplicatie::addDrum()
{
    cout << "Alegeti tipul drumului: " << endl;
    cout << "1. Drum national" << endl;
    cout << "2. Drum european" << endl;
    cout << "3. Autostrada" << endl;
    int varianta;
    cin >> varianta;
    if (varianta == 1)
    {
        this->listaDrumuri.push_back(new DrumNational());
    }
    else if (varianta == 2)
    {
        this->listaDrumuri.push_back(new DrumEuropean());

    }
    else if (varianta == 3)
    {
        this->listaDrumuri.push_back(new Autostrada());
    }
    cin >> *(this->listaDrumuri.back());
}

void Aplicatie::printDrumuri()
{
    for (int i = 0; i < this->listaDrumuri.size(); i++)
    {
        cout << "Drumul " << i+1 << ": " << endl;
        cout << *(this->listaDrumuri[i]) << endl;
    }
}

void Aplicatie::addContract()
{
    Contract aux;
    cin >> aux;

    cout << "Alegeti drumul pentru care faceti contractul : " << endl;
    for (int i = 0; i < this->listaDrumuri.size(); i++)
    {
        cout << i+1 << ". " << *(this->listaDrumuri[i]) << endl;
    }

    try
    {
        int varianta;
        cin >> varianta;
        varianta--;
        cout << "Introduceti tronson: ";
        int tronson;
        cin >> tronson;
        tronson--;
        if (this->listaDrumuri[varianta]->getEsteTronsonContractat(tronson))
        {
            throw -1;
        }

        this->listaDrumuri[varianta]->setTronsonContractat(tronson);
        aux.setDrum(this->listaDrumuri[varianta]);
        aux.setTronson(tronson);
        this->listaContracte.push_back(aux);

    }
    catch(exception& e)
    {
        cout << "Adauagarea nu s-a realizat deoarece tronsonul este deja contractat!" << endl << endl;

    }

}

void Aplicatie::printContracte()
{
    for (int i = 0; i < this->listaContracte.size(); i++)
    {
        cout << "Contract " << i+1 << ": " << endl;
        cout << this->listaContracte[i] << endl;
    }
}

void Aplicatie::lungimeTot()
{
    double lungime = 0;
    for (int i = 0; i < this->listaDrumuri.size(); i++)
    {
        lungime += this->listaDrumuri[i]->getLungime();
    }
    cout << "Lungimea totala a drumurilor este: " << lungime << endl << endl;
}

void Aplicatie::lungimeAutostrada()
{
    double lungime = 0;
    for (int i = 0; i < this->listaDrumuri.size(); i++)
    {
        if (dynamic_cast<Autostrada*>(this->listaDrumuri[i]))
        {
            lungime += this->listaDrumuri[i]->getLungime();
        }
    }
    cout << "Lungimea totala a autostrazilor este: " << lungime << endl << endl;
}

void Aplicatie::deleteContract()
{
    system("CLS");
    cout << "Functionalitate in curs de implementare, va rugam reveniti!" << endl << endl;

    // cout << "Introduceti nume firma: ";
    // string aux;
    // cin >> aux;
    // for (int i = 0; i < this->listaContracte.size(); i++)
    // {
    //     if  (this->listaContracte[i].getCIF() == aux)
    //     {
    //         this->listaContracte.erase(this->listaContracte.begin() + i);
    //     }
    // }
}

void Aplicatie::calculeazacostTronsonDrum()
{
    double cost = 0;
    cout << "Introduceti nume drum: ";
    string aux;
    cin >> aux;
    for (int i = 0; i < this->listaDrumuri.size(); i++)
    {
        if (this->listaDrumuri[i]->getDenumire() == aux)
        {
            for (int j = 0; j < this->listaContracte.size(); j++)
            {
                /// aici teoretic ar trebui sa verific daca drumu din contract e acelasi cu this->listadrumuri[i]
                /// dar lucrand cu pointer daca fac get la drum din contract stric encapsularea
                /// daca ar fi indeplinita conditia de mai sus atunci adaugam in variabila cost
                /// this->listaDrumuri[i]->cost
            }
        }
        break;
    }

    cout << endl;
    cout << "Costul este: " << cost << endl << endl;
}

Aplicatie* Aplicatie::instanta = nullptr;

int main()
{
    Aplicatie* app;
    app = app->getInstanta();

    try
    {
        app->startApp();
    }
    catch(const std::exception& e)
    {
        system("CLS");
        cout << "S-a produs o eroare fatala, va rugam sa reveniti!";
    }

    delete app;
    


    return 0;
}