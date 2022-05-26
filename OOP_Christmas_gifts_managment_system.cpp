//C++ -> Code Blocks:20.03
#include <bits/stdc++.h>
using namespace std;
string vid;
int tip1,tip2,tip3,tip4;

class jucarie{
protected:
    string denumire;
    float dimensiune;
    string tip;
    int fel;
public:
    jucarie(string a, float b, string c);
    ~jucarie();
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    friend istream& operator>>(istream &in, jucarie& x);
    friend ostream& operator<<(ostream &out, jucarie& x);
};
jucarie::jucarie(string a = "", float b = 0, string c = "")
{
    denumire = a;
    dimensiune = b;
    tip = c;
    fel = 0;
}
jucarie::~jucarie()
{
    denumire = "";
    dimensiune = 0;
    tip = "";
}
void jucarie::citire(istream &in)
{
    cout << "Denumire: ";
    getline(in, denumire);

    cout << "Dimensiune(cm^3): ";
    cin >> dimensiune, getline(in, vid);

    cout << "Tipul: ";
    getline(in, tip);
}
void jucarie::afisare(ostream &out)
{
    cout << "Denumire: " << denumire << endl <<  "Dimensiune este de " << dimensiune << " cm cubi\n" << "Tipul: " << tip << endl;
}
istream& operator>>(istream &in, jucarie& x)
{
    x.citire(in);
    return in;
}
ostream& operator<<(ostream &out, jucarie& x)
{
    x.afisare(out);
    return out;
}






class clasic:public jucarie{
protected:
    string material;
    string culoare;
public:
    clasic(string a, float b, string c, string d, string e);
    ~clasic();
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream &in, clasic& x);
    friend ostream& operator<<(ostream &out, clasic& x);
};
clasic::clasic(string a = "", float b = 0, string c = "", string d = "", string e = "" ):jucarie(a,b,c)
{
    material = d;
    culoare = e;
    fel = 1;
}
clasic::~clasic()
{
    material = culoare = "";
}

void clasic::citire(istream &in)
{
    jucarie::citire(in);
    cout << "Material: ";
    getline(in, material);
    cout << "Culoare: ";
    getline(in, culoare);
}
void clasic::afisare(ostream &out)
{
    jucarie::afisare(out);
    cout << "Material: " << material << endl;
    cout << "Culoare: "  << culoare << endl;
}
istream& operator>>(istream &in, clasic& x)
{
    x.citire(in);
    return in;
}
ostream& operator<<(ostream &out, clasic& x)
{
    x.afisare(out);
    return out;
}













class educativ:virtual public jucarie{
protected:
    string abilitate_dezvoltata;
public:
    educativ(string a, float b, string c, string d);
    ~educativ();
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    friend istream& operator>>(istream &in, educativ& x);
    friend ostream& operator<<(ostream &out, educativ& x);

};
educativ::educativ(string a = "", float b = 0, string c = "", string d = ""):jucarie(a,b,c)
{
    abilitate_dezvoltata = d;
    fel = 2;
}
educativ::~educativ()
{
    abilitate_dezvoltata = "";
}


void educativ::citire(istream &in)
{
    jucarie::citire(in);
    cout << "Abilitate dezvoltata: ";
    getline(in, abilitate_dezvoltata);

}
void educativ::afisare(ostream &out)
{
    jucarie::afisare(out);
    cout << "Abilitate dezvoltata: ";
    cout << abilitate_dezvoltata << endl;

}
istream& operator>>(istream &in, educativ& x)
{
    x.citire(in);
    return in;
}
ostream& operator<<(ostream &out, educativ& x)
{
    x.afisare(out);
    return out;
}



class electronic:virtual public jucarie{
protected:
    int nr_baterii;
public:
    electronic(string a, float b, string c, int d);
    ~electronic();

    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    friend istream& operator>>(istream &in, electronic& x);
    friend ostream& operator<<(ostream &out, electronic& x);
};
electronic::electronic(string a = "", float b = 0, string c = "", int d = 0)
{
    nr_baterii = d;
    fel = 3;
}
electronic::~electronic()
{
    nr_baterii = 0;
}
void electronic::citire(istream &in)
{
    jucarie::citire(in);
    cout << "Numar baterii: ";
    cin >> nr_baterii, getline(in, vid);
}
void electronic::afisare(ostream &out)
{
    jucarie::afisare(out);
    cout << "Numar baterii: " << nr_baterii << endl;
}
istream& operator>>(istream &in, electronic& x)
{
    x.citire(in);
    return in;
}
ostream& operator<<(ostream &out, electronic& x)
{
    x.afisare(out);
    return out;
}



