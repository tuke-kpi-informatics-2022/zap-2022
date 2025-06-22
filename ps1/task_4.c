#include <superkarel.h>

#define MAP_NAME "task_4.kw"
#define ZERO_SPEED 0
#define NORMAL_SPEED 25

void turn_around();
bool has_here_pillar();
void turn_back_to_down();
void make_pillar();
void repair_pillars();
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

    repair_pillars();
    turn_off();
}

void turn_around()
{
    set_step_delay(ZERO_SPEED);
    turn_left();
    set_step_delay(NORMAL_SPEED);
    turn_left();
}

bool has_here_pillar()
{
    while (front_is_clear())
    {
        if (beepers_present())
        {
            return true;
        }
        step();
    }
    return false;
}

void turn_back_to_down()
{
    set_step_delay(ZERO_SPEED);
    turn_around();

    while (front_is_clear())
    {
        step();
    }

    set_step_delay(NORMAL_SPEED);
}

void make_pillar()
{
    while (beepers_in_bag())
    {
        if (no_beepers_present())
        {
            put_beeper();
        }

        if (front_is_clear())
        {
            step();
        }
        else
        {
            break;
        }
    }
}

void repair_pillars()
{
    while (not_facing_north())
    {
        turn_left();
    }

    while (beepers_in_bag())
    {
        if (has_here_pillar())
        {
            turn_back_to_down();
            turn_around();
            make_pillar();
        }

        turn_back_to_down();

        if (left_is_clear())
        {
            turn_left();
            step();
            turn_left();
        }
        else
        {
            turn_left();
            break;
        }
    }
}