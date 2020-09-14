#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int op,i;
char cliente[70];
void arch1(char nombre[70], char cliente[25], char comida[100]);
void arch2(char nombre[70], char cliente[25], char comida[100]);
void arch3(char nombre[70], char cliente[25], char comida[100]);

int main(void) {
	pid_t pid1, pid2;
    int status1, status2;
	printf("Ingrese su nombre\n");
	scanf("%s",cliente);
	printf("\n");
	
	do{
	
	printf("¿Que desea ordenar %s?\n",cliente);
	printf("Contamos con:\n\n");
	printf("1. Desayuno\n");
	printf("2. Comida\n");
	printf("3. Cena\n");
	printf("4. Desayuno y Comida\n");
	printf("5. Comida y Cena\n");
	printf("6. Desayuno, Comida y Cena\n");	
	printf("7. Salir\n");
	scanf("%d",&op);

	switch(op)
		{
		case 1:
			if((pid1=fork())==0){ 

			}
			else
			{
				printf("El desayuno es: \n");
				printf("Café, fruta y jugo de naranja. (Proceso: %d)\n", getpid());
			}
		
			arch1(" Desayuno ", cliente, "café, fruta y jugo de naranja.\n");
			exit(0);
			break;
		case 2:
			if((pid1=fork())==0){ 

			}
			else
			{
				printf("La comida es caldo de pollo. (Proceso: %d)\n", getpid());
				arch2(" Comida ", cliente, "caldo de pollo.\n");
			}
			exit(0);
			break;
		case 3:
			if((pid1=fork())==0){ 

			}
			else
			{
				printf("La cena es huevo y té %d.\n", getpid());
				arch3(" Cena ", cliente, "huevo y té.\n");
			}
			exit(0);
			break;
		case 4:
			if((pid1=fork())==0){ 
				printf("El desayuno es: \n");
				printf("Café, fruta y jugo de naranja. (Proceso: %d)\n", getpid());
				arch1(" Desayuno ", cliente, "café, fruta y jugo de naranja..\n");
			}
			else{
				wait(&status1);
				printf("La comida es caldo de pollo. (Proceso: %d)\n", getpid());
				arch2(" Comida ", cliente, "caldo de pollo.\n");
			}
			exit(0);
			break;
		case 5:
			if((pid1=fork())==0){ 
				printf("La comida es caldo de pollo (Proceso: %d)\n", getpid());
				arch2(" Comida ", cliente, "caldo de pollo.\n");
			}
			else{
				wait(&status1);
				printf("La cena es huevo y té %d.\n", getpid());
				arch3(" Cena ", cliente, "huevo y té .\n");
			}
			exit(0);
			break;
		case 6:	
			if((pid1=fork())==0){ 
				if((pid1=fork())==0){
					printf("La cena es huevo y té %d.\n", getpid());
					arch3(" Cena ", cliente, "huevo y té.\n");
				}
				else{
					wait(&status2);
					printf("La comida es calde de pollo (Proceso %d)\n", getpid());
					arch2(" Comida ", cliente, "caldo de pollo.\n");
				}
			}
			else{
				wait(&status1);
				printf("El desayuno es café, fruta y jugo de naranja. %d.\n", getpid());
				arch1(" Desayuno ", cliente, "café, fruta y jugo de naranja.\n");
			}
			exit(0);
			break;
		default: 
			return 0;
		}
	}while(op!=7);
	return 0;	
}

void arch1(char nom[70], char cliente[25], char comida[100]){
    FILE* fichero;
    fichero = fopen("desayuno.txt", "a+");
    fputs(cliente, fichero);
    fputs(nom, fichero);
    fputs(comida, fichero);
    fclose(fichero);
    return;
}

void arch2(char nom[70], char cliente[25], char comida[100]){
    FILE* fichero;
    fichero = fopen("comida.txt", "a+");
    fputs(cliente, fichero);
    fputs(nom, fichero);
    fputs(comida, fichero);
    fclose(fichero);
    return;
}

void arch3(char nom[70], char cliente[25], char comida[100]){
    FILE* fichero;
    fichero = fopen("cena.txt", "a+");
    fputs(cliente, fichero);
    fputs(nom, fichero);
    fputs(comida, fichero);
    fclose(fichero);
    return;
}
