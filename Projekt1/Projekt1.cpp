#include <iostream>

using namespace std;
/// Struktura przedstawiająca węzeł listy dwukierunkowej.
struct wezly {
    int dane; ///< Przechowuje dane w węźle.
    wezly* nastepny; ///< Wskaźnik na następny węzeł.
    wezly* poprzedni; ///< Wskaźnik na poprzedni węzeł.
};
/**
 * @brief Klasa reprezentująca listę dwukierunkową.
 */
class ListaDwukierunkowa {
private:
    wezly* glowa; ///< Wskaźnik na pierwszy element listy.
    wezly* ogon; ///< Wskaźnik na ostatni element listy.
    wezly* obecny; ///< Wskaźnik na obecny element na liście.
public:
    /// Domyślny konstruktor listy dwukierunkowej.
    ListaDwukierunkowa(void): glowa(NULL), ogon(NULL), obecny(NULL) {}
    /// Destruktor listy dwukierunkowej, usuwa on wszystkie elementy z listy.
    ~ListaDwukierunkowa(void) {
        wyczysc();
    }
    /// Dodaje element na początek listy.
    /// @param x Wartość do dodania na początku.
    void dodajNApoczatek(int x) {
        wezly* element = new wezly;
        element->dane = x;
        element->poprzedni = NULL;
        element->nastepny = glowa;
        if (glowa) {
            glowa->poprzedni = element;
        }
        else {
            ogon = element;
        }
        glowa = element;
    }   
    /// Dodaje element na koniec listy.
    /// @param x Wartość do dodania na końcu.
    void dodajNAkoniec(int x) {
        wezly* element = new wezly;
        element->dane = x;
        element->nastepny = NULL;
        element->poprzedni = ogon;
        if (ogon) {
            ogon->nastepny = element;
        }
        else {
            glowa = element;
        }
        ogon = element;
    }
    /// Dodaje element na wybranym indeksie w liście.
    /// @param numer Wartość do dodania.
    /// @param pozycja Indeks, na którym ma zostać dodany element.
    void dodajNAindeks(int numer, int pozycja) {
        if (pozycja  < 0) {
            cout << "Blad." << endl;
            return;
        }
        if (pozycja == 0) {
            dodajNApoczatek(numer);
        }
        wezly* obecny = glowa;
        wezly* x = new wezly;
        x->dane = numer;
        int i = 0;
        while (i < pozycja - 1 && obecny != NULL) {
            obecny = obecny->nastepny;
            i++;
        }
        if (obecny == NULL) {
            dodajNAkoniec(numer);
        }
        else {
            x->nastepny = obecny->nastepny;
            x->poprzedni = obecny;
            obecny->nastepny = x;
            if (x->nastepny != NULL) {
                x->nastepny->poprzedni = x;
            }
        }
    }
    /// Usuwa element z początku listy.
    void usunZpoczatek(void) {
        wezly* x = glowa;
        if (x) {
            glowa = glowa->nastepny;
            if (!glowa) {
                ogon = NULL;
            }
            else {
                glowa->poprzedni = NULL;
            }
            delete x;
        }
    }
    /// Usuwa element z końca listy.
    void usunZkoniec(void) {
        wezly* x = ogon;
        if (x) {
            ogon = ogon->poprzedni;
            if (!ogon) {
                glowa = NULL;
            }
            else {
                ogon->nastepny = NULL;
            }
            delete x;
        }
    }
    /// Usuwa element z określonego indeksu w liście.
    /// @param pozycja Indeks, z którego ma zostać usunięty element.
    void usunZindeks(int pozycja) {
        if (pozycja < 0) {
            cout << "Blad." << endl;
            return;
        }
        if (pozycja == 0) {
            usunZpoczatek();
        }
        wezly* obecny = glowa;
        int i = 0;
        while (i < pozycja && obecny != NULL) {
            obecny = obecny->nastepny;
            i++;
        }
        if (obecny == NULL) {
            return;
        }
        if (obecny->poprzedni) {
            obecny->poprzedni->nastepny = obecny->nastepny;
        }
        if (obecny->nastepny) {
            obecny->nastepny->poprzedni = obecny->poprzedni;
        }
        if (obecny == ogon) {
            ogon = obecny->poprzedni;
        }
        delete obecny;
    }
    /// Wyświetla elementy listy w kolejności od początku do końca.
    void wyswietl(void) {
        wezly* x;
        cout << "Lista wyglada nastepujaco: " << endl;
        for (x = glowa; x; x= x->nastepny) {
            cout << x->dane << " ";
            }
        cout << endl;
    }
    /// Wyświetla elementy listy w odwrotnej kolejności, od końca do początku.
    void wyswietlodwrotnie(void) {
        wezly* x = ogon;
        cout << "Lista po odwroceniu wyglada nastepujaco: " << endl;
        while (x) {
            cout << x->dane << " ";
            x = x->poprzedni;
        }
        cout << endl;
    }
    /// Wyświetla kolejny element w stosunku do obecnego elementu listy.
    void wyswietlnastepny(void) {
        if (obecny == NULL) {
            obecny = glowa;

        }
        else {
            if (obecny->nastepny != NULL) {
                obecny = obecny->nastepny;
            }
            else {
                cout << "Koniec listy, brak nastepnego." << endl;
            }
        }
        cout << "Nastepny element to: " << obecny->dane << endl;
    }
    /// Wyświetla poprzedni element w stosunku do obecnego elementu listy.
    void wyswietlpoprzedni(void) {
        if (obecny == NULL) {
            cout << "Poczatek listy, brak poprzednika." << endl;
            return;
        }
        wezly* x = obecny->poprzedni;
        if (x != NULL) {
            cout << "Poprzedni element to: " << x->dane << endl;
            obecny = x;
        }
        else {
            cout << "Poczatek listy, brak poprzednika." << endl;
        }
    }
    /// Czyści listę, usuwając wszystkie elementy.
    void wyczysc(void) {
        wezly* x;
        while (ogon) {
            x = ogon;
            ogon = x->poprzedni;
            delete x;
        }
        glowa = NULL;
    }
};
