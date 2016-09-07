#ifndef APLICACION_H
#define APLICACION_H
#include <QDialog>
#include "nodo.h"

namespace Ui {
class Aplicacion;
}

class Aplicacion : public QDialog
{
    Q_OBJECT

public:
    explicit Aplicacion(QWidget *parent = 0);
    ~Aplicacion();

    void obtenerCodigoFuente();

    void paintEvent(QPaintEvent *event);
private:
    Ui::Aplicacion *ui;
    Nodo *nodoActual;
    QString nombreDelCodigoFuente;
    QString codigoFuente;
    Nodo nodoRaiz;

    //funciones de utlidad
    void establecerArbol();
    void crearRaiz();
    void estabablecerOperadoresYOperandos();
    void establecerLadoMas();
    void establecerLadoIzquierdo();
    void establecerLadoDerecho();
};

#endif // APLICACION_H
