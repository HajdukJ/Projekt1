#include <iostream>

using namespace std;

struct wezly {
    int dane;
    wezly* nastepny;     
    wezly* poprzedni; // przechowuje na poczatku wskaznik pusty ( zero, nie wskazuje elementu ) null
};

class ListaDwukierunkowa {
private:
    int licznik;
    wezly* glowa;
    wezly* ogon;
public:
    ListaDwukierunkowa(void): glowa(NULL), ogon(NULL), licznik(0) {}
    ~ListaDwukierunkowa(void) {
        wyczysc();  //dopisac do metody wyczysc
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
        licznik++;
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
        licznik++;
    }
    void dodajNAindeks(void) {

    }
    void usunZpoczatek(void) {

    }
    void usunZkoniec(void) {

    }
    void usunZindeks(void) {
            
    }
    void wyswietl(void) {
        wezly* x;
        cout << "Lista prezentuje sie nastepujaco: " << endl;
        for (x = glowa; x; x= x->nastepny) {
            cout << x->dane << " ";
            }
    }
    void wyswietlodwrotnie(void) {

    }
    void wyswietlnastepny(void) {

    }
    void wyswietlpoprzedni(void) {

    }
    void wyczysc(void) {
        wezly* x;
        while (ogon) {
            x = ogon;
            ogon = x->poprzedni;
            delete x;
        }
        glowa = NULL;
        licznik = 0;
    }
};

int main()
{
    ListaDwukierunkowa lista;
    for (int i = 1; i <= 10; i++) {
        lista.dodajNAkoniec(i);
    }
    lista.wyswietl();
    /*
    lista.dodajNApoczatek();
    lista.dodajNAkoniec();
    lista.dodajNAindeks();
    lista.usunZpoczatek();
    lista.usunZkoniec();
    lista.usunZindeks();
    lista.wyswietl();
    lista.wyswietlodwrotnie();
    lista.wyswietlnastepny();
    lista.wyswietlpoprzedni();
    lista.wyczysc();
    */
    return 0;
}