#include <stdio.h>
#include <stdlib.h>

#define NMAX 100000
#define NMIN 1

int main()
{
	unsigned N, i, *v, nr, poz, j;

	FILE *fin = fopen("carti1.in", "r");

	if (!fin) { printf("Eroare carti1.in\n"); return 1; }

	fscanf(fin, "%u", &N);

	if (N < NMIN || N > NMAX) { printf("Eroare valoare N\n"); return 2; }

	v = (unsigned*)malloc(N*sizeof(unsigned));

	for (i = 0; i < N; i++) {
		fscanf(fin, "%u", &v[i]);

		if (v[i] < NMIN || v[i] > NMAX) { printf("Eroare valoare v[i]\n"); return 3; }
	}
	
	fclose(fin);

	for (nr = poz = 0, i = 1; i <= N;) {
		for (j = poz; j < N && v[j] != i; j++);
	
		if (j < N) poz = j+1, i++;
		else poz = 0, nr++;
	}	

	free(v);

	FILE *fout = fopen("carti1.out", "w");

	fprintf(fout, "%u", nr);

	fclose(fout);
	
	return 0;
}
// scor 40
