#include "drivingstate.h"

DrivingState::DrivingState() {}

std::string DrivingState::GetStateName() {
    return "Driving";
}

void DrivingState::UpdateState(Vehicle * vehicle) {
    vehicle->ApplySteer(1);
}
