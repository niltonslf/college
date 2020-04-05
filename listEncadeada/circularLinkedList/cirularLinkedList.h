
typedef struct
{
  int matricula;
  char nome[30];
  float n1, n2, n3;
} aluno;

typedef struct elemento *Lista;

Lista *cria_lista();
void libera_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);
int insere_lista_inicio(Lista *li, aluno al);
int insere_lista_final(Lista *li, aluno al);
int insere_lista_ordenada(Lista *li, aluno al);
