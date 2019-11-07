#include<iostream>
#include<vector>
#include<string>
#include<utility>

using namespace std;

template<typename CONTAINER>
void print_swaps(CONTAINER container) {
    for(auto i = begin(container); i != end(container); i++)
        cout << "Optimal train swapping takes " << *i << " swaps";
}

template<typename CONTAINER>
int BubbleSort(CONTAINER container) {
    int swaps = 0;

    int cont_i = 0;
    for(auto i = begin(container); i != end(container); i++) {
        auto to_j = next(begin(container), container.size()-cont_i-1);
        for(auto j = begin(container); j != to_j; j++) 
            if(*j > *(j+1)) {
                swap(*j, *(j+1));
                swaps++;
            }
    }

    return swaps; 
}

void Train_Swapping() {
    size_t number_cases;
    cin >> number_cases;
    cin.ignore();

    vector<int> results;

    for(; number_cases > 0; number_cases--) {
        size_t quantity_numbers;
        cin >> quantity_numbers;
        cin.ignore();

        vector<int> numbers;
        for(; quantity_numbers > 0; quantity_numbers--) {
            int temp_number;
            cin >> temp_number;
            cin.ignore();
            numbers.push_back(temp_number);
        }

        results.push_back(BubbleSort(numbers));
    }

    cout << endl;
    print_swaps(results);
}
