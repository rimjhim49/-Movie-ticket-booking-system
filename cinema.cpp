class Cinema {
private:
    string name;
    vector<Screen> screens;

public:
    Cinema(string name) : name(name) {}

    void addScreen(const Screen& screen) {
        screens.push_back(screen);
    }

    string getName() const {
        return name;
    }

    vector<Screen>& getScreens() {
        return screens;
    }
};
