// Implementação do Método de Range-Kutta de 4° ordem utilizando C

// ATENÇÃO: código com bug, use o de Python

#include<stdio.h> 
#include<math.h>
#include <stdlib.h>
#include <string.h>

#define AM 0.05
#define W 2 // sqrt(4/1), k=4
#define M 1 // 1 + 36%4
  
// Considerando f(x, y) = dy / dx na função abaixo
float f(float t)
{
    if(t>=0 && t<=0.5){
        return 4*t;
    }
    else if(t>0.5 && t<=1){
        return 4 - 4*t;
    }
    else {
        return 0;
    }
} 
float F(float v, float x, float t) // dx/dt
{ 
    return v; 
}

float G(float v, float x, float t) // dv/dt
{
    return f(t)/M - 2*AM*W*v - W*W*x;
}
  
// Encontra um valor de v e x para um dado t usando passo h e
// valores iniciais v0, x0 e t0. 
float* rungeKutta(float t0, float x0, float v0, float t, float h) 
{ 
    // Contagem do número de iterações pela altura do passo h 
    int n = floorf((t - t0) / h); 
    
    //printf("n = %d\n", n);
  
    float k1, k2, k3, k4, l1, l2, l3, l4;

    // retorno
    float* c; 
  
    // Iteração pelo número de iterações n
    float x = x0;
    float v = v0; 
    //printf("v = %f, x = %f, t = %f\n", v, x, t0);
    for (int i=1; i<=n; i++) 
    { 
        // Fórmulas de Range-Kutta
        k1 = h*F(t0, x, v);
        l1 = h*G(t0, x, v);  
        k2 = h*F(t0 + 0.5*h, x + 0.5*k1,  v + 0.5*l1);
        l2 = h*G(t0 + 0.5*h, x + 0.5*k1, v + 0.5*l1); 
        k3 = h*F(t0 + 0.5*h, x + 0.5*k2, v + 0.5*l2);
        l3 = h*G(t0 + 0.5*h, x + 0.5*k2, v + 0.5*l2); 
        k4 = h*F(t0 + h, x + k3, v + l3);
        l4 = h*G(t0 + h, x + k3, v + l3);

        // Próximo valor de x
        x = x + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);    
        // Próximo valor de v
        v = v + (1.0/6.0)*(l1 + 2*l2 + 2*l3 + l4);  
  
        // Próximo valor de t
        t0 = t0 + h; 
        
        //printf("v = %f, x = %f, t = %f\n", v, x, t0);
    } 
    c[0] = v;
    c[1] = x;
    return c; // v(t), x(t)
} 

float* VX(float t0, float x0, float v0, float t, float h, float tol)
{
    float* c = rungeKutta(t0, x0, v0, t, h);
    float x_f = c[1];
    float x_i;
    do{
        h = 0.5*h;
        x_i = x_f;
        c = rungeKutta(t0, x0, v0, t, h);
        x_f = c[1];
        //printf("\ndiferenca: %.32f\n", fabs(x_f-x_i));
        //printf("h: %.32f\n", h);
        //printf("x_i: %.32f\n", x_i);
        //printf("x_f: %.32f\n", x_f);
    } while (fabs(x_f-x_i)>tol);
    return c;
}
  
// Driver method 
int main(int argc, char *argv[]) 
{
    if( argc != 4 ){
        printf("Coloque o valor do tempo t desejado, do passo inicial h e da tolerância tol entre 0 e 1. \n");
        printf("Exemplo: pvi_ap 1.2 0.2");
        return -1;
    }
    float t = atof(argv[1]);
    float h = atof(argv[2]);
    float tol = atof(argv[3]);
    float t0 = 0, x0 = 0, v0 = 0; 
    float *c = VX(t0, x0, v0, t, h, tol); 
    printf("\n\nO valor de v e x em t = %f eh: \n v =  %.16f \n x = %.16f", t,
            c[0], c[1]); 
    return 0; 
} 