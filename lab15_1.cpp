#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[N] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,result,N,M);
	showData(result,N,1);
}

//Write definition of randData(), showData() and findRowSum()
void randData(double *dPtr,int N,int M){
	double value;
	for(int i=0;i<N*M;i++){
		value = (rand()%101)/100.0;
		*(dPtr+i)=value;
	}
}

void showData(double *dPtr,int N,int M){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout << fixed << setprecision(2);
			cout << *(dPtr+i+(j*7)) << " ";
		}
		cout << "\n";
	}
}

void findRowSum(const double *dPtr,double *result,int N,int M){
	double sum=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			sum+=*(dPtr+(i*7)+j);
		}
		result[i]=sum;
		sum=0;
	}
}