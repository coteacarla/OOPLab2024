#pragma once

class Student {
private:
	char name[255];
	float m;
	float e;
	float h;
	float avr;
public:
	char* GetName();//afisez
	char SetName(const char* s);
	float GetMath();//mate
	void SetMath(float x);
	float GetEng();//eng
	void SetEng(float x);
	float GetHistory();//ist
	void SetHistory(float x);
	void SetAvg();//afisez avg
	float GetAvg();

};

