/****************************
****Autor : Michal Pessel****
****Zadanie : Kockova hra****
****Kruzok : RK 2		 ****
*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _CRT_NO_SECURE_DEPRECATE												/*define aby nevyhadzovalo zbytocne warningy*/
#define MAX 6

int hod_kockou_1[MAX]; int hod_kockou_2[MAX]; int vzor[MAX];
void about();																	/* definicia funkcie void, ktora vypise zakladne udaje o projekte*/
void vypisanie(int pole[]);														/* funkcia ktora mi vypise pole*/
void zoradenie(int pole[]);														/* zarodanie pola*/
int porovnanie_hodov(int hod_kockou_1[], int hod_kockou_2[]);					/* porovna mi polia 1 a 2*/
int figury(int hod_kockou[]);													/*funkcia ktora mi porovnava hodnoty v poli a vracia status na zaklade ktoreho dostavam figury*/
int nahradny_hod_kockou(int hod_kockou_1[]);									/*funkcia ktora mi generuje nahradny hod kockou ak nie som spokojny*/
int pocet_bodov(int hod_kockou_1[]);											/*funkcia ktora mi spocita body za dane figury*/
int menu();																		/*jednoducha funkcia menu*/

/*zaciatok main funkcie*/

int main()                                                                                                                               
{
	about();
	menu();

	int k = 0;
	int i;											   
	int volba = 0;
	

	

	srand(time(0));
	do{
	/*cyklus for pre naplnenie pola hod_kockou_1 random hodnotami*/

	for (k = 0; k < MAX + 1; k++)                                                                  
	{
		hod_kockou_1[k] = rand() % 6 + 1;
	}
	
	
	
		/*vypisanie poli naplnene hodnotami*/

		printf("Nezoradeny prvy hod kockami:\n");
		vypisanie(hod_kockou_1);

		zoradenie(hod_kockou_1);

		printf("Zoradeny prvy hod kockami:\n");
		vypisanie(hod_kockou_1);

		i = figury(hod_kockou_1);


		/*podmienky pre figury*/
		
		if (i == 0)
		{
			printf("*****************\n");
			printf("*    POSTUPKA   *\n");
			printf("*****************\n");
			pocet_bodov(hod_kockou_1);

		}
		else if (i == 3)
		{
			printf("*****************\n");
			printf("*    DVOJICA    *\n");
			printf("*****************\n");
			pocet_bodov(hod_kockou_1);
		}
		else if (i == 6)
		{
			printf("*****************\n");
			printf("*     POKER     *\n");
			printf("*****************\n");
			pocet_bodov(hod_kockou_1);
		}
		else if (i == 7)
		{
			printf("*****************\n");
			printf("*    TROJICA    *\n");
			printf("*****************\n");
			pocet_bodov(hod_kockou_1);
		}
		else if (i == 10)
		{
			printf("*****************\n");
			printf("*     PENTA     *\n");
			printf("*****************\n");
			pocet_bodov(hod_kockou_1);
		}
		else if (i == 15)
		{
			printf("*****************\n");
			printf("*    GENERAL    *\n");
			printf("*****************\n");
			pocet_bodov(hod_kockou_1);
		}
		else
		{
			printf("ZIADNA PLATNA FIGURA !!\n");
			printf("Pocet bodov = **0**\n");
		}
	} while ((i != 0) && (i != 3) && (i != 6) && (i != 7) && (i != 10) && (i != 15));
		
	
	/*printf("status = %i\n", i);*/
	
	/*podmienka pre nahradny hod*/

	/*printf("Ste spokojny s vasim hodom kockou? [1 = ANO / 0 = NIE]");
	scanf_s("%i", &volba);
	printf("###############################################\n");

	if (volba == 1)
	{
		printf("Ak chcete hrat znova zapnite a vypnite program\n");
	}
	else if (volba == 0) nahradny_hod_kockou(hod_kockou_1);*/


	return 0;

}  /* KONIEC MAIN*/

/*funkcia ktora vypise pole*/
void vypisanie(int pole[])                                                                                              
{
	int i = 0;
	

	while (i < MAX)
	{
		printf("kocka[%i] = %i\n", i, pole[i]);
		i++;
	}
	printf("#############################\n");

}

/* funkcia ktora mi hodnoty v poli zoradi*/
void zoradenie(int pole[])                                                                                              
{
	int j = 0;
	int n = 6;
	int i = 0;
	int p = 0;

	for (j = 0; j < n - 1; j++)
		for (i = j + 1; i < n; i++)
		{
			if (pole[i] < pole[j])
			{
				p = pole[i];
				pole[i] = pole[j];
				pole[j] = p;
			}
		}


}

