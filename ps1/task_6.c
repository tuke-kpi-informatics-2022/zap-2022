#include <superkarel.h>

#define MAP_NAME "task_6.kw"
#define ZERO_SPEED 0
#define NORMAL_SPEED 25

void go_to_the_beeper();
void find_the_treasure();
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

    find_the_treasure();
    turn_off();
}

void go_to_the_beeper()
{
    while (no_beepers_present())
    {
        step();
    }
}

void find_the_treasure()
{
    while (front_is_clear())
    {
        go_to_the_beeper();
        pick_beeper();

        if (no_beepers_present())
        {
            set_step_delay(ZERO_SPEED);
            while (!facing_north())
            {
                turn_left();
            }
            set_step_delay(NORMAL_SPEED);
        }
        else
        {
            pick_beeper();

            if (!beepers_present())
            {
                set_step_delay(ZERO_SPEED);
                while (!facing_west())
                {
                    turn_left();
                }
                set_step_delay(NORMAL_SPEED);
            }
            else
            {
                pick_beeper();

                if (!beepers_present())
                {
                    set_step_delay(ZERO_SPEED);
                    while (!facing_south())
                    {
                        turn_left();
                    }
                    set_step_delay(NORMAL_SPEED);
                }
                else
                {
                    pick_beeper();
                    if (!beepers_present())
                    {
                        set_step_delay(ZERO_SPEED);
                        while (!facing_east())
                        {
                            turn_left();
                        }
                        set_step_delay(NORMAL_SPEED);
                    }
                    else
                    {
                        pick_beeper();
                        break;
                    }
                }
            }
        }
    }
}