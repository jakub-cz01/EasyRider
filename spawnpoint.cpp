#include "spawnpoint.h"
int SpawnPoint::m_IdCounter = 0;

SpawnPoint::SpawnPoint(int row, int column, int size) : StreetMapNode(row, column, size) {
    m_SpawnPointId = SpawnPoint::m_IdCounter++;
    setPixmap(QPixmap(":/textures/roads/grass.png").scaled(size, size));
}
