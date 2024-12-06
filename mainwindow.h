#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "muParser.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector<double> x, y;
    double f(double x);
    double xmin;
    double xmax;
    int N;
    double dx;
    double df(double x);
    void guardar_archivo(const char *archivo);


public slots:
    void plot_fx();
    QVector<double>biseccionMultiplefx();
    double newton_rapson();
    void plot_integralfx();
    void GuardarArchivoClicked();

};

#endif // MAINWINDOW_H
