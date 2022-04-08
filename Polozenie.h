#ifndef POLOZENIE_H
#define POLOZENIE_H
#include <iostream>

typedef struct {
    int x;
    int y;
} Polozenie;
#endif

enum Kierunki
{
    LEWY = 0,
    GORNY = 1,
    PRAWY = 2,
    DOLNY = 3

};