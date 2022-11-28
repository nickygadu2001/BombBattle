 #ifndef __JUGADOR_H__
 #define __JUGADOR_H__

 enum Direcciones(arriba,abajo,izquierda,derecha,neutro);
 class cjugador{
 public:
     cjugador(int x,int y){
         //posicion
         this->x=x;
         this->y=y;
         //movimiento
         direccionalX=0;
         direccionalY=0;
         //animacion movimiento
         ancho=18//caracteristicas del ancho del esprite
         alto=26//caracteristica de alto del sprite
         indiceX=0;
         indiceY=0;

         direccion = Direcciones::neutro;
         ultima =Direcciones::abajo
     }
     ~cjugador(){}
     //
     void dibujarjugador(Graphis^g,Bitmap^bmpjugador){
             Rectangle usarpixeles = Rectangle(indiceX*ancho,indiceY*alto,ancho,alto);
             Rectangle aumento = Rectangle(x,y,ancho*3,alto*3);
             g->DrawImage(bmpjugador, aumento, usarpixeles,GraphicsUnit::Pixel);
             x+=direccionalX;
             y+=direccionalY;
     }

     void movjugagor(Graphis^g,Bitmap^bmpjugador,int**){
             switch(direccion){
             case Direcciones::arriba:
                indiceY=0;
                if(indiceX>1&& indiceX<3)
                    indiceX++;
                else
                    indiceX=1;

                direccionalX=0;
                direccionalY=-10;
                neutro=arriba;
                break;

             case Direcciones::abajo:
                indiceX=0;
                if(indiceY>01&& indiceY<3)
                    indiceY++;
                else
                    indiceY=1;

                direccionalY=0;
                direccionalX=-10;
                neutro=abajo;
                break;

              case Direcciones::izquierda:
                indiceY=0;
                if(indiceX>1&& indiceX<3)
                    indiceX++;
                else
                    indiceX=1;

                direccionalY=0;
                direccionalX=10;
                neutro=izquierda;
                break;

              case Direcciones::derecha:
                indiceY=1;
                if(indiceX>1&& indiceX<3)
                    indiceX++;
                else
                    indiceX=1;

                direccionalY=0;
                direccionalX=10;
                neutro=derecha;
                break;
              case Direcciones::neutro:
                direccionalX=direccionalY=0;
                if(neutro==Direcciones::abajo){indiceX=0;indiceY=2}
                if(neutro==Direcciones::arriba){indiceX=0;indiceY=0}
                if(neutro==Direcciones::izquierda){indiceX=1;indiceY=1}
                if(neutro==Direcciones::derecha){indiceX=1;indiceY=3}
                break;
              default:
                break;
             }
             dibujarjugador(g,bmpjugador);
     }

 private:
    int x;
    int y;
    int direccionalX;
    int direccionalY;
    int ancho;
    int alto;
    int indiceX;
    int indiceY;
    Direcciones direccion;
    Direcciones ultima;
    Rectangle 
 };
 #endif // __JUGADOR_H__
