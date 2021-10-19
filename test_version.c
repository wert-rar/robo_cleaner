#include <stdio.h>
#include <math.h>

float get_angle(int off_x,int off_y,float distance)
{
	// in this case distance will be hypotenuse so we can find angle using this
	printf("angle sin  %f \n",(asin(off_x/distance)/3.14)*180);
	printf("angle cos  %f \n",(asin(off_y/distance)/3.14)*180);
	return (asin(off_x/distance)/3.14)*180;
}

float get_distance(int off_x,int off_y)
{
	return sqrt(off_x*off_x + off_y*off_y);
}


void rotate(float angle)
{
	//resetGyro(gyroSensor);

	if(angle < 0)
	{
		printf("left %f  \n",angle);
	}

	if(angle > 0)
	{
	    printf("right %f \n",angle);
	}

}

void move(float distance)
{
	printf("робот проехал %f  робот повернул в ",distance);
}

float move_to_next_coord(int c_x,int c_y,int n_x,int n_y,float r_angle)
{
	// get offset of current coord and next
	int off_x = n_x - c_x;
	int off_y = n_y - c_y;

	float distance = get_distance(off_x,off_y);

	// turn the robot in the direction to next coord
	float angle = get_angle(off_x,off_y,distance);
	angle = (angle <0) ? angle + r_angle : angle - r_angle;

	rotate(-angle);// vex angle are not correct

	r_angle = angle; // change angle of robot

	move(distance);	// move the robot to next coord
	return r_angle;
}


int main()
{
    // angle between start pos and current
	float r_angle = 0;

	r_angle = move_to_next_coord(0,0,0,5,r_angle);
	//printf("angle 1  %f \n",r_angle);
	r_angle = move_to_next_coord(0,20,10,20,r_angle);
	//printf("angle 2  %f \n",r_angle);
	r_angle = move_to_next_coord(10,20,10,40,r_angle);
	//printf("angle 3  %f \n",r_angle);

	
	r_angle = move_to_next_coord(10,40,10,10,r_angle);
	//printf("angle 4  %f \n",r_angle);
	return 0;
}
