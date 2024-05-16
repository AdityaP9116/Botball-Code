#include <kipr/wombat.h>
#include "constants.h"
/*
void claw_open()
{
    set_servo_position(CLAW, CLAW_OPEN);
    msleep(750);
}

void claw_close_purp()
{
    set_servo_position(CLAW, CLAW_CLOSED_PURP);
    msleep(750);
}
*/
/*
void move_servo_slow(int port, int end_pos, int delay)
{
    int current_pos;
    current_pos = get_servo_position(port);
    if (current_pos < end_pos)
    {
        while(current_pos < end_pos)
        {
            current_pos +=7;
            set_servo_position(port, current_pos);
            msleep(delay);
        }
    }
    else
    {
        while(current_pos > end_pos)
        {
            current_pos -=7;
            set_servo_position(port, current_pos);
            msleep(delay);
        }
    }
    set_servo_position(port, end_pos);
}
*/
void move_servo_slow(int port, int end_pos, int step)
{
    int i;

    int start_pos = get_servo_position(port);
    if (start_pos > end_pos) // count down
    {
        for(i = start_pos; i > end_pos; i-=step)
        {
            set_servo_position(port, i);
            msleep(MSS_DELAY);
        }
		set_servo_position(port, end_pos);
    }
    else
    {

        for(i = start_pos; i < end_pos; i+=step)
        {
            set_servo_position(port, i);
            msleep(MSS_DELAY);
        }
        set_servo_position(port, end_pos);
    }
    

}
