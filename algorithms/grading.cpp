#include <bits/stdc++.h>

using namespace std;

int round_grade(int grade)
{
    if (grade < 38) return grade;
    
    int next_multiple = (grade / 5 + 1) * 5;
    if (next_multiple - grade < 3) return next_multiple;
    
    return grade;
}

void solve(vector < int > grades){
    for (auto grade: grades) {
        cout << round_grade(grade) << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> grades(n);
    for(int grades_i = 0; grades_i < n; grades_i++){
       cin >> grades[grades_i];
    }
    solve(grades);
    
    return 0;
}
