#include "Projekt1.cpp" ///< Do��cza plik nag��wkowy zawieraj�cy klas� ListaDwukierunkowa.
#include <iostream>

/// Funkcja g��wna programu.

int main()
{
    ListaDwukierunkowa lista; ///< Tworzy now� list�.
    // Dodaje elementy od 1 do 8 na koniec listy.
    for (int i = 1; i <= 8; i++) {
        lista.dodajNAkoniec(i);
    }
    lista.wyswietl(); ///< Wy�wietla obecny stan listy.
    lista.usunZpoczatek(); ///< Usuwa pierwszy element listy.
    lista.usunZkoniec(); ///< Usuwa ostatni element listy.
    lista.usunZindeks(3); ///< Usuwa element znajduj�cy si� na indeksie 3.
    lista.wyswietl(); ///< Wy�wietla stan listy po zmianach.
    lista.dodajNApoczatek(77); ///< Dodaje 77 na pocz�tek listy.
    lista.dodajNAkoniec(82); ///< Dodaje 82 na koniec listy.
    lista.dodajNAindeks(52, 4); ///< Dodaje 52 na indeksie 4.
    lista.wyswietl(); ///< Wy�wietla stan listy po zmianach. 
    // Wy�wietla kolejne elementy od obecnego.
    lista.wyswietlnastepny();
    lista.wyswietlnastepny();
    lista.wyswietlnastepny();
    // Wy�wietla poprzednie elementy od obecnego.
    lista.wyswietlpoprzedni();
    lista.wyswietlpoprzedni();
    lista.wyswietlpoprzedni();
    lista.wyswietlodwrotnie(); ///< Wy�wietla list� w kolejno�ci odwrotnej.
    lista.wyczysc(); ///< Czy�ci list�, usuwaj�c wszystkie elementy.
    lista.wyswietl(); ///< Wy�wietla stan listy po jej wyczyszczeniu.
    return 0; ///< Zwraca 0, ko�cz�c program.
}