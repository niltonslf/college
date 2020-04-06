#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"   // Carrega arquivo com as funções da lista
#include "loadPlaylist.h" // Carrega arquivo com a função de gerar a playlist
#include "managerMenu.h"  // Carrega arquivo com a função de gerenciar o menu da playlist

int main()
{

  List *playlist = createList(); // inicia uma lista vazia
  loadPlaylist(playlist);        // carrega a playlist do arquivo txt

  /* CÓDIGO DO MENU  */
  managerMenu(playlist); // Executa função do menu gerenciador da playlist

  freeList(playlist); // desaloca playlist da memória

  return 0;
}
