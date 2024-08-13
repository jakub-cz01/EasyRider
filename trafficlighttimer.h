#ifndef TRAFFICLIGHTTIMER_H
#define TRAFFICLIGHTTIMER_H

#include <QObject>
#include <QTimer>
#include <vector>
#include "trafficlight.h"

class TrafficLightTimer : public QObject
{
    Q_OBJECT
public:
    explicit TrafficLightTimer(QObject *parent = nullptr);
    void SetTimerInterval(double newInterval);
    void ChangeLights();
    void AddTrafficLight(TrafficLight * light);
    void Start();
    void Stop();
private:
    QTimer m_LightsTimer;
    double m_Interval;
    bool m_IsStarted;
    std::vector<TrafficLight*> m_AffectedLights;
};

#endif // TRAFFICLIGHTTIMER_H
