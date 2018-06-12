#include <omp.h>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

int main(){

	#pragma omp parallel
	cout<<"Hell"<<endl;


	int popitok=10E7;
	int papodaniy=0;

	cout<<"Single sream"<<endl;
	unsigned int start_time=clock();
	for(int i=0; i<popitok; i++){
		double randX=(double)rand()/(double)RAND_MAX;
		double randY=(double)rand()/(double)RAND_MAX;

		if((pow(randX, 2)+pow(randY, 2))<=1){
			papodaniy++;
		}
	}
	double pi1=4.0*(double)papodaniy/(double)popitok;	
	unsigned int stop_time=clock();
	cout<<pi1<<" "<<stop_time-start_time<<endl;

	cout<<"\n\nMulti sream"<<endl;	
	papodaniy=0;
	start_time=clock();
	#pragma omp parallel for
	for(int i=0; i<popitok; i++){
		double randX=(double)rand()/(double)RAND_MAX;
		double randY=(double)rand()/(double)RAND_MAX;

		if((pow(randX, 2)+pow(randY, 2))<=1){
			papodaniy++;
		}
	}
	double pi2=4.0*(double)papodaniy/(double)popitok;
	stop_time=clock();
	cout<<pi2<<" "<<stop_time-start_time<<endl;

	return 0;
}
