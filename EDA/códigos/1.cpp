#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct arvore{
    char item;
    arvore *esq,*dir;
};

arvore *Raiz;
int contador;

void arvore_Construtor(){
    Raiz=NULL;
    contador=0;
}

void arvore_Destrutor(arvore *&Raiz){
    if(Raiz!=NULL){
        arvore_Destrutor(Raiz->esq);
        arvore_Destrutor(Raiz->dir);
        free(Raiz);
        Raiz=NULL;
    }
}

bool arvore_Vazia(){
    return Raiz==NULL;
}

int arvore_Tamanho(){
    return contador;
}

bool arvore_Inserir(char letra, arvore *&Raiz){
    if(Raiz==NULL){
        if((Raiz=(arvore *) malloc(sizeof(arvore)))==NULL)
            return false;
        else{
            Raiz->item=letra;
            Raiz->esq=Raiz->dir=NULL;
            contador++;
            return true;
        }
    }
    else{
        if(letra<Raiz->item)
            return arvore_Inserir(letra,Raiz->esq);
        else{
            if(letra>Raiz->item)
                return arvore_Inserir(letra,Raiz->dir);
            else
                return false;//letra j� existe na �rvore
        }
    }
}

//percorre a �rvore

//percorre a �rvore
void arvore_Busca_pre_Ordem(arvore *&Raiz){
    if(Raiz!=NULL){
        printf(" %c",Raiz->item);
        arvore_Busca_pre_Ordem(Raiz->esq);
        arvore_Busca_pre_Ordem(Raiz->dir);
    }
}



int main(){
    char x,opcao;

    arvore_Construtor();

    do{
        printf("\nInforme a letra: ");
        setbuf(stdin,NULL);
        scanf("%c",&x);

        arvore_Inserir(x,Raiz);

        printf("\nMais dados? S/N:  ");
        setbuf(stdin,NULL);
        scanf("%c",&opcao);
    }while(toupper(opcao)!='N');

//  tamanho da �rvore
    printf("\nQuantidade de elementos: %d\n",contador);


//  impress�o em pr�-ordem
    printf("Arvore em pre-ordem:\n");
    arvore_Busca_pre_Ordem(Raiz);
    printf("\n\n");


//  devolvendo mem�ra alocada ao sistema operacional
    arvore_Destrutor(Raiz);

    return 0;
}


