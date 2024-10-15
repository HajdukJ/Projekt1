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
public:
    ListaDwukierunkowa(void): glowa(NULL), ogon(NULL) {}
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
    void dodajNAindeks(void) {

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
    void usunZindeks(void) {
            
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
    }
};

int main()
{
    ListaDwukierunkowa lista;
    for (int i = 1; i <= 10; i++) {
        lista.dodajNAkoniec(i);
    }
    lista.wyswietl();
    lista.usunZpoczatek();
    lista.wyswietl();
    lista.usunZkoniec();
    lista.wyswietl();
    lista.dodajNAkoniec(8);
    lista.wyswietl();
    lista.dodajNApoczatek(3);
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
    lista.wyswietlodwrotnie();
    lista.wyczysc();
    lista.wyswietl();
    return 0;
}