#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <QObject>
#include "trafficlightstate.h"

class TrafficLight : public QObject
{
    Q_OBJECT
public:
    explicit TrafficLight(QObject *parent = nullptr);
    void ToggleState();
    TrafficLightState GetState();
private:
    TrafficLightState state;
    TrafficLightState targetState;
signals:
    void StateChanged(TrafficLightState newState);
};

#endif // TRAFFICLIGHT_H
