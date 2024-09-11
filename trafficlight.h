/**
 * \file trafficlight.h
 * \brief Plik nagłówkowy klasy TrafficLight.
 *
 * Ten plik zawiera deklarację klasy TrafficLight, która reprezentuje
 * sygnalizację świetlną w symulacji. Klasa ta dziedziczy po QGraphicsPixmapItem
 * i implementuje interfejs SimulatedObject, dostarczając funkcjonalności
 * związane z zarządzaniem stanem sygnalizatora i jego aktualizacją.
 */

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <QGraphicsPixmapItem>
#include "trafficlightstate.h"
#include "simulatedobject.h"

/**
 * \class TrafficLight
 * \brief Reprezentuje sygnalizator świetlny.
 *
 * Klasa TrafficLight dziedziczy po QGraphicsPixmapItem i implementuje
 * interfejs SimulatedObject. Umożliwia zarządzanie stanem sygnalizatora
 * oraz jego aktualizację na podstawie upływu czasu.
 */

class TrafficLight : public QGraphicsPixmapItem, public SimulatedObject
{
public:
    /**
     * \brief Konstruktor obiektu TrafficLight.
     * \param offset Przesunięcie sygnalizatora w stosunku do rodzica.
     * \param size Rozmiar sygnalizatora.
     * \param initialState Początkowy stan sygnalizatora.
     * \param parent Wskaźnik do rodzica QGraphicsPixmapItem, jeśli istnieje.
     *
     * Inicjalizuje nową instancję klasy TrafficLight z określonym przesunięciem,
     * rozmiarem, początkowym stanem i opcjonalnym rodzicem.
     */
    TrafficLight(QPoint offset, QSize size, TrafficLightState initialState, QGraphicsPixmapItem *parent = nullptr);

    /**
     * \brief Ustawia stan sygnalizatora.
     * \param state Nowy stan sygnalizatora.
     *
     * Metoda ta ustawia stan sygnalizatora na podany w parametrze.
     */
    void SetState(TrafficLightState state);

    /**
     * \brief Pobiera aktualny stan sygnalizatora.
     * \return Aktualny stan sygnalizatora.
     *
     * Metoda ta zwraca obecny stan sygnalizatora.
     */
    TrafficLightState GetState();

    /**
     * \brief Aktualizuje stan sygnalizatora.
     * \param deltaTime Czas, który upłynął od ostatniej aktualizacji.
     *
     * Metoda ta aktualizuje stan sygnalizatora na podstawie upływu czasu.
     */
    void Update(int deltaTime) override;
private:
    TrafficLightState m_State; ///< Aktualny stan sygnalizatora.
    QSize m_Size; ///< Rozmiar sygnalizatora.
    int m_MsPerCycle{20000}; ///< Czas trwania cyklu w milisekundach.
    int m_Counter; ///< Licznik czasu.
    int m_PrevCounter; ///< Wartość licznika czasu z poprzedniej klatki symulacji.
    int m_YellowLightDuration; ///< Czas trwania żółtego światła.
    int m_YellowLightThreshold1; ///< Pierwszy próg czasowy dla żółtego światła.
    int m_YellowLightThreshold2; ///< Drugi próg czasowy dla żółtego światła.
};

#endif // TRAFFICLIGHT_H
