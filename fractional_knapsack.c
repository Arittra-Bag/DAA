#include <stdio.h>

struct Item {
    int value;
    int weight;
};

void sortByValuePerWeight(struct Item items[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            double ratio1 = (double)items[j].value / items[j].weight;
            double ratio2 = (double)items[j + 1].value / items[j + 1].weight;
            if (ratio1 < ratio2) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

double fractionalKnapsack(struct Item items[], int n, int capacity) {
    sortByValuePerWeight(items, n);
    double totalValue = 0.0;
    int currentWeight = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += (double)remainingWeight * items[i].value / items[i].weight;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n,i,capacity;
    printf("Enter the number of items: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for number of items.\n");
        return 1;
    }
    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (i = 0; i < n; i++) {
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
    double maxTotalValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value obtained from fractional knapsack problem: %.2lf\n", maxTotalValue);
    return 0;
}

