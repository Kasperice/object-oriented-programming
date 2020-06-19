#include <algorithm>
#include <memory>
#include <string>
#include <vector>

class Cargo {
public:
    // Cargo& operator+=(size_t amount) {
    //     amount_ += amount;
    //     return *this;
    // }
    // Cargo& operator-=(size_t amount) {
    //     amount_ -= amount;
    //     return *this;
    // }
    virtual double getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};

class Fruit : public Cargo {
public:
    std::string getName() const override { return name_; };
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; };
    Fruit& operator--() {
        if (currentExpiryDate_ == 0) {
            return *this;
        }
        --currentExpiryDate_;
        return *this;
    }
    double getPrice() const override { return basePrice_ * currentExpiryDate_ / expiryDate_; }

private:
    const uint32_t expiryDate_{10};
    uint32_t currentExpiryDate_{10};
};

class Alcohol : public Cargo {
public:
    std::string getName() const override { return name_; };
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; };
    double getPrice() const override { return basePrice_ * power_ / maxAlcohol_; }

private:
    const uint32_t maxAlcohol_{96};
    const uint32_t power_{95};
};

class Item : public Cargo {
public:
    enum class Rarity { common = 1, rare = 2, epic = 3, legendary = 5 };
    std::string getName() const override { return name_; };
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; };
    double getPrice() const override { return basePrice_ * static_cast<int>(rarity_); }

private:
    const Rarity rarity_ = Rarity::common;
};

class Ship {
public:
    Ship() : id_(-1) {}
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id)
        : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id) {}
    Ship(int maxCrew, int speed, size_t id) : Ship(0, maxCrew, speed, "", id) {}

    void setName(const std::string& name) { name_ = name; }

    Ship& operator-=(size_t num) {
        crew_ -= num;
        return *this;
    }
    Ship& operator+=(size_t num) {
        crew_ += num;
        return *this;
    }

    size_t getCapacity() const { return capacity_; }
    size_t getMaxCrew() const { return maxCrew_; }
    size_t getSpeed() const { return speed_; }
    std::string getName() const { return name_; }
    size_t getId() const { return id_; }

    void load(const std::shared_ptr<Cargo>& cargo) { cargo_.push_back(cargo); }

    void unload(Cargo* cargo) {
        auto it = std::find_if(begin(cargo_), end(cargo_), [cargo](const auto& ptr) { return *ptr == *cargo; });
        if (it != cargo_.end()) {
            cargo_.erase(it);
        };
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

int main() {
    Fruit fruit;
}
