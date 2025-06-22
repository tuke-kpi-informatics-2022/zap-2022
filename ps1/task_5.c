#include <superkarel.h>

#define MAP_NAME "task_5.kw"
#define ZERO_SPEED 0
#define NORMAL_SPEED 25

void turn_right();
void turn_around();
void move_to_border();
void move_to_the_upper_left_border();
void put_beepers_near_border();
void find_the_border_center();
void find_the_center_of_the_map();
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

    move_to_the_upper_left_border();
    put_beepers_near_border();
    find_the_center_of_the_map();
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

void move_to_border()
{
    while (front_is_clear())
    {
        step();
    }
}

void move_to_the_upper_left_border()
{
    while (not_facing_north())
    {
        turn_left();
    }

    move_to_border();

    while (not_facing_west())
    {
        turn_left();
    }

    move_to_border();
}

void put_beepers_near_border()
{
    while (no_beepers_present())
    {
        put_beeper();

        if (front_is_blocked())
        {
            turn_left();
        }

        step();
    }
}

void find_the_border_center()
{
    if (front_is_clear())
    {
        set_step_delay(ZERO_SPEED);

        step();
        step();
        find_the_border_center();

        if (facing_south() || facing_east())
        {
            turn_around();
        }

        step();

        set_step_delay(NORMAL_SPEED);
    }
}

void find_the_center_of_the_map()
{
    move_to_the_upper_left_border();
    turn_around();

    find_the_border_center();

    while (not_facing_south())
    {
        turn_left();
    }
    find_the_border_center();

    while (not_facing_north())
    {
        turn_left();
    }
}
