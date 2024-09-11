#include "streetmap.h"
#include "straightstreet.h"
#include "intersection.h"
#include "simulationloop.h"
#include "spawnpoint.h"
#include <queue>
#include "unordered_set"
#include "vehiclemanager.h"
#include <QRandomGenerator>
#include <QTime>

StreetMap::StreetMap(QWidget* parent) : QGraphicsView(parent) {
    setScene(new QGraphicsScene());
    SimulationLoop::GetInstance().SetMainMap(this);
    VehicleManager::GetInstance().SetStreetMap(this);
    m_NumGridMap = {
                    {0, 0, 4, 0, 4, 0, 4, 0, 0},
                    {0, 0, 1, 0, 1, 0, 1, 0, 0},
                    {4, 2, 3, 2, 3, 2, 3, 2, 4},
                    {0, 0, 1, 0, 1, 0, 1, 0, 0},
                    {0, 0, 1, 0, 1, 0, 1, 0, 0},
                    {0, 0, 1, 0, 1, 0, 1, 0, 0},
                    {4, 2, 3, 2, 3, 2, 3, 2, 4},
                    {0, 0, 1, 0, 1, 0, 1, 0, 0},
                    {0, 0, 4, 0, 4, 0, 4, 0, 0},
                };
    std::vector<std::vector<StreetMapNode *>> grid(m_NumGridMap.size(), std::vector<StreetMapNode *>(m_NumGridMap.size(), nullptr));
    m_GridMap = grid;
    RenderStreetMap();
    AddNeighbors();
    centerOn(scene()->sceneRect().center());
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setRenderHint(QPainter::Antialiasing, true);
    setViewportUpdateMode(ViewportUpdateMode::NoViewportUpdate);
    connect(&(SimulationLoop::GetInstance()), &SimulationLoop::Render, this, &StreetMap::UpdateSimScene);
}

void StreetMap::RenderStreetMap() {
    for (int i = 0; i < m_NumGridMap.size(); i++) {
        for (int j = 0; j < m_NumGridMap[0].size(); j++) {
            switch(m_NumGridMap[i][j]) {
            case 0:
            {
                QGraphicsPixmapItem * grassTile = new QGraphicsPixmapItem(QPixmap(":/textures/roads/grass.png").scaled(m_TileSize, m_TileSize));
                grassTile->setPos(j * m_TileSize, i * m_TileSize);
                scene()->addItem(grassTile);
            }
            break;
            case 1:
                m_GridMap[i][j] = new StraightStreet(true, i, j, m_TileSize);
                scene()->addItem(m_GridMap[i][j]);
                break;
            case 2:
                m_GridMap[i][j] = new StraightStreet(false, i, j, m_TileSize);
                scene()->addItem(m_GridMap[i][j]);
                break;
            case 3:
                m_GridMap[i][j] = new Intersection(i, j, m_TileSize);
                scene()->addItem(m_GridMap[i][j]);
                break;
            case 4:
                m_GridMap[i][j] = new SpawnPoint(i, j, m_TileSize);
                m_SpawnPoints.push_back(m_GridMap[i][j]);
                scene()->addItem(m_GridMap[i][j]);
            break;
            }
        }
    }
}
void StreetMap::UpdateSimScene() {
    this->viewport()->update();
}

void StreetMap::wheelEvent(QWheelEvent *event) {}

void StreetMap::AddNeighbors() {
    for (int i = 0; i < m_NumGridMap.size(); i++) {
        for (int j = 0; j < m_NumGridMap.size(); j++) {
            if (m_NumGridMap[i][j] > 0) {
                StreetMapNode * node = m_GridMap[i][j];
                if ((i > 0) && (m_NumGridMap[i-1][j] > 0)) node->AddNeighbor(m_GridMap[i-1][j]);
                if ((i < m_NumGridMap.size() - 1) && (m_NumGridMap[i+1][j] > 0)) node->AddNeighbor(m_GridMap[i+1][j]);
                if ((j > 0) && (m_NumGridMap[i][j-1] > 0)) node->AddNeighbor(m_GridMap[i][j-1]);
                if ((j < m_NumGridMap.size() - 1) && (m_NumGridMap[i][j+1] > 0)) node->AddNeighbor(m_GridMap[i][j+1]);
            }

        }
    }
}

std::vector<StreetMapNode *> StreetMap::GenerateShortestPath() {

    QRandomGenerator rng = QRandomGenerator::global()->securelySeeded();
    int limit = m_SpawnPoints.size();
    int index1 = rng.bounded(limit);
    int index2 = rng.bounded(limit);

    if (index1 == index2) {
        index2 += QTime::currentTime().msecsSinceStartOfDay();
        index2 %= limit;
    }

    if (index1 == index2) index2 = (index2++) % limit;

    StreetMapNode * a = m_SpawnPoints[index1];
    StreetMapNode * b = m_SpawnPoints[index2];

    std::unordered_map<StreetMapNode *, StreetMapNode *> parent;
    std::queue<StreetMapNode *> q;
    std::unordered_set<StreetMapNode *> visited;
    std::vector<StreetMapNode *> path;

    q.push(a);
    visited.insert(a);
    parent[a] = nullptr;

    while (!q.empty()) {
        StreetMapNode * currentNode = q.front();
        q.pop();

        if (currentNode == b) {
            StreetMapNode * node = b;
            while (node != nullptr) {
                path.push_back(node);
                node = parent[node];
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (StreetMapNode * neighbor : currentNode->GetNeighbors()) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
                parent[neighbor] = currentNode;
            }
        }
    }

    return {};
}
