#include <stdio.h>
#include <string.h>

#define MAX 100

struct Process {
    char id[10];
    int arrival;
    int burst;
    int waiting;
    int turnaround;
};

int main() {
    int n;
    struct Process p[MAX];

    float total_wt = 0, total_tat = 0;
    int current_time = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].id, &p[i].arrival, &p[i].burst);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival > p[j].arrival) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival) {
            current_time = p[i].arrival;
        }

        p[i].waiting = current_time - p[i].arrival;

        current_time += p[i].burst;

        p[i].turnaround = current_time - p[i].arrival;

        total_wt += p[i].waiting;
        total_tat += p[i].turnaround;
    }
    printf("Waiting Time:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].id, p[i].waiting);
    }

    printf("Turnaround Time:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].id, p[i].turnaround);
    }

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}