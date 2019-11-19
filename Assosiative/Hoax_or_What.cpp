#include<iostream>
#include<set>

using namespace std;

void Hoax_or_What() {
    multiset<int> bills;
    int result = 0;
    int days;
    cin >> days; cin.ignore();

    for(; days > 0; days--) {
        int number_bills;
        cin >> number_bills; cin.ignore();

        for(; number_bills > 0; number_bills--) {
            int bill;
            cin >> bill; cin.ignore();
            bills.insert(bill);
        }

        auto lowest = begin(bills);
        auto highest = next(begin(bills), bills.size()-1);
            
        result += (*highest - *lowest);
            
		bills.erase(highest);
        bills.erase(lowest); 
    }
        
    cout << endl << result << '\n';
}
