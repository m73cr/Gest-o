#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "collaborators.h"

void createCollaborator(Collaborator** collaborators, int* totalCollaborators) {
    Collaborator newCollaborator;
    printf("Enter Collaborator ID: ");
    scanf("%d", &newCollaborator.collaboratorId);
    getchar();  // Limpar o buffer do teclado
    printf("Enter Collaborator Name: ");
    fgets(newCollaborator.name, 100, stdin);
    newCollaborator.name[strcspn(newCollaborator.name, "\n")] = '\0';  // Remover a nova linha
    printf("Enter Collaborator Role: ");
    fgets(newCollaborator.role, 50, stdin);
    newCollaborator.role[strcspn(newCollaborator.role, "\n")] = '\0';  // Remover a nova linha
    printf("Enter Collaborator Phone: ");
    fgets(newCollaborator.phone, 15, stdin);
    newCollaborator.phone[strcspn(newCollaborator.phone, "\n")] = '\0';  // Remover a nova linha
    printf("Enter Collaborator Email: ");
    fgets(newCollaborator.email, 100, stdin);
    newCollaborator.email[strcspn(newCollaborator.email, "\n")] = '\0';  // Remover a nova linha
    printf("Enter Collaborator Hire Date (DD/MM/YYYY): ");
    fgets(newCollaborator.hireDate, 11, stdin);
    newCollaborator.hireDate[strcspn(newCollaborator.hireDate, "\n")] = '\0';  // Remover a nova linha

    // Adicionar o novo colaborador ao array
    (*collaborators) = realloc(*collaborators, sizeof(Collaborator) * (*totalCollaborators + 1));
    (*collaborators)[*totalCollaborators] = newCollaborator;
    (*totalCollaborators)++;
    printf("Collaborator added successfully!\n");
}

// Função para ler os colaboradores
void readCollaborator(Collaborator* collaborators, int totalCollaborators) {
    if (totalCollaborators == 0) {
        printf("No collaborators available.\n");
        return;
    }

    for (int i = 0; i < totalCollaborators; i++) {
        printf("\nCollaborator ID: %d\n", collaborators[i].collaboratorId);
        printf("Name: %s\n", collaborators[i].name);
        printf("Role: %s\n", collaborators[i].role);
        printf("Phone: %s\n", collaborators[i].phone);
        printf("Email: %s\n", collaborators[i].email);
        printf("Hire Date: %s\n", collaborators[i].hireDate);
    }
}

// Função para atualizar um colaborador
void updateCollaborator(Collaborator* collaborators, int totalCollaborators) {
    int id, found = 0;
    printf("Enter Collaborator ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < totalCollaborators; i++) {
        if (collaborators[i].collaboratorId == id) {
            found = 1;
            getchar();  // Limpar o buffer do teclado
            printf("Enter new name: ");
            fgets(collaborators[i].name, 100, stdin);
            collaborators[i].name[strcspn(collaborators[i].name, "\n")] = '\0';
            printf("Enter new role: ");
            fgets(collaborators[i].role, 50, stdin);
            collaborators[i].role[strcspn(collaborators[i].role, "\n")] = '\0';
            printf("Enter new phone: ");
            fgets(collaborators[i].phone, 15, stdin);
            collaborators[i].phone[strcspn(collaborators[i].phone, "\n")] = '\0';
            printf("Enter new email: ");
            fgets(collaborators[i].email, 100, stdin);
            collaborators[i].email[strcspn(collaborators[i].email, "\n")] = '\0';
            printf("Enter new hire date (DD/MM/YYYY): ");
            fgets(collaborators[i].hireDate, 11, stdin);
            collaborators[i].hireDate[strcspn(collaborators[i].hireDate, "\n")] = '\0';
            printf("Collaborator updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Collaborator not found.\n");
    }
}

// Função para excluir um colaborador
void deleteCollaborator(Collaborator* collaborators, int* totalCollaborators) {
    int id, found = 0;
    printf("Enter Collaborator ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *totalCollaborators; i++) {
        if (collaborators[i].collaboratorId == id) {
            found = 1;
            for (int j = i; j < *totalCollaborators - 1; j++) {
                collaborators[j] = collaborators[j + 1];
            }
            (*totalCollaborators)--;
            collaborators = realloc(collaborators, sizeof(Collaborator) * (*totalCollaborators));
            printf("Collaborator deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Collaborator not found.\n");
    }
}

// Função para listar todos os colaboradores
void listCollaborators(Collaborator* collaborators, int totalCollaborators) {
    if (totalCollaborators == 0) {
        printf("No collaborators available.\n");
        return;
    }

    printf("\nList of Collaborators:\n");
    for (int i = 0; i < totalCollaborators; i++) {
        printf("ID: %d, Name: %s, Role: %s, Phone: %s, Email: %s, Hire Date: %s\n",
               collaborators[i].collaboratorId, collaborators[i].name, collaborators[i].role,
               collaborators[i].phone, collaborators[i].email, collaborators[i].hireDate);
    }
}

// Função de relatório de colaboradores
void reportCollaborators(Collaborator* collaborators, int totalCollaborators, Task* tasks, int totalTasks) {
    if (totalCollaborators == 0) {
        printf("No collaborators to report.\n");
        return;
    }

    printf("\nCollaborator Report:\n");

    int totalTasksCompleted = 0;

    for (int i = 0; i < totalCollaborators; i++) {
        int tasksCompleted = 0;
        for (int j = 0; j < totalTasks; j++) {
            if (tasks[j].collaboratorId == collaborators[i].collaboratorId && tasks[j].status == TASK_COMPLETED) {
                tasksCompleted++;
            }
        }

        totalTasksCompleted += tasksCompleted;

        printf("Collaborator: %s\n", collaborators[i].name);
        printf("Role: %s\n", collaborators[i].role);
        printf("Total Completed Tasks: %d\n\n", tasksCompleted);
    }

    printf("Total Completed Tasks across all Collaborators: %d\n", totalTasksCompleted);
}