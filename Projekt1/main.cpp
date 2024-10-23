#include "Projekt1.cpp" ///< Do³¹cza plik nag³ówkowy zawieraj¹cy klasê ListaDwukierunkowa.
#include <iostream>

/// Funkcja g³ówna programu.

int main()
{
    ListaDwukierunkowa lista; ///< Tworzy now¹ listê.
    // Dodaje elementy od 1 do 8 na koniec listy.
    for (int i = 1; i <= 8; i++) {
        lista.dodajNAkoniec(i);
    }
    lista.wyswietl(); ///< Wyœwietla obecny stan listy.
    lista.usunZpoczatek(); ///< Usuwa pierwszy element listy.
    lista.usunZkoniec(); ///< Usuwa ostatni element listy.
    lista.usunZindeks(3); ///< Usuwa element znajduj¹cy siê na indeksie 3.
    lista.wyswietl(); ///< Wyœwietla stan listy po zmianach.
    lista.dodajNApoczatek(77); ///< Dodaje 77 na pocz¹tek listy.
    lista.dodajNAkoniec(82); ///< Dodaje 82 na koniec listy.
    lista.dodajNAindeks(52, 4); ///< Dodaje 52 na indeksie 4.
    lista.wyswietl(); ///< Wyœwietla stan listy po zmianach. 
    // Wyœwietla kolejne elementy od obecnego.
    lista.wyswietlnastepny();
    lista.wyswietlnastepny();
    lista.wyswietlnastepny();
    // Wyœwietla poprzednie elementy od obecnego.
    lista.wyswietlpoprzedni();
    lista.wyswietlpoprzedni();
    lista.wyswietlpoprzedni();
    lista.wyswietlodwrotnie(); ///< Wyœwietla listê w kolejnoœci odwrotnej.
    lista.wyczysc(); ///< Czyœci listê, usuwaj¹c wszystkie elementy.
    lista.wyswietl(); ///< Wyœwietla stan listy po jej wyczyszczeniu.
    return 0; ///< Zwraca 0, koñcz¹c program.
}