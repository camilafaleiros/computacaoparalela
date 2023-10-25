//formula a ser usada para solucionar o algoritimos do trapézio
//algoritmo serial

//input: a, b n
h = (b - a)/n
approx = (f(a) + f(b))/2.0;
for (i = 1; i <= n = 1; i++) {
    x_i = a + i*h;
    approx += f(x_i); 
}
approx = h*approx;
