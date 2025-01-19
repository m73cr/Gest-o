#include <stdio.h>
#include <stdlib.h>
#include "file_operations.h"
#include "projects.h"
#include "collaborators.h"
#include "materials.h"
#include "tasks.h"

// Função para carregar os dados dos arquivos para a memória
void loadData(Project** projects, int* projectCount, 
              Collaborator** collaborators, int* collaboratorCount, 
              Material** materials, int* materialCount, 
              Task** tasks, int* taskCount) {
    FILE *file;

    // Carregar projetos
    file = fopen("projects.dat", "rb");
    if (file != NULL) {
        fread(projectCount, sizeof(int), 1, file);
        *projects = malloc(sizeof(Project) * (*projectCount));
        fread(*projects, sizeof(Project), *projectCount, file);
        fclose(file);
    }

    // Carregar colaboradores
    file = fopen("collaborators.dat", "rb");
    if (file != NULL) {
        fread(collaboratorCount, sizeof(int), 1, file);
        *collaborators = malloc(sizeof(Collaborator) * (*collaboratorCount));
        fread(*collaborators, sizeof(Collaborator), *collaboratorCount, file);
        fclose(file);
    }

    // Carregar materiais
    file = fopen("materials.dat", "rb");
    if (file != NULL) {
        fread(materialCount, sizeof(int), 1, file);
        *materials = malloc(sizeof(Material) * (*materialCount));
        fread(*materials, sizeof(Material), *materialCount, file);
        fclose(file);
    }

    // Carregar tarefas
    file = fopen("tasks.dat", "rb");
    if (file != NULL) {
        fread(taskCount, sizeof(int), 1, file);
        *tasks = malloc(sizeof(Task) * (*taskCount));
        fread(*tasks, sizeof(Task), *taskCount, file);
        fclose(file);
    }
}

// Função para salvar os dados da memória para os arquivos
void saveData(Project* projects, int projectCount, 
              Collaborator* collaborators, int collaboratorCount, 
              Material* materials, int materialCount, 
              Task* tasks, int taskCount) {
    FILE *file;

    // Salvar projetos
    file = fopen("projects.dat", "wb");
    if (file != NULL) {
        fwrite(&projectCount, sizeof(int), 1, file);
        fwrite(projects, sizeof(Project), projectCount, file);
        fclose(file);
    }

    // Salvar colaboradores
    file = fopen("collaborators.dat", "wb");
    if (file != NULL) {
        fwrite(&collaboratorCount, sizeof(int), 1, file);
        fwrite(collaborators, sizeof(Collaborator), collaboratorCount, file);
        fclose(file);
    }

    // Salvar materiais
    file = fopen("materials.dat", "wb");
    if (file != NULL) {
        fwrite(&materialCount, sizeof(int), 1, file);
        fwrite(materials, sizeof(Material), materialCount, file);
        fclose(file);
    }

    // Salvar tarefas
    file = fopen("tasks.dat", "wb");
    if (file != NULL) {
        fwrite(&taskCount, sizeof(int), 1, file);
        fwrite(tasks, sizeof(Task), taskCount, file);
        fclose(file);
    }
}

