// Abre arquivo no modo leitura
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

int loadPlaylist(List *playlist)
{

  FILE *file;
  char fileData[100];

  file = fopen("./playlist.txt", "r");
  if (file == NULL)
  {
    printf("Erro ao abrir arquivo");
    return 0;
  }

  // run into all songs
  while (fgets(fileData, 100, file) != NULL)
  {
    // split song line in parts
    char *song = strtok(fileData, "|");

    int i = 0;
    Song newSong;

    while (song != NULL)
    {
      // Save currente song parts
      switch (i)
      {
      case 0:
        strncpy(newSong.nome, song, 50);
        i++;
        break;
      case 1:
        strncpy(newSong.artista, song, 50);
        i++;
        break;
      case 2:
        newSong.duracao = strtof(song, NULL);
        i++;
        break;
      }
      song = strtok(NULL, "|");
    }
    insertListBegin(playlist, newSong);
  }
  fclose(file);
  return 1;
}