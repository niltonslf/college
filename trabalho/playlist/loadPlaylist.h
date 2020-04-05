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

  // percorre por todas as músicas
  while (fgets(fileData, 100, file) != NULL)
  {
    // divide a linha da música corrente em partes
    char *song = strtok(fileData, "|");

    int i = 0; // variável uitilizada para saber em qual parte da música está. 0 => nome da música | 1 => Artista | 2 => Duração
    Song newSong;

    while (song != NULL)
    {
      // Save currente song parts
      switch (i)
      {
      case 0:
        strncpy(newSong.nome, song, 50); // copia o valor da primeira parte para o nome da música
        i++;
        break;
      case 1:
        strncpy(newSong.artista, song, 50); // copia o valor da segunra parte para o artista
        i++;
        break;
      case 2:
        newSong.duracao = strtof(song, NULL); // copia o valor da terceira parte para a duração da música
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