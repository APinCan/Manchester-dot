#pragma once
#include<string>
#include<iostream>

using namespace std;

class DifManEncoder
{
private:
	string codeOrigin;
	string codeOutput;
	string outputArray[4][100];

public:
	DifManEncoder();
	~DifManEncoder();
	DifManEncoder(string);
	void bitLoop();
	void zeroToBit(int);
	void oneToBit(int);
	void downTransition(int);
	void upTransition(int);
	void addClock(int);
	string getEncodedCode();
	void showEncodedData();
};

