#include<stdio.h>

// Function to return the maximum of two numbers
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int main() {
    int n, capacity, i, j, w;
    int weight[20], value[20], v[50][50];

    // Input number of items
    printf("\n\n\t\tEnter the number of items: ");
    scanf("%d", &n);

    printf("\t\t--------------------------------\n");
    printf("\n\t\t Enter : WEIGHTS - VALUES \n");
    printf("\t\t--------------------------------\n");
    printf("\t\t--------------------------------\n\t\t");

    // Input weights and values of items
    for (i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        scanf("%d", &value[i]);
        printf("\t\t");
    }

    printf("\t\t--------------------------------\n");
    printf("\t\tEnter the capacity of Knapsack: ");
    scanf("%d", &capacity);
    printf("\t\t--------------------------------\n\t\t");

    // Initialize knapsack matrix
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } else if (j - weight[i] >= 0) {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - weight[i]] + value[i]);
            } else {
                v[i][j] = v[i - 1][j];
            }
            printf("%4d", v[i][j]);
        }
        printf("\n\t\t");
    }

    // Determine which items to include in the knapsack
    w = capacity;
    printf("The items in the knapsack:\n");
    for (i = n; i > 0; i--) {
        printf("\t\t");
        if (v[i][w] != v[i - 1][w]) {
            w -= weight[i];
            printf("%3d", i);
        }
    }
    printf("\n\t\tTotal Profit = %d\n", v[n][capacity]);

    return 0;
}
