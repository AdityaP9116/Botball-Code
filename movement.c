#include "constants.h"
#include <kipr/wombat.h>

void backward(int speed, int mm)
{
    set_create_distance(0);
    create_drive_straight(-speed);
    while(get_create_distance() > -mm)
    {
        //pass
        //msleep(25);
    }
    create_drive_straight(0);
}


void forward(int speed, int mm)
{
    set_create_distance(0);
    create_drive_straight(speed);
    while(get_create_distance() < mm)
    {
        //pass
    }
    create_drive_straight(0);
}

void drive_direct_dist(int lspeed, int rspeed, int mm)
{
    set_create_distance(0);
    create_drive_direct(lspeed,rspeed);
    while(get_create_distance() < mm)
    {
        //pass
    }
    create_drive_straight(0);
}

void forward_to_bump(int speed)
{

    create_drive_straight(speed);
    while(get_create_lbump()==0  && get_create_rbump()==0)
    {
        //pass
    }
    create_drive_straight(0);
}

void drive_to_black(float speed)
{
    create_drive_straight(speed);
    while (analog(TOPHAT) < BLACK)
    {
        //pass
    }
    create_drive_straight(0);
}

void turn_to_black(float speed)
{
    create_spin_CCW(speed);
    while (analog(TOPHAT) < BLACK)
    {
            create_drive_straight(speed);
    }
    create3_velocity_set_components(0,0);
}

void CCW_to_black(float speed, int port)
{
    create_spin_CCW(speed);
    while (analog(port) < BLACK)
    {
            //create_drive_straight(speed);
    }
    create_drive_direct(0,0);
}

void CW_to_black(float speed, int port)
{
    create_spin_CW(speed);
    while (analog(port) < BLACK)
    {
            //create_drive_straight(speed);
    }
    create_drive_direct(0,0);
}

void CW(int speed, int angle)
{
    set_create_total_angle(0);
    create_spin_CW(speed);
    while(get_create_total_angle() >= -angle)
    {
        //pass
        msleep(25);
    }
    create_spin_CW(0);
}

void CCW(int speed, int angle)
{
    set_create_total_angle(0);
    create_spin_CCW(speed);
    while(get_create_total_angle() < angle)
    {
        //pass
        //msleep(25);
    }
    create_spin_CCW(0);
}

void move_servo_slowly(int port, int end_pos, int delay)
{
    int current_pos;

    current_pos = get_servo_position(port);

    if (current_pos < end_pos)
    {
        while (current_pos < end_pos)
        {
            current_pos += 7;
            set_servo_position(port, current_pos);
            msleep(delay);
        }
    }
    else
    {
        while (current_pos > end_pos)
        {
            current_pos -= 7;
            set_servo_position(port, current_pos);
            msleep(delay);
        }

    }
    set_servo_position(port, end_pos);
}

void line_follow_to_black(int speed, int trigger_port)
{
    
    while( analog(trigger_port) < BLACK )
    {
        //create_spin_CCW(speed);
        if (analog(0) > BLACK)
        {
             create_spin_CW(speed);
            create_drive_direct(speed, speed);
        }
        else
        {
            create_drive_direct(speed, speed+(speed/2));
        }
    }
    create_drive_straight(0);
}

void line_follow_to_bump(int speed)
{
    
    while(get_create_lbump()==0  && get_create_rbump()==0)
    {
        create_spin_CCW(speed);
        if (analog(0) > BLACK)
        {
             create_spin_CW(speed);
        }
        else
        {
            create_drive_straight(speed);
        }
    }
    create_drive_straight(0);
}

void line_follow_for_distance(int speed, int mm)
{
    set_create_distance(0);
    create_drive_straight(speed);
    while(get_create_distance() < mm)
    {
        create_spin_CCW(speed);
        if (analog(0) > BLACK)
        {
             create_spin_CW(speed);
        }
        else
        {
            create_drive_straight(speed);
        }
    }
    create_drive_straight(0);
}
    
    
    








