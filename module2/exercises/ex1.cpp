#include <memory>
#include <string>
#include <vector>

class Ship {
public:
    Ship() : id_(-1) {}
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id)
        : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id) {}
    Ship(int maxCrew, int speed, size_t id) : Ship(0, maxCrew, speed, "", id) {}

    void setName(const std::string& name) {
        name_ = name;
    }

    Ship& operator-=(size_t num) {
        crew_ -= num;
        return *this;
    }
    Ship& operator+=(size_t num) {
        crew_ += num;
        return *this;
    }

    size_t getCapacity() const {
        return capacity_;
    }
    size_t getMaxCrew() const {
        return maxCrew_;
    }
    size_t getSpeed() const {
        return speed_;
    }
    std::string getName() const {
        return name_;
    }
    size_t getId() const {
        return id_;
    }

    void load(std::shared_ptr<Cargo> cargo) {
        cargo_.push_back(cargo);
    }

private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    std::vector<std::shared_ptr<Cargo>> cargo_;
};
