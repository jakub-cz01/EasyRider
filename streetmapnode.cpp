#include "streetmapnode.h"

StreetMapNode::StreetMapNode(int row, int column, int size) : m_Row(row), m_Col(column), m_Size(size) {
    setPos(size * column, size * row);
    m_Center = QVector2D(m_Col * m_Size + (m_Size / 2), m_Row * m_Size + (m_Size / 2));
}
QVector2D StreetMapNode::GetMiddlePoint() {
    return m_Center;
}

QList<Vehicle *> StreetMapNode::GetVehiclesAtStreet() {
    QList<QGraphicsItem *> allCollisions = collidingItems();
    QList<Vehicle *> out;
    for (auto collidingObject: allCollisions) {
        Vehicle * collidingVehicle = dynamic_cast<Vehicle *>(collidingObject);
        if (collidingVehicle) {
            out.append(collidingVehicle);
        }
    }
    return out;
}

QList<Vehicle *> StreetMapNode::GetVehiclesInSameDirection(QVector2D direction, bool opposite) {
    QList<QGraphicsItem *> allCollisions = collidingItems();
    QList<Vehicle *> out;
    for (auto collidingObject: allCollisions) {
        Vehicle * collidingVehicle = dynamic_cast<Vehicle *>(collidingObject);
        if (collidingVehicle) {
            float dot = QVector2D::dotProduct(direction, collidingVehicle->GetMoveDirection());
            if (opposite) {
                if (dot < -0.9) out.append(collidingVehicle);
            } else {
                if (dot > 0.9) out.append(collidingVehicle);
            }
        }
    }
    return out;
}

void StreetMapNode::AddNeighbor(StreetMapNode * Node) {
    m_Neighbors.push_back(Node);
}
std::vector<StreetMapNode *> StreetMapNode::GetNeighbors() {
    return m_Neighbors;
}

bool StreetMapNode::IsIntersection() {
    return false;
}
