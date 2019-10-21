# MES_1D





Subject: DETERMINATION OF A FIXED TEMPERATURE FIELD IN A BAR

 Task 1 Calculate the temperature value in nodes of the finite element mesh for the problem of fixed heat charge in a bar (Fig. 2). The following output data were adopted:
 k = 50 W / mK,
 α = 10 W / m^2K, 
 S = 2 m2, 
 L = 5 m, 
 L (1) = 2.5 m,
 L (2) = 2.5 m,
 q = - 150 W / m^2,
 t∞ = 400 K
 
  Legends:
 L  Lenght
 t  Temperature
 t∞ Ambient temperature
 q  Heat flux density
 α  Convective heat factor
 S  Cross-sectional area
 k  Thermal conductivity coefficient
 
 
 fig.2
 * point

 
 
  __________________________
 |            BAR           |
 |__________________________|
 |         |                |
 | L(1)    |  L(2)          |
 *<------->*<-------------->*
t(1)     t(2)         t(3)
               x
 *------------->
      
solving the accounting task in the main.cpp file
