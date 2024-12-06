#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btn_fx, SIGNAL(clicked()), this, SLOT(plot_fx()) );
    connect(ui->biseccion, SIGNAL(clicked()), this, SLOT(biseccionMultiplefx()) );
    connect(ui->newton, SIGNAL(clicked()), this, SLOT(newton_rapson()) );
    connect(ui->btn_integralfx, SIGNAL(clicked()), this, SLOT(plot_integralfx()) );

    connect(ui->archivo, SIGNAL(clicked()), this, SLOT(GuardarArchivoClicked()) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::f(double x)
{
    mu::Parser parser;
    parser.DefineVar(L"x",&x);
    parser.SetExpr(ui->fx->text().toStdWString());
    double y = parser.Eval();
    return y;
}
void MainWindow::plot_fx()
{
    dx = ui->dx->text().toDouble();
    xmin = ui->x1->text().toDouble();
    xmax = ui->x2->text().toDouble();
    N = (xmax - xmin)/ dx;
    x.resize(N);
    y.resize(N);
    for(int i=0; i<N; i++)
    {
        x[i] = xmin + double(i)*dx;
        y[i] = f(x[i]); // Uso la función f para evaluar y[i]
    }
     //si aun no hay grafica, agrego una
    if(ui->graphic->graphCount()==0)
        ui->graphic->addGraph();
    ui->graphic->graph(0)->setData(x,y);
    ui->graphic->xAxis->setRange(xmin,xmax);
    ui->graphic->graph(0)->setPen(QPen(Qt::darkMagenta));
    ui->graphic->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);
    ui->graphic->rescaleAxes();
    ui->graphic->replot();
}

QVector<double> MainWindow::biseccionMultiplefx()
{
    QVector<double> roots;
    double x_left = ui->x1->text().toDouble();
    double x_right = ui->x2->text().toDouble();
    double umbral = 0.0000001;
    double t = 0.1; // Tamaño de subintervalo
    double end = 0;
    double y_start = 0;
    double y_end = 0;
    double root;
    int iter = 0;//contador de las iteraciones

    for (double start = x_left; start < x_right; start = start + t)
    {
        end = start + t;
        y_start = f(start);
        y_end = f(end);

        if (y_start * y_end < 0) // Si hay cambio de signo, puede haber una raíz
        {
            while (end - start> umbral) // Método de bisección
            {
                double x_middle = (start + end) / 2.0;
                double y_middle = f(x_middle);

                if ((y_start * y_middle) < 0)
                    end = x_middle;
                else
                    start = x_middle;

                iter++; //incremento el contador de iteraciones porque en el while es donde se hace el metodo de biseccion
            }
            root = (start + end) / 2.0; // Raíz encontrada
            roots.append(root); // Guardo en mi QVector root las raices para poder mostrar mas de una sola raiz
        }
    }

    QString rootText;

    if (roots.isEmpty()==false)//el vector NO está vacio
    {
        for (int i = 0; i < roots.size(); i++)
        {
            rootText = rootText +  QString::number(roots[i])+","; //separo con comas las raices para diferenciarlas
            qDebug() << "Root found f(x):" << roots[i];

        }
    }
    else
    {
        rootText = "No roots found";
    }
    ui->rbis->setText(rootText); // Muestro las raíces en la interfaz :D

    qDebug() << "Total de interacciones en biseccion: " << iter;
    return roots;
}

double MainWindow::df(double x)
{
    double dx = 1e-6;
    double dy = f(x+dx) - f(x);
    return dy/dx;
}


double MainWindow::newton_rapson()
{
    double xroot = ui->raiz->text().toDouble();       // Valor inicial estimativo de la raíz
    double umbral = 1e-5;
    double xnext = xroot;
    int iter = 0;

    do
    {
        xroot = xnext;
        double fx = f(xroot);
        double fdx = df(xroot);

        if (fdx < 1e-6 && fdx > -1e-6) // evito que la derivada sea cero o cercana a cero
        {
            qDebug() << "La derivada es demasiado pequeña cerca de x =" << xroot;
            return xroot;
        }

        xnext = xroot - fx / fdx;

        iter++;
    } while (qAbs(xnext - xroot) > umbral); // si la resta de ambos es menor a umbral, significa que encontre raiz

    qDebug() << "Raíz encontrada en x =" << xnext;
    ui->rnew->setText(QString::number(xnext));

    qDebug() << "Total de iteracciones en newton rapson: " << iter;
    return xnext;
}

void MainWindow::plot_integralfx()
{


    QVector<double> x_integral, y_integral;
    double integral = 0.0;
    for (double x = xmin; x < xmax; x += dx)
    {
        double h1 = f(x);          // Altura en el punto inicial
        double h2 = f(x + dx);     // Altura en el punto final
        double B = dx;
            // Calculo con área del trapecio
        double trap_area = (h1 + h2) * B / 2.0;
        integral += trap_area;

        x_integral.append(x);
        y_integral.append(integral);
    }
//agrego otra grafica para la integral
    if (ui->graphic->graphCount() ==1)
        ui->graphic->addGraph();


    ui->graphic->graph(1)->setData(x_integral, y_integral);
    ui->graphic->graph(1)->setPen(QPen(Qt::red));
    ui->graphic->rescaleAxes();
    ui->graphic->replot();


}

void MainWindow::guardar_archivo(const char *archivo)
{
    double x_min = ui->x1->text().toDouble();
    double x_max = ui->x2->text().toDouble();

    FILE *fa = fopen(archivo, "wb");

    if (fa == nullptr)
    {
        qDebug() << "Error al abrir el archivo para guardar los datos:";
    }

    for (double x = x_min; x <= x_max; x += dx)
    {
        double fx = f(x); // Calculo f(x) usando mi funcion f
        fwrite(&x, sizeof(double), 1, fa);  // Guardo los valores de x
        fwrite(&fx, sizeof(double), 1, fa); // Guardo los valores de f(x)
    }

    fclose(fa);
    qDebug() << "Datos guardados correctamente en el archivo";
}

//funcion que al apretar el boton, guarde los datos en el archivo de la ruta y nombre que especifique :D
void MainWindow::GuardarArchivoClicked()
{
    const char* archivo = "C:\\Users\\schme\\OneDrive\\Escritorio\\Recup2_2024\\datos_de_funcion.dat";
    guardar_archivo(archivo);
}
