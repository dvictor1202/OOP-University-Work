#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <conio.h>
using namespace std;

class Avocat
{
protected:
    int cod, nr_procese;
    string nume;
    int *vector_procese;
    static int nr_avocati;
public:
    //initializare, copiere, destructor
    Avocat(int, int, int*, string);
    Avocat(Avocat&);
    virtual ~Avocat();

    //in/out
    virtual void afisare(ostream &out);
    virtual void citire(istream &in);
    friend istream& operator>>(istream &in, Avocat& x);
    friend ostream& operator<<(ostream &out, Avocat& x);

    static int get_nr_avocati(){return nr_avocati;}
    static void increase_nr_avocati(){nr_avocati++;}

    //operatori
    Avocat& operator=(Avocat &x);
    friend bool operator<(const Avocat x, const Avocat y);
    friend bool operator>(const Avocat x, const Avocat y);
    friend bool operator>=(const Avocat x, const Avocat y);
    friend bool operator<=(const Avocat x, const Avocat y);

};


Avocat::Avocat(int codd = 0, int nr_procesee = 0, int* pntr = NULL, string numee = "")
{
    cod = codd;
    nume = numee;
    nr_procese = nr_procesee;
    vector_procese = pntr;
}
Avocat::Avocat(Avocat &x)
{
    this->cod = x.cod;
    this->nr_procese = x.nr_procese;
    this->nume = x.nume;
    this->vector_procese = x.vector_procese;
}
Avocat::~Avocat()
{
    cod = 0;
    nr_procese = 0;
    nume = "";
    vector_procese = NULL;
}


void Avocat::citire(istream &in)
{
    int varr;
    string varr2;
    cout << "Care este codul?\n";
    in >> cod;
    getline(in, varr2);
    cout << "Care este numele?\n";
    getline(in, nume);
    cout << "Cate procese platite a avut avocatul " << nume << " ?" << endl;
    in >> nr_procese;
    int *vec_procese = new int[nr_procese + 1];
    cout << "Sumele incasate: \n";
    for(int i = 0; i < nr_procese; i++)
        cin >> varr, vec_procese[i] = varr;
    vector_procese = vec_procese;
}
istream& operator>>(istream &in, Avocat &x)
{
    x.citire(in);
    return in;
}


void Avocat::afisare(ostream &out)
{
    cout << "Numele avocatului: ";
    out << nume << '\n';
    cout << "Codul avocatului: ";
    out << cod << '\n';
    cout << "Numar procese platite :";
    out << nr_procese << '\n';
    cout << "Sumele incasate: \n";
    for(int i = 0; i < nr_procese; i++)
        out << vector_procese[i] << " ";
    cout << endl;
}
ostream& operator<<(ostream &out, Avocat &x)
{
    x.afisare(out);
    return out;
}


Avocat& Avocat::operator=(Avocat &x)
{
    cod = x.cod;
    nume = x.nume;
    nr_procese = x.nr_procese;
    vector_procese = x.vector_procese;
}

bool operator<(const Avocat x, const Avocat y)
{
    if(x.nr_procese < y.nr_procese)
        return true;
    else return false;
}
bool operator<=(const Avocat x, const Avocat y)
{
    if(x.nr_procese <= y.nr_procese)
        return true;
    else return false;
}
bool operator>(const Avocat x, const Avocat y)
{
    if(x.nr_procese > y.nr_procese)
        return true;
    else return false;
}
bool operator>=(const Avocat x, const Avocat y)
{
    if(x.nr_procese >= y.nr_procese)
        return true;
    else return false;
}



class Avocat_Oficiu:public Avocat
{
protected:
    string nume_client;
    int durata;

public:
    Avocat_Oficiu(int, int, int*, string, string, int);
    ~Avocat_Oficiu(){};

    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Avocat_Oficiu&);
    friend ostream& operator<<(ostream&, Avocat_Oficiu&);

    int get_durata(){return durata;}
};

Avocat_Oficiu::Avocat_Oficiu(int codd = 0, int nr_procesee = 0, int* pntr = NULL, string numee = "", string nume_clientt = "", int durataa = 0):Avocat(codd, nr_procesee, pntr, numee){
    nume_client = nume_clientt;
    durata = durataa;
}

void Avocat_Oficiu::citire(istream &in){
    string strr2;
    Avocat::citire(in);
    getline(in, strr2);
    cout<< "Nume Client: \n";
    getline(in, nume_client);
    cout << "Durata(zile): \n";
    in >> durata;
}
istream& operator>>(istream& in, Avocat_Oficiu& x){
    x.citire(in);
    return in;
}


