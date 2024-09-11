/**
 * \file drivingstate.h
 * \brief Plik nagłówkowy dla klasy DrivingState.
 *
 * Ten plik zawiera deklarację klasy DrivingState, która jest konkretną implementacją
 * stanu kierowcy pojazdu. Klasa ta dziedziczy po klasie VehicleDriverState i
 * implementuje stan jazdy, gdy w otoczeniu pojazdu nie są wykryte przeszkody.
 */

#ifndef DRIVINGSTATE_H
#define DRIVINGSTATE_H

#include "vehicledriverstate.h"
#include "vehicle.h"


/**
 * \class DrivingState
 * \brief Konkretny stan kierowcy pojazdu reprezentujący jazdę.
 *
 * Klasa DrivingState jest konkretną implementacją stanu kierowcy pojazdu, który
 * odpowiada za jazdę, gdy w otoczeniu nie ma przeszkód.
 */
class DrivingState : public VehicleDriverState
{
public:

    /**
     * \brief Konstruktor obiektu DrivingState.
     *
     * Inicjalizuje nową instancję klasy DrivingState.
     */
    DrivingState();

    /**
     * \brief Aktualizuje stan.
     * \param vehicle Wskaźnik do pojazdu związanego z klasą kierowcy.
     *
     * Metoda ta ustawia przyspieszenie pojazdu na maksymalne.
     */
    void UpdateState(Vehicle * vehicle) override;

    /**
     * \brief Pobiera nazwę bieżącego stanu kierowcy.
     * \return Nazwa bieżącego stanu kierowcy jako ciąg znaków.
     *
     * Metoda ta zwraca nazwę stanu jazdy jako ciąg znaków.
     */
    std::string GetStateName() override;
};

#endif // DRIVINGSTATE_H
