class Screen {
private:
    int screenNumber;
    vector<Seat> seats;

public:
    Screen(int number) : screenNumber(number) {}

    void addSeat(const Seat& seat) {
        seats.push_back(seat);
    }

    int getScreenNumber() const {
        return screenNumber;
    }

    vector<Seat>& getSeats() {
        return seats;
    }
};
