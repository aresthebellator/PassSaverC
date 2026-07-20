// ===============================================
// PassSaverC
// Copyright (c) 2026 aresthebellator
// Version: 1.0 
// ===============================================


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define CYAN    "\033[1;36m"
#define YELLOW "\033[1;33m"
#define BLUE   "\033[1;34m"

struct NuovaPassword
{
  char email[15];
  char sito[30];
  char social[20];
  char password[40];
};

void scritta()
{
  printf(" ____                ____                      ____ \n");
  printf("|  _ \\ __ _ ___ ___ / ___|  __ ___   _____ _ __/ ___|\n");
  printf("| |_) / _` / __/ __|\\___ \\ / _` \\ \\ / / _ \\ '__| |   \n");
  printf("|  __/ (_| \\__ \\__ \\ ___) | (_| |\\ V /  __/ |  | |___ \n");
  printf("|_|   \\__,_|___/___/|____/ \\__,_| \\_/ \\___|_|   \\____|\n\n");
}

void SalvaPasswordSito(char *nomefile, struct NuovaPassword a)
{
  FILE *fp = fopen(nomefile, "a");
  if(fp == NULL)
  {
    printf(RED "Errore durante l'apertura del file.\n" RESET);
    return;
  }
  fprintf(fp, CYAN"Sito: %s | Email: %s | Password: %s\n" RESET, a.sito, a.email, a.password);
  fclose(fp);
  printf(YELLOW "Password salvate con successo nel file: %s\n" RESET,nomefile);
}

void SalvaPasswordSocial(char *nomefile, struct NuovaPassword a)
{
  FILE *fp = fopen(nomefile, "a");
  if(fp == NULL)
  {
    printf(RED "Errore durante l'apertura del file. \n" RESET);
    return;
  }
  fprintf(fp, CYAN "Social: %s | Email: %s | Password: %s\n" RESET,a.social,a.email,a.password);
  fclose(fp);
  printf(YELLOW "Password salvate con successo nel file: %s\n" RESET,nomefile);

}

void ApriFile(char *nomefile)
{
  FILE *fp = fopen(nomefile,"r");
  if(fp == NULL)
  {
    printf(RED "Errore,File non trovato.\n" RESET);
    return;
  }
  system("clear");
  scritta();
  printf(YELLOW "SCRIVI CHE TIPO DI PASSWORD VUOI CONTROLLARE: \n" RESET);
  int sceltapass;
  printf(CYAN "[1]" RESET " SITO \n");
  printf(CYAN "[2]" RESET " SOCIAL\n");
  scanf("%d",&sceltapass);
  if(sceltapass == 1)
  {
    printf(BLUE "\n--- CONTENUTO FILE ---\n" RESET);
    char linea[100];
    while (fgets(linea, sizeof(linea), fp)) 
    {
        printf("%s", linea);
    }
    fclose(fp);
  }
  else
  {
    printf(BLUE "\n--- CONTENUTO FILE ---\n" RESET);
    char linea[100];
    while (fgets(linea, sizeof(linea), fp)) {
        printf("%s", linea);
    }
    fclose(fp);
  }
}

int main()
{
  struct NuovaPassword a;
  int scelta;
  char nomefile[50];
  system("clear");
  scritta();
  printf(YELLOW "SCRIVI COSA VUOI FARE: " RESET);
  printf("\n");
  printf(CYAN "[1]" RESET " INSERIRE UNA NUOVA PASSWORD \n");
  printf(CYAN "[2]" RESET " APRI IL GESTORE \n");
  printf("> ");
  scanf("%d",&scelta);
  
  if(scelta == 1)
  {
    int sceltatipo;
    system("clear");
    scritta();
    printf(YELLOW "SCEGLI CHE TIPO DI PASSWORD DEVO SALVARE: \n" RESET);
    printf(CYAN "[1]" RESET " SITO WEB \n");
    printf(CYAN "[2]" RESET " SOCIAL \n");
    printf("> ");
    scanf("%d",&sceltatipo);
    if(sceltatipo == 1)
    {
      system("clear");
      scritta();
      printf(YELLOW " INSERISCI IL NOME DEL SITO: " RESET);
      scanf("%s",a.sito);
      printf(YELLOW " INSERISCI L'EMAIL: " RESET);
      scanf("%s",a.email);
      printf(YELLOW " INSERISCI LA PASSWORD: "RESET);
      scanf("%s", a.password);
      printf(RED "INSERISCI IL NOME DEL FILE DOVE SONO CONTENUTE LE PASSWORD (es: password.txt/json): "RESET);
      scanf("%s",nomefile);
      SalvaPasswordSito(nomefile, a);
    
    }
    else
    {
      system("clear");
      scritta();
      printf(YELLOW" INSERISCI IL NOME DEL SOCIAL: " RESET);
      scanf("%s",a.social);
      printf(YELLOW "INSERISCI L'EMAIL: " RESET);
      scanf("%s",a.email);
      printf(YELLOW " INSERISCI LA PASSWORD: " RESET);
      scanf("%s",a.password);
      printf(RED "INSERISCI IL NOME DEL FILE DOVE SONO CONTENUTE LE PASSWORD (es: password.txt/json): " RESET);
      scanf("%s",nomefile);
      SalvaPasswordSocial(nomefile, a);
    }
  }
  
  else
  {
    system("clear");
    scritta();
    printf(YELLOW "Scrivi il nome del file dove sono contenute le password: " RESET);
    scanf("%s",nomefile);
    ApriFile(nomefile);
  }
  return 0;
}
