#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
using namespace std;

class film{
private:
    string denumire_film, gen, regizor;
    float rating_imdb;
public:
    //initializare, copiere, destructor
    film();
    film(film&);
    ~film();

    //getteri
    string get_denumire_film(){return denumire_film;}
    string get_gen(){return gen;}
    string get_regizor(){return regizor;}
    float  get_rating(){return rating_imdb;}

    //setteri
    void set_denumire_film(string x){denumire_film = x;}
    void set_gen(string x){gen = x;}
    void set_regizor(string x){regizor = x;}
    void set_rating(float x){rating_imdb = x;}

    //operatori
    film& operator=(film &x);
    friend bool operator<(const film x, const film y);
    friend bool operator>(const film x, const film y);
    friend bool operator>=(const film x, const film y);
    friend bool operator<=(const film x, const film y);

    //citire
    void citire(istream &in);
    friend istream& operator>>(istream &in, film& x);
    void afisare(ostream &out);
    friend ostream& operator<<(ostream &out, film& x);
};

film::film(){
    this->denumire_film = "";
    this->gen = "";
    this->regizor = "";
    this->rating_imdb = 0;
}

film::film(film &x){
    this->denumire_film = x.denumire_film;
    this->gen = x.gen;
    this->regizor = x.regizor;
    this->rating_imdb = x.rating_imdb;
}

film::~film(){
    this->denumire_film = "";
    this->gen = "";
    this->regizor = "";
    this->rating_imdb = 0;
}

film& film::operator=(film &x)
{
    denumire_film = x.get_denumire_film();
    gen = x.get_gen();
    regizor = x.get_regizor();
    rating_imdb = x.get_rating();

}

bool operator<(const film x, const film y)
{
    if(x.rating_imdb < y.rating_imdb)
        return true;
    else return false;
}
bool operator<=(const film x, const film y)
{
    if(x.rating_imdb <= y.rating_imdb)
        return true;
    else return false;
}
bool operator>(const film x, const film y)
{
    if(x.rating_imdb > y.rating_imdb)
        return true;
    else return false;
}
bool operator>=(const film x, const film y)
{
    if(x.rating_imdb >= y.rating_imdb)
        return true;
    else return false;
}

void film::citire(istream &in)
{
    string r;
    cout << "Denumire film: ";
    getline(in, denumire_film);
    cout << "Gen: ";
    getline(in, gen);
    cout << "Regizor: ";
    getline(in, regizor);
    cout << "Rating imdb: ";
    cin >> rating_imdb;
    cout << endl;
    getline(in, r);
}

istream& operator>>(istream& in,film& x)
{
    x.citire(in);
    return in;
}

void film::afisare(ostream &out)
{
    cout << "Denumire film: ";
    cout << denumire_film << endl;
    cout << "Gen : ";
    cout << gen << endl;
    cout << "Regizor : ";
    cout << regizor << endl;
    cout << "Rating imbd : ";
    cout << rating_imdb << endl;
}

ostream& operator<<(ostream &out, film &x)
{
    x.afisare(out);
    return out;
}


film *vec = new film[3];
int lungime, max_lungime;

//-------------functii vector----------------
void resize()
{
    int i, newlen = 2 * max_lungime;
    film *newvec = new film[newlen];
    for(i = 0; i < lungime; i++)
    {
        newvec[i].set_denumire_film(vec[i].get_denumire_film());
        newvec[i].set_gen(vec[i].get_gen());
        newvec[i].set_regizor(vec[i].get_regizor());
        newvec[i].set_rating(vec[i].get_rating());
    }
    max_lungime = newlen;
    delete []vec;
    vec = newvec;
}

void afis()
{
    int i = 0;
    for (i; i < lungime; i++)
        cout << i+1 << "." <<endl << vec[i]<< endl;
}
//-------------------------------------------
void meniu_initial()
{
    cout << "*****Buna ziua, ce doriti sa faceti?*****\n\n";
    cout << "-> Apasati '1' daca doriti sa adaugati un nou film\n\n";
    cout << "-> Apasati '2' daca doriti sa comparati doua filme\n\n";
    cout << "-> Apasati '3' daca doriti sa modificati informatiile unui film\n\n";
    cout << "-> Apasati '4' daca doriti sa afisati filmele existente\n\n";
    cout << "-> Pentru a iesi, apasati de doua ori tasta 'ESC'\n";
}

