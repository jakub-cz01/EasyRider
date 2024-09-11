#include "mainwindow.h"
#include "simulationloop.h"
#include "streetmap.h"
#include "vehiclemanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    SimulationLoop::GetInstance().Start();
    VehicleManager::GetInstance();
    w.show();
    return a.exec();
}
