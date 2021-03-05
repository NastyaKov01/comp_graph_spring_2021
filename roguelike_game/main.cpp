#include "common.h"
#include "Image.h"
#include "Player.h"
#include "drawmap.h"

#define GLFW_DLL
#include <algorithm>
#include <GLFW/glfw3.h>

constexpr GLsizei WINDOW_WIDTH = 1024, WINDOW_HEIGHT = 672;
const float death = 3.0;
float death_timer = 0.0;

struct InputState
{
  bool keys[1024]{}; //массив состояний кнопок - нажата/не нажата
  GLfloat lastX = 400, lastY = 300; //исходное положение мыши
  bool firstMouse = true;
  bool captureMouse         = true;  // Мышка захвачена нашим приложением или нет?
  bool capturedMouseJustNow = false;
} static Input;


GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;
int **tiles;
int *treasures;
int m = 0;
int n = 0;

void OnKeyboardPressed(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		if (action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
		break;
    case GLFW_KEY_1:
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        break;
    case GLFW_KEY_2:
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        break;
	default:
		if (action == GLFW_PRESS)
            Input.keys[key] = true;
		else if (action == GLFW_RELEASE)
            Input.keys[key] = false;
	}
}

void processPlayerMovement(Player &player, Image &screen, Image &copy, bool &wood)
{
    if (Input.keys[GLFW_KEY_W])
        player.ProcessInput(MovementDir::UP, screen, copy, tiles, treasures, wood, m, n);
    else if (Input.keys[GLFW_KEY_S])
        player.ProcessInput(MovementDir::DOWN, screen, copy, tiles, treasures, wood, m, n);
    if (Input.keys[GLFW_KEY_A])
        player.ProcessInput(MovementDir::LEFT, screen, copy, tiles, treasures, wood, m, n);
    else if (Input.keys[GLFW_KEY_D])
        player.ProcessInput(MovementDir::RIGHT, screen, copy, tiles, treasures, wood, m, n);
}

void OnMouseButtonClicked(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
        Input.captureMouse = !Input.captureMouse;

    if (Input.captureMouse)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        Input.capturedMouseJustNow = true;
    }
    else
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void OnMouseMove(GLFWwindow* window, double xpos, double ypos)
{
    if (Input.firstMouse)
    {
        Input.lastX = float(xpos);
        Input.lastY = float(ypos);
        Input.firstMouse = false;
    }

    GLfloat xoffset = float(xpos) - Input.lastX;
    GLfloat yoffset = Input.lastY - float(ypos);

    Input.lastX = float(xpos);
    Input.lastY = float(ypos);
}


void OnMouseScroll(GLFWwindow* window, double xoffset, double yoffset)
{
  // ...
}


int initGL()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize OpenGL context" << std::endl;
		return -1;
	}

	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    std::cout << "Controls: "<< std::endl;
    std::cout << "press right mouse button to capture/release mouse cursor  "<< std::endl;
    std::cout << "W, A, S, D - movement  "<< std::endl;
    std::cout << "press ESC to exit" << std::endl;

	return 0;
}

int main(int argc, char** argv)
{
	if(!glfwInit())
    return -1;

//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow*  window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Castle treasure", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window); 

	glfwSetKeyCallback        (window, OnKeyboardPressed);  
	glfwSetCursorPosCallback  (window, OnMouseMove); 
    glfwSetMouseButtonCallback(window, OnMouseButtonClicked);
	glfwSetScrollCallback     (window, OnMouseScroll);

	if(initGL() != 0) 
		return -1;
	
  //Reset any OpenGL errors which could be present for some reason
	GLenum gl_error = glGetError();
	while (gl_error != GL_NO_ERROR)
		gl_error = glGetError();

	Point starting_pos{.x = 32, .y = 32};
	Player player{starting_pos};

	Image screenBuffer(WINDOW_WIDTH, WINDOW_HEIGHT, 4);
    Image playerPic("./resources/player.png");

    treasures = new int[7];
    std::fill(treasures, treasures + 7, 0);
    tiles = new int*[mapHeight * WINDOW_HEIGHT/tileSize];
    for (int i = 0; i < mapHeight * WINDOW_HEIGHT/tileSize; ++i) {
        tiles[i] = new int[mapWidth * WINDOW_WIDTH/tileSize];
    }  
    bool wood = false;
    ReadMap("./maps/map.txt", tiles);
    DrawRoom(screenBuffer, tiles, wood, m , n);
    Image copy(screenBuffer);

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);  GL_CHECK_ERRORS;
    glClearColor(176.0f, 196.0f, 222.0f, 1.0f); GL_CHECK_ERRORS;
    glClear(GL_COLOR_BUFFER_BIT);

  //game loop
	while (!glfwWindowShouldClose(window))
	{
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
        glfwPollEvents();

        processPlayerMovement(player, screenBuffer, copy, wood);
        player.Draw(playerPic, screenBuffer, copy);
        
        if (player.Killed()) {
            death_timer += deltaTime;
            if (death_timer > death) {
                return 0;
            }
        }
        
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); GL_CHECK_ERRORS;
        glDrawPixels (WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, screenBuffer.Data()); GL_CHECK_ERRORS;

		glfwSwapBuffers(window);
	}
    for (int i = 0; i < WINDOW_HEIGHT/tileSize; ++i) {
        delete [] tiles[i];
    }
    delete [] tiles;
    delete [] treasures;
	glfwTerminate();
	return 0;
}
