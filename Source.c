//programa que descifra la contrase�a que previamente ha introducido el usuario
//1 pedir contrase�a o cojer la contrase�a que esta ya en el archivo
//2 resolver
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>


#define N 9
//estructura
struct CONT{
	char cad[N+4],cadv[N+4];
};
//fuciones
void Cambiocontrase�a(struct CONT *);
int Descifrador(int *);
//main
void main()
{
	//declaracion de variables
	int opc, flag = 0, contrase�a,*pcontra,descifrado;
	char cad[20] , cad2[20];
	clock_t comienzo, final;

	struct CONT *pcont,cont;
	pcontra = &contrase�a;
	pcont = &cont;

	//declaracion de ficheros
	FILE *pcontrase�a,*presultado;
	errno_t err1,err2;

	//primera pantalla, titulo del programa
	printf("        ***************************************************************************************************************************\n");
	printf("        **            _______   _______  _______                 ______      ______   _______                _______    _______  **\n");
	printf("        **        |  |         |        |       |         |  |  |        |  |        |       |           |  |       |  |       | **\n");
	printf("        ** _______|  |_______  |        |       | _______ |  |  |______  |  |        |_______|   ________|  |       |  |_______| **\n");
	printf("        **|       |  |         |        |       | |       |  |  |        |  |        |       |  |        |  |       |  |     |   **\n");
	printf("        **|       |  |         |        |       | |       |  |  |        |  |        |       |  |        |  |       |  |     |   **\n");
	printf("        **|_______|  |_______  |______  |_______| |______ |  |  |        |  |______  |       |  |________|  |_______|  |     |   **\n");
	printf("        **                                                                                                                       **\n");
	printf("        ***************************************************************************************************************************\n");
	getch();
	system("cls");//sirve para borrar la pantalla
	
	do {
		
		system("cls");
		//panel principal
		printf("   *DESCIFRADOR DE CONTRASE�AS NUMERICAS*\n\n");
		printf(" seleccione 1 opcion:\n");
		printf("\t1-cambio de contrase�a\n\t2-descifrar contrase�a original\n\t3-salir del programa\n");
		scanf_s("%d", &opc);
		switch (opc)
		{
		case 1: //cambio de contrase�a
		{
			system("cls");
			printf("   *DESCIFRADOR DE CONTRASE�AS NUMERICAS*\n\n");
			getchar();
			Cambiocontrase�a(pcont);
			//se abre el fichero
			err1 = fopen_s(&pcontrase�a, "Contrase�a.txt", "w");
			//check del fichero
			if (err1 != NULL)
			{
				printf("apertura incorrecta");
				fclose(pcontrase�a);
				exit(1);
			}
			fprintf(pcontrase�a, "contrase�a guardada: %s\n", cont.cad);//imprime en el block de notas lo que pone ente ""
			fclose(pcontrase�a); //se cierra el fichero
			flag = 1;
			break;
		}
		case 2: //descifra la contrase�a original (que esta guardada en un block de notas llamado "Contrase�a.txt"
		{
			system("cls");
			printf("   *DESCIFRADOR DE CONTRASE�AS NUMERICAS*\n\nesperando...");
			getchar();
			err1 = fopen_s(&pcontrase�a, "Contrase�a.txt", "r");//abrir fichero de contrase�a
			//bucle de lectura del fichero
			while (feof(pcontrase�a) == 0)
			{
				fscanf_s(pcontrase�a, "%s %s %d", cad, _countof(cad), cad2, _countof(cad2), &contrase�a);
			}
			err2 = fopen_s(&presultado, "Resultado.txt", "w");//abrir fichero del resultado
			comienzo = clock(); //empieza a cronometrar
			descifrado = Descifrador(pcontra); //funcion que descifra la contrase�a
			final = clock(); //termina de cronometrar
			system("cls");
			printf("   *DESCIFRADOR DE CONTRASE�AS NUMERICAS*\n\n");
			fprintf(presultado, "contrase�a: %d\n", descifrado);
			fprintf(presultado, "tiempo que ha tardado en resolverlo(ms): %d\n", (final-comienzo));
			printf("la contrase�a es %d\n", descifrado);
			printf("tiempo que ha tardado en resolverlo(ms): %d\n", (final-comienzo));//la diferencia de tiempo es el tiempo que ha tardado en resolver la contrase�a
			system("pause");
			//cierre de ficheros
			fclose(pcontrase�a); 
			fclose(presultado);
			flag = 1;
			break;
		}
		case 3: //salir del programa
		{
			system("cls");
			printf("   *DESCIFRADOR DE CONTRASE�AS NUMERICAS*\n\n");
			printf("hasta la vista\n");
			flag = 0;
			break;
		}
		default: //si as seleccionaado una opcion distinta a las anteriores, te devuelve otra vez al inicio
			printf("seleccione una opcion posible\n");
			system("pause");
			flag = 1;
		}
	} while (flag == 1); //todos los casos te repiten el bucle excepto el 3, que sirve para cerrar el programa y finaliza el bucle

	system("pause");
}


//funcion cambio de contrase�a
void Cambiocontrase�a(struct CONT *pcon)
{
	//declaro variables de la funcion
	int i = 0,j=0, a = 0;
	int flag = 0, flag1=0, flag2 = 0;
	//se repite el bucle hasta que el usuario ponga una contrase�a valida
	do
	{
		system("cls");
		printf("*DESCIFRADOR DE CONTRASE�AS NUMERICAS*\n\n");
		do
		{
			system("cls");
			flag = 0;
			printf("*DESCIFRADOR DE CONTRASE�AS NUMERICAS*\n\n");
			printf("-la contrase�a tiene que ser num�rica\n-la contrase�a puede tener entre 4 y %d d�gitos\n\n",N);
			printf("introduzca la contrase�a: ");
			gets(pcon->cad);//el usuario introduce la contrase�a
			//check te verificacion de contrase�a, si no se cumple alguna de las opciones se repite el bucle
			for (i = 0; i < a; i++)
			{
				if (pcon->cad[i] >= '0' && pcon->cad[i] <= '9')
				{
					flag = 0;
				}
				else
				{
					printf("contrase�a no valida\n\n");
					flag = 1;
					break;
				}
				if (a > N || a < 4)
				{
					printf("contrase�a no valida\n\n");
					flag = 1;
					break;
				}
			}

		} while (flag == 1);
		printf("contrase�a valida\n\nverifique la contrase�a: ");
		gets(pcon->cadv);//el usuario repite la contrase�a por si se ha equivocado
		flag2 = strncmp(pcon->cad, pcon->cadv, N);//si no es la misma contrase�a se repite el bucle
	} while (flag2 != 0);
	printf("contrase�a verificada\n\n");
	system("pause");
	//se vuelve al main 
}

//fucion Descifrador
int Descifrador(int *pcont)
{
	int i = 0,*pcifrado,cifrado;
	pcifrado = (int*)calloc(1,sizeof(int));//asignacion dinamica de memoria
	//bucle para decubrir la contrase�a
	for (i = 0; i < pow(10,N); i++)
	{
		if (*pcifrado== *pcont)
			break;
		(*pcifrado)++;
	
	}
	cifrado = *pcifrado; //copio el valor de lo que apunta el puntero para poder liberarlo despues
	free(pcifrado);//libras el espacio ocupado por el puntero
	return(cifrado);
}


