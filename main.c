#include <stdio.h>
#include <math.h>
#include <windows.h>
#define eps 1e-10

//первая функция
double first(double x) {
    return 1.0/(sqrt(5-pow(x,3)));
}

//вторая функция
double second(double x) {
    return cos(5*x);
}

// Метод Ньютона для приближенного вычисления определенного интеграла
double Integral(double (*func)(double), double a, double b) {
    int n = 2; // Начальное количество шагов
    int max_iter = 1000;
    double result = 0.0;
    double integral_prev = 0.0;

    for (int iter = 0; iter < max_iter; ++iter) {
        double h = (b - a) / n; // Шаг интегрирования
        double sum = (func(a) + func(b)); // Первый и последний члены

        for (int i = 1; i < n; i++) {
            double x_i = a + i * h;
            double y_i = func(x_i);
            if (i % 3 == 0) {
                sum += 2 * y_i; // Каждый третий член с весом 2
            } else {
                sum += 3 * y_i; // Остальные с весом 3
            }
        }

        result = (3 * h / 8) * sum;

        if (fabs(result - integral_prev) < eps) {
            return result; // Достигли заданной точности
        }

        integral_prev = result;
        n *= 2; // Удвоение количества шагов
    }
    return result;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double result = Integral(first, -2, 1);
    printf("Приближенное значение определенного интеграла: %.10lf\n", result);
    result = Integral(second, -2, 3);
    printf("Приближенное значение определенного интеграла: %.10lf\n", result);
    return 0;
}
