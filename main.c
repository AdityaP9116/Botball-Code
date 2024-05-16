#include "movement.h"
#include <kipr/wombat.h>
#include "constants.h"
#include "effectors.h"

int main()
{

    create_connect();
    printf("Connected to create");
    create_full();
    enable_servos();
    
	
    printf("test");
    printf("test2");
    
    forward(75, 20); //adjust tournament day to prevent rub
    CW(50, 10);  //adjust to prevent rub
    CW(50, 38);
    
    
    move_servo_slow(SHOULDER, SHOULDER_RUN, 20);
    move_servo_slow(WRIST, WRIST_RUN, 20);
    move_servo_slow(CLAW, CLAW_OPEN, 20);
    
    forward(100, 700);
    CCW(50, 100);
    backward( 100, 300);
    move_servo_slow(CLAW, CLAW_BULLDOZE, 20);
    move_servo_slow(SHOULDER, SHOULDER_BULLDOZE, 20);
    move_servo_slow(WRIST, WRIST_BULLDOZE, 20);
    CW(50, 3);
    forward(100, 200);
    move_servo_slow(SHOULDER, SHOULDER_RUN, 20);
    move_servo_slow(WRIST, WRIST_RUN, 20);
    move_servo_slow(CLAW, CLAW_OPEN, 20);
    backward(100, 500);
    forward(100, 50);
    CW(50, 45); //change on competition day
    forward(50, 75); //change on competitiond day
    move_servo_slow(CLAW, CLAW_BULLDOZE, 20);
    move_servo_slow(SHOULDER, SHOULDER_BULLDOZE, 20);
    move_servo_slow(WRIST, WRIST_BULLDOZE, 20);
    forward(50,55);
    move_servo_slow(CLAW, CLAW_CLOSE, 20);
    CW(25,45);
    move_servo_slow(CLAW, CLAW_BULLDOZE, 20);
    CCW(25,7);
    move_servo_slow(SHOULDER, SHOULDER_SET, 20);
    
    backward(100, 160);
    CCW(50, 95);
    backward(100, 350);
    forward(50, 50);
    CW(50, 90); //change based on drift
    move_servo_slow(SHOULDER, SHOULDER_BULLDOZE, 20);
    move_servo_slow(WRIST, WRIST_BULLDOZE, 20);
    //CCW(25,5); uncomment based on battery levels turn right before line follow black towards PVC land
    drive_to_black(50);
    forward(100, 100);
    line_follow_for_distance(100, 375);
    move_servo_slow(CLAW, CLAW_MIDCLOSE, 20);
    forward(50,20);
    drive_direct_dist(50, 125, 380);
    move_servo_slow(CLAW, CLAW_BULLDOZE, 20);
    forward(50,65);
    move_servo_slow(CLAW, CLAW_MIDCLOSE, 20);
    drive_direct_dist(110, 50, 333);
    //CW(30, 18);
    //forward(50,350);
    backward(150, 75);
    move_servo_slow(SHOULDER, SHOULDER_RUN, 20);
    backward(150,325);
    /*
    CW(100, 165);
    backward(200,690);
    drive_to_black(50);
    forward(50,75);
    CW(50,105);
    forward(100,175);
    */
    CCW(100,145);
    drive_to_black(50);
    forward(100,150);
    CW_to_black(50,0);
    forward_to_bump(75);
    backward(100,135);
    CW(50,17);
    move_servo_slow(WRIST, WRIST_BLOCK, 20);
    forward(100, 27);
    move_servo_slow(CLAW, CLAW_BLOCKCLOSE, 50);
    backward(100, 100);
    CW(100, 100);
    forward_to_bump(500);
    backward(200, 100);
    CCW(100, 95);
    forward(100, 50);
    move_servo_slow(SHOULDER, SHOULDER_SET, 50);
    move_servo_slow(CLAW, CLAW_BULLDOZE, 50);
    

    
    
    


    
    
    
    
    /*
    move_servo_slow(CLAW, CLAW_MIDCLOSE, 20);
    CCW(30,20);
    move_servo_slow(CLAW, CLAW_BULLDOZE, 20);
    CW(30,15);

    forward(100,40);
    move_servo_slow(CLAW, CLAW_MIDCLOSE, 20);
    forward(50,450);
    */

    
    /*
    move_servo_slow(CLAW, CLAW_MIDCLOSE, 20);
    move_servo_slow(CLAW, CLAW_BULLDOZE, 20);
    forward(50,50);
    CCW(50,20);
    move_servo_slow(CLAW, CLAW_MIDCLOSE, 20);
    move_servo_slow(CLAW, CLAW_BULLDOZE, 20);
    forward(50,50)
    */
    

    
    printf("test");
    msleep(2000);
    
    

    
    disable_servos();
    create_disconnect();
    return 0;
}
