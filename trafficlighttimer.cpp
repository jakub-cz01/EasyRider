#include "trafficlighttimer.h"

TrafficLightTimer::TrafficLightTimer(QObject *parent)
    : QObject{parent}
{}

void TrafficLightTimer::SetTimerInterval(double newInterval) {
    m_Interval = newInterval;
    m_LightsTimer.start(1000 * newInterval);
}

void TrafficLightTimer::ChangeLights() {
    for (auto &light: m_AffectedLights) {
        light->ToggleState();
    }
}

void TrafficLightTimer::AddTrafficLight(TrafficLight * light) {
    m_AffectedLights.push_back(light);
}

void TrafficLightTimer::Start() {
    if (!m_IsStarted) {
        connect(&m_LightsTimer, &QTimer::timeout, this, &TrafficLightTimer::ChangeLights);
        m_LightsTimer.start(1000 * m_Interval);
    }
}

void TrafficLightTimer::Stop() {
    if (m_IsStarted) {
        disconnect(&m_LightsTimer, &QTimer::timeout, this, &TrafficLightTimer::ChangeLights);
    }
}

