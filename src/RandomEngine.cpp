#include "RandomEngine.h"

namespace helpers
{

	std::shared_ptr<RandomEngine> RandomEngine::m_instance = nullptr;

	RandomEngine::RandomEngine() 
		: m_defaultRandomEngine{ std::default_random_engine{ static_cast<unsigned int>(time(0)) } }
	{
	}


	RandomEngine::~RandomEngine()
	{
	}

	std::shared_ptr<RandomEngine> RandomEngine::getInstance()
	{

		if (m_instance == nullptr)
		{
			m_instance.reset(new RandomEngine);
		}
		return m_instance;
	}

	const int RandomEngine::getRandomInteger(const int& startDistance, const int& endDistance)
	{
		std::uniform_int_distribution<int> widthDistance(startDistance, endDistance);
		return widthDistance(m_defaultRandomEngine);
	}


}//namespace helpers