/**
 * \file straightstreet.h
 * \brief Plik nagłówkowy dla klasy StraightStreet.
 *
 * Ten plik zawiera deklarację klasy StraightStreet, która jest klasą pochodną
 * klasy StreetMapNode i reprezentuje prostą ulicę na mapie.
 */

#ifndef STRAIGHTSTREET_H
#define STRAIGHTSTREET_H

#include "streetmapnode.h"

/**
 * \class StraightStreet
 * \brief Reprezentuje prostą ulicę na mapie.
 *
 * Klasa StraightStreet dziedziczy po klasie StreetMapNode i reprezentuje prostą
 * ulicę na mapie ulic.
 */
class StraightStreet : public StreetMapNode
{
public:

    /**
     * \brief Konstruktor obiektu StraightStreet.
     * \param vertical Flaga określająca, czy ulica jest pionowa (true) czy pozioma (false).
     * \param row Wiersz w siatce mapy, w którym znajduje się ulica.
     * \param column Kolumna w siatce mapy, w której znajduje się ulica.
     * \param size Rozmiar ulicy.
     *
     * Konstruktor inicjalizuje obiekt StraightStreet na podstawie przekazanych parametrów.
     */
    StraightStreet(bool vertical, int row, int column, int size);
private:
    bool m_IsVertical; ///< Flaga określająca, czy ulica jest pionowa.
};

#endif // STRAIGHTSTREET_H
