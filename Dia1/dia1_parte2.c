#include<stdio.h>
#include<stdlib.h>

#define MAX_LINE 50

int main(int argc, char **argv) {
	char line[MAX_LINE];
	int value[4], n_lines, incr, num;
	FILE *fd;

	n_lines = incr = num = 0;

	if(argc !=2) {
		perror("Error en el número de argumentos.\n");
		perror("Uso: dia1 <archivo>\n");
		return 1;
	}

	if(!(fd = fopen(argv[1], "r"))) {
		perror("Error al abrir el fichero.\n");
		return 1;
	}

	while(fgets(line, MAX_LINE, fd)){
		num = atoi(line);
		value[(n_lines + 0) % 4] = num;
		// value[(n_lines + 1) % 4] += num;
		value[(n_lines + 2) % 4] += num;
		value[(n_lines + 3) % 4] += num;
		if ((n_lines >= 3) &&
				(value[(n_lines + 1) % 4]) < (value[(n_lines + 2) % 4])) {
				++incr;
		}
		++n_lines;
	}

	printf("Lineas: %i\n",n_lines);
	printf("Incrementos (con ruido): %i\n", incr);

	return 0;
}
