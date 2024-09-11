/**
 * \file vehicledriver.h
 * \brief Plik nagłówkowy dla klasy VehicleDriver.
 *
 * Ten plik zawiera deklarację klasy VehicleDriver, która zarządza stanem kierowcy
 * pojazdu. Klasa ta wykorzystuje obiekt VehicleDriverState do oceny i aktualizacji
 * stanu kierowcy w symulacji.
 */


#ifndef VEHICLEDRIVER_H
#define VEHICLEDRIVER_H

#include "vehicledriverstate.h"
#include <string>

class Vehicle;

/**
 * \class VehicleDriver
 * \brief Zarządza stanem kierowcy pojazdu.
 *
 * Klasa VehicleDriver jest odpowiedzialna za zarządzanie stanem kierowcy pojazdu,
 * w tym za ocenę i aktualizację stanu kierowcy na podstawie otoczenia pojazdu.
 */
class VehicleDriver
{
public:
    /**
     * \brief Konstruktor obiektu VehicleDriver.
     * \param parent Wskaźnik do pojazdu, którym kierowca steruje.
     *
     * Inicjalizuje nową instancję klasy VehicleDriver z określonym pojazdem.
     */
    VehicleDriver(Vehicle * parent);

    /**
     * \brief Pobiera nazwę bieżącego stanu kierowcy.
     * \return Nazwa bieżącego stanu kierowcy jako ciąg znaków.
     *
     * Metoda ta zwraca nazwę bieżącego stanu kierowcy pojazdu.
     */
    std::string GetStateName();

    /**
     * \brief Aktualizuje stan kierowcy, gdy jest to wymagane.
     *
     * Metoda ta ocenia obecny stan kierowcy i aktualizuje go na podstawie informacji z otoczenia pojazdu.
     */
    void EvaluateState();
private:
    Vehicle * m_Vehicle; ///< Wskaźnik do pojazdu zarządzanego przez kierowcę.
    VehicleDriverState * m_VehicleDriverState; ///< Obiekt reprezentujący aktualny stan kierowcy.
};

#endif // VEHICLEDRIVER_H
