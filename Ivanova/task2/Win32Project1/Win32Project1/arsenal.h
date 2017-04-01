#pragma once
#include "stdafx.h"
#include "weapon.h"
#include <memory>
using namespace std;

//arsenal сделать shared_ptr-ом, т.е. кол-во людей владеющих им будет записано

class arsenal {

public:
	unique_ptr<sword> allocate_sword() {
		return unique_ptr<sword>(new sword());
	}

	unique_ptr<shovel> allocate_shovel() {
		return unique_ptr<shovel>(new shovel());
	}

	unique_ptr<bow> allocate_bow() {
		return unique_ptr<bow>(new bow());
	}

	unique_ptr<hammer> allocate_hammer() {
		return unique_ptr<hammer>(new hammer());
	}

};