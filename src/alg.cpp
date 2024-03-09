// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    }
    double res_pown = 1;
    for (uint16_t i = 0; i < n; ++i) {
        res_pown *= value;
    }
    return res_pown;
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    }
    uint64_t res_fact = 1;
    for (uint16_t i = 1; i <= n; ++i) {
        res_fact *= i;
    }
    return res_fact;
}

double calcItem(double x, uint16_t n) {
    double item = pown(x, n) / fact(n);
    return item;
}

double expn(double x, uint16_t count) {
    double res_expn = 0.0;
    for (uint16_t n = 1; n <= count; ++n) {
        res_expn += calcItem(x, n);
    }
    return res_expn;
}

double sinn(double x, uint16_t count) {
    double res_sinn = x;
    for (uint16_t n = 2; n <= count; ++n) {
        res_sinn += pown(-1, n - 1) * calcItem(x, 2 * n - 1);
    }
    return res_sinn;
}

double cosn(double x, uint16_t count) {
    double res_cosn = 1;
    for (uint16_t n = 2; n <= count; ++n) {
        res_cosn += pown(-1, n - 1) * calcItem(x, 2 * n - 2);
    }
    return res_cosn;
}
