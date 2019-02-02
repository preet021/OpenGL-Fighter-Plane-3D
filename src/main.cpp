#include "main.h"
#include "timer.h"
#include "plane.h"
#include "ground.h"
#include "fish.h"
#include "fan.h"
#include "dashboard.h"
#include "needle.h"
#include <algorithm>

#define INF 100000
#define NO_OF_FISHES 100
using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Needle needle[3];
Fan fan;
Plane plane;
Ground ground;
Fish fishes[NO_OF_FISHES];
Dashboard db;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0, ea, eb, ec, ta, tb, tc, ua, ub, uc;
bool plane_view = 0, follow_cam_view = 1, top_view = 0, heli_cam_view = 0, tower_view = 0;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    glm::vec3 eye (ea, eb, ec);
    glm::vec3 eye1 (0, 0, 10);
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (ta, tb, tc);
    glm::vec3 target1 (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (ua, ub, uc);
    glm::vec3 up1 (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    Matrices.view = glm::lookAt( eye1, target1, up1 ); // Rotating Camera for 3D
    glm::mat4 VP1 = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    plane.draw(VP);
    ground.draw(VP);
    for (int i=0; i<NO_OF_FISHES; ++i) {
        fishes[i].draw(VP);
    }
    fan.draw(VP, fan.position.x - plane.position.x, fan.position.y - plane.position.y, fan.position.z - plane.position.z);
    db.draw(VP1);
    needle[0].draw(VP1);
    needle[1].draw(VP1);
    needle[2].draw(VP1);
}

void tick_input(GLFWwindow *window) {
    
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    int space = glfwGetKey(window, GLFW_KEY_SPACE);
    int h = glfwGetKey(window, GLFW_KEY_H);
    int a = glfwGetKey(window, GLFW_KEY_A);
    int d = glfwGetKey(window, GLFW_KEY_D);
    int q = glfwGetKey(window, GLFW_KEY_Q);
    int e = glfwGetKey(window, GLFW_KEY_E);
    int w = glfwGetKey(window, GLFW_KEY_W);
    
    if (left) {
        plane_view = tower_view = follow_cam_view = heli_cam_view = top_view = 0;
        plane_view = 1;
    }

    if (right) {
        plane_view = tower_view = follow_cam_view = heli_cam_view = top_view = 0;
        top_view = 1;
    }

    if (up) {
        plane_view = tower_view = follow_cam_view = heli_cam_view = top_view = 0;
        follow_cam_view = 1;
    }

    if (down) {
        plane_view = tower_view = follow_cam_view = heli_cam_view = top_view = 0;
        tower_view = 1;
    }

    if (h) {
        plane_view = tower_view = follow_cam_view = heli_cam_view = top_view = 0;
        heli_cam_view = 1;
    }

    if (d) {
        if (plane.rotation.z > -plane.maxtilt)
            plane.rotation.z -= plane.tilt;
    }

    else if (a) {
        if (plane.rotation.z < plane.maxtilt)
            plane.rotation.z += plane.tilt;
    }

    else if (q) {
        if (plane.rotation.z < plane.maxtilt)
            plane.rotation.z += plane.tilt;
        plane.rotation.y += plane.tilt;
    }

    else if (e) {
        if (plane.rotation.z > -plane.maxtilt)
            plane.rotation.z -= plane.tilt;
        plane.rotation.y -= plane.tilt;
    }

    else if (w) {
        plane.speed_z += plane.acc_z;
        if (plane.speed_z > 3) plane.speed_z = 3;
        plane.position.z -= plane.speed_z * cos(plane.rotation.y * M_PI / 180.0);
        plane.position.x -= plane.speed_z * sin(plane.rotation.y * M_PI / 180.0);
    }

    else if (space) {
        plane.rotation.z = 0;
        plane.position.y += 0.5;
    }

    else if (plane.rotation.z > 0) plane.rotation.z -= plane.tilt;

    else if (plane.rotation.z < 0) plane.rotation.z += plane.tilt;

    ua = 0; ub = 1; uc = 0;

    if (plane_view) {
        ea = plane.position.x - 1.5 * plane.flength * sin(plane.rotation.y * M_PI / 180.0);
        eb = plane.position.y + 10;
        ec = plane.position.z - 1.5 * plane.flength * cos(plane.rotation.y * M_PI / 180.0);
        ta = plane.position.x - (plane.flength + 50) * sin(plane.rotation.y * M_PI / 180.0);
        tb = plane.position.y - 10;
        tc = plane.position.z - (plane.flength + 50) * cos(plane.rotation.y * M_PI / 180.0);
        ua = -sin(plane.rotation.z * M_PI / 180.0) * cos(plane.rotation.y * M_PI / 180.0);
        ub = cos(plane.rotation.z * M_PI / 180.0);
        uc = sin(plane.rotation.z * M_PI / 180.0) * sin(plane.rotation.y * M_PI / 180.0);
    }
    
    if (top_view) {
        ea = plane.position.x + plane.rlength * sin(plane.rotation.y * M_PI/180.0);
        eb = plane.position.y + 100;
        ec = plane.position.z + (plane.rlength + 1) * cos(plane.rotation.y * M_PI/180.0);
        ta = plane.position.x;
        tb = plane.position.y;
        tc = plane.position.z;
    }

    if (follow_cam_view) {
        ea = plane.position.x + (plane.rlength + 30) * sin(plane.rotation.y * M_PI/180.0);
        eb = plane.position.y + 40;
        ec = plane.position.z + (plane.rlength + 30) * cos(plane.rotation.y * M_PI/180.0);
        ta = plane.position.x;
        tb = plane.position.y;
        tc = plane.position.z;
    }

    if (heli_cam_view) {

    }

    if (tower_view) {
        ea = 100;
        eb = 100;
        ec = 100;
        ta = plane.position.x;
        tb = plane.position.y;
        tc = plane.position.z;
    }

}

void tick_elements() {

    plane.tick();

    fan.position.x = plane.position.x - plane.flength * sin(plane.rotation.y * M_PI/180.0);
    fan.position.y = plane.position.y;
    fan.position.z = plane.position.z - plane.flength * cos(plane.rotation.y * M_PI/180.0);
    fan.tick();

    needle[0].rotation = max(90 * (2 - plane.speed_z), (double)-90); // speed
    needle[2].rotation = min(90 - (plane.fuel/plane.maxfuel)*180, (double)90); //fuel
    needle[1].rotation = max(90 - (plane.position.y/plane.maxalt)*180, (double)-90); //altitude

}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    color_t r = {255, 0, 0}, g = {0, 255, 0}, b = {0, 0, 255};    

    plane = Plane(0, 80, 0);
    ground = Ground(0, 0, 0);
    for (int i=0; i<NO_OF_FISHES; ++i) {
        fishes[i] = Fish(-250 + rand() % 500, -ground.deep, -250 + rand() % 500);
    }
    fan = Fan(0, 0, 0);
    db = Dashboard(-12, -6.9, 0);
    needle[0] = Needle(0, -11, 0, r);
    needle[1] = Needle(-8, -11, 0, g);
    needle[2] = Needle(8, -11, 0, b);
    needle[2].rotation = -90;

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 600;
    int height = 600;

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);
            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 40 / screen_zoom;
    float bottom = screen_center_y - 40 / screen_zoom;
    float left   = screen_center_x - 40 / screen_zoom;
    float right  = screen_center_x + 40 / screen_zoom;
    Matrices.projection = glm::perspective(100*M_PI/180, (double)1 , (double)0.1, (double)INF);
}
