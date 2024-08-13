#ifndef VEHICLEMANAGER_H
#define VEHICLEMANAGER_H

#include <QObject>
#include "component.h"

class VehicleManager: public Component, public QObject
{

Q_OBJECT

public:
    static VehicleManager& GetInstance();
    void Update(int deltaTime) override;
    std::string GetComponentId() const override;
    void SetCarsPerTruckRate(int newRate);
    double GetCarsPerTruckRate() const;
    void SetVehicleLimit(int newLimit);
    int GetVehicleLimit() const;

    VehicleManager(const VehicleManager&) = delete;
    void operator=(const VehicleManager&) = delete;
private:
    explicit VehicleManager(QObject *parent = nullptr) : QObject(parent) {}
    double m_CarsPerTruckRate;
    int m_VehicleLimit;
    std::string m_ComponentId;
    void SpawnVehicle();
};

#endif // VEHICLEMANAGER_H
