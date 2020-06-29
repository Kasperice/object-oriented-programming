#pragma once

#include <string>

#include "cargo.hpp"

class Item : public Cargo {

	private:
		Rarity rarity_;

	public:
		enum class Rarity { common = 1, rare = 3, epic = 6, legendary = 10 };

		Item(size_t amount, const std::string& name, size_t base_price, Rarity rarity);
		~Item() override = default;

		std::string getName() const override;
		uint32_t getAmount() const override;
		uint32_t getBasePrice() const override;
		double getPrice() const override;
		Rarity getRarity() const;
		Cargo& operator+=(uint32_t amount) override;
		Cargo& operator-=(uint32_t amount) override;
		bool operator==(const Cargo& cargo) const override;
};

