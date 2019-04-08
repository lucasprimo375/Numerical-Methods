#include "user_input.h"

#ifdef __MINGW32__
	#include <Windows.h>
#endif

int main(){
	calculate_integral();

#ifdef __MINGW32__
	system("pause");
#endif

	return 0;
}
