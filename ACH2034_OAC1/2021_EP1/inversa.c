#include <stdio.h>
#define true 1
#define false 0

typedef int bool;

//Calcula o determinante e testa invetibilidade
bool eh_inversivel(float matriz[3][3], float* det){
	int det_pos = 0;
	int det_neg = 0;
	det_pos = (matriz[0][0] * matriz[1][1] * matriz[2][2]) + (matriz[0][1]*matriz[1][2]*matriz[2][0])+ (matriz[0][2]*matriz[1][0]*matriz[2][1]);
	det_neg = (matriz[0][2] * matriz[1][1] * matriz[2][0]) + (matriz[0][1]*matriz[1][0]*matriz[2][2]) + (matriz[0][0]*matriz[1][2]*matriz[2][1]);
	*det = (det_pos - det_neg);
	printf("Det: %f\n", *det);
	if((*det) !=0) return true;
	return false;
}

void matriz_inversa(float matriz[3][3]){
	int i = 0;
	int j = 0;
	float matriz_a[3][3];
	float matriz_inv[3][3];
	float det;
	if(!(eh_inversivel(matriz, &det))) return;
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
			printf("%f", matriz_inv[i][j]);
		}
		printf("\n");
	}

}

int main(){
	printf("Escolha os elementos da matriz de ordem 3X3:\n");
	float matriz[3][3];
	int i;
	int j;
	//Entrada dos dados pelo usuario
	for(i = 0; i < 3; i ++){
		for(j = 0; j < 3; j++){
			printf("Posicao %d %d: ", i, j);
			scanf("%f", &matriz[i][j]);
		}
	}
	//Calculo da matriz inversa
  matriz_inversa(matriz);
	return 0;
}