class modern:public educativ, public electronic{
protected:
    string brand;
    string model;
public:
    modern(string a, float b, string c, string d, int e, string f, string g);
    ~modern();
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream &in, modern& x);
    friend ostream& operator<<(ostream &out, modern& x);

};
modern::modern(string a = "", float b = 0, string c = "", string d = "generala", int e = 1, string f = "", string g = ""):jucarie(a,b,c),educativ(a,b,c,d),
electronic(a,b,c,e)
{
    brand = f;
    model = g;
    fel = 4;
}
modern::~modern()
{
    brand = "";
    model = "";
}

void modern::citire(istream &in)
{
    jucarie::citire(in);
    cout << "Brand: ";
    getline(in, brand);
    cout << "Model: ";
    getline(in, model);
}
void modern::afisare(ostream &out)
{
    jucarie::afisare(out);
    cout << "Abilitate dezvoltata: " << abilitate_dezvoltata << endl;
    cout << "Numar baterii: " << nr_baterii << endl;
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
}
istream& operator>>(istream &in, modern& x)
{
    x.citire(in);
    return in;
}
ostream& operator<<(ostream &out, modern& x)
{
    x.afisare(out);
    return out;
}



vector<jucarie*> gol;


class copil{
protected:
    static int idd;
    int id;

    string nume;
    string prenume;
    string adresa;
    int varsta;
    int nr_faptebune;
    vector<jucarie*> primeste;
public:
    copil(string a, string b, string c, int d, int e, vector<jucarie*> f);
    ~copil();

    string ret_nume(){return nume;}
    int ret_varsta(){return varsta;}
    int ret_fapte(){return nr_faptebune;}
    int ret_id(){return id;}
    void modifica(int n){nr_faptebune += n;}
    void adaugare(jucarie *j)
    {
        primeste.push_back(j);
    }

    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    friend istream& operator>>(istream &in, copil& x);
    friend ostream& operator<<(ostream &out, copil& x);
};
copil::copil(string a = "", string  b = "", string c = "", int d = 0, int e = 0, vector<jucarie*> f = gol)
{
    nume = a;
    prenume = b;
    adresa = c;
    varsta = d;
    nr_faptebune = e;
    primeste = f;
    id = idd;
    idd++;
}
copil::~copil()
{
    nume = prenume = adresa = "";
    varsta = 0;
    nr_faptebune = 0;
    primeste = gol;
}

void copil::citire(istream &in)
{
    cout << "Nume: ";
    getline(in, nume);

    cout << "Prenume: ";
    getline(in, prenume);

    cout << "Adresa: ";
    getline(in, adresa);

    cout << "Varsta: ";
    cin >> varsta, getline(in, vid);
}
void copil::afisare(ostream &out)
{
    cout << "ID: " << id << endl << endl;

    cout << "Nume: " << nume << endl;

    cout << "Prenume: " << prenume << endl;

    cout << "Adresa: " << adresa << endl;

    cout << "Varsta: " << varsta << " ani" << endl;

}
istream& operator>>(istream &in, copil& x)
{
    x.citire(in);
    return in;
}
ostream& operator<<(ostream &out, copil& x)
{
    x.afisare(out);
    return out;
}



class cuminte:public copil
{
protected:
    int dulciuri;
public:
    cuminte(string a, string b, string c, int d, int e, vector<jucarie*> f, int g);
    ~cuminte();

    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream &in, cuminte& x);
    friend ostream& operator<<(ostream &out, cuminte& x);

};
cuminte::cuminte(string a = "", string  b = "", string c = "", int d = 0, int e = 0, vector<jucarie*> f = gol, int g = 0):copil(a,b,c,d,e,f)
{
    dulciuri = g;
}
cuminte::~cuminte()
{
    dulciuri = 0;
}

void cuminte::citire(istream &in)
{
    copil::citire(in);
    cout << "Numar fapte bune: ";
    cin >> nr_faptebune;
    while(nr_faptebune < 2)
    {
        cout << "Copilul este cuminte, reintroduceti numarul de fapte bune(minim 10): ";
        cin >> nr_faptebune;
    }
    getline(in, vid);
    int i = 0;
    cout << endl;
    for(i = 0; i < nr_faptebune; i++)
    {
        cout << "Ce fel de jucarie este(clasica/educativa/electronica/moderna): ";
        getline(in, vid);
        if(vid == "clasica")
        {
            clasic *j = new clasic;
            cin >> (*j);
            primeste.push_back(j);
        }
        else if(vid == "educativa")
        {
            educativ *j = new educativ;
            cin >> (*j);
            primeste.push_back(j);
        }
        else if(vid == "electronica")
        {
            electronic *j = new electronic;
            cin >> (*j);
            primeste.push_back(j);
        }
        else if(vid == "moderna")
        {
            modern *j = new modern;
            cin >> (*j);
            primeste.push_back(j);
        }
        else
        {
            cout << "Gresit! Mai incercati inca o data!\n";
            i--;
        }
    }

    cout << "Cate dulciuri primeste: ";
    cin >> dulciuri;
    getline(in, vid);
}
void cuminte::afisare(ostream &out)
{
    copil::afisare(out);
    cout << "A facut " << nr_faptebune << " fapte bune, prin urmare acestea sunt jucariile:\n";
    int i = 0, len = primeste.size();
    for(i = 0; i < len; i++)
    {
        cout << i+1 << ". " << endl;
        cout << (*primeste[i]) << endl;
    }
    cout << "Primeste si " << dulciuri << " dulciuri\n";
}
istream& operator>>(istream &in, cuminte& x)
{
    x.citire(in);
    return in;
}
ostream& operator<<(ostream &out, cuminte& x)
{
    x.afisare(out);
    return out;
}






