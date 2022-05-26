#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <list>
using namespace std;

class Animal{
private:
    string lungime, greutate;
    int varsta;
    static int nr_animale;
public:
    Animal(string a = "", string b = "", int c = 0){lungime = a, greutate = b, varsta = c;}
    Animal(Animal& x){this->greutate = x.greutate, this->lungime = x.lungime, this->varsta = x.varsta;}
    virtual ~Animal(){lungime = "", greutate = "", varsta = 0;}

    string get_lungime(){return lungime;}
    string get_greutate(){return greutate;}
    int get_varsta()const {return varsta;}

    static int get_nr_animale(){return nr_animale;}
    void creste_nr_animale(){nr_animale++;}

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);
    friend istream& operator>>(istream &in, Animal& x);
    friend ostream& operator<<(ostream &out, Animal& x);
};


void Animal::citire(istream &in)
{
    cout << "Care este lungimea animalului?(In metri)" << '\n';
    in >> lungime;
    cout << "Care este masa animalului?(In kilograme)" << '\n';
    in >> greutate;
    cout << "Care este speranta de viata a animalului?(In ani)\n";
    in >> varsta;
}
istream& operator>>(istream &in, Animal &x)
{
    x.citire(in);
    return in;
}

void Animal::afisare(ostream &out)
{
    cout << "Lungimea animalului(metri): ";
    out << lungime << '\n';
    cout << "Masa animalului(kilograme): ";
    out << greutate << '\n';
    cout << "Speranta de viata a animalului(ani): ";
    out << varsta << '\n';
}
ostream& operator<<(ostream &out, Animal &x)
{
    x.afisare(out);
    return out;
}



class Pesti:public Animal{
private:
    string denumire, nume_latina, tip_peste;

public:
    Pesti(string, string, int, string, string, string);
    ~Pesti(){};

    string get_denumire(){return denumire;}
    string get_nume_latina(){return nume_latina;}
    string get_tip_peste(){return tip_peste;}

    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Pesti&);
    friend ostream& operator<<(ostream&, Pesti&);
};
Pesti::Pesti(string lungimee = "", string greutatee = "", int varstaa = 0, string denumiree = "",
             string nume_latinaa = "", string tip_pestee = ""):
                 Animal(lungimee, greutatee, varstaa){
    denumire = denumiree;
    nume_latina = nume_latinaa;
    tip_peste = tip_pestee;
}

void Pesti::citire(istream &in)
{
    string str;
    Animal::citire(in);
    getline(in, str);
    cout << "Denumirea pestelui: \n";
    getline(in, denumire);
    cout << "Numele stiintific al speciei: \n";
    getline(in, nume_latina);
    cout << "Tip peste(rapitor/pasnic): \n";
    getline(in, tip_peste);
    unsigned i, len = tip_peste.size();
    for(i = 0; i < len; i++)
        if(tip_peste[i] > 64 && tip_peste[i] < 91)
            tip_peste[i]+=32;
    while(tip_peste != "rapitor" && tip_peste != "pasnic")
    {
        cout << "Nu exista tipul '" << tip_peste << "'! Va rugam selectati unul din tipurile date(rapitor/pasnic):\n";
        getline(in, tip_peste);
        for(i = 0; i < len; i++)
            if(tip_peste[i] > 64 && tip_peste[i] < 91)
                tip_peste[i]+=32;
    }
}
istream& operator>>(istream& in, Pesti& x){
    x.citire(in);
    return in;
}

void Pesti::afisare(ostream &out){
    Animal::afisare(out);
    out << "Denumirea pestelui: " << denumire << '\n';
    out << "Numele stiintific al speciei: " << nume_latina << "\n";
    out << "Tip peste: " << tip_peste << '\n';
}
ostream& operator<<(ostream& out, Pesti& x){
    x.afisare(out);
    return out;
}



class Pasari:public Animal{
private:
    string denumire, nume_latina, tip_pasare;

public:
    Pasari(string, string, int, string, string, string);
    ~Pasari(){};

    string get_denumire(){return denumire;}
    string get_nume_latina(){return nume_latina;}
    string get_tip_pasare(){return tip_pasare;}

    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Pasari&);
    friend ostream& operator<<(ostream&, Pasari&);
};
Pasari::Pasari(string lungimee = "", string greutatee = "", int varstaa = 0, string denumiree = "",
             string nume_latinaa = "", string tip_pasaree = ""):
                 Animal(lungimee, greutatee, varstaa){
    denumire = denumiree;
    nume_latina = nume_latinaa;
    tip_pasare = tip_pasaree;
}

void Pasari::citire(istream &in)
{
    string str;
    Animal::citire(in);
    getline(in, str);
    cout << "Denumirea pasarii: \n";
    getline(in, denumire);
    cout << "Numele stiintific al speciei: \n";
    getline(in, nume_latina);
    cout << "Tip pasare(carnivor/omnivor/erbivor): \n";
    getline(in, tip_pasare);
    unsigned i, len = tip_pasare.size();
    for(i = 0; i < len; i++)
        if(tip_pasare[i] > 64 && tip_pasare[i] < 91)
            tip_pasare[i]+=32;
    while(tip_pasare != "carnivor" && tip_pasare != "erbivor" && tip_pasare != "omnivor")
    {
        cout << "Nu exista tipul '" << tip_pasare << "'! Va rugam selectati unul din tipurile date(carnivor/omnivor/erbivor):\n";
        getline(in, tip_pasare);
        for(i = 0; i < len; i++)
            if(tip_pasare[i] > 64 && tip_pasare[i] < 91)
                tip_pasare[i]+=32;
    }
}
istream& operator>>(istream& in, Pasari& x){
    x.citire(in);
    return in;
}

void Pasari::afisare(ostream &out){
    Animal::afisare(out);
    out << "Denumirea pasarii: " << denumire << '\n';
    out << "Numele stiintific al speciei: " << nume_latina << "\n";
    out << "Tip pasare: " << tip_pasare << '\n';
}
ostream& operator<<(ostream& out, Pasari& x){
    x.afisare(out);
    return out;
}



class Mamifere:public Animal{
private:
    string denumire, nume_latina, tip_mamifer;

public:
    Mamifere(string, string, int, string, string, string);
    ~Mamifere(){};

    string get_denumire(){return denumire;}
    string get_nume_latina(){return nume_latina;}
    string get_tip_mamifer(){return tip_mamifer;}

    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Mamifere&);
    friend ostream& operator<<(ostream&, Mamifere&);
};
Mamifere::Mamifere(string lungimee = "", string greutatee = "", int varstaa = 0, string denumiree = "",
             string nume_latinaa = "", string tip_mamiferr = ""):
                 Animal(lungimee, greutatee, varstaa){
    denumire = denumiree;
    nume_latina = nume_latinaa;
    tip_mamifer = tip_mamiferr;
}

void Mamifere::citire(istream &in)
{
    string str;
    Animal::citire(in);
    getline(in, str);
    cout << "Denumirea mamiferului: \n";
    getline(in, denumire);
    cout << "Numele stiintific al speciei: \n";
    getline(in, nume_latina);
    cout << "Tip mamifer(carnivor/omnivor/erbivor): \n";
    getline(in, tip_mamifer);
    unsigned i, len = tip_mamifer.size();
    for(i = 0; i < len; i++)
        if(tip_mamifer[i] > 64 && tip_mamifer[i] < 91)
            tip_mamifer[i]+=32;
    while(tip_mamifer != "carnivor" && tip_mamifer != "erbivor" && tip_mamifer != "omnivor")
    {
        cout << "Nu exista tipul '" << tip_mamifer << "'! Va rugam selectati unul din tipurile date(carnivor/omnivor/erbivor):\n";
        getline(in, tip_mamifer);
        for(i = 0; i < len; i++)
            if(tip_mamifer[i] > 64 && tip_mamifer[i] < 91)
                tip_mamifer[i]+=32;
    }
}
istream& operator>>(istream& in, Mamifere& x){
    x.citire(in);
    return in;
}

void Mamifere::afisare(ostream &out){
    Animal::afisare(out);
    out << "Denumirea mamiferului: " << denumire << '\n';
    out << "Numele stiintific al speciei: " << nume_latina << "\n";
    out << "Tip mamifer: " << tip_mamifer << '\n';
}
ostream& operator<<(ostream& out, Mamifere& x){
    x.afisare(out);
    return out;
}


int nr;
class Reptile:public Animal{
private:
    string denumire, nume_latina, tip_reptile;

public:
    Reptile(string, string, int, string, string, string);
    ~Reptile(){};

    string get_denumire(){return denumire;}
    string get_nume_latina(){return nume_latina;}
    string get_tip_reptile(){return tip_reptile;}

    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Reptile&);
    friend ostream& operator<<(ostream&, Reptile&);
};
Reptile::Reptile(string lungimee = "", string greutatee = "", int varstaa = 0, string denumiree = "",
             string nume_latinaa = "", string tip_reptilee = ""):
                 Animal(lungimee, greutatee, varstaa){
    denumire = denumiree;
    nume_latina = nume_latinaa;
    tip_reptile = tip_reptilee;
}

void Reptile::citire(istream &in)
{
    string str;
    Animal::citire(in);
    getline(in, str);
    cout << "Denumirea reptilei: \n";
    getline(in, denumire);
    cout << "Numele stiintific al speciei: \n";
    getline(in, nume_latina);
    cout << "Tip reptila(carnivor/insectivor): \n";
    getline(in, tip_reptile);
    unsigned i, len = tip_reptile.size();
    for(i = 0; i < len; i++)
        if(tip_reptile[i] > 64 && tip_reptile[i] < 91)
            tip_reptile[i]+=32;
    while(tip_reptile != "carnivor" && tip_reptile != "insectivor")
    {
        cout << "Nu exista tipul '" << tip_reptile << "'! Va rugam selectati unul din tipurile date(rapitor/pasnic):\n";
        getline(in, tip_reptile);
        for(i = 0; i < len; i++)
            if(tip_reptile[i] > 64 && tip_reptile[i] < 91)
                tip_reptile[i]+=32;
    }
}
istream& operator>>(istream& in, Reptile& x){
    x.citire(in);
    return in;
}

void Reptile::afisare(ostream &out){
    Animal::afisare(out);
    out << "Denumirea reptilei: " << denumire << '\n';
    out << "Numele stiintific al speciei: " << nume_latina << "\n";
    out << "Tip reptila: " << tip_reptile << '\n';
}
ostream& operator<<(ostream& out, Reptile& x){
    x.afisare(out);
    return out;
}



class Nevertebrate:public Animal{
private:
    string denumire, nume_latina, tip_nevertebrate;
    static int nr_nevertebrate;
public:
    Nevertebrate(string, string, int, string, string, string);
    ~Nevertebrate(){};

    string get_denumire(){return denumire;}
    string get_nume_latina(){return nume_latina;}
    string get_tip_nevertebrate(){return tip_nevertebrate;}

    void creste_nr_nevertebrate(){nr_nevertebrate++;}
    static int afisare_nr_nevertebrate(){return nr_nevertebrate;}

    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Nevertebrate&);
    friend ostream& operator<<(ostream&, Nevertebrate&);
};
Nevertebrate::Nevertebrate(string lungimee = "", string greutatee = "", int varstaa = 0, string denumiree = "",
             string nume_latinaa = "", string tip_nevertebratee = ""):
                 Animal(lungimee, greutatee, varstaa){
    denumire = denumiree;
    nume_latina = nume_latinaa;
    tip_nevertebrate = tip_nevertebratee;
}

void Nevertebrate::citire(istream &in)
{
    string str;
    Animal::citire(in);
    getline(in, str);
    cout << "Denumirea nevertebratei: \n";
    getline(in, denumire);
    cout << "Numele stiintific al speciei: \n";
    getline(in, nume_latina);
    cout << "Tip nevertebrata dupa modul de obtinere a hranei(liber/parazit): \n";
    getline(in, tip_nevertebrate);
    unsigned i, len = tip_nevertebrate.size();
    for(i = 0; i < len; i++)
        if(tip_nevertebrate[i] > 64 && tip_nevertebrate[i] < 91)
            tip_nevertebrate[i]+=32;
    while(tip_nevertebrate != "liber" && tip_nevertebrate != "parazit")
    {
        cout << "Nu exista tipul '" << tip_nevertebrate << "'! Va rugam selectati unul din tipurile date(liber/parazit):\n";
        getline(in, tip_nevertebrate);
        for(i = 0; i < len; i++)
            if(tip_nevertebrate[i] > 64 && tip_nevertebrate[i] < 91)
                tip_nevertebrate[i]+=32;
    }
}
istream& operator>>(istream& in, Nevertebrate& x){
    x.citire(in);
    return in;
}

