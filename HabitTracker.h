#include <string>
#include <vector>

#ifndef HABITTRACKER_H
#define HABITTRACKER_H

using namespace std;

class HabitTracker {
private:
    static const int ARRAY_SIZE = 12;
    static const int DAYS[ARRAY_SIZE];
    int month;
    string habit;
    int habitIndex;
    vector<string> tracker;

public:
    HabitTracker(int m, string h);

    int getDays() { return DAYS[month-1]; }
    string getHabit() { return habit; }
    int getHabitIndex() { return habitIndex; }
    vector<string> getTracker() { return tracker; }

    void setGoodDays();
    void setBadDays();
    
    HabitTracker& operator--();

	friend ostream& operator<<(ostream& os, const HabitTracker& t);
};

#endif