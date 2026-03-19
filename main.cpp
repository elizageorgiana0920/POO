#include<iostream>
#include<fstream>

std::ifstream fin ("date.in");
std::ofstream fout ("date.out");
class bautura {
    ///denumire
    ///pret preparare
    ///reteta de unde mostenesc ingrediente
    ///+ingrediente extra
    ///timp de preparare
    ///constructor explicit bautura
    ///constructor de copiere
    ///operatorul=
    ///destructorul
    ///functie pentru pretul final in care adaug pret preparare+pretul fiecarui ingredient
    ///functie pentru reducere procent
    ///verifica disponibilitae
};
class ingredient {
    ///cantitate pe stoc
    ///nume ingredient
    ///pret ingredient client
    ///pret ingredient cu care a fost cumparat
    ///atribute private accesibile prin getters
    ///functie de suplimentare stoc
    ///adaugare ingrediente
    ///categorii vegane, non-vegane
    ///sugar free

};
class comanda {
    ///numar comanda
    ///lista produse comandate
    ///indice-in perparare, nu se poate prepara-stoc indisponibil, finalizare comanda
    ///operator de afisare a comenzii care sa includ bautura, ingrediente plus specificatii extra, pret=bon
    ///functie de verificare disponibilitate
    ///tips?
    ///timp de preparare
};

///++generare de raport zilinic cu inasari =profit etc.
int main() {
    return 0;
}