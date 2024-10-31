#include "../../header/Graphics/GraphicService.h"
#include "../../header/Global/Config.h"

#include <iostream>

namespace Graphics
{
	using namespace Global;
	
	GraphicService::GraphicService() { game_window = nullptr; }

	GraphicService::~GraphicService() { onDestroy(); }

	void GraphicService::initialize()
	{
		createGameWindow();
		setFrameRate(frame_rate);
	}

	void GraphicService::update(){}
	void GraphicService::render(){}

	sf::RenderWindow* GraphicService::createGameWindow()
	{
		configureVideoMode();
		game_window = new sf::RenderWindow(video_mode, game_window_title, sf::Style::Fullscreen);
		return game_window;
	}

	void GraphicService::configureVideoMode()
	{

		// Retrieve all supported fullscreen modes
		// std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();

		// sf::VideoMode selected_mode;
		// bool valid_mode_found = false;

		// // Loop through the modes to find the first valid one
		// for (const auto &mode : modes)
		// {
		// 	if (mode.isValid())
		// 	{
		// 		selected_mode = mode;
		// 		valid_mode_found = true;
		// 		std::cout << "Selected Video Mode - Width: " << mode.width
		// 				  << ", Height: " << mode.height
		// 				  << ", Bits per Pixel: " << mode.bitsPerPixel << std::endl;
		// 		break;
		// 	}
		// }

		// if (valid_mode_found)
		// {
		// 	// Create a window using the valid mode
		// 	sf::RenderWindow window(selected_mode, "Selected Fullscreen Mode", sf::Style::Fullscreen);

		// 	// Main loop (example)
		// 	while (window.isOpen())
		// 	{
		// 		sf::Event event;
		// 		while (window.pollEvent(event))
		// 		{
		// 			if (event.type == sf::Event::Closed)
		// 			{
		// 				window.close();
		// 			}
		// 		}

		// 		window.clear();
		// 		// Draw stuff here
		// 		window.display();
		// 	}
		// }
		// else
		// {
		// 	std::cout << "No valid fullscreen mode available!" << std::endl;
		// }

		//video_mode = *(new sf::VideoMode(selected_mode.width, selected_mode.height, selected_mode.bitsPerPixel));

		 video_mode = *(new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel));
	}
	
	void GraphicService::setFrameRate(int frame_rate_to_set) { game_window->setFramerateLimit(frame_rate_to_set); }

	bool GraphicService::isGameWindowOpen() { return game_window->isOpen(); }

	sf::RenderWindow* GraphicService::getGameWindow() { return game_window; }

	void GraphicService::onDestroy()
	{
		delete(game_window);
	}
}