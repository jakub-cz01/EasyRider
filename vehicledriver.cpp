#include "vehicledriver.h"
#include "vehicle.h"
#include "followingstate.h"
#include "drivingstate.h"
#include "stoppedstate.h"
#include "trafficlightstate.h"
#include "intersection.h"
#include "streetmapnode.h"
#include "genericdistance.h"

VehicleDriver::VehicleDriver(Vehicle * parent) : m_Vehicle(parent) {
    m_VehicleDriverState = new StoppedState();
}

std::string VehicleDriver::GetStateName() {
    return m_VehicleDriverState->GetStateName();
}

void VehicleDriver::EvaluateState() {
    Vehicle * vehicleInFront = m_Vehicle->GetCarInFront();
    if (m_Vehicle->IsAtIntersection()) {
        Intersection * intersection = dynamic_cast<Intersection *>(m_Vehicle->GetCurrentStreetMapNode());
        TrafficLightState currentLight = intersection->GetTrafficLightStateFromDirection(m_Vehicle->GetApproxMoveDirection(m_Vehicle->pos(), intersection));
        double distanceToIntersection = GDistance(intersection->GetMiddlePoint(), m_Vehicle->pos());
        if (currentLight == TrafficLightState::Green) {
            if (m_Vehicle->CanTurnLeft() && GetStateName() != "Driving" && currentLight == TrafficLightState::Green && vehicleInFront == nullptr) {
                delete m_VehicleDriverState;
                m_VehicleDriverState = new DrivingState();
            }
            else if (GetStateName() != "Stopped" && currentLight != TrafficLightState::Green) {
                delete m_VehicleDriverState;
                m_VehicleDriverState = new StoppedState();
            }
            else if (vehicleInFront && GetStateName() != "Following") {
                delete m_VehicleDriverState;
                m_VehicleDriverState = new FollowingState(vehicleInFront);
            }
        }
        else if (GetStateName() != "Stopped" && (distanceToIntersection < 20.0)) {
            delete m_VehicleDriverState;
            m_VehicleDriverState = new StoppedState();
        }
        else if (vehicleInFront && GetStateName() != "Following") {
            delete m_VehicleDriverState;
            m_VehicleDriverState = new FollowingState(vehicleInFront);
        }
    }
    else if (vehicleInFront && GetStateName() != "Following") {
        delete m_VehicleDriverState;
        m_VehicleDriverState = new FollowingState(vehicleInFront);
    }
    else if (vehicleInFront == nullptr && GetStateName() != "Driving") {
        delete m_VehicleDriverState;
        m_VehicleDriverState = new DrivingState();
    }
    m_VehicleDriverState->UpdateState(m_Vehicle);
}
