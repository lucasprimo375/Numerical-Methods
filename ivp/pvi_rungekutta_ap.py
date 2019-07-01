# Implementação do Método de Range-Kutta de 4° ordem utilizando Python

import numpy
import sys
from decimal import Decimal

AM = 0.05
W = 2.0 # sqrt(4/1), k=4
M = 1.0 # 1 + 36%4
  
# Considerando f(x, y) = dy / dx na função abaixo
def f( t):
    if(t>=0 and t<=0.5):
        return 4*t
    
    elif(t>0.5 and t<=1):
        return 4 - 4*t
    
    else :
        return 0
    
 
def F( t,  x,  v): # dx/dt 
    return v 


def G( t,  x,  v): # dv/dt
    return f(t)/M - 2*AM*W*v - W*W*x

  
# Encontra um valor de v e x para um dado t usando passo h e
# valores iniciais v0, x0 e t0. 
def rungeKutta(t0,  x0,  v0,  t,  h): 
    # Contagem do número de iterações pela altura do passo h 
    n = int((t - t0) / h) 
    
    #printf("n = %d\n", n)
  
    # Iteração pelo número de iterações n
    x = x0
    v = v0 
    #printf("v = %f, x = %f, t = %f\n", v, x, t0)
    while t0<t: 
        # Fórmulas de Range-Kutta
        k1 = h*F(t0, x, v)
        l1 = h*G(t0, x, v)  
        k2 = h*F(t0 + 0.5*h, x + 0.5*k1,  v + 0.5*l1)
        l2 = h*G(t0 + 0.5*h, x + 0.5*k1, v + 0.5*l1) 
        k3 = h*F(t0 + 0.5*h, x + 0.5*k2, v + 0.5*l2)
        l3 = h*G(t0 + 0.5*h, x + 0.5*k2, v + 0.5*l2) 
        k4 = h*F(t0 + h, x + k3, v + l3)
        l4 = h*G(t0 + h, x + k3, v + l3)

        # Próximo valor de x
        x = x + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4)    
        # Próximo valor de v
        v = v + (1.0/6.0)*(l1 + 2*l2 + 2*l3 + l4)  
  
        # Próximo valor de t
        t0 = t0 + h
        
        #printf("v = %f, x = %f, t = %f\n", v, x, t0)
    
    v = Decimal.from_float(v)
    x = Decimal.from_float(x)
    print(f"(v: {v:.17f}, x: {x:.17f}, h: {h})")

    return v, x
 

def VX( t0,  x0,  v0,  t,  h,  tol):

    c = rungeKutta(t0, x0, v0, t, h)
    x_f = c[1]
    h = 0.5*h
    x_i = x_f
    c = rungeKutta(t0, x0, v0, t, h)
    x_f = c[1]
    while (abs((x_f-x_i)/x_f)>tol):
        #print(abs((x_f-x_i)/x_f))
        h = 0.5*h
        x_i = x_f
        c = rungeKutta(t0, x0, v0, t, h)
        x_f = c[1]
        #printf("\ndiferenca: %.32f\n", fabs(x_f-x_i))
        #print("h: {}".format(h))
        #print("x_i: {}".format(x_i))
        #print("x_f: {}\n".format(x_f))
    return c

  
# Driver method 

if len(sys.argv)!=4: print("Entre o tempo, a tolerância e o passo inicial desejados.\nEx: python pvi_rungekutta_ap.py 1.2 0.000000001 0.1")
t = float(sys.argv[1])#1.2
h = float(sys.argv[3])#0.1
tol = float(sys.argv[2])#0.000000001
t0, x0, v0 = 0, 0, 0 
c = VX(t0, x0, v0, t, h, tol) 
print(f"\nO valor de v e x em t = {t} (com tolerância de {tol}) é: \nv =  {c[0]:.17f} \nx = {c[1]:.17f}") 
