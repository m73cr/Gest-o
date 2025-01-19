#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projects.h"
#include "collaborators.h"
#include "materials.h"
#include "tasks.h"
#include "menus.h"
#include "file_operations.h"

int main(int argc, char** argv) {
    Project* projects = NULL;
    Collaborator* collaborators = NULL;
    Material* materials = NULL;
    Task* tasks = NULL;
    
    int projectCount = 0;
    int collaboratorCount = 0;
    int materialCount = 0;
    int taskCount = 0;

    // Carregar os dados dos arquivos
    loadData(&projects, &projectCount, 
             &collaborators, &collaboratorCount, 
             &materials, &materialCount, 
             &tasks, &taskCount);

    int option;

    do {
        showMainMenu();  // Exibe o menu principal
        scanf("%d", &option);

        switch(option) {
            case 1: {
                int subOption;
                do {
                    showProjectMenu();  // Exibe o menu de projetos
                    scanf("%d", &subOption);

                    switch(subOption) {
                        case 1:
                            createProject(&projects, &projectCount);
                            break;
                        case 2:
                            readProject(projects, projectCount);
                            break;
                        case 3:
                            updateProject(projects, projectCount);
                            break;
                        case 4:
                            deleteProject(projects, &projectCount);
                            break;
                        case 5:
                            break;
                        default:
                            printf("Invalid option! Try again.\n");
                    }
                } while (subOption != 5);
                break;
            }
            case 2: {
                int subOption;
                do {
                    showCollaboratorMenu();  // Exibe o menu de colaboradores
                    scanf("%d", &subOption);

                    switch(subOption) {
                        case 1:
                            createCollaborator(&collaborators, &collaboratorCount);
                            break;
                        case 2:
                            readCollaborator(collaborators, collaboratorCount);
                            break;
                        case 3:
                            updateCollaborator(collaborators, collaboratorCount);
                            break;
                        case 4:
                            deleteCollaborator(collaborators, &collaboratorCount);
                            break;
                        case 5:
                            break;
                        default:
                            printf("Invalid option! Try again.\n");
                    }
                } while (subOption != 5);
                break;
            }
            case 3: {
                int subOption;
                do {
                    showMaterialMenu();  // Exibe o menu de materiais
                    scanf("%d", &subOption);

                    switch(subOption) {
                        case 1:
                            createMaterial(&materials, &materialCount);
                            break;
                        case 2:
                            readMaterial(materials, materialCount);
                            break;
                        case 3:
                            updateMaterial(materials, materialCount);
                            break;
                        case 4:
                            deleteMaterial(materials, &materialCount);
                            break;
                        case 5:
                            break;
                        default:
                            printf("Invalid option! Try again.\n");
                    }
                } while (subOption != 5);
                break;
            }
            case 4: {
                int subOption;
                do {
                    showTaskMenu();  // Exibe o menu de tarefas
                    scanf("%d", &subOption);

                    switch(subOption) {
                        case 1:
                            createTask(&tasks, &taskCount, projects, projectCount);
                            break;
                        case 2:
                            readTask(tasks, taskCount);
                            break;
                        case 3:
                            updateTask(tasks, taskCount);
                            break;
                        case 4:
                            deleteTask(tasks, &taskCount);
                            break;
                        case 5:
                            break;
                        default:
                            printf("Invalid option! Try again.\n");
                    }
                } while (subOption != 5);
                break;
            }
            case 5: {  // Relatórios
                int subOption;
                do {
                    printf("\nReports Menu:\n");
                    printf("1. Project Report\n");
                    printf("2. Collaborator Report\n");
                    printf("3. Material Report\n");
                    printf("4. Back\n");
                    printf("Choose an option: ");
                    scanf("%d", &subOption);

                    switch(subOption) {
                        case 1:
                            reportProjects(projects, projectCount);
                            break;
                        case 2:
                            reportCollaborators(collaborators, collaboratorCount, tasks, taskCount);
                            break;
                        case 3:
                            reportMaterials(materials, materialCount, projects, projectCount);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid option! Try again.\n");
                    }
                } while (subOption != 4);
                break;
            }
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    } while (option != 6);

   

    // Liberar memória dinâmica
    free(projects);
    free(collaborators);
    free(materials);
    free(tasks);
    
    return (EXIT_SUCCESS);
}


