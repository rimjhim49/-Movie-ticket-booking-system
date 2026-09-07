class PriceCalculator {
public:
    double calculate(const vector<ShowSeat*>& seats) {
        double total = 0;

        for (ShowSeat* seat : seats)
            total += seat->getSeat()->getPrice();

        return total;
    }
};
