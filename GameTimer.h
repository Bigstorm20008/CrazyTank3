#ifndef GAME_TIMER_H
#define GAME_TIMER_H

#include <chrono>
#include <string>

class GameTimer
{
public:
	GameTimer();
	~GameTimer();

	void start();
	void pause();
	void stop();
	void resume();
	std::wstring getElapsedTime();

private:
	std::chrono::high_resolution_clock::time_point currentTimePoint_;
	std::chrono::high_resolution_clock::time_point previousTimePoint_;
	std::chrono::high_resolution_clock::time_point pausedAtTimePoint_;
	std::chrono::seconds pausedTimeInSeconds_;
	bool isStarted_;
	bool isPaused_;

};

#endif // !GAME_TIMER_H



