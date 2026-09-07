class BookingService {
private:
    vector<Movie> movies;
    vector<Show> shows;
    vector<unique_ptr<Booking>> bookings;
    PriceCalculator calculator;
    TicketPrinter printer;

    void loadData(Cinema& cinema) {
        movies.emplace_back("Avengers", "English", 180);
        movies.emplace_back("3 Idiots", "Hindi", 170);
        movies.emplace_back("Dangal", "Hindi", 161);

        shows.emplace_back(&movies[0], &cinema.getScreens()[0], "10:00 AM");
        shows.emplace_back(&movies[0], &cinema.getScreens()[0], "06:00 PM");
        shows.emplace_back(&movies[1], &cinema.getScreens()[1], "01:00 PM");
        shows.emplace_back(&movies[2], &cinema.getScreens()[1], "08:00 PM");
    }

    Payment* choosePayment(int choice) {
        if (choice == 1) return new UpiPayment();
        if (choice == 2) return new CardPayment();
        if (choice == 3) return new CashPayment();
        return nullptr;
    }

public:
    BookingService(Cinema& cinema) {
        loadData(cinema);
    }

    void displayMovies() {
        cout << "\n--- MOVIES ---\n";

        for (int i = 0; i < (int)movies.size(); i++) {
            cout << i + 1 << ". "
                 << movies[i].getTitle()
                 << " | " << movies[i].getLanguage()
                 << " | " << movies[i].getDuration()
                 << " min\n";
        }
    }

    void bookTicket() {
        displayMovies();

        int movieChoice;
        cout << "Select movie: ";
        cin >> movieChoice;

        if (movieChoice < 1 || movieChoice > (int)movies.size()) {
            cout << "Invalid movie.\n";
            return;
        }

        Movie* movie = &movies[movieChoice - 1];

        vector<Show*> movieShows;

        cout << "\n--- SHOWS ---\n";

        for (auto& show : shows) {
            if (show.getMovie() == movie) {
                movieShows.push_back(&show);
                cout << movieShows.size()
                     << ". Screen "
                     << show.getScreen()->getScreenNumber()
                     << " - " << show.getStartTime() << '\n';
            }
        }

        int showChoice;
        cout << "Select show: ";
        cin >> showChoice;

        if (showChoice < 1 || showChoice > (int)movieShows.size()) {
            cout << "Invalid show.\n";
            return;
        }

        Show* show = movieShows[showChoice - 1];

        show->displaySeats();

        int count;
        cout << "\nNumber of seats: ";
        cin >> count;

        if (count <= 0) {
            cout << "Invalid number of seats.\n";
            return;
        }

        vector<ShowSeat*> selected;

        for (int i = 0; i < count; i++) {
            int number;
            cout << "Enter seat number " << i + 1 << ": ";
            cin >> number;

            ShowSeat* seat = show->findSeat(number);

            if (!seat) {
                cout << "Invalid seat number.\n";
                return;
            }

            if (!seat->isAvailable()) {
                cout << "Seat already booked.\n";
                return;
            }

            selected.push_back(seat);
        }

        double total = calculator.calculate(selected);

        cout << "\nTotal amount = Rs."
             << fixed << setprecision(2) << total << '\n';

        string name, phone;
        cout << "Customer name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        cout << "Phone: ";
        getline(cin, phone);

        for (auto* seat : selected)
            seat->book();

        cout << "\n1. UPI\n2. Card\n3. Cash\n";
        cout << "Payment method: ";

        int paymentChoice;
        cin >> paymentChoice;

        unique_ptr<Payment> payment(choosePayment(paymentChoice));

        if (!payment) {
            cout << "Invalid payment. Seats released.\n";

            for (auto* seat : selected)
                seat->cancel();

            return;
        }

        bool paid = payment->pay(total);

        if (!paid) {
            cout << "Payment failed. Booking cancelled.\n";

            for (auto* seat : selected)
                seat->cancel();

            return;
        }

        Customer* customer = new Customer(name, phone);

        bookings.push_back(
            make_unique<Booking>(customer, show, selected, total)
        );

        printer.print(*bookings.back(), *payment);
    }

    void cancelBooking() {
        int id;

        cout << "Enter booking ID: ";
        cin >> id;

        for (auto& booking : bookings) {
            if (booking->getId() == id &&
                booking->isConfirmed()) {

                booking->cancel();

                cout << "Booking cancelled successfully.\n";
                cout << "Seats are AVAILABLE again.\n";
                return;
            }
        }

        cout << "Booking not found.\n";
    }
   void viewBooking() {
    int id;

    cout << "Enter booking ID: ";
    cin >> id;

    for (auto& booking : bookings) {
        if (booking->getId() == id) {
            cout << "\n===== BOOKING DETAILS =====\n";
            cout << "Booking ID : " << booking->getId() << endl;
            cout << "Amount     : Rs." << fixed << setprecision(2)
                 << booking->getAmount() << endl;
            cout << "Status     : "
                 << (booking->isConfirmed() ? "CONFIRMED" : "CANCELLED")
                 << endl;

            cout << "Seats      : ";
            for (auto* showSeat : booking->getSeats()) {
                cout << showSeat->getSeat()->getSeatNumber() << " ";
            }
            cout << endl;

            cout << "===========================\n";
            return;
        }
    }

    cout << "Booking not found.\n";
}
};
