#include <stdio.h>
#include <stdlib.h>

//Traete el codigo del STACK aqui, que necesitas hacerle para que
//funcione? Son muy pocos cambios.

void isvalidformula(char * f)
{
  //Imprime aqui si la formula "f" recibida esta bien formada o no
}

int main() 
{
  char formula1[30] = "aa()bb((c))(ddd((rr((a)a)))";
  char formula2[30] = "((a+b)-(z*d))";

  isvalidformula(formula1);
  isvalidformula(formula2);
}