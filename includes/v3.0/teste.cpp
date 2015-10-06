#include "BlackLib.h"

using namespace BlackLib;

int main(){

	BlackPWM* pwm = new BlackPWM(P8_19);
	pwm->setPeriodTime(500000);
	usleep(10000);
	pwm->setDutyPercent(50);
	sleep(240);

}
