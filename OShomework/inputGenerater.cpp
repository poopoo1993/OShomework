#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

int main(){
	
	string fileName = "input";
	int outputAmount;
	
	cout<<"Enter how many number would like to output :"<<endl;
	cin>>outputAmount;
	fstream fout;
	
	for(int i = 0; i < 4; i++){
		string i_str = to_string(i+1);
		fileName = fileName + string(i_str);
		fout.open(fileName+".txt",ios::out);
		srand(time(NULL));
		fout<<i+1;
		for(int j = 0; j < outputAmount; j++){
			int randomNum = rand()%10000;
			fout<<randomNum<<" ";
		}
		fout.close();
		fileName = "input";
	}

}
