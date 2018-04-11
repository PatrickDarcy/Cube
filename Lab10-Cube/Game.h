#ifndef GAME
#define GAME

// don't forget to comment

#include <SFML/Graphics.hpp>
#include "MyVector3.h"
#include "MyMatrix3.h"


const double PI = 3.141592653589793238;
const sf::Color BLUE{ 0,151,244,255 };
const sf::Color TAN{ 251,149,0,255 };
const sf::Color YELLOW{ 252,248,0,255 };
const sf::Color RED{ 249,26,25,255 };
const sf::Color GREEN{ 0,246,0,255 };
const sf::Color PURPLE{ 145,77,176,255 };
const sf::Color PINK{ 252,150,197,255 };
const sf::Color GRAY{ 25,25,25,255 };
const sf::Color BLACK{ 0,0,0,255 };
const sf::Color WHITE{ 255,255,255,255 };

class Game
{
public:
	Game();
	void run();
private:
	void    processEvents(); // check for keys
	void    update(const sf::Time t_deltaTime); // perform rotations and culling
	void    render(); // draw screen
	void	processKeyPress(const sf::Event t_event); // handle key input
	void	showFace(const int t_index); // add the cube corners for a face to the vertex arrays
	void	drawPoint(const int t_index); // draw a black circle and the index number at the cube corner location
	bool	checkFace(const int t_index); // find out which way the face is pointing and cull or not
	void	setupText(); // set the default text properties


	sf::RenderWindow m_window; // main rendering window
	sf::VertexArray m_faces;  // vertex Array used toi draw active faces (not culled)
	sf::VertexArray m_edges; // vertex array used to draw active edges (not culled)

	sf::CircleShape m_circle; // used to indicate location of cube corners?
	sf::Text m_letter; // used to print index of cube corner
	sf::Text m_instructions; // text to display instructions
	sf::Font m_font; // font used by application

	MyVector3 m_points[8];  // hold current cube corners in 3d space
	sf::Color m_colours[6]; // stores colour for each face

	

	int m_cubeVertexs[6][4]; // index of the corners of each of the six faces
	bool m_showFace[6];  // bools to remember if a face is not culled
	
	double	m_angle; // angle amount used to rotate per key press
};

#endif // !GAME

