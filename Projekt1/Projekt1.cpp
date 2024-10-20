#include <iostream>

using namespace std;

struct wezly {
    int dane;
    wezly* nastepny;
    wezly* poprzedni;
};

class ListaDwukierunkowa {
private:
    wezly* glowa;
    wezly* ogon;
    wezly* obecny;
public:
    ListaDwukierunkowa(void): glowa(NULL), ogon(NULL), obecny(NULL) {}
    ~ListaDwukierunkowa(void) {
        wyczysc();
    }
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
    void wyswietl(void) {
        wezly* x;
        cout << "Lista wyglada nastepujaco: " << endl;
        for (x = glowa; x; x= x->nastepny) {
            cout << x->dane << " ";
            }
        cout << endl;
    }
    void wyswietlodwrotnie(void) {
        wezly* x = ogon;
        cout << "Lista po odwroceniu wyglada nastepujaco: " << endl;
        while (x) {
            cout << x->dane << " ";
            x = x->poprzedni;
        }
        cout << endl;
    }
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

int main()
{
    ListaDwukierunkowa lista;
    for (int i = 1; i <= 8; i++) {
        lista.dodajNAkoniec(i);
    }
    lista.wyswietl();
    lista.usunZpoczatek();
    lista.usunZkoniec();
    lista.usunZindeks(3);
    lista.wyswietl();
    lista.dodajNApoczatek(77);
    lista.dodajNAkoniec(82);
    lista.dodajNAindeks(52, 4);
    lista.wyswietl();
    lista.wyswietlnastepny();
    lista.wyswietlnastepny();
    lista.wyswietlnastepny();
    lista.wyswietlpoprzedni();
    lista.wyswietlpoprzedni();
    lista.wyswietlpoprzedni();
    lista.wyswietlodwrotnie();
    lista.wyczysc();
    lista.wyswietl();
    return 0;
}