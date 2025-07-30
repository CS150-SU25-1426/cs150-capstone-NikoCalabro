#include "HabitList.h"
#include <iostream>
#include <iomanip>

using namespace std;

const string HabitList::MONTHS[12] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
};

vector<HabitTracker> HabitList::LIST[ARRAY_SIZE] = {};

string HabitList::getMonth(int month) { return MONTHS[month-1]; } 
vector<HabitTracker>& HabitList::getMonthHabits(int month) { return LIST[month-1]; }

bool HabitList::addHabit(int month, HabitTracker ht) {
    LIST[month-1].push_back(ht);
    return true;
}

bool HabitList::removeHabit(int month, string habit) {
    int index = getIndex(month, habit);
    if (index >= 0) {
        LIST[month-1].erase(LIST[month-1].begin() + index);
        return true;
    }
    return false;
}
int HabitList::getIndex(int month, string habit) {
    int index = -1;
    for (int i = 0; i < LIST[month-1].size(); i++) {
        if (LIST[month-1][i].getHabit() == habit) {
            index = i;
        }
    }
    return index;
}

void HabitList::displayMonth(int month) const {    
    cout << "\n" << MONTHS[month-1] << "\n\n";

    if (LIST[month-1].size() == 0) {
        cout << "      No Habits to Show\n";
        return;
    }
    int width = 7;

    for(int i =0; i < LIST[month-1].size(); i++) {
        cout << setw(23) << left << LIST[month-1][i].getHabit();
    }
    cout << "\n";
    for (int i = 0; i <= LIST[month-1][0].getDays()/width; i++) {
        for (int j =0; j < LIST[month-1].size(); j++) {
            for (int k = width*i; k < width*i+width && k < LIST[month-1][0].getDays(); k++) {
                if (LIST[month-1][j].getTracker()[k] == "X") {
                    cout << setw(3) << LIST[month-1][j].getTracker()[k];
                }
                else if (stoi(LIST[month-1][j].getTracker()[k]) == 29 && j>0) {
                    if (j == 1)
                        cout << setw(17-3*(LIST[month-1][0].getDays()-30)) << right << LIST[month-1][j].getTracker()[k];
                    else
                        cout << setw(18-3*(LIST[month-1][0].getDays()-30)) << right << LIST[month-1][j].getTracker()[k];
                } else
                    cout << setw(3) << LIST[month-1][j].getTracker()[k];
            }
            cout  << "  ";
        }
        cout << "\n";
    }
    // cout << "\n";
}

ostream& operator<<(ostream& os, const HabitList& list) {
    for(int i =1; i <= list.ARRAY_SIZE; i++) {
        list.displayMonth(i);
    }
    return os;
}