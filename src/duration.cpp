#include "duration.h"
#include <assert.h>

/* b) Constructor with no arguments and no alarm */
Duration::Duration() /* b */
{
    time = 0; /* Initialising time to 0 */

    alarmHasBeenSet = false; /* Initialising alarmHasBeenSet to false */
}

/* c) Constructor with an argument t */
Duration::Duration(int t) 
{
    assert(t >= 0); /* t must not be negative, since time cannot be negative */
    time = t;

    alarmHasBeenSet = false; /* Initialising alarmHasBeenSet to false */
}

/* a) Returns the current value of time */
int Duration::getDuration() 
{
    return time;
}

/* e) Function incrementing time by 1 and returns the check funtion*/
bool Duration::tick() /* e */
{
    time++; /* Incrementing time */

    return checkAndUpdateAlarm(); /* Returning the boolean of the check function */
}

/* f) Function adding an integer dt to time and returns the check function */
bool Duration::tick(int dt)
{
    assert(dt > 0); /* Input has to be larger than zero */
    time += dt;     /* Adding dt to time */

    return checkAndUpdateAlarm(); /* Returning the boolean of the check function */
}

/* g) and e) Function setting an alarm */
void Duration::setAlarm(int t)
{
    if (t > time) /* If the input is larger than the current time, the alarm can be set */
    {
        alarm = t;              /* Setting alarm to t */
        alarmHasBeenSet = true; /* Updating status */
    }
}

/* i) Function checking and updating the status of the alarm */
bool Duration::checkAndUpdateAlarm()
{
    if(alarmHasBeenSet == true && time > alarm) /* If the alarm has been set and time has passed it, this statement runs */
    {
        alarmHasBeenSet = false; /* Updating status of the alarm */
        return true; /* Returning true, since time has passed the alarm */
    }
    else /* Otherwise it returns false  */
    {
        return false;
    }
}
 
Duration::~Duration(){}