class neastamparat:public copil
{
protected:
    int carbuni;
public:
    neastamparat(string a, string b, string c, int d, int e, vector<jucarie*> f, int g);
    ~neastamparat();

    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream &in, neastamparat& x);
    friend ostream& operator<<(ostream &out, neastamparat& x);

};
neastamparat::neastamparat(string a = "", string  b = "", string c = "", int d = 0, int e = 0, vector<jucarie*> f = gol, int g = 0):copil(a,b,c,d,e,f)
{
    carbuni = g;
}
neastamparat::~neastamparat()
{
    carbuni = 0;
}

void neastamparat::citire(istream &in)
{
    copil::citire(in);
    cout << "Numar fapte bune: ";
    cin >> nr_faptebune;
    getline(in, vid);
    int i = 0;
    cout << endl;
    for(i = 0; i < nr_faptebune; i++)
    {
        cout << "Ce fel de jucarie este(clasica/educativa/electronica/moderna): ";
        getline(in, vid);
        if(vid == "clasica")
        {
            clasic *j = new clasic;
            cin >> (*j);
            primeste.push_back(j);
        }
        else if(vid == "educativa")
        {
            educativ *j = new educativ;
            cin >> (*j);
            primeste.push_back(j);
        }
        else if(vid == "electronica")
        {
            electronic *j = new electronic;
            cin >> (*j);
            primeste.push_back(j);
        }
        else if(vid == "moderna")
        {
            modern *j = new modern;
            cin >> (*j);
            primeste.push_back(j);
        }
        else
        {
            cout << "Gresit! Mai incercati inca o data!\n";
            i--;
        }
    }

    cout << "Cati carbuni primeste: ";
    cin >> carbuni;
    getline(in, vid);

}
void neastamparat::afisare(ostream &out)
{
    copil::afisare(out);
    cout << "A facut " << nr_faptebune << " fapte bune, prin urmare acestea sunt jucariile:\n";
    int i = 0, len = primeste.size();
    for(i = 0; i < len; i++)
    {
        cout << i+1 << ". " << endl;
        cout << (*primeste[i]) << endl;
    }
    cout << "Primeste si " << carbuni << " carbuni\n";

}
istream& operator>>(istream &in, neastamparat& x)
{
    x.citire(in);
    return in;
}
ostream& operator<<(ostream &out, neastamparat& x)
{
    x.afisare(out);
    return out;
}











int copil::idd = 1;


void meniu()
{
    cout << "BUNA ZIUA! INTRODUCETI NUMARUL ACTIUNII DORITE:" << endl;
    cout << "1. Citire n copii(ce au fiecare un numar corespunzator de jucarii)\n";
    cout << "2. Afisarea copiilor\n";
    cout << "3. Gasire copil dupa nume\n";
    cout << "4. Ordonare copii dupa varsta\n";
    cout << "5. Ordonare copii dupa fapte bune\n";
    cout << "6. Modificare fapte bune si jucarii pentru un copil\n";
    cout << "7. Raport jucarii\n";
    cout << "8. Creare jucarie\n";
    cout << "9. EXIT\n";
}

class mos_craciun{
protected:
    vector<copil*> toticopiii;
    vector<jucarie*> jucarii;
public:
    void cerinta1(int n);
    void cerinta2();
    void cerinta3(string x);
    void cerinta4();
    void cerinta5();
    void cerinta6(int a, int b);
    //void cerinta7();
    void cerinta8();
}MOSCRACIUN;

void mos_craciun::cerinta1(int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        cout << "Copil cuminte(da/nu): ";
        getline(cin, vid);
        if(vid == "da")
        {
            cuminte* c = new cuminte;
            cin >> (*c);
            toticopiii.push_back(c);
        }
        else
        {
            neastamparat* c = new neastamparat;
            cin >> (*c);
            toticopiii.push_back(c);
        }
    }

}

