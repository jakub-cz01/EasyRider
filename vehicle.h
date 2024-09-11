/**
 * \file vehicle.h
 * \brief Plik nagłówkowy klasy Vehicle.
 *
 * Ten plik zawiera deklarację klasy Vehicle, która reprezentuje pojazd w symulacji.
 * Klasa ta dziedziczy po QObject, QGraphicsPixmapItem i implementuje interfejs SimulatedObject,
 * oferując funkcjonalności związane z ruchem pojazdu, jego stanem oraz interakcją z mapą ulic.
 */

#ifndef VEHICLE_H
#define VEHICLE_H

#include "simulatedobject.h"
#include "vehicledriver.h"
#include <QVector2D>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include "movedirection.h"
#include "vehicledriverstate.h"
#include <string>

class StreetMapNode;

/**
 * \class Vehicle
 * \brief Reprezentuje pojazd w symulacji.
 *
 * Klasa Vehicle dziedziczy po QObject, QGraphicsPixmapItem i implementuje
 * interfejs SimulatedObject. Umożliwia zarządzanie ruchem pojazdu, jego prędkością,
 * kierunkiem ruchu oraz interakcją z otoczeniem, w tym z węzłami mapy ulic.
 */
class Vehicle: public QObject, public QGraphicsPixmapItem, public SimulatedObject
{
    Q_OBJECT
public:
    /**
     * \brief Konstruktor obiektu Vehicle.
     * \param path Ścieżka węzłów, przez które pojazd ma przejechać.
     *
     * Inicjalizuje nową instancję klasy Vehicle z określoną ścieżką węzłów.
     */
    Vehicle(std::vector<StreetMapNode *> path);

    /**
     * \brief Destruktor obiektu Vehicle.
     *
     * Zwalnia zasoby używane przez obiekt Vehicle, jednocześnie usuwając go ze sceny i symulacji.
     */
    ~Vehicle();

    /**
     * \brief Metoda sterująca pojazdem, pozwalająca wpływać na jego przyspieszenie.
     * \param acceleration Wartość przyspieszenia od -1 do 1.
     *
     * Metoda ta stosuje przyspieszenie do pojazdu, zmieniając jego prędkość, a także odpowiada za ruch i obrót pojazdu.
     */
    void ApplySteer(double acceleration);

    /**
     * \brief Aktualizuje stan pojazdu.
     * \param deltaTime Czas, który upłynął od ostatniej aktualizacji.
     *
     * Metoda ta aktualizuje stan pojazdu na podstawie upływu czasu.
     */
    void Update(int deltaTime) override;

    /**
     * \brief Pobiera kierunek ruchu pojazdu.
     * \return Kierunek ruchu pojazdu jako wektor 2D.
     *
     * Metoda ta zwraca kierunek ruchu pojazdu w postaci wektora 2D.
     */
    QVector2D GetMoveDirection() const;

    /**
     * \brief Pobiera przybliżony kierunek ruchu pojazdu do następnego węzła.
     * \param carPosition Pozycja pojazdu.
     * \param waypoint Wskaźnik do węzła, do którego pojazd ma się udać.
     * \return Enum - określający kierunek ruchu pojazdu jako 1 z 4 kierunków w przybliżeniu.
     *
     * Metoda ta zwraca przybliżony kierunek ruchu pojazdu w kierunku podanego węzła jako wartość enumeracji (NORTH, WEST, EAST, SOUTH).
     */
    MoveDirection GetApproxMoveDirection(QPointF carPosition, StreetMapNode * waypoint);

    /**
     * \brief Sprawdza, czy pojazd znajduje się na skrzyżowaniu.
     * \return true, jeśli pojazd jest na skrzyżowaniu, false w przeciwnym razie.
     *
     * Metoda ta sprawdza, czy pojazd znajduje się na skrzyżowaniu ulic.
     */
    bool IsAtIntersection();

    /**
     * \brief Sprawdza, czy pojazd może skręcić w lewo.
     * \return true, jeśli pojazd może skręcić w lewo, false w przeciwnym razie.
     *
     * Metoda ta zwraca, czy pojazd ma możliwość skręcenia w lewo.
     */
    bool CanTurnLeft();

    /**
     * \brief Pobiera pojazd znajdujący się przed bieżącym pojazdem.
     * \return Wskaźnik do pojazdu znajdującego się przed bieżącym pojazdem, lub nullptr.
     *
     * Metoda ta zwraca wskaźnik do pojazdu, który znajduje się bezpośrednio przed
     * bieżącym pojazdem na drodze.
     */
    Vehicle * GetCarInFront();

    /**
     * \brief Pobiera aktualny stan kierowcy pojazdu.
     * \return Nazwa aktualnego stanu kierowcy jako ciąg znaków.
     *
     * Metoda ta zwraca ciąg znaków reprezentujący obecny stan kierowcy pojazdu.
     */
    std::string GetCurrentDriverState();

    /**
     * \brief Pobiera aktualną prędkość pojazdu.
     * \return Aktualna prędkość pojazdu.
     *
     * Metoda ta zwraca prędkość pojazdu.
     */
    int GetCurrentSpeed() const;

    /**
     * \brief Pobiera aktualny węzeł mapy ulic, do którego zmierza pojazd.
     * \return Wskaźnik do aktualnego węzła mapy ulic.
     *
     * Metoda ta zwraca wskaźnik do węzła mapy ulic, do którego obecnie zmierza pojazd.
     */
    StreetMapNode * GetCurrentStreetMapNode();

    /**
     * \brief Oblicza kąt do następnego węzła.
     * \return Kąt do następnego węzła w stopniach.
     *
     * Metoda ta zwraca kąt między kierunkiem ruchu pojazdu a kierunkiem do
     * następnego węzła.
     */
    double AngleToNextWaypoint();
private:
    double m_MaxSpeed{.5}; ///< Maksymalna prędkość pojazdu w pikselach na klatkę.
    double m_CurrentSpeed{0}; ///< Obecna prędkość pojazdu.
    double m_AccelerationFactor{.2}; ///< Współczynnik przyspieszenia pojazdu.
    double m_TurningSpeed{4}; ///< Prędkość skręcania pojazdu.
    QVector2D m_MoveDirection; ///< Kierunek ruchu pojazdu.
    VehicleDriver m_VehicleDriver; ///< Obiekt klasy kierowcy pojazdu.
    QGraphicsRectItem * m_FrontCollisionProbe; ///< Hitbox wyłapujący inne pojazdy przed tym pojazdem.
    QGraphicsRectItem * m_TurnCollisionProbe; ///< Hitbox wyłapujący pojazdy na lewym pasie, przydatny przy skręcie w lewo.
    std::vector<StreetMapNode *> m_Path; ///< Ścieżka węzłów, przez które pojazd ma przejechać.
    QPointF m_CurrentWaypoint; ///< Aktualny węzeł docelowy dla pojazdu.
    int m_CurrentWaypointIndex{0}; ///< Indeks aktualnego węzła docelowego.
signals:
    /**
     * \brief Sygnał emitowany, gdy pojazd osiągnie końcowy węzeł.
     * \param vehicle Wskaźnik do pojazdu, który osiągnął końcowy węzeł.
     *
     * Ten sygnał jest emitowany, gdy pojazd osiągnie końcowy węzeł na swojej
     * ścieżce.
     */
    void FinalWaypointReached(Vehicle * vehicle);
};

#endif // VEHICLE_H
