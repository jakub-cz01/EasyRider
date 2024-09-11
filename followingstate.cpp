#include "followingstate.h"
#include "vehicle.h"

FollowingState::FollowingState(Vehicle * toFollow) : m_ToFollow(toFollow) {}

std::string FollowingState::GetStateName() {
    return "Following";
}

void FollowingState::UpdateState(Vehicle * vehicle) {
    int followedSpeed = m_ToFollow->GetCurrentSpeed();
    int vehicleSpeed = vehicle->GetCurrentSpeed();
    if (followedSpeed == 0) {
        vehicle->ApplySteer(-1);
    }
    else vehicle->ApplySteer((followedSpeed - vehicleSpeed) * 5 / (followedSpeed));
}
