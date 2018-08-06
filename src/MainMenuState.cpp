#include "MainMenuState.h"

namespace gamestates
{

	MainMenuState::MainMenuState(EventQueue& eventQueue,
		                         GraficsBuffer& graficsBuffer) : 
								 GameState{ eventQueue, graficsBuffer }
	{
	}


	MainMenuState::~MainMenuState()
	{
	}


	void MainMenuState::processEvent(const enumerations::Event& event)
	{	
	}


	void MainMenuState::update()
	{
	}


	void MainMenuState::initialize()
	{
		using namespace enumerations;
		using namespace helpers;


		graficsBuffer_->clear();

		const unsigned int& bufferWidth = graficsBuffer_->getWidth();
		const unsigned int& bufferHeight = graficsBuffer_->getHeight();

		constants::StatesConstans gameplayConstants;
		const std::wstring menuTitle = std::move(gameplayConstants.getMainMenuTitle());
		Point centerScreen(bufferWidth / 2, bufferHeight / 2);

		int offsetToLeft = menuTitle.length() / 2;
		int offsetToUp = 4;
		Point startTextPoint = centerScreen;
		startTextPoint.x -= offsetToLeft;
		startTextPoint.y -= offsetToUp;
		graficsBuffer_->drawText(startTextPoint, Direction::RIGHT, menuTitle);

		const std::wstring firstMenuElement = std::move(gameplayConstants.getFirstMenuElement());
		offsetToLeft = firstMenuElement.length() / 2;
		int offsetToDown = 2;
		startTextPoint.x = centerScreen.x - offsetToLeft;
		startTextPoint.y += offsetToDown;
		graficsBuffer_->drawText(startTextPoint, Direction::RIGHT, firstMenuElement);

		const std::wstring secondMenuElement = std::move(gameplayConstants.getSecondMenuElement());
		offsetToLeft = secondMenuElement.length() / 2;
		startTextPoint.x = centerScreen.x - offsetToLeft;
		startTextPoint.y += offsetToDown;
		graficsBuffer_->drawText(startTextPoint, Direction::RIGHT, secondMenuElement);
	}

}//namespace gamestates