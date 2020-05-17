
#include "../headers/Random2D.h"

#define integer 1
#define real 2

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; } // ����� ���

void get_next(Lehmer_p *obj) {
    // ������� ������ s-n���� ����� ����������� s
    obj->s_n = (obj->a * obj->s_n + obj->c) % obj->m;
}

double get_value(Lehmer_p *obj) {
    // ������� ����������� ����� r_n ����������� r
    return obj->type == real ? (double)(obj->s_n + 1) / (double)(obj->m + 1) : obj->s_n;
}

Lehmer_p get(unsigned type) { // ����������� ����������
    unsigned k = rand();
    k %= 31; // k < 31 ������  � m ���� ������������
    if (k < 3)
        k+=3; // k < 3 ������ m <= 4
    unsigned m = 1 << k; // 1) m=2^k, �� k � ���������� �����
    unsigned a = rand() % m;
    unsigned c = rand() % m;

    if (c % 2 == 0) // 2) c �� m � ������ ����� �����, �� � m ������ �� �������� ������� ��� 2
        ++c;

    if (a % 2 == 0) // 3) ���� (a-1) ������� �� �� ����� ����� p, �� � ��������� m, �� � m ������ �� �������� ������� ��� 2
        ++a;

    if (a % 4 == 0) // 4) c*(a-1) ������� �� 4., �� � m ������ �� �������� ������� ��� 2 � � �������
        a+=2;

    if (a >= m)  // a < m
        a = 1 + (m >> 1);

    if (c >= m)  // c < m
        c = 1 + (m >> 1);

    unsigned s0 = 1 + rand() % m;
    if (s0 == m) // s0 < m
        --s0;

    while (s0 == Lehmer_p_s) {
        s0 = 1 + rand() % m;
        if (s0 == m) // s0 < m
            --s0;
    }

    Lehmer_p_s = s0;
    Lehmer_p obj;
    obj.type = type;
    obj.a = a; obj.c = c;
    obj.m = m; obj.s_n = s0;
    return obj;
}

// ��������� ����������� �������
double* get_rand_vector(unsigned n, Lehmer_p *gen) {
    double *res = (double *)malloc(sizeof(double) * n);
    gen->type = real;
    for (size_t i = 0; i < n; i++) {
        res[i] = get_value(gen);
        get_next(gen);
    }
    return res;
}

// ����� �����-����� ��� ������ ��'��� n-������ �����
double monte_carlo_method(unsigned dim, double r, Lehmer_p *gen) {
    unsigned M = 0;
    //valarray<double> tmp_a(dim);
    double *tmp_a = (double *)malloc(sizeof(double) * dim);
    //vector<double> tmp_v(dim);
    for (size_t i = 0; i < 10000; i++) {

        double *tmp_v = get_rand_vector(dim, gen);
        for (size_t j = 0; j < dim; j++)
            tmp_a[j] = tmp_v[j];
        free(tmp_v);
        double sum = 0;
        for (size_t i = 0; i < dim; i++)
            sum += tmp_a[i] * tmp_a[i];
        //if (r * r > (tmp_a * tmp_a).sum())
        if (r * r > sum)
            M++;
    }
    free(tmp_a);
    return (1 << dim) * (double)M / 10000.;
}

void writeNum(double num, int digitCount, int exp) {
    char str[100] = "";
    strcpy(str, "%.");
    char number[15];
    char fmt[3] = "f";
    if (exp)
        strcpy(fmt, "e");
    sprintf(number, "%d", digitCount);
    strcat(str, number);
    strcat(str, fmt);
    printf(str, num);
}
