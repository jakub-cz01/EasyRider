/**
 * \file simulatedobject.h
 * \brief Plik nagłówkowy dla klasy SimulatedObject.
 *
 * Ten plik zawiera deklarację klasy SimulatedObject, która stanowi bazową klasę dla
 * obiektów w symulacji, które wymagają aktualizacji w czasie rzeczywistym.
 */

#ifndef SIMULATEDOBJECT_H
#define SIMULATEDOBJECT_H

#include<string>


/**
 * \class SimulatedObject
 * \brief Bazowa klasa dla obiektów w symulacji.
 *
 * Klasa SimulatedObject stanowi bazę dla obiektów, które biorą udział w symulacji.
 * Zapewnia metodę do aktualizacji obiektu oraz unikalny identyfikator dla każdego obiektu.
 */
class SimulatedObject
{
public:
    /**
     * \brief Konstruktor obiektu SimulatedObject.
     *
     * Konstruktor inicjalizuje obiekt SimulatedObject i przypisuje mu unikalny identyfikator.
     */
    SimulatedObject();

    /**
     * \brief Metoda wirtualna do aktualizacji obiektu.
     * \param deltaTime Czas, który upłynął od ostatniej aktualizacji w milisekundach.
     *
     * Ta czysta metoda wirtualna musi być zaimplementowana przez klasy pochodne i jest
     * używana do aktualizacji stanu obiektu w symulacji.
     */
    virtual void Update(int deltaTime) = 0;

    /**
     * \brief Pobiera identyfikator obiektu symulowanego.
     * \return Identyfikator obiektu symulowanego.
     *
     * Metoda ta zwraca unikalny identyfikator obiektu symulowanego.
     */
    int GetSimulatedObjectId() const;

    /**
     * \brief Destruktor obiektu SimulatedObject.
     *
     * Wirtualny destruktor, umożliwiający prawidłowe zwolnienie pamięci przez obiekty pochodne.
     */
    virtual ~SimulatedObject();
private:
    int m_Id; ///< Unikalny identyfikator obiektu symulowanego.
};

#endif // SIMULATEDOBJECT_H
