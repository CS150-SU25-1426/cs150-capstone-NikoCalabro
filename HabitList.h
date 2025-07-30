#ifndef HABITLIST_H
#define HABITLIST_H

#include "HabitTracker.h"
#include <vector>

using namespace std;

class HabitList {
private:
    static const int ARRAY_SIZE = 12;
    static vector<HabitTracker> LIST[ARRAY_SIZE];
    static const string MONTHS[ARRAY_SIZE];

public:
    bool addHabit(int month, HabitTracker ht);
    bool removeHabit(int month, string habit);

    string getMonth(int month); 
    static vector<HabitTracker>& getMonthHabits(int month);
    int getIndex(int month, string habit);

    void displayMonth(int month) const;

    friend ostream& operator<<(ostream& os, const HabitList& list);
};


#endif