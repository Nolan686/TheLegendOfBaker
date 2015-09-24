#ifndef TIMER_H
#define TIMER_h

#include <iostream>
#include <SDL.h>



class Timer
{
public:
	Timer();


	void start();
	void stop();
	void pause();
	void unpause();



	Uint32 getTicks();


	bool isStarted();

	bool isPuased();







private:


	Uint32 mStartTicks;

	Uint32 mPausedTicks;

	bool mPaused;
	bool mStarted;




};

extern Timer timer;
#endif