void Nevertebrate::afisare(ostream &out){
    Animal::afisare(out);
    out << "Denumirea nevertebratei: " << denumire << '\n';
    out << "Numele stiintific al speciei: " << nume_latina << "\n";
    out << "Tip nevertebrata: " << tip_nevertebrate << '\n';
}
ostream& operator<<(ostream& out, Nevertebrate& x){
    x.afisare(out);
    return out;
}



int Animal::nr_animale = 0;
int Nevertebrate::nr_nevertebrate = 0;

template <class T>
class AtlasZoologic{
private:
    list <Animal*> lista;
    int animale_adaugate;
    const int nr_maxim_animale = 1000000;

public:
    const get_nr_maxim_animale(){return nr_maxim_animale;}
    AtlasZoologic(){animale_adaugate = 0;}
    ~AtlasZoologic(){
        lista.clear();
    }

    friend ostream& operator<<(ostream &out, AtlasZoologic<T> &x)
    {
        out << "Bine ati venit! Acestea sunt elementele din atlasul zoologic:\n\n\n";
        list<Animal*>::iterator it;
        for(it = x.lista.begin(); it != x.lista.end(); it++)
            out << *(*it) << '\n';
        return out;
    }

    void add_element(T* x)
    {
        lista.push_back(new T);
        list<Animal*>::iterator itr = lista.end();
        itr--;
        *itr = x;
        animale_adaugate++;
    }
    void show(T x)
    {
        cout << "Avem " << animale_adaugate << " animale adaugate!\n" << '\n';
    }
    void show_pesti(Pesti* x)
    {
        string cop;
        list<Animal*>::iterator itr;
        for(itr = lista.begin(); itr != lista.end(); itr++)
        {
            cop = (*(*itr)).get_lungime();
            if(cop[0] != '0')
                cout << *(*itr);
        }
    }
};

template <>
class AtlasZoologic <Pesti>{
private:
    list <Animal*> lista;
    int animale_adaugate;
    const int nr_maxim_animale = 1000000;

public:
    const get_nr_maxim_animale(){return nr_maxim_animale;}
    AtlasZoologic(){animale_adaugate = 0;}
    ~AtlasZoologic(){
        lista.clear();
    }
    void cresc_animale(){animale_adaugate++;}
    friend ostream& operator<<(ostream &out, AtlasZoologic<Pesti> &x)
    {
        out << "Bine ati venit! Acestea sunt elementele din atlasul zoologic:\n\n\n";
        list<Animal*>::iterator it;
        for(it = x.lista.begin(); it != x.lista.end(); it++)
            out << *(*it) << '\n';
        return out;
    }

    void add_element(Pesti* x)
    {
        lista.push_back(new Pesti);
        list<Animal*>::iterator itr = lista.end();
        itr--;
        *itr = x;
        animale_adaugate++;
    }
    void show(Pesti* x)
    {
        string cop;
        list<Animal*>::iterator itr;
        for(itr = lista.begin(); itr != lista.end(); itr++)
        {
            cop = (*(*itr)).get_lungime();
            if(cop[0] != '0')
                cout << *(*itr);
        }
    }
};


void meniu_initial()
{
    cout << "*****Buna ziua, ce doriti sa faceti?*****\n\n";
    cout << "-> Apasati '1' urmat de 'ENTER' daca doriti sa adaugati un nou animal\n\n";
    cout << "-> Apasati '2' urmat de 'ENTER' daca doriti sa aflati numarul de animale adaugate in atlas\n\n";
    cout << "-> Apasati '3' urmat de 'ENTER' daca doriti sa aflati numarul de pesti adaugati cu dimensiunea mai mare de 1m\n\n";
    cout << "-> Apasati '4' urmat de 'ENTER' daca doriti sa afisati capacitatea maxima a atlasului\n\n";
    cout << "-> Pentru a iesi, apasati '5' urmat de 'ENTER'\n";
}

