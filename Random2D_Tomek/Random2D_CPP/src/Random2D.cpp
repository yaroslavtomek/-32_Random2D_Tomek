#include "Random2D.h"

#define integer 1
#define real 2

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }// Пошук НСД

void Lehmer_p::get_next() {
    s_n = (a * s_n + c) % m;   // функція пошуку s-nного члена послідовності s
    }
double Lehmer_p::get_value() {
    return type == real ? (double)(s_n + 1) / (double)(m + 1) : s_n; // функція знаходження члену r_n послідовності r
    }

unsigned Lehmer_p::_s = 0;

Lehmer_p get(unsigned type) { // Генерування генератору
    unsigned k = rand();
    k %= 31; // k < 31 інакше  в m буде переповнення
    if (k < 3)
        k+=3; // k < 3 інакше m <= 4
    unsigned m = 1 << k; // 1) m=2^k, де k — натуральне число
    unsigned a = rand() % m;
    unsigned c = rand() % m;

    if (c % 2 == 0) // 2) c та m — взаємно прості числа, бо у m відсутні не тривіальні дільники крім 2
        ++c;

    if (a % 2 == 0) // 3) Якщо (a-1) ділиться на всі прості числа p, що є дільниками m, бо у m відсутні не тривіальні дільники крім 2
        ++a;

    if (a % 4 == 0) // 4) c*(a-1) ділиться на 4., бо у m відсутні не тривіальні дільники крім 2 і с непарне
        a+=2;

    if (a >= m)  // a < m
        a = 1 + (m >> 1);

    if (c >= m)  // c < m
        c = 1 + (m >> 1);

    unsigned s0 = 1 + rand() % m;
    if (s0 == m) // s0 < m
        --s0;

    while (s0 == Lehmer_p::_s) {
        s0 = 1 + rand() % m;
        if (s0 == m) // s0 < m
            --s0;
    }

    Lehmer_p::_s = s0;

    return {
        type, a, c, m, s0
        };
}

vector<double> get_rand_vector(unsigned n, Lehmer_p& gen) {// Генерація випадкового вектора
    vector<double> res(n);
    gen.type = real;
    for (size_t i = 0; i < n; i++) {
        res[i] = gen.get_value();
        gen.get_next();
    }
    return res;
}

double monte_carlo_method(unsigned dim, double r, Lehmer_p& gen) {// метод Монте-Карло для пошуку об'єму n-вимірної сфери
    unsigned M = 0;
    valarray<double> tmp_a(dim);
    vector<double> tmp_v(dim);

    for (size_t i = 0; i < 10000; i++) {

        tmp_v = get_rand_vector(dim, gen);
        for (size_t j = 0; j < dim; j++)
            tmp_a[j] = tmp_v[j];

        if (r * r > (tmp_a * tmp_a).sum())
            M++;

    }
    return (1 << dim) * (double)M / 10000.;
}
