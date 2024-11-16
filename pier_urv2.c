#include <stdio.h>
#include <stdlib.h>

double absa(double a, double b)
{
    if(a-b>0) return a - b;
    return b - a;
}

double sqrt(double n)//implementacja algorytmu Newtona-Raphsona dla pierwiastka kwadratowego
{
    double a = 1, b = n;
    while(absa(b, a) > 0.0000000001)
    {
        a = (a + b)/2;
        b = n / a;
        if(a==b) return a;
    }
    return a;
}

int main()
{
    double a = 0, b = 0;
    printf("Give real part\n");
    scanf("%lf", &a);
    printf("Give imaginary part\n");
    scanf("%lf", &b);
    double modul = sqrt((a*a) + (b*b));//calculating module
    double sin = sqrt((modul-a)/(2*modul));//calculating argument of rooted number (from formula calculating cosinus of doubled angle)
    double cos = sqrt(1 - (modul-a)/(2*modul));
    double real = sqrt(modul) * cos;
    double imag = sqrt(modul) * sin;
    if(b>=0) printf("%f + %fi\n -%f - %fi\n", real, imag, real, imag);
    else printf("-%f + %fi\n %f - %fi\n", real, imag, real, imag);
    return 0;
}
