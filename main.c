#include <stdio.h>
#include <math.h>
#include <windows.h>

//первая функция
double first(double x) {
    return 1.0/(sqrt(5-pow(x,3)));
}

//вторая функция
double second(double x) {
    return cos(5*x);
}

// Метод Ньютона для приближенного вычисления определенного интеграла
double Integral(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n; // Шаг интегрирования
    double result = (func(a) + func(b)); // Первый и последний члены

    for (int i = 1; i < n; i++) {
        double x_i = a + i * h;
        double y_i = func(x_i);

        if (i % 3 == 0) {
            result += 2 * y_i; // Каждый третий член с весом 2
        } else {
            result += 3 * y_i; // Остальные с весом 3
        }
    }

    result = (3 * h / 8) * result;

    return result;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double eps;
    printf("Введите точность (она должна быть кратна 3): ");
    scanf("%lf",&eps);

    double result = Integral(first, -2, 1, eps);
    printf("Приближенное значение определенного интеграла: %lf\n", result);
    result = Integral(second, -2, 3, eps);
    printf("Приближенное значение определенного интеграла: %lf\n", result);
    return 0;
}
