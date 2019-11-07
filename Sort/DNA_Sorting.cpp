#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int inversion(string s1) {
    int count_inversion = 0;
    for(size_t i = 0; i < s1.size()-1; i++)
        for(size_t j = i; j < s1.size()-i-1; j++)
            if(s1[i] > s1[j])
                count_inversion++;

    return count_inversion;
}

void DNA_Sorting() {
    size_t number_cases;
    cin >> number_cases;
    cin.ignore();

    cout << endl;

    vector<vector<string>> result;
    for(; number_cases > 0; number_cases--) {
        size_t size_DNA, number_DNA;
        cin >> size_DNA >> number_DNA;

        vector<string> v_DNA;
        for(; number_DNA > 0; number_DNA--) {
            char DNA [size_DNA];
            cin >> DNA;
            cin.ignore();

            v_DNA.push_back(DNA);
        }

        cout << endl;

        stable_sort(begin(v_DNA), end(v_DNA), [](string s1, string s2){return inversion(s1) < inversion(s2);});
        
        result.push_back(v_DNA);
    }

    for(auto i : result) {
        for(auto j : i)
            cout << j << endl;
        cout << endl;
    }
}
