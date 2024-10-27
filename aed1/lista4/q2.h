#define MAX 1000

struct node{
    int data[MAX];
    int lenght;
};

typedef struct node node;

void insere(node *list, int valor);
void remove_elements(node *list, int n);
void print(node *list);