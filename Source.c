//programa que descifra la contraseña que previamente ha introducido el usuario
//1 pedir contraseña o coger la contraseña que esta ya en el archivo
//2 resolver

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<math.h>
#include<time.h>

#define N 9

//estructura
struct CONT {
	char cad[N], cadv[N];
};
//fuciones
void Titulo(void);
int Panelp(void);
void Cambiocontraseña(struct CONT *);
int Descifrador(int *);
//main
void main()
{
	//declaracion de variables
	int opc, flag = 0, contraseña, *pcontra, descifrado;
	char cad[20], cad2[20];
	clock_t comienzo, final;
	struct CONT *pcont, cont;
	pcont = &cont;
	pcontra = &contraseña;

	//declaracion de ficheros
	FILE *pcontraseña, *presultado;
	errno_t err1, err2;

	//primera pantalla, titulo del programa.
	Titulo(); //llamamos a la funcion titulo.
	
	do {
		system("cls"); //borra la pantalla.
		opc = Panelp();
		switch (opc)
		{
		case 1: //cambio de contraseña
		{
			system("cls");
			printf("\n\t*DESCIFRADOR DE CONTRASENAS NUMERICAS*\n\n");
			getchar();
			Cambiocontraseña(pcont);
			//se abre el fichero
			err1 = fopen_s(&pcontraseña, "Contraseña.txt", "w");
			//check del fichero
			if (err1 != NULL)
			{
				printf("apertura incorrecta");
				fclose(pcontraseña);
				exit(1);
			}
			fprintf(pcontraseña, "contrasena guardada: %s\n", cont.cad);//imprime en el block de notas lo que pone ente ""
			fclose(pcontraseña); //se cierra el fichero
			flag = 1;
			break;
		}
		case 2: //descifra la contraseña original (que esta guardada en un block de notas llamado "Contraseña.txt"
		{
			system("cls");
			printf("\n\t*DESCIFRADOR DE CONTRASENAS NUMERICAS*\n\nesperando...");
			getchar();
			err1 = fopen_s(&pcontraseña, "Contraseña.txt", "r");//abrir fichero de contraseña
			//bucle de lectura del fichero
			while (feof(pcontraseña) == 0)
			{
				fscanf_s(pcontraseña, "%s %s %d", cad, _countof(cad), cad2, _countof(cad2), &contraseña);
			}
			err2 = fopen_s(&presultado, "Resultado.txt", "w");//abrir fichero del resultado
			comienzo = clock(); //empieza a cronometrar
			descifrado = Descifrador(pcontra); //funcion que descifra la contraseña
			final = clock(); //termina de cronometrar
			system("cls");
			printf("\n\t*DESCIFRADOR DE CONTRASENAS NUMERICAS*\n\n");
			fprintf(presultado, "Contrasena: %d\n", descifrado);
			fprintf(presultado, "Tiempo que ha tardado en resolverlo: %d milisegundos\n", (final - comienzo));
			printf("La contrasena es %d\n", descifrado);
			printf("Tiempo que ha tardado en resolverlo: %d milisegundos\n", (final - comienzo));//la diferencia de tiempo es el tiempo que ha tardado en resolver la contraseña
			system("pause");
			//cierre de ficheros
			fclose(pcontraseña);
			fclose(presultado);
			flag = 1;
			break;
		}
		case 3: //salir del programa
		{
			system("cls");
			printf("\n\t*DESCIFRADOR DE CONTRASENAS NUMERICAS*\n\n");
			printf("\t Hasta la vista!");
			flag = 0;
			break;
		}
		default: //si as seleccionaado una opcion distinta a las anteriores, te devuelve otra vez al inicio
			system("cls"); //borra la pantalla.
			printf("\n\t*DESCIFRADOR DE CONTRASENAS NUMERICAS*\n\n");
			printf("\t Seleccione una opcion posible");
			system("pause>>null");
			flag = 1;
		}
	} while (flag == 1); //todos los casos te repiten el bucle excepto el 3, que sirve para cerrar el programa y finaliza el bucle

	system("pause>>null");
}

//funcion del titulo
void Titulo()
{
	printf("\n\n\n\n");
	printf("\t\t*****************************************************************************************\n");
	printf("\t\t**                                                                                     **\n");
	printf("\t\t**    %c%c  %c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c     %c%c  %c%c  %c%c%c%c%c  %c%c  %c%c%c%c%c  %c%c%c%c%c     %c%c  %c%c%c%c%c  %c%c%c%c%c **\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	printf("\t\t**    %c%c  %c%c     %c%c     %c%c %c%c     %c%c      %c%c         %c%c     %c%c %c%c     %c%c  %c%c %c%c  %c%c %c%c **\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	printf("\t\t** %c%c%c%c%c  %c%c%c%c%c  %c%c     %c%c %c%c  %c%c%c%c%c  %c%c  %c%c%c%c   %c%c  %c%c     %c%c%c%c%c  %c%c%c%c%c  %c%c %c%c  %c%c%c%c%c **\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	printf("\t\t** %c%c %c%c  %c%c     %c%c     %c%c %c%c  %c%c %c%c  %c%c  %c%c     %c%c  %c%c     %c%c %c%c  %c%c %c%c  %c%c %c%c  %c%c %c  **\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	printf("\t\t** %c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c  %c%c  %c%c     %c%c  %c%c%c%c%c  %c%c %c%c  %c%c%c%c%c  %c%c%c%c%c  %c%c %c%c **\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	printf("\t\t**                                                                                     **\n");
	printf("\t\t*****************************************************************************************\n");
	system("pause>>null"); //para el sistema, no sale ninguna frase
}
//funcion del panel principal
int Panelp()
{
	int opcion;
	printf("\n\t*DESCIFRADOR DE CONTRASENAS NUMERICAS*\n\n");
	printf(" Seleccione 1 opcion:\n");
	printf("\t1-Cambio de contrasena\n\t2-Descifrar contrasena original\n\t3-Salir del programa\n");
	scanf_s("%d", &opcion);
	return opcion;
}


//funcion cambio de contraseña
void Cambiocontraseña(struct CONT *pcon)
{
	//declaro variables de la funcion
	int i = 0, j = 0, lon = 0;
	int flag = 0, flag1 = 0, flag2 = 0;
	char *pcad, *pcadv;

	//se repite el bucle hasta que el usuario ponga una contraseña valida
	do
	{
		system("cls");
		printf("\n\t*DESCIFRADOR DE CONTRASENAS NUMERICAS*\n\n");
		do
		{
			system("cls");
			flag = 0; 
			printf("\n\t*DESCIFRADOR DE CONTRASENAS NUMERICAS*\n\n");
			printf(" requisitos:\n");
			printf("\t-La contrasena tiene que ser numerica\n\t-La contrasena puede tener entre 4 y %d digitos\n\n", N);
			printf(" Introduzca la contrasena: ");
			fflush(stdin); //limpia el buffer
			//el usuario introduce la contraseña
			pcad = (char*)malloc((N + 1) * sizeof(char));//asignación dinámica de memoria
			do
			{
				flag1 = 0;
				*(pcad + i) = _getch();
				pcon->cad[i] = *(pcad + i);

				if (*(pcad + i) == 13)
				{
					*(pcad + i) = '\0';
					pcon->cad[i] = '\0';
					lon = i;
					flag1 = 1;
					break;
				}
				if (*(pcad + i) == 8)
				{
					*(pcad + i) = '\0';
					pcon->cad[i] = '\0';
					*(pcad + i - 1) = '\0';
					pcon->cad[i - 1] = '\0';
					i--;
					printf("\b \b");

				}
				else
				{
					printf("*");
					i++;
				}
			} while (flag1 != 1);

			pcad = (char*)realloc(pcad, (lon + 1) * sizeof(char)); //reasignacion de memoria, para liberar los espacios no ocupados

			//check te verificacion de contraseña, si no se cumple alguna de las opciones se repite el bucle
			i = 0;
			for (i = 0; i < lon; i++)
			{
				if (pcon->cad[i] >= '0' && pcon->cad[i] <= '9')
				{
					flag = 0;
				}
				else
				{
					printf("\nContrasena no valida\n\n");
					fflush(stdin);
					flag = 1;
					system("pause");
					break;
				}
				if (lon > N || lon < 4)
				{
					printf("\nContrasena no valida\n\n");
					fflush(stdin);
					flag = 1;
					system("pause");
					break;
				}
			}

		} while (flag == 1);
		printf("\nContrasena valida\n\nVerifique la contrasena: ");
		//el usuario repite la contraseña por si se ha equivocado
		pcadv = (char*)malloc((N + 1) * sizeof(char));//asignación dinámica de memoria
		do
		{
			flag2 = 0;
			*(pcadv + j) = _getch();
			pcon->cadv[j] = *(pcadv + j);
			if (*(pcadv + j) == 13)
			{
				*(pcadv + j) = '\0';
				pcon->cadv[j] = '\0';
				flag2 = 1;
				free(pcadv); //se libera el espacio ocupado por el puntero
				break;
			}
			if (*(pcadv + j) == 8)
			{
				*(pcadv + j) = '\0';
				pcon->cadv[j] = '\0';
				j--;
				printf("\b \b");

			}
			else
			{
				printf("*");
				j++;
			}
		} while (flag2 != 1);
		flag2 = strncmp(pcon->cad, pcon->cadv, N);//si no es la misma contraseña se repite el bucle
	} while (flag2 != 0);
	printf("\nContrasena verificada\n\n");
	system("pause");
	//se vuelve al main 
}

//fucion Descifrador
int Descifrador(int *pcont)
{
	int i = 0, cifrado = 0;
	//bucle para decubrir la contraseña
	for (i = 0; i < pow(10, N); i++)
	{
		if (cifrado == *pcont)
			break;
		cifrado++;

	}
	return(cifrado);
}
