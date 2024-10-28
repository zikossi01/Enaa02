#include <stdio.h>

#define MAX_PERSONS 100 // Maximum number of persons that can be stored

// Define the Address structure
struct Address {
    char street[100];
    char city[50];
    int postalCode;
};

// Define the Person structure
struct Person {
    char name[50];
    int age;
    struct Address address; // Nested Address structure
};

// Function prototypes
void createPerson(struct Person* persons, int* count);
void displayPersons(struct Person* persons, int count);
void updatePerson(struct Person* persons, int count);
void deletePerson(struct Person* persons, int* count);

int main() {
    struct Person persons[MAX_PERSONS]; // Array to store Person structures
    int count = 0; // Number of persons created
    int choice;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Create Person\n");
        printf("2. Display Persons\n");
        printf("3. Update Person\n");
        printf("4. Delete Person\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createPerson(persons, &count); // Create a new Person
                break;
            case 2:
                displayPersons(persons, count); // Display all Persons
                break;
            case 3:
                updatePerson(persons, count); // Update a Person's information
                break;
            case 4:
                deletePerson(persons, &count); // Delete a Person
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to create a new Person
void createPerson(struct Person* persons, int* count) {
    if (*count >= MAX_PERSONS) {
        printf("Cannot create more Persons. Limit reached.\n");
        return;
    }
    
    struct Person newPerson;

    // Get user input for the new Person
    printf("Enter name: ");
    scanf("%s", newPerson.name); // Basic input without spaces
    printf("Enter age: ");
    scanf("%d", &newPerson.age);
    printf("Enter street: ");
    scanf("%s", newPerson.address.street); // Basic input without spaces
    printf("Enter city: ");
    scanf("%s", newPerson.address.city); // Basic input without spaces
    printf("Enter postal code: ");
    scanf("%d", &newPerson.address.postalCode);

    // Add the new Person to the array
    persons[*count] = newPerson;
    (*count)++; // Increment the count of Persons
    printf("Person created successfully.\n");
}

// Function to display all Persons
void displayPersons(struct Person* persons, int count) {
    if (count == 0) {
        printf("No Persons available.\n");
        return;
    }

    printf("\nList of Persons:\n");
    for (int i = 0; i < count; i++) {
        printf("Person %d:\n", i + 1);
        printf("Name: %s\n", persons[i].name);
        printf("Age: %d\n", persons[i].age);
        printf("Address: %s, %s, %d\n", persons[i].address.street, persons[i].address.city, persons[i].address.postalCode);
    }
}

// Function to update a Person's information
void updatePerson(struct Person* persons, int count) {
    if (count == 0) {
        printf("No Persons available to update.\n");
        return;
    }

    int index;
    printf("Enter the person number to update (1 to %d): ", count);
    scanf("%d", &index);
    
    if (index < 1 || index > count) {
        printf("Invalid person number.\n");
        return;
    }

    struct Person* person = &persons[index - 1];

    // Get new information for the Person
    printf("Enter new name (current: %s): ", person->name);
    scanf("%s", person->name); // Basic input without spaces
    printf("Enter new age (current: %d): ", person->age);
    scanf("%d", &person->age);
    printf("Enter new street (current: %s): ", person->address.street);
    scanf("%s", person->address.street); // Basic input without spaces
    printf("Enter new city (current: %s): ", person->address.city);
    scanf("%s", person->address.city); // Basic input without spaces
    printf("Enter new postal code (current: %d): ", person->address.postalCode);
    scanf("%d", &person->address.postalCode);

    printf("Person updated successfully.\n");
}

// Function to delete a Person
void deletePerson(struct Person* persons, int* count) {
    if (*count == 0) {
        printf("No Persons available to delete.\n");
        return;
    }

    int index;
    printf("Enter the person number to delete (1 to %d): ", *count);
    scanf("%d", &index);
    
    if (index < 1 || index > *count) {
        printf("Invalid person number.\n");
        return;
    }

    // Shift remaining Persons to fill the gap
    for (int i = index - 1; i < *count - 1; i++) {
        persons[i] = persons[i + 1];
    }

    (*count)--; // Decrease the count
    printf("Person deleted successfully.\n");
}
