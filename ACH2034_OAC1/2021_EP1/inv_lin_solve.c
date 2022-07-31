#include <stdio.h>
#define true 1
#define false 0

typedef int bool;

//Calcula o determinante
float determinante(float matriz[3][3]){
	float det;
	float det_pos;
	float det_neg;
	det_pos = (matriz[0][0] * matriz[1][1] * matriz[2][2]) + (matriz[0][1]*matriz[1][2]*matriz[2][0])+ (matriz[0][2]*matriz[1][0]*matriz[2][1]);
	det_neg = (matriz[0][2] * matriz[1][1] * matriz[2][0]) + (matriz[0][1]*matriz[1][0]*matriz[2][2]) + (matriz[0][0]*matriz[1][2]*matriz[2][1]);
	det = (det_pos - det_neg);
	return det;
}

void resolve(float matriz[3][3], float matriz_Y[3], int det){
	int i = 0;
	int j = 0;
	float matriz_a[3][3];
	float matriz_inv[3][3];
	float resp[] = {0,0,0};
	//Calculo dos cofatores:
	matriz_a[0][0] = (((matriz[1][1]*matriz[2][2]) - (matriz[1][2]*matriz[2][1])));
	matriz_a[0][1] = (-1)*((matriz[1][0]*matriz[2][2]) - (matriz[1][2]*matriz[2][0]));
	matriz_a[0][2] = (((matriz[1][0]*matriz[2][1]) - (matriz[1][1]*matriz[2][0])));
	matriz_a[1][0] = ((-1)*((matriz[0][1]*matriz[2][2]) - (matriz[0][2]*matriz[2][1])));
	matriz_a[1][1] = (((matriz[0][0]*matriz[2][2]) - (matriz[0][2]*matriz[2][0])));
	matriz_a[1][2] = ((-1)*((matriz[0][0]*matriz[2][1]) - (matriz[0][1]*matriz[2][0])));
	matriz_a[2][0] = (((matriz[0][1]*matriz[1][2]) - (matriz[0][2]*matriz[1][1])));
	matriz_a[2][1] = ((-1)*(((matriz[0][0]*matriz[1][2]) - (matriz[0][2]*matriz[1][0]))));
	matriz_a[2][2] = ((matriz[0][0]*matriz[1][1]) - (matriz[0][1]*matriz[1][0]));

	//transpoe matriz e divide pelo determinante
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			matriz_inv[i][j] = (matriz_a[j][i]/det);
		}
	}

	//multiplica matrizes

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			resp[i] += matriz_inv[i][j] * matriz_Y[j];
		}
	}

	printf("x: %f\n", resp[0]);
	printf("y: %f\n", resp[1]);
	printf("z: %f\n", resp[2]);
}


int main(){

	float matriz_A[3][3];
	float matriz_Y[3];
	int i;
	int j;
	float d;
	//Entrada dos dados pelo usuario
	printf("Escolha os elementos da matriz A de ordem 3X3:\n");
	for(i = 0; i < 3; i ++){
		for(j = 0; j < 3; j++){
			printf("Posicao %d %d \n", i, j);
			scanf("%f", &matriz_A[i][j]);
		}
	}
	printf("Escolha os elementos da matriz y:\n");
	for(i = 0; i < 3; i ++){
			printf("Posicao %d \n", i);
			scanf("%f", &matriz_Y[i]);
	}
	//calcula o determinante principal
	d = determinante(matriz_A);
	//testa invertibilidade
	if(d) resolve(matriz_A, matriz_Y, d);
	else printf("O determinante e zero.\n");

	return 0;
}
