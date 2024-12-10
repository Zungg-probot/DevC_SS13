#include<stdio.h>
int array(int a, int b){
	int array[a][b];
	int n;
	for(int i =0;i<a;i++){
		for(int j=0;j<b;j++){
			printf("array[%d][%d]=",i,j);
			scanf("%d",&n);
			array[i][j]=n;
		}
	}
	for(int i =0;i<a;i++){
		for(int j=0;j<b;j++){
			printf("%d \t",array[i][j]);
		}
		printf("\n \n");
	}
	return n;
}
int main(){
	array(3,4);
	return 0;
}
