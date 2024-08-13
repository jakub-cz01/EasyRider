#include "trafficlight.h"

TrafficLight::TrafficLight(QObject *parent) : QObject{parent} {}

void TrafficLight::ToggleState() {
    switch(state) {
        case TrafficLightState::Red:
            state = TrafficLightState::Yellow;
            targetState = TrafficLightState::Green;
            emit StateChanged(TrafficLightState::Yellow);
            break;
        case TrafficLightState::Yellow:
            targetState = targetState == TrafficLightState::Red ?
                TrafficLightState::Green :
                TrafficLightState::Red;
            break;
        case TrafficLightState::Green:
            state = TrafficLightState::Yellow;
            targetState = TrafficLightState::Red;
            emit StateChanged(TrafficLightState::Yellow);
            break;
    }
}


TrafficLightState TrafficLight::GetState() {
    return TrafficLightState{state};
}
