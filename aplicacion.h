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
    Nodo *nodoActual;//para saber donde esta el nodo actual
    QString nombreDelCodigoFuente; //direccion del archivo
    QString codigoFuente;//donde se almacena el codigo
    Nodo nodoRaiz;//el nodo principal, es un objeto

    //funciones de utlidad para el arbol
    void establecerArbol();
    void crearRaiz();
    void estabablecerOperadoresYOperandos();
    void establecerLadoIzquierdo();
    void establecerLadoDerecho();
};

#endif // APLICACION_H
