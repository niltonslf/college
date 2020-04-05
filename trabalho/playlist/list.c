#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"
#include "loadPlaylist.h"
#include "managerMenu.h"

int main()
{

  List *playlist = createList(); // inicia uma lista vazia
  loadPlaylist(playlist);        // carrega a playlist do arquivo txt

  /* CÓDIGO DO MENU  */
  managerMenu(playlist); // Executa função do menu gerenciador da playlist

  return 0;
}
