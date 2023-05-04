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
void insertarNodoInicio(Nodo **lista, Nodo *nodo);
void mostrarLista(Nodo *lista);
Nodo *quitarNodo(Nodo **lista, int id);
void eliminarTarea(Nodo **lista, Nodo *nodo); //elimina un nodo
void mostrarDatos(Nodo *lista);
int longLista(Nodo *lista);

int main(){
    Nodo *ListaPen, *ListaReal, *ListaTareasEnProceso, *nodo;
    Tarea *tarea = malloc(sizeof(Tarea));
    tarea->Descripcion = malloc(sizeof(char)*50);
    
    int aux, i=0, modifica, id, opcion, mover;

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
    printf("\n Desea modificar alguna tarea? 1-SI, 0-NO: ");
    scanf("%i", &modifica);
    while (modifica != 0)
    {
        printf("\n --LISTA TAREAS PENDIENTES--");
        mostrarLista(ListaPen);
        printf("\n --LISTA TAREAS REALIZADAS--");
        mostrarLista(ListaReal);
        printf("\n --LISTA TAREAS EN PROCESO--");
        mostrarLista(ListaTareasEnProceso);
        
        printf("\n En cual lista desea realizar cambios? 1-Pend, 2-Real, 3-En Proc: ");
        scanf("%i", &aux);
        printf("\n Ingresar ID de la tarea: ");
        scanf("%i", &id);
        printf("\n Desea: 1-Mover tarea, 2-Eliminar tarea de la lista, 3-No hacer nada:  ");
        scanf("%i", &opcion);
        if (opcion == 1)
        {   
            switch (aux) //segun la lista elijo la otra
            {
                case 1:
                    printf("\n A que lista desea mover? 2-Real, 3-En Proc: ");
                    scanf("%i", &mover);
                    break;
                case 2:
                    printf("\n A que lista desea mover? 1-Pend, 3-En Proc: ");
                    scanf("%i", &mover);
                    break;
                case 3:
                    printf("\n A que lista desea mover? 1-Pend, 2-Real: ");
                    scanf("%i", &mover);
                    break;
                default:
                    break;
            }
        }
    
        switch (aux) //en que lista quiere realizar cambios
        {
            case 1: //lista de pendientes
                nodo = quitarNodo(&ListaPen, id);
                if (opcion == 1) //muevo tarea
                {
                    if (mover = 2) //mover a realizadas
                    {
                        insertarNodoInicio(&ListaReal, nodo);
                    }else if(mover = 3){ //mover a en proceso
                        insertarNodoInicio(&ListaTareasEnProceso, nodo);
                    }
                } else if(opcion == 2){ //elimino tarea
                    eliminarTarea(&ListaPen, nodo);
                }
                break;
            case 2: //lista de realizadas
                nodo = quitarNodo(&ListaReal, id);/* code */
                if (opcion == 1) //muevo tarea
                {
                    if (mover = 1) //mover a pendientes
                    {
                        insertarNodoInicio(&ListaPen, nodo);
                    }else if(mover = 3){ //mover a en proceso
                        insertarNodoInicio(&ListaTareasEnProceso, nodo);
                    }
                } else if(opcion == 2){ //elimino tarea
                    eliminarTarea(&ListaReal, nodo);
                }
                break;
            case 3: //lista de tareas en proceso
                nodo = quitarNodo(&ListaTareasEnProceso, id);
                if (opcion == 1) //muevo tarea
                {
                    if (mover = 1) //mover a pendientes
                    {
                        insertarNodoInicio(&ListaPen, nodo);
                    }else if(mover = 2){ //mover a realizadas
                        insertarNodoInicio(&ListaReal, nodo);
                    }
                } else if(opcion == 2){ //elimino tarea
                    eliminarTarea(&ListaTareasEnProceso, nodo);
                }
                break;
            default:
                break;
        }
        printf("\n Desea modificar alguna tarea? 1-SI, 0-NO: ");
        scanf("%i", &modifica);
    }
    printf("\n ---LISTA TAREAS PENDIENTES---");
    mostrarLista(ListaPen);
    printf("\n --DATOS DE LISTA TAREAS PENDIENTES--");
    mostrarDatos(ListaPen);
    printf("\n ---LISTA TAREAS REALIZADAS---");
    mostrarLista(ListaReal);
    printf("\n --DATOS DE LISTA TAREAS REALIZADAS--");
    mostrarDatos(ListaReal);
    printf("\n ---LISTA TAREAS EN PROCESO---");
    mostrarLista(ListaTareasEnProceso);
    printf("\n --DATOS DE LISTA TAREAS EN PROCESO--");
    mostrarDatos(ListaTareasEnProceso);
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
void insertarNodoInicio(Nodo **lista, Nodo *nodo){
    nodo->siguiente = *lista;
    *lista = nodo;
}
Nodo *quitarNodo(Nodo **lista, int id){
    Nodo *actual = *lista;
    Nodo *anterior = *lista;
    while (actual != NULL && actual->T.TareaID != id)
    {
        anterior = actual;
        actual = actual->siguiente;
    }
    if(actual){ //encontre el nodo, debo desconectarlo
        if (actual == *lista) //la lista tiene un solo elem
        {
            *lista = actual->siguiente;
        } else {
            anterior->siguiente = actual->siguiente;
        }
        actual->siguiente = NULL;
    }
    return actual;
}
void eliminarTarea(Nodo **lista, Nodo *nodo){ //elimina el nodo
    Nodo *actual = *lista;
    Nodo *anterior = *lista;
    while (actual != NULL && actual != nodo)
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
    if (aux == NULL)
    {
        printf("\n La lista esta vacia");
    } else {
        while (aux != NULL && i<cant)
        {
            printf("\n Tarea ID: %i", aux->T.TareaID);
            printf("\n Duracion: %i", aux->T.Duracion);
            printf("\n Descripcion: ");
            puts(aux->T.Descripcion);
            aux = aux->siguiente;
        }  
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