#include "gauss.h"
#include <math.h>


/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	//int row=0; // obecny wiersz
    /**
	 * dla kazdej kolumny szukamy najwiekszej liczby,
	 *  zamieniamy jej wiersz z obecnym wierszem
	 * 
	*/
	for (int c = 0; c< mat->r-1; c++){
		int biggest = c; // wiersz zawierajacy najwiekszy abs numer w tej kolumnie
		for ( int i = c+1; i< mat->r; i++){
			biggest =fabs(mat->data[i][c]) > fabs(mat->data[biggest][c]) ?  i : biggest;
		}
		// podmieniamy wiersze aktualny z biggest
		if(biggest != c){
			for (int j =0; j<mat->c; j++){
				double temp = mat->data[c][j];
				mat->data[c][j] = mat->data[biggest][j];
				mat->data[biggest][j] = temp;
			}
			double temp = b->data[c][0];
			b->data[c][0] = b->data[biggest][0];
			b->data[biggest][0] = temp;
		}
		for ( int i = c; i< mat->r-1; i++){
			double multiplier = mat->data[i+1][c] / mat->data[c][c];
			//mnozymy cały rzad + prawa strone rownania
			for (int j =0; j<mat->c; j++){
				mat->data[i+1][j]-=mat->data[c][j] * multiplier;
			}
			b->data[i+1][0]-=b->data[c][0] * multiplier;
		}
	}

	return 0;
}


