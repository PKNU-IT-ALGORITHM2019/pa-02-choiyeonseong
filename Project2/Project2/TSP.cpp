#pragma warning (disable:4996)
#include<stdio.h>
#include<math.h>
#define Max 20

typedef struct point {	//지나는 장소의 좌표
	int x;
	int y;
}Point;

Point spot[Max];

int N;	//지나는 장소의 개수
int order[Max];	//순서를 저장하는 배열
int k = 0;
double length[][Max] = { 0 };
double sum;
double min = 987654321;
int minpath[Max];


void TSP(int *order, int k);
void swap(int data[], int a, int b);
double getDistance(Point a, Point b);	//구조체를 받아서 거리반환
void readFile(void);


int main(void) {
	readFile();
	TSP(order, 0);
	
	for (int i = 0; i < N; i++)
		printf("%d ", minpath[i]);
	printf("최단경로:%lf\n", min);
	
}


void readFile(void) {


	FILE *fp = fopen("input3.txt", "r");

	fscanf(fp, "%d", &N);

	for (int i = 0; i < N; i++)
	{
		fscanf(fp, "%d %d", &spot[i].x, &spot[i].y);
		order[i] = i;
	}

	fclose(fp);

	for (int i = 0; i < N; i++) {
		printf("(%d, %d)\n", spot[i].x, spot[i].y);
	}
}


void TSP(int *order, int k) {
	int m = 0;
	if (k == N) {
		int i = 0;
		for (i = 0; i < N; i++) {
			if (i == N - 1)
				sum += getDistance(spot[order[i]], spot[order[0]]);
			else
				sum += getDistance(spot[order[i]], spot[order[i + 1]]);

		}
		if (min > sum) {
			min = sum;
			for (int a = 0; a < N; a++) {
				minpath[a] = order[a];
			}
		}
		sum = 0;
		return;
	}

	else {
		for (int i = k; i < N; i++) {
			swap(order, k, i);
			TSP(order, k + 1);
			swap(order, k, i);
		}
	}
}


void swap(int data[], int a, int b) {
	int p = data[a];
	data[a] = data[b];
	data[b] = p;

}



double getDistance(Point a, Point b) {	//구조체를 받아서 거리반환
	return sqrt(pow(abs(a.x - b.x),2) + pow(abs(a.y - b.y),2));
}




