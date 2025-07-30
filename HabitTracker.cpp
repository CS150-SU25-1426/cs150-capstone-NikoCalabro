#include <iostream>
#include <sstream>
#include <iomanip>
#include "HabitTracker.h"

const int HabitTracker::DAYS[12] = {
    31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31
};

HabitTracker::HabitTracker(int m, string h) {
    month = m;
    habit = h;
    for (int i = 0; i < DAYS[month-1]; i++) {
        tracker.push_back(to_string(i+1)); 
    }
    habitIndex = tracker.size() - 1; 
}

void HabitTracker::setGoodDays() {
    if (tracker.size() == 0) return;

    string input, day;
    // cin.ignore();
    
    cout << "\nEnter good days as a comma-separated list (i.e. 1,2,3): ";
    getline(cin, input);
    stringstream data(input);

    while (getline(data, day, ',')) {
        for (int i = 0; i < DAYS[month-1]; i++) {
            if (tracker[i] == day) {
                tracker[i] = "X"; 
                break;
            }
        }
    }
}
void HabitTracker::setBadDays() {
    if (tracker.size() == 0) return;
    
    string input, day;
    // cin.ignore();

    cout << "\nRemove good days as a comma-separated list (i.e. 1,2,3): ";
    getline(cin, input);
    stringstream data(input);

    while (getline(data, day, ',')) {
        int dayNum = stoi(day);
        if (dayNum < DAYS[month-1] && tracker[dayNum-1] == "X") {
            tracker[dayNum-1] = day;
        }
    }
}

HabitTracker& HabitTracker::operator--() {
    for (int i = 0; i < DAYS[month-1]; i++) {
        tracker[i] = to_string(i+1);
    }
    return *this;
}


ostream& operator<<(ostream& os, const HabitTracker& t) {
    int width = 7;
    os  << "\n" << left << t.habit << ":\n";

    for (int i = 0; i <= t.tracker.size()/width; i++) {
        for (int j = width*i; j < t.tracker.size() && j < width*(i+1); j++) {
            os << setw(3) << left << t.tracker[j];
        }
        os << "\n";
    }
    os << "\n";
    return os;
}