typedef struct{
    int sizeArray;
    void* punteroArray;
}arrayList;

typedef struct{
    char nombre[50];
    char apellido[50];
    int id;
    int isEmpty;
}Employee;

int newEmployeeArray(arrayList* list);
int initArray(arrayList* list);
int buscarLibre(arrayList* list);
int pedirDatos(int* id, char* nombre,char* apellido);
int addEmployee(arrayList* list);
int printEmployee(arrayList * list);
