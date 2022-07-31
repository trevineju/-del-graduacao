#include <iostream>
#include <stdio.h>
using namespace std;

bool eh_quadrada(float matriz[3][3], int i, int j){

	if(i == j){
		return true;
	}
	else
		return false;

}

bool eh_inversivel(float matriz[3][3], float* det){//determinante igual a zero?
	int det_pos = 0;
	int det_neg = 0;
	*det = 0;
	int i = 0;
	int j = 0;
	//for(i = 0; i < 3; i ++){
	//	for(j = 0; j < 5; j++){
	//		if(j < 3){
    //           matriz_det[i][j] = matriz[i][j];
    //      }
    //        else if (j == 3){
    //            matriz_det[i][j] = matriz[i][j];
    //        }
    //        else if(j == 4){
    //           matriz_det[i][j] = matriz[i][j];
    //        }
	//	}
	//}
	i = 0;
	j = 0;
    printf("%f", matriz[0][0]);
	det_pos = (matriz[0][0] * matriz[1][1] * matriz[2][2]) + (matriz[0][1]*matriz[1][2]*matriz[2][0])+ (matriz[0][2]*matriz[1][0]*matriz[2][1]);
	det_neg = (matriz[0][2] * matriz[1][1] * matriz[2][0]) + (matriz[0][1]*matriz[1][0]*matriz[2][2]) + (matriz[0][0]*matriz[1][2]*matriz[2][1]);
	//printf("%f %f\n", det_pos, det_neg);
	*det = (det_pos - det_neg);
	printf("Det: %f\n", det);
	if((*det)!=0){
		return true;
	}
	else
		return false;

}

void imprimir_matriz(float matriz[3][3]){
	int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			 printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void matriz_inversa(float matriz[3][3], float det){
	if((!eh_quadrada(matriz, 3, 3)||!(eh_inversivel(matriz, &det)))){
		return;
	}
	//Calculo dos cofatores:
	//matrizes
	//transpoe
	//divide todos pelo determinante
	int i = 0;
	int j = 0;
	float matriz_a[3][3];
	matriz_a[0][0] = (((matriz[1][1]*matriz[2][2]) - (matriz[1][2]*matriz[2][1])));
	matriz_a[0][1] = (-1)*((matriz[1][0]*matriz[2][2]) - (matriz[1][2]*matriz[2][0]));
	matriz_a[0][2] = (((matriz[1][0]*matriz[2][1]) - (matriz[1][1]*matriz[2][0])));
	matriz_a[1][0] = ((-1)*((matriz[0][1]*matriz[2][2]) - (matriz[0][2]*matriz[2][1])));
	matriz_a[1][1] = (((matriz[0][0]*matriz[2][2]) - (matriz[0][2]*matriz[2][0])));
	matriz_a[1][2] = ((-1)*((matriz[0][0]*matriz[2][1]) - (matriz[0][1]*matriz[2][0])));
	matriz_a[2][0] = (((matriz[0][1]*matriz[1][2]) - (matriz[0][2]*matriz[1][1])));
	matriz_a[2][1] = ((-1)*(((matriz[0][0]*matriz[1][2]) - (matriz[0][2]*matriz[1][0]))));
	matriz_a[2][2] = ((matriz[0][0]*matriz[1][1]) - (matriz[0][1]*matriz[1][0]));
	//matriz transposta
	//imprimir_matriz(matriz_a);
	float matriz_inv[3][3];
	matriz_inv[0][0] = matriz_a[0][0];
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			matriz_inv[i][j] = (matriz_a[j][i]/det);
			printf("%f", matriz_inv[i][j]);
		}
		printf("\n");
	}

	//imprimir_matriz(matriz_inv);
}

int main(){
	printf("Escolha os elementos da matriz de ordem 3X3:");
	float matriz[3][3];
	int i;
	int j;
	for(i = 0; i < 3; i ++){
		for(j = 0; j < 3; j++){
			printf("Posição %d %d:", i, j);
			scanf("%f", &matriz[i][j]);
		}
	}

	float det_pos = 1;
	float det_neg = 1;
	i = 0;
	j = 0;
    //printf("%f", (matriz[0][0] * matriz[1][1] * matriz[2][2])+(matriz[0][1]*matriz[1][2]*matriz[2][0])+(matriz[0][2]*matriz[1][0]*matriz[2][1]));
	//printf("%f", (matriz[0][2] * matriz[1][1] * matriz[2][0]) + (matriz[0][1]*matriz[1][0]*matriz[2][2]) + (matriz[0][0]*matriz[1][2]*matriz[2][1]));
	//det_pos = (matriz[0][0] * matriz[1][1] * matriz[2][2]) + (matriz[0][1]*matriz[1][2]*matriz[2][0])+ (matriz[0][2]*matriz[1][0]*matriz[2][1]);
	//det_neg = (matriz[0][2] * matriz[1][1] * matriz[2][0]) + (matriz[0][1]*matriz[1][0]*matriz[2][2]) + (matriz[0][0]*matriz[1][2]*matriz[2][1]);
	//printf("%f %f\n", det_pos, det_neg);
	//float det = (det_pos - det_neg);
	//printf("Det: %f\n", det);
	//if((det)==0){
	//	printf("Nao eh possivel inverter essa matriz", det_pos, det_neg);
	//}
	//else{
	float det;
        matriz_inversa(matriz, det);
	//}


}
