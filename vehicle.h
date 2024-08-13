#ifndef VEHICLE_H
#define VEHICLE_H

#include "component.h"
#include <QObject>

class Vehicle: public Component, public QObject
{
    Q_OBJECT
public:
    Vehicle();
private:
    double m_MaxSpeed;
    double m_Acceleration;

};

#endif // VEHICLE_H
