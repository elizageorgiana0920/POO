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
    float kcal;

public:
    ///Constructor implicit
    Ingredient():nume(nullptr), stoc(0), pret(0.0f), vegan(false), faraZahar(false), kcal(0.0f) {}

    ///Constructor de initializare
    Ingredient(const char* nume_, int stoc_, float pret_, bool vegan_, bool faraZahar_, float kcal_)
    :stoc{stoc_}, pret{pret_}, vegan{vegan_}, faraZahar{faraZahar_}, kcal{kcal_} {
        if (nume_) {
            nume=new char[std::strlen(nume_)+1];
            std::strcpy(nume, nume_);
        }
        else
            nume=nullptr;

    }

    ///Constructor cu un singur parametru
    explicit Ingredient (const char *nume_): stoc(0), pret(0.0f), vegan(false), faraZahar(false), kcal(0.0f) {
        if (nume_) {
            nume=new char[std::strlen(nume_)+1];
            std::strcpy(nume, nume_);
        }
        else
            nume=nullptr;
    }

    ///Constructor de copiere (CC)
    Ingredient(const Ingredient& other):stoc(other.stoc), pret(other.pret), vegan(other.vegan), faraZahar(other.faraZahar), kcal(other.kcal) {
        if (other.nume) {
            nume=new char[std::strlen(other.nume)+1];
            std::strcpy(nume, other.nume);
        }
        else
            nume=nullptr;
    }

    ///Operator de copiere (op=)
    Ingredient& operator=(const Ingredient& other) {
        ///eliberez memoria
        if (this!=&other) {
            delete[] nume;

            ///copiez datele vechi
            stoc=other.stoc;
            pret=other.pret;
            vegan=other.vegan;
            faraZahar=other.faraZahar;
            kcal=other.kcal;

            ///aloc spatiu si copiez noul nume
            if (other.nume) {
                nume=new char[std::strlen(other.nume)+1];
                std::strcpy(nume, other.nume);
            }
            else
                nume=nullptr;
        }
        return *this;

    }

    ///Destructor
    ~Ingredient() {
        delete[] nume;
    }

    void cresterePret() {
        if (stoc>0 && stoc<500) {
            pret+=pret*12/100;
        }
    }

    void reaprovizionare(int stocAdaugat) {
        stoc+=stocAdaugat;
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
    float getKcal() const
    {
        return kcal;
    }

    void setNume(const char* numeNou) {
        if (numeNou) {
            delete[] nume;
            nume=new char[strlen(numeNou)+1];
            strcpy(nume, numeNou);
        }
    }
    ///Friend pentru operatori
    friend std::istream& operator>>(std::istream& is, Ingredient& ing) {
        char copie[300];
        if (is>>copie>>ing.stoc>>ing.pret>>ing.vegan>>ing.faraZahar>>ing.kcal){
        delete[] ing.nume;
        ing.nume=new char[std::strlen(copie)+1];
        std::strcpy(ing.nume, copie);
    }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Ingredient& ing) {
        os<<"Nume: " << ing.nume <<", stoc: " <<ing.stoc <<", pret: "<<ing.pret<<", vegan: "<<ing.vegan<<", fara zahar :"<<ing.faraZahar<<", kcal:"<<ing.kcal<<"\n";
        return os;
    }
};

class Bautura {
    char *numeBautura;
    float pretPreparare;
    int timpPreparare;
    Ingredient* listaIngrediente;
    int nrIngrediente;

public:
    ///Constructor Implicit
    Bautura():numeBautura(nullptr), pretPreparare(0.0f), timpPreparare(0), listaIngrediente(nullptr), nrIngrediente(0) {}

    ///Constructor de initializare
    Bautura(const char* numeBautura_, float pretPreparare_, int timpPreparare_): pretPreparare{pretPreparare_}, timpPreparare{timpPreparare_}, listaIngrediente(nullptr), nrIngrediente(0)
    {
        if (numeBautura_)
        {
            numeBautura = new char[std::strlen(numeBautura_) + 1];
            std::strcpy(numeBautura, numeBautura_);
        }
        else numeBautura = nullptr;
    }

    ///Constructor de copiere(CC)
    Bautura(const Bautura& other)
        :pretPreparare(other.pretPreparare), timpPreparare(other.timpPreparare), nrIngrediente(other.nrIngrediente)
    {
        if (other.numeBautura)
        {
            numeBautura = new char[std::strlen(other.numeBautura) + 1];
            std::strcpy(numeBautura, other.numeBautura);
        }
        else numeBautura = nullptr;

        if (other.listaIngrediente)
        {
            listaIngrediente = new Ingredient[other.nrIngrediente];
            for (int i=0; i<other.nrIngrediente; i++)
                listaIngrediente[i] = other.listaIngrediente[i]; // Se bazează pe op= din Ingredient
        }
        else listaIngrediente = nullptr;
    }

