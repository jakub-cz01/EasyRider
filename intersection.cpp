#include "intersection.h"

Intersection::Intersection(int row, int column, int size) : StreetMapNode(row, column, size){
    setPixmap(QPixmap(":/textures/roads/intersection.png").scaled(size, size));
    m_BottomLeftLight = new TrafficLight(QPoint(8, 72), QSize(8, 24), TrafficLightState::Green, this);
    m_BottomRightLight = new TrafficLight(QPoint(80, 72), QSize(8, 24), TrafficLightState::Red, this);
    m_TopLeftLight = new TrafficLight(QPoint(8, 0), QSize(8, 24), TrafficLightState::Red, this);
    m_TopRightLight = new TrafficLight(QPoint(80, 0), QSize(8, 24), TrafficLightState::Green, this);
}

bool Intersection::IsIntersection() {
    return true;
}

TrafficLightState Intersection::GetTrafficLightStateFromDirection(MoveDirection direction) {
    TrafficLightState out;
    switch(direction) {
    case MoveDirection::East:
        out = m_BottomLeftLight->GetState();
        break;
    case MoveDirection::North:
        out = m_BottomRightLight->GetState();
        break;
    case MoveDirection::West:
        out = m_TopRightLight->GetState();
        break;
    case MoveDirection::South:
        out = m_TopLeftLight->GetState();
        break;
    }
    return out;
}
