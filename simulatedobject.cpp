#include "simulatedobject.h"
#include "simulationloop.h"

SimulatedObject::SimulatedObject() {
    m_Id = SimulationLoop::GetInstance().GenerateId();
    SimulationLoop::GetInstance().AddSimulatedObject(this);
}

SimulatedObject::~SimulatedObject() {
    SimulationLoop::GetInstance().RemoveSimulatedObject(this);
}

int SimulatedObject::GetSimulatedObjectId() const {
    return m_Id;
}
