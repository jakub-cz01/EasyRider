/**
 * \file spawnpoint.h
 * \brief Plik nagłówkowy dla klasy SpawnPoint.
 *
 * Ten plik zawiera deklarację klasy SpawnPoint, która jest klasą pochodną
 * klasy StreetMapNode i reprezentuje punkt startowy (końcowy) na mapie.
 */

#ifndef SPAWNPOINT_H
#define SPAWNPOINT_H

#include "streetmapnode.h"

/**
 * \class SpawnPoint
 * \brief Reprezentuje punkt startowy (końcowy) na mapie.
 *
 * Klasa SpawnPoint dziedziczy po klasie StreetMapNode i reprezentuje punkt startowy
 * na mapie ulic. Klasa ta dodaje unikalny identyfikator dla każdego punktu startowego.
 */
class SpawnPoint : public StreetMapNode
{
public:
    /**
     * \brief Konstruktor obiektu SpawnPoint.
     * \param row Wiersz w siatce mapy, w którym znajduje się punkt startowy.
     * \param column Kolumna w siatce mapy, w której znajduje się punkt startowy.
     * \param size Rozmiar punktu startowego.
     *
     * Konstruktor inicjalizuje obiekt SpawnPoint na podstawie przekazanych parametrów
     * oraz przypisuje unikalny identyfikator punktowi startowemu.
     */
    SpawnPoint(int row, int column, int size);
private:
    static int m_IdCounter; ///< Licznik generatora identyfikatorów punktów startowych.
    int m_SpawnPointId; ///< Unikalny identyfikator punktu startowego.
};

#endif // SPAWNPOINT_H
