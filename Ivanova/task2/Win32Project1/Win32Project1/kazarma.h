#pragma once
#include "stdafx.h"
#include "character.h"
#include <memory>
using namespace std;

class kazarma {
public:

	unique_ptr<knight> allocate_knight(int strength, int stamina, int speed) {
		return unique_ptr<knight>(new knight(strength, stamina, speed));
	}

	unique_ptr<archer> allocate_archer(int strength, int stamina, int speed) {
		return unique_ptr<archer>(new archer(strength, stamina, speed));
	}

	unique_ptr<farmer> allocate_farmer(int strength, int stamina, int speed) {
		return unique_ptr<farmer>(new farmer(strength, stamina, speed));
	}
};