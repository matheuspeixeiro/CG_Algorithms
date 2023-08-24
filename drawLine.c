#define _WIN32_WINNT 0x0600          /* precisa desse define e colocado aqui no in�cio */
#include "windows.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main() {

    HWND meu_console = GetConsoleWindow();
    HDC meu_dc = GetDC(meu_console);
    COLORREF COR= RGB(255,255,0);   /* cor amarela */
    printf("Algoritmo de Breseham...");
    printf(" ");
    //=============================================================
   int x1 = 50;  int y1 = 50;
   int x2 = 300; int y2 = 300;
   int dx = x2 - x1;
   int dy = y2 - y1;
   int d = 2 * dy - dx; /* Valor inicial de d */
   int incE = 2 * dy; /* Incremento de E */
   int incNE = 2 * (dy - dx); /* Incremento de NE */
   int x = x1;
   int y = y1;
    SetPixel(meu_dc,x,y,COR);
    while (x < x2){
    if (d <= 0){
/* Escolhe E */
        d = d + incE;
        x = x + 1;
        }else{
        /* Escolhe NE */
            d = d + incNE;
            x = x + 1;
            y = y + 1;
    }/* end if */
    SetPixel(meu_dc,x,y,COR);
    }/* end while */
     //=============================================================
    ReleaseDC(meu_console, meu_dc);
    getch();
    exit(0);
}
