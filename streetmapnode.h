/**
 * \file streetmapnode.h
 * \brief Plik nagłówkowy klasy StreetMapNode.
 *
 * Ten plik zawiera deklarację klasy StreetMapNode, która reprezentuje
 * pojedynczy węzeł w siatce mapy ulic. Klasa ta rozszerza QGraphicsPixmapItem
 * i dostarcza funkcjonalności do zarządzania sąsiadami oraz pojazdami na ulicy.
 */

#ifndef STREETMAPNODE_H
#define STREETMAPNODE_H

#include <vector>
#include <QVector2D>
#include <QGraphicsPixmapItem>
#include <vehicle.h>

/**
 * \class StreetMapNode
 * \brief Reprezentuje węzeł w siatce mapy ulic.
 *
 * Klasa StreetMapNode dziedziczy po QGraphicsPixmapItem i reprezentuje
 * węzeł na mapie ulic. Obejmuje funkcjonalności do zarządzania sąsiadami
 * oraz pojazdami znajdującymi się na danej ulicy.
 */
class StreetMapNode: public QGraphicsPixmapItem
{
public:
    /**
     * \brief Konstruktor obiektu StreetMapNode.
     * \param row Indeks wiersza w siatce.
     * \param column Indeks kolumny w siatce.
     * \param size Rozmiar węzła w pikselach.
     *
     * Inicjalizuje nową instancję klasy StreetMapNode z określoną pozycją
     * i rozmiarem.
     */
    StreetMapNode(int row, int column, int size);

    /**
     * \brief Pobiera środkowy punkt węzła.
     * \return Wektor 2D reprezentujący środkowy punkt węzła.
     *
     * Metoda ta zwraca środkowy punkt węzła w postaci wektora 2D.
     */
    QVector2D GetMiddlePoint();

    /**
     * \brief Dodaje sąsiada do węzła.
     * \param Node Wskaźnik do węzła sąsiada.
     *
     * Metoda ta dodaje wskazany węzeł jako sąsiada do bieżącego węzła.
     */
    void AddNeighbor(StreetMapNode * Node);

    /**
     * \brief Pobiera pojazdy znajdujące się na ulicy.
     * \return Lista wskaźników do pojazdów znajdujących się na ulicy.
     *
     * Metoda ta zwraca listę pojazdów znajdujących się na ulicy związanej
     * z bieżącym węzłem.
     */
    QList<Vehicle *> GetVehiclesAtStreet();

    /**
     * \brief Zwraca listę pojazdów znajdujących się na węźle i poruszających się w tym samym kierunku lub przeciwnym.
     * \param direction Kierunek, w którym mają być wyszukiwane pojazdy.
     * \param opposite Jeśli ustawione na true, zwraca pojazdy w przeciwnym
     *        kierunku.
     * \return Lista wskaźników do pojazdów poruszających się w określonym kierunku.
     *
     * Metoda ta zwraca listę pojazdów poruszających się w określonym kierunku,
     * zależnie od parametru opposite.
     */
    QList<Vehicle *> GetVehiclesInSameDirection(QVector2D direction, bool opposite = false);

    /**
     * \brief Pobiera sąsiadów węzła.
     * \return Wektor wskaźników do sąsiednich węzłów.
     *
     * Metoda ta zwraca wektor wskaźników do węzłów sąsiadujących z bieżącym
     * węzłem.
     */
    std::vector<StreetMapNode *> GetNeighbors();

    /**
     * \brief Sprawdza, czy węzeł jest skrzyżowaniem.
     * \return true, jeśli węzeł jest skrzyżowaniem, false w przeciwnym razie.
     *
     * Metoda ta sprawdza, czy bieżący węzeł jest skrzyżowaniem ulic.
     */
    virtual bool IsIntersection();

private:
    int m_Row; ///< Indeks wiersza w siatce mapy.
    int m_Col; ///< Indeks kolumny w siatce mapy.
    int m_Size; ///< Rozmiar węzła.
    std::vector<StreetMapNode *> m_Neighbors; ///< Lista sąsiadów węzła.
    QVector2D m_Center; ///< Środkowy punkt węzła.
};

#endif // STREETMAPNODE_H
