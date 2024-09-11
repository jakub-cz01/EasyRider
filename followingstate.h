/**
 * \file followingstate.h
 * \brief Plik nagłówkowy dla klasy FollowingState.
 *
 * Ten plik zawiera deklarację klasy FollowingState, która jest konkretną implementacją
 * stanu kierowcy pojazdu, reprezentującą jazdę za innym pojazdem.
 */

#ifndef FOLLOWINGSTATE_H
#define FOLLOWINGSTATE_H

#include "vehicledriverstate.h"


/**
 * \class FollowingState
 * \brief Konkretny stan kierowcy pojazdu reprezentujący jazdę za innym pojazdem.
 *
 * Klasa FollowingState jest konkretną implementacją stanu kierowcy pojazdu, który
 * odpowiada za kontrolowanie pojazdu, gdy znajduje się przed nim inny pojazd.
 */
class FollowingState : public VehicleDriverState
{
public:
    /**
     * \brief Konstruktor obiektu FollowingState.
     * \param toFollow Wskaźnik do pojazdu, za którym pojazd będzie podążał.
     *
     * Inicjalizuje nową instancję klasy FollowingState ze wskaźnikiem do pojazdu przed tym pojazdem.
     */
    FollowingState(Vehicle * toFollow);

    /**
     * \brief Aktualizuje stan.
     * \param vehicle Wskaźnik do pojazdu związanego z klasą kierowcy.
     *
     * Metoda ta aktualizuje dostosowuje prędkość pojazdu do prędkości pojazdu przed nim.
     */
    void UpdateState(Vehicle * vehicle) override;

    /**
     * \brief Pobiera nazwę bieżącego stanu kierowcy.
     * \return Nazwa bieżącego stanu kierowcy jako ciąg znaków.
     *
     * Metoda ta zwraca nazwę stanu jazdy jako ciąg znaków.
     */
    std::string GetStateName() override;
private:
    Vehicle * m_ToFollow; ///< Wskaźnik do pojazdu, który jedzie przed kierowcą.
};
#endif // FOLLOWINGSTATE_H