void Avocat_Oficiu::afisare(ostream &out){
    Avocat::afisare(out);
    out<<"Nume Client: " << nume_client << '\n';
    out<<"Durata(zile): " << durata << '\n';
}
ostream& operator<<(ostream& out, Avocat_Oficiu& x){
    x.afisare(out);
    return out;
}


int Avocat::nr_avocati = 0;
int n, lung_v1, lung_v2;

int ret_maxim_zile(Avocat_Oficiu *v)
{
    int i, maximul = -1, indice = -1;
    for(i = 0; i < lung_v2; i++)
    {
        if(v[i].get_durata() > maximul)
            indice = i, maximul = v[i].get_durata();
    }
    return indice;
}

void meniu_initial()
{
    cout << "*****Buna ziua, ce doriti sa faceti?*****\n\n";
    cout << "-> Apasati '1' urmat de 'ENTER' daca doriti sa adaugati un nou avocat\n\n";
    cout << "-> Apasati '2' urmat de 'ENTER' daca doriti sa aflati durata maxima a unui proces sustinut de un avocat din oficiu\n\n";
    cout << "-> Apasati '3' urmat de 'ENTER' daca doriti sa afisati avocatii in ordine\n\n";
    cout << "-> Apasati '4' urmat de 'ENTER' daca doriti sa afisati numarul total de avocati adaugati\n\n";
    cout << "-> Pentru a iesi, apasati '5' urmat de 'ENTER'\n";
}

int main()
{
    cout << "Cati avocati vom adauga(n = ?): " << endl;
    cin >> n;
    char c;
    int j = 0,i, jj = 1;
    int optiune;
    Avocat obj1, dec, BAZA;
    Avocat_Oficiu obj2, DERIV;
    Avocat *v1 = new Avocat[n+1];;
    Avocat_Oficiu *v2 = new Avocat_Oficiu[n+1];
    while(j < n || jj)
    {
        meniu_initial();
        cin >> optiune;
        system("cls");
        if(optiune == 1 && j != n)
        {
            j++;
            Avocat::increase_nr_avocati();
            system("cls");
            cout << "Avocatul va fi din oficiu? (y/n)\n";
            cin >> c;
            if(c == 'y')
            {
                cin >> obj2;
                v2[lung_v2] = obj2;
                lung_v2++;
            }
            else
            {
                Avocat_Oficiu *ao = (Avocat_Oficiu*) new Avocat;
                cin >> *ao;
                int k = lung_v1;
                v1[k] = *ao;
                while(k > 0 && v1[k] < v1[k-1])
                    dec = v1[k-1], v1[k-1] = v1[k], v1[k] = dec, k--;
                lung_v1++;
            }
            system("cls");
        }
        else if(optiune == 2)
        {
            if(lung_v2 > 0){
            int k = ret_maxim_zile(v2);
            cout << "Durata maxima este de " << v2[k].get_durata() << " zile \n";
            cout << "Acestea sunt datele despre avocat:\n";
            cout << v2[k];
            cout << endl << endl;
            }
            cout << "Doriti sa continuati?(y/n)";
            cin >> c;
            if (c == 'n')
                j = n, jj = 0;
            else
                system("cls");
        }
        else if(optiune == 3)
        {
            for(i = 0; i < lung_v1; i++)
                cout << v1[i] << endl << endl;
            cout << endl << endl;
            cout << "Doriti sa continuati?(y/n)";
            cin >> c;
            if (c == 'n')
                j = n, jj = 0;
            else
                system("cls");
        }
        else if(optiune == 4)
        {
            cout << Avocat::get_nr_avocati()<<endl;
            cout << endl << endl;
            cout << "Doriti sa continuati?(y/n)";
            cin >> c;
            if (c == 'n')
                j = n, jj = 0;
            else
                system("cls");
        }
        else if(optiune == 5)
        {
            j = n;
            jj = 0;
            cout << "Va multumim!";
        }
        else
        {
            cout << "Ne pare rau, nu puteti sa mai adaugati avocati!\n";
            cout << endl << endl;
            cout << "Doriti sa continuati?(y/n)";
            cin >> c;
            if (c == 'n')
                j = n, jj = 0;
            else
                system("cls");
        }
    }


    return 0;
}

