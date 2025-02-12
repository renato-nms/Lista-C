#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* proximo;
} No;


typedef struct lista{
    No* inicio;
    No* fim;
    int tam;
} Lista;

void cria_lista(Lista *lista);

void cria_lista(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void inserir_inicio(Lista *lista,int num);

void inserir_inicio(Lista *lista,int num){
    No* novo = (No*)malloc(sizeof(No));

    if(novo == NULL){
    printf("Erro ao alocar");
      }

  novo->valor = num;
  novo->proximo = lista->inicio; //O novo no aponta para o antigo inicio
  lista->inicio = novo; // Atualiza o inicio
  lista->tam++;

      //Caso a lista senja nula tanto o fim quannto o proximo serão nulos
    if(lista->fim == NULL){
        lista->fim = novo;
        lista->inicio = novo;
    }

}



void inserir_meio(Lista *lista,int num,int ant);

void inserir_meio(Lista *lista,int num,int ant){
    No *aux = lista->inicio,*novo = (No*)malloc(sizeof(No));


    novo->valor = num;

    while(aux->proximo != NULL && aux->proximo != ant){
        aux = aux->proximo;
    }

    if(novo){
    
        if(aux != NULL)
         novo->proximo = aux->proximo;
          aux->proximo = novo;
        
    } else {
    free(novo);
    }
}
    


void inserir_fim(Lista *lista, int num);

void inserir_fim(Lista *lista, int num){
    No *novo = (No*)malloc(sizeof(No));

    if(novo == NULL){
        printf("erro ao alocar memoria");
        return;
    }

    novo->valor = num;
    novo->proximo = NULL;

    if(lista->tam == 0){ //Lista esta vazia
    lista->inicio = lista->fim=novo;
    } else{
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tam++;
}

void ordenado(Lista *lista, int num){
    No **aux = &lista->inicio, *novo = (No*)malloc(sizeof(No));

    if(novo == NULL){
        printf("Erro ao alocar");
        return;
    }
    novo->valor = num;

        while(*aux!= NULL && (*aux)->valor < num)
        aux = &(*aux)->proximo;
        novo->proximo = *aux;
        *aux = novo;
        lista->tam++;
    } 

    


void imprimir(Lista* lista);

void imprimir(Lista* lista){
    No *no = lista->inicio;
    while(no!=NULL){
        printf("%d ",lista->tam);
        printf("%d ->",no->valor);
        no = no->proximo;
        

    }
    printf("\n\n");

}



int main(void){

int valor,opcao,referencia;
Lista lista;
cria_lista(&lista);
imprimir(&lista);

imprimir(&lista);

printf("-------ESCOLHA UMA OPCAO-------\n\n");

do{
printf("0: sair || 1: inserir no inicio || 2: inserir no meio || 3:inserir no fim || 4: Ordenar || 5: imprimir");
scanf("%d",&opcao);

switch(opcao){

    case 0:
    printf("Saindo...");
    break;

    case 1:
    printf("Digite um valor ");
    scanf("%d",&valor);
    inserir_inicio(&lista,valor);
    break;

    case 2:
    printf("Digite um valor ");
    scanf("%d",&valor);
    printf("Digite a referencia ");
    scanf("%d",&referencia);
    inserir_meio(&lista,valor,referencia);
    break;

    case 3:
    printf("Digite um valor ");
    scanf("%d",&valor);
    inserir_fim(&lista,valor);
    break;

    case 4:
    printf("Digite um valor ");
    scanf("%d",&valor);
    ordenado(&lista,valor);
    break;

    case 5:
    imprimir(&lista);
    break;


    default:
    printf("Opcao invalida\n");
    
    break;
}
} while(opcao != 0);
    return 0;
}