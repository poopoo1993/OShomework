#include "function.h"
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

 int main(void) {
	/*Q1
	string fileName;
	openFile(fileName);
	vector <int> data;
	readFile(data);
	bubbleSort(data);
	printData(data);
	*/
	/*Q2
	string fileName;
	openFile(fileName);
	vector <int> data;
	readFile(data);

	vector <int> *dividedData;
	int parts;
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
	*/
	///*Q3
	string fileName;
	openFile(fileName);
	vector <int> data;
	readFile(data);
	vector <int> *dividedData;
	int parts;
	divideData(data, dividedData, parts);
	int* status = 0;
	pid_t pid;
	for (int i = 0; i < parts; i++) {
		vector<int> *v;
		v = &dividedData[i];
		pid = fork();
		if (pid == 0) {
			bubbleSort(*v);
			printData(*v);
			exit(0);
		}
	}
	do{
		pid = waitpid(pid, &status, 0);
	}while(pid == 0);
	mergeSort(dividedData,data,parts);
	printData(data);
	//*/

	/*Q4
	string fileName;
	openFile(fileName);
	vector <int> data;
	readFile(data);

	vector <int> *dividedData;
	int parts;

	divideData(data, dividedData, parts);
	for (int i = 0; i < parts; i++) {
		bubbleSort(dividedData[i]);
	}
	mergeSort(dividedData, data, parts);
	printData(data);
	*/

}
