/**
 * \file intersection.h
 * \brief Plik nagłówkowy dla klasy Intersection.
 *
 * Ten plik zawiera deklarację klasy Intersection, która jest klasą pochodną
 * klasy StreetMapNode i reprezentuje skrzyżowanie na mapie ulic.
 */

#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "streetmapnode.h"
#include "trafficlight.h"
#include "movedirection.h"

/**
 * \class Intersection
 * \brief Reprezentuje skrzyżowanie na mapie ulic.
 *
 * Klasa Intersection dziedziczy po klasie StreetMapNode i reprezentuje skrzyżowanie,
 * zawierajće sygnalizatory świetlne dla różnych kierunków ruchu. Klasa ta
 * umożliwia określenie stanu sygnalizatora świetlnego w zależności od kierunku ruchu.
 */
class Intersection: public StreetMapNode
{
public:
    /**
     * \brief Konstruktor obiektu Intersection.
     * \param row Wiersz w siatce mapy, w którym znajduje się skrzyżowanie.
     * \param column Kolumna w siatce mapy, w której znajduje się skrzyżowanie.
     * \param size Rozmiar skrzyżowania w pikselach.
     *
     * Konstruktor inicjalizuje obiekt Intersection na podstawie przekazanych parametrów.
     */
    Intersection(int row, int column, int size);

    /**
     * \brief Sprawdza, czy obiekt jest skrzyżowaniem.
     * \return Zwraca true.
     *
     * Metoda ta nadpisuje metodę bazową IsIntersection i zawsze zwraca true,
     * wskazując, że obiekt jest skrzyżowaniem.
     */
    bool IsIntersection() override;

    /**
     * \brief Pobiera stan sygnalizatora świetlnego dla określonego kierunku ruchu.
     * \param direction Kierunek ruchu, dla którego ma być pobrany stan sygnalizatora.
     * \return Stan sygnalizatora świetlnego dla określonego kierunku.
     *
     * Metoda ta zwraca stan sygnalizatora świetlnego (czerwony, żółty, zielony)
     * dla podanego przybliżonego kierunku ruchu.
     */
    TrafficLightState GetTrafficLightStateFromDirection(MoveDirection direction);
private:
    TrafficLight * m_BottomLeftLight; ///< Sygnalizator świetlny w lewym dolnym rogu skrzyżowania.
    TrafficLight * m_BottomRightLight; ///< Sygnalizator świetlny w prawym dolnym rogu skrzyżowania.
    TrafficLight * m_TopLeftLight; ///< Sygnalizator świetlny w lewym górnym rogu skrzyżowania.
    TrafficLight * m_TopRightLight; ///< Sygnalizator świetlny w prawym górnym rogu skrzyżowania.
};

#endif // INTERSECTION_H
