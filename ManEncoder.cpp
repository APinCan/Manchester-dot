#include "ManEncoder.h"



ManEncoder::ManEncoder()
{
}


ManEncoder::~ManEncoder()
{
}

ManEncoder::ManEncoder(string codeOrigin)
{
	this->codeOrigin = codeOrigin;
}

void ManEncoder::bitLoop()
{
	for (int i = 0; i < codeOrigin.length(); i++) {
		if (codeOrigin.at(i) == '0') {
			zeroToBit(i);
		}
		else {
			oneToBit(i);
		}
	}
}

void ManEncoder::zeroToBit(int index)
{
	if (codeOutput == "") {
		downTransition(0);
	}
	else if (codeOrigin.at(index - 1) == '0') {
		downTransition(index);
		addClock(index);
	}
	else {
		downTransition(index);
	}
	codeOutput += "01";
}

void ManEncoder::oneToBit(int index)
{
	if (codeOutput == "") {
		upTransition(0);
	}
	else if (codeOrigin.at(index - 1) == '1') {
		upTransition(index);
		addClock(index);
	}
	else {
		upTransition(index);
	}
	codeOutput += "10";
}

void ManEncoder::downTransition(int index)
{
	outputArray[0][index] = "----   ";
	outputArray[1][index] = "   |   ";
	outputArray[2][index] = "   |   ";
	outputArray[3][index] = "   ----";
}

void ManEncoder::upTransition(int index)
{
	outputArray[0][index] = "   ----";
	outputArray[1][index] = "   |   ";
	outputArray[2][index] = "   |   ";
	outputArray[3][index] = "----   ";
}

void ManEncoder::addClock(int index)
{
	outputArray[1][index]= "|  |   ";
	outputArray[2][index]= "|  |   ";
}

string ManEncoder::getEncodedCode()
{
	return codeOutput;
}

void ManEncoder::showEncodedData()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 15; j++) {
			cout << outputArray[i][j];
		}
		cout << endl;
	}
}
