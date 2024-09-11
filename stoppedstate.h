/**
 * \file stoppedstate.h
 * \brief Plik nagłówkowy dla klasy StoppedState.
 *
 * Ten plik zawiera deklarację klasy StoppedState, która jest konkretną implementacją
 * stanu kierowcy pojazdu, reprezentującą stan zatrzymania.
 */

#ifndef STOPPEDSTATE_H
#define STOPPEDSTATE_H
#include "vehicledriverstate.h"
#include "vehicle.h"


/**
 * \class StoppedState
 * \brief Konkretny stan kierowcy pojazdu reprezentujący stan zatrzymania.
 *
 * Klasa StoppedState jest konkretną implementacją stanu kierowcy pojazdu, który
 * odpowiada za kontrolowanie pojazdu w stanie zatrzymania. Klasa ta dziedziczy
 * z klasy VehicleDriverState i implementuje metody potrzebne do zarządzania stanem
 * zatrzymania.
 */
class StoppedState : public VehicleDriverState
{
public:
    /**
     * \brief Konstruktor obiektu StoppedState.
     *
     * Inicjalizuje nową instancję klasy StoppedState.
     */
    StoppedState();

    /**
     * \brief Aktualizuje stan.
     * \param vehicle Wskaźnik do pojazdu związanego z klasą kierowcy.
     *
     * Metoda ta ustawia przyspieszenie pojazdu na -1, w celu zatrzymania go.
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

#endif // STOPPEDSTATE_H
