#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int at;
    int bt;
    int wt;
    int tat;
    int original_index;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Process p[100];

    for (int i = 0; i < n; i++) {
        char pname[20];
        scanf("%s %d %d", pname, &p[i].at, &p[i].bt);
        p[i].pid = atoi(pname + 1);
        p[i].original_index = i;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int cur = 0;
    for (int i = 0; i < n; i++) {

        if (cur < p[i].at)
            cur = p[i].at;

        p[i].wt = cur - p[i].at;
        cur += p[i].bt;
        p[i].tat = cur - p[i].at;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].original_index > p[j + 1].original_index) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    double avgWT = 0, avgTAT = 0;

    printf("Waiting Time:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d %d\n", p[i].pid, p[i].wt);
        avgWT += p[i].wt;
    }

    printf("Turnaround Time:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d %d\n", p[i].pid, p[i].tat);
        avgTAT += p[i].tat;
    }

    printf("Average Waiting Time: %.2f\n", avgWT / n);
    printf("Average Turnaround Time: %.2f\n", avgTAT / n);

    return 0;
}