//Héctor S. Salinas 1°f Leg:100171
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    // las variables varA y varB son para ingresar los datos, luego la del contador que inicia en 0 para luego ir incremetadose en 1 por iteracion realizada en las operaciones

    int opcion=0;
    float varA=0,varB=0;

    while(seguir=='s')
    {
        CLS();

        printf("\n\t\t1- Ingresar 1er operando (A=%.4f)",varA);
        printf("\n\t\t2- Ingresar 2do operando (B=%.4f)",varB);
        printf("\n\t\t3- Calcular todas las operaciones");
        printf("\n\t\t4- Informar Resultados");
        printf("\n\t\t5- Salir\n");
        printf("\n\n\t\tOpcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        opcion=ValEntero(opcion, 0, 5);

        switch(opcion)
        {
            case 1:
            	 printf("\n\t\tingrese valor A = ");
            	 fflush(stdin);
            	 scanf("%f",&varA); // en case 1 y 2 se cargan las variables a utilizar

                break;
            case 2:
            	 printf("\n\t\tingrese valor B = ");
            	 fflush(stdin);
            	 scanf("%f",&varB);

                break;

            case 3:

                Calcular_todas_las_operaciones(varA, varB);

                break;
            case 4: //imprime todas las operaciones.


                printf("\n\t\ta) El resultado de (A+B)= %.4f",Suma(varA, varB));
                printf("\n\t\tb) El resultado de (A-B)= %.4f",Resta(varA, varB));
                printf("\n\t\tc) El resultado de (A/B)= %.4f", Divicion(varA, varB));
                printf("\n\t\td) El resultado de (A*B)= %.4f", Multiplicacion(varA, varB));
                printf("\n\t\te) El factorial de (A!) es: %.4f \n\t\t   El factorial de (B!) es: %.4f\n", Factorial(varA), Factorial(varB));
                printf("\n\n\t\tPrecione cualquier telca para continuar");
                getch();

                break;
            case 5:
                seguir = 'n';
                break;
        }

    }
    return 0;
}
