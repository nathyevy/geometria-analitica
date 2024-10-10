#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define t 20

typedef struct {
    int x, y, z;
} p;

void obp(p *p, char n) {
    printf("Digite os 3 valores inteiros para o ponto %c (ex: -2 6 4): ", n);
    while (scanf("%d %d %d", &p->x, &p->y, &p->z) != 3) {
        printf("Entrada inválida. Por favor, insira três números inteiros.\n");
        while (getchar() != '\n');
    }
}

float cal(p a, p b, p c) {
    return 0.5 * sqrt(
        pow((b.y - a.y) * (c.z - a.z) - (c.y - a.y) * (b.z - a.z), 2) +
        pow((b.z - a.z) * (c.x - a.x) - (c.z - a.z) * (b.x - a.x), 2) +
        pow((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y), 2)
    );
}

void imp(p a, p b, p c) {
    printf("\nTriângulo:\n");
    printf("A: (%d, %d, %d)\n", a.x, a.y, a.z);
    printf("B: (%d, %d, %d)\n", b.x, b.y, b.z);
    printf("C: (%d, %d, %d)\n", c.x, c.y, c.z);
}

void lin(char m[t][t], int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        if (x1 >= 0 && x1 < t && y1 >= 0 && y1 < t) m[y1][x1] = '.';
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

void tri(p a, p b, p c) {
    char m[t][t];

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            m[i][j] = ' ';
        }
    }

    int ax = a.x + t / 2, ay = t / 2 - a.y;
    int bx = b.x + t / 2, by = t / 2 - b.y;
    int cx = c.x + t / 2, cy = t / 2 - c.y;

    lin(m, ax, ay, bx, by);
    lin(m, bx, by, cx, cy);
    lin(m, cx, cy, ax, ay);

    if (ax >= 0 && ax < t && ay >= 0 && ay < t) m[ay][ax] = 'A';
    if (bx >= 0 && bx < t && by >= 0 && by < t) m[by][bx] = 'B';
    if (cx >= 0 && cx < t && cy >= 0 && cy < t) m[cy][cx] = 'C';

    printf("\nRepresentação gráfica do triângulo:\n");
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    p a, b, c;

    obp(&a, 'A');
    obp(&b, 'B');
    obp(&c, 'C');

    float ar = cal(a, b, c);
    printf("Área do triângulo: %.2f\n", ar);

    imp(a, b, c);
    tri(a, b, c);

    return 0;
}
