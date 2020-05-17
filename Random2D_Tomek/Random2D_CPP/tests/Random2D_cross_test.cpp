#include "../../Random2D_C/src/Random2D.c"
#include <iostream>
#include <vector>
#define integer 1
#define real 2
using namespace std;

int main(){

	Lehmer_p int_gen = get(integer), real_gen = get(real); // створюємо генератори для цілих та дійсних чисел
    srand(time(0));    // встановлюємо для кожного запуску своє зерно


    cout << "Choose:\n1) Print results in file\n2) Print results in console\n";
    int flag;
    cin >> flag;
    if (flag == 1)
        freopen("text.txt", "w", stdout);
    cout << "get_rand_vector(3, real_gen)" << endl;

    for (size_t i = 0; i < 10; i++){
        double *tmp_v = (double *)get_rand_vector(3, &real_gen);
        for (size_t i = 0; i < 3; i++)
            cout << tmp_v[i] << ' ';
        cout << endl;
        free(tmp_v);
    }
    cout << endl;

    cout << "get_rand_vector(6, real_gen)" << endl;

    for (size_t i = 0; i < 10; i++) {
        double *tmp_v = (double *)get_rand_vector(6, &real_gen);
        for (size_t i = 0; i < 6; i++)
            cout << tmp_v[i] << ' ';

        cout << endl;
        free(tmp_v);
    }
    cout << endl;

    cout << "monte_carlo_method(2, 0.2) = " << monte_carlo_method(2, 0.2, &real_gen) << endl;
    cout << "monte_carlo_method(2, 0.5) = " << monte_carlo_method(2, 0.5, &real_gen) << endl;
    cout << "monte_carlo_method(3, 0.3) = " << monte_carlo_method(3, 0.3, &real_gen) << endl;
    cout << "monte_carlo_method(3, 0.5) = " << monte_carlo_method(3, 0.5, &real_gen) << endl;
    cout << "monte_carlo_method(4, 0.5) = " << monte_carlo_method(4, 0.5, &real_gen) << endl;

    cout << endl;




}