    ///Operator de copiere(op=)
    Bautura& operator=(const Bautura& other)
    {
        ///eliberez memoria
        if (this!=&other)
        {
            delete[] numeBautura;
            delete[] listaIngrediente;

            ///copiez datele vechi
            pretPreparare=other.pretPreparare;
            timpPreparare=other.timpPreparare;
            nrIngrediente=other.nrIngrediente;

            ///aloc spatiu si copiez noul nume
            if (other.numeBautura)
            {
                numeBautura = new char[std::strlen(other.numeBautura) + 1];
                std::strcpy(numeBautura, other.numeBautura);
            }
            else numeBautura = nullptr;

            if (other.listaIngrediente)
            {
                listaIngrediente = new Ingredient[other.nrIngrediente];
                for (int i=0; i<other.nrIngrediente; ++i)
                {
                    listaIngrediente[i] = other.listaIngrediente[i]; // Se bazează pe op= din Ingredient
                }
            }
            else listaIngrediente = nullptr;
        }
        return *this;

    }
    ///Destructor
    ~Bautura()
    {
        delete[] numeBautura;
        delete[] listaIngrediente;
    }

    ///Getteri
    const char* getNumeBautura() const
    {
        return numeBautura;
    }
    int getTimpPreparare() const
    {
        return timpPreparare;
    }
    float getPretPreparare() const
    {
        return pretPreparare;
    }

    int getNrIngrediente() const
    {
        return nrIngrediente;
    }


    float calculeazaPret() const
    {
        float pretTotal=0;
        for(int i=0; i<nrIngrediente; i++)
        {
            pretTotal+=listaIngrediente[i].getPret();
        }
        return pretTotal;
    }

    float calculeazaKcal() const
    {
        float kcalTotal=0;
        for(int i=0; i<nrIngrediente; i++)
        {
            kcalTotal+=listaIngrediente[i].getKcal();
        }
        return kcalTotal;
    }

    bool verificaVegan() const
    {
        bool ok=true;
        for(int i=0; i<nrIngrediente; i++)
        {
            if(listaIngrediente[i].getVegan()==0)
                ok=false;
        }
        return ok;
    }

    double aplicareReducere20() const
    {
        double pretRedus=calculeazaPret();
        if(verificaVegan()==true)
            pretRedus-=pretRedus*20/100;

        return pretRedus;
    }

    bool verificaStoc()
    {
        bool ok=true;
        for(int i=0; i<nrIngrediente; i++)
        {
            if(listaIngrediente[i].getStoc()==0)
                ok=false;
        }
        return ok;
    }


    ///Friend pentru operatori
    friend std::istream& operator>>(std::istream& is, Bautura& bau)
    {
        char copie[300];
        if(is>>copie>>bau.pretPreparare>>bau.timpPreparare>>bau.nrIngrediente)
        {
            delete[] bau.numeBautura;
            bau.numeBautura=new char[std::strlen(copie)+1];
            std::strcpy(bau.numeBautura, copie);

            delete[] bau.listaIngrediente;
            bau.listaIngrediente=new Ingredient[bau.nrIngrediente];

            for(int i=0; i<bau.nrIngrediente; i++)
            {
                char numeIng[100];
                is>>numeIng;

                bau.listaIngrediente[i].setNume(numeIng);
            }
        }

        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Bautura& bau)
    {
        os<<"Nume: " << bau.numeBautura <<", pret preparare: " <<bau.pretPreparare<<", timp preparare: "<<bau.timpPreparare<<", lista de ingrediente: ";
        for(int i=0; i<bau.nrIngrediente-1; i++)
        {
            os<<bau.listaIngrediente[i].getNume()<<", ";
        }
        os<<bau.listaIngrediente[bau.nrIngrediente-1].getNume()<<"\n";
        return os;
    }
};


class comanda {
    ///numar comanda
    ///lista produse comandate
    ///indice-in perparare, nu se poate prepara-stoc indisponibil, finalizare comanda
    ///operator de afisare a comenzii care sa includ bautura, ingrediente plus specificatii extra, pret=bon
    ///functie de verificare disponibilitate
    ///tips?
    ///timp de preparare, furnizare ora la care este gata comanda
    ///ingrediente extra
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