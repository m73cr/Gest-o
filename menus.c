#include <stdio.h>
#include "projects.h"
#include "collaborators.h"
#include "materials.h"
#include "tasks.h"
#include "menus.h"

void showMainMenu() {
    printf("\nProject Management System\n");
    printf("1. Manage Projects\n");
    printf("2. Manage Collaborators\n");
    printf("3. Manage Materials\n");
    printf("4. Manage Tasks\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

// Exibição do menu de gestão de projetos
void showProjectMenu() {
    printf("\nProject Management\n");
    printf("1. Create Project\n");
    printf("2. Read Project\n");
    printf("3. Update Project\n");
    printf("4. Delete Project\n");
    printf("5. Back\n");
    printf("Choose an option: ");
}

// Exibição do menu de gestão de colaboradores
void showCollaboratorMenu() {
    printf("\nCollaborator Management\n");
    printf("1. Create Collaborator\n");
    printf("2. Read Collaborator\n");
    printf("3. Update Collaborator\n");
    printf("4. Delete Collaborator\n");
    printf("5. Back\n");
    printf("Choose an option: ");
}

// Exibição do menu de gestão de materiais
void showMaterialMenu() {
    printf("\nMaterial Management\n");
    printf("1. Create Material\n");
    printf("2. Read Material\n");
    printf("3. Update Material\n");
    printf("4. Delete Material\n");
    printf("5. Back\n");
    printf("Choose an option: ");
}

// Exibição do menu de gestão de tarefas
void showTaskMenu() {
    printf("\nTask Management\n");
    printf("1. Create Task\n");
    printf("2. Read Task\n");
    printf("3. Update Task\n");
    printf("4. Delete Task\n");
    printf("5. Back\n");
    printf("Choose an option: ");
}

// Exibição do menu de relatórios
void showReports(Project* projects, int totalProjects, Material* materials, int totalMaterials,
                 Collaborator* collaborators, int totalCollaborators, Task* tasks, int totalTasks) {
    int choice;
    do {
        printf("\n==== Reports ====\n");
        printf("1. Project Report\n");
        printf("2. Material Report\n");
        printf("3. Collaborator Report\n");
        printf("4. Back to Main Menu\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reportProjects(projects, totalProjects);
                break;
            case 2:
                reportMaterials(materials, totalMaterials, projects, totalProjects);
                break;
            case 3:
                reportCollaborators(collaborators, totalCollaborators, tasks, totalTasks);
                break;
            case 4:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    } while (choice != 4);
}

