/**
 * \file vehicledriverstate.h
 * \brief Plik nagłówkowy dla klasy VehicleDriverState.
 *
 * Ten plik zawiera deklarację klasy VehicleDriverState, która jest abstrakcyjną klasą
 * bazową dla stanów kierowcy pojazdu. Klasa ta definiuje interfejs dla zarządzania stanami
 * kierowcy w symulacji.
 */

#ifndef VEHICLEDRIVERSTATE_H
#define VEHICLEDRIVERSTATE_H

#include <string>

class Vehicle;

/**
 * \class VehicleDriverState
 * \brief Abstrakcyjna klasa bazowa dla stanów kierowcy pojazdu.
 *
 * Klasa VehicleDriverState jest abstrakcyjną klasą bazową, która definiuje interfejs
 * dla zarządzania stanami kierowcy pojazdu. Każdy konkretny stan kierowcy powinien
 * dziedziczyć z tej klasy i implementować metody UpdateState i GetStateName.
 */
class VehicleDriverState
{
public:
    /**
     * \brief Aktualizuje stan kierowcy na podstawie stanu pojazdu.
     * \param vehicle Wskaźnik do pojazdu, którego stan ma być aktualizowany.
     *
     * Metoda ta aktualizuje stan kierowcy w zależności od stanu pojazdu.
     */
    virtual void UpdateState(Vehicle * vehicle) = 0;

    /**
     * \brief Pobiera nazwę bieżącego stanu kierowcy.
     * \return Nazwa bieżącego stanu kierowcy jako ciąg znaków.
     *
     * Metoda ta zwraca nazwę bieżącego stanu kierowcy.
     */
    virtual std::string GetStateName() = 0;
};

#endif // VEHICLEDRIVERSTATE_H
