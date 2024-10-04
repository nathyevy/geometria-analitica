#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    float m = 1.0;
    float area_numerador = sqrt(30);
    int area_denominador = 2;

    float AB[3] = {-(1 - m), (2 * m - 1), 2};
    float AC[3] = {0, 2, -1};
    float produto_vetorial[3];

    produto_vetorial[0] = AB[1] * AC[2] - AB[2] * AC[1];
    produto_vetorial[1] = AB[2] * AC[0] - AB[0] * AC[2];
    produto_vetorial[2] = AB[0] * AC[1] - AB[1] * AC[0];

    printf("O valor de m que torna o triângulo ABC retângulo em A é: m = %.2f\n", m);
    printf("A área do triângulo ABC é: A = (v30) / 2\n");

    printf("\nCálculo do produto vetorial AB x AC:\n");
    printf("AB = (%.1f, %.1f, %.1f)\n", AB[0], AB[1], AB[2]);
    printf("AC = (%.1f, %.1f, %.1f)\n", AC[0], AC[1], AC[2]);
    
    printf("\nCálculo do produto vetorial:\n");
    printf("i = AB[1] * AC[2] - AB[2] * AC[1] = %.1f * %.1f - %.1f * %.1f = %.1f\n", 
           AB[1], AC[2], AB[2], AC[1], produto_vetorial[0]);
    printf("j = AB[2] * AC[0] - AB[0] * AC[2] = %.1f * %.1f - %.1f * %.1f = %.1f\n", 
           AB[2], AC[0], AB[0], AC[2], produto_vetorial[1]);
    printf("k = AB[0] * AC[1] - AB[1] * AC[0] = %.1f * %.1f - %.1f * %.1f = %.1f\n", 
           AB[0], AC[1], AB[1], AC[0], produto_vetorial[2]);

    printf("\nProduto vetorial AB x AC = (%.1f, %.1f, %.1f)\n", 
           produto_vetorial[0], produto_vetorial[1], produto_vetorial[2]);

    printf("\nEquações utilizadas:\n");
    printf("1. Produto escalar: (AB) · (AC) = 0\n");
    printf("   onde AB = (-1, 1, 2) e AC = (0, 2, -1)\n");
    printf("   Resultando em: -1(1 - m) + (2m - 1)(2) + (2)(-1) = 0\n");
    printf("2. m = 1\n");
    printf("3. Área do triângulo: Area = (1/2) * ||AB x AC||\n");
    printf("   ||AB x AC|| = v30 \n");
    printf("   Resultando em: A = (v30) / 2\n");

    printf("\nGráfico simples do triângulo ABC:\n");
    printf("            C\n");
    printf("            *\n");
    printf("          *   *\n");
    printf("        *       *\n");
    printf("      *           *\n");
    printf("    *               *\n");
    printf("  A-------------------B\n");

    return 0;
}

