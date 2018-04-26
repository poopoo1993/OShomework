#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <pthread.h>

using namespace std;

fstream fin;
fstream fout;


void openFile(string fileName) {
	fileName = fileName + ".txt";
	fin.open(fileName.c_str(), ios::in);
	int i;
	fin >> i;
}

void readFile(vector <int> &data) {
	int temp;
	while (!fin.eof()) {
		fin >> temp;
		data.push_back(temp);
	}
}

void printData(vector <int> data) {

	for (int i = 0; i < data.size(); i++) {
		fout << data[i] << " ";
	}

}

void bubbleSort(vector <int> &data) {

	int n = data.size() - 1;

	for (int i = n; i > 1; i--) {
		for (int j = 0; j < i; j++) {

			if (data[j] < data[j + 1]) {
				swap(data[j], data[j + 1]);
			}

		}
	}

}

void divideData(vector <int> data, vector <int> *&dividedData, int parts) {

	int divideIndex;
	divideIndex = data.size() / parts;
	dividedData = new vector<int>[parts];

	for (int i = 0; i < parts; i++) {
 
		for (int j = divideIndex * i; j < divideIndex*(i + 1); j++) {

			if (i == parts - 1) {
				for (int k = divideIndex * i; k < data.size(); k++) {
					dividedData[i].push_back(data[k]);
				}
				break;
			}

			dividedData[i].push_back(data[j]);

		}

	}

}

void mergeSort(vector <int> *&dividedData, vector <int> &data, int parts) {
	
	data.clear();

	while (1) {
		
		int temp = -1;
		int tempPos = -1;

		for (int i = 0; i < parts; i++) {
			
			if (dividedData[i].size() != 0 && dividedData[i].front() > temp) {
				temp = dividedData[i].front();
				tempPos = i;
			}

		}
		
		if (temp == -1) {
			return;
		}

		data.push_back(dividedData[tempPos].front());
		dividedData[tempPos].erase(dividedData[tempPos].begin());

	}

}

void* threadFn(void* arg) {

	vector <int> *v = static_cast<vector<int>*>(arg);
	bubbleSort(*v);
	return NULL;

}
