/**
 * \file vehiclemanager.h
 * \brief Plik nagłówkowy dla klasy VehicleManager.
 *
 * Ten plik zawiera deklarację klasy VehicleManager, która zarządza pojazdami
 * w symulacji, kontrolując ich liczbę, szybkość pojawiania się oraz interakcję
 * z mapą ulic.
 */

#ifndef VEHICLEMANAGER_H
#define VEHICLEMANAGER_H

#include <QObject>
#include "simulatedobject.h"
#include "streetmap.h"


/**
 * \class VehicleManager
 * \brief Zarządza pojazdami w symulacji.
 *
 * Klasa VehicleManager jest odpowiedzialna za zarządzanie pojazdami w symulacji,
 * w tym za kontrolowanie ich liczby, szybkości pojawiania się oraz interakcję
 * z mapą ulic. Klasa ta implementuje wzorzec Singleton.
 */
class VehicleManager: public QObject, public SimulatedObject
{

Q_OBJECT

public:
    /**
     * \brief Pobiera instancję singletona VehicleManager.
     * \return Referencja do jedynej instancji VehicleManager.
     *
     * Metoda ta zwraca referencję do jedynej instancji klasy VehicleManager, implementując wzorzec Singleton.
     */
    static VehicleManager& GetInstance();

    /**
     * \brief Aktualizuje stan menedżera pojazdów.
     * \param deltaTime Czas, który upłynął od ostatniej aktualizacji.
     *
     * Metoda ta aktualizuje stan menedżera pojazdów na podstawie upływu czasu.
     */
    void Update(int deltaTime) override;

    /**
     * \brief Ustala limit liczby pojazdów.
     * \param newLimit Nowy limit liczby pojazdów.
     *
     * Metoda ta ustawia nowy limit liczby pojazdów, które mogą być aktywne w symulacji.
     */
    void SetVehicleLimit(int newLimit);

    /**
     * \brief Pobiera limit liczby pojazdów.
     * \return Limit liczby pojazdów.
     *
     * Metoda ta zwraca obecny limit liczby pojazdów, które mogą być aktywne w symulacji.
     */
    int GetVehicleLimit() const;

    /**
     * \brief Ustala mapę ulic dla menedżera pojazdów.
     * \param map Wskaźnik do obiektu StreetMap.
     *
     * Metoda ta ustawia mapę ulic, z którą menedżer pojazdów będzie współpracować.
     */
    void SetStreetMap(StreetMap * map);

    /**
     * \brief Usuwa możliwość kopiowania obiektu VehicleManager.
     *
     * Metoda ta usuwa możliwość kopiowania obiektu VehicleManager, ponieważ jest to singleton.
     */
    VehicleManager(const VehicleManager&) = delete;

    /**
     * \brief Operator przypisania dla VehicleManager.
     *
     * Metoda ta usuwa możliwość przypisania obiektu VehicleManager, ponieważ jest to singleton.
     */
    void operator=(const VehicleManager&) = delete;

    /**
     * \brief Resetuje licznik pojazdów.
     *
     * Metoda ta resetuje licznik aktywnych pojazdów w symulacji.
     */
    void ResetVehicleCounter();

    /**
     * \brief Ustala szybkość pojawiania się pojazdów.
     * \param vehicleSpawnRate Nowa szybkość pojawiania się pojazdów w milisekundach.
     *
     * Metoda ta ustawia szybkość, z jaką pojazdy pojawiają się w symulacji.
     */
    void SetVehicleSpawnRate(int vehicleSpawnRate);
private:
    explicit VehicleManager(QObject *parent = nullptr) : QObject(parent) {}
    int m_VehicleSpawnRateMs{1000}; ///< Szybkość pojawiania się pojazdów w milisekundach.
    int m_SpawnCounter{0}; ///< Licznik służący do kontrolowania czasu pojawiania się pojazdów.
    int m_VehicleLimit{100}; ///< Limit liczby pojazdów w symulacji.
    int m_VehicleCounter{0}; ///< Licznik aktualnej liczby pojazdów w symulacji.
    std::string m_ComponentId; ///< Identyfikator komponentu.
    StreetMap * m_StreetMap; ///< Wskaźnik do mapy ulic.
    void SpawnVehicle(); ///< Metoda do tworzenia nowych pojazdów.
public slots:
    /**
     * \brief Slot wywoływany, gdy pojazd osiągnie końcowy węzeł.
     * \param vehicle Wskaźnik do pojazdu, który osiągnął końcowy węzeł.
     *
     * Slot ten jest wywoływany, gdy pojazd osiągnie końcowy węzeł na swojej ścieżce.
     */
    void OnFinalWaypointReached(Vehicle * vehicle);
};

#endif // VEHICLEMANAGER_H
