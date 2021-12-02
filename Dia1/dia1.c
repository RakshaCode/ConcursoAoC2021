#include<stdio.h>
#include<stdlib.h>

#define MAX_LINE 50
int main(int argc, char **argv) {

	char line[MAX_LINE];
	int prev_value, value, num_values, incr;
	FILE *fd;

	prev_value = value = num_values = incr = 0;


	if(argc !=2) {
		perror("Error en el número de argumentos.\n");
		perror("Uso: dia1 <archivo>\n");
		exit(1);
	}

	if(!(fd = fopen(argv[1], "r"))) {
		perror("Error al abrir el fichero.\n");
		exit(1);
	}

	while((fgets(line, MAX_LINE, fd))){
		value = atoi(line);
		//The fist case is not consider neither a increment or a decrement
		if(num_values && (prev_value < value)){
			++incr;
		}
		++num_values;
		prev_value = value;
	}

	fclose(fd);
	printf("Lineas: %i\n",num_values);
	printf("Incrementos: %i\n",incr);

	return 0;
}
