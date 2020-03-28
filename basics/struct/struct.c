#include <stdio.h>

typedef struct
{
 char name[100];
 int age;
 char gender;
} pessoa;


int main(int argc, char const *argv[])
{


  pessoa marcola = {"Marcos", 28, 'M'};
  printf("Nome %s \n", marcola.name);
  printf("age %s \n", marcola.age);
  printf("Gênero %s \n", marcola.gender);

  return 0;
}