void mos_craciun::cerinta2()
{
    int i, len;
    len = toticopiii.size();
    for(i = 0; i < len; i++)
        cout << i+1 << "." << (*toticopiii[i]) << endl << endl;
}

void mos_craciun::cerinta3(string x)
{
    int i, len = toticopiii.size();
    for(i = 0; i < len; i++)
        if(toticopiii[i]->ret_nume() == x)
            cout << (*toticopiii[i]) << endl << endl;
}

void mos_craciun::cerinta4()
{
    int i, j, len = toticopiii.size();
    for(i = 0; i < len; i++)
    {
        j = i;
        while(j > 0)
        {
            if(toticopiii[j]->ret_varsta() < toticopiii[j-1]->ret_varsta())
                swap(toticopiii[j], toticopiii[j-1]), j--;
            else j = 0;
        }
    }
    for(i = 0; i < len; i++)
        cout << (*toticopiii[i]) << endl << endl;
}

void mos_craciun::cerinta5()
{
    int i, j, len = toticopiii.size();
    for(i = 0; i < len; i++)
    {
        j = i;
        while(j > 0)
        {
            if(toticopiii[j]->ret_fapte() < toticopiii[j-1]->ret_fapte())
                swap(toticopiii[j], toticopiii[j-1]), j--;
            else j = 0;
        }
    }
    for(i = 0; i < len; i++)
        cout << (*toticopiii[i]) << endl << endl;

}

void mos_craciun::cerinta6(int a, int b)
{
    int i, jj, len = toticopiii.size();
    for(i = 0; i < len; i++)
    {
        if(toticopiii[i]->ret_id() == a)
            jj = i, i = len;
    }
    toticopiii[jj]->modifica(b);
    for(i = 0; i < b; i++)
    {
        cout << "Ce fel de jucarie este(clasica/educativa/electronica/moderna): ";
        getline(cin, vid);
        if(vid == "clasica")
        {
            clasic *j = new clasic;
            cin >> (*j);
            toticopiii[jj]->adaugare(j);
        }
        else if(vid == "educativa")
        {
            educativ *j = new educativ;
            cin >> (*j);
            toticopiii[jj]->adaugare(j);
        }
        else if(vid == "electronica")
        {
            electronic *j = new electronic;
            cin >> (*j);
            toticopiii[jj]->adaugare(j);
        }
        else if(vid == "moderna")
        {
            modern *j = new modern;
            cin >> (*j);
            toticopiii[jj]->adaugare(j);
        }
        else
        {
            cout << "Gresit! Mai incercati inca o data!\n";
            i--;
        }

    }
}

void mos_craciun::cerinta8()
{
        cout << "Ce fel de jucarie este(clasica/educativa/electronica/moderna): ";
        getline(cin, vid);
        if(vid == "clasica")
        {
            clasic *j = new clasic;
            cin >> (*j);
            jucarii.push_back(j);
        }
        else if(vid == "educativa")
        {
            educativ *j = new educativ;
            cin >> (*j);
            jucarii.push_back(j);
        }
        else if(vid == "electronica")
        {
            electronic *j = new electronic;
            cin >> (*j);
            jucarii.push_back(j);
        }
        else
        {
            modern *j = new modern;
            cin >> (*j);
            jucarii.push_back(j);
        }
}

int main()
{

    int raspuns, optiune = 1, i, j;
    while(optiune != 9)
    {
        system("cls");
        meniu();
        cin >> optiune,getline(cin, vid);
        system("cls");
        if(optiune == 1)
        {
            cout << "Cati copii citim: ";
            cin >> raspuns, getline(cin, vid);
            MOSCRACIUN.cerinta1(raspuns);
        }
        else if(optiune == 2)
        {
            MOSCRACIUN.cerinta2();
        }
        else if(optiune == 3)
        {
            cout << "Introduceti numele dorit: ";
            getline(cin, vid);

        }
        else if(optiune == 4)
        {
            MOSCRACIUN.cerinta4();
        }
        else if(optiune == 5)
        {
            MOSCRACIUN.cerinta5();
        }
        else if(optiune == 6)
        {
            int x;
            cout << "ID-ul copilului: ";
            cin >> raspuns;
            cout << "Valoarea X(nr fapte bune adaugate): ";
            cin >> x, getline(cin, vid);
            MOSCRACIUN.cerinta6(raspuns, x);
        }
        else if(optiune == 7)
        {
            //tip1 tip2 tip3 si tip4 sunt incrementate de fiecare data cand e citita o jucarie de tipul respectiv, iar apoi se afiseaza ce se cere

        }
        else if(optiune == 8)
        {
            MOSCRACIUN.cerinta8();
        }
        else return 0;
        cout << "Doriti sa continuati?(da/nu)\n";
        getline(cin, vid);
        if(vid == "nu")
            optiune = 9;
    }

    return 0;
}
