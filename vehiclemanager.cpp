#include "vehiclemanager.h"
#include "vehicle.h"
#include "simulationloop.h"
#include <QDebug>

VehicleManager& VehicleManager::GetInstance() {
    static VehicleManager instance;
    return instance;
}

void VehicleManager::Update(int deltaTime) {
    m_SpawnCounter -= deltaTime;
    if (m_SpawnCounter < 0 && m_VehicleCounter < m_VehicleLimit) {
        SpawnVehicle();
        m_SpawnCounter += m_VehicleSpawnRateMs;
    }
}

void VehicleManager::SetVehicleLimit(int newLimit) {
    m_VehicleLimit = newLimit;
}


int VehicleManager::GetVehicleLimit() const {
    return m_VehicleLimit;
}

void VehicleManager::SpawnVehicle() {
    auto path = m_StreetMap->GenerateShortestPath();
    int vehiclesAtStreet = path[0]->GetVehiclesAtStreet().size();
    if (vehiclesAtStreet > 3) {
        return;
    };
    Vehicle * vehicle = new Vehicle(m_StreetMap->GenerateShortestPath());
    m_StreetMap->scene()->addItem(vehicle);
    connect(vehicle, &Vehicle::FinalWaypointReached, this, &VehicleManager::OnFinalWaypointReached);
    m_VehicleCounter++;
}

void VehicleManager::SetStreetMap(StreetMap *map) {
    m_StreetMap = map;
}

void VehicleManager::OnFinalWaypointReached(Vehicle * vehicle) {
    m_VehicleCounter--;
    disconnect(vehicle, &Vehicle::FinalWaypointReached, this, &VehicleManager::OnFinalWaypointReached);
    delete vehicle;
}
void VehicleManager::ResetVehicleCounter() {
    m_VehicleCounter = 0;
}

void VehicleManager::SetVehicleSpawnRate(int vehicleSpawnRate) {
    m_VehicleSpawnRateMs = vehicleSpawnRate;
}
