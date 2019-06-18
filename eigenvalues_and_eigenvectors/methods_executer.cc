#include "methods_executer.h"

void execute_method( Method method ) {
	switch( method ) {
		case Method::RegularPowerMethod: return;

		case Method::InversePowerMethod: return;
	
		case Method::DisplacementPowerMethod: return;
	
		case Method::HouseHolderMethod: return;
	
		case Method::JacobiMethod: return;

		case Method::QRMethod: return;

		default: return;
	}
}