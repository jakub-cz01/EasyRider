#ifndef SIMULATIONLOOP_H
#define SIMULATIONLOOP_H

#include<unordered_map>
#include<string>

#include<QObject>
#include<QTimer>
#include<QElapsedTimer>

#include "component.h"

class SimulationLoop: public QObject {

Q_OBJECT

public:
    static SimulationLoop& GetInstance();
    void Start();
    void Pause();
    void AddComponent(Component * component);
    void RemoveComponent(Component * component);
    void SetSimulationSpeed(double speed);

    SimulationLoop(const SimulationLoop&) = delete;
    void operator=(const SimulationLoop&) = delete;
private:
    explicit SimulationLoop(QObject *parent = nullptr) : QObject(parent) {}
    std::unordered_map<std::string, Component*> m_Components;
    QTimer m_LoopTimer;
    QElapsedTimer m_ElapsedTimer;
    double m_SimulationSpeed{1.0};
    bool m_IsRunning{false};
    int m_LastFrameTime{0};

private slots:
    void UpdateLoop();
}
;

#endif // SIMULATIONLOOP_H
