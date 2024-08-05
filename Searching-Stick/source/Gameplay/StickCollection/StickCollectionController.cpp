// Some code
#include "Gameplay/StickCollection/StickCollectionController.h"

#include <random>

#include "Global/ServiceLocator.h"

//Some Code
void Gameplay::Collection::StickCollectionController::shuffleSticks()
{
	std::random_device device;
	std::mt19937 random_engine(device());

	std::shuffle(sticks.begin(), sticks.end(), random_engine);
}

void Gameplay::Collection::StickCollectionController::resetSticksColor()
{
	for (int i = 0; i < sticks.size(); i++)
		sticks[i]->stick_view->setFillColor(collection_model->element_color);
}

void Gameplay::Collection::StickCollectionController::resetVariables()
{
	number_of_comparisons = 0;
	number_of_array_access = 0;
}

void Gameplay::Collection::StickCollectionController::resetSearchStick()
{
	stick_to_search = sticks[std::rand() % sticks.size()];
	stick_to_search->stick_view->setFillColor(collection_model->search_element_color);
}

void Gameplay::Collection::StickCollectionController::processLinearSearch()
{

	for (int i = 0; i < sticks.size(); i++)
	{

		number_of_array_access += 1;
		number_of_comparisons++;

		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::COMPARE_SFX);

		if (sticks[i] == stick_to_search)
		{
			stick_to_search->stick_view->setFillColor(collection_model->found_element_color);
			stick_to_search = nullptr;
			return;
		}
		else
		{
			sticks[i]->stick_view->setFillColor(collection_model->processing_element_color);
			sticks[i]->stick_view->setFillColor(collection_model->element_color);
		}

	}
}

//Some Code

void Gameplay::Collection::StickCollectionController::reset()
{

	shuffleSticks();
	updateSticksPosition();
	resetSticksColor();
	resetSearchStick();
	resetVariables();
}

void Gameplay::Collection::StickCollectionController::searchElement(SearchType search_type)
{
	this->search_type = search_type;

	switch (search_type)
	{
	case Gameplay::Collection::SearchType::LINEAR_SEARCH:
		processLinearSearch();
		break;
	}
}

SearchType Gameplay::Collection::StickCollectionController::getSearchType()
{
	return search_type;
}

int Gameplay::Collection::StickCollectionController::getNumberOfComparisons()
{
	return number_of_comparisons;
}

int Gameplay::Collection::StickCollectionController::getNumberOfArrayAccess()
{
	return number_of_array_access;
}

int Gameplay::Collection::StickCollectionController::getNumberOfSticks()
{
	return collection_model->number_of_elements;
}

	}
}