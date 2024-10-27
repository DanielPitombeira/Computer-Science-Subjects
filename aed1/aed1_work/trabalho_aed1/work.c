#include "work.h"
#define MAX 100000

usuario* cabeca = NULL; //cabeca da lista de usuários
musica* pilha = NULL; //pilha de musica

// ------------------------------------- CRIAÇÕES -----------------------------------------------------------------

musica* cria_musica(char nome_autor[], char nome_musica[]){
    /*Essa função cria uma célula da lista de músicas de um determinado usuário.
    Este usuário é aquele que foi passado como parâmetro na função novo_menu() na main
    */
    musica* music;

    music = (musica*)malloc(sizeof(musica));
    strcpy(music->nome_musica, nome_musica);
    strcpy(music->nome_autor, nome_autor);
    music->prox = NULL;

    return music;
}

void adiciona_musica(usuario* user, char nome_autor[], char nome_musica[]){
    usuario* temp = user; /*variável temporária recebe o usuário passado como parâmetro. As músicas serão adicionadas
    na lista de musicas desse usuário*/
    musica* music;

    music = cria_musica(nome_autor, nome_musica);

    /*if(temp->cabeca == NULL){ //temp->cabeca é a cabeca da lista de musicas
        temp->cabeca = music; //no caso em que a lista de musicas está vazia, temp->cabeca recebe a primeira cabeca
        return;
    }*/

    music->prox = temp->cabeca;
    temp->cabeca = music;
    /*
    linha 31 e 32 adicionam a música no início da lista de músicas do usuário
    */
}

usuario* cria_usuario(char nome[], char email[], char senha[]){
    /*
    Essa função cria uma célula da lista de usuários 
    */
    usuario* user;

    user = (usuario*)malloc(sizeof(usuario));
    strcpy(user->nome, nome);
    strcpy(user->email, email);
    strcpy(user->senha, senha);
    user->prox = NULL;
    user->cabeca = NULL;

    return user;
}

void adiciona_usuario(char nome[], char email[], char senha[]){
    usuario* user;

    user = cria_usuario(nome, email, senha); // recebe o usuário criado na função cria_usuario

    /*
    Adiciona o usuário no inicio da lista de usuários
    */
    user->prox = cabeca;
    cabeca = user;
}

// ---------------------------------------- BUSCAS ----------------------------------------------------------------

bool search(char email[], char senha[], usuario** aux){
    /*o usuário é passado com dois ponteiros em usuario** aux, para que as alterações feitas na função novo_menu 
    sejam refletidas(salvas) na main*/
    usuario* temp = cabeca;

    while(temp != NULL){
        if((strcmp(temp->email, email) == 0) && (strcmp(temp->senha, senha) == 0)){
            /*strcmp compara o temp->email(email de cada usuário) com o email do usuário passado como parâmetro,
            até achar o email do usuário procurado*, caso ele exista. O mesmo é feito com a senha*/

            *aux = temp; 
            /*
                se o email e a senha for encontrada, então a variável aux armazena o usuário
            */
            return true; //retorna true porque foi encontrado
        }

        temp = temp->prox;
    }

    return false; // se o programa chegou até esse ponto é porque o usuário não foi encontrado
}

// ------------------------------------- EXCLUSÕES ----------------------------------------------------------------

void excluir_tudo(){
    usuario* atual = cabeca;
    usuario* anterior = NULL;

    while(atual != NULL){
        musica* atual2 = atual->cabeca;
        musica* anterior2 = NULL;

        while(atual2 != NULL){
            anterior2 = atual2;
            free(anterior2);
            atual2 = atual2->prox;
        }   

        anterior = atual;
        free(anterior);
        atual = atual->prox;
    } 
}

