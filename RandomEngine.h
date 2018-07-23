#ifndef RANDOM_ENGINE_H
#define RANDOM_ENGINE_H

#include<random>
#include<ctime>
#include <memory>

namespace helpers
{

	class RandomEngine
	{
	public:

		~RandomEngine();

		static std::shared_ptr<RandomEngine> getInstance();
		const int getRandomInteger(const int& startDistance, const int& endDistance);

	private:
		std::default_random_engine m_defaultRandomEngine;
		RandomEngine();
		RandomEngine(const RandomEngine&) = delete;
		void operator=(const RandomEngine&) = delete;
		static std::shared_ptr<RandomEngine> m_instance;
	};

}//namespace helpers

#endif // !RANDOM_ENGINE_H




