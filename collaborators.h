#ifndef COLLABORATORS_H
#define COLLABORATORS_H

#include "tasks.h"

// Estrutura de um colaborador
typedef struct {
    int collaboratorId;
    char name[100];
    char role[50];
    char phone[15];
    char email[100];
    char hireDate[11]; // Formato DD/MM/YYYY
} Collaborator;

// Funções CRUD para colaboradores
void createCollaborator(Collaborator** collaborators, int* totalCollaborators);
void readCollaborator(Collaborator* collaborators, int totalCollaborators);
void updateCollaborator(Collaborator* collaborators, int totalCollaborators);
void deleteCollaborator(Collaborator* collaborators, int* totalCollaborators);
void listCollaborators(Collaborator* collaborators, int totalCollaborators);

// Relatório de colaboradores
void reportCollaborators(Collaborator* collaborators, int totalCollaborators, Task* tasks, int totalTasks);

#endif

