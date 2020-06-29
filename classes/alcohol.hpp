#pragma once

#include <iostream>
#include <string>

#include "cargo.h"

class Alcohol : public Cargo {
	private:
		const int32_t maxAlcohol_{96};
		uint32_t power_;

	public:
		Alcohol(uint32_t amount, const std::string& name, uint32_t basePrice, int32_t power);

		~Alcohol() override = default;

		std::string getName() const override;
		uint32_t getAmount() const override;
		uint32_t getBasePrice() const override;
		double getPrice() const override;
		int32_t getPower() const override;

		Cargo& operator += (uint32_t amount) override;
		Cargo& operator -= (uint32_t amount) override;
		bool operator == (const Cargo& cargo) const override;
}

