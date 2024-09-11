#include "stoppedstate.h"

StoppedState::StoppedState() {}

std::string StoppedState::GetStateName() {
    return "Stopped";
}

void StoppedState::UpdateState(Vehicle * vehicle) {
    vehicle->ApplySteer(-1);
}
