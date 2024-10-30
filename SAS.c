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

int modifyTask(Task tasks[], int task_count) {
    int index;
    printf("Enter the task number to modify: ");
    scanf("%d", &index);
    if (index > 0 && index <= task_count) {
        index--;
        printf("Enter new title: ");
        scanf(" %[^\n]", tasks[index].title);
        printf("Enter new description: ");
        scanf(" %[^\n]", tasks[index].description);
        printf("Enter new due date (YYYY-MM-DD): ");
        scanf(" %[^\n]", tasks[index].due_date);
        printf("Enter new priority (1 for High, 0 for Low): ");
        scanf("%d", &tasks[index].priority);
        printf("Task modified successfully!\n");
    } else {
        printf("Invalid task number.\n");
    }
    return task_count;
}

int deleteTask(Task tasks[], int task_count) {
    int index;
    printf("Enter the task number to delete: ");
    scanf("%d", &index);
    if (index > 0 && index <= task_count) {
        index--;
        int i = index;
        while (i < task_count - 1) {
            tasks[i] = tasks[i + 1];
            i++;
        }
        task_count--;
        printf("Task deleted successfully!\n");
    } else {
        printf("Invalid task number.\n");
    }
    return task_count;
}

void filterTasksByPriority(Task tasks[], int task_count) {
    if (task_count == 0) {
        printf("No tasks available.\n");
        return;
    }
    int filter_priority, found = 0;
    printf("Enter priority to filter by (1 for High, 0 for Low): ");
    scanf("%d", &filter_priority);
    
    int i = 0;
    while (i < task_count) {
        if (tasks[i].priority == filter_priority) {
            printf("Task %d:\n", i + 1);
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Due Date: %s\n", tasks[i].due_date);
            printf("--------------------------\n");
            found = 1;
        }
        i++;
    }
    if (found == 0) {
        printf("No tasks found\n");
    }
}

int main() {
    Task tasks[10];
    int task_count = 0, choice = -1;

    while (choice != 0) {
        printf("Task Management Application\n");
        printf("1. Add Task\n2. Display Tasks\n3. Modify Task\n4. Delete Task\n5. Filter Tasks by Priority\n0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        printf("-----------------------------\n");

        if (choice == 1) {
            task_count = addTask(tasks, task_count);
        } else if (choice == 2) {
            displayTasks(tasks, task_count);
        } else if (choice == 3) {
            task_count = modifyTask(tasks, task_count);
        } else if (choice == 4) {
            task_count = deleteTask(tasks, task_count);
        } else if (choice == 5) {
            filterTasksByPriority(tasks, task_count);
        } else if (choice == 0) {
            printf("Exiting...\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

