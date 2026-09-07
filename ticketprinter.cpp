class TicketPrinter {
public:
    void print(const Booking& booking, const Payment& payment) {
        cout << "\n================================\n";
        cout << "           TICKET\n";
        cout << "================================\n";
        cout << "Booking ID : " << booking.getId() << '\n';
        cout << "Customer   : " << booking.getCustomer()->getName() << '\n';
        cout << "Movie      : " << booking.getShow()->getMovie()->getTitle() << '\n';
        cout << "Screen     : " << booking.getShow()->getScreen()->getScreenNumber() << '\n';
        cout << "Time       : " << booking.getShow()->getStartTime() << '\n';

        cout << "Seats      : ";
        for (auto* seat : booking.getSeats())
            cout << seat->getSeat()->getSeatNumber() << " ";

        cout << "\nAmount     : Rs." << fixed << setprecision(2)
             << booking.getAmount();
        cout << "\nPayment    : " << payment.method();
        cout << "\nStatus     : CONFIRMED\n";
        cout << "================================\n";
    }
};
