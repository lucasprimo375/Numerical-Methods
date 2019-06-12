#include "newton_cotes.h"
#include "closed_one.h"
#include "closed_two.h"

int main() {
	NewtonCotes* newtonCotes = new ClosedOne();
	newtonCotes->estimate(1.0, 2.0, 0.001);

	newtonCotes = new ClosedTwo();
	newtonCotes->estimate(1.0, 2.0, 0.001);

	return 0;
}