#include<cs50.h>
#include<stdio.h>

int main(int argc, string argv[])
{

  if (argc < 3) 
  {
    printf("usage: previous n (the number whose predecessor you want)\n");

    return 1;
  }

  printf ("Result %.2f\n", atof(argv[1]) + atof(argv[2]));

  return 0;
}