#ifndef NODO_H
#define NODO_H
#include <QString>

class Nodo
{
public:
    Nodo();
    void establecerNodoRaiz(QString valor);
    void establecerNodoAlaIzquierda(Nodo *ptr);
    void establecerNodoAlaDerecha(Nodo *ptr);
    Nodo* obtenerNodoAlaDerecha();
    Nodo* obtenerNodoAlaIzquierda();
private:
    QString item;
    Nodo *nodoIzquierdo;
    Nodo *nodoDerecho;
};

#endif // NODO_H
