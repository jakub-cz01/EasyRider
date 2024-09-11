/**
 * \file streetmap.h
 * \brief Plik nagłówkowy klasy StreetMap.
 *
 * Ten plik zawiera deklarację klasy StreetMap, która reprezentuje
 * mapę używającą siatki obiektów StreetMapNode i zapewnia funkcjonalności
 * do manipulowania i wyświetlania mapy.
 */

#ifndef STREETMAP_H
#define STREETMAP_H

#include <vector>
#include <QGraphicsView>
#include "streetmapnode.h"


/**
 * \class StreetMap
 * \brief Reprezentuje graficzny widok mapy ulic.
 *
 * Klasa StreetMap dziedziczy po QGraphicsView i zapewnia funkcjonalności
 * do wyświetlania i manipulowania mapą opartą na siatce ulic. Umożliwia interakcję
 * taką jak przybliżanie i oddalanie za pomocą kółka myszy oraz znajdowanie ścieżek
 * między węzłami.
 */
class StreetMap : public QGraphicsView
{
Q_OBJECT
public:
    /**
     * \brief Konstruktor obiektu StreetMap.
     * \param parent Wskaźnik do rodzica QWidget, jeśli istnieje.
     *
     * Inicjalizuje nową instancję klasy StreetMap z opcjonalnym rodzicem.
     */
    explicit StreetMap(QWidget* parent = nullptr);

    /**
     * \brief Pobiera wszystkie sąsiednie węzły w danej pozycji siatki.
     * \param row Indeks wiersza w siatce.
     * \param col Indeks kolumny w siatce.
     * \return Wektor wskaźników do sąsiednich obiektów StreetMapNode.
     *
     * Metoda ta zwraca wszystkie sąsiednie węzły graniczące z określoną
     * pozycją w siatce (wiersz, kolumna).
     */
    std::vector<StreetMapNode*> GetAllNeighborsAt(int row, int col);

    /**
     * \brief Losuje 2 punkty i generuje najkrótszą ścieżkę między nimi na mapie używając algorytmu przeszukiwania grafu wszerz.
     * \return Wektor wskaźników do obiektów StreetMapNode reprezentujących najkrótszą ścieżkę.
     *
     * Metoda ta oblicza i zwraca najkrótszą ścieżkę między dwoma węzłami
     * na mapie ulic, opartą na algorytmie BFS.
     */
    std::vector<StreetMapNode*> GenerateShortestPath();
public slots:
    /**
     * \brief Aktualizuje scenę symulacji.
     *
     * Ten slot jest podłączony do sygnału Render(), który wywołuje aktualizację
     * sceny symulacji. Rysuje całą widoczną przestrzeń sceny.
     */
    void UpdateSimScene();
protected:
    /**
     * \brief Wyłącza reakcję na zdarzenia związane z kółkiem myszy.
     * \param event Zdarzenie kółka myszy.
     *
     * Metoda ta jest nadpisywana, aby zapewnić niestandardowe zachowanie
     * przy przybliżaniu i oddalaniu mapy ulic przy użyciu kółka myszy.
     */
    void wheelEvent(QWheelEvent *event) override;
private:
    /**
     * \brief Dodaje wszystkie sąsiednie węzły dla każdego węzła na mapie.
     *
     * Ta prywatna metoda inicjalizuje relacje sąsiedztwa między węzłami
     * w siatce w celu ułatwienia znajdowania ścieżek i poruszania się po mapie.
     */
    void AddNeighbors();

    /**
     * \brief Renderuje mapę ulic.
     *
     * Ta prywatna metoda zajmuje się graficznym renderowaniem mapy ulic.
     * Ustawia wizualną reprezentację mapy w QGraphicsView.
     */
    void RenderStreetMap();
    std::vector<std::vector<int>> m_NumGridMap; ///< Numeryczna reprezentacja siatki mapy.
    std::vector<std::vector<StreetMapNode *>> m_GridMap; ///< Siatka węzłów reprezentujących mapę ulic.
    std::vector<StreetMapNode *> m_SpawnPoints; ///< Lista punktów startowych na mapie.
    int m_TileSize{96}; ///< Rozmiar każdego kafelka na mapie, w pikselach.
};

#endif // STREETMAP_H
