#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materials.h"

// Função para criar um novo material
void createMaterial(Material** materials, int* totalMaterials) {
    Material newMaterial;
    printf("Enter Material ID: ");
    scanf("%d", &newMaterial.materialId);
    getchar();  // Limpar o buffer do teclado
    printf("Enter Material Name: ");
    fgets(newMaterial.name, 100, stdin);
    newMaterial.name[strcspn(newMaterial.name, "\n")] = '\0';  // Remover a nova linha
    printf("Enter Material Category: ");
    fgets(newMaterial.category, 50, stdin);
    newMaterial.category[strcspn(newMaterial.category, "\n")] = '\0';  // Remover a nova linha
    printf("Enter Material Quantity: ");
    scanf("%d", &newMaterial.quantity);
    printf("Enter Material Unit Price: ");
    scanf("%f", &newMaterial.unitPrice);

    // Adicionar o novo material ao array
    (*materials) = realloc(*materials, sizeof(Material) * (*totalMaterials + 1));
    (*materials)[*totalMaterials] = newMaterial;
    (*totalMaterials)++;
    printf("Material added successfully!\n");
}

// Função para ler os materiais
void readMaterial(Material* materials, int totalMaterials) {
    if (totalMaterials == 0) {
        printf("No materials available.\n");
        return;
    }

    for (int i = 0; i < totalMaterials; i++) {
        printf("\nMaterial ID: %d\n", materials[i].materialId);
        printf("Name: %s\n", materials[i].name);
        printf("Category: %s\n", materials[i].category);
        printf("Quantity: %d\n", materials[i].quantity);
        printf("Unit Price: %.2f\n", materials[i].unitPrice);
    }
}

// Função para atualizar um material
void updateMaterial(Material* materials, int totalMaterials) {
    int id, found = 0;
    printf("Enter Material ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < totalMaterials; i++) {
        if (materials[i].materialId == id) {
            found = 1;
            getchar();  // Limpar o buffer do teclado
            printf("Enter new name: ");
            fgets(materials[i].name, 100, stdin);
            materials[i].name[strcspn(materials[i].name, "\n")] = '\0';
            printf("Enter new category: ");
            fgets(materials[i].category, 50, stdin);
            materials[i].category[strcspn(materials[i].category, "\n")] = '\0';
            printf("Enter new quantity: ");
            scanf("%d", &materials[i].quantity);
            printf("Enter new unit price: ");
            scanf("%f", &materials[i].unitPrice);
            printf("Material updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Material not found.\n");
    }
}

// Função para excluir um material
void deleteMaterial(Material* materials, int* totalMaterials) {
    int id, found = 0;
    printf("Enter Material ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *totalMaterials; i++) {
        if (materials[i].materialId == id) {
            found = 1;
            for (int j = i; j < *totalMaterials - 1; j++) {
                materials[j] = materials[j + 1];
            }
            (*totalMaterials)--;
            materials = realloc(materials, sizeof(Material) * (*totalMaterials));
            printf("Material deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Material not found.\n");
    }
}

// Função para listar todos os materiais
void listMaterials(Material* materials, int totalMaterials) {
    if (totalMaterials == 0) {
        printf("No materials available.\n");
        return;
    }

    printf("\nList of Materials:\n");
    for (int i = 0; i < totalMaterials; i++) {
        printf("ID: %d, Name: %s, Category: %s, Quantity: %d, Unit Price: %.2f\n",
               materials[i].materialId, materials[i].name, materials[i].category,
               materials[i].quantity, materials[i].unitPrice);
    }
}

// Função de relatório de materiais
void reportMaterials(Material* materials, int totalMaterials, Project* projects, int totalProjects) {
    if (totalMaterials == 0) {
        printf("No materials to report.\n");
        return;
    }

    printf("\nMaterial Report:\n");

    int totalQuantity = 0;
    for (int i = 0; i < totalMaterials; i++) {
        totalQuantity += materials[i].quantity;
    }

    printf("Total Materials in Stock: %d\n", totalQuantity);

    // Relatório de materiais por categoria
    printf("\nMaterials by Category:\n");
    for (int i = 0; i < totalMaterials; i++) {
        printf("Category: %s, Name: %s, Quantity: %d\n", materials[i].category,
               materials[i].name, materials[i].quantity);
    }

    // Análise de consumo de materiais por projeto
    printf("\nMaterial Consumption by Project:\n");
    for (int i = 0; i < totalProjects; i++) {
        printf("Project: %s\n", projects[i].name);
        for (int j = 0; j < totalMaterials; j++) {
            printf("Material: %s, Quantity Used: %d\n", materials[j].name, materials[j].quantity);
        }
        printf("\n");
    }
}