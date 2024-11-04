#include <stdio.h>

typedef struct
{
    char title[50];
    char description[100];
    char due_date[11]; // Format: YYYY-MM-DD
    int priority;      // Priority of the task (0 for Low, 1 for High)
} Task;

// Function to input and validate date
int inputDate(char date[11])
{
    int year, month, day;

    while (1)
    { // Loop until a valid date is entered
        printf("Enter year (2024 or later): ");
        scanf("%d", &year);

        if (year < 2024)
        {
            printf("Year must be 2024 or later. Please try again.\n");
            continue;
        }

        printf("Enter month (1-12): ");
        scanf("%d", &month);

        if (month < 1 || month > 12)
        {
            printf("Month must be between 1 and 12. Please try again.\n");
            continue;
        }

        printf("Enter day (1-31): ");
        scanf("%d", &day);

        if (day < 1 || day > 31)
        {
            printf("Day must be between 1 and 31. Please try again.\n");
            continue;
        }

        // Format and store the date in YYYY-MM-DD format
        sprintf(date, "%04d-%02d-%02d", year, month, day);
        return 1; // Indicate success
    }
}

// Function to input and validate task priority
int inputPriority()
{
    int priority;
    while (1)
    {
        printf("Enter task priority (1 for High, 0 for Low): ");
        scanf("%d", &priority);
        if (priority == 0 || priority == 1)
        {
            return priority; // Valid priority
        }
        else
        {
            printf("Invalid priority. Please enter 0 for Low or 1 for High.\n");
        }
    }
}

int addTask(Task tasks[], int task_count)
{
    if (task_count < 10)
    {
        printf("Enter task title: ");
        scanf(" %[^\n]", tasks[task_count].title);
        printf("Enter task description: ");
        scanf(" %[^\n]", tasks[task_count].description);

        // Call the inputDate function to get the due date
        if (!inputDate(tasks[task_count].due_date))
        {
            return task_count; // Return without adding the task
        }

        // Call inputPriority function for priority input
        tasks[task_count].priority = inputPriority();
        task_count++;
        printf("Task added successfully!\n");
    }
    else
    {
        printf("Task limit reached.\n");
    }
    return task_count;
}

void displayTasks(Task tasks[], int task_count)
{
    if (task_count == 0)
    {
        printf("No tasks available.\n");
    }
    else
    {
        for (int i = 0; i < task_count; i++)
        {
            printf("Task %d:\n", i + 1);
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Due Date: %s\n", tasks[i].due_date);
            printf("Priority: %s\n", tasks[i].priority ? "High" : "Low");
            printf("--------------------------\n");
        }
    }
}

int modifyTask(Task tasks[], int task_count)
{
    int index;
    printf("Enter the task number to modify: ");
    scanf("%d", &index);
    if (index > 0 && index <= task_count)
    {
        index--;
        printf("Enter new title: ");
        scanf(" %[^\n]", tasks[index].title);
        printf("Enter new description: ");
        scanf(" %[^\n]", tasks[index].description);

        // Call the inputDate function to modify the due date
        if (!inputDate(tasks[index].due_date))
        {
            return task_count; // Return without modifying the task
        }

        // Call inputPriority function for priority input
        tasks[index].priority = inputPriority();
        printf("Task modified successfully!\n");
    }
    else
    {
        printf("Invalid task number.\n");
    }
    return task_count;
}

int deleteTask(Task tasks[], int task_count)
{
    int index;
    printf("Enter the task number to delete: ");
    scanf("%d", &index);
    if (index > 0 && index <= task_count)
    {
        index--;
        for (int i = index; i < task_count - 1; i++)
        {
            tasks[i] = tasks[i + 1];
        }
        task_count--;
        printf("Task deleted successfully!\n");
    }
    else
    {
        printf("Invalid task number.\n");
    }
    return task_count;
}

void filterTasksByPriority(Task tasks[], int task_count)
{
    if (task_count == 0)
    {
        printf("No tasks available.\n");
        return;
    }
    int filter_priority, found = 0;
    printf("Enter priority to filter by (1 for High, 0 for Low): ");
    scanf("%d", &filter_priority);

    for (int i = 0; i < task_count; i++)
    {
        if (tasks[i].priority == filter_priority)
        {
            printf("Task %d:\n", i + 1);
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Due Date: %s\n", tasks[i].due_date);
            printf("--------------------------\n");
            found = 1;
        }
    }
    if (!found)
    {
        printf("No tasks found with the specified priority.\n");
    }
}

int main()
{
    Task tasks[10];
    int task_count = 0, choice = -1;

    while (choice != 0)
    {
        printf("Task Management Application\n");
        printf("1. Add Task\n2. Display Tasks\n3. Modify Task\n4. Delete Task\n5. Filter Tasks by Priority\n0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        printf("-----------------------------\n");
        switch (choice)
        {
        case 1:
            task_count = addTask(tasks, task_count);
            break;
        case 2:
            displayTasks(tasks, task_count);
            break;
        case 3:
            task_count = modifyTask(tasks, task_count);
            break;
        case 4:
            task_count = deleteTask(tasks, task_count);
            break;
        case 5:
            filterTasksByPriority(tasks, task_count);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
    return 0;
}
