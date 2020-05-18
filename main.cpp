/**
 * @author Gustavo Vicente Dauer <gustavo.dauer@hotmail.com>.
 * @name main.cpp
 * @date 17/05/2020
 */

#include <GLFW/glfw3.h>

#define SPEED 0.015f

#define COLOR_VISIBLE 100
#define COLOR_NOT_VISIBLE 0

#define RESIZE_Y 0.019f
#define RESIZE_X 0.01f

float topVertexPositionY = 0.5;
float topVertexPositionX = 0.0;

float leftVertexPositionY = -0.5;
float leftVertexPositionX = -0.5;

float rightVertexPositionY = -0.5;
float rightVertexPositionX = 0.5;

float redColorStrength = COLOR_VISIBLE;
float blueColorStrength = COLOR_VISIBLE;
float greenColorStrength = COLOR_VISIBLE;

/**
 * Move triangle to left direction.
 *
 * @return void
 */
void moveTriangleLeftDirection()
{
    topVertexPositionX = topVertexPositionX - SPEED;
    leftVertexPositionX = leftVertexPositionX - SPEED;
    rightVertexPositionX = rightVertexPositionX - SPEED;
}

/**
 * Move triangle to right direction.
 *
 * @return void
 */
void moveTriangleRightDirection()
{
    topVertexPositionX = topVertexPositionX + SPEED;
    leftVertexPositionX = leftVertexPositionX + SPEED;
    rightVertexPositionX = rightVertexPositionX + SPEED;
}

/**
 * Move triangle to up direction.
 *
 * @return void
 */
void moveTriangleUpDirection()
{
    topVertexPositionY = topVertexPositionY + SPEED;
    leftVertexPositionY = leftVertexPositionY + SPEED;
    rightVertexPositionY = rightVertexPositionY + SPEED;
}

/**
 * Move triangle to down direction.
 *
 * @return void
 */
void moveTriangleDownDirection()
{
    topVertexPositionY = topVertexPositionY - SPEED;
    leftVertexPositionY = leftVertexPositionY - SPEED;
    rightVertexPositionY = rightVertexPositionY - SPEED;
}

/**
 * Change triangle color to white.
 *
 * @return void
 */
void paintTriangleWithWhiteColor()
{
    redColorStrength = COLOR_VISIBLE;
    blueColorStrength = COLOR_VISIBLE;
    greenColorStrength = COLOR_VISIBLE;
}

/**
 * Change triangle color to red.
 *
 * @return void
 */
void paintTriangleWithRedColor()
{
    redColorStrength = COLOR_VISIBLE;
    blueColorStrength = COLOR_NOT_VISIBLE;
    greenColorStrength = COLOR_NOT_VISIBLE;
}

/**
 * Change triangle color to green.
 *
 * @return void
 */
void paintTriangleWithGreenColor()
{
    redColorStrength = COLOR_NOT_VISIBLE;
    blueColorStrength = COLOR_NOT_VISIBLE;
    greenColorStrength = COLOR_VISIBLE;
}

/**
 * Change triangle color to blue.
 *
 * @return void
 */
void paintTriangleWithBlueColor()
{
    redColorStrength = COLOR_NOT_VISIBLE;
    blueColorStrength = COLOR_VISIBLE;
    greenColorStrength = COLOR_NOT_VISIBLE;
}

/**
 * Shrink triangle size.
 *
 * @return void
 */
void shrinkTriangleSize()
{
    topVertexPositionY = topVertexPositionY - RESIZE_Y;
    leftVertexPositionX = leftVertexPositionX + RESIZE_X;
    rightVertexPositionX = rightVertexPositionX - RESIZE_X;
}

/**
 * Increase triangle size.
 *
 * @return void
 */
void increaseTriangleSize()
{
    topVertexPositionY = topVertexPositionY + RESIZE_Y;
    leftVertexPositionX = leftVertexPositionX - RESIZE_X;
    rightVertexPositionX = rightVertexPositionX + RESIZE_X;
}

/**
 * Triangle control callback function.
 *
 * Control the triangle form based on event poll from glfw.
 *
 * @param GLFWwindow* window
 * @param int         key
 * @param int         scanCode
 * @param int         action
 * @param int         mods
 */
void triangleControl(GLFWwindow* window, int key, int scanCode, int action, int mods)
{
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
        moveTriangleLeftDirection();
    } else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
        moveTriangleRightDirection();
    } else if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
        moveTriangleUpDirection();
    } else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
        moveTriangleDownDirection();
    } else if (key == GLFW_KEY_W && action == GLFW_PRESS) {
        paintTriangleWithWhiteColor();
    } else if (key == GLFW_KEY_R && action == GLFW_PRESS) {
        paintTriangleWithRedColor();
    } else if (key == GLFW_KEY_G && action == GLFW_PRESS) {
        paintTriangleWithGreenColor();
    } else if (key == GLFW_KEY_B && action == GLFW_PRESS) {
        paintTriangleWithBlueColor();
    } else if ((key == GLFW_KEY_MINUS || key == GLFW_KEY_KP_SUBTRACT) && action == GLFW_PRESS) {
        shrinkTriangleSize();
    } else if (key == GLFW_KEY_KP_ADD && action == GLFW_PRESS) {
        increaseTriangleSize();
    }
}

/**
 * Main function.
 *
 * @return int
 */
int main() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "FMU - OpenGL implementation", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Clear Background buffer */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Begin triangle form */
        glBegin(GL_TRIANGLES);

        /* Triangle RGB values */
        glColor3b(redColorStrength, greenColorStrength, blueColorStrength);

        /* Vertex creation */
        glVertex2f(topVertexPositionX, topVertexPositionY); // top vertex
        glVertex2f(leftVertexPositionX, leftVertexPositionY); // left vertex
        glVertex2f(rightVertexPositionX, rightVertexPositionY); // right vertex

        /* Listen to events */
        glfwSetKeyCallback(window, triangleControl);

        glEnd();
        glFlush();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
