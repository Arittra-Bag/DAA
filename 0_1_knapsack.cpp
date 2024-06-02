#include <stdio.h>

struct Item {
    int value;
    int weight;
};

int knapsack(struct Item items[], int n, int capacity) {
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (items[i - 1].weight <= j) {
                dp[i][j] = (items[i - 1].value + dp[i - 1][j - items[i - 1].weight] > dp[i - 1][j]) ? 
                           items[i - 1].value + dp[i - 1][j - items[i - 1].weight] : dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][capacity];
}

int main() {
    int n,capacity;
    printf("Enter the number of items: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for number of items.\n");
        return 1;
    }
    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        if (scanf("%d %d", &items[i].value, &items[i].weight) != 2 || items[i].value <= 0 || items[i].weight <= 0) {
            printf("Invalid input for item %d.\n", i + 1);
            return 1;
        }
    }
    printf("Enter the capacity of the knapsack: ");
    if (scanf("%d", &capacity) != 1 || capacity <= 0) {
        printf("Invalid input for knapsack capacity.\n");
        return 1;
    }
    int maxTotalValue = knapsack(items, n, capacity);
    printf("Maximum value obtained from 0-1 knapsack problem: %d\n", maxTotalValue);
    return 0;
}

