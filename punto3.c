struct Tarea{
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;
struct Nodo{
    Tarea T;
    Nodo *Siguiente;
}typedef Nodo;