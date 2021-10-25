#include <stdio.h>
#include <math.h>
float  pi = 3.14;
float get_angle(float off_x,float off_y,float distance)
{
	// in this case distance will be hypotenuse, so we can find angle using th
	if (off_x > 0 && off_y > 0){
	    return acosf(off_x / distance) / pi * 180;
	}
	else if (off_x > 0 && off_y < 0){
	    return -acosf(off_x / distance) / pi * 180;
	}
	else if ( off_x < 0 && off_y > 0){
	    return 180 - acosf(off_y / distance) / pi * 180;
	}
	else if (off_x < 0 && off_y < 0){
	    return -(90 + acosf(off_y / distance) / pi * 180);
	}
	else if (off_x == 0 && off_y < 0){
	    return -90;
	}
	else if (off_x == 0 && off_y > 0){
	    return 90;
	}
	else if (off_y == 0 && off_x < 0) {
        return -180;
    }
	else {
        if (off_y == 0 && off_x > 0) {
            return 0;
        };
    }
    return 0;

}

float get_distance(float off_x,float off_y)
{
	return sqrtf(off_x*off_x + off_y*off_y);
}


void rotate(float angle)
{
	//resetGyro(gyroSensor);

//	if(angle > 0)
//	{
//		printf("left %f  \n",angle);
//	}
//
//	if(angle < 0)
//	{
//	    printf("right %f \n",angle);
//	}

}

void move(float distance)
{
	printf("distance =  %f  \n",distance);
}

float move_to_next_coord(int c_x,int c_y,int n_x,int n_y,float r_angle)
{
	// get offset of current coord and next
	float off_x = (float)(n_x - c_x);
	float off_y = (float)(n_y - c_y);

	float distance = get_distance(off_x,off_y);

	// turn the robot in the direction to next coord
	float  angle = (float)get_angle(off_x,off_y,distance);
	// change angle of robot
	r_angle = angle - r_angle;
	rotate(r_angle);



	move(distance);	// move the robot to next coord
	return angle;
}


int main()
{
    // angle between start pos and current
	float r_angle = 90;
	printf("a = %f\n",r_angle);
	r_angle = move_to_next_coord(0,0,0,5,r_angle);
    printf("a = %f\n",r_angle);
	r_angle = move_to_next_coord(0,5,0,20,r_angle);
	printf("a = %f\n",r_angle);
	r_angle = move_to_next_coord(0,20,20,40,r_angle);
	printf("a = %f\n",r_angle);
	r_angle = move_to_next_coord(20,40,10,10,r_angle);
	printf("a = %f\n",r_angle);
    printf("\nangle  = %f",r_angle);
	return 0;
}
