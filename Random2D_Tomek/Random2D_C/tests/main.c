/*
    Маємо натуральні а, с, m, s0 такі, що m — найбільше з них.
    Визначемо послідовність натуральних чисел s0, s1, . . .sn наступним чином: sn дорівнює s_n = a*s_{n-1} + c (mod m),
    та розглянемо послідовність r_n = (s_n+1)/(m+1).
    Послідовність r_i буде імітувати рівномірно розподілені в інтервалі (0, 1) випадкові числа, якщо:
        1) m=2^k, де k — натуральне число
        2) c та m — взаємно прості числа
        3) Якщо (a-1) ділиться на всі прості числа p, що є дільниками m
        4) c*(a-1) ділиться на 4.
    Завдання:
        а) Створити функцію, що буде генерувати числа а, с, m, s0, що задовольняють вказаним умовам
        б) створити на базі цієї послідовності генератори випадкових цілих чисел  та генератор випадкових дійсних чисел
        в) створити цей генератор таким чином, щоб він генерував майже завжди різні числа при першому виклику (визначайте нове s0) та враховував попередні виклики при нових викликах (використуйте   статичний член структури або класу)
        г) на базі даного ГВЧ створить метод, що генерує n-вимірні випадкові вектори дійсних чисел, кожні дві координтати яких є некорельовані.
        Напишить код, який перевіряє на достатньо великій вибірці, що вони дійсно некорельовані.
        д) На базі методу Монте-Карло підрахуйте об“єм n-вимірної сфери.
*/

#include <time.h>
#include "../src/Random2D.c"

#define integer 1
#define real 2


int main(){
    Lehmer_p int_gen, real_gen; // створюємо генератори для цілих та дійсних чисел
    srand(time(0));    // встановлюємо для кожного запуску своє зерно
    int_gen = get(integer);
    real_gen = get(real);

    printf("Choose:\n1) Print results in file\n2) Print results in console\n");
    int flag;
    scanf("%d", &flag);
    if (flag == 1)
        freopen("text.txt", "w", stdout);
    puts("get_rand_vector(3, real_gen)");

    for (size_t i = 0; i < 10; i++){
        double *tmp_v = get_rand_vector(3, &real_gen);
        for (size_t i = 0; i < 3; i++)
            //printf("%.5f ", tmp_v[i]);
            writeNum(tmp_v[i], 6, 1); // 6 знаків після коми, 1 - експоненційний формат виводу
        puts("");
        free(tmp_v);
    }
    puts("");
    puts("get_rand_vector(6, real_gen)");

    for (size_t i = 0; i < 10; i++) {
        double *tmp_v = get_rand_vector(6, &real_gen);
        for (size_t i = 0; i < 6; i++)
            //printf("%.5f ", tmp_v[i]);
            writeNum(tmp_v[i], 5, 0);   // 5 знаків після коми, 0 - звичайний формат виводу

        puts("");
        free(tmp_v);
    }
    puts("");

    printf("monte_carlo_method(2, 0.2) = %.5f\n", monte_carlo_method(2, 0.2, &real_gen));
    printf("monte_carlo_method(2, 0.5) = %.5f\n", monte_carlo_method(2, 0.5, &real_gen));
    printf("monte_carlo_method(3, 0.3) = %.5f\n", monte_carlo_method(3, 0.3, &real_gen));
    printf("monte_carlo_method(3, 0.5) = %.5f\n", monte_carlo_method(3, 0.5, &real_gen));
    printf("monte_carlo_method(4, 0.5) = %.5f\n", monte_carlo_method(4, 0.5, &real_gen));
    puts("");

}
