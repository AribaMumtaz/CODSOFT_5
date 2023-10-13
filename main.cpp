#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Constants
const int NUM_ROWS = 5;
const int NUM_COLS = 10;
const double TICKET_PRICE = 10.0;

// Function to display the seating chart
void displaySeatingChart(const vector<vector<char>>& seats) {
    cout << "  Seats:  ";
    for (int i = 1; i <= NUM_COLS; i++) {
        cout << setw(3) << i;
    }
    cout << "\n";

    for (int i = 0; i < NUM_ROWS; i++) {
        cout << "Row " << char('A' + i) << ":   ";
        for (int j = 0; j < NUM_COLS; j++) {
            cout << seats[i][j] << "  ";
        }
        cout << "\n";
    }
}

// Function to book a seat
bool bookSeat(vector<vector<char>>& seats, int row, int col) {
    if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS || seats[row][col] == 'X') {
        cout << "Invalid seat selection or seat already booked." << endl;
        return false;
    }

    seats[row][col] = 'X';
    return true;
}

// Function to calculate the total cost
double calculateTotalCost(const vector<vector<char>>& seats) {
    int numBookedSeats = 0;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (seats[i][j] == 'X') {
                numBookedSeats++;
            }
        }
    }
    return numBookedSeats * TICKET_PRICE;
}

int main() {
    vector<vector<char>> seats(NUM_ROWS, vector<char>(NUM_COLS, 'O'));
    char choice;

    do {
        cout << "Movie Ticket Booking System\n";
        cout << "1. View Movie Listings\n";
        cout << "2. Book a Seat\n";
        cout << "3. Calculate Total Cost\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                displaySeatingChart(seats);
                break;

            case '2':
                char row;
                int col;
                cout << "Enter seat (e.g., A1): ";
                cin >> row >> col;
                row = toupper(row) - 'A';
                col--;

                if (bookSeat(seats, row, col)) {
                    cout << "Seat booked successfully!" << endl;
                }
                break;

            case '3':{
                double totalCost = calculateTotalCost(seats);
                cout << "Total Cost: $" << totalCost << endl;
                break;}
            case '4': {
                cout << "Thank you for using the system. Goodbye!" << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '4');

    return 0;
}