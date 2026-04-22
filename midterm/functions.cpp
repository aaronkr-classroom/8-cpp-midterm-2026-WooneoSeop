// functions.cpp

#include <vector>
#include <algorithm>
#include <iomanip> // setprecision

#include "functions.h"


double calculateAverage(const vector<double>& grades) {
    double total = 0;

        for (int i = 0; i < grades.size(); i++) {
            total += grades[i];
        }
        
    return total / grades.size();
}

bool compare(const Student_info& a, const Student_info& b) {
    return a.name < b.name; // True나 False 반환
}
