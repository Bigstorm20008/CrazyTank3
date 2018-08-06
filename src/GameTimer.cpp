#include "GameTimer.h"


GameTimer::GameTimer() : currentTimePoint_{}, previousTimePoint_{},
                         pausedAtTimePoint_{}, pausedTimeInSeconds_{ 0 },
						 isStarted_{ false }
{
}


GameTimer::~GameTimer()
{
}


void GameTimer::start()
{
	currentTimePoint_ = previousTimePoint_ = std::chrono::high_resolution_clock::now();
	isStarted_ = true;
}


void GameTimer::pause()
{
	isStarted_ = false;
	pausedAtTimePoint_ = std::chrono::high_resolution_clock::now();
}


void GameTimer::resume()
{
	currentTimePoint_ = std::chrono::high_resolution_clock::now();
	pausedTimeInSeconds_ += std::chrono::duration_cast<std::chrono::seconds>(currentTimePoint_ - pausedAtTimePoint_);
	isStarted_ = true;
}


void GameTimer::stop()
{

}


std::wstring GameTimer::getElapsedTime()
{
	std::wstring time;
	time.clear();

	if (isStarted_)
	{
		currentTimePoint_ = std::chrono::high_resolution_clock::now();
		std::chrono::seconds gameTimeInSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTimePoint_ - previousTimePoint_) - pausedTimeInSeconds_;

		std::chrono::hours elapsedHours = std::chrono::duration_cast<std::chrono::hours>(gameTimeInSeconds);

		std::chrono::minutes elapsedMinutes = std::chrono::duration_cast<std::chrono::minutes>(gameTimeInSeconds)-
			std::chrono::duration_cast<std::chrono::minutes>(elapsedHours);

		std::chrono::seconds elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(gameTimeInSeconds)-
			std::chrono::duration_cast<std::chrono::seconds>(elapsedHours)-
			std::chrono::duration_cast<std::chrono::seconds>(elapsedMinutes);

		if (elapsedHours.count() < 10)
		{
			time.append({ L"0" });
		}
		time.append({ std::to_wstring(elapsedHours.count()) });
		time.append({ L":" });

		if (elapsedMinutes.count() < 10)
		{
			time.append({ L"0" });
		}
		time.append({ std::to_wstring(elapsedMinutes.count()) });
		time.append({ L":" });

		if (elapsedSeconds.count() < 10)
		{
			time.append({ L"0" });
		}
		time.append({ std::to_wstring(elapsedSeconds.count()) });
	}

	return std::move(time);
}