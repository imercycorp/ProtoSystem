// Library header
#include "Arduino.h"
#include "cledm.h"
#include "oscore.h"
#include "LedControl.h"

//
// Define -- 0 : Emplacement ; 0 : Partie ; 000 : Numero animation --> 00000 ou 31001
//

const int AnimLed[][5][8]={
    { //Bouche Gauche -- Animation Normale
        {31001},
        {15,15,15,143,220,248,112,0},
        {28,62,119,227,193,128,0,0},
        {0,0,0,0,1,3,255,254},
        {0,0,0,0,0,0,255,255},
    },
    { //Bouche Droite -- Animation Normale
        {42001},
        {0,0,0,0,0,0,255,255},
        {0,0,0,0,128,192,255,127},
        {56,124,238,199,131,1,0,0},
        {240,240,240,241,59,31,14,0},
    },
    {//Oeuil Gauche -- Animation Normal
        {32001},
        {255,255,255,255,254,252,248,224},
        {255,255,255,255,127,63,31,7},
    },
    {//Oeuil Droit -- Animation Normal
        {42001},
        {255,255,255,255,254,252,248,224},
        {255,255,255,255,127,63,31,7},
    },
    {// Oueil Gauche -- Animation Ronde
        {32002},
        {192,224,240,240,240,240,224,192},
        {3,7,15,15,15,15,7,3},
    },
    {// Oeuil Droit -- Animation Ronde
        {42002},
        {192,224,240,240,240,240,224,192},
        {3,7,15,15,15,15,7,3},
    },
    {// Oeuil Gauche -- Animation Sérieuse
        {32003},
        {112,248,248,248,248,240,224,192},
        {0,0,1,3,7,15,15,7},
    },
    {// Oeuil Droit -- Animation Sérieuse
        {42003},
        {15,31,31,31,31,15,7,3},
        {0,0,128,192,224,240,240,112},
    },
    {// Oeuil Gauche -- Animation Heureuse
        {32004},
        {224,248,124,30,7,7,2,0},
        {7,31,62,120,224,224,64,0},
    },
    {// Oeuil Droit -- Animation Heureuse
        {42004},
        {224,248,124,30,7,7,2,0},
        {7,31,62,120,224,224,64,0},
    },
    {// Oeuil Gauche -- Animation Alienne
        {32005},
        {124,252,252,248,248,240,192,0},
        {0,1,3,7,7,15,7,0},
    },
    {// Oeuil droit -- Animation Alienne
        {42005},
        {0,128,192,224,224,240,240,224},
        {62,63,63,31,31,7,3,0},
    },
    {// Oeuil Gauche -- Animation Odinne
        {32006},
        {62,252,248,240,224,192,128,0},
        {0,0,3,7,15,31,31,15},
    },
    {// Oeuil Droit -- Animation Odinne
        {42006},
        {0,0,192,224,240,248,248,224},
        {124,63,31,15,7,3,1,0},
    },
    {// Oeuil Gauche -- Animation Amandine
        {32007},
        {248,248,252,252,252,252,248,192},
        {0,3,7,15,31,63,63,127},
    },
    {// Oeuil Droit -- Animation Amandine
        {42007},
        {31,31,63,63,63,63,31,3},
        {0,192,224,240,248,252,252,254},
    },
    {// Oeuil Gauche -- Animation Extase
        {32008},
        {224,240,224,192,128,0,0,0},
        {3,7,15,15,15,15,6,4,},
    },
    {// Oeuil Droite -- Animation Extase
        {42008},
        {192,224,240,240,240,240,96,32},
        {7,15,7,3,1,0,0,0},
    },
    {// Nez Gauche -- Animation Normale
        {21001},
        {0,0,0,24,28,14,6,0},
        {48,56,28,12,28,56,112,224}
    },
    {// Nez Droit -- Animation Gauche
        {22001},
        {0,6,14,28,24,0,0,0},
        {224,112,56,28,12,28,56,48},
    }
};

//
//Fonction
//

//DATA, CLK, CS, Nb Matrix
LedControl MCD=LedControl(MCD_DATA,MCD_CLK,MCD_CS,MCD_NB);
LedControl MCG=LedControl(MCG_DATA,MCG_CLK,MCG_CS,MCG_NB);

int oldimages = 0

// Code
cledm::cledm() {}

void cledm::DrawM(int loc, int emp, int images) {
  if (images != oldimages) {
    for(int img=0;img<5;img++){
            if (images == AnimLed[img][0][0]) {
                if(loc == 1){
                    for(int n=1;n<5;n++) {
                      for(int l=0;l<8;l++) {
                          if(emp == 1){
                              MCG.setRow(n+1,l,AnimLed[img][n][l]);
                          }else if(emp == 2){
                              MCD.setRow(n+1,l,AnimLed[img][n][l]);
                          }
                      }
                    }
                }else if(loc == 2){
                    for(int n=1;n<3;n++) {
                        for(int l=0;l<8;l++) {
                            if(emp == 1){
                                MCG.setRow(n-1,l,AnimLed[img][n][l]);
                            }else if(emp == 2){
                                MCD.setRow(n-1,l,AnimLed[img][n][l]);
                            }
                        }
                    }
                }else if(loc == 3){
                    for(int n=1;n<3;n++) {
                        for(int l=0;l<8;l++) {
                            if(emp == 1){
                                MCG.setRow(n+5,l,AnimLed[img][n][l]);
                            }else if(emp == 2){
                                MCD.setRow(n+5,l,AnimLed[img][n][l]);
                            }
                        }
                    }
                }
                oldimages = images;
                break;
            }
        }
    }
}
