/**
 * \file genericdistance.h
 * \brief Plik nagłówkowy z funkcją szacującą odległość między dwoma punktami.
 *
 * Ten plik zawiera definicję szablonowej funkcji GDistance, która oblicza
 * odległość euklidesową między dwoma punktami, które mogą być różnych typów (QPointF i QVector2D).
 */

#ifndef GENERICDISTANCE_H
#define GENERICDISTANCE_H
#include <QtMath>

#endif // GENERICDISTANCE_H

/**
 * \brief Oblicza odległość euklidesową między dwoma punktami.
 * \tparam T1 Typ pierwszego punktu.
 * \tparam T2 Typ drugiego punktu.
 * \param point1 Pierwszy punkt.
 * \param point2 Drugi punkt.
 * \return Odległość euklidesowa między dwoma punktami jako wartość typu double.
 *
 * Funkcja ta oblicza odległość euklidesową między dwoma punktami. Typy punktów
 * muszą mieć metody x() i y() zwracające współrzędne punktów.
 */

template <typename T1, typename T2>
double GDistance(const T1& point1, const T2& point2) {
    return qSqrt(qPow(point1.x() - point2.x(), 2) + qPow(point1.y() - point2.y(), 2));
}
