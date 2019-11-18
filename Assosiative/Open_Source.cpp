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
    map<string, int> project;
    while(true) {
        getline(cin, line, '\n');
        if(line == "0")
            break;
        
        else {
            if(upp(line)){
                project[line] = 0;
            }
            else {
                project[line]++;
            }
        }
    }
    for(const auto& i : project)
            cout << i.first << " " << i.second << endl;
}

int main() {
    //Open_Source();
    
    std::string str = "Hello World";

    string temp = str;
    boost::to_upper(temp);

    cout << str << endl << temp;

    return 0;
}