/* funkcia ktora mi porovna hody kockou*/
int porovnanie_hodov(int hod_kockou_1[], int hod_kockou_2[])                    
{
	int status = 0;
	int i = 0;

	for (i = 0; i < MAX; i++)
	{
		if (hod_kockou_1[i] == hod_kockou_2[i])
		{
			status = status + 0;
		}
		else
		{
			status = status + 1;
		}
	}
	return status;
}
/*funkcia pre vsetky figury, ktora mi vrati status danej figury a na zaklade toho vyhodnotim pomocou podmienok o aku figuru ide*/
int figury(int hod_kockou[])
{
	int status = 0;
	int i = 0;
	int j = 0;

	for (j = 0; j<MAX - 1; j++)
		for (i = j + 1; i<MAX; i++)
		{
			if (hod_kockou[j] == hod_kockou[i])
			{
				status += 1;
			}
			else
			{
				status += 0;
			}
		}
	if (status == 6)
	{
		if (hod_kockou[2] == hod_kockou[3])
		{
			status = 6;										/* ak vyhodi status = 6 je to poker*/
		
		}
		else
		{
			status = 7;										/* ak vyhodi status 7 je to trojica */
		}
	}
	if (status == 3)
	{
		if (hod_kockou[0] == hod_kockou[1] && hod_kockou[2] == hod_kockou[3] && hod_kockou[4] == hod_kockou[5])					  /*osetrenie pre fiuru dvojica*/
		{
			status = 3;		 /*hodnota statusu = 3 je figura dvojica*/
		}
		else
		{
			status = 8;		  /*ak nepadne dvojica tak vypise hoci ake cislo si tu zadam, napr 8 cize ziadna figura*/
		}
	}
	return status;
}

 /*funkcia pre nahradny hod kockou ak nahodou nie som spokojny s prvym*/
int nahradny_hod_kockou(int hod_kockou_1[])
{
	int k = 0;
	int i;
	srand(time(0));

	/* cyklus for pre naplnenie pola hod_kockou_1 random hodnotami*/
	for (k = 0; k < MAX + 1; k++)                                                                  
	{
		hod_kockou_1[k] = rand() % 6 + 1;
	}
	printf("Nezoradeny nahradny hod kockami:\n");
	vypisanie(hod_kockou_1);

	zoradenie(hod_kockou_1);

	printf("Zoradeny nahradny hod kockami:\n");
	vypisanie(hod_kockou_1);

	i = figury(hod_kockou_1);

	/*figury pre nahradny hod*/
	if (i == 0)
	{
		printf("*****************\n");
		printf("*    POSTUPKA   *\n");
		printf("*****************\n");
		pocet_bodov(hod_kockou_1);
	
	}
	else if (i == 3)
	{
		printf("*****************\n");
		printf("*    DVOJICA    *\n");
		printf("*****************\n");
		pocet_bodov(hod_kockou_1);
	}
	else if (i == 6)
	{
		printf("*****************\n");
		printf("*     POKER     *\n");
		printf("*****************\n");
		pocet_bodov(hod_kockou_1);
	}
	else if (i == 7)
	{
		printf("*****************\n");
		printf("*    TROJICA    *\n");
		printf("*****************\n");
		pocet_bodov(hod_kockou_1);
	}
	else if (i == 10)
	{
		printf("*****************\n");
		printf("*     PENTA     *\n");
		printf("*****************\n");
		pocet_bodov(hod_kockou_1);
	}
	else if (i == 15)
	{
		printf("*****************\n");
		printf("*    GENERAL    *\n");
		printf("*****************\n");
		pocet_bodov(hod_kockou_1);
	}
	else
	{
		printf("ZIADNA PLATNA FIGURA !!\n");
		printf("Pocet bodov = **0**\n");

	}

	/*printf("status = %i\n", i);*/

	return 0;
}
/*koniec funkcie pre nahradny hod*/

/*funkcia na vypocet poctu bodov*/

int pocet_bodov(int hod_kockou_1[])
{
	
	int suma;
	int i = 0;
	
		suma = hod_kockou_1[0] + hod_kockou_1[1] + hod_kockou_1[2] + hod_kockou_1[3] + hod_kockou_1[4] + hod_kockou_1[5];		 /*suma urcuje vlastne spocitanie vsetkych hodnot v poli*/
		printf("Pocet bodov = **%i** \n", suma);																				/* vypisanie poctu bodov*/
	
	return 0;
} 
/*koniec funkcie pre pocet bodov*/

/*jedoducha funkcia na menu*/
int menu()
{
	int moznost = 0;

	printf("Pre hod kockami stlacte cislo *1* : ");						/*zvolenie moznosti */
	scanf_s("%i", &moznost);

	return 0;
}

 /*void na jednoduche vypisanie informacii o projekte*/
void about()
{
	printf("##########################\n");
	printf("#Zadanie : Kockova Hra   #\n");
	printf("#Autor\t : Michal Pessel #\n");
	printf("#Kruzok\t : RK 2          #\n");
	printf("##########################\n");
}
