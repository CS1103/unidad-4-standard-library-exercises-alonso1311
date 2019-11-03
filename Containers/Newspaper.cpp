#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

using Kind_values = size_t;

void Newspaper() {
    size_t number_test;
    cin >> number_test;
    cin.ignore();

    vector<vector<Kind_values>> real_result;

    for(size_t i = 0; i < number_test; i++) {
        vector<Kind_values> result;

        size_t number_paid_characters;
        cin >> number_paid_characters;
        cin.ignore();

        map<char, Kind_values> table;

        for(size_t j = 0; j < number_paid_characters; j++) {
            char paid_character;
            Kind_values values;
            cin >> paid_character >> values;

            table[paid_character] = values;
        }

        size_t number_lines;
        cin >> number_lines;
        cin.ignore();
        
        Kind_values to_paid = 0;

        for(size_t k = 0; k < number_lines; k++) {
            string line;
            getline(cin, line);

            for(char char_to_paid : line) {
                auto search = table.find(char_to_paid);
                if(search != table.end()) 
                    to_paid += search->second;
            }
        }

        result.push_back(to_paid);
        real_result.push_back(result);
    }

    for(auto vectors : real_result)
        for(auto elements : vectors)
            cout << elements/100 << '.' << elements%100 << "$\n";
}
