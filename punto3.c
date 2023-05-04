#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct Tarea{
    int tareaID; //Numerado en ciclo iterativo
    char *descripcion; //
    int duracion; // entre 10 – 100
} typedef Tarea;

struct nodo{
    Tarea T;
    struct nodo *siguiente;
}typedef Nodo;

Nodo *crearLista();
Nodo *crearNodo(Tarea *tarea);
Tarea *cargarTarea(int i);
void insertarInicio(Nodo **lista, Tarea *tarea);
void mostrarLista(Nodo **listaP, Nodo **listaR);
Nodo *quitarNodo(Nodo **lista, Nodo *nodo);
void insertarNodo(Nodo **lista, Nodo *nodo);
void mostrarTareas(Nodo *lista);

Nodo *buscarTareaPorID(Nodo *lista, int id);
Nodo *buscarTareaPorPalabra(Nodo *lista, char *palabra);
void mostrarTarea(Tarea tarea);
int main(){
    Nodo *ListaPen, *ListaReal, *nodo_tarea;
    Tarea *tarea;
    int aux, i=0;
    char *palabra = malloc(sizeof(char)*20);
    ListaPen = crearLista();
    ListaReal = crearLista();

    printf("\n Desea cargar tarea? 1-SI, 0-NO: ");
    scanf("%i", &aux);
    srand(time(NULL));
    while (aux != 0)
    {
        tarea = cargarTarea(i);
        insertarInicio(&ListaPen, tarea);
        printf("\n Desea cargar otra tarea? 1-SI, 0-NO: ");
        scanf("%i", &aux);
        i++; // contador de tareas
    }
    mostrarLista(&ListaPen, &ListaReal); //muestro pendientes y muevo
    printf("\n--- LISTA DE TAREAS PENDIENTES ---");
    mostrarTareas(ListaPen);
    printf("\n--- LISTA DE TAREAS REALIZADAS ---");
    mostrarTareas(ListaReal);

    printf("\n Ingresar ID de tarea a buscar: ");
    scanf("%i", &i);
    if (buscarTareaPorID(ListaPen, i) != NULL)
    {
        nodo_tarea = buscarTareaPorID(ListaPen, i);
        printf("\n Tarea encontrada: ");
        mostrarTarea(nodo_tarea->T);
    } else {
        printf("\n Tarea no encontrada. \n ");
    }
    printf("\n Ingresar palabra a buscar en una tarea: ");
    fflush(stdin);
    gets(palabra);
    if (buscarTareaPorPalabra(ListaPen, palabra) != NULL)
    {
        nodo_tarea = buscarTareaPorPalabra(ListaPen, palabra);
        printf("\n Tarea encontrada. \n ");
        mostrarTarea(nodo_tarea->T);
    } else {
        printf("\n Tarea no encontrada: ");
    }
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
Tarea *cargarTarea(int i){
    Tarea *tarea = malloc(sizeof(Tarea));
    tarea->descripcion = malloc(sizeof(char)*40);
    printf("\n Ingresar descripcion: ");
    fflush(stdin);
    gets(tarea->descripcion);
    tarea->duracion = rand()%91+10;
    tarea->tareaID = i+1;
    return tarea;
}
void insertarInicio(Nodo **lista, Tarea *tarea){
    Nodo *nodo;
    nodo = crearNodo(tarea);
    nodo->siguiente = *lista;
    *lista = nodo;
}
void mostrarTarea(Tarea tarea){
    printf("\n Tarea id: %i", tarea.tareaID);
    printf("\n Duracion: %i", tarea.duracion);
    printf("\n Descripcion: ");
    puts(tarea.descripcion);
}
void mostrarLista(Nodo **listaP, Nodo **listaR){
    Nodo *actual, *nodo;
    int aux;
    printf("\n --- LISTA ---");
    actual = *listaP;
    while (actual != NULL)
    {
        printf("\n Tarea id: %i", actual->T.tareaID);
        printf("\n Duracion: %i", actual->T.duracion);
        printf("\n Descripcion: ");
        puts(actual->T.descripcion);
        
        printf("\n Realizo la tarea? 1-SI, 0-NO: ");
        scanf("%i", &aux);
        if (aux == 1) //borro de pendientes e inserto en realizadas
        {
            nodo = actual;
            actual = actual->siguiente; // muevo el puntero antes de borrarlo
            nodo = quitarNodo(listaP, nodo);
            insertarNodo(listaR, nodo);
        } else {
            actual = actual->siguiente;
        }
    }
}
Nodo *quitarNodo(Nodo **lista, Nodo *nodo){
    Nodo *actual = *lista;
    Nodo *anterior = *lista;
    while (actual != NULL && (actual != nodo))
    {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual) //significa que no encontro el nodo o que es vacia
    {
        if (actual == *lista)
        {
            *lista = actual->siguiente;
        } else {
            anterior->siguiente = actual->siguiente;
        }
        actual->siguiente = NULL;
    }
    return actual;
}
void insertarNodo(Nodo **lista, Nodo *nodo){
    nodo->siguiente = *lista;
    *lista = nodo;
}
void mostrarTareas(Nodo *lista){
    Nodo *aux = lista;
    while (aux != NULL)
    {
        printf("\n Tarea id: %i", aux->T.tareaID);
        printf("\n Duracion: %i", aux->T.duracion);
        printf("\n Descripcion: ");
        puts(aux->T.descripcion);
        aux = aux->siguiente;
    }    
}
Nodo *buscarTareaPorID(Nodo *lista, int id){
    Nodo *aux = lista;
    while (aux != NULL && aux->T.tareaID != id)
    {
        aux = aux->siguiente;
    }
    if (aux)
    {
        return aux;
    }
    return NULL;
}
Nodo *buscarTareaPorPalabra(Nodo *lista, char *palabra){
    Nodo *aux = lista;
    while (aux != NULL && strstr(aux->T.descripcion, palabra) == NULL)
    {
        aux = aux->siguiente;
    }
    if (aux)
    {
        return (aux);
    }
    return NULL;
}