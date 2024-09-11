/**
 * \file simulationloop.h
 * \brief Plik nagłówkowy dla klasy SimulationLoop.
 *
 * Ten plik zawiera deklarację klasy SimulationLoop, która zarządza pętlą symulacyjną,
 * w tym uruchamianiem i pauzowaniem symulacji oraz dodawaniem i usuwaniem obiektów symulacyjnych.
 * Odpowiada również za kontrolowanie prędkości symulacji.
 */

#ifndef SIMULATIONLOOP_H
#define SIMULATIONLOOP_H

#include<unordered_map>
#include<string>

#include<QObject>
#include<QTimer>
#include<QElapsedTimer>

#include "streetmap.h"
#include "simulatedobject.h"

/**
 * \class SimulationLoop
 * \brief Zarządza pętlą symulacyjną.
 *
 * Klasa SimulationLoop zarządza pętlą symulacyjną, która jest odpowiedzialna za
 * uruchamianie, pauzowanie i aktualizowanie stanu obiektów symulowanych. Klasa ta
 * umożliwia dodawanie i usuwanie obiektów z symulacji oraz zarządzanie parametrami
 * symulacji.
 */
class SimulationLoop: public QObject {

Q_OBJECT

public:
/**
     * \brief Pobiera instancję singletonu klasy SimulationLoop.
     * \return Referencja do instancji singletonu.
     *
     * Metoda ta zwraca referencję do jedynej instancji klasy SimulationLoop, zapewniając
     * dostęp do obiektu z dowolnego miejsca w kodzie.
     */
    static SimulationLoop& GetInstance();

    /**
     * \brief Rozpoczyna pętlę symulacyjną.
     *
     * Metoda ta uruchamia pętlę symulacyjną, zaczynając symulację.
     */
    void Start();

    /**
     * \brief Pauzuje pętlę symulacyjną.
     *
     * Metoda ta wstrzymuje działanie pętli symulacyjnej, zatrzymując symulację.
     */
    void Pause();

    /**
     * \brief Dodaje obiekt symulowany do pętli.
     * \param object Wskaźnik do obiektu symulowanego, który ma być dodany.
     *
     * Metoda ta dodaje obiekt symulowany do pętli symulacyjnej, umożliwiając jego
     * aktualizację i zarządzanie nim w trakcie symulacji.
     */
    void AddSimulatedObject(SimulatedObject * object);

    /**
     * \brief Usuwa obiekt symulowany z pętli.
     * \param object Wskaźnik do obiektu symulowanego, który ma być usunięty.
     *
     * Metoda ta usuwa obiekt symulowany z pętli symulacyjnej, zatrzymując jego
     * aktualizację i zarządzanie nim.
     */
    void RemoveSimulatedObject(SimulatedObject * object);

    /**
     * \brief Ustala główną mapę dla symulacji.
     * \param map Wskaźnik do obiektu StreetMap, który ma być ustawiony jako główny.
     *
     * Metoda ta przypisuje obiekt mapy jako główną mapę dla symulacji.
     */
    void SetMainMap(StreetMap * map);

    /**
     * \brief Dodaje obiekt do sceny.
     * \param object Wskaźnik do obiektu QGraphicsItem, który ma być dodany.
     *
     * Metoda ta dodaje obiekt do sceny graficznej.
     */
    void AddToScene(QGraphicsItem * object);

    /**
     * \brief Usuwa obiekt ze sceny.
     * \param object Wskaźnik do obiektu QGraphicsItem, który ma być usunięty.
     *
     * Metoda ta usuwa obiekt ze sceny graficznej.
     */
    void RemoveFromScene(QGraphicsItem * object);

    /**
     * \brief Generuje unikalny identyfikator dla obiektu.
     * \return Unikalny identyfikator.
     *
     * Metoda ta generuje i zwraca unikalny identyfikator dla nowego obiektu symulowanego.
     */
    int GenerateId();
    SimulationLoop(const SimulationLoop&) = delete; ///< Usuwa kopiowanie obiektów.
    void operator=(const SimulationLoop&) = delete; ///< Usuwa przypisanie obiektów.
public slots:
    /**
     * \brief Przełącza stan symulacji.
     * \param checked Wartość przekazywana przez zdarzenie clicked, nieużywana.
     *
     * Slot ten jest wywoływany w celu przełączenia stanu symulacji uruchomiony lub zapauzowany.
     */
    void ToggleSimulation(bool checked);

    /**
     * \brief Ustala prędkość symulacji.
     * \param speed Nowa prędkość symulacji.
     *
     * Slot ten jest wywoływany w celu ustawienia nowej prędkości symulacji.
     */
    void SetSimulationSpeed(int speed);

    /**
     * \brief Czyści wszystkie samochody.
     * \param checked Wartość przekazywana przez zdarzenie clicked, nieużywana.
     *
     * Slot ten jest wywoływany w celu usunięcia wszystkich samochodów z symulacji.
     */
    void ClearAllCars(bool checked);
private:
    explicit SimulationLoop(QObject *parent = nullptr) : QObject(parent) {} ///< Prywatny konstruktor singletonu.
    std::unordered_map<int, SimulatedObject*> m_Objects; ///< Kontener przechowujący symulowane obiekty.
    QTimer m_LoopTimer; ///< Timer pętli symulacyjnej.
    QElapsedTimer m_ElapsedTimer; ///< Timer mierzący rzeczywisty czas między klatkami.
    double m_SimulationSpeed{1.0}; ///< Prędkość symulacji.
    bool m_IsRunning{false}; ///< Flaga wskazująca, czy symulacja jest uruchomiona.
    int m_LastFrameTime{0}; ///< Czas ostatniej klatki.
    int m_IdCounter; ///< Licznik generatora identyfikatorów obiektów.
    StreetMap * m_Map; ///< Wskaźnik do głównej mapy.
private slots:
    /**
     * \brief Reaguje na wywołanie przez timer określoną ilość razy na sekundę.
     *
     * Slot ten jest wywoływany cyklicznie, aby aktualizować stan obiektów w pętli
     * symulacyjnej.
     */
    void UpdateLoop();
signals:
    /**
     * \brief Sygnalizuje, że należy odświeżyć renderowanie.
     *
     * Sygnał ten jest używany do informowania o konieczności odświeżenia
     * sceny.
     */
    void Render();
}
;

#endif // SIMULATIONLOOP_H
