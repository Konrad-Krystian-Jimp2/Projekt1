#include <stdio.h>
#include <stdlib.h>


void Show_Error(int which_error){

	switch(which_error){
	   case 1 :
	      fprintf(stderr,"\tUzycie programu GrafExe: \n"
			     "/grafexe [ -h|--help ] | [ [-g nazwa_pliku  -w  <x>  -f  <k> -t  <l> [--bfs] [-n liczba_sciezek --file plikf]]\n"
			     "| [-r nazwa_pliku [ --bfs ] [-n liczba_sciezek --file plikf]  ] ] \n\n"
			     " -g inicjalizuje generowanie grafu\n"
			     " -w podajemy liczbe generowanych wezlow\n"
			     " -f <k>  -t <l>  jest to przedzial <k,l> z ktorego losowane beda wagi przejsc miedzy wezlami\n"
			     " --bfs inicjalizuje BFS\n"
			     " -n  podajemy liczbe sciezek do wyszukania\n"
			     " --file podajemy plik z ktorego beda odczytywane dane odnosnie wyszukania sciezek\n"
			     " -r podajemy plik z grafem do wczytwania\n\n"
			     " \t Przykladowe uzycie: \n"
			     " $:  ./grafexe -g -w 10 -f 1 -t 2 -n 1 --file plik_z_danymi \n\n"); 
	      exit(1);
	   break;
	   case 2 :
	      fprintf(stderr,"Wprowadzono niepoprawna liczbe wezlow\n");
	      exit(2);
	   break;
	   case 3 :
	      fprintf(stderr,"Podany przedzial <k;l> nie jest poprawny\n");
	      exit(3);
	   break;
	   case 4 :
	      fprintf(stderr,"Wprowadzono nieznana flage\n");
	      exit(4);
	   break;
	   case 5 :
	      fprintf(stderr,"Nie wprowadzono flagi -g, dlatego program nie utworzy grafu o okreslonych parametrach\n");
	      exit(5);
	   break;

 	   case 6 :
	      fprintf(stderr,"Wprowadzono nieodpowiednia liczbe okreslajaca ilosc par, miedzy ktorymi wyznaczone bedd sciezki\n");
	      exit(6);
	   break;
	   case 7 :
	      fprintf(stderr,"Wprowadzono niewlasciwa liczbe wyznaczajaca przedzial, z którego losowane beda wagi\n");
	      exit(7);
	   break;

	   default:
	      fprintf(stderr, "error!\n");
	      exit(EXIT_FAILURE);
	}
}

