#include "vehiclemanager.h"

VehicleManager& VehicleManager::GetInstance() {
    static VehicleManager instance;
    return instance;
}

void VehicleManager::Update(int deltaTime) {

}

std::string VehicleManager::GetComponentId() const {
    return m_ComponentId;
}

void VehicleManager::SetCarsPerTruckRate(int newRate) {
    m_CarsPerTruckRate = newRate;
}

void VehicleManager::SetVehicleLimit(int newLimit) {
    m_VehicleLimit = newLimit;
}

double VehicleManager::GetCarsPerTruckRate() const {
    return m_CarsPerTruckRate;
}

int VehicleManager::GetVehicleLimit() const {
    return m_VehicleLimit;
}
