#include "mainwindow.h"
#include "simulationloop.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    SimulationLoop::GetInstance().Start();
    w.show();
    return a.exec();
}
