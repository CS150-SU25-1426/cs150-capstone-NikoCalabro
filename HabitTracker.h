#include <string>
#include <vector>

#ifndef HABITTRACKER_H
#define HABITTRACKER_H

using namespace std;

class HabitTracker {
private:
    static const int ARRAY_SIZE = 12;
    static const string MONTHS[ARRAY_SIZE];
    static const int DAYS[ARRAY_SIZE];
    int month;
    string habit;
    int habitIndex;
    vector<string> tracker;

    static vector<vector<string>> monthTrackers;
    static vector<string> habits;

public:
    HabitTracker(int m, string h);

    string getMonth() { return MONTHS[month-1]; }
    int getDays() { return DAYS[month-1]; }
    string getHabit() { return habit; }
    int getHabitIndex() { return habitIndex; }

    void setGoodDays(int habit);
    
    HabitTracker& operator--();

	friend ostream& operator<<(ostream& os, const HabitTracker& t);
};

#endif