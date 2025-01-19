#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projects.h"
#include "tasks.h"

void createTask(Task** tasks, int* totalTasks, Project* projects, int totalProjects) {
    Task newTask;

    // Atribuição do ID da tarefa
    newTask.taskId = *totalTasks;
    (*totalTasks)++; // Incrementa o total de tarefas

    printf("Task Description: ");
    getchar(); // Limpar o buffer de entrada
    fgets(newTask.description, sizeof(newTask.description), stdin);
    newTask.description[strcspn(newTask.description, "\n")] = '\0'; // Remover o caractere de nova linha

    printf("Start Date (DD/MM/YYYY): ");
    fgets(newTask.startDate, sizeof(newTask.startDate), stdin);
    newTask.startDate[strcspn(newTask.startDate, "\n")] = '\0'; // Remover o caractere de nova linha

    printf("End Date (DD/MM/YYYY): ");
    fgets(newTask.endDate, sizeof(newTask.endDate), stdin);
    newTask.endDate[strcspn(newTask.endDate, "\n")] = '\0'; // Remover o caractere de nova linha

    printf("Select the Project ID for the task: ");
    int projectId;
    scanf("%d", &projectId);

    // Verificar se o ID do projeto é válido
    if (projectId < 0 || projectId >= totalProjects) {
        printf("Invalid project ID.\n");
        return;
    }
    newTask.projectId = projectId;

    printf("Enter the Collaborator ID responsible for the task: ");
    int collaboratorId;
    scanf("%d", &collaboratorId);
    newTask.collaboratorId = collaboratorId;

    newTask.status = TASK_PLANNED; // Definir o estado inicial como "Planeada"

    // Alocar memória dinamicamente para a tarefa e armazená-la
    *tasks = realloc(*tasks, sizeof(Task) * (*totalTasks));
    if (*tasks == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    (*tasks)[*totalTasks - 1] = newTask;

    printf(
        "Task \"%s\" (ID %d) created successfully for project ID %d and assigned to collaborator ID %d!\n",
        newTask.description, newTask.taskId, newTask.projectId, newTask.collaboratorId
    );
}

void readTask(Task* tasks, int totalTasks) {
    int id;
    printf("Enter the task ID to view: ");
    scanf("%d", &id);

    if (id < 0 || id >= totalTasks) {
        printf("Task not found!\n");
    } else {
        printf("ID: %d\n", tasks[id].taskId);
        printf("Description: %s\n", tasks[id].description);
        printf("Start Date: %s\n", tasks[id].startDate);
        printf("Deadline: %s\n", tasks[id].endDate);
        printf("Status: ");
        
        switch (tasks[id].status) {
            case TASK_PLANNED: 
                printf("Planned\n"); 
                break;
            case TASK_IN_PROGRESS: 
                printf("In Progress\n"); 
                break;
            case TASK_COMPLETED: 
                printf("Completed\n"); 
                break;
            default: 
                printf("Unknown Status\n");
        }

        printf("Project ID: %d\n", tasks[id].projectId);
        printf("Collaborator ID: %d\n", tasks[id].collaboratorId);
    }
}

void updateTask(Task* tasks, int totalTasks) {
    int id;
    printf("Enter the task ID to update: ");
    scanf("%d", &id);

    if (id < 0 || id >= totalTasks) {
        printf("Task not found!\n");
    } else {
        printf("Updating task \"%s\"...\n", tasks[id].description);

        // Atualizar descrição
        getchar();  // Limpar buffer de entrada
        printf("New Task Description: ");
        fgets(tasks[id].description, 200, stdin);
        tasks[id].description[strcspn(tasks[id].description, "\n")] = '\0';  // Remover nova linha

        // Atualizar data de início
        printf("New Start Date (DD/MM/YYYY): ");
        fgets(tasks[id].startDate, 11, stdin);
        tasks[id].startDate[strcspn(tasks[id].startDate, "\n")] = '\0';  // Remover nova linha

        // Atualizar prazo
        printf("New Deadline (DD/MM/YYYY): ");
        fgets(tasks[id].endDate, 11, stdin);
        tasks[id].endDate[strcspn(tasks[id].endDate, "\n")] = '\0';  // Remover nova linha

        // Atualizar estado
        printf("Select new status (0: Planned, 1: In Progress, 2: Completed): ");
        int status;
        scanf("%d", &status);
        if (status >= 0 && status <= 2) {
            tasks[id].status = (TaskStatus)status;
        } else {
            printf("Invalid status!\n");
            return;
        }

        // Atualizar ID do colaborador responsável
        printf("New Collaborator ID: ");
        scanf("%d", &tasks[id].collaboratorId);

        printf("Task updated successfully!\n");
    }
}

void deleteTask(Task** tasks, int* totalTasks) {
    if (*tasks == NULL || *totalTasks <= 0) {
        printf("No tasks available to delete.\n");
        return;
    }

    int id;
    printf("Enter the task ID to delete: ");
    scanf("%d", &id);

    if (id < 0 || id >= *totalTasks) {
        printf("Task not found!\n");
    } else {
        // Confirmação de exclusão
        printf("Are you sure you want to delete task \"%s\"? (y/n): ", (*tasks)[id].description);
        getchar(); // Limpar buffer de entrada
        char confirm = getchar();
        if (confirm != 'y' && confirm != 'Y') {
            printf("Task deletion canceled.\n");
            return;
        }

        // Shift tasks para remover a tarefa
        for (int i = id; i < *totalTasks - 1; i++) {
            (*tasks)[i] = (*tasks)[i + 1];
            (*tasks)[i].taskId = i; // Atualizar os IDs das tarefas
        }

        (*totalTasks)--;  // Diminuir o número total de tarefas

        // Realocar memória
        *tasks = realloc(*tasks, sizeof(Task) * (*totalTasks));
        if (*tasks == NULL && *totalTasks > 0) {
            printf("Memory reallocation failed after deletion!\n");
            return;
        }

        printf("Task deleted successfully!\n");
    }
}

void listTasks(Task* tasks, int totalTasks) {
    if (totalTasks == 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("Listing all tasks:\n");
    printf("---------------------------------------------------------------\n");
    printf("| ID  | Description          | Start Date | End Date   | Status      | Project ID | Collaborator ID |\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < totalTasks; i++) {
        printf("| %-3d | %-20s | %-10s | %-10s | %-11s | %-10d | %-15d |\n",
               tasks[i].taskId,
               tasks[i].description,
               tasks[i].startDate,
               tasks[i].endDate,
               (tasks[i].status == TASK_PLANNED) ? "Planned" :
               (tasks[i].status == TASK_IN_PROGRESS) ? "In Progress" : "Completed",
               tasks[i].projectId,
               tasks[i].collaboratorId);
    }
    printf("---------------------------------------------------------------\n");
}
