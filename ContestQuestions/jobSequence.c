#include <stdio.h>
#include <stdlib.h>

// A structure to represent a job
typedef struct {
    char id;      // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is completed before or on deadline
} Job;

// Comparison function for qsort to sort jobs in descending order of profit
int compareJobs(const void* a, const void* b) {
    Job* jobA = (Job*)a;
    Job* jobB = (Job*)b;
    return (jobB->profit - jobA->profit);
}

// Finds the maximum deadline among all jobs
int findMaxDeadline(Job arr[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].deadline > max) {
            max = arr[i].deadline;
        }
    }
    return max;
}

// Function to print the job sequencing solution
void printJobSequencing(Job arr[], int n) {
    // 1. Sort all jobs according to decreasing order of profit
    qsort(arr, n, sizeof(Job), compareJobs);

    // 2. Find the maximum deadline to determine the size of the result array
    int maxDeadline = findMaxDeadline(arr, n);
    
    // If there are no jobs or no valid deadlines, exit
    if (maxDeadline == 0) {
        printf("No jobs to schedule or all jobs have a deadline of 0.\n");
        return;
    }

    // 3. To keep track of free time slots
    char* result = (char*)malloc(maxDeadline * sizeof(char));
    int* slot = (int*)malloc(maxDeadline * sizeof(int));
    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = 0; // 0 indicates slot is free
    }

    int totalProfit = 0;
    int jobCount = 0;

    // 4. Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = arr[i].deadline - 1; j >= 0; j--) {
            // If a free slot is found, add this job to the result
            if (slot[j] == 0) {
                result[j] = arr[i].id; // Add this job to result
                slot[j] = 1;           // Make this slot occupied
                totalProfit += arr[i].profit;
                jobCount++;
                break; // Move to the next job
            }
        }
    }

    // Print the result
    printf("\n----------------------------------\n");
    printf("Following is the maximum profit sequence of jobs:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i]) {
            printf("%c ", result[i]);
        }
    }
    printf("\n");
    printf("Total Profit: %d\n", totalProfit);

    // Free allocated memory
    free(result);
    free(slot);
}

// Driver code
int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // Allocate memory for the jobs
    Job* arr = (Job*)malloc(n * sizeof(Job));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the job details (ID Deadline Profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        // Note the space before %c to consume any leftover whitespace (like newline)
        scanf(" %c %d %d", &arr[i].id, &arr[i].deadline, &arr[i].profit);
    }

    printJobSequencing(arr, n);
    
    // Free the memory allocated for the jobs array
    free(arr);
    
    return 0;
}
