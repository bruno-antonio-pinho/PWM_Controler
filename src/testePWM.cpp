#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/v3.0/BlackPWM.h"

using namespace std;

int init(BlackLib::BlackPWM& Motor1_FW, BlackLib::BlackPWM& Motor2_FW, BlackLib::BlackPWM& Motors_BW){

	Motors_BW.setPeriodTime(500, BlackLib::microsecond);
	Motors_BW.setDutyPercent(0.0);
	Motor2_FW.setPeriodTime(500, BlackLib::microsecond);
	Motor2_FW.setDutyPercent(50.0);
	Motor1_FW.setPeriodTime(500, BlackLib::microsecond);
	Motor1_FW.setDutyPercent(50.0);

	return 1;
}


char* receiver(){

	int sockfd;
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in server, client;

	server.sin_family = AF_INET;
	server.sin_port = htons(5507);
	server.sin_addr.s_addr = inet_addr("172.18.131.50");

	char* buffer = new char[256];
	socklen_t l = sizeof(client);

	int rc;

	rc = bind (sockfd, (struct sockaddr *) &server, sizeof(server));
	rc = recvfrom(sockfd, buffer, 256, 0, (struct sockaddr *)&client, &l);

	if(rc < 0){

		cout << "ERROR READING FROM SOCKET";

	}

	close(sockfd);
	return buffer;

}


/*int robot_direction(BlackLib::BlackPWM& Motor1_FW, BlackLib::BlackPWM& Motor2_FW, BlackLib::BlackPWM& Motors_BW, int direction){

	switch(direction){

		case 2:
			Motor1_FW.setRunState(BlackLib::run);
			Motor2_FW.setRunState(BlackLib::stop);
			Motors_BW.setRunState(BlackLib::stop);

		case 3:
                	Motor1_FW.setRunState(BlackLib::stop);
                        Motor2_FW.setRunState(BlackLib::run);
                        Motors_BW.setRunState(BlackLib::stop);

		case 0:
                	Motor1_FW.setRunState(BlackLib::run);
                        Motor2_FW.setRunState(BlackLib::run);
                        Motors_BW.setRunState(BlackLib::stop);

        	case 1:
                	Motor1_FW.setRunState(BlackLib::stop);
                        Motor2_FW.setRunState(BlackLib::stop);
                        Motors_BW.setRunState(BlackLib::run);


        	default:
			Motor1_FW.setRunState(BlackLib::stop);
                        Motor2_FW.setRunState(BlackLib::stop);
                        Motors_BW.setRunState(BlackLib::stop);

	}

	return 1;
}


int change_speed(BlackLib::BlackPWM& Motor1_FW, BlackLib::BlackPWM& Motor2_FW, BlackLib::BlackPWM& Motors_BW, float speed){

	if(speed != Motor1_FW.getNumericValue()){

		Motor1_FW.setDutyPercent(speed);
        	Motor2_FW.setDutyPercent(speed);
       		Motors_BW.setDutyPercent(speed);

	}
	return 1;
}

int cam_direction(int direction){

        switch(direction){

                case 2:
                        Motor1_FW.setRunState(BlackLib::run);
                        Motor2_FW.setRunState(BlackLib::stop);
                        Motors_BW.setRunState(BlackLib::stop);

                case 3:
                        Motor1_FW.setRunState(BlackLib::stop);
                        Motor2_FW.setRunState(BlackLib::run);
                        Motors_BW.setRunState(BlackLib::stop);

                case 0:
                        Motor1_FW.setRunState(BlackLib::run);
                        Motor2_FW.setRunState(BlackLib::run);
                        Motors_BW.setRunState(BlackLib::stop);

                case 1:
                        Motor1_FW.setRunState(BlackLib::stop);
                        Motor2_FW.setRunState(BlackLib::stop);
                        Motors_BW.setRunState(BlackLib::run);


                default:
                        Motor1_FW.setRunState(BlackLib::stop);
                        Motor2_FW.setRunState(BlackLib::stop);
                        Motors_BW.setRunState(BlackLib::stop);

        }

	return 1;
}


int example(){

	BlackLib::BlackPWM servo(BlackLib::P9_14);
	servo.setDutyPercent(100.0);
	servo.setPeriodTime(20, BlackLib::milisecond);
	servo.setDutyPercent(50.0);
	servo.setRunState(BlackLib::run);


	usleep(500);

	cout << "PWM duty ratio : " << servo.getValue() << "%" << endl;

	while(1){

		usleep(10000);
		servo.toggleRunState();
		cout << "State : " << servo.getRunValue() <<  endl;
	}
	return 0;

}*/

int main(){

	BlackLib::BlackPWM Motor1_FW(BlackLib::P8_13);
	BlackLib::BlackPWM Motor2_FW(BlackLib::EHRPWM1A);
	BlackLib::BlackPWM Motors_BW(BlackLib::EHRPWM1B);
	init(Motor1_FW, Motor2_FW, Motors_BW);
	sleep(5);
	while(1){
		cout << Motor1_FW.getNumericValue() << endl;
		char* buffer = receiver();
		cout << "cheguei" << endl;
		for(int i = 0; i < 256; i++){

			cout << buffer[i];
		}
		cout << endl;
		Motor2_FW.setDutyPercent(80.0);
		usleep(2000);
		Motors_BW.setDutyPercent(10.0);
	}
}
