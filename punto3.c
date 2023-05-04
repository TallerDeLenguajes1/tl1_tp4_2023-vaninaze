#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Tarea{
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;
struct nodo{
    Tarea T;
    struct nodo *siguiente;
} typedef Nodo;

Nodo *crearLista();
Nodo *crearNodo(Tarea *tarea);
Tarea *cargarTarea(int indice);
void insertarNodo(Nodo **lista, Tarea *tarea);
void mostrarLista(Nodo *lista);
void eliminarTarea(Nodo **lista, int id); //elimina un nodo
void mostrarDatos(Nodo *lista);
int longLista(Nodo *lista);

int main(){
    Nodo *ListaPen, *ListaReal, *ListaTareasEnProceso, *nodo;
    Tarea *tarea = malloc(sizeof(Tarea));
    tarea->Descripcion = malloc(sizeof(char)*50);
    int aux, i=0;
    ListaPen = crearLista();
    ListaReal = crearLista();
    ListaTareasEnProceso = crearLista();
    srand(time(NULL));

    printf("\n Desea cargar una tarea? 1-SI, 0-NO: ");
    scanf("%i", &aux);
    while (aux != 0)
    {
        tarea = cargarTarea(i);
        insertarNodo(&ListaPen, tarea);

        i++;
        printf("\n Desea cargar una tarea? 1-SI, 0-NO: ");
        scanf("%i", &aux);
    }
    mostrarLista(ListaPen);

    return 0;
}
Nodo *crearLista(){
    return NULL;
}
Nodo *crearNodo(Tarea *tarea){
    Nodo *nodo;
    nodo = malloc(sizeof(Nodo));
    nodo->T = *tarea;
    nodo->siguiente = NULL;
    return nodo;
}
Tarea *cargarTarea(int indice){
    Tarea *tarea;
    tarea = (Tarea *)malloc(sizeof(Tarea));
    tarea->Descripcion = (char *)malloc(sizeof(char)*100);
    printf("\n Ingresar descripcion: ");
    fflush(stdin);
    gets(tarea->Descripcion);
    tarea->TareaID = indice+1;
    tarea->Duracion = rand()%91+10;
    return tarea;
}
void insertarNodo(Nodo **lista, Tarea *tarea){
    Nodo *nodo;
    nodo = crearNodo(tarea);
    nodo->siguiente = *lista;
    *lista = nodo;
}
void eliminarTarea(Nodo **lista, int id){ //elimina el nodo
    Nodo *actual = *lista;
    Nodo *anterior = *lista;
    while (actual != NULL && actual->T.TareaID != id)
    {
        anterior = actual;
        actual = actual->siguiente;
    }
    if(actual){
        anterior->siguiente = actual->siguiente;
        free(actual);
    }
}
void mostrarLista(Nodo *lista){
    Nodo *aux = lista;
    int i=0, cant;
    cant = longLista(lista);
    while (aux != NULL && i<cant)
    {
        printf("\n Tarea ID: %i", aux->T.TareaID);
        printf("\n Duracion: %i", aux->T.Duracion);
        printf("\n Descripcion: ");
        puts(aux->T.Descripcion);
        aux = aux->siguiente;
    }    
}
void mostrarDatos(Nodo *lista){
    Nodo *aux = lista;
    int cant, i=0;
    float tiempo=0;
    cant = longLista(lista);
    if (cant != 0)
    {
        while (aux != NULL && i<cant)
        {
            tiempo = tiempo + aux->T.Duracion;
            aux = aux->siguiente;
        }
        printf("\n Cantidad de tareas: %i", cant);
        printf("\n Tiempo asociado: %.2f", tiempo);
    } else {
        printf("\n La lista esta vacia");
    }
}
int longLista(Nodo *lista){
    Nodo *aux = lista;
    int cant=0;
    while (aux != NULL)
    {
        cant++;
        aux = aux->siguiente;
    }
    return cant;
}