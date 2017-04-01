#pragma once
#include "stdafx.h"
#include "character.h"
#include <memory>
using namespace std;

class kazarma {
public:

	unique_ptr<knight> allocate_knight() {
		return unique_ptr<knight>(new knight()); 

	}

	unique_ptr<archer> allocate_archer() {
		return unique_ptr<archer>(new archer()); 
	}

	unique_ptr<farmer> allocate_farmer() {
		return unique_ptr<farmer>(new farmer());
	}
};