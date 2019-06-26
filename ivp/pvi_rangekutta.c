// Implementação do Método de Range-Kutta de 4° ordem utilizando C++
#include<stdio.h> 
#include<math.h>
  
// Considerando f(x, y) = dy / dx na função abaixo 
float f(float x, float y) 
{ 
    return(-2*x*y); 
} 
  
// Encontra um valor de y para um dado x usando passo h e
// valores iniciais y0 e x0. 
float rungeKutta(float x0, float y0, float x, float h) 
{ 
    // Contagem do número de iterações pela altura do passo h 
    int n = floorf((x - x0) / h); 
    
    printf("n = %d\n", n);
  
    float k1, k2, k3, k4; 
  
    // Iteração pelo número de iterações n
    float y = y0; 
    printf("x = %f, y = %f\n", x0, y);
    for (int i=1; i<=n; i++) 
    { 
        // Fórmulas de Range-Kutta
        k1 = h*f(x0, y); 
        k2 = h*f(x0 + 0.5*h, y + 0.5*k1); 
        k3 = h*f(x0 + 0.5*h, y + 0.5*k2); 
        k4 = h*f(x0 + h, y + k3); 
  
        // Próximo valor de y
        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);
  
        // Próximo valor de x
        x0 = x0 + h; 
        
        printf("x = %f, y = %f \n", x0, y);
    } 
  
    return y; 
} 
  
// Driver method 
int main() 
{ 
    float x0 = 0, y0 = 2, x = 3, h = 0.25; 
    printf("\nO valor de y em x = %f eh: %.16f", x,
            rungeKutta(x0, y0, x, h)); 
    return 0; 
} 