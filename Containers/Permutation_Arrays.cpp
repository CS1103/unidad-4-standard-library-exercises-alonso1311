#include<iostream>
#include<iterator>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

template<typename CONTAINER>
void print(CONTAINER container) {
    auto bgin = begin(container);
    auto last = end(container);

    for(; bgin != last; ++bgin)
        cout << *bgin << '\n';
}

template<typename Kind_content>
void Permutation_Arrays() {
    size_t number_cases;
    cin >> number_cases;
    cin.ignore();
    cout << '\n';

    vector<vector<Kind_content>> real_result;
    
    for(size_t i = 0; i < number_cases; i++) {
        vector<size_t> index;
        vector<Kind_content> content;
        vector<pair<size_t, Kind_content>> table;
        string temp;

        getline(cin, temp, '\n');
        istringstream input_index(temp);
        copy(istream_iterator<size_t>(input_index), istream_iterator<size_t>(), back_inserter(index));

        getline(cin, temp, '\n');
        istringstream input_content(temp);
        copy(istream_iterator<Kind_content>(input_content), istream_iterator<Kind_content>(), back_inserter(content));

        cout << '\n';

        if(index.size() == content.size()) {
            vector<Kind_content> result;
            auto bgin_i = begin(index);
            auto bgin_c = begin(content);

            for(; bgin_i != end(index), bgin_c != end(content); bgin_i++, bgin_c++) 
                table.push_back(make_pair(*bgin_i, *bgin_c));
            
            sort(begin(table), end(table), [](pair<size_t, Kind_content> p1, pair<size_t, Kind_content> p2){return p1.first < p2.first;});

            for(auto bgin_t = begin(table); bgin_t != end(table); bgin_t++) 
                result.push_back((*bgin_t).second);

            real_result.push_back(result);
        }
            
        else
            cerr << "Index y Content tienen diferente tamano \n";
    }   

    for(auto i : real_result) {
        print(i); 
        cout << '\n';
    }
    cout << '\n';
}
