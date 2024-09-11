#include "trafficlight.h"
#include<QDebug>
TrafficLight::TrafficLight(QPoint offset, QSize size, TrafficLightState initialState, QGraphicsPixmapItem * parent) : QGraphicsPixmapItem(parent) {
    setPos(offset);
    m_Size = size;
    m_YellowLightDuration = m_MsPerCycle / 10;
    m_YellowLightThreshold1 = m_MsPerCycle / 2 + m_YellowLightDuration;
    m_YellowLightThreshold2 = m_YellowLightDuration;
    m_Counter = initialState == TrafficLightState::Red ? m_MsPerCycle : initialState == TrafficLightState::Green ? m_YellowLightThreshold1 - m_YellowLightDuration : m_YellowLightThreshold2;
    m_PrevCounter = m_Counter + 16;
    SetState(initialState);
}

void TrafficLight::SetState(TrafficLightState state) {
    switch (state) {
    case TrafficLightState::Green:
        setPixmap(QPixmap(":/textures/sygnalizacja_g.png").scaled(m_Size));
        m_State = TrafficLightState::Green;
        break;
    case TrafficLightState::Yellow:
        setPixmap(QPixmap(":/textures/sygnalizacja_y.png").scaled(m_Size));
        m_State = TrafficLightState::Yellow;
        break;
    case TrafficLightState::Red:
        setPixmap(QPixmap(":/textures/sygnalizacja_r.png").scaled(m_Size));
        m_State = TrafficLightState::Red;
        break;
    }
}


TrafficLightState TrafficLight::GetState() {
    return m_State;
}

void TrafficLight::Update(int deltaTime) {

    if (m_PrevCounter < m_Counter) {
        SetState(TrafficLightState::Red);
    }
    if (m_PrevCounter >= m_YellowLightThreshold1 && m_Counter < m_YellowLightThreshold1) {
        SetState(TrafficLightState::Yellow);
    }
    if (m_PrevCounter >= m_YellowLightThreshold1 - m_YellowLightDuration && m_Counter < m_YellowLightThreshold1 - m_YellowLightDuration) {
        SetState(TrafficLightState::Green);
    }
    if (m_PrevCounter >= m_YellowLightThreshold2 && m_Counter < m_YellowLightThreshold2) {
        SetState(TrafficLightState::Yellow);
    }
    m_PrevCounter = m_Counter;
    m_Counter -= deltaTime;
    m_Counter %= m_MsPerCycle;
    if (m_Counter < 0) {
        m_Counter += m_MsPerCycle;
    }

}
