/*
 * Student Management System
 * Registration Number: CT101/G/26680/25
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[50];
    struct Student* next;
} Student;

Student* head = NULL;


typedef struct Stack {
    int id;
    char name[50];
    struct Stack* next;
} Stack;

Stack* top = NULL;

void push(int id, char name[]) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = top;
    top = newNode;
}

Stack* pop() {
    if (top == NULL) return NULL;
    Stack* temp = top;
    top = top->next;
    return temp;
}


void addStudent() {
    Student* newStudent = (Student*)malloc(sizeof(Student));

    printf("Enter Student ID: ");
    scanf("%d", &newStudent->id);

    getchar(); 

    printf("Enter Student Name: ");
    fgets(newStudent->name, sizeof(newStudent->name), stdin);

    newStudent->next = head;
    head = newStudent;

    printf("Student added successfully!\n");
}


void viewStudents() {
    Student* temp = head;
    if (temp == NULL) {
        printf("No records found.\n");
        return;
    }

    while (temp != NULL) {
        printf("ID: %d | Name: %s", temp->id, temp->name);
        temp = temp->next;
    }
}

void searchStudent() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Found: ID=%d, Name=%s", temp->id, temp->name);
            return;
        }
        temp = temp->next;
    }

    printf("Student not found.\n");
}

void deleteStudent() {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    Student *temp = head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        push(temp->id, temp->name);
        free(temp);
        printf("Student deleted.\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found.\n");
        return;
    }

    prev->next = temp->next;
    push(temp->id, temp->name);
    free(temp);
    printf("Student deleted.\n");
}

// Undo delete
void undoDelete() {
    Stack* temp = pop();

    if (temp == NULL) {
        printf("Nothing to undo.\n");
        return;
    }

    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->id = temp->id;
    strcpy(newStudent->name, temp->name);

    newStudent->next = head;
    head = newStudent;

    free(temp);

    printf("Undo successful!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- STUDENT MANAGEMENT SYSTEM ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Undo Delete\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: undoDelete(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
