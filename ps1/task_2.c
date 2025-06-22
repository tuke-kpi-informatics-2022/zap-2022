#include <superkarel.h>

#define MAP_NAME "task_2.kw"
#define ZERO_SPEED 0
#define NORMAL_SPEED 25

void turn_right();
void turn_around();
void collect_beeper();
void return_to_start();
void run_karel();

int main()
{
    run_karel();
    return 0;
}

void run_karel()
{
    turn_on(MAP_NAME);

    set_step_delay(NORMAL_SPEED);

    collect_beeper();
    return_to_start();
    turn_off();
}

void turn_right()
{
    set_step_delay(ZERO_SPEED);
    turn_left();
    turn_left();
    set_step_delay(NORMAL_SPEED);
    turn_left();
}

void turn_around()
{
    set_step_delay(ZERO_SPEED);
    turn_left();
    set_step_delay(NORMAL_SPEED);
    turn_left();
}

void collect_beeper()
{
    while (not_facing_east())
    {
        turn_left();
    }

    while (no_beepers_present())
    {
        if (left_is_clear())
        {
            turn_left();
        }
        step();
    }

    if (beepers_present())
    {
        pick_beeper();
    }
}

void return_to_start()
{
    turn_around();
    step();

    while (beepers_in_bag())
    {
        if (front_is_blocked() && right_is_blocked() && left_is_blocked())
        {
            break;
        }
        else if (right_is_clear())
        {
            turn_right();
        }

        step();
    }
}
