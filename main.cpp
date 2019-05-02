#include <vector>
#include <iostream>

#include "Vector3D.h"
#include "Esfera.h"
#include "ViewPlane.h"

#include "Utilitarios.h"
#include "Plano.h"
#include "Triangulo.h"
#include "LuzPuntual.h"
#include <algorithm> 
#include <math.h>

using namespace std;

double acotar(double n)
{
    if ( n > 1.0)
    {
        return 1.0;
    }
    else
    {
        return n;
    }
}

ColorRGB obtenerColorPixel(const Rayo& r, vector<ObjetoGeometrico*> objetos, LuzPuntual luz){
    
    ColorRGB color;

    color.r = 0.0;
    color.g = 0.0;
    color.b = 0.0;

    double t;
    double tmin = 2000000;    
    Vector3D n;
    Punto3D q;

    Vector3D h;
    for(int i = 0; i < objetos.size(); i++) {
        if( objetos[i]->hayImpacto(r, t, n, q) && t < tmin){
           // color.r = objetos[i]->obtenerColor().r;
           // color.g = objetos[i]->obtenerColor().g;
           // color.b = objetos[i]->obtenerColor().b;

            //h = ((-1)*r.d).hat();
            //color.r = acotar( 0.1 + luz.color.r * objetos[i]->obtenerColor().r * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));
            //color.g = acotar( 0.1 + luz.color.g * objetos[i]->obtenerColor().g * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));
            //color.b = acotar( 0.1 + luz.color.b * objetos[i]->obtenerColor().b * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));

            //color.r = objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion-q).hat() );
            //color.g = objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion-q).hat() );
            //color.b = objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion-q).hat() );

            color.r = objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
            color.g = objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
            color.b = objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
           
            tmin = t;
        }
    }
    return color;
}

int main() {
    //LUZ
    LuzPuntual luz(1.0, 1.0, 1.0, 0, 0, -50);

    // ESCENA--------------------------------------------------------------------------------------------
    
    //Base
    //Triangulo principal
     
    Punto3D A(-275, -225, 0);
    Punto3D B(275, -225,0);
    Punto3D C(0, 400, 0);
    Triangulo t(A,C,B);
    t.establecerColor(1.0,0.2,0.7);
    //Triangulo inferior izquierdo 1
    Punto3D ATII1(-275, -400, 0);
    Punto3D BTII1(-135, -225, 0);
    Punto3D CTII1(-275, -225, 0);
    Triangulo t2(ATII1,CTII1,BTII1);
    t2.establecerColor(1.0,0.2,0.7);
    //Triangulo inferior izquierdo 2
    Punto3D ATII2(-275, -400, 0);
    Punto3D BTII2(-275, -225, 0);
    Punto3D CTII2(-300, -300, 0);
    Triangulo t3(ATII2,CTII2,BTII2);
    t3.establecerColor(1.0,0.2,0.7);
    //Triangulo inferior izquierdo 3
    Punto3D ATII3(-275, -400, 0);
    Punto3D BTII3(-300, -300, 0);
    Punto3D CTII3(-300, -360, 0);
    Triangulo t4(ATII3,CTII3,BTII3);
    t4.establecerColor(1.0,0.2,0.7);
    
    //Triangulo inferior derecho 1
    Punto3D ATID1(275, -400, 0);
    Punto3D BTID1(275, -225, 0);
    Punto3D CTID1(135, -225, 0);
    Triangulo t5(ATID1,CTID1,BTID1);
    t5.establecerColor(1.0,0.2,0.7);
    //Triangulo inferior derecho 2
    Punto3D ATID2(275, -400, 0);
    Punto3D BTID2(300, -300, 0);
    Punto3D CTID2(275, -225, 0);
    Triangulo t6(ATID2,CTID2,BTID2);
    t6.establecerColor(1.0,0.2,0.7);
    //Triangulo inferior derecho 3
    Punto3D ATID3(275, -400, 0);
    Punto3D BTID3(300, -360, 0);
    Punto3D CTID3(300, -300, 0);
    Triangulo t7(ATID3,CTID3,BTID3);
    t7.establecerColor(1.0,0.2,0.7);

    //Triangulo inferior medio 1
    Punto3D ATIM1(-115, -300, 0);
    Punto3D BTIM1(135, -225, 0);
    Punto3D CTIM1(-135, -225, 0);
    Triangulo t8(ATIM1,CTIM1,BTIM1);
    t8.establecerColor(1.0,0.2,0.7);
    //Triangulo inferior medio 2
    Punto3D ATIM2(115, -300, 0);
    Punto3D BTIM2(135, -225, 0);
    Punto3D CTIM2(-115, -300, 0);
    Triangulo t9(ATIM2,CTIM2,BTIM2);
    t9.establecerColor(1.0,0.2,0.7);
    //Triangulo inferior medio 3
    Punto3D ATIM3(0, -400, 0);
    Punto3D BTIM3(115, -300, 0);
    Punto3D CTIM3(-115, -300, 0);
    Triangulo t10(ATIM3,CTIM3,BTIM3);
    t10.establecerColor(1.0,0.2,0.7);
    //---------------------------------------------------------------------------------------------------------------------
    //Cuerpo IZQUIERDO
    Punto3D ACI1(0, 290, 35);
    Punto3D BCI1(0, 400, 0);
    Punto3D CCI1(-25, 335, 0);
    Triangulo tci1(ACI1,CCI1,BCI1);
    tci1.establecerColor(1.0,0.1,0.9);

    Punto3D ACI2(0, 190, 100);
    Punto3D BCI2(25, 335, 0);
    Punto3D CCI2(-25, 335, 0);
    Triangulo tci2(ACI2,CCI2,BCI2);
    tci2.establecerColor(1.0,0.1,0.9);

    Punto3D ACI3(0, 190, 100);
    Punto3D BCI3(-25, 335, 0);
    Punto3D CCI3(-60, 265, 0);
    Triangulo tci3(ACI3,CCI3,BCI3);
    tci3.establecerColor(1.0,0.1,0.9);

    Punto3D ACI4(0, -195, 40);
    Punto3D BCI4(0, 190, 100);
    Punto3D CCI4(-90, -113, 40);
    Triangulo tci4(ACI4,CCI4,BCI4);
    tci4.establecerColor(1.0,0.1,0.9);

    Punto3D ACI5(-60, -25, 0);
    Punto3D BCI5(0, 190, 100);
    Punto3D CCI5(-60, 265, 0);
    Triangulo tci5(ACI5,CCI5,BCI5);
    tci5.establecerColor(1.0,0.1,0.9);

    Punto3D ACI6(-50, 210, 25);
    Punto3D BCI6(-60, 218, 0);
    Punto3D CCI6(-108, 175, 0);
    Triangulo tci6(ACI6,CCI6,BCI6);
    tci6.establecerColor(1.0,0.1,0.9);

    Punto3D ACI7(-98, 167, 25);
    Punto3D BCI7(-50, 210, 25);
    Punto3D CCI7(-108, 175, 0);
    Triangulo tci7(ACI7,CCI7,BCI7);
    tci7.establecerColor(1.0,0.1,0.9);

    Punto3D ACI8(-85, 50, 68);
    Punto3D BCI8(-43, 180, 50);
    Punto3D CCI8(-83, 135, 50);
    Triangulo tci8(ACI8,CCI8,BCI8);
    tci8.establecerColor(1.0,0.1,0.9);

    //REVISAR LA ALTURA!!!!!
    Punto3D ACI9(-60, -25, 72);
    Punto3D BCI9(-43, 180, 50);
    Punto3D CCI9(-85, 50, 68);
    Triangulo tci9(ACI9,CCI9,BCI9);
    tci9.establecerColor(1.0,0.1,0.9);





    //-------------------------------------------------------------------------------------------------------------------
    //Cuerpo DERECHO
    Punto3D ACD1(0, 290, 35);
    Punto3D BCD1(25, 335, 0);
    Punto3D CCD1(0, 400, 0);
    Triangulo tcd1(ACD1,CCD1,BCD1);
    tcd1.establecerColor(1.0,0.1,0.9);

    Punto3D ACD3(0, 190, 100);
    Punto3D BCD3(60, 265, 0);
    Punto3D CCD3(25, 335, 0);
    Triangulo tcd3(ACD3,CCD3,BCD3);
    tcd3.establecerColor(1.0,0.1,0.9);

    //======================================================================================================================
    //Metemos los objetos a la Escena
    vector<ObjetoGeometrico*> escena;

    //BASE--------------------------------
    escena.push_back(&t);
    escena.push_back(&t2);
    escena.push_back(&t3);
    escena.push_back(&t4);
    escena.push_back(&t5);
    escena.push_back(&t6);
    escena.push_back(&t7);
    escena.push_back(&t8);
    escena.push_back(&t9);
    escena.push_back(&t10);


    //CUERPO---------------------------
    // - Izquierdo
    escena.push_back(&tci1);
    escena.push_back(&tci2);
    escena.push_back(&tci3);
    escena.push_back(&tci4);
    escena.push_back(&tci5);
    escena.push_back(&tci6);
    escena.push_back(&tci7);
    escena.push_back(&tci8);
    escena.push_back(&tci9);


    //- Derecho
    escena.push_back(&tcd1);
    escena.push_back(&tcd3);
    //==========================================================================



    //Plano
     Punto3D AP(0,-1500,0);
     Vector3D v(0.1,0.1,0.1);
     Plano p(AP,v.hat());
     //p.establecerColor(0.3,0.4,0.9);
    p.establecerColor(0.5,0.75,1);
    escena.push_back(&p);

    ColorRGB color_pixel;

    //VIEWPLANE
    int hres = 1000;
    int vres = 1000;
    double s = 1.0;
    ViewPlane vp(hres, vres, s);

    // UTILITARIO PARA GUARDAR IMAGEN -------------------------------------------------------------------
    int dpi = 72;
    int width = vp.hres;
    int height = vp.vres;
    int n = width * height;
    ColorRGB* pixeles = new ColorRGB[n];

    // ALGORITMO RAYTRACER
    for(int fil = 0; fil < vp.vres; fil++)
    {
        for ( int col = 0; col < vp.hres; col++) 
        {
             // Disparamos un rayo
            Vector3D direccion(0.0, 0.0, -1.0);
            double x_o = vp.s * ( col - vp.hres/2 + 0.5 );
            double y_o = vp.s * ( fil - vp.vres/2 + 0.5 );
            double z_o = 100;
            Punto3D origen(x_o, y_o, z_o);
            Rayo rayo(origen, direccion);

            color_pixel = obtenerColorPixel(rayo, escena, luz);

            pixeles[fil*width+col].r = color_pixel.r;
            pixeles[fil*width+col].g = color_pixel.g;
            pixeles[fil*width+col].b = color_pixel.b;
        }
    }    
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}