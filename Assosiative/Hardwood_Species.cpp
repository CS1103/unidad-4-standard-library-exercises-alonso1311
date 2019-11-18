#include<iostream>
#include<iomanip>
#include<string>
#include<map>

using namespace std;

void Hardwood_Species() {
    size_t number_cases;
    cin >> number_cases; cin.ignore();
    cout << endl;

    for(; number_cases > 0;) {
        map<string, int> m_trees;
        int total = 0;
        string trees;
        while(getline(cin, trees)) {
            if(trees == "") {
                number_cases--;
                break;
            } 

            else {
                m_trees[trees]++;
                total++;
            }
        }
        for (const auto& i : m_trees) 
            cout << i.first << " " << fixed << setprecision(4) << i.second*100.0/total << endl;
        }
}
