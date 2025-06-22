#include <superkarel.h>

#define MAP_NAME "task_7.kw"
#define ZERO_SPEED 0
#define NORMAL_SPEED 25

void turn_around();
void go_to_border();
void turn_right();
void put_beeper_when_warehouse_dangerous();
void put_beeper_in_finish();
void verify_warehouse();
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

    verify_warehouse();
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

void put_beeper_in_finish()
{
    set_step_delay(ZERO_SPEED);
    go_to_border();
    put_beeper();
    turn_around();
    go_to_border();
    turn_around();
    set_step_delay(NORMAL_SPEED);
}

void go_to_border()
{
    while (front_is_clear())
    {
        step();
    }
}

void verify_warehouse()
{
    put_beeper_in_finish();

    while (beepers_in_bag())
    {
        while (left_is_blocked() && front_is_clear())
        {
            step();
        }

        if (left_is_clear())
        {
            turn_left();
            step();
            put_beeper();
            put_beeper_when_warehouse_dangerous();

            if (front_is_clear())
            {
                step();
            }
        }

        if (front_is_blocked() && right_is_blocked())
        {
            break;
        }
    }
    pick_beeper();
}

void put_beeper_when_warehouse_dangerous()
{
    while (beepers_in_bag())
    {
        if (left_is_clear())
        {
            turn_left();
        }
        else if (front_is_blocked() && right_is_clear())
        {
            turn_right();
        }
        else if (front_is_blocked() && right_is_blocked() && left_is_blocked())
        {
            turn_around();
        }

        step();

        if ((facing_south() && left_is_clear() && front_is_blocked()) ||
            (right_is_clear() && facing_south() && beepers_present() &&
             front_is_blocked()))
        {
            turn_around();
            step();

            if (beepers_present())
            {
                pick_beeper();
                break;
            }
            else
            {
                put_beeper();
                break;
            }
        }
    }

    turn_around();
    step();
    turn_left();
}