#include<iostream>
#include<fstream>
#include<cstring>


class Ingredient {
private:
    char* nume;
    int stoc;
    float pret;
    bool vegan;
    bool faraZahar;

public:
    ///Constructor implicit
    Ingredient():nume(), stoc(), pret(), vegan(), faraZahar() {}

    ///Constructor principal
    Ingredient(const char* nume_, int stoc_, float pret_, bool vegan_, bool faraZahar_):stoc{stoc_}, pret{pret_}, vegan{vegan_}, faraZahar{faraZahar_} {
        nume=new char[strlen(nume_)+1];
        strcpy(nume, nume_);
    }

    ///Constructor cu un ingur parametru
    Ingredient (const char *nume): stoc(), pret(), vegan(), faraZahar() {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume, nume);
    }

    ///Constructor de copiere
    Ingredient(const Ingredient& other):stoc(other.stoc), pret(other.pret), vegan(other.vegan), faraZahar(other.faraZahar) {
        if (other.nume) {
            nume=new char[strlen(other.nume)+1];
            strcpy(nume, other.nume);
        }
        else
            nume=nullptr;
    }

    void cresterPret() {
        if (this->stoc<500 && this->stoc >0) {
            float pretVechi=this->pret;
            this->pret*=1.20;
            std::cout<<"Stoc limitat de "<<this->nume<<"! Pretul a fost marit: "<<pretVechi<<" ==> "<<this->pret<<"\n";
        }
    }

    void reaprovizionare(int stocAdaugat) {
        this->stoc+=stocAdaugat;
    }

    //Getteri
    const char* getNume() const
    {
        return nume;
    }
    int getStoc() const
    {
        return stoc;
    }
    float getPret() const
    {
        return pret;
    }
    bool getVegan() const
    {
        return vegan;
    }
    bool getFaraZahar() const
    {
        return faraZahar;
    }

    ///Destructor
    ~Ingredient() {
      ///  delete[] nume;
    }

    ///Friend pentru operatori
    friend std::istream& operator>>(std::istream& is, Ingredient& ing) {
        char copie[100];
        is>>copie>>ing.stoc>>ing.pret>>ing.vegan>>ing.faraZahar;
        delete[] ing.nume;
        ing.nume=new char[strlen(copie)+1];
        strcpy(ing.nume, copie);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Ingredient& ing) {
        os<<"Nume: " << ing.nume <<", stoc: " <<ing.stoc <<", pret: "<<ing.pret<<", vegan: "<<ing.vegan<<", fara zahar :"<<ing.faraZahar<<"\n";
        return os;
    }
};

class bautura {
    std::string denumire;
    int pret;

    ///denumire
    ///pret preparare
    ///reteta care contine elemente de tip ingredient
    ///+ingrediente extra
    ///timp de preparare
    ///constructor explicit bautura
    ///constructor de copiere
    ///operatorul=
    ///destructorul
    ///functie pentru pretul final in care adaug pret preparare+pretul fiecarui ingredient
    ///functie pentru reducere procent oferta vegan, daca toate sunt vegane atunci aplic o reducere
    ///verifica disponibilitae
};

class comanda {
    ///numar comanda
    ///lista produse comandate
    ///indice-in perparare, nu se poate prepara-stoc indisponibil, finalizare comanda
    ///operator de afisare a comenzii care sa includ bautura, ingrediente plus specificatii extra, pret=bon
    ///functie de verificare disponibilitate
    ///tips?
    ///timp de preparare, furnizare ora la care este gata comanda
};

class barista {
    ///
};

///++generare de raport zilinic cu inasari =profit etc.
int main() {
    std::ifstream fin ("ingrediente.txt");
    int nrIngrediente;
    fin>>nrIngrediente;
    Ingredient* camara=new Ingredient[nrIngrediente];
    for (int i=0;i<nrIngrediente; i++) {
        fin>>camara[i];
    }
    for (int i=0;i<nrIngrediente; i++) {
        std::cout<<camara[i];
    }

    int ok=-1;
    while (ok!=0) {
        std::cout << "--------- MENIU CAFENEA ---------\n";
        std::cout << "1. Aprovizioneaza stoc\n";
        std::cout << "2. Afiseaza stocul de ingrediente\n";
        std::cout << "3. Comanda\n";
        std::cout << "0. Iesire program\n";
        std::cout << "Alegere: ";

        std::cin>>ok;
        switch (ok) {
            case1:
            for(int i=0; i<nrIngrediente; i++)
            {
                std::cout<<"cod produs: "<<i<<" ==> "<<camara[i]<<"\n";
            }
            std::cout << "Pentru reaprovizionare te rugam sa introduci codul produsului si stocul adaugat!\n";
            int cod, aprovizionare;
            std::cin>>cod>>aprovizionare;
            camara[cod].reaprovizionare(aprovizionare);
            std::cout<<"Ingredientul "<<camara[cod]<<" a fost reaprovizionat!\n";
            break;
            case 2:
            break;
            case 3:
            break;
            case 0:
            break;
            default:
            break;
        }
    }
    fin.close();
    delete[] camara;
    return 0;
}