void meniu_2()
{
    cout << "-> Apasati '1' urmat de 'ENTER' daca doriti sa adaugati o vertebrata\n\n";
    cout << "-> Apasati '2' urmat de 'ENTER' daca doriti sa adaugati o nevertebrata\n\n";
}

void meniu_3(){

    cout << "-> Apasati '1' urmat de 'ENTER' daca doriti sa adaugati un peste\n\n";
    cout << "-> Apasati '2' urmat de 'ENTER' daca doriti sa adaugati un mamifer\n\n";
    cout << "-> Apasati '3' urmat de 'ENTER' daca doriti sa adaugati o pasare\n\n";
    cout << "-> Apasati '4' urmat de 'ENTER' daca doriti sa adaugati o reptila\n\n";
}

int main()
{
    int n;

    Pesti aa;
    Mamifere bb;
    Pasari cc;
    Reptile dd;
    Nevertebrate ee;

    AtlasZoologic <Animal> AtlasZoologic;
    cout << "Cate animale vom adauga(n = ?): " << endl;
    cin >> n;
    system("cls");
    int j = 0, jj = 1, i, optiune, optiune2, optiune3;
    while(j < n || jj)
    {
        meniu_initial();
        optiune2 = -1;
        cin >> optiune;
        system("cls");
        if(optiune == 1 && j != n)
        {
            j++;
            system("cls");
            meniu_2();
            cin >> optiune2;
            system("cls");
            while(optiune2 != 1 && optiune2 != 2)
            {
                system("cls");
                cout << "Va rugam selectati o optiune valida!(1/2)" << endl << endl;
                meniu_2();
                cin >> optiune2;
            }
            if(optiune2 == 1)
            {
                system("cls");
                meniu_3();
                cin >> optiune3;
                system("cls");
                while(optiune3 < 1 || optiune3 > 4)
            {
                system("cls");
                cout << "Va rugam selectati o optiune valida!(1/2/3/4)" << endl << endl;
                meniu_3();
                cin >> optiune3;
            }
            if(optiune3 == 1)
            {
                cin >> aa;
                string gett;
                gett = aa.get_lungime();
                if(gett[0] != '0')
                    nr++;
                AtlasZoologic.add_element(&aa);
            }
            else if(optiune3 == 2)
            {
                cin >> bb;
                AtlasZoologic.add_element(&bb);
            }
            else if(optiune3 == 3)
            {
                cin >> cc;
                AtlasZoologic.add_element(&cc);
            }
            else
            {
                cin >> dd;
                AtlasZoologic.add_element(&dd);
            }
            }
            else if(optiune2 == 2)
            {
                system("cls");
                cin >> ee;
            }

            system("cls");

        }
        else if(optiune == 2)
        {
            AtlasZoologic.show(aa);
            cout << "Doriti sa continuati?(y/n)"<<endl;
            char c;
            cin >> c;
            if(c == 'y')
            {
                system("cls");
            }
            else jj = 0, j = n + 1, system("cls");
        }
        else if(optiune == 3)
        {
            cout << nr  << " pesti cu lungime >= 1 metru" << endl;
            cout << "Doriti sa continuati?(y/n)"<<endl;
            char c;
            cin >> c;
            if(c == 'y')
            {
                system("cls");
            }
            else jj = 0, j = n + 1, system("cls");
        }
        else if(optiune == 4)
        {
            cout << "Capacitatea maxima a atlasului : ";
            cout << AtlasZoologic.get_nr_maxim_animale() << endl;
            cout << "Doriti sa continuati?(y/n)"<<endl;
            char c;
            cin >> c;
            if(c == 'y')
            {
                system("cls");
            }
            else jj = 0, j = n + 1, system("cls");

        }
        else if(optiune == 5)
        {
            cout << "La revedere";
            j = n + 1, jj = 0;
        }
        else{
            cout << "Ne pare rau, nu mai puteti adauga animale!" << endl;
        }

    }

    return 0;
}
