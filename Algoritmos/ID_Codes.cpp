#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

void ID_Codes() {
   string lines;

   vector<string> result;

   for(;;) {
       cin >> lines;
       if(lines == "#") 
           break;
       else {
           if(next_permutation(lines.begin(), lines.end()))
              result.push_back(lines);
           else
              result.push_back("No Succesor");
       }
    }

   for(auto const& elements : result)
       cout << elements << '\n';
}
