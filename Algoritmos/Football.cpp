#include<iostream>
#include<map>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<functional>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace std;

struct Result {
    size_t points_earned = 0;
    size_t games_played = 0; 
    size_t wins = 0;
    size_t ties = 0;
    size_t losses = 0;
    int goal_scored = 0;
    int goal_against = 0;
};

using Comparator = function<bool(pair<string, Result>, pair<string, Result>)>;

void Football() {
    size_t number_tournaments;
    cin >> number_tournaments;
    cin.ignore();

    for(size_t i = 0; i < number_tournaments; i++) {
        string Tournament;
        getline(cin, Tournament, '\n');

        map<string, Result> team_result;
        size_t number_teams;
        cin >> number_teams;
        cin.ignore();
        for(size_t j = 0; j < number_teams; j++) {
            string team_name;
            getline(cin, team_name, '\n');
            team_result[team_name];
        }

        size_t number_games;
        cin >> number_games;
        cin.ignore();
        for(size_t j = 0; j < number_games; j++) {
            string match;
            vector<string> v_match;
            getline(cin, match, '\n');
            boost::split(v_match, match, boost::is_any_of("#@"));    
            string team_1 = v_match[0];
            int goal_1 = stoi(v_match[1]);
            string team_2 = v_match[3];
            int goal_2 = stoi(v_match[2]);
            team_result[team_1].goal_scored += goal_1;
            team_result[team_1].goal_against += goal_2;
            team_result[team_2].goal_scored += goal_2;
            team_result[team_2].goal_against += goal_1;

            if(goal_1 > goal_2) {
                team_result[team_1].points_earned += 3;
                team_result[team_1].wins += 1;
                team_result[team_2].losses += 1;
            }
            else if(goal_2 > goal_1) {
                team_result[team_2].points_earned += 3;
                team_result[team_2].wins += 1;
                team_result[team_1].losses += 1;
            }
            else {
                team_result[team_1].points_earned += 1;
                team_result[team_2].points_earned += 1;
                team_result[team_1].ties += 1;
                team_result[team_2].ties += 1;
            }
        }

        Comparator compare = [](pair<string, Result> equipo_1, pair<string, Result> equipo_2) {
                        return equipo_1.second.points_earned > equipo_2.second.points_earned;
                        };

        set<pair<string, Result>, Comparator> set_team_result(team_result.begin(), team_result.end(), compare);

        int ranking = 1;
        cout << Tournament << endl;
        for(auto const& elem : set_team_result) {
            cout << ranking << ") " << elem.first << " " << elem.second.points_earned << 
                " p, " << elem.second.games_played << " g (" << 
                elem.second.wins << "-" << elem.second.ties << "-" << elem.second.losses << "), " << 
                abs(elem.second.goal_scored - elem.second.goal_against) << " gd (" << elem.second.goal_scored << 
                "-" << elem.second.goal_against << ")\n";

            ranking++;
        } 
    }
}
