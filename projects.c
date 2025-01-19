#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "projects.h"
#include "tasks.h"

void createProject(Project** projects, int* totalProjects) {
    Project newProject;

    // Atribuir um ID único ao projeto
    newProject.projectId = *totalProjects;
    (*totalProjects)++;  // Incrementa o número total de projetos

    printf("Project Name: ");
    getchar();  // Limpar o buffer de entrada
    fgets(newProject.name, 100, stdin);
    newProject.name[strcspn(newProject.name, "\n")] = '\0';  // Remover nova linha

    printf("Location: ");
    fgets(newProject.location, 100, stdin);
    newProject.location[strcspn(newProject.location, "\n")] = '\0';  // Remover nova linha

    printf("Start Date (DD/MM/YYYY): ");
    fgets(newProject.startDate, 11, stdin);
    newProject.startDate[strcspn(newProject.startDate, "\n")] = '\0';  // Remover nova linha

    
    printf("End Date (DD/MM/YYYY): ");
    getchar();
    fgets(newProject.endDate, 11, stdin);
    newProject.endDate[strcspn(newProject.endDate, "\n")] = '\0';  // Remover nova linha

    newProject.status = PROJECT_PLANNED;  // Inicialmente o projeto está planeado
    newProject.taskCount = 0;
    newProject.tasks = NULL;  // Inicialmente sem tarefas associadas

    // Alocar memória para o projeto e armazená-lo
    *projects = realloc(*projects, sizeof(Project) * (*totalProjects));
    (*projects)[*totalProjects - 1] = newProject;

    printf("Project \"%s\" created successfully!\n", newProject.name);
}

void readProject(Project* projects, int totalProjects) {
    int id;
    printf("Enter the project ID to view: ");
    scanf("%d", &id);

    if (id < 0 || id >= totalProjects) {
        printf("Project not found!\n");
    } else {
        printf("\nProject ID: %d\n", projects[id].projectId);
        printf("Name: %s\n", projects[id].name);
        printf("Location: %s\n", projects[id].location);
        printf("Start Date: %s\n", projects[id].startDate);
        printf("End Date: %s\n", projects[id].endDate);

        printf("Status: ");
        switch (projects[id].status) {
            case PROJECT_PLANNED: printf("Planned\n"); break;
            case PROJECT_IN_PROGRESS: printf("In Progress\n"); break;
            case PROJECT_COMPLETED: printf("Completed\n"); break;
        }

        printf("Number of tasks: %d\n", projects[id].taskCount);
    }
}

void updateProject(Project* projects, int totalProjects) {
    int id;
    printf("Enter the project ID to update: ");
    scanf("%d", &id);

    if (id < 0 || id >= totalProjects) {
        printf("Project not found!\n");
    } else {
        printf("Updating project \"%s\"...\n", projects[id].name);

        // Atualizar detalhes do projeto
        getchar();  // Limpar buffer de entrada
        printf("New Project Name: ");
        fgets(projects[id].name, 100, stdin);
        projects[id].name[strcspn(projects[id].name, "\n")] = '\0';  // Remover nova linha

        printf("New Location: ");
        fgets(projects[id].location, 100, stdin);
        projects[id].location[strcspn(projects[id].location, "\n")] = '\0';  // Remover nova linha

        printf("New Start Date (DD/MM/YYYY): ");
        fgets(projects[id].startDate, 11, stdin);
        projects[id].startDate[strcspn(projects[id].startDate, "\n")] = '\0';  // Remover nova linha

        printf("New End Date (DD/MM/YYYY): ");
        fgets(projects[id].endDate, 11, stdin);
        projects[id].endDate[strcspn(projects[id].endDate, "\n")] = '\0';  // Remover nova linha

        printf("Select new status (0: Planned, 1: In Progress, 2: Completed): ");
        int status;
        scanf("%d", &status);
        if (status >= 0 && status <= 2) {
            projects[id].status = (ProjectStatus)status;
        } else {
            printf("Invalid status!\n");
            return;
        }

        printf("Project updated successfully!\n");
    }
}

void deleteProject(Project* projects, int* totalProjects) {
    int id;
    printf("Enter the project ID to delete: ");
    scanf("%d", &id);

    if (id < 0 || id >= *totalProjects) {
        printf("Project not found!\n");
    } else {
        // Tornar o projeto inativo, mantendo os dados
        projects[id].status = PROJECT_COMPLETED;  // Tornar o projeto como concluído (inativo)

        printf("Project marked as completed (inactive).\n");
    }
}

void listProjects(Project* projects, int totalProjects) {
    for (int i = 0; i < totalProjects; i++) {
        printf("ID: %d, Name: %s, Status: %d\n", 
                projects[i].projectId, projects[i].name, projects[i].status);
    }
}

void reportProjects(Project* projects, int totalProjects) {
    int activeProjects = 0;
    int completedProjects = 0;
    int inProgressProjects = 0;
    int delayedProjects = 0;
    
    time_t now = time(NULL);
    struct tm *currentDate = localtime(&now);
    char today[11];
    strftime(today, 11, "%d/%m/%Y", currentDate);

    for (int i = 0; i < totalProjects; i++) {
        if (projects[i].status == PROJECT_PLANNED) {
            inProgressProjects++;
        } else if (projects[i].status == PROJECT_IN_PROGRESS) {
            activeProjects++;
        } else if (projects[i].status == PROJECT_COMPLETED) {
            completedProjects++;
        }
        
        if (strcmp(projects[i].endDate, today) < 0 && 
            projects[i].status != PROJECT_COMPLETED) {
            delayedProjects++;
        }
    }
    
    printf("\nProject Report:\n");
    printf("Active Projects: %d\n", activeProjects);
    printf("Completed Projects: %d\n", completedProjects);
    printf("In Progress Projects: %d\n", inProgressProjects);
    printf("Delayed Projects: %d\n", delayedProjects);
}
