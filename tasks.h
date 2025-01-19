#ifndef TASKS_H
#define TASKS_H

#include "projects.h"

// Definição de um tipo enumerado para o estado das tarefas
typedef enum {
    TASK_PLANNED,
    TASK_IN_PROGRESS,
    TASK_COMPLETED
} TaskStatus;

typedef struct {
    int taskId;
    char description[100];
    char startDate[11]; // Formato DD/MM/YYYY
    char endDate[11];   // Formato DD/MM/YYYY
    int status; // Tarefa: Planeada, Em progresso, Concluída
    int collaboratorId; // ID do colaborador responsável
    int projectId;
} Task;

// Funções para operações CRUD nas tarefas
void createTask(Task** tasks, int* totalTasks, Project* projects, int totalProjects);
void readTask(Task* tasks, int totalTasks);
void updateTask(Task* tasks, int totalTasks);
void deleteTask(Task** tasks, int* totalTasks);
void listTasks(Task* tasks, int totalTasks);

#endif

