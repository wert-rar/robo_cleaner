#include <stdio.h>
#include <math.h>

typedef struct  
{
    float x;
    float y;
} vector;

typedef struct {
    vector coords[];
    int  length;
}coords_array;

//constants
float  diameter = 63; // wheel diameter in mm
float robot_angle = 0; // robot rotation relative to coords
float wheel_l =  0; // length of wheel
float pi  = 3.14;
// in future data will be sent from server
coords_array get_coords()
{
    int length = 6;
    vector coords[6] =  { {0,0},{0,1},{1,2},{2,2},{2,3},{1,5}};
    return {coords,length};
}


// angle between current and next robot position
float get_angle(vector offset,float distance)
{   
    // in this case distance will be hypotenuse, so we can find angle using th
    if (offset.x  > 0 && offset.y > 0){
        return acosf(off_x / distance) / pi * 180;
    }
    else if (offset.x > 0 && offset.y < 0){
        return -acosf(off_x / distance) / pi * 180;
    }
    else if ( offset.x < 0 && offset.y > 0){
        return 180 - acosf(off_y / distance) / pi * 180;
    }
    else if (offset.x < 0 && offset.y < 0){
        return -(90 + acosf(offset.y / distance) / pi * 180);
    }
    else if (offset.x == 0 && offset.y < 0){
        return -90;
    }
    else if (offset.x == 0 && offset.y > 0){
        return 90;
    }
    else if (offset.y == 0 && offset.x < 0) {
        return -180;
    }
    else {
        if (offset.y == 0 && offset.x > 0) {
            return 0;
        };
    }
    return 0;
}


// distance between current and next robot position
float get_distance(vector offset)
{   
    return sqrtf(offset.x*offset.x + offset.y*offset.y);
}


// rotate robot to current angle
void rotate(float angle)
{
    //resetGyro(gyroSensor);
    if(angle < 0)
    {
        //SetMotorSpeed(leftMotor,50);
        //SetMotorSpeed(rightMotor,-50);
        
    }
    if(angle > 0)
    {
        // SetMotorSpeed(leftMotor,50);
        //SetMotorSpeed(rightMotor,-50);
    }
    
}


// move robot to next position
void move(float distance) 
{
//    SetMotorSpeed(leftMotor,50);
//    SetMotorSpeed(rightMotor,50);
//    resetGyro(GyroSencor);
//    while(GetMotorEncoder(leftMotor) < distance / wheel_l)
}


void move_to_next_coord(vector current, vector next)
{
   // get offset of current coord and next
   vector offset = {next.x - current.x,next.y - current.y};
   
   float distance = get_distance(offset);
   float angle = get_angle(offset,distance);

   robot_angle = angle - robot_angle; // merge global angle of robot and current
   //angle = (angle <0) ? angle + robot_angle : angle - robot_angle;
   rotate(robot_angle);

   robot_angle = angle; // change angle of robot
   move(distance);      // move the robot to next coord
}


void move_by_coords(coords_array coordsArray)
{
    vector robot_pos = coordsArray.coords[0];
    for(int i = 1;i<coordsArray.length;i++)
    {
        move_to_next_coord(robot_pos, coordsArray.coords[i]);
        robot_pos = coordsArray.coords[i];
    }
}


int main()
{
    coords_array  nav = get_coords();
    move_by_coords(nav);
    return 0;
}
