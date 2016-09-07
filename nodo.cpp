#include "nodo.h"

Nodo::Nodo()
{
    nodoIzquierdo = nullptr;
    nodoDerecho = nullptr;
}

void Nodo::establecerNodoRaiz(QString valor)
{
    item = valor;
}

void Nodo::establecerNodoAlaIzquierda(Nodo *ptr)
{
    nodoIzquierdo = ptr;
}

void Nodo::establecerNodoAlaDerecha(Nodo *ptr)
{
    nodoDerecho = ptr;
}

Nodo *Nodo::obtenerNodoAlaDerecha()
{
    return nodoDerecho;
}

Nodo *Nodo::obtenerNodoAlaIzquierda()
{
    return nodoIzquierdo;
}
