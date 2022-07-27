#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define C_3 3
#define C_0 0
#define C_1 1
#define C_2 2
#define MAX_TURNOS 9

void jugarJuego();
void verificadorGanador(char simbolo);
void ganadorX(char simbolo);

char simbolo;

int main()
{
    jugarJuego();
    return 0;
}



void jugarJuego()
{
    char opc='c';
    do
    {
    char matriz[C_3][C_3]= {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int i,fila,columna,turno=C_0;
    bool juego=true,jugador=false;
    char simbolo,opc;
    printf("Juego del Gato V1.0\n");
    printf(" %c  | %c    | %c\n",matriz[0][0],matriz[0][1],matriz[0][2]);
    printf("________________\n");
    printf(" %c  | %c    | %c\n",matriz[1][0],matriz[1][1],matriz[1][2]);
    printf("________________\n");
    printf(" %c  | %c    | %c\n",matriz[2][0],matriz[2][1],matriz[2][2]);
    do
    {

        if(!jugador)
        {
            simbolo='X';
        }
        else
        {
            simbolo='O';
        }
        if (turno==MAX_TURNOS)
        {
            printf("Empate\n");
            juego = !juego;
        }
        else
        {
            printf("Es turno del jugador %c\n",simbolo);
            printf("Dime la fila (1 a 3): \n");
            scanf("%d",&fila);
            printf("Dime la columna (1 a 3): \n");
            scanf("%d",&columna);
            if(matriz[fila-C_1][columna-C_1]==' ')
            {
                matriz[fila-C_1][columna-C_1]=simbolo;
                turno++;
                jugador=!jugador;
                system("cls");
                printf("Juego del Gato V1.0\n");
                printf(" %c  | %c    | %c\n",matriz[0][0],matriz[0][1],matriz[0][2]);
                printf("________________\n");
                printf(" %c  | %c    | %c\n",matriz[1][0],matriz[1][1],matriz[1][2]);
                printf("________________\n");
                printf(" %c  | %c    | %c\n",matriz[2][0],matriz[2][1],matriz[2][2]);
                /**VA a revisar horizontal*/
                for(i=0; i<C_3; i++)
                {
                    verificadorGanador(simbolo);
                }
                ganadorX(simbolo);

            }
            else
            {
                getchar();
                printf("Casilla ocupada\n");
                getchar();
            }


        }
    }
    while(juego);
    printf("Otra partida? (S/N)");
    getchar();
    scanf("%c",&opc);
    if ((opc=='S')||(opc=='s'))
    {

    }
    else
    {
        juego=!juego;
    }
    }
    while((opc=='S')||(opc=='s'));
}


void verificadorGanador(char simbolo)
{
    char matriz[C_3][C_3]= {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int i=C_0;
    bool juego=true;
    if((matriz[i][C_0]==simbolo)&&(matriz[i][C_1]==simbolo)&&(matriz[i][C_2]==simbolo))
    {
        printf("Gano el : %c \n",simbolo);
        getchar();
        juego=!juego;
    }
    else if((matriz[C_0][i]==simbolo)&&(matriz[C_1][i]==simbolo)&&(matriz[C_2][i]==simbolo))
    {
        printf("Gano el : %c \n",simbolo);
        getchar();
        juego=!juego;
    }
    else
    {
    }
}

void ganadorX(char simbolo)
{
    char matriz[C_3][C_3]= {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    bool juego=true;
    if((matriz[C_0][C_0]==simbolo)&&(matriz[C_1][C_1]==simbolo)&&(matriz[C_2][C_2]==simbolo))
    {
        printf("Gano el : %c \n",simbolo);
        getchar();
        juego=!juego;
    }
    else if((matriz[C_0][C_2]==simbolo)&&(matriz[C_1][C_1]==simbolo)&&(matriz[C_2][C_0]==simbolo))
    {
        printf("Gano el : %c \n",simbolo);
        getchar();
        juego=!juego;

    }
    else
    {

    }
}
