#include <stdio.h>
#include <stdlib.h>

#define NMAX 100000
#define NMIN 1

int main()
{
	unsigned N, *poz, i, x, nr;

	FILE *fin = fopen("carti1.in", "r");

	if (!fin) { printf("Eroare carti1.in\n"); return 1; }

	fscanf(fin, "%u", &N);

	if (N < NMIN || N > NMAX) { printf("Eroare valoare N\n"); return 2; }

	poz = (unsigned*)malloc(N*sizeof(unsigned));

	for (i = 0; i < N; i++) {
		fscanf(fin, "%u", &x);

		if (x < NMIN || x > NMAX) { printf("Eroare valoare x\n"); return 3; }

		poz[x-1] = i;
	}
	
	fclose(fin);

	for (nr = 0, i = 1; i < N; i++)
		if (poz[i] < poz[i-1]) nr++;

	free(poz);

	FILE *fout = fopen("carti1.out", "w");

	fprintf(fout, "%u", nr);

	fclose(fout);
	
	return 0;
}
// scor 100
