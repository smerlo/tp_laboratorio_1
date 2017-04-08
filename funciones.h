#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float result = 0;


void suma (float a, float b)
{
    result = a + b;
    printf("El resultado de la suma de %.2f y %.2f es %.2f \n\n", a, b ,result);
    return;
}

void resta(float a, float b)
{
    result = a - b;
    printf("El resultado de la resta de %.2f y %.2f es %.2f \n\n", a, b ,result);
    return;
}

 void division(float a, float b)
{
    // Verifica que no intenten divir por 0
    if(b == 0)
    {
        printf("No se puede divir por 0 \n\n");
    }
    // 0 dividido cualquier numero, es 0

    else if (a == 0)
    {
        printf("0 dividido cualquier numero, es 0 \n\n");
    }
    else
    {
        result = a / b;
        printf("El resultado de la division de %.2f y %.2f es %.2f \n\n", a, b ,result);
    }

    return;
}

void multiplicacion (float a, float b)
{
    // Cualquier numero multiplicado por 0 da 0, por lo cual verifica antes de
    // hacer la cuenta
    if(a == 0 || b == 0)
    {
        printf("Error: Cualquier numero multiplicado por 0 es 0 \n\n");
    }
    else
    {
        result = a * b;
        printf("El resultado de la multiplicacion de %.2f y %.2f es %.2f \n\n",a,b,result);
    }

    return;
}

void factorial(float a)
{
    int i = 1;
    int factorial = 1;
    // El factorial de 0 de 1 siempre es 1
    if(a == 0 || a == 1)
    {
        printf("El factorial de %.2f es 1 \n \n", a);
    }
    else
    {
        for (i = 1 ; i <= a ; i++)
        {
            factorial = (factorial * i);
        }
        printf("El factorial de %.2f es %d \n \n", a, (factorial));
    }
    return;
}

#endif // FUNCIONES_H_INCLUDED
