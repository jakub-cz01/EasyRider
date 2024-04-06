#include "simulationloop.h"

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

void SimulationLoop::AddComponent(Component * component) {
    m_Components[component->GetComponentId()] = component;
}

void SimulationLoop::RemoveComponent(Component * component) {
    m_Components[component->GetComponentId()] = nullptr;
}

void SimulationLoop::UpdateLoop() {
    int currentTime = m_ElapsedTimer.elapsed();
    int deltaTime = currentTime - m_LastFrameTime;
    m_LastFrameTime = currentTime;

    for (auto& componentPair : m_Components) {
        componentPair.second->Update(deltaTime);
    }
}
