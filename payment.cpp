class Payment {
public:
    virtual bool pay(double amount) = 0;
    virtual string method() const = 0;
    virtual ~Payment() = default;
};

class UpiPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "UPI payment of Rs." << fixed << setprecision(2)
             << amount << " successful.\n";
        return true;
    }

    string method() const override {
        return "UPI";
    }
};

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Card payment of Rs." << fixed << setprecision(2)
             << amount << " successful.\n";
        return true;
    }

    string method() const override {
        return "CARD";
    }
};

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Cash payment of Rs." << fixed << setprecision(2)
             << amount << " received.\n";
        return true;
    }

    string method() const override {
        return "CASH";
    }
};
