#include "function.h"
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h> //fork
#include <ctime> //time

 int main(void) {	
	string fileName = "output.txt";
	fout.open(fileName.c_str(),ios::out);
	clock_t start, stop;

	//Q1 start
	fout<<"Q1 : bubble sort with single thread."<<endl;
	fileName = "input1";
	openFile(fileName);
	vector <int> data;
	readFile(data);
	start = clock();//timer start
	bubbleSort(data);
	stop = clock();//timer stop
	printData(data);
	data.clear();
	fin.close();
	fout<<"End of Q1"<<endl<<endl;
	double timeforQ1 = (stop-start) / CLOCKS_PER_SEC;
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

	start = clock();//timer start
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
	stop = clock();//timer stop
	printData(data);
	data.clear();
	for(int i = 0; i < parts; i++){
		dividedData[i].clear();
	}
	fin.close();
	fout<<"End of Q2"<<endl<<endl;
	double timeforQ2 = (stop-start) / CLOCKS_PER_SEC;
	//Q2 end

	/*Q3
	string fileName = "input3";
	openFile(fileName);
	readFile(data);

	divideData(data, dividedData, parts);
	int* status = 0;
	pid_t *pid=new pid_t[parts];	
	start = clock();
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

	//wait all child process to end.
	mergeSort(dividedData,data,parts);
	stop = clock();
	printData(data);
	data.clear();
        for(int i = 0; i < parts; i++){
                dividedData[i].clear();
        }
        fin.close();
        fout<<"End of Q3"<<endl<<endl;
        double timeforQ3 = (stop-start) / CLOCKS_PER_SEC;	
	*/
	
	//Q4 start
	fout<<"Q4 : divide data by 10 parts, bubble sort for each, and merge."<<endl;
	fileName = "input4";
	openFile(fileName);
	readFile(data);

	divideData(data, dividedData, parts);
	start = clock();//timer start
	for (int i = 0; i < parts; i++) {
		bubbleSort(dividedData[i]);
	}
	mergeSort(dividedData, data, parts);
	stop = clock();//timer stop
	printData(data);
	fin.close();
	fout<<"End of Q4."<<endl<<endl;
	double timeforQ4 = (stop-start) / CLOCKS_PER_SEC; 
	//Q4 end

	fout<<"Execute time :"<<endl;
	fout<<"Q1 : "<<timeforQ1<<endl;
	fout<<"Q2 : "<<timeforQ2<<endl;
	//fout<<"Q3 : "<<timeforQ3<<endl;
	fout<<"Q4 : "<<timeforQ4<<endl;
	
}	
