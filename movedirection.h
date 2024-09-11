/**
 * \file movedirection.h
 * \brief Plik nagłówkowy dla enum MoveDirection.
 *
 * Ten plik zawiera definicję wyliczenia MoveDirection, które określa kierunki ruchu
 * w symulacji pojazdów.
 */

#ifndef MOVEDIRECTION_H
#define MOVEDIRECTION_H


/**
 * \enum MoveDirection
 * \brief Kierunki ruchu pojazdu.
 *
 * Enum MoveDirection definiuje cztery podstawowe kierunki ruchu pojazdu w symulacji:
 * Północ, Wschód, Południe i Zachód.
 */
enum class MoveDirection {
    North, ///< Kierunek północny.
    East, ///< Kierunek wschodni.
    South, ///< Kierunek południowy.
    West ///< Kierunek zachodni.
};

#endif // MOVEDIRECTION_H
