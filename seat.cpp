enum class SeatType { SILVER, GOLD, PLATINUM };
enum class SeatStatus { AVAILABLE, BOOKED };

class Seat {
private:
    int seatNumber;
    SeatType type;

public:
    Seat(int number, SeatType type)
        : seatNumber(number), type(type) {}

    int getSeatNumber() const { return seatNumber; }
    SeatType getType() const { return type; }

    int getPrice() const {
        if (type == SeatType::SILVER) return 150;
        if (type == SeatType::GOLD) return 250;
        return 400;
    }

    string getTypeName() const {
        if (type == SeatType::SILVER) return "SILVER";
        if (type == SeatType::GOLD) return "GOLD";
        return "PLATINUM";
    }
};
