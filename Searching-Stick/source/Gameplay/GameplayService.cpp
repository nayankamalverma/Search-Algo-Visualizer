#include "Gameplay/GameplayService.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		
	}

	GameplayService::~GameplayService()
	{
		
	}

	void GameplayService::initialize()
	{
		initializeRandomSeed();
	}

	void GameplayService::initializeRandomSeed()
	{
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
	}


	void GameplayService::update()
	{
		
	}

	void GameplayService::render()
	{
		
	}

	void GameplayService::reset()
	{
		
	}


}
