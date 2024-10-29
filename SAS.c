#include <stdio.h>

typedef struct {
    char title[50];
    char description[100];
    char due_date[11]; // Format: YYYY-MM-DD
    int priority; // Priority of the task (0 for Low, 1 for High)
} Task;

int addTask(Task tasks[], int task_count) {
    if (task_count < 10) {
        printf("Enter task title: ");
        scanf(" %[^\n]", tasks[task_count].title);
        printf("Enter task description: ");
        scanf(" %[^\n]", tasks[task_count].description);
        printf("Enter due date (YYYY-MM-DD): ");
        scanf(" %[^\n]", tasks[task_count].due_date);
        printf("Enter task priority (1 for High, 0 for Low): ");
        scanf("%d", &tasks[task_count].priority);
        task_count++;
        printf("Task added successfully!\n");
    } else {
        printf("Task limit reached.\n");
    }
    return task_count;
}

void displayTasks(Task tasks[], int task_count) {
    if (task_count == 0) {
        printf("No tasks available.\n");
    } else {
        int i = 0;
        while (i < task_count) {
            printf("Task %d:\n", i + 1);
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Due Date: %s\n", tasks[i].due_date);
            printf("Priority: %s\n", tasks[i].priority ? "High" : "Low");
            printf("--------------------------\n");
            i++;
        }
    }
}


