#ifndef PROJECTS_H
#define PROJECTS_H

struct Task;

// Definição do tipo enumerado para o estado do projeto
typedef enum {
    PROJECT_PLANNED,
    PROJECT_IN_PROGRESS,
    PROJECT_COMPLETED
} ProjectStatus;

typedef struct {
    int projectId;               // Project ID
    char name[100];              // Project name
    char location[100];          // Project location
    char startDate[11];          // Start date (DD/MM/YYYY)
    char endDate[11];            // End date (DD/MM/YYYY)
    ProjectStatus status; 
    int taskCount;  // Número de tarefas associadas
    struct Task* tasks; // Project status
} Project;

// Funções para operações CRUD nos projetos
void createProject(Project** projects, int* totalProjects);
void readProject(Project* projects, int totalProjects);
void updateProject(Project* projects, int totalProjects);
void deleteProject(Project* projects, int* totalProjects);
void listProjects(Project* projects, int totalProjects);
void reportProjects(Project* projects, int totalProjects);

#endif


