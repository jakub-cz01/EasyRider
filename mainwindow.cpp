#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "simulationloop.h"
#include "vehiclemanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFixedSize(800, 560);
    ui->setupUi(this);
    QSlider * spawnSlider = findChild<QSlider *>("SpawnSlider");
    QSlider * carLimitSlider = findChild<QSlider *>("CarLimitSlider");
    QSlider * simSpeedSlider = findChild<QSlider *>("SimSpeedSlider");
    QPushButton * clearButton = findChild<QPushButton *>("ClearButton");
    QPushButton * pauseButton = findChild<QPushButton *>("PauseButton");

    connect(pauseButton, &QPushButton::clicked, &SimulationLoop::GetInstance(), &SimulationLoop::ToggleSimulation);
    connect(pauseButton, &QPushButton::clicked, this, &MainWindow::OnCloseButtonClicked);
    connect(clearButton, &QPushButton::clicked, &SimulationLoop::GetInstance(), &SimulationLoop::ClearAllCars);
    connect(carLimitSlider, QSlider::valueChanged, this, &MainWindow::OnCarLimitSliderValueChange);
    connect(spawnSlider, QSlider::valueChanged, this, &MainWindow::OnSpawnSliderValueChange);
    connect(simSpeedSlider, QSlider::valueChanged, this, &MainWindow::OnSimSpeedSliderValueChange);
    connect(simSpeedSlider, QSlider::valueChanged, &SimulationLoop::GetInstance(), &SimulationLoop::SetSimulationSpeed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnCloseButtonClicked() {
    auto button = findChild<QPushButton *>("PauseButton");
    if (button->text() == "Wstrzymaj symulację") {
        button->setText("Uruchom symulację");
    } else button->setText("Wstrzymaj symulację");
}

void MainWindow::OnCarLimitSliderValueChange(int value) {
    auto sliderText = findChild<QLabel *>("CarLimitLabel");
    VehicleManager::GetInstance().SetVehicleLimit(value * 10);
    sliderText->setText(QString("Limit aut: %1").arg(value * 10));
}

void MainWindow::OnSpawnSliderValueChange(int value) {
    auto sliderText = findChild<QLabel *>("SpawnLabel");
    VehicleManager::GetInstance().SetVehicleSpawnRate(qPow(2, value) * 1000);
    sliderText->setText(QString("Czas tworzenia aut: %1s").arg(qPow(2, value)));
}

void MainWindow::OnSimSpeedSliderValueChange(int value) {
    auto sliderText = findChild<QLabel *>("SimSpeedLabel");
    sliderText->setText(QString("Prędkość symulacji: %1x").arg(qPow(2, value)));
}
