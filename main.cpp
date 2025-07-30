#include <iostream>
#include "HabitTracker.h"

using namespace std;

int main() {
    vector<HabitTracker> monthList;
    int month, habits;
    string habit;

    int choice = 0;

	// do {
	// 	cout << "************************************************************************\n";
	// 	cout << "**                                                                    **\n";
	// 	cout << "**                          WELCOME TO THE                            **\n";
	// 	cout << "**                          HABIT TRACKER                             **\n";
	// 	cout << "**                                                                    **\n";
	// 	cout << "************************************************************************\n";
	// 	cout << "** Please make a choice from the following options:                   **\n";
	// 	cout << "** 1)  Add a new Habit from a selected month                          **\n";
	// 	cout << "** 2)  Remove a Habit from a selected month                           **\n";
    //     cout << "** 5)  Add good days from a Habit                                     **\n";
    //     cout << "** 5)  Remove good days from a Habit                                  **\n";
	// 	cout << "** 3)  Display all Habits in a selected month                         **\n";
    //     cout << "** 4)  Display all Habits                                             **\n";
	// 	cout << "** 6)  Exit                                                           **\n";
	// 	cout << "************************************************************************\n";
	// 	cout << ">> ";
	// 	cin >> choice;
    
	// 	cin.ignore(); 
    //     string hold;

	// 	switch (choice)
	// 	{
	// 	case 1:
	// 	{
            // cout << "Enter the month (1-12): ";
            // cin >> month;

            // cout << "Enter habit: ";
            // getline(cin, habit);

            // HabitTracker habitTracker(month, habit);
            // monthList.push_back(habitTracker);

	// 		cout << endl;
	// 		break;
	// 	}
	// 	case 2:
	// 		cout << inventory << endl;
	// 		cout << "\nWhich ID# would you like to remove? (or -1 to cancel) >> ";
	// 		cin >> id;
	// 		if (inventory.removeBoard(id)) {
	// 	        	cout << "~~~Surfboard #" << id << " removed successfully~~~\n\n";
	// 		} else {
	// 		        cout << "~~~Surfboard #" << id << " not found\n\n";
	// 		}
			
	// 		break;
	// 	case 3:
	// 		cout << inventory;
    //         cout << "\nPress Enter to Continue\n";
	// 		getline(cin, hold);
	// 		break;
	// 	case 6:
	// 		cout << "Good Luck!\n";
	// 		break;
	// 	}

	// } while (choice != 4);

    cout << "Enter the month (1-12): ";
    cin >> month;
    cin.ignore();
    cout << "Enter habit: ";
    getline(cin, habit);

    HabitTracker habitTracker(month, habit);
    monthList.push_back(habitTracker);

    cout << monthList[0];
    cin.ignore();
    monthList[0].setGoodDays(1);
	cout << monthList[0];

	--monthList[0];
    cout << monthList[0];

    return 0;
}