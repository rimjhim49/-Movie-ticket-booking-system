#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;

#include "Movie.cpp"
#include "Seat.cpp"
#include "Screen.cpp"
#include "Cinema.cpp"
#include "ShowSeat.cpp"
#include "Show.cpp"
#include "Customer.cpp"
#include "Payment.cpp"
#include "PriceCalculator.cpp"
#include "Booking.cpp"
#include "TicketPrinter.cpp"
#include "BookingService.cpp"

int main() {
    Cinema cinema("PVR Cinema");

    Screen screen1(1), screen2(2);

    for (int i = 1; i <= 10; i++) {
        SeatType type = i <= 4 ? SeatType::SILVER :
                        i <= 7 ? SeatType::GOLD : SeatType::PLATINUM;

        screen1.addSeat(Seat(i, type));
        screen2.addSeat(Seat(i, type));
    }

    cinema.addScreen(screen1);
    cinema.addScreen(screen2);

    BookingService service(cinema);

    int choice;

    do {
        cout << "\n===== MOVIE TICKET BOOKING =====\n";
        cout << "1. List Movies\n";
        cout << "2. Book Ticket\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "5. View Booking\n"; 
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
        case 1:
            service.displayMovies();
            break;
        case 2:
            service.bookTicket();
            break;
        case 3:
            service.cancelBooking();
            break;
        case 4:
            cout << "Thank you!\n";
            break;
        case 5:
            service.viewBooking();
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
