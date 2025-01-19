#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "projects.h"
#include "collaborators.h"
#include "materials.h"
#include "tasks.h"

// Funções para ler e escrever dados
void loadData(Project** projects, int* projectCount, 
              Collaborator** collaborators, int* collaboratorCount, 
              Material** materials, int* materialCount, 
              Task** tasks, int* taskCount);

void saveData(Project* projects, int projectCount, 
              Collaborator* collaborators, int collaboratorCount, 
              Material* materials, int materialCount, 
              Task* tasks, int taskCount);

#endif


