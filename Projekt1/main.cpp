#include "Projekt1.cpp"
#include <iostream>

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