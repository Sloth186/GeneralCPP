//
// Created by scrot on 3/20/2025.
//

#include <cstdlib>
#include "Die.h"

Die::Die() : sides(2) {}

Die::Die(int sides) : sides(sides) {}

int Die::roll() {
	return rand() % sides + 1;
}