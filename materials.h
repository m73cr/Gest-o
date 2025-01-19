#ifndef MATERIALS_H
#define MATERIALS_H

#include "projects.h"

// Estrutura de um material
typedef struct {
    int materialId;
    char name[100];
    char category[50]; // Exemplo: Estrutural, Acabamento, etc.
    int quantity;
    float unitPrice;
} Material;

// Funções CRUD para materiais
void createMaterial(Material** materials, int* totalMaterials);
void readMaterial(Material* materials, int totalMaterials);
void updateMaterial(Material* materials, int totalMaterials);
void deleteMaterial(Material* materials, int* totalMaterials);
void listMaterials(Material* materials, int totalMaterials);

// Relatório de materiais
void reportMaterials(Material* materials, int totalMaterials, Project* projects, int totalProjects);

#endif


