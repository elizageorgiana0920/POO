# Eliza's coffee shop - Gestiune

La cafeneaua "Eliza's coffee shop" se testeaza o noua aplicatie software de gestiune a comenzilor, a stocului si a profitului cafenelei.
Aplicatia este echipata cu un meniu interactiv care face facila utilizarea acesteia de catre personal sau clienti. Programarea aplicatiei s-a realizat folosind conceptele POO.

---

### Clasele principale:

* **clasa Ingredient**, avand campurile:
    * nume(sir de caractere de dimensiune variabila, reprezentand denumirea ingredientelor)
    * stoc (intreg, reprezentand cantitatea disponibila din fiecare ingredient)
    * pret (float, reprezentand pretul ingredientului)
    * vegan(bool, care retine daca ingredientul este sau nu vegan)
    * faraZahar(bool, care retine daca ingredientul contine sau nu zahar)
    * kcal(float, reprezentand numarul de kilocalorii pentru fiecare ingredient).

* **clasa Bautura**, avand campurile:
    * numeBautura(sir de caractere de dimensiune variabila, reprezentand denumirea bauturii)
    * pretPreparare(float, reprezentand costul de preparare a bauturii-se duce spre barista)
    * nrIngrediente(intreg, reprezentand numarul de ingrediente pe care le contine bautura)
    * listaIngrediente (pointer către tipul Ingredient, utilizat pentru a gestiona un tablou alocat dinamic de obiecte, reprezentând compoziția fiecărei băuturi).

* **clasa Comanda**, avand campurile:
    * profitVanzari(atribut static, reprezentand profitul incasat de cafenea dupa vanzari)
    * nrTotalComenzi(atribut static intreg, reprezentand numarul total de comenzi)
    * numeClient(sir de caractere de dimensiune variabila, reprezentand numele clientului care initiaza comanda)
    * nrBauturiComandate(intreg, reprezentand numarul de bauturi comandate pe comanda)
    * listaBauturi(pointer catre tipul Bautura, utilizat pentru a gestiona bauturile din comanda)
    * totalPlata(float, reprezentand pretul final al unei comenzi)
    * oraComandata(sir de caractere de dimensiune variabila, reprezentand ora la care se initiaza comanda).

---

### Operatii disponibile:

Cu ajutorul acestei aplicatii software se pot face operatii precum:
* aprovizionare stoc;
* calculare profit;
* filtrare produse dupa ingrediente;
* initierea unei comenzi si calcularea pretului, timpului de asteptare si a valorilor nutritionale;
* consultarea meniului cu produse exclusiv pe stoc;
* afisarea specificatiilor pentru o anumita bautura;