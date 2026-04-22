// main.cpp

#include <iostream>
#include <ios>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "functions.h"

using namespace std;

typedef vector <double> ::size_type vec_sz;
typedef vector<Student_info>::size_type si_sz;




int main() {

	string::size_type maxlen = 0;
	vector <Student_info> students;
	


	cout << "Enter number of students : ";
	int a = 0;
	cin >> a;

	// 학생 수 입력 받기
	for (int i = 1; i <= a; i++) {
		Student_info record;
		cout << endl;
		cout << "== Student " << i << " ==" << endl;
		cout << "Enter name : ";
		cin >> record.name;

		cout << "Enter 3 scores : ";
		for(int j=0; j< 3; j++){
			double score;
			cin >> score;
			record.scores.push_back(score);
		}
		students.push_back(record);
		maxlen = std::max(maxlen, record.name.size());
		
	}

	// 학생 정보를 알파벳 순으로 정렬
	sort(students.begin(), students.end(), compare);

	cout << endl;
	cout << "--- Grade Summary ---" << endl;

	// 모든 학생의 결과를 출력
	for (si_sz i = 0; i != students.size(); ++i) {
		// 이름과 오른쪽 공백을 포함하여 maxlen + 1개의 문자를 출력
		cout << students[i].name <<
			string(maxlen + 1 - students[i].name.size(), ' ');

		// 최종 점수를 계산하여 출력
		try {
			double final_grade = calculateAverage(students[i].scores); // 계산 함수
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what();
		}
		
	}
	return 0;
}


/*
프롬프트 : double final_grade = calculateAverage(students[i].scores); // 계산 함수
이 부분 아직도 올퓨남

답변 : 지금 calculateAverage(students[i].scores)에서 오류가 나는 이유는 헤더와 구현 파일의 함수 시그니처가 맞지 않기 때문이에요.

입력 시 벡터 크기 확보하기
지금은 record.scores[j]에 바로 입력하려고 해서 런타임 에러가 날 수 있습니다.반드시 resize(3)로 크기를 확보하세요 :

cpp
cout << "Enter 3 scores : ";
record.scores.resize(3);
for (int j = 0; j < 3; j++) {
	cin >> record.scores[j];
}

프롬프트 :.resize(3) 말고 다른 방법 ㅇ벗나

답변 3. 입력 개수를 유연하게 받기
만약 점수 개수가 항상 3개가 아니라 학생마다 다를 수 있다면, 먼저 개수를 입력받고 그만큼 push_back 하면 됩니다 :

cpp
cout << "Enter number of scores : ";
int n;
cin >> n;

record.scores.clear();
for (int j = 0; j < n; j++) {
	double score;
	cin >> score;
	record.scores.push_back(score);
}
✅ 정리하면.resize(3) 대신 push_back을 쓰는 게 가장 깔끔하고 확장성도 좋아요.

혹시 점수 개수를 항상 3개로 고정할 건가요, 아니면 나중에 과제 점수처럼 학생마다 개수가 달라질 수 있도록 유연하게 하고 싶으세요 ? */
