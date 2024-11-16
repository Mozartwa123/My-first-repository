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

int main(int argc, char * argv[])
{
    if(argc<3) return 0;
    double wpsa = 1;//wpsa=1 means real part of number to root is bigger that zero, wpsa=-1 means real part is smaller than zero
    if(argv[1][0] == '-') {argv[1][0] = '0'; wpsa = -1;}
    double wpsb = 1;
    double a = wpsa * atof(argv[1]);
    if(argv[2][0] == '-') {argv[2][0] = '0'; wpsb = -1;}
    double b = wpsb * atof(argv[2]);
    double modul = sqrt((a*a) + (b*b));//calculating module
    double sin = sqrt((modul-a)/(2*modul));//calculating argument of rooted number (from formula calculating cosinus of doubled angle)
    double cos = sqrt(1 - (modul-a)/(2*modul));
    double real = sqrt(modul) * cos;
    double imag = sqrt(modul) * sin;
    if(b>=0) printf("%f + %fi\n -%f - %fi\n", real, imag, real, imag);
    else printf("-%f + %fi\n %f - %fi\n", real, imag, real, imag);
    return 0;
}
