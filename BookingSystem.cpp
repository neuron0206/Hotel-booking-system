#include "BookingSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool file_open(const string& file_name) {
    ifstream file(file_name);
    return file.good();
}

void clear_field() {
    system("cls");
}

void BookingSystem::processCommands() {

    string command;
    while (true) {
        cout << "1 - NEW-HOTEL" << endl << "2 - BOOK-CMD" << endl << "3 - PROLONG" << endl <<
            "4 - CLEAR-STORAGE" << endl << "5 - EXIT" << endl << "Enter command: ";
        cin >> command;

        if (command.empty()) {
            continue;
        }

        if (command == "1") {
            string name;
            int capacity, maxGuests, costPerPerson;
            cout << "Enter hotel name: ";
            cin >> name;
            cout << "Enter capacity: ";
            cin >> capacity;
            cout << "Enter max guests in room: ";
            cin >> maxGuests;
            cout << "Enter cost per person: ";
            cin >> costPerPerson;

            string file_name = name + ".txt";

            if (file_open(file_name)) {
                clear_field();
                cerr << "Error: File " << file_name << " already exists" << endl << endl;
            }
            else {
                ofstream hotelFile(file_name);
                hotelFile << "Hotel Name: " << name << "\n";
                hotelFile << "Capacity: " << capacity << "\n";
                hotelFile << "Max Guests per Room: " << maxGuests << "\n";
                hotelFile << "Cost per Person: " << costPerPerson << "\n";
                hotelFile.close();
            }

            newHotel(name, capacity, maxGuests, costPerPerson);
        }
    }
}

void BookingSystem::newHotel(const string& name, int capacity, int maxGuests, int costPerPerson) {
    clear_field();
    cout << "New hotel with " << capacity << " guests has been created!\n";
}