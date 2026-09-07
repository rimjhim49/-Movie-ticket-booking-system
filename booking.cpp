enum class BookingStatus { CONFIRMED, CANCELLED };

class Booking {
private:
    static int nextId;
    int bookingId;
    Customer* customer;
    Show* show;
    vector<ShowSeat*> seats;
    double amount;
    BookingStatus status;

public:
    Booking(Customer* customer, Show* show,
            vector<ShowSeat*> seats, double amount)
        : customer(customer), show(show), seats(seats),
          amount(amount), status(BookingStatus::CONFIRMED) {
        bookingId = nextId++;
    }

    int getId() const { return bookingId; }
    Customer* getCustomer() const { return customer; }
    Show* getShow() const { return show; }
    double getAmount() const { return amount; }
    const vector<ShowSeat*>& getSeats() const { return seats; }

    void cancel() {
        status = BookingStatus::CANCELLED;

        for (ShowSeat* seat : seats)
            seat->cancel();
    }

    bool isConfirmed() const {
        return status == BookingStatus::CONFIRMED;
    }
    string getStatus() const {
    return isConfirmed() ? "CONFIRMED" : "CANCELLED";
}
};

int Booking::nextId = 1001;
