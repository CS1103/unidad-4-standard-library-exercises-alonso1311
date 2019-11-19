#include<iostream>
#include<map>
#include<set>
#include<string>

#include <boost/algorithm/string.hpp>

using namespace std;

bool upp(string str) {
    string temp = str;
    boost::to_upper(temp);
    if(str == temp) 
        return true;

    else 
        return false;
}

void Open_Source() {
    string line;
    string name;
    map<string, int> project;
    set<string> temp;
    while(true) {
        getline(cin, line, '\n');
        if(line == "0")
            break;
        
        else {
            int count = 0;
            if(upp(line)){
                name = line;
                project[name];
            }
            else {
                temp.insert(line);
                cout << endl << line << endl;
                count++;
            }
            project[name] = count;
       }
    }
    for(const auto& i : project)
            cout << i.first << " " << i.second << endl;

    for(const auto& i : temp)
        cout << i << " ";
}

int main() {
    Open_Source();

    return 0;
}
