#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
	char id;
	int dead;
	int profit;
} Job;

int compare(const void* a, const void* b) {
	Job* temp1 = (Job*)a;
	Job* temp2 = (Job*)b;
	return (temp2->profit - temp1->profit);
}

int min(int num1, int num2) {
	return (num1 > num2) ? num2 : num1;
}

void printJobScheduling(Job arr[], int n) {
	qsort(arr, n, sizeof(Job), compare);
	int result[n];
	bool slot[n];
	for (int i = 0; i < n; i++)
		slot[i] = false;
	for (int i = 0; i < n; i++) {
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
			if (slot[j] == false) {
				result[j] = i;
				slot[j] = true;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (slot[i])
			printf("%c ", arr[result[i]].id);
}

int main() {
    int n,total_profit=0;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for job %d:\n", i + 1);
        printf("ID: ");
        scanf(" %c", &arr[i].id);
        printf("Deadline: ");
        scanf("%d", &arr[i].dead);
        printf("Profit: ");
        scanf("%d", &arr[i].profit);
    }
    printf("Following is the maximum profit sequence of jobs:\n");
    printJobScheduling(arr, n);
    bool slot[n];
    for (int i = 0; i < n; i++) {
        slot[i] = false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                total_profit += arr[i].profit;
                slot[j] = true;
                break;
            }
        }
    }
    printf("\nTotal Profit: %d\n", total_profit);
    return 0;
}

