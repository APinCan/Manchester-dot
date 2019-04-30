#include<iostream>
#include<string>
#include"DifManEncoder.h"
#include"ManEncoder.h"

using namespace std;

void main() {
	string codeOrigin;

	cout << "origin code: ";
	cin >> codeOrigin;
	cout << "\ncode Encoding..." << endl;
	cout << "Original Code : " << codeOrigin << endl;

	ManEncoder manEncoder(codeOrigin);
	manEncoder.bitLoop();
	cout << "-- Manchester Encoding --\n" << manEncoder.getEncodedCode() << endl;
	manEncoder.showEncodedData();

	DifManEncoder difManEncoder(codeOrigin);
	difManEncoder.bitLoop();
	cout << "-- Diffential Manchester Encoding --\n" << difManEncoder.getEncodedCode() << endl;
	difManEncoder.showEncodedData();

	system("pause");
}