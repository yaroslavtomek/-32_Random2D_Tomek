/*
The MIT License (MIT)

Copyright (c) 2020 Yaroslav Tomek (yaroslav.tomek@gmail.com)
21.06.2014

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/* File  Random2D.h
Realization of Lehmer_p structure, function for generating vectors and calculating spheres (Task 32)
Done by TOmek Yaroslav  (group statistics-2)
Email: yaroslav.tomek@gmail.com
Date 13.05.2020 */

#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

static unsigned Lehmer_p_s = 0; // зерно минулого генератора

int gcd(int x, int y);
struct Lehmer_p{
    unsigned type, a, c, m, s_n;
};

typedef struct Lehmer_p Lehmer_p;

void get_next(Lehmer_p *obj);
double get_value(Lehmer_p *obj);

Lehmer_p get(unsigned type);
double* get_rand_vector(unsigned n, Lehmer_p *gen); // генеруємо n-вимірний вектор
double monte_carlo_method(unsigned dim, double r, Lehmer_p *gen); // пошук об'єму сфери методом монте-карло

void writeNum(double num, int digitCount, int exp); // функція виводу якоїсь кількості знаків після крапки + науковий формат
