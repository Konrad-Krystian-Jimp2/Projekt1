#include <stdio.h>
#include <stdlib.h>


void Show_Error(int which_error){

	switch(which_error){
	   case 1 :
	      fprintf(stderr,"\tUzycie programu GrafExe: \n"
			     "/grafexe [ -h|--help ] | [ [-g nazwa_pliku  -p <r> -q <s>  -f  <k> -t  <l> [--bfs] [-n liczba_sciezek --file plikf]]\n"
			     "| [-r nazwa_pliku [ --bfs ] [-n liczba_sciezek --file plikf]  ] ] \n\n"
			     " -g inicjalizuje generowanie grafu\n"
			     " -p podajemy liczb� kolumn generowanego grafu\n"
			     " -q podajemy liczb� wierszy generowanego grafu\n"
			     " -f <k>  -t <l>  jest to przedzial <k,l> z ktorego losowane beda wagi przejsc miedzy wezlami\n"
			     " --bfs inicjalizuje BFS\n"
			     " -n  podajemy liczbe sciezek do wyszukania\n"
			     " --file podajemy plik z ktorego beda odczytywane dane odnosnie wyszukania sciezek\n"
			     " -r podajemy plik z grafem do wczytwania\n\n"
			     " \t Przykladowe uzycie: \n"
			     " $:  ./grafexe -g nazwapliku -p 2 -q 3 -f 1 -t 2 -n 1 --file plik_z_danymi \n\n"); 
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
	      fprintf(stderr,"Wprowadzono nieodpowiednia liczbe okreslajaca ilosc par, miedzy ktorymi wyznaczone beda sciezki\n");
	      exit(6);
	   break;
	   case 7 :
	      fprintf(stderr,"Wprowadzono niewlasciwa liczbe wyznaczajaca przedzial, z kt�rego losowane beda wagi\n");
	      exit(7);
	   break;
	   case 8 :
	      fprintf(stderr,"Brak przedzialu wagowego dla generowanego grafu\n");
	      exit(8);
	   break;
	 /*  case 9 :
	      fprintf(stderr,"Nie da sie znalezc jeden z podanych sciezek\n");
	      exit(9);
	*/

	   default:
	      fprintf(stderr, "error!\n");
	      exit(EXIT_FAILURE);
	}
}

