#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

int main(){
	
	string fileName;
	int outputAmount;
	
	cout<<"Enter the name of output file :"<<endl;
	cin>>fileName;
	cout<<"Enter how many number would like to output :"<<endl;
	cin>>outputAmount;
	fstream fout;
	fout.open(fileName+".txt",ios::out);
	
	srand(time(NULL));
	
	for(int i = 0; i < outputAmount; i++){
		int randomNum = rand()%10000;
		fout<<randomNum<<" ";
	}
	
	fout.close();
}
