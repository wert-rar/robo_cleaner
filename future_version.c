#include <stdio.h>
#include <math.h>

typedef struct  
{
    float x;
    float y;
} vector;

// robot rotation relative to coords
float robot_angle = 0;
float wheel_l =  0;
typedef struct {
    vector coords[];
    int  length;
}coords_array;

coords_array get_coords()
{
    int length = 6;
    vector coords[6] =  { {0,0},{0,1},{1,2},{2,2},{2,3},{1,5}};
    return {coords,length};
}
float get_angle(vector offset,float distance)
{   
    // in this case distance will be hypotenuse so we can find angle using this
    return (float)(asinf(offset.x/distance)/3.14f)*180;
}

float get_distance(vector offset)
{   
    return sqrtf(offset.x*offset.x + offset.y*offset.y);
}


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
   
   // turn the robot in the direction to next coord
   float angle = get_angle(offset,distance);
   
   angle = (angle <0) ? angle + robot_angle : angle - robot_angle;
   
   rotate(angle);
   
   // change angle of robot
   robot_angle = angle;
   
   // move the robot to next coord
   move(distance);
}

void move_by_coords(vector coords[], int len)
{
    vector robot_pos = coords[0];
    for(int i = 1;i<len;i++)
    {
        move_to_next_coord(robot_pos, coords[i]);
        robot_pos = coords[i];
    }
}


int main()
{

    vector coords[6] = { {0,0},{0,1},{1,2},{2,2},{2,3},{1,5}};

    move_by_coords(coords,6);
    return 0;
}
