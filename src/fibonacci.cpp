#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }
    auto alpha = (1 + sqrt(5)) / 2;
    auto znam = pow(alpha, n) - pow(-alpha, -n);
    auto chis = 2 * alpha - 1;
    return round(znam / chis);

    // Напишите здесь свой код ...
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;

    // Напишите здесь свой код ...
    for (int i = 1; i < n; i++) {
      int a = fib_curr;
      fib_curr += fib_prev;
      fib_prev = a;
    }

    return fib_curr;
  }

  int64_t fib_recursive(int n) {

    // Напишите здесь свой код ...
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] == -1) {
      // Напишите здесь свой код ...
      cache[n] = fib_recursive_memoization(n - 1, cache) + fib_recursive_memoization(n - 2, cache);
      return cache[n];
    }

    // Напишите здесь свой код ...
    return cache[n];
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }

    // Напишите здесь свой код ...
    Matrix2x2 matrix;
    matrix[0][0] = 0;
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 1;
    matrix = matrix_power(matrix, n);

    // Tip: используйте реализованную функцию matrix_pow

    return matrix[0][1];
  }

}  // namespace assignment
