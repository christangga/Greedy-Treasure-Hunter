/* 	File 	: mainfunction.h 
	Author 	: Jan Wira Gotama Putra (13512015), 
			  Christ Angga Saputra (13512019),
			  Ivana Clairine Irsan (13512041),
			  Kelas 01
*/

#ifndef MAINFUNCTION_H
#define MAINFUNCTION_H
#include "stdafx.h"
#include "Game.h"

typedef struct {
	string  *path;
	int 	*distance;
	int		*total_harta;
}Djikstra_MAP;

extern char Pita_Karakter[63];
extern ifstream fin;

extern Peti	*vertex;
extern int 	**Graf;
extern int 	JumlahWarna[3];
extern int	*LetakMerah, *LetakKuning, *LetakHijau;
extern int	skor_menang, waktu_main, n_simpul, modal, curr_vertex;
extern bool	random;

bool AllVertexVisited(bool const *flag, int const n_simpul);
void fungsi_seleksi_value(int** const Graf, Hunter AIHunter, Peti vertex, int *candidate, int *distance, int *maxvalue, int const i);
void fungsi_seleksi_distance(int** const Graf, Hunter AIHunter, Peti vertex, int *candidate, int *distance, int *maxvalue, int const i);
void ShortestPath(int ** const Graf, Djikstra_MAP *Out, int const n_simpul, int const curr_vertex, Peti harta[]);
int GetNextVertex(string path, int *i);
void Preparation();

#endif
