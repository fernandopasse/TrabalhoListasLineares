#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
/* definição da estrutura da lista */
struct lista {
       int info;
       struct lista *prox;
};
typedef struct lista Lista;

/* funÃ§Ã£o de criaÃ§Ã£o: retorna uma lista vazia */

Lista *lst_cria(void)
{
       return NULL;
}

/* inserÃ§Ã£o no inÃ­cio: retorna a lista atualizada */
Lista *lst_insere (Lista *l, int i)
{
       Lista *novo = (Lista*) malloc(sizeof(Lista));
       novo->info = i;
       novo->prox = l;
       return novo;
}
/* funÃ§Ã£o imprime: imprime valores dos elementos */
void lst_imprime (Lista *l)
{
     Lista *p;
     printf("  ");              /* variÃ¡vel auxiliar para precorrer a lista */
     for (p = l; p != NULL; p =p->prox)
     {
         printf("%02d ", p->info);
     }
}
/* funÃ§Ã£o busca: busca um valor na lista */
Lista *lst_busca (Lista *l, int v)
{
     Lista *p;              /* variÃ¡vel auxiliar para precorrer a lista */
     for (p = l; p != NULL; p =p->prox)
     {
         if (p->info == v)
            return p;
     }
     return NULL;
}

/* funÃ§Ã£o vazia: retorna 1 se a lista estÃ¡ vazia ou o se nÃ£o vazia */
int lst_vazia (Lista *l)
{
  if (l == NULL)
     return 1;
  else
     return 0;
}
/* funÃ§Ã£o retira: retira um elemento da lista */
Lista *lst_retira (Lista *l, int v)
{
       Lista *ant = NULL;     /* ponteiro para o elemento anterior */
       Lista *p = l;          /* ponteiro para percorrer a lista */
       /* procura o elemento na lista, guardando o anterior */
       while (p != NULL && p->info != v) {
             ant = p;
             p = p->prox;
       }
       /* verifica se achou o elemento */
       if (p == NULL)
          return l;         /* nÃ£o achou o elemento: retorna a lista original */

       /* retira o elemento */
       if (ant == NULL) {
               /* retira elemento do inÃ­cio */
               l = p->prox;
               }
       else {
               /* retira elemento do meio da lista */
               ant->prox = p->prox;
       }
       free(p);
       return l;
}
/* funÃ§Ã£o libera lista: libera o espaÃ§o de memÃ³ria alocado  */
Lista *lst_libera (Lista *l)
{
     Lista *p = l;
     Lista *t;
     while (p != NULL) {
           t = p->prox; /* guarda referÃªncia p/ prÃ³ximo elemento */
           free(p);            /* libera a memÃ³ria apontada por p */
           p = t;
     }
     return p;
}
/* -------------------- */
/*  InÃ­cio do Programa  */
/* -------------------- */
int main (void)
{
    Lista *L, *DOIS, *TRES, *INCOMUM, *COMUM, *p; // define a variávvel L do tipo TLISTA
    int valor; // define a variável valor do tipo TDADOS para digitação
    L = lst_cria();
    DOIS = lst_cria();
    TRES = lst_cria();
    COMUM = lst_cria();
    INCOMUM = lst_cria();
    system("color f0");
    char opcao, menuCerteza, menuOpcao_Um, menuOpcao_Dois, menuOpcao_Tres, valorPertinente;
    int numero;
    continuar:

    while (1){
           textcolor(12);
           textbackground(15);
           sleep(500);
           printf("\n\n        \xFE");
           textcolor(10);
           printf("\xFE\xFE");
           textcolor(0);
           printf("  INSTITUTO FEDERAL DE EDUCA%c%cO CI%cNCIA E TECNOLOGIA\n", 128, 199, 210);
           textcolor(10);
           sleep(500);
           printf("        \xFE\xFE");
           textcolor(0);
           printf("   DO SUDESTE DE MINAS GERAIS\n");
           textcolor(10);
           sleep(500);
           printf("        \xFE\xFE\xFE\n");
           sleep(500);
           printf("        \xFE\xFE   CAMPUS JUIZ DE FORA\n\n");
           sleep(500);
           textcolor(0);
           denovo:
           printf("\n\t       TRABALHO LISTAS ENCADEADAS - ELEMENTOS EM COMUM");
           printf("\n\t       ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
           printf("\n\n\t       Desenvolvido por: Fernando - Felipe");
           printf("\n\n \xC9\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCB\ÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBB");
           printf("\n \xBA              MENU PRINCIPAL - OP\x80\xE5\x45S                         \xBA N\xA7 DA OP\x80\x41O \xBA");
           printf("\n \xCC\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCE\ÍÍÍÍÍÍÍÍÍÍÍÍÍ\xB9");
           printf("\n \xBA CRIAR LISTA                                                  \xBA      1      \xBA");
           printf("\n \xCC\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCE\ÍÍÍÍÍÍÍÍÍÍÍÍÍ\xB9");
           printf("\n \xBA GERAR LISTA COM ELEMENTOS DIVIS%cVEIS POR DOIS E OUTRA  COM   \xBA      2      \xBA", 214);
           printf("\n \xBA               ELEMENTOS DIVIS%cVEIS POR TR%cS                  \xBA             \xBA", 214, 210);
           printf("\n \xCC\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCE\ÍÍÍÍÍÍÍÍÍÍÍÍÍ\xB9");
           printf("\n \xBA MOSTRAR ELEMENTOS COMUNS AS DUAS LISTAS CRIADAS NA OP%c%cO     \xBA      3      \xBA", 128, 199);
           printf("\n \xBA    DOIS E ELEMENTOS QUE N%cO S%cO COMUNS AS DUAS LISTAS        \xBA             \xBA", 199, 199);
           printf("\n \xCC\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCE\ÍÍÍÍÍÍÍÍÍÍÍÍÍ\xB9");
           printf("\n \xBA SAIR                                                         \xBA      0      \xBA");
           printf("\n \xC8\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCAÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBC");
           printf("\n\n                 DIGITE O N%cMERO DA OP%c%cO DESEJADA: ", 233, 128, 199);
           printf ("\n\n                          Escolha uma op%c%co:  ", 135, 198);
           opcao = getch();
           system("cls");
           switch (opcao){
                case '0':
                     if(lst_vazia(L) == 0){
                             printf("\n T%cM CERTEZA? TUDO QUE FOI CRIADO SER%c PERDIDO \n  (0 PARA SIM OU QUALQUER TECLA PARA N%cO): ", 210, 181, 199);
                             valorPertinente = getch();
                             if(valorPertinente == '0'){
                             L = lst_libera(L);
                             DOIS = lst_libera(DOIS);
                             TRES = lst_libera(TRES);
                             COMUM = lst_libera(COMUM);
                             INCOMUM = lst_libera(INCOMUM);
                             p = lst_libera(p);
                             exit(1);
                             }else{
                                   system("cls");
                                   break;
                             }
                     }else{
                           exit(1);
                     }
                           
                case '1':
                       printf("\n     \xC9\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCBÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBB\n");
                       printf("     \xBA  VOC%c ESCOLHEU CRIAR LISTA                         \xBA N\xA7 DA OP\x80\x41O \xBA", 210);
                       printf("\n     \xCC\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCE\ÍÍÍÍÍÍÍÍÍÍÍÍÍ\xB9");
                       printf("\n     \xBA  VOLTAR AO MENU PRINCIPAL                          \xBA      1      \xBA");
                       printf("\n     \xCC\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCE\ÍÍÍÍÍÍÍÍÍÍÍÍÍ\xB9");
                       printf("\n     \xBA  CRIAR E PREENCHER A LISTA / CONTINUAR PREENCHENDO \xBA      2      \xBA");
                       printf("\n     \xCC\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCE\ÍÍÍÍÍÍÍÍÍÍÍÍÍ\xB9");
                       printf("\n     \xBA  LIMPAR E PREENCHER                                \xBA      3      \xBA");
                       printf("\n     \xC8\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCAÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBC");
                       novamente: 
                       printf("\n\n  DIGITE A OP%c%cO: ", 128, 199);
                       menuOpcao_Um = getch();
                       switch(menuOpcao_Um){
                             case '1':
                                  system("cls");
                                  goto continuar;
                                  break;
                             case '2':
                                  voltar:
                                  printf("\n\n  DIGITE OS ELEMENTOS DA LISTA( 0 PARA PARAR O PREENCHIMENTO ): ");
                                  scanf("%d",&valor);
                                  if(valor != 0){
                                        L = lst_insere(L, valor); // função que inclui um valor no final da lista
                                        do {
                                           printf("\n  VOC%c DIGITOU: ", 210);
                                           lst_imprime(L); // procedimento que exibe a lista L
                                           printf("\n\n  DIGITE OS ELEMENTOS DA LISTA( 0 PARA PARAR O PREENCHIMENTO ): ");
                                           scanf("%d",&valor);
                                           if (valor != 0){
                                                     L = lst_insere(L, valor);
                                           }else{
                                                 goto novamente;
                                           }
                                        }while (valor != 0);
                                  }else{
                                        goto novamente;
                                  }
                                  break; 
                               case '3':
                                    if((lst_vazia(L)) == 0){
                                            printf("\n  VOC%c TEM CERTEZA? A LISTA SER%c COMPLETAMENTE APAGADA \n  (0 PARA SIM OU QUALQUER TECLA PARA N%cO): ", 210, 181, 199);
                                            menuCerteza = getch();
                                            switch(menuCerteza){
                                                     case '0':
                                                          L = lst_libera (L);
                                                          goto voltar;
                                                          break;
                                                     default:
                                                             goto novamente;
                                                             break;
                                            }
                                    }else{
                                         goto voltar;
                                    } 
                                    break;            
                             default:
                                 textcolor(12);   
                                 printf("\n \xC9\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBB"); 
                                 printf("\n \xBA   OP%c%cO INV%cLIDA!   \xBA", 128, 199, 181);
                                 printf("\n \xC8ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBC\n");
                                 textcolor(0);
                                 goto novamente;
                                 break;
                       }
                       break;
                case '2':
                       printf("\n \xC9\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCBÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBB\n");
                       printf(" \xBA  GERAR LISTA COM ELEMENTOS DIVIS%cVEIS POR DOIS E OUTRA  COM  \xBA             \xBA", 214);
                       printf("  \xBA                    ELEMENTOS DIVISIVEIS POR TR%cS             \xBA N\xA7 DA OP\x80\x41O \xBA", 210);
                       printf("\n \xCC\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCE\ÍÍÍÍÍÍÍÍÍÍÍÍÍ\xB9");
                       printf("\n \xBA  VOLTAR AO MENU PRINCIPAL                                    \xBA      1      \xBA");
                       printf("\n \xCC\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCE\ÍÍÍÍÍÍÍÍÍÍÍÍÍ\xB9");
                       printf("\n \xBA  GERAR                                                       \xBA      2      \xBA");
                       printf("\n \xC8\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCA\ÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBC");
                       continuarAqui:
                          printf("\n\n  DIGITE A OP%c%cO: ", 128, 199);
                          menuOpcao_Dois = getch();
                          switch(menuOpcao_Dois){
                                     case '1':
                                               system("cls");
                                               goto continuar;
                                               break;
                                     case '2':
                                          if(lst_vazia(L)){
                                                 printf("\n  LISTA VAZIA, VOLTE AO MENU PRINCIPAL PARA PREENCHE-LA!");
                                                 goto continuarAqui;
                                          }
                                          DOIS = lst_libera(DOIS);
                                          TRES = lst_libera(TRES);
                                          for (p = L; p != NULL; p =p->prox){
                                                  if((p->info % 2) == 0){
                                                       DOIS = lst_insere(DOIS, p->info);
                                                  }
                                                  if((p->info % 3) == 0){
                                                       TRES = lst_insere(TRES, p->info);
                                                  }
                                                      
                                           }
                                          printf("\n  LISTA ATUALIZADA OU GERADA, COM SUCESSO!!!\n");
                                          printf("  ELEMENTOS DIVIS%cVEIS POR DOIS: ", 214);
                                          if(lst_vazia(DOIS)){
                                                  printf(" NENHUM ELEMENTO DIVIS%cVEL POR DOIS ", 214);
                                          }else{             
                                                  lst_imprime(DOIS);
                                          }
                                          printf("\n  ELEMENTOS DIVIS%cVEIS POR TR%cS: ", 214, 210);
                                          if(lst_vazia(TRES)){
                                                  printf(" NENHUM ELEMENTO DIVIS%cVEL POR TR%cS ", 214, 210);
                                          }else{             
                                                  lst_imprime(TRES);
                                          }
                                          goto continuarAqui;
                                          break;
                                     default:
                                          textcolor(12);   
                                          printf("\n \xC9\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBB"); 
                                          printf("\n \xBA   OP%c%cO INV%cLIDA!   \xBA", 128, 199, 181);
                                          printf("\n \xC8ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBC\n");
                                          textcolor(0);
                                          goto continuarAqui;
                                          break;
                          }
                case '3':
                       printf("\n \xC9\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCBÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBB\n");
                       printf(" \xBA  MOSTRAR ELEMENTOS COMUNS AS DUAS LISTAS CRIADAS NA OP%c%cO    \xBA             \xBA", 128, 199);
                       printf("  \xBA    DOIS E ELEMENTOS QUE N%cO S%cO COMUNS AS DUAS LISTAS        \xBA N\xA7 DA OP\x80\x41O \xBA", 199, 199);
                       printf("\n \xCC\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCE\ÍÍÍÍÍÍÍÍÍÍÍÍÍ\xB9");
                       printf("\n \xBA  VOLTAR AO MENU PRINCIPAL                                    \xBA      1      \xBA");
                       printf("\n \xCC\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCE\ÍÍÍÍÍÍÍÍÍÍÍÍÍ\xB9");
                       printf("\n \xBA  MOSTRAR                                                     \xBA      2      \xBA");
                       printf("\n \xC8\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xCA\ÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBC");
                       continuarLa:
                          printf("\n\n  DIGITE A OP%c%cO: ", 128, 199);
                          menuOpcao_Tres = getch();
                          switch(menuOpcao_Tres){
                                     case '1':
                                               system("cls");
                                               goto continuar;
                                               break;
                                     case '2':
                                          if(lst_vazia(L)){
                                                 printf("\n  LISTA VAZIA, VOLTE AO MENU PRINCIPAL PARA PREENCHE-LA!");
                                                 goto continuarLa;
                                          }
                                          if((lst_vazia(DOIS) == 1) && (lst_vazia(TRES) == 1)){
                                                 printf("VOC%c N%cO GEROU AS LISTAS! USE A OP%c%cO DOIS DO MENU PRINCIPAL", 210, 199, 128, 199);
                                                goto continuarLa;
                                          }
                                          INCOMUM = lst_libera(INCOMUM);
                                          COMUM = lst_libera(COMUM);
                                          for (p = L; p != NULL; p =p->prox){
                                                 if((p->info % 2 != 0) && ((p->info % 3 != 0))){
                                                       INCOMUM = lst_insere(INCOMUM, p->info);
                                                 }
                                                 if((p->info % 3 == 0) && ((p->info % 2 == 0))){
                                                       COMUM = lst_insere(COMUM, p->info);
                                                 }
                                          }
                                          printf("\n  ELEMENTOS COMUNS AS DUAS LISTAS: ");
                                          if(lst_vazia(COMUM)){
                                                  printf(" NENHUM ELEMENTO COMUM ");
                                          }else{             
                                                  lst_imprime(COMUM);
                                          }
                                          printf("\n  ELEMENTOS INCOMUNS AS DUAS LISTAS: ");
                                          if(lst_vazia(INCOMUM)){
                                                  printf(" NENHUM ELEMENTO INCOMUM ");
                                          }else{             
                                                  lst_imprime(INCOMUM);
                                          }
                                          goto continuarLa;
                                          break;
                                     default:
                                          textcolor(12);   
                                          printf("\n \xC9\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBB"); 
                                          printf("\n \xBA   OP%c%cO INV%cLIDA!   \xBA", 128, 199, 181);
                                          printf("\n \xC8ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBC\n");
                                          textcolor(0);
                                          goto continuarLa;
                                          break;
                          }
                default:
                       textcolor(12);
                       printf("\xC9\ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBB"); 
                       printf("\n\xBA   OP%c%cO INV%cLIDA!   \xBA", 128, 199, 181);
                       printf("\n\xC8ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\xBC");
                       textcolor(0);
                       printf("\n\nPRESSIONE QUALQUER TECLA PARA VOLTAR...\n");
                       getch();
                       system("cls");
                       break;

        }
}

    return(0);
}
