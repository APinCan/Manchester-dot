#include "DifManEncoder.h"

DifManEncoder::DifManEncoder()
{
}

DifManEncoder::~DifManEncoder()
{
}

DifManEncoder::DifManEncoder(string codeOrigin)
{
	this->codeOrigin = codeOrigin;
}

void DifManEncoder::bitLoop()
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

void DifManEncoder::zeroToBit(int index)
{
	//이전코드가 1이면 01
	//이전코드가 0이면 10
	int beforeBit = codeOutput.length() - 1;

	if (codeOutput == "") {
		codeOutput += "10";
		upTransition(0);
	}
	else if(codeOutput.at(beforeBit)=='0') {
		codeOutput += "10";
		upTransition(index);
		addClock(index);
	}
	else {
		codeOutput += "01";
		downTransition(index);
		addClock(index);
	}
}

void DifManEncoder::oneToBit(int index)
{
	//이전코듣가 0이면 01
	//이전코드가 1이면 10
	int beforeBit = codeOutput.length()-1;
	
	if (codeOutput == "") {
		codeOutput += "01";
		downTransition(0);

	}
	else if (codeOutput.at(beforeBit) == '0') {
		codeOutput += "01";
		downTransition(index);
	}
	else {
		codeOutput += "10";
		upTransition(index);
	}
}

void DifManEncoder::downTransition(int index)
{
	outputArray[0][index] = "----   ";
	outputArray[1][index] = "   |   ";
	outputArray[2][index] = "   |   ";
	outputArray[3][index] = "   ----";
}

void DifManEncoder::upTransition(int index)
{
	outputArray[0][index] = "   ----";
	outputArray[1][index] = "   |   ";
	outputArray[2][index] = "   |   ";
	outputArray[3][index] = "----   ";
}

void DifManEncoder::addClock(int index)
{
	outputArray[1][index] = "|  |   ";
	outputArray[2][index] = "|  |   ";
}

string DifManEncoder::getEncodedCode()
{
	return codeOutput;
}

void DifManEncoder::showEncodedData()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 15; j++) {
			cout << outputArray[i][j];
		}
		cout << endl;
	}
}
