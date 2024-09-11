#include "vehicle.h"
#include "simulationloop.h"
#include "streetmapnode.h"
#include <QDebug>

Vehicle::Vehicle(std::vector<StreetMapNode *> path): m_Path(path), m_VehicleDriver(this) {
    setPixmap(QPixmap(":/textures/vehicles/Audi.png").scaled(18, 24));
    setTransform(QTransform().rotate(90), true);
    setTransformOriginPoint(0,0);
    m_FrontCollisionProbe = new QGraphicsRectItem(this);
    m_TurnCollisionProbe = new QGraphicsRectItem(this);

    m_FrontCollisionProbe->setVisible(false);
    m_TurnCollisionProbe->setVisible(false);
    m_FrontCollisionProbe->setRect(6, -5, 8, 5);
    m_TurnCollisionProbe->setRect(-12, -80, 8, 72);
    setZValue(10);

    m_CurrentWaypoint = m_Path[m_CurrentWaypointIndex]->GetMiddlePoint().toPointF();
    setPos(m_CurrentWaypoint);

}

Vehicle::~Vehicle() {
    SimulationLoop::GetInstance().RemoveFromScene(this);
    SimulationLoop::GetInstance().RemoveSimulatedObject(this);
    delete m_FrontCollisionProbe;
    delete m_TurnCollisionProbe;
}

void Vehicle::ApplySteer(double acceleration) {

    QVector2D position(pos().x(), pos().y());
    QVector2D direction = QVector2D(m_CurrentWaypoint.x(), m_CurrentWaypoint.y()) - position;

    double currentAngle = rotation();
    double targetAngle = qAtan2(direction.y(), direction.x()) * (180.0 / M_PI);
    double angleDiff = targetAngle - currentAngle;

    if (angleDiff > 180) angleDiff -= 360;
    if (angleDiff < -180) angleDiff += 360;

    if (qAbs(angleDiff) > 1) {
        if (angleDiff > 0) {
            currentAngle += (m_TurningSpeed);
        } else {
            currentAngle -= m_TurningSpeed;
        }
        setRotation(currentAngle);
    } else {
        setRotation(targetAngle);
    }

    m_CurrentSpeed += (acceleration * m_AccelerationFactor);

    if (m_CurrentSpeed > m_MaxSpeed) m_CurrentSpeed = m_MaxSpeed;
    if (m_CurrentSpeed < 0) m_CurrentSpeed = 0;

    double radians = qDegreesToRadians(rotation());
    QVector2D moveVector(qCos(radians) * m_CurrentSpeed, qSin(radians) * m_CurrentSpeed);

    position += moveVector;
    setPos(position.x(), position.y());
}

void Vehicle::Update(int deltaTime) {
    m_VehicleDriver.EvaluateState();
    float distance = m_Path[m_CurrentWaypointIndex]->GetMiddlePoint().distanceToPoint(QVector2D(pos().x(), pos().y()));
    if (distance < 5) {
        if (m_CurrentWaypointIndex < m_Path.size() - 1) {
            m_CurrentWaypointIndex++;
            m_CurrentWaypoint = m_Path[m_CurrentWaypointIndex]->GetMiddlePoint().toPoint();
        }
        else {
            emit FinalWaypointReached(this);
        }
    }
}

QVector2D Vehicle::GetMoveDirection() const {
    return m_MoveDirection.normalized();
}

MoveDirection Vehicle::GetApproxMoveDirection(QPointF carPosition, StreetMapNode *waypoint) {
    double dx = carPosition.x() - waypoint->GetMiddlePoint().x();
    double dy = carPosition.y() - waypoint->GetMiddlePoint().y();

    double angle = qAtan2(dy, dx);

    if (angle >= -M_PI_4 && angle <= M_PI_4) {
        return MoveDirection::East;
    } else if (angle > M_PI_4 && angle <= 3 * M_PI_4) {
        return MoveDirection::North;
    } else if (angle < -M_PI_4 && angle >= -3 * M_PI_4) {
        return MoveDirection::South;
    } else {
        return MoveDirection::West;
    }
}

bool Vehicle::IsAtIntersection() {
    return m_Path[m_CurrentWaypointIndex]->IsIntersection();
}

bool Vehicle::CanTurnLeft() {
    QList<QGraphicsItem *> collidingItems = m_TurnCollisionProbe->collidingItems();
    for (auto item: collidingItems) {
        Vehicle * vehicle = dynamic_cast<Vehicle *>(item);
        if (vehicle) {
            if (vehicle->GetCurrentDriverState() == "Driving")
            return false;
        }
    }
    return true;
}

Vehicle * Vehicle::GetCarInFront() {
    QList<QGraphicsItem *> collidingItems = m_FrontCollisionProbe->collidingItems();
    for (auto item: collidingItems) {
        Vehicle * vehicle = dynamic_cast<Vehicle *>(item);
        if (vehicle && vehicle->GetSimulatedObjectId() != GetSimulatedObjectId()) {
            return vehicle;
        }
    }
    return nullptr;
}

std::string Vehicle::GetCurrentDriverState() {
    return m_VehicleDriver.GetStateName();
}

int Vehicle::GetCurrentSpeed() const {
    return m_CurrentSpeed;
}

StreetMapNode * Vehicle::GetCurrentStreetMapNode() {
    return m_Path[m_CurrentWaypointIndex];
}
