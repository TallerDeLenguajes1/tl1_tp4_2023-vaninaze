#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Tarea{
    int TareaId; //numerado en ciclo interatio
    char *Descripcion;
    int Duracion; //entre 10-100
} typedef Tarea;

void mostrarUnaTarea(Tarea *tarea);
void mostrarTareas(Tarea *tareas, int cant);
Tarea *buscarTareaPorId(Tarea** TareasP, int cant, int id);
Tarea *buscarTareaPorPalabra(Tarea **TareaP, int cant, char *palabra);

int main(){
    int cantTareas, aux, id;
    char *palabra = malloc(sizeof(char)*20);

    Tarea ** tareasPendientes; //arreglo dinamico de tareas pendientes
    Tarea **tareaRealizadas; //arreglo dinamico de tareas realizadas
    
    Tarea *tarea;
    tarea = (Tarea *)malloc(sizeof(Tarea));
    tarea->Descripcion = (char *)malloc(sizeof(char)*100);

    printf("Ingrese el numeros de tareas: ");
    scanf("%d", &cantTareas);

    //inicializo arreglo dinamico
    tareasPendientes = (Tarea **) malloc(cantTareas * sizeof(Tarea*));
    tareaRealizadas = (Tarea **) malloc(cantTareas * sizeof(Tarea*));

    for (int i = 0; i < cantTareas; i++)
    {
        tareaRealizadas[i] == NULL;
        tareasPendientes[i] = NULL; //inicializamos puntero

        tareasPendientes[i] = (Tarea *) malloc(sizeof(Tarea)); 
    }
    srand(time(NULL));
    //carga de tareas pendientes
    for ( int i = 0; i < cantTareas; i++)
    {
        tareasPendientes[i]->TareaId= i+1;
        tareasPendientes[i]->Duracion = rand()% 91 + 10;
        tareasPendientes[i]->Descripcion = (char *)malloc(sizeof(char)*100);
        printf("\nIngrese la descripcion de tarea %i: ", i+1);
        fflush(stdin);
        gets(tareasPendientes[i]->Descripcion);
    }

    int aux2 = 0; //indice del arreglo de tareasRealizadas
    for (int i = 0; i < cantTareas; i++)
    {
        mostrarUnaTarea(tareasPendientes[i]);
        printf("\nRealizo la Tarea %d? 1-SI, 0-NO: ", i+1);
        scanf("%i", &aux);
        
        if (aux == 1)
        {
            tareaRealizadas[aux2] = tareasPendientes[i];
            tareasPendientes[i] = NULL;
            aux2++; //muevo el indice de tareasRealizadas
        }
    }

    printf("\n Tareas Realizadas: \n");
    mostrarTareas(tareaRealizadas, aux2);
    printf("\n Tareas Pendientes: \n");
    mostrarTareas(tareaRealizadas, cantTareas);

    return 0;

}

void mostrarTarea(Tarea *tarea){
    printf("\n----------------");
    printf("\nTareaId: %d", tarea->TareaId);
    printf(" \nDuracion %i", tarea->Duracion);
    printf("\nDescripcion: %s", tarea->Descripcion);
}
void mostrarTareas(Tarea *tareas, int cant){
    for (int i = 0; i < cant; i++)
    {
        if (tareas[i] != NULL){
            printf("\n--------Tarea Realizada [%d]--------", i+1);
            printf("\nTareaId: %d", tareas[i].TareaId);
            printf(" \nDuracion %i", tareas[i].Duracion);
            printf("\nDescripcion: %s", tareas[i].Descripcion);
        }
    }
}