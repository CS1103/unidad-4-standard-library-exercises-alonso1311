#include<iostream>
#include<iterator>
#include<utility>
#include<vector>

using namespace std;

template<typename CONTAINER>
void Ultra_QuickSort() { 
    CONTAINER container;
    int number_cases;
    cin >> number_cases; cin.ignore();

    for(; number_cases > 0; number_cases--) {
        int temp;
        cin >> temp; cin.ignore();
        container.push_back(temp);
    }

    int n = container.size();
    pair<int, int> pos[n]; 
    for (int i = 0; i < n; i++) 
    { 
        pos[i].first = container[i]; 
        pos[i].second = i; 
    } 
  
    sort(pos, pos + n); 
  
    vector<bool> vis(n, false); 
  
    int count = 0; 
  
    for (int i = 0; i < n; i++) { 
        if (vis[i] || pos[i].second == i) 
            continue; 
  
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]) { 
            vis[j] = 1; 
  
            j = pos[j].second; 
            cycle_size++; 
        } 
  
        if (cycle_size > 0)  
            count += (cycle_size - 1); 
         
    } 
    cout << count;
}