void modificare()
{
    int b;
    cout << "Indicele filmului este pe care doriti sa il modificati este : ";
    cin >> b;
    while(b < 1 || b > lungime)
    {
        cout << "Indicele nu exista, va rog selectati un numar cuprins intre 1 si " << lungime << "!\n";
        cin >> b;
    }
    string instr;
    cout << "Ce doriti sa modificati?('denumire'/'gen'/'regizor'/'rating')" << endl;
    getline(cin, instr);
    getline(cin, instr);
    while(instr != "denumire" && instr != "gen" && instr != "regizor" &&instr != "rating")
    {
        cout << "Acest criteriu nu exista, va rugam selectati din 'denumire'/'gen'/'regizor'/'rating'" << endl;
        getline(cin,instr);
    }
    if(instr == "denumire")
    {
        cout << "Care doriti sa fie noul nume?" << endl;
        getline(cin,instr);
        vec[b-1].set_denumire_film(instr);
    }
    else if(instr == "gen")
    {
        cout << "Care doriti sa fie noul gen?" << endl;
        getline(cin, instr);
        vec[b-1].set_gen(instr);
    }
    else if(instr == "regizor")
    {
        cout << "Care doriti sa fie noul regizor?" << endl;
        getline(cin,instr);
        vec[b-1].set_regizor(instr);
    }
    else
    {
        float d;
        cout << "Care doriti sa fie noul rating?" << endl;
        cin >> d;
        vec[b-1].set_rating(d);
        getline(cin,instr);
    }
    cout << "Modificare efectuata cu succes!" << endl;
}

int main()
{
    max_lungime = 3;
    string none;
    int i = 0, a, b, j = 1;
    char tasta = '0';
    meniu_initial();
    while(tasta != 27)
    {
        if (kbhit())
        {
            j = 1;
            tasta = getch();
            if(tasta == '1')
            {
                system("CLS");
                cin >> vec[i];
                lungime++, i++;
                if(lungime == max_lungime)
                    resize();
                cout << endl << endl;
                cout << "Apasati orice tasta pentru a continua\n";
            }
            else if(tasta == '2')
            {
                if(lungime > 1)
                {
                system("CLS");
                afis();
                cout << endl << endl;
                cout << "Primul film ales: (numarul de ordine al acestuia) ";
                cin >> a;
                while(a < 1 || a > lungime)
                {
                    cout << "Indicele nu exista, va rog selectati un numar cuprins intre 1 si " << lungime << "!\n";
                    cin >> a;
                }
                cout << "Al doilea film ales: (numarul de ordine al acestuia) ";
                cin >> b;
                while(b == a)
                {
                    cout << "Indicii sunt identici, va rog selectati alt indice\n";
                    cin >> b;
                }
                while(b < 1 || b > lungime)
                {
                    cout << "Indicele nu exista, va rog selectati un numar cuprins intre 1 si " << lungime << "!\n", cin >> b;
                    while(b == a)
                    {
                        cout << "Indicii sunt identici, va rog selectati alt indice\n";
                        cin >> b;
                    }
                }
                a--,b--;
                if(vec[a] > vec[b])
                    cout << "Filmul " << vec[a].get_denumire_film() << " are un scor mai mare pe imdb\n";
                else if(vec[b] > vec[a])
                    cout << "Filmul " << vec[b].get_denumire_film() << " are un scor mai mare pe imdb\n";
                else cout << "Filmele alese au acelasi scor pe imdb!\n";
                getline(cin, none);
                }
                else
                    cout << "\nNu exista cel putin doua filme pentru a putea face comparatia!";
                cout << endl << endl;
                cout << "Apasati orice tasta pentru a continua\n";
            }
            else if(tasta == '3')
            {
                if(lungime)
                {
                    system("CLS");
                    afis();
                    cout << endl << endl;
                    modificare();
                    cout << endl << endl;
                    cout << "Apasati orice tasta pentru a continua\n";
                }
                else
                {
                    cout << "Nu exista filme. Adaugati filme noi!\n";
                    cout << endl << endl;
                    cout << "Apasati orice tasta pentru a continua\n";
                }
            }
            else if (tasta == '4')
            {
              system("CLS");
              afis();
              cout << endl << endl;
              cout << "Apasati orice tasta pentru a continua\n";
            }
            while(j)
            {
                if(kbhit())
                    tasta = getch(), j = 0;
            }
            system("CLS");
            meniu_initial();
        }
    }
    delete []vec;
    return 0;
}

