#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Tarea{
    int TareaId; //numerado en ciclo interatio
    char *Descripcion;
    int Duracion; //entre 10-100
} typedef Tarea;

int main(){
    int cantTareas, aux;
    Tarea ** tareasPendientes;
    Tarea **tareaRealizadas;

    printf("Ingrese el numeros de tareas: ");
    scanf("%d", &cantTareas);

    tareasPendientes = (Tarea **) malloc(cantTareas * sizeof(Tarea*));
    tareaRealizadas = (Tarea **) malloc(cantTareas * sizeof(Tarea*));
    for (int i = 0; i < cantTareas; i++)
    {
        tareaRealizadas[i] == NULL;
    }
    

    for (int i = 0; i < cantTareas; i++)
    {
        tareasPendientes[i] = NULL; //inicializamos puntero
        tareasPendientes[i] = (Tarea *) malloc(sizeof(Tarea)); 
    }
    srand(time(NULL));
    for ( int j = 0; j < cantTareas; j++)
    {
        tareasPendientes[j]->TareaId=j+1;
        tareasPendientes[j]->Duracion = rand()% 91 + 10;
        tareasPendientes[j]->Descripcion = (char *)malloc(sizeof(char)*100);
        printf("\nIngrese la descripcion de tarea %i: ", j+1);
        fflush(stdin);
        gets(tareasPendientes[j]->Descripcion);
    }
    int aux2 = 0;

    for (int j = 0; j < cantTareas; j++)
    {
        printf("\n----------------");
        printf("\nTareaId: %d", tareasPendientes[j]->TareaId);
        printf(" \nDuracion %i", tareasPendientes[j]->Duracion);
        printf("\nDescripcion: %s", tareasPendientes[j]->Descripcion);
        printf("\nRealizo la Tarea %d? Ingrese 1 si la hizo  ", j+1);
        scanf("%i", &aux);
        
        if (aux == 1)
        {
            tareaRealizadas[aux2] = tareasPendientes[j];
            tareasPendientes[j] = NULL;
            aux2++;
        }
        
    }

    printf("\nTareas Realizadas: \n");
    for (int i = 0; i < aux2; i++)
    {
        printf("\n--------Tarea Realizada [%d]--------", i+1);
        printf("\nTareaId: %d", tareaRealizadas[i]->TareaId);
        printf(" \nDuracion %i", tareaRealizadas[i]->Duracion);
        printf("\nDescripcion: %s", tareaRealizadas[i]->Descripcion);
    }
    printf("\nTareas Pendientes: \n");
    for (int j = 0; j < cantTareas; j++)
    {
        if (tareasPendientes[j]!=NULL)
        {
            printf("\n------Tarea Pendiente [%d]----------", j+1);
            printf("\nTareaId: %d", tareasPendientes[j]->TareaId);
            printf(" \nDuracion %i", tareasPendientes[j]->Duracion);
            printf("\nDescripcion: %s", tareasPendientes[j]->Descripcion); 
        }
        
        
    }
    
    
    return 0;
}