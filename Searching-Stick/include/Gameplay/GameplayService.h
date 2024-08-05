#pragma once
#include <SFML/System/String.hpp>
#include "Gameplay/StickCollection/StickCollectionModel.h"
#include "Gameplay/StickCollection/StickCollectionController.h"

namespace Gameplay
{
	using namespace Collection;
	class GameplayController;
	enum class SearchType;

	class GameplayService
	{
	private:
		GameplayController* gameplay_controller;
		StickCollectionContoller* collection_controller;

		void initializeRandomSeed();

	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();

		void reset();
		void searchElement(Collection::SearchType search_type);

		Collection::SearchType getCurrentSearchType();

		int getNumberOfComparisons();
		int getNumberOfArrayAccess();
		int getNumberOfSticks();
		int getDelayMilliseconds();
		sf::String getTimeComplexity();

	};
}