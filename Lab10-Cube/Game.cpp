#include "Game.h"

Game::Game()
	: m_window{ sf::VideoMode{ 400, 440 }, "Lab8 Cube" },
	m_faces{ sf::Quads },
	m_edges{ sf::Lines },
	m_circle{ 6.0f },
	m_letter{},
	m_instructions{},
	m_font{},
	m_points{
		{ -111.222, -70.8045, -42.6197 },
		{ -5.26656, -121.78, 65.8928 },
		{ 8.62074, -21.7196, -136.579 },
		{ 114.576, -72.6952, -28.0669 },
		{ 5.26656, 121.78, -65.8928 },
		{ 111.222, 70.8045, 42.6197 },
		{ -114.576, 72.6952, 28.0669 },
		{ -8.62074, 21.7196, 136.579 } },
		m_colours{ YELLOW,BLUE,TAN,PINK,GREEN,RED },
		m_cubeCorners{
			{ 2, 3, 1, 0 },
			{ 4, 5, 3, 2 },
			{ 0, 6, 4, 2 },
			{ 1 ,3 ,5 ,7 },
			{ 0, 1, 7, 6 },
			{ 6, 7, 5, 4 } },
			m_showFace{ {false} }, // sets all siz to false
			m_angle{ PI / 36.0 },  // 5 degrees
			m_cubeVertexs{
				{m_points[2], sf::Color(RED)},
				{m_points[3], sf::Color(RED)},
				{m_points[1], sf::Color(RED)},
				{m_points[0], sf::Color(RED)},
				{m_points[4], sf::Color(YELLOW)},
				{m_points[5], sf::Color(YELLOW)},
				{m_points[3], sf::Color(YELLOW)},
				{m_points[2], sf::Color(YELLOW)},
				{m_points[0], sf::Color(TAN)},
				{m_points[6], sf::Color(TAN)},
				{m_points[4], sf::Color(TAN)}, 
				{m_points[2], sf::Color(TAN)},
				{m_points[1], sf::Color(BLUE)},
				{m_points[3], sf::Color(BLUE)},
				{m_points[5], sf::Color(BLUE)},
				{m_points[7], sf::Color(BLUE)},
				
{
	setupText();	
}
/// <summary>
/// load the font and setup the text properties
/// </summary>
void Game::setupText()
{
	if (!m_font.loadFromFile("c:\\windows\\fonts\\ariblk.ttf"))
	{
		std::cout << "problem with font" << std::endl;
	}
	m_letter.setFont(m_font);
	m_letter.setFillColor(WHITE);
	m_letter.setCharacterSize(10);
	m_circle.setFillColor(BLACK);
	m_instructions.setFont(m_font);
	m_instructions.setFillColor(BLACK);
	m_instructions.setCharacterSize(18);
	m_instructions.setPosition(30, 360);
	m_instructions.setString("Press X,Y,Z to rotate clockwise \nshift for anticlockwise  \nP to print current co-ordinates");
}

/// <summary>
/// game run loop 
/// 60 frames per second
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

/// <summary>
/// process window events
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		if (event.type == event.KeyPressed)
		{
			processKeyPress(event);
		}
	}
}

/// <summary>
/// rotate by 5 degrees based on key or print co-ordinates to command window
/// if P key pressed
/// </summary>
/// <param name="t_event">sf event with key press</param>
void Game::processKeyPress(const sf::Event t_event)
{
	if (sf::Keyboard::Z == t_event.key.code)
	{		
		//about z axis
		if (t_event.key.shift)
		{
		// backwards
		}
		for (int i = 0; i < 8; i++)
		{
			//rotate
		}
	}	
}
/// <summary>
/// game update loop clear vertexarrays
/// check for culled faces and add non culled ones
/// </summary>
/// <param name="deltaTime">delta time 1/60 second</param>
void Game::update(const sf::Time t_deltaTime)
{
	m_edges.clear();
	m_faces.clear();
	for (int i = 0; i < 6; i++)
	{
		if (checkFace(i))
		{
			showFace(i);
		}
	}	
}
/// <summary>
/// check if face is facing towards positive Z direction were camera is
/// get two vector pointing away from corner, counterclockwise order
/// sign of Z in crossproduct will determine culling or not
/// svae result in m_showFace
/// </summary>
/// <param name="t_index">No of Face 0-5</param>
/// <returns>true if pointing towards camera</returns>
bool Game::checkFace(const int t_index)
{
	return m_showFace[t_index];
}

/// <summary>
/// add a face/quad/4 vertices to the vertex array using the associated colour
/// add the edges to the edge vertexarray for that face 4 lines
/// </summary>
/// <param name="t_index">No of face 0-5</param>
void Game::showFace(const int t_index)
{
	sf::Vector2f offset{ 200,200 }; // offset from origin	
}

/// <summary>
/// Draw the cube faces then the edges
/// then the points for each non culled face
/// some points may be drawn twice
/// </summary>
void Game::render()
{
	m_window.clear(WHITE);
	m_window.draw(m_faces);
	m_window.draw(m_edges);
	//...
	m_window.draw(m_instructions);
	m_window.display();
}



/// <summary>
/// Draws a black circle a little up and the left
/// then a white number corresponding to the
/// cornerr number / index
/// </summary>
/// <param name="t_index">0-7 which corner of cube</param>
void Game::drawPoint(const int t_index)
{
	
}


