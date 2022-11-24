#ifndef _DURATION_CLASS_H_
#define _DURATION_CLASS_H_

/* a */
class Duration
{
    private:
        int time;
        
        int alarm;
        bool alarmHasBeenSet;

    public:
        Duration();
        ~Duration();

        Duration(int t);

        int getDuration();

        bool tick();

        bool tick(int dt);

        void setAlarm(int t);

        bool checkAndUpdateAlarm();
};

#endif