void excluir_usuario(char email[], char senha[]){
    //nessa função deverá ser excluido todas as musicas desse usuário e depois a célula do usuário
    usuario* atual = cabeca;
    usuario* anterior = NULL;

    while(atual != NULL){
        if(!strcmp(atual->email, email) && !strcmp(atual->senha, senha)){
            musica* atual2 = atual->cabeca;
            musica* anterior2 = NULL;

            while(atual2 != NULL){
                anterior2 = atual2;
                free(anterior2);
                atual2 = atual2->prox;
            }   

            if(anterior == NULL){ // O nó a ser removido é o primeiro da lista
                cabeca = atual->prox;
            }else{ // O nó a ser removido está no meio ou no final da lista
                anterior->prox = atual->prox;
            }

            free(atual);
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }
    printf("Este usuario não está presente, ou, os dados fornecidos estão incorretos!\n");
}

void excluir_musica(usuario* user, char nome_autor[], char nome_musica[]){
    musica* atual = user->cabeca;
    musica* anterior = NULL;

    while(atual != NULL) {
        if(!strcmp(atual->nome_autor, nome_autor) && !strcmp(atual->nome_musica, nome_musica)) {
            if(anterior == NULL){ // O nó a ser removido é o primeiro da lista
                user->cabeca = atual->prox;
            }else{ // O nó a ser removido está no meio ou no final da lista
                anterior->prox = atual->prox;
            }

            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Esta musica não está presente na sua playlist!\n");
}

// ------------------------------ PRINTS --------------------------------------------------------------------------

void print_musica(usuario* user){
    musica *aux = user->cabeca;

    if(aux == NULL) printf("Você não possui musicas no momento!\n");
    else{
        while(aux != NULL){
                printf("Nome do autor: %s\n", aux->nome_autor);
                printf("Nome da musica: %s\n", aux->nome_musica);

                aux = aux->prox;
        }
    }
}

void print(){
    usuario* temp1 = cabeca;
    bool flag = false;

    while(temp1 != NULL){
        printf("\n");
        printf("-------------------------------------------------\n");
        printf("Nome: %s\n", temp1->nome);
        printf("Email: %s\n", temp1->email);
        printf("Senha: %s\n", temp1->senha);
        printf("\n");
        //imprimi a célula usuário

        musica* temp2 = temp1->cabeca;
        while(temp2 != NULL){
            printf("Nome da musica: %s\n", temp2->nome_musica);
            printf("Nome do autor: %s\n", temp2->nome_autor);
            //imprimi a célula música

            temp2 = temp2->prox;
        }
        printf("-------------------------------------------------\n");

        temp1 = temp1->prox;
    }
}

// ------------------------------------ TOCAR MUSICA --------------------------------------------------------------

int particao(musica v[], int inicio, int fim){
    int i, pIndex;
    musica swap;
    char pivo;

    pivo = v[fim].nome_musica[0];
    pIndex = inicio;

    for(i = inicio; i < fim; i++){
        if(v[i].nome_musica[0] <= pivo){
            swap = v[i];
            v[i] = v[pIndex];
            v[pIndex] = swap;
            pIndex++;
        }
    }
    swap = v[fim];
    v[fim] = v[pIndex];
    v[pIndex] = swap;

    return pIndex;
}

void QuickSort(musica* v, int inicio, int fim){
    int pIndex;
    if(inicio < fim){
        pIndex = particao(v, inicio, fim);

        QuickSort(v, inicio, pIndex - 1);
        QuickSort(v, pIndex + 1, fim);
    }
}

void Merge(musica *v1, int esquerda, musica *v2, int direita, musica *v, int n){
    int i, j, k;

    i = j = k = 0;

    while(i < esquerda && j < direita){
        if(v1[i].nome_musica[0] <= v2[j].nome_musica[0]){
            v[k] = v1[i];
            i++;
        }else{
            v[k] = v2[j];
            j++;
        }
        k++;
    }

    while(i < esquerda){
        v[k] = v1[i];
        i++;
        k++;
    }

    while(j < direita){
        v[k] = v2[j];
        j++;
        k++;
    }
}

void MergeSort(musica *v, int n){
    int meio, esquerda, direita;

    if(n < 2) 
        return;
    if(n % 2 == 0)
        meio = n / 2;
    else
        meio = (n + 1) / 2;
    esquerda = meio;
    direita = n - meio;

    musica v1[esquerda], v2[direita];
    int k = 0;

    for(int i = 0; i < esquerda; i++)
        v1[i] = v[k++];

    for(int i = 0; i < direita; i++)
        v2[i] = v[k++];

    MergeSort(v1, esquerda);
    MergeSort(v2, direita);
    Merge(v1, esquerda, v2, direita, v, n);
}

void BubbleSort(musica* v, int n){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(v[i].nome_musica[0] > v[j].nome_musica[0]){
                musica swap;

                swap = v[j];
                v[j] = v[i];
                v[i] = swap;
            }
        }
    }
}

void cria_pilha(usuario* user) {
    while (pilha != NULL) {
        pop();
    }
    
    musica* temp = user->cabeca;
    musica v[MAX];
    int i = 0;

    while (temp != NULL) {
        strcpy(v[i].nome_musica,temp->nome_musica);
        strcpy(v[i].nome_autor, temp->nome_autor);
        i++;

        temp = temp->prox;
    }

    QuickSort(v, 0, i - 1);
    //MergeSort(v, i);
    //BubbleSort(v, i);

    for (int j = i-1; j >= 0; j--) {
        push(v[j].nome_autor, v[j].nome_musica);
    }
}

void push(char nome_autor[], char nome_musica[]){
    musica* music;

    music = cria_musica(nome_autor, nome_musica);

    music->prox = pilha;
    pilha = music;
}

void top(){
    if(pilha == NULL){
        printf("Fim da playlist\n");
        return;
    }

    printf("Musica: %s\n", pilha->nome_musica);
    printf("Autor: %s\n", pilha->nome_autor);
}

void pop(){
    if(pilha == NULL){
        return;
    }
    musica* temp = pilha;
    pilha = pilha->prox;

    free(temp);
}

// bool isEmpty(usuario* user, int n){
//     if(n == 1){
//         if(cabeca == NULL) return true;
//         else return false;
//     }else if(n == 2){
//         if(cabeca->cabeca == NULL) return true;
//         else return false;
//     }
// }
