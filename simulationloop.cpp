#include "simulationloop.h"
#include "vehiclemanager.h"
#include <QDebug>
SimulationLoop& SimulationLoop::GetInstance() {
    static SimulationLoop instance;
    return instance;
}

void SimulationLoop::Start() {
    if (m_IsRunning) return;
    connect(&m_LoopTimer, &QTimer::timeout, this, &SimulationLoop::UpdateLoop);

    m_LoopTimer.start(16.6 / m_SimulationSpeed);
    m_IsRunning = true;
}

void SimulationLoop::Pause() {
    if (!m_IsRunning) return;
    disconnect(&m_LoopTimer, &QTimer::timeout, this, &SimulationLoop::UpdateLoop);
    m_LoopTimer.stop();
    m_IsRunning = false;
}

void SimulationLoop::AddSimulatedObject(SimulatedObject * simulatedObject) {
    m_Objects[simulatedObject->GetSimulatedObjectId()] = simulatedObject;
}

void SimulationLoop::RemoveSimulatedObject(SimulatedObject * simulatedObject) {
    m_Objects.erase(simulatedObject->GetSimulatedObjectId());
}

void SimulationLoop::UpdateLoop() {
    int currentTime = m_ElapsedTimer.elapsed();
    int deltaTime = abs((currentTime - m_LastFrameTime) % 100);
    m_LastFrameTime = currentTime;
    for (auto& objectPair : m_Objects) {
        objectPair.second->Update(deltaTime * m_SimulationSpeed);
    }

    emit Render();
}

int SimulationLoop::GenerateId() {
    return m_IdCounter++;
}

void SimulationLoop::SetMainMap(StreetMap * map) {
    m_Map = map;;
}

void SimulationLoop::AddToScene(QGraphicsItem *object) {
    m_Map->scene()->addItem(object);
}

void SimulationLoop::RemoveFromScene(QGraphicsItem * object) {
    m_Map->scene()->removeItem(object);
    emit Render();
}

void SimulationLoop::ToggleSimulation(bool checked) {
    if (m_IsRunning) {
        Pause();
    } else {
        Start();
    }
}

void SimulationLoop::ClearAllCars(bool checked) {
    for (auto& objectPair : m_Objects) {
        Vehicle * vehicle = dynamic_cast<Vehicle *>(objectPair.second);
        if (vehicle) {
            VehicleManager::GetInstance().ResetVehicleCounter();
            delete vehicle;
        }
    }
}

void SimulationLoop::SetSimulationSpeed(int speed) {
    m_SimulationSpeed = qPow(2, speed);
    if (m_IsRunning) {
        m_LoopTimer.stop();
        m_LoopTimer.start(16.6/m_SimulationSpeed);
    }
}
