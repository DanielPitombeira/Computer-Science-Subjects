#include "work.h"

int opcao;
char email[30], nome[30], senha[30];
char nome_musica[30], nome_autor[30];
usuario* user; //serve para salvar o usuário na função search()

void novo_menu(usuario* user);
void escutar_musica(usuario* user);

int main(){
    bool flag = false; //flag para encerrar o código

    while(1){
        printf("\n1- Cadastrar conta.\n");
        printf("2- Login.\n");
        printf("3- Apagar conta.\n");
        printf("4- Mostrar todos o usuarios e suas musicas.\n");
        printf("5- Sair.\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        printf("\n");
        switch(opcao){
            case 1:
                /*essa opção é declarado o nome, email e a senha do usuario 
                  que será cadastrado
                */
                printf("Nome de usuario: \n");
                scanf("%*c%[^\n]", nome);
                printf("Email: \n");
                scanf("%*c%s", email);
                printf("Senha: \n");
                scanf("%*c%[^\n]", senha);
                adiciona_usuario(nome, email, senha); //função que adiciona o usuário
                break;
            case 2:
                /*na opção do login, o usuário deverá entrar com seus dados para acessar sua conta.
                Se os dados estiverem corretos ele entra, caso contrário é impresso usuário ou senha
                inválida.
                */
                printf("Email: \n");
                scanf("%*c%s", email);
                printf("Senha: \n");
                scanf("%*c%[^\n]", senha);
                if(search(email, senha, &user)){  
                    /*A função search, do tipo booleana, procura na lista de usuários os dados fornecidos e retorna
                    true se o usuário foi encontrada e false se ele não foi achado.

                    Nessa função é passado &user como parâmetro para salvar o usuário que foi encontrado e assim 
                    logá-lo para fazer as seguintes operações na função novo_menu():

                    1- Adicionar musica:
                    2- Escutar musicas:
                    3- Excluir musica:
                    */         
                    novo_menu(user);
                }else{
                    printf("Senha ou usuario invalido\n"); //caso o usuário não esteja na lista de usuários
                }
                break;
            case 3:
                // o caso 3 ainda não foi feito.Nele o usuário deverá ser procurado na lista de usuário para apagá-lo.
                printf("Email: \n");
                scanf("%*c%s", email);
                printf("Senha: \n");
                scanf("%*c%[^\n]", senha);
                excluir_usuario(email, senha);
                break;
            case 4:
                print(); // imprimi a lista de usuários com as musicas de cada um
                break;
            case 5:
                //caso 4 é para encerrar o código
                flag = true;
                break;
            default:
            printf("Selecione um opção válida\n");
        }
        if(flag) break;
    }

    excluir_tudo();
    return 0;
}

void novo_menu(usuario* user){
    bool flag = false;
    int opcao;

    while(1){
        printf("\n1- Adicionar musica: \n");
        printf("2- Escutar musicas: \n");
        printf("3- Excluir musica: \n");
        printf("4- Mostrar musicas: \n");
        printf("5- Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Nome do autor: \n");
                scanf("%*c%[^\n]", nome_autor);
                printf("Nome da musica: \n");
                scanf("%*c%[^\n]", nome_musica);
                adiciona_musica(user, nome_autor, nome_musica);
                break;
            case 2:
                /*na função de escutar músicas, as músicas do usuário user deverão ser copiadas para uma pilha
                para rodar musica por musica*/
                escutar_musica(user);
                break;
            case 3:
                printf("Nome do autor: \n");
                scanf("%*c%[^\n]", nome_autor);
                printf("Nome da musica: \n");
                scanf("%*c%[^\n]", nome_musica);
                excluir_musica(user, nome_autor, nome_musica);
                break;
            case 4:
                print_musica(user);
                break;
            case 5:
                flag = true;
                break;
            default:
            printf("Selecione uma opção válida\n");
        }
        if(flag)
            break; //volta para a main
    }
}

void escutar_musica(usuario* user){
    cria_pilha(user);
    int op;
    bool flag = false;

    while(1){
        printf("\n1- Tocar musica\n");
        printf("2- Proxima musica\n");
        printf("3- Parar de tocar musicas\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        printf("\n");
        switch(op){
            case 1:
                top();
                pop();
                break;
            case 2:
                top();
                break;
            case 3:
                flag = true;
                break;
            default:
            printf("Selecione uma opção válida\n");
        }

        if(flag)
            break;

        printf("\n");
    }
}
