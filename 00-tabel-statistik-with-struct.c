#include <math.h>
#include <stdio.h>

void minMax(float *min, float *max, float current) {
    if (current < *min) {
        *min = current;
    }
    if (current > *max) {
        *max = current;
    }
}

int main(void) {
    int n;
    printf("ALAT PENENTU TABEL FREKUENSI\n");
    printf("Note : Efektif untuk lebih dari 30 data!\n\n");
    printf("Jumlah data = ");
    scanf("%d", &n);

    // input data
    float data[n], min, max;
    printf("Data ke-1 = ");
    scanf("%f", &data[0]);
    min = data[0];
    max = data[0];

    for (int i = 1; i < n; i++) {
        printf("Data ke-%d = ", i + 1);
        scanf("%f", &data[i]);
        minMax(&min, &max, data[i]);
    }

    printf("\nmin: %.2f  max: %.2f\n", min, max);

    // mulai penghitungan statistik
    int k = round(1 + 3.3 * log10(n));
    int c = round((max - min) / k);
    printf("k = %d\nc = %d\n\n", k, c);

    // --- membuat tabel ---
    struct Table {
        float x_low[n];
        float x_top[n];
        float x_mid[n];
        int frek[n];
    } table;

    for (int i = 0; i < k; i++) {
        table.x_low[i] = min + i * c;
        table.x_top[i] = table.x_low[i] + c - 1;
        table.x_mid[i] = (table.x_low[i] + table.x_top[i]) / 2;
        table.frek[i] = 0;

        // menghitung frekuensi
        for (int j = 0; j < n; j++) {
            if (data[j] >= (table.x_low[i] - 0.5) && data[j] < (table.x_top[i]) + 0.5) {
                table.frek[i]++;
            }
        }
    }

    // output tabel
    printf("|---------------------------------------------|\n");
    printf("|       interval      |    x mid     |  frek  |\n");
    printf("|---------------------------------------------|\n");
    for (int i = 0; i < k; i++) {
        printf("%1s", "|  ");
        printf("%6.0f", table.x_low[i]);
        printf("%1s", "  -  ");
        printf("%6.0f", table.x_top[i]);
        printf("%1s", "  |  ");
        printf("%10.2f", table.x_mid[i]);
        printf("%1s", "  |  ");
        printf("%4d", table.frek[i]);
        printf("%1s", "  |\n");
    }
    printf("|---------------------------------------------|\n");

    return 0;
}
