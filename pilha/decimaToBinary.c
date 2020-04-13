#include "./pilhaInt.h"



int decimalToBinary (int decimalNumber, Pilha pilha) {

  int res = decimalNumber / 2;
  int mod = decimalNumber % 2;
  empilha(mod, pilha);

  if(res != 0) decimalToBinary(res, pilha);

  while(!vazia(pilha)) printf("%d ",desempilha(pilha));
}



int main() {
  
    Pilha pilha = criaPilha(100);

    decimalToBinary(59, pilha);

    return 0;
}