#include "types.h"
#include "user.h"
#define MAX_PROCESSES 10
struct Process {
    int id;
    int burst;
};
void roundRobin(struct Process processes[], int n, int timeQuantum) {
    int rem[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        rem[i] = processes[i].burst;
    }
    int done = 0;
    printf(1, "Gantt Chart:\n");
    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (rem[i] > 0) {
                int executionTime = (rem[i] > timeQuantum) ? timeQuantum : rem[i];
                rem[i] -= executionTime;
                printf(1, "| P%d (time:%d)|", processes[i].id, executionTime);
                if (rem[i] == 0) done++;
            }
        }
    }
    printf(1, "\n");
}
int main() {
    int n;
    char buf[16]; // Buffer for reading input
    printf(1, "Enter the number of processes: ");
    gets(buf, sizeof(buf));
    n = atoi(buf);
    struct Process processes[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf(1, "Enter burst time for P%d: ", i + 1);
        gets(buf, sizeof(buf));
        processes[i].burst = atoi(buf);
    }
    int timeQuantum = 3;
    roundRobin(processes, n, timeQuantum);

    exit();
}
