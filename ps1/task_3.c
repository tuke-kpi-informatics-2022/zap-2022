#include <superkarel.h>

#define MAP_NAME "task_3.kw"
#define ZERO_SPEED 0
#define NORMAL_SPEED 25

void turn_right();
void turn_around();
void turn_back();
bool has_beepers_right();
void collect_beepers();
void put_beepers();
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

    while (not_facing_east())
    {
        turn_left();
    }
    put_beepers();
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

void turn_back()
{
    set_step_delay(ZERO_SPEED);
    turn_around();
    step();
    turn_right();
    set_step_delay(NORMAL_SPEED);
}

bool has_beepers_right()
{
    set_step_delay(ZERO_SPEED);
    turn_right();
    step();

    if (beepers_present())
    {
        turn_back();
        return true;
    }
    else
    {
        turn_back();
        return false;
    }
}

void collect_beepers()
{
    do
    {
        step();

        if (beepers_present())
        {
            pick_beeper();
        }
    } while (front_is_clear());
}

void put_beepers()
{
    while (no_beepers_in_bag())
    {
        collect_beepers();

        if (front_is_blocked() && facing_east())
        {
            turn_around();
        }

        while (beepers_in_bag())
        {
            if (right_is_blocked() || has_beepers_right())
            {
                put_beeper();
            }
            step();
        }

        if (front_is_blocked() && facing_west())
        {
            turn_left();

            if (front_is_blocked())
            {
                break;
            }

            step();
            turn_left();
        }
    }
}

void return_to_start()
{
    while (not_facing_east())
    {
        turn_left();
    }

    while (no_beepers_present())
    {
        step();

        if (front_is_blocked())
        {
            if (facing_east())
            {
                turn_left();
                step();
                turn_left();
            }
            else if (facing_west())
            {
                turn_right();
                step();
                turn_right();
            }
        }
    }

    while (not_facing_north())
    {
        turn_left();
    }

    while (front_is_clear())
    {
        step();
    }

    turn_left();

    while (front_is_clear())
    {
        step();
    }

    turn_around();
}