ofstream& operator<< (ofstrema& out, Angajat& obj)
{
    out << obj.Nume << endl;
    out << obj.Prenume << endl;
    out << obj.Email << endl;
    out << obj.Salariu << endl;

    return out;
}