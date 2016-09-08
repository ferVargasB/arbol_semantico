#include "aplicacion.h"
#include "ui_aplicacion.h"
#include <QFile>
#include <QTextStream>
#include <QPainter>

Aplicacion::Aplicacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aplicacion)
{
    ui->setupUi(this);
    nodoActual = nullptr;
    nombreDelCodigoFuente = "C:/Users/Fredo/Desktop/codigoFuente.txt";
    nodoActual = &nodoRaiz;
    codigoFuente = "";
    obtenerCodigoFuente();

    //funciones relacionadas con el arbol
    establecerArbol();
}

Aplicacion::~Aplicacion()
{
    delete ui;
}

void Aplicacion::obtenerCodigoFuente()
{
    QFile file(nombreDelCodigoFuente);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return;

    QTextStream entrada(&file);
    while (!entrada.atEnd()) {
        codigoFuente += entrada.readLine();
    }
}

void Aplicacion::paintEvent(QPaintEvent *event)
{
    int x{250};
    int y{0};
    QPainter p(this);
    p.setPen(Qt::black);

    //lado izquierdo del arbol
    p.drawEllipse(x,y,30,30);
    p.drawEllipse(x,y,30,30);

    y = 150;
    for(int i = 100; i <= 250; i += 50){
        p.drawEllipse(i,y,30,30);
    }
    p.drawEllipse(70,y-50,30,30);
    p.drawEllipse(10,y-50,30,30);
    p.drawEllipse(120,y-50,30,30);
    p.drawEllipse(220,y-50,30,30);
    p.drawEllipse(40,y-100,30,30);
    p.drawEllipse(170,y-100,30,30);
    p.drawEllipse(100,y-130,30,30);
    p.drawLine(250,15,130,35);
    p.drawLine(130,40,170,65);
    p.drawLine(100,40,70,60);
    p.drawLine(65,75,85,100);
    p.drawLine(65,75,85,100);
    p.drawLine(50,79,20,100);
    p.drawLine(180,79,132,100);
    p.drawLine(132,130,115,150);
    p.drawLine(140,130,160,150);
    p.drawLine(240,130,260,150);
    p.drawLine(235,130,220,150);
    p.drawLine(200,74,225,100);
    p.drawText(x+10,y-130,":=");
    p.drawText(110,y-110,"=");
    p.drawText(180,y-80,"+");
    p.drawText(50,y-80,"c");
    p.drawText(17,120,"int");
    p.drawText(85,120,";");
    p.drawText(130,120,"a");
    p.drawText(230,120,"b");
    p.drawText(255,170,"null");
    p.drawText(209,170,"int");
    p.drawText(155,170,"null");
    p.drawText(105,170,"int");

    //Lado derecho
    x = 290;
    y = 20;
    p.drawEllipse(290,20,30,30);
    for(int i = 0; i < 12; i++){
        p.drawEllipse(x,y,30,30);
        x += 30;
        y += 40;
    }
    p.drawLine(280,15,295,23);

    x = 315;
    y = 45;
    for(int i = 0; i < 11; i++){
        p.drawLine(x,y,x+15,y+15);
        x += 30;
        y += 40;
    }

    x = 260;
    y = 50;
    p.drawEllipse(260,50,30,30);
    for(int i = 0; i < 11; i++){
        p.drawEllipse(x,y,30,30);
        x += 30;
        y += 40;
    }

    x = 285;
    y = 53;
    p.drawLine(x,y,x+9,y-10);
    p.drawLine(x+27,y+40,x+37,y+31);
    p.drawLine(x+54,y+79,x+69,y+70);
    p.drawLine(x+81,y+118,x+96,y+110);
    p.drawLine(x+122,y+165,x+130,y+150);
    p.drawLine(x+150,y+200,x+160,y+190);
    p.drawLine(x+178,y+240,x+190,y+230);
    p.drawLine(x+206,y+280,x+220,y+270);
    p.drawLine(x+234,y+320,x+250,y+310);
    p.drawLine(x+265,y+360,x+280,y+350);
    p.drawLine(x+300,y+400,x+310,y+390);

    //nombres de los nodos de la derecha;
    x = 300;
    y = 40;
    p.drawEllipse(290,20,30,30);
    for(int i = 0; i < 12; i++){
        if(i == 0)
            p.drawText(x,y,"if");
        if(i == 1)
            p.drawText(x,y,"c");
        if(i == 2)
            p.drawText(x,y,"<");
        if(i == 3)
            p.drawText(x,y,":=");
        if(i == 4)
            p.drawText(x,y,"=");
        if(i == 5)
            p.drawText(x,y,"+");
        if(i == 6)
            p.drawText(x,y,"2");
        if(i == 7)
            p.drawText(x,y,"else");
        if(i == 8)
            p.drawText(x,y,":=");
        if(i == 9)
            p.drawText(x,y,"=");
        if(i == 10)
            p.drawText(x,y,"-");
        if(i == 11)
            p.drawText(x,y,"1");
        x += 30;
        y += 40;
    }

    x = 265;
    y = 65;
    for(int i = 0; i < 13; i++){
        if(i == 0)
            p.drawText(x,y,"null");
        if(i == 1)
            p.drawText(x,y,"null");
        if(i == 2)
            p.drawText(x,y,"null");
        if(i == 3)
            p.drawText(x,y,"null");
        if(i == 4)
            p.drawText(x,y,"c");
        if(i == 5)
            p.drawText(x,y,"a");
        if(i == 6)
            p.drawText(x,y,"null");
        if(i == 7)
            p.drawText(x,y,"null");
        if(i == 8)
            p.drawText(x,y,"null");
        if(i == 9)
            p.drawText(x,y,"null");
        if(i == 10)
            p.drawText(x,y,"b");
        x += 30;
        y += 40;
    }
}

void Aplicacion::establecerArbol()
{
    crearRaiz();
    establecerLadoIzquierdo();
    establecerLadoDerecho();
}

void Aplicacion::crearRaiz()
{
    nodoRaiz.establecerNodoRaiz(":=");
}

void Aplicacion::estabablecerOperadoresYOperandos()
{
    bool banderaMas = true;
    int contadorDePuntoYcoma{0};
    int indice{0};
    while(contadorDePuntoYcoma < 3){
        if(codigoFuente.at(indice) == 'c'){
            Nodo *nodoCPtr = new Nodo;
            nodoCPtr->establecerNodoRaiz("c");
            Nodo *nodoInt = new Nodo;
            nodoInt->establecerNodoRaiz("int");
            Nodo *nodoComillas = new Nodo;
            nodoComillas->establecerNodoRaiz(";");
            nodoActual->establecerNodoAlaIzquierda(nodoCPtr);
            nodoCPtr->establecerNodoAlaIzquierda(nodoInt);
            nodoCPtr->establecerNodoAlaDerecha(nodoComillas);
            indice++;
        }
        else if(codigoFuente.at(indice) == '+'){
            Nodo *nuevoNodoMas = new Nodo;
            nodoActual->establecerNodoAlaDerecha(nuevoNodoMas);
            nodoActual = nuevoNodoMas;
            nodoActual->establecerNodoRaiz("+");
            banderaMas = false;
            indice++;
        }
        else if(codigoFuente.at(indice) == 'a' && banderaMas == false){
            Nodo *nuevoNodo = new Nodo;
            nuevoNodo->establecerNodoRaiz("a");
            Nodo *nuevoNodoDos = new Nodo;
            nuevoNodoDos->establecerNodoRaiz("int");
            nuevoNodo->establecerNodoAlaIzquierda(nuevoNodoDos);
            nodoActual->establecerNodoAlaIzquierda(nuevoNodo);
        }
        else if(codigoFuente.at(indice) == 'b' && banderaMas == false){
            nodoActual = nodoRaiz.obtenerNodoAlaIzquierda()->obtenerNodoAlaDerecha();
            Nodo *nuevoNodoB = new Nodo;
            nuevoNodoB->establecerNodoRaiz("b");
            Nodo *nodoBInt = new Nodo;
            nodoBInt->establecerNodoRaiz("int");
            nuevoNodoB->establecerNodoAlaIzquierda(nodoBInt);
            nodoActual->establecerNodoAlaDerecha(nuevoNodoB);
            indice++;
        }
        else if(codigoFuente.at(indice) == ';'){
            contadorDePuntoYcoma++;
        }
        indice++;
    }
}

void Aplicacion::establecerLadoMas()
{

}

void Aplicacion::establecerLadoIzquierdo()
{
    bool banderaDelIgual = true;
    int contadorDePuntoYcoma{0};
    int indice{0};
    while(contadorDePuntoYcoma < 3){
        if(codigoFuente.at(indice) == '='){
            if(banderaDelIgual){
                Nodo *nuevoNodoPtr = new Nodo;
                nodoActual->establecerNodoAlaIzquierda(nuevoNodoPtr);
                nodoActual = nuevoNodoPtr;
                nodoActual->establecerNodoRaiz("=");
                codigoFuente.remove(indice,1);
                banderaDelIgual = false;
                indice++;
            }
        }
        else if(codigoFuente.at(indice) == ';'){
            contadorDePuntoYcoma++;
        }
        else{
            indice++;
        }
    }

    /*Nodo *nuevoNodoPtr = new Nodo;
    nodoActual->establecerNodoAlaIzquierda(nuevoNodoPtr);
    nodoActual = nuevoNodoPtr;
    nodoActual->establecerNodoRaiz("=");*/

    estabablecerOperadoresYOperandos();
}

void Aplicacion::establecerLadoDerecho()
{
    int contadorIgual{0};
    bool banderaC = true;
    nodoActual = &nodoRaiz;
    Nodo *nodoIf = new Nodo;
    nodoIf->establecerNodoRaiz("if");
    nodoActual->establecerNodoAlaDerecha(nodoIf);
    nodoActual = nodoIf;

    for(int indice = 62; indice < codigoFuente.length(); indice++){
        if(codigoFuente[indice] == 'c' && banderaC == true){
            Nodo *nodoC = new Nodo;
            nodoC->establecerNodoRaiz("c");
            nodoActual->establecerNodoAlaDerecha(nodoC);
            nodoActual = nodoC;
            codigoFuente.remove(indice,1);
            banderaC = false;
        }
        else if(codigoFuente[indice] == '<'){
            Nodo *nodoMenor = new Nodo;
            nodoMenor->establecerNodoRaiz("<");
            nodoActual->establecerNodoAlaDerecha(nodoMenor);
            nodoActual = nodoMenor;
            codigoFuente.remove(indice,1);
        }
        else if(codigoFuente[indice] == '3'){
            Nodo *nodoTres = new Nodo;
            nodoTres->establecerNodoRaiz("3");
            nodoActual->establecerNodoAlaDerecha(nodoTres);
            nodoActual = nodoTres;
            codigoFuente.remove(indice,1);
            Nodo *entoncesPtr = new Nodo;
            entoncesPtr->establecerNodoRaiz(":=");
            nodoActual->establecerNodoAlaDerecha(entoncesPtr);
            nodoActual = entoncesPtr;
        }
        else if(codigoFuente[indice] == '=' && contadorIgual == 0){
            Nodo *nodoIgual = new Nodo;
            Nodo *SegundoC = new Nodo;
            nodoIgual->establecerNodoRaiz("=");
            SegundoC->establecerNodoRaiz("c");
            nodoIgual->establecerNodoAlaIzquierda(SegundoC);
            nodoActual->establecerNodoAlaDerecha(nodoIgual);
            nodoActual = nodoIgual;
            contadorIgual++;
        }
        else if(codigoFuente[indice] == '+'){
            Nodo *nodoMas = new Nodo;
            Nodo *nodoA = new Nodo;
            nodoMas->establecerNodoRaiz("+");
            nodoA->establecerNodoRaiz("a");
            nodoMas->establecerNodoAlaIzquierda(nodoA);
            nodoActual->establecerNodoAlaDerecha(nodoMas);
            nodoActual = nodoMas;
        }
        else if(codigoFuente[indice] == '2'){
            Nodo *nodoDos = new Nodo;
            nodoDos->establecerNodoRaiz("2");
            nodoActual->establecerNodoAlaDerecha(nodoDos);
            nodoActual = nodoDos;
            Nodo *nodoElse = new Nodo;
            nodoElse->establecerNodoRaiz("else");
            nodoActual->establecerNodoAlaDerecha(nodoElse);
            nodoActual = nodoElse;
            Nodo *nodoEntoncesDos = new Nodo;
            nodoEntoncesDos->establecerNodoRaiz(":=");
            nodoActual->establecerNodoAlaDerecha(nodoEntoncesDos);
            nodoActual = nodoEntoncesDos;
        }
        else if(codigoFuente[indice] == 'b'){
            Nodo *nodoIgualDos = new Nodo;
            nodoIgualDos->establecerNodoRaiz("=");
            Nodo *nodoCDos = new Nodo;
            nodoCDos->establecerNodoRaiz("c");
            nodoIgualDos->establecerNodoAlaIzquierda(nodoCDos);
            nodoActual->establecerNodoAlaDerecha(nodoIgualDos);
            nodoActual = nodoIgualDos;
        }
        else if(codigoFuente[indice] == '-'){
            Nodo *nodoMenos = new Nodo;
            nodoMenos->establecerNodoRaiz("-");
            Nodo *nodoB = new Nodo;
            nodoB->establecerNodoRaiz("b");
            nodoMenos->establecerNodoAlaIzquierda(nodoB);
            nodoActual->establecerNodoAlaDerecha(nodoMenos);
            nodoActual = nodoMenos;
        }
        else if(codigoFuente[indice] == '1'){
            Nodo *nodoUno = new Nodo;
            nodoUno->establecerNodoRaiz("1");
            nodoActual->establecerNodoAlaDerecha(nodoUno);
        }
    }
}


