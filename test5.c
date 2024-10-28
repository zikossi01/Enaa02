#include <stdio.h>
#include <string.h>

#define MAX_PERSONS 100 // Define a constant for the maximum number of persons

// Structure to hold address information
typedef struct {
    char street[50];
    char city[50];
    int code_postal;
} Address;

// Structure to hold person information
typedef struct {
    char name[50];
    int age;
    Address address; // Corrected spelling from 'Adress' to 'Address'
} Person;

// Function prototypes
void createPerson(Person *p);
void displayPerson(const Person *p);
void displayForDeletion(const Person *p);
void deletePerson(Person persons[], int *count, int index);
void modifyPerson(Person *p);
int getValidInput(int min, int max);

int main() {
    Person persons[MAX_PERSONS]; // Array to store created persons
    int choice; // User choice
    int personCount = 0; // To track the total number of persons

    do {
        // Display menu options
        printf("What's next?\n");
        printf("1. Add a person\n");
        printf("2. Delete a person\n");
        printf("3. Modify a person\n");
        printf("4. Display persons\n");
        printf("0. Exit\n");
        choice = getValidInput(0, 4); // Get valid user choice

        switch (choice) {
            case 1: { // Adding a new person
                int numToAdd = 0;

                printf("How many persons would you like to add? (Max: %d)\n", MAX_PERSONS - personCount);
                numToAdd = getValidInput(1, MAX_PERSONS - personCount); // Get valid number of persons to add

                for (int i = 0; i < numToAdd; i++) {
                    printf("Person %d\n", personCount + 1);
                    createPerson(&persons[personCount]);
                    personCount++;
                }
                break;
            }

            case 2: { // Deleting a person
                if (personCount == 0) {
                    printf("No persons to delete.\n");
                    break;
                }
                printf("Which person number do you want to delete?\n");
                for (int i = 0; i < personCount; i++) {
                    displayForDeletion(&persons[i]);
                }
                int index = getValidInput(1, personCount);
                deletePerson(persons, &personCount, index);
                break;
            }

            case 3: { // Modifying a person
                if (personCount == 0) {
                    printf("No persons to modify.\n");
                    break;
                }
                printf("Which person number do you want to modify?\n");
                for (int i = 0; i < personCount; i++) {
                    displayForDeletion(&persons[i]);
                }
                int index = getValidInput(1, personCount);
                modifyPerson(&persons[index - 1]);
                break;
            }

            case 4: { // Displaying persons
                if (personCount == 0) {
                    printf("No persons to display.\n");
                    break;
                }
                for (int i = 0; i < personCount; i++) {
                    displayPerson(&persons[i]);
                }
                break;
            }

            case 0: // Exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("-----------------------------\n");
    } while (choice != 0);

    return 0;
}

// Function to create a new person
void createPerson(Person *p) {
    printf("Name: ");
    scanf("%49s", p->name);

    printf("Age: ");
    scanf("%d", &p->age);

    printf("Address (Street): ");
    scanf("%49s", p->address.street);

    printf("Address (City): ");
    scanf("%49s", p->address.city);

    printf("Address (Code Postal): ");
    scanf("%d", &p->address.code_postal);

    printf("-------------------------\n");
}

// Function to display a person
void displayPerson(const Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Address (Street): %s\n", p->address.street);
    printf("Address (City): %s\n", p->address.city);
    printf("Address (Code Postal): %d\n", p->address.code_postal);
    printf("--------------------------\n");
}

// Function to display a person's name for deletion
void displayForDeletion(const Person *p) {
    printf("Name: %s\n", p->name);
    printf("--------------------------\n");
}

// Function to delete a person
void deletePerson(Person persons[], int *count, int index) {
    if (index < 1 || index > *count) {
        printf("Invalid person number\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        persons[i] = persons[i + 1];
    }
    (*count)--;

    printf("Person number %d deleted successfully.\n", index);
    printf("--------------------------\n");
}

// Function to modify a person's details
void modifyPerson(Person *p) {
    int choice;
    printf("What would you like to modify?\n");
    printf("1. Name\n");
    printf("2. Age\n");
    printf("3. Address (Street)\n");
    printf("4. Address (City)\n");
    printf("5. Address (Code Postal)\n");
    printf("Choose an option (1-5): ");
    choice = getValidInput(1, 5);

    switch (choice) {
        case 1:
            printf("Enter new name: ");
            scanf("%49s", p->name);
            break;
        case 2:
            printf("Enter new age: ");
            scanf("%d", &p->age);
            break;
        case 3:
            printf("Enter new Address (Street): ");
            scanf("%49s", p->address.street);
            break;
        case 4:
            printf("Enter new Address (City): ");
            scanf("%49s", p->address.city);
            break;
        case 5:
            printf("Enter new Address (Code Postal): ");
            scanf("%d", &p->address.code_postal);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}

// Function to get valid user input within a specified range
int getValidInput(int min, int max) {
    int input;
    while (1) {
        scanf("%d", &input);
        if (input >= min && input <= max) {
            return input;
        }
        printf("Invalid input. Please enter a number between %d and %d: ", min, max);
    }
}
