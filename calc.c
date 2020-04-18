//Héctor S. Salinas 1°f Leg:100171
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

/** \brief Valida valores con un valor minimo y maximo retorna valor valido
 *
 * \param entra valor int Opc
 * \param int OpcMin
 * \param int OpcMax
 * \return Opc
 *
 */
int ValEntero(int Opc, int OpcMin, int OpcMax)
{
    while(Opc<OpcMin || Opc>OpcMax)
    {
         printf("\n\t\tError debe ingresar valor entre %d y %d: ", OpcMin, OpcMax);
         fflush(stdin);
         scanf("%d",&Opc);
    }
    return Opc;
}


/** \brief entran valor float
 *          Valida con la funcion ValIntCero() que VariableB no sea 0
 * \param float VariableA
 * \param float VariableB
 * \return float
 *
 */
float Divicion(float VariableA, float VariableB)
{
    float auxB=VariableB;

    auxB=ValCero(auxB);

    return (VariableA /  auxB);
}


/** \brief entran valors float, multiplica las variables
 *
 * \param float VariableA
 * \param float VariableB
 * \return float como resultado
 *
 */
float Multiplicacion(float VariableA, float VariableB)
{
    return(VariableA * VariableB);
}


/** \brief entran valors enteros y muestra por pantalla la resta, devuelve flaot
 *
 * \param float VariableA
 * \param float VariableB
 * \return float
 *
 */
float Resta(float VariableA, float VariableB)
{
    return (VariableA - VariableB);
}


/** \brief entran valors float y muestra por pantalla la suma, devuelve float
 *
 * \param float VariableA
 * \param float VariableB
 * \return void
 *
 */
float Suma(float VariableA, float VariableB)
{

    return (VariableA+VariableB);
}

/** \brief entran valor float y muestra por pantalla resultado pasados double para procesar factorial de mas valor que los permitidos por float, devuelve float
 *
 * \param float varF
 * \param
 * \return float
 *
 */
float Factorial(float varF)//se crea el factoria usando un for o while
 {
     int i;
     float fact=1;
      if(varF==0)
    {
        fact = 1;
    }

/*
     for(i=varF; i<=1; i--)
     {
        fact = fact *i;
     }
 */
    i=(int) varF; //i se iguala a la varible ingresada para obtener el factorial y se casquea como entero int
     while(i>=1)
     {
         fact=fact * i;
         i--;
     }

    return fact;
 }


 /** \brief Verifica que el divisor no se 0, y pide que ingrese un valor distinto
  *
  * \param ingresa flaot VariableB
  * \param
  * \return VarB
  *
  */
 float ValCero(float VariableB)
 {
    float varB;
    varB=VariableB;

    if(varB==0) //verifica que el divisor no sea 0
                {
                    printf("\n\t\tNo se pude divider por 0, reingrese divisor o 1 para avanzar: ");
                    scanf("%f",&varB);
                    varB=ValCero(varB);
                }
    return varB;
 }


 /** \brief ingresa variable float,  returna valor float
  *
  * \param float num
  * \param
  * \return 1 si el valor ingresado es 0
  *
  */
  /*
 int FactorialDeClase(int num)
{
    int valor;
    if(num==0)
    {
        return 1;
    }

    valor=num*FactorialDeClase(num-1);
    return valor;
}
*/

 /** \brief ingresa variable float,  returna void
  *
  * \param float varA
  * \param float varB
  * \return void
  *
  */
void Calcular_todas_las_operaciones(float varA, float varB)
{
    char Opcion;

    printf("\n\t\ta) Calcular la suma (A+B)"
        "\n\t\tb) Calcular la resta (A-B)"
        "\n\t\tc) Calcular la division (A/B)"
        "\n\t\td) Calcular la multiplicacion (A*B)"
        "\n\t\te) Calcular el factorial (A!) (B!)");
    fflush(stdin);
    scanf("%c",&Opcion);

    Opcion = ValChar(Opcion, 'a', 'e');

    printf("\n\t\tOpcion: %c",Opcion);
    switch(Opcion)
        {
            case 'a':
                printf("\n\t\ta) El resultado de (A+B) = %.4f", Suma(varA, varB));
                break;

            case 'b':
                printf("\n\t\tb) El resultado de (A-B) = %.4f", Resta(varA, varB));
                break;

            case 'c':
                printf("\n\t\tc) El resultado de (A/B) = %.4f", Divicion(varA, varB));
                break;

            case 'd':
                printf("\n\t\td) El resultado de (A*B) = %.4f", Multiplicacion(varA, varB));
                break;

            case 'e':
                printf("\n\t\tf) El resultado de (A!) = %.4f", Factorial(varA));
                printf("\n\t\t   El resultado de (B!) = %.4f", Factorial(varB));
                break;
        }
        printf("\n\n\t\tPreciones cualquier tecla para continuar");
    getch();

    CLS();


}

/** \brief Valida entre 2 rango de caracteres, ingresa char Opc a validar entre (char OpcMin y char OpcMax)
 *
 * \param char Opc,
 * \param char OpcMin
 * \param char OpcMax
 * \return char
 *
 */
char ValChar(char Opc, char OpcMin, char OpcMax)
{
    char AuxOpc;

    AuxOpc = tolower(Opc);
    while(AuxOpc<OpcMin || AuxOpc>OpcMax)
    {
         printf("\n\t\tError debe ingresar valor entre %c y %c: ",OpcMin, OpcMax);
         fflush(stdin);
         scanf("%c",&AuxOpc);
         AuxOpc = tolower(AuxOpc);
    }
    return AuxOpc;
}

/** \brief limpia pantalla con la posibilidad que funcione de forma universal en linux y MS Windows
 *
 * \param
 * \param
 * \return void
 *
 */
void CLS(void)
{
    int VarCLS;
    printf("/n");
    VarCLS=system("cls"); //si hay error de comando devuelve 1 y ejecuta el comando compatible con Linux
    if (VarCLS==1)
    {
        system("clear");
    }
}
