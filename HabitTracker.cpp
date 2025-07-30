#include <iostream>
#include <sstream>
#include <iomanip>
#include "HabitTracker.h"

vector<vector<string>> HabitTracker::monthTrackers;
vector<string> HabitTracker::habits;

HabitTracker::HabitTracker(int m, string h) {
    month = m;
    habit = h;
    for (int i = 0; i < DAYS[month-1]; ++i) {
        tracker.push_back(to_string(i+1)); 
    }
    monthTrackers.push_back(tracker);
    habits.push_back(habit);
    habitIndex = habits.size() - 1; 
}

const string HabitTracker::MONTHS[12] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
};
const int HabitTracker::DAYS[12] = {
    31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31
};

void HabitTracker::setGoodDays(int habit) {
    string input, day;

    cout << "\nEnter good days as a comma-separated list (i.e. 1,2,3): ";
    getline(cin, input);
    stringstream data(input);

    while (getline(data, day, ',')) {

        for (int i = 0; i < DAYS[month-1]; i++) {
            if (monthTrackers[habit-1][i] == day) {
                monthTrackers[habit-1][i] = "X"; 
                break;
            }
        }
    }
}

HabitTracker& HabitTracker::operator--() {
    for (int i = 0; i < DAYS[month-1]; i++) {
        monthTrackers[this->getHabitIndex()][i] = to_string(i+1);
    }
    return *this;
}


ostream& operator<<(ostream& os, const HabitTracker& t) {
    int width = 7;
    os << "\nHabit Tracker for " << t.MONTHS[t.month-1] << ":\n\n";
    for (int i = 0; i < t.habits.size(); i++) {
        os << "  ";
        os  << setw(21) << left << t.habits[i];
    }
    os << right << "\n";

    for (int i = 0; i <= t.DAYS[t.month-1]/width; i++) {
        for (int j =0; j < t.monthTrackers.size(); j++) {
            for (int k = width*i; k < width*i+width && k < t.monthTrackers[j].size(); k++) {
                if(t.monthTrackers[j][k] == "X") {
                    os << setw(3) << t.monthTrackers[j][k];
                }
                else if (stoi(t.monthTrackers[j][k]) == 29 && j>0) {
                    os << setw(24-(t.DAYS[t.month-1] % 7)*3) <<  t.monthTrackers[j][k];
                    continue;
                } else
                    os << setw(3) << t.monthTrackers[j][k];
            }
            os  << "  ";
        }
        os << "\n";
    }

    os << "\n";
    return os;
}