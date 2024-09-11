/**
 * \file mainwindow.h
 * \brief Plik nagłówkowy dla klasy MainWindow.
 *
 * Ten plik zawiera deklarację klasy MainWindow, która jest głównym oknem aplikacji
 * i zawiera różne kontrolki GUI, takie jak przyciski i suwaki.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


/**
 * \class MainWindow
 * \brief Główne okno aplikacji.
 *
 * Klasa MainWindow dziedziczy po klasie QMainWindow i zarządza głównym oknem aplikacji.
 * Klasa ta zawiera wskaźnik do obiektu interfejsu użytkownika oraz sloty do obsługi
 * różnych działań, takich jak kliknięcia przycisków i zmiany wartości suwaków.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * \brief Konstruktor obiektu MainWindow.
     * \param parent Wskaźnik do rodzica okna.
     *
     * Konstruktor inicjalizuje obiekt MainWindow i ustawia wskaźnik do obiektu interfejsu
     * użytkownika.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * \brief Destruktor obiektu MainWindow.
     *
     * Destruktor zwalnia zasoby używane przez obiekt MainWindow.
     */
    ~MainWindow();

private:
    Ui::MainWindow *ui; ///< Wskaźnik do obiektu interfejsu użytkownika.

private slots:
    /**
     * \brief Slot obsługujący kliknięcie przycisku wstrzymania symulacji.
     *
     * Slot ten jest wywoływany, gdy przycisk wstrzymania symulacji zostanie kliknięty.
     */
    void OnCloseButtonClicked();

    /**
     * \brief Slot obsługujący zmianę wartości suwaka limitu pojazdów.
     * \param value Nowa wartość suwaka.
     *
     * Slot ten jest wywoływany, gdy wartość suwaka limitu pojazdów ulegnie zmianie.
     */
    void OnCarLimitSliderValueChange(int value);

    /**
     * \brief Slot obsługujący zmianę wartości suwaka częstości pojawiania się aut.
     * \param value Nowa wartość suwaka.
     *
     * Slot ten jest wywoływany, gdy wartość suwaka ulegnie zmianie.
     */
    void OnSpawnSliderValueChange(int value);

    /**
     * \brief Slot obsługujący zmianę wartości suwaka prędkości symulacji.
     * \param value Nowa wartość suwaka.
     *
     * Slot ten jest wywoływany, gdy wartość suwaka prędkości symulacji ulegnie zmianie.
     */
    void OnSimSpeedSliderValueChange(int value);
};
#endif // MAINWINDOW_H
