class ShowSeat {
private:
    Seat* seat;
    SeatStatus status;

public:
    ShowSeat(Seat* seat)
        : seat(seat), status(SeatStatus::AVAILABLE) {}

    Seat* getSeat() const {
        return seat;
    }

    bool isAvailable() const {
        return status == SeatStatus::AVAILABLE;
    }

    void book() {
        status = SeatStatus::BOOKED;
    }

    void cancel() {
        status = SeatStatus::AVAILABLE;
    }

    string getStatus() const {
        return isAvailable() ? "AVAILABLE" : "BOOKED";
    }
};
