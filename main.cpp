#include <iostream>
#include "HabitTracker.h"
#include "HabitList.h"

using namespace std;

int main() {
	HabitList monthList;

    int month, habits;
    string habit;

    int choice = 0;

	do {
		cout << "************************************************************************\n";
		cout << "**                                                                    **\n";
		cout << "**                          WELCOME TO THE                            **\n";
		cout << "**                          HABIT TRACKER                             **\n";
		cout << "**                                                                    **\n";
		cout << "************************************************************************\n";
		cout << "** Please make a choice from the following options:                   **\n";
		cout << "** 1)  Add a new Habit from a selected month                          **\n";
		cout << "** 2)  Remove a Habit from a selected month                           **\n";
        cout << "** 3)  Add good days from a Habit                                     **\n";
        cout << "** 4)  Remove good days from a Habit                                  **\n";
		cout << "** 5)  Display all Habits in a selected month                         **\n";
        cout << "** 6)  Display all Habits                                             **\n";
		cout << "** 7)  Exit                                                           **\n";
		cout << "************************************************************************\n";
		cout << ">> ";
		cin >> choice;
    
		cin.ignore(); 
        string hold;

		switch (choice)
		{
		case 1:
		{
            cout << "Enter the month (1-12): ";
            cin >> month;
			cin.ignore();
            cout << "Enter habit: ";
            getline(cin, habit);

            HabitTracker habitTracker(month, habit);
            monthList.addHabit(month, habitTracker);
			cout << habitTracker << endl;

			cout << endl;
			break;
		}
		case 2: {
			int monthRemove;
			string habitRemove;

			cout << "\nEnter the month containing the Habit to be removed (1-12) >> ";
			cin >> monthRemove;
			monthList.displayMonth(monthRemove);

			cout << "\nEnter the name of the Habit to be removed >> ";
			cin >> habitRemove;

			if (monthList.removeHabit(monthRemove, habitRemove)) {
					cout << "The Habit " << habitRemove << "was removed successfully from " 
						 << monthList.getMonth(monthRemove) << "\n\n";
			} else {
					cout << "The Habit " << habitRemove << "was not found in " 
						 << monthList.getMonth(monthRemove) << "\n\n";
			}

			break;
		}
		case 3: {
			int monthAdd;
			string habitAdd;

			cout << "\nEnter the month containing the Habit to be edited (1-12) >> ";
			cin >> monthAdd;
			monthList.displayMonth(monthAdd);

			if (monthList.getMonthHabits(monthAdd).size() == 0) { cout << "\n\n"; break; }

			cout << "\nEnter the name of the Habit to be edited >> ";
			cin >> habitAdd;
			cin.ignore();

			monthList.getMonthHabits(monthAdd)[monthList.getIndex(monthAdd, habitAdd)].setGoodDays();
			cout << monthList.getMonthHabits(monthAdd)[monthList.getIndex(monthAdd, habitAdd)];
			
			break;
		}
		case 4: {
			int monthBad;
			string habitBad;

			cout << "\nEnter the month containing the Habit to be edited (1-12)>> ";
			cin >> monthBad;
			monthList.displayMonth(monthBad);

			if (monthList.getMonthHabits(monthBad).size() == 0) { cout << "\n\n"; break; }
		
			cout << "\nEnter the name of the Habit to be edited >> ";
			cin >> habitBad;
			cin.ignore();

			monthList.getMonthHabits(monthBad)[monthList.getIndex(monthBad, habitBad)].setBadDays();
			cout << monthList.getMonthHabits(monthBad)[monthList.getIndex(monthBad, habitBad)];
			
			break;
		}
		case 5: {
			int monthDisplay;

			cout << "\nEnter the month to display (1-12)>> ";
			cin >> monthDisplay;
			monthList.displayMonth(monthDisplay);

			cin.ignore();
			cout << "\nPress Enter to Continue\n";
			getline(cin, hold);
			break;
		}
		case 6:
			cout << monthList;

            cout << "\nPress Enter to Continue\n";
			getline(cin, hold);
			break;
		case 7:
			cout << "\nGood Luck Habiting!\n\n";
			break;
		}

	} while (choice != 7);

    // cout << "Enter the month (1-12): ";
    // cin >> month;
    // cin.ignore();
    // cout << "Enter habit: ";
    // getline(cin, habit);

    // HabitTracker habitTracker(month, habit);

    // cout << habitTracker;
    // habitTracker.setGoodDays();
	// cout << habitTracker;
	// habitTracker.setBadDays();
	// cout << habitTracker;
	// // --habitTracker;
    // // cout << habitTracker;

    return 0;
}