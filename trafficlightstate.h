/**
 * \file trafficlightstate.h
 * \brief Plik nagłówkowy dla enumeracji TrafficLightState.
 *
 * Ten plik zawiera deklarację enumeracji TrafficLightState, która definiuje
 * możliwe stany sygnalizatora świetlnego w symulacji.
 */

#ifndef TRAFFICLIGHTSTATE_H
#define TRAFFICLIGHTSTATE_H

/**
 * \enum TrafficLightState
 * \brief Stany sygnalizatora świetlnego.
 *
 * Enumeracja TrafficLightState definiuje możliwe stany sygnalizatora świetlnego:
 * - Red: Światło czerwone
 * - Yellow: Światło żółte
 * - Green: Światło zielone
 */
enum class TrafficLightState {
    Red, ///< Światło czerwone
    Yellow, ///< Światło żółte
    Green, ///< Światło zielone
};

#endif // TRAFFICLIGHTSTATE_H
