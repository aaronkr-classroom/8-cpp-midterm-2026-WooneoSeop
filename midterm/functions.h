#pragma once
// functions_h

#ifndef GUARD_functions_h
#define GUARD_functions_h

#include <vector>
#include <iostream>
#include <string>


using namespace std;

// 구조체
struct Student_info {
	// 속성
	string name; // 학생 이름
	vector<double> scores;; // 중간고사 기말고사
	
};

double calculateAverage(const vector<double>&);
bool compare(const Student_info&, const Student_info&); // 이름 비교하기



#endif
