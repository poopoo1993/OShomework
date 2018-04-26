#include "function.h"
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

 int main(void) {	
	string fileName = "output.txt";
	fout.open(fileName.c_str(),ios::out);
	//Q1 start
	fout<<"Q1 : bubble sort with single thread."<<endl;
	fileName = "input1";
	openFile(fileName);
	vector <int> data;
	readFile(data);
	bubbleSort(data);
	printData(data);
	data.clear();
	fin.close();
	fout<<"End of Q1"<<endl<<endl;
	//Q1 end

	//Q2 strat
	fout<<"Q2 : bubble sort with multi-thread (here is 10) and merge."<<endl;
	fileName = "input2";
	openFile(fileName);
	readFile(data);

	vector <int> *dividedData;
	int parts = 10;
	divideData(data, dividedData, parts);

	int *rc = new int[parts];
	pthread_t *thread = new pthread_t [parts];


	for (int i = 0; i < parts; i++) {
		rc[i] = pthread_create(&thread[i], NULL, threadFn, &dividedData[i]);
		if (rc[i] == 0) {
			cout << "Thread [" << i+1 << "] is created." << endl;
		}
	}
	
	for (int i = 0; i < parts; i++) {
		pthread_join(thread[i], NULL);
	}

	mergeSort(dividedData, data, parts);
	printData(data);
	data.clear();
	for(int i = 0; i < parts; i++){
		dividedData[i].clear();
	}
	fin.close();
	fout<<"End of Q2"<<endl<<endl;
	//Q2 end

	/*Q3
	string fileName;
	openFile(fileName);
	vector <int> data;
	readFile(data);
	vector <int> *dividedData;
	int parts;
	divideData(data, dividedData, parts);
	int* status = 0;
	pid_t *pid=new pid_t[parts];	

	for (int i = 0; i < parts; i++) {
		vector<int> *v;
		v = &dividedData[i];
		pid[i] = fork();
		if (pid[i] == 0) {
			cout<<"this is child process NO."<<i+1<<"."<<endl;
			bubbleSort(*v);
			printData(*v);
			write(*v,dividedData[i],sizeof(dividedData[i]));
			exit(0);
			
		}
	}

	sleep(5);
	
	mergeSort(dividedData,data,parts);
	printData(data);
	*/
	
	//Q4 start
	fout<<"Q4 : divide data by 10 parts, bubble sort for each, and merge."<<endl;
	fileName = "input4";
	openFile(fileName);
	readFile(data);

	divideData(data, dividedData, parts);
	for (int i = 0; i < parts; i++) {
		bubbleSort(dividedData[i]);
	}
	mergeSort(dividedData, data, parts);
	printData(data);
	fin.close();
	fout<<"End of Q4."<<endl<<endl;
	//Q4 end


	//fout execute time to output.
}
