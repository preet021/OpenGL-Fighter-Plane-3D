#include <algorithm>
#include "arrow.h"
#include "bomb.h"
#include <cmath>
#include "dashboard.h"
#include "enemy.h"
#include "fan.h"
#include "fish.h"
#include "fuel.h"
#include "ground.h"
#include "island.h"
#include <list>
#include "main.h"
#include "missile.h"
#include "needle.h"
#include "plane.h"
#include "parachute.h"
#include "ring.h"
#include "score.h"
#include "timer.h"
#include "volcano.h"

#define sz(a) (int)(a).size()
#define pb push_back
#define INF 100000
#define NO_OF_FISHES 200
using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Arrow arrow;
Dashboard db;
Fan fan;
Fish fishes[NO_OF_FISHES];
Ground ground;
Needle needle[3];
Plane plane;
list <Bomb> bombs;
list <Enemy> emissiles;
list <Fuel> ftanks;
list <Island> islands;
list <Island>::iterator checkpoint;
list <Missile> missiles;
list <Parachute> parachutes;
list <Ring> rings;
list <Volcano> volc;
vector <Score> scr;
Score segment;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0, near_pt = 0.1, far_pt = INF;
float camera_rotation_angle = 0, ea, eb, ec, ta, tb, tc, ua, ub, uc, curX = 0, curY = 0, heli_cam_view_radius = 100, heli_cam_view_elevation = 0, heli_cam_view_rotation = 0;
bool plane_view = 0, follow_cam_view = 1, top_view = 0, heli_cam_view = 0, tower_view = 0, heli_cam_init;
int cnt = 0, missile_tick = 0, bomb_tick = 0, emissile_tick = 0, rem_checkpoints = 5, no_of_lives = 20, player_score = 0;
GLFWcursor *cursor = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);

void detect_collisions();
void display_score();
float sq (float x);
float dist (float a, float b, float c, float d, float e, float f);

Timer t60(1.0 / 60);

static void CursorPositionCallback (GLFWwindow *window, double xPos, double yPos);

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
    // fan.draw(VP, fan.position.x - plane.position.x, fan.position.y - plane.position.y, fan.position.z - plane.position.z);
    arrow.draw(VP1);
    db.draw(VP1);
    needle[0].draw(VP1);
    needle[1].draw(VP1);
    needle[2].draw(VP1);
    for (int i=0; i<sz(scr); i++) {
        scr[i].draw(VP1);
    }
    for (list<Ring>::iterator it=rings.begin(); it!=rings.end(); it++) {
        it->draw(VP);
    }
    for (list<Fuel>::iterator it=ftanks.begin(); it!=ftanks.end(); it++) {
        it->draw(VP);
    }
    for (list<Volcano>::iterator it=volc.begin(); it!=volc.end(); it++) {
        it->draw(VP);
    }
    for (list<Missile>::iterator it=missiles.begin(); it!=missiles.end(); it++) {
        it->draw(VP);
    }
    for (list<Enemy>::iterator it=emissiles.begin(); it!=emissiles.end(); it++) {
        it->draw(VP);
    }
    for (list<Bomb>::iterator it=bombs.begin(); it!=bombs.end(); it++) {
        it->draw(VP);
    }
    for (list<Island>::iterator it=islands.begin(); it!=islands.end(); it++) {
        it->draw(VP);
    }
    for (list<Parachute>::iterator it=parachutes.begin(); it!=parachutes.end(); it++) {
        it->draw(VP);
    }
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
    int m = glfwGetKey(window, GLFW_KEY_M);
    int c = glfwGetKey(window, GLFW_KEY_C);
    int x = glfwGetKey(window, GLFW_KEY_X);
    int mouse_left = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    int mouse_right = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
    float enemy_plane_dist = dist(plane.position.x, plane.position.y, plane.position.z, checkpoint->position.x, checkpoint->position.y, checkpoint->position.z);
    bool tilt = 0;

    if (mouse_left == GLFW_PRESS && missile_tick <= 0) {
        missile_tick = 40;
        missiles.push_back(Missile(plane.rotation.y, plane.position.x, plane.position.y, plane.position.z));
    }
    --missile_tick;
    
    if (enemy_plane_dist <= 2000 && emissile_tick <= 0) {
        emissile_tick = 50;
        emissiles.push_back(Enemy(checkpoint->position.x, checkpoint->position.y, checkpoint->position.z, plane.position.x, plane.position.y, plane.position.z));
    }
    --emissile_tick;

    if (mouse_right == GLFW_PRESS && bomb_tick <= 0) {
        bomb_tick = 40;
        bombs.push_back(Bomb(plane.position.x, plane.position.y, plane.position.z));
    }
    --bomb_tick;
    
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

    if (c) {
        plane.rotation.x += 3*plane.tilt;
    }

    if (x) {
        plane.rotation.x -= 3*plane.tilt;
    }

    if (d) {
        tilt = 1;
        if (plane.rotation.z > -plane.maxtilt)
            plane.rotation.z -= plane.tilt;
    }

    if (a) {
        tilt = 1;
        if (plane.rotation.z < plane.maxtilt)
            plane.rotation.z += plane.tilt;
    }

    if (q) {
        tilt = 1;
        if (plane.rotation.z < plane.maxtilt)
            plane.rotation.z += plane.tilt;
        plane.rotation.y += plane.tilt;
    }

    if (e) {
        tilt = 1;
        if (plane.rotation.z > -plane.maxtilt)
            plane.rotation.z -= plane.tilt;
        plane.rotation.y -= plane.tilt;
    }

    if (w) {
        plane.speed_z += plane.acc_z;
        if (plane.speed_z > 3.5) plane.speed_z = 3;
        plane.position.y += plane.speed_z * sin(plane.rotation.x * M_PI / 180.0);
        plane.position.z -= plane.speed_z * cos(plane.rotation.y * M_PI / 180.0) * cos(plane.rotation.x * M_PI / 180.0);
        plane.position.x -= plane.speed_z * sin(plane.rotation.y * M_PI / 180.0) * cos(plane.rotation.x * M_PI / 180.0);
    }

    if (space) {
        plane.rotation.z = 0;
        plane.position.y += 0.5;
    }

    if (!tilt && plane.rotation.z > 0) plane.rotation.z -= plane.tilt;

    if (!tilt && plane.rotation.z < 0) plane.rotation.z += plane.tilt;

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

    if (tower_view) {
        ea = 100;
        eb = 100;
        ec = 100;
        ta = plane.position.x;
        tb = plane.position.y;
        tc = plane.position.z;
    }

    if (heli_cam_view) {
        ta = plane.position.x;
        tb = plane.position.y;
        tc = plane.position.z;
        ea = plane.position.x + cos(heli_cam_view_elevation * M_PI / 180.0) * heli_cam_view_radius * sin((plane.rotation.y + heli_cam_view_rotation) * M_PI/180.0);
        eb = plane.position.y + heli_cam_view_radius * sin(heli_cam_view_elevation * M_PI / 180.0);
        ec = plane.position.z + cos(heli_cam_view_elevation * M_PI / 180.0) * heli_cam_view_radius * cos((plane.rotation.y + heli_cam_view_rotation) * M_PI/180.0);
    }

}

void tick_elements() {

    if (plane.position.y < ground.position.y) no_of_lives = 0;

    plane.tick();
    if (plane.fuel <= 0) no_of_lives = 0;

    fan.position.x = plane.position.x - plane.flength * sin(plane.rotation.y * M_PI/180.0);
    fan.position.y = plane.position.y;
    fan.position.z = plane.position.z - plane.flength * cos(plane.rotation.y * M_PI/180.0);
    fan.tick();

    for (list<Missile>::iterator it=missiles.begin(); it!=missiles.end(); it++) {
        it->position.z -= it->speed * cos(it->rotation * M_PI / 180.0);
        it->position.x -= it->speed * sin(it->rotation * M_PI / 180.0);
    }

    for (list<Enemy>::iterator it=emissiles.begin(); it!=emissiles.end(); it++) {
        it->position.y += it->speed;
        it->position.x += it->speed * it->ux / it->uy;
        it->position.z += it->speed * it->uz / it->uy;
    }

    for (list<Bomb>::iterator it=bombs.begin(); it!=bombs.end(); it++) {
        it->position.y -= it->speed;
    }

    for (list<Parachute>::iterator it=parachutes.begin(); it!= parachutes.end(); it++) {
        it->tick();
    }

    // checking whether checkpoint is on left / right of the plane
    bool on_left = 0, on_right = 0;
    float wlx = plane.position.x - plane.radius * cos(plane.rotation.y * M_PI / 180.0);
    float wlz = plane.position.z - plane.radius * sin(plane.rotation.y * M_PI / 180.0);
    float wrx = plane.position.x + plane.radius * cos(plane.rotation.y * M_PI / 180.0);
    float wrz = plane.position.z + plane.radius * sin(plane.rotation.y * M_PI / 180.0);
    float wy = plane.position.y;

    float dot_product = (fan.position.x-plane.position.x)*(checkpoint->position.x-plane.position.x);
    dot_product += (fan.position.y-plane.position.y)*(wy-plane.position.y);
    dot_product += (fan.position.z-plane.position.z)*(checkpoint->position.z-plane.position.z);
    dot_product /= dist(fan.position.x-plane.position.x, fan.position.y-plane.position.y, fan.position.z-plane.position.z, 0, 0, 0);
    dot_product /= dist(checkpoint->position.x-plane.position.x, wy-plane.position.y, checkpoint->position.z-plane.position.z, 0, 0, 0);
    // now dot_product is equal to cos_theta

    float fx = plane.position.x - plane.flength * sin((plane.rotation.y + acos(dot_product)*180/M_PI) * M_PI/180.0);
    float fy = plane.position.y;
    float fz = plane.position.z - plane.flength * cos((plane.rotation.y + acos(dot_product)*180/M_PI) * M_PI/180.0);

    float dot_product1 = (fx-plane.position.x)*(checkpoint->position.x-plane.position.x);
    dot_product1 += (fy-plane.position.y)*(wy-plane.position.y);
    dot_product1 += (fz-plane.position.z)*(checkpoint->position.z-plane.position.z);
    dot_product1 /= dist(fx-plane.position.x, fy-plane.position.y, fz-plane.position.z, 0, 0, 0);
    dot_product1 /= dist(checkpoint->position.x-plane.position.x, wy-plane.position.y, checkpoint->position.z-plane.position.z, 0, 0, 0);
    
    if (dot_product > dot_product1) on_right = 1;
    else on_left = 1;

    // making the arrow to point the checkpoint
    if (on_left)
        arrow.rotation = (acos(dot_product) * 180) / M_PI;
    else
        arrow.rotation = -(acos(dot_product) * 180) / M_PI; 

    // updating the dashboard
    needle[0].rotation = max(90 * (2 - plane.speed_z), (double)-90); // speed
    needle[1].rotation = max(90 - (plane.position.y/plane.maxalt)*180, (double)-90); //altitude
    needle[2].rotation = min(90 - (plane.fuel/plane.maxfuel)*180, (double)90); //fuel

    checkpoint->tick();
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    color_t r = {255, 0, 0}, g = {0, 255, 0}, b = {0, 0, 255};    

    plane = Plane(0, 180, 0);

    ground = Ground(0, 0, 0);
    
    for (int i=0; i<NO_OF_FISHES; ++i) {
        fishes[i] = Fish(-5000 + rand() % 5000, -ground.deep + 6, -(rand() % 5000));
    }
    
    fan = Fan(0, 0, 0);
    
    db = Dashboard(-12, -6.9, 0);
    
    needle[0] = Needle(-4, -11, 0, r);
    needle[1] = Needle(-9.4, -11, 0, g);
    needle[2] = Needle(1.5, -11, 0, b);
    needle[2].rotation = -90;

    rings.assign(40, Ring(0, 0, 0));
    for (list<Ring>::iterator it=rings.begin(); it!=rings.end(); it++) {
        *it = Ring(-2500 + rand() % 5000, 50 + rand() % 100, -(rand() % 5000));
    }

    ftanks.assign(35, Fuel(0, 0, 0));
    for (list<Fuel>::iterator it=ftanks.begin(); it!=ftanks.end(); it++) {
        *it = Fuel(-2500 + rand() % 5000, 50 + rand() % 100, -(rand() % 5000));
    }

    volc.assign(20, Volcano(0, 0, 0));
    for (list<Volcano>::iterator it=volc.begin(); it!=volc.end(); it++) {
        *it = Volcano(-5000 + rand() % 5000, 0, -(rand() % 5000));
    }

    islands.assign(rem_checkpoints, Island(0, 0, 0));
    for (list<Island>::iterator it=islands.begin(); it!=islands.end(); it++) {
        *it = Island(-5000 + rand() % 5000, 12, -(rand() % 5000));
    }
    checkpoint = islands.begin();
    checkpoint->is_checkpoint = true;

    arrow = Arrow(0, 8, 0, 0);

    parachutes.assign(20, Parachute(0, 0, 0));
    for (list<Parachute>::iterator it=parachutes.begin(); it!=parachutes.end(); it++) {
        *it = Parachute((-5000 + rand() % 5000), 100 + rand()%400, -(rand() % 5000));
    }

    segment = Score(0, -8 + 0.3, 0, COLOR_BLACK);

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
    char buffer[50];

    window = initGLFW(width, height);
    glfwSetCursorPosCallback(window, CursorPositionCallback);
    glfwSetScrollCallback(window, scroll_callback);

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
            reset_screen();
            detect_collisions();
            tick_elements();
            tick_input(window);
            display_score();
            sprintf(buffer, "Checkpoints Left: %d\t\tHealth: %d", rem_checkpoints, no_of_lives);
            glfwSetWindowTitle(window, buffer);
            if (rem_checkpoints <= 0 || no_of_lives <= 0) break;
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }
    cout << "\n------------- Game Over ----------------\nYour Score: " << player_score << endl;
    quit(window);
}

void detect_collisions() {

    // plane and smoke ring
    list<Ring>::iterator it_ring;
    for (list<Ring>::iterator it=rings.begin(); it!=rings.end();) {
        it_ring = it;
        it++;
        float plx = plane.position.x, ply = plane.position.y, plz = plane.position.z;
        float rgx = it_ring->position.x, rgy = it_ring->position.y, rgz = it_ring->position.z, radius = it_ring->radius;
        bool x, y, z;
        x = y = z = 0;
        if (plx >= rgx - radius && plx <= rgx + radius) x = 1;
        if (ply >= rgy - radius && ply <= rgy + radius) y = 1;
        if (plz >= rgz - 0.7*plane.rlength && plz <= rgz + 0.7*plane.rlength) z = 1;
        if (x && y && z) {
            player_score += 2;
            rings.erase(it_ring);
        }
    }

    // plane and smoke fuel tank
    list<Fuel>::iterator it_fuel;
    for (list<Fuel>::iterator it=ftanks.begin(); it!=ftanks.end();) {
        it_fuel = it;
        it++;
        float plx = plane.position.x, ply = plane.position.y, plz = plane.position.z;
        float ftx = it_fuel->position.x, fty = it_fuel->position.y, ftz = it_fuel->position.z, radius = it_fuel->side;
        bool x, y, z;
        x = y = z = 0;
        if (plx >= ftx - radius && plx <= ftx + radius) x = 1;
        if (ply >= fty - radius && ply <= fty + radius) y = 1;
        if (plz >= ftz - plane.rlength && plz <= ftz + plane.rlength) z = 1;
        if (x && y && z) {
            it_fuel->position.x = -2500 + rand() % 5000;
            it_fuel->position.y = 50 + rand() % 100;
            it_fuel->position.z = -(rand() % 5000);
            plane.fuel = plane.maxfuel;
        }
    }

    // no flying zone (volcano)
    list<Volcano>::iterator it_volc;
    for (list<Volcano>::iterator it=volc.begin(); it!=volc.end();) {
        it_volc = it;
        it++;
        float plx = plane.position.x, plz = plane.position.z;
        float vlx = it_volc->position.x, vlz = it_volc->position.z, side=it_volc->side;
        if (plx >= vlx - side && plx <= vlx + side && plz >= vlz - side && plz <= vlz + side) {
            no_of_lives = 0;
        }
    }

    // bomb and island
    list<Bomb>::iterator it_bomb;
    for (list<Bomb>::iterator it=bombs.begin(); it!=bombs.end();) {
        it_bomb = it;
        it++;
        if (it_bomb->position.y <= 0) {
            bombs.erase(it_bomb);
            continue;
        }
        bool x = 0, y = 0, z = 0;
        float bx = it_bomb->position.x, by = it_bomb->position.y, bz = it_bomb->position.z;
        if (bx >= checkpoint->position.x - checkpoint->side && bx <= checkpoint->position.x + checkpoint->side) x = 1;
        if (bz >= checkpoint->position.z - checkpoint->side && bz <= checkpoint->position.z + checkpoint->side) z = 1;
        if (by >= checkpoint->position.y + checkpoint->height - checkpoint->side && by <= checkpoint->position.y + checkpoint->height + checkpoint->side) y = 1;
        if (x && y && z) {
            player_score += 8;
            bombs.erase(it_bomb);
            // cout << cnt << " bomb hits island" << endl; ++cnt;
            islands.erase(islands.begin());
            rem_checkpoints -= 1;
            if (rem_checkpoints > 0) {
                checkpoint = islands.begin();
                checkpoint->is_checkpoint = true;
            }
            break;
        }
    }

    // missile and island
    list<Missile>::iterator it_miss;
    for (list<Missile>::iterator it=missiles.begin(); it!=missiles.end();) {
        it_miss = it;
        it++;
        if (abs(it_miss->position.z) > ground.gmax || abs(it_miss->position.x) > ground.gmax) {
            missiles.erase(it_miss);
            continue;
        }
        bool x = 0, y = 0, z = 0;
        float mx = it_miss->position.x, my = it_miss->position.y, mz = it_miss->position.z;
        if (mx >= checkpoint->position.x - checkpoint->side && mx <= checkpoint->position.x + checkpoint->side) x = 1;
        if (mz >= checkpoint->position.z - checkpoint->side && mz <= checkpoint->position.z + checkpoint->side) z = 1;
        if (my >= checkpoint->position.y + checkpoint->height - checkpoint->side && my <= checkpoint->position.y + checkpoint->height + checkpoint->side) y = 1;
        if (x && y && z) {
            player_score += 10;
            missiles.erase(it_miss);
            // cout << cnt << " missile hits island" << endl; ++cnt;
            islands.erase(islands.begin());
            rem_checkpoints -= 1;
            if (rem_checkpoints > 0) {
                checkpoint = islands.begin();
                checkpoint->is_checkpoint = true;
            }
            break;
        }
    }

    // enemy missile and plane
    list<Enemy>::iterator it_emiss;
    for (list<Enemy>::iterator it=emissiles.begin(); it!=emissiles.end();) {
        it_emiss = it;
        it++;
        if (it_emiss->position.y > plane.maxalt) {
            emissiles.erase(it_emiss);
            continue;
        }
        float rx = plane.position.x + plane.rlength * sin(plane.rotation.y * M_PI/180.0);
        float ry = plane.position.y;
        float rz = plane.position.z + plane.rlength * cos(plane.rotation.y * M_PI/180.0);
        float fx = fan.position.x, fy = fan.position.y, fz = fan.position.z;
        float len = plane.flength + plane.rlength;
        float d = dist(it_emiss->position.x, it_emiss->position.y, it_emiss->position.z, rx, ry, rz);
        d += dist(it_emiss->position.x, it_emiss->position.y, it_emiss->position.z, fx, fy, fz);
        if (abs(d - len) <= plane.radius) {
            // cout << "enemy missile hits plane" << endl;
            emissiles.erase(it_emiss);
            no_of_lives -= 1;
        }
    }

    list<Parachute>::iterator it_parach;
    for (list<Parachute>::iterator it=parachutes.begin(); it!=parachutes.end();) {
        it_parach = it;
        it++;
        if (it_parach->position.y < -20) {
            it_parach->position.x = -5000 + rand() % 5000;
            it_parach->position.y = 100 + rand() % 400;
            it_parach->position.z = -5000 + rand() % 5000;
        }
    }

    for (list<Parachute>::iterator it1=parachutes.begin(); it1!=parachutes.end();) {
        it_parach = it1;
        it1++;
        for (list<Missile>::iterator it2=missiles.begin(); it2!=missiles.end();) {
            it_miss = it2;
            it2++;
            bool x, y, z;
            x = y = z = 0;
            float px = it_parach->position.x, py = it_parach->position.y, pz = it_parach->position.z;
            if (it_miss->position.x >= px - 2 && it_miss->position.x <= px + 2) x = 1;
            if (it_miss->position.y >= py - 7 && it_miss->position.y <= py - 3) y = 1;
            if (it_miss->position.z >= pz + 8 && it_miss->position.z <= pz + 12) z = 1;
            if (x && y && z) {
                player_score += 5;
                // cout << cnt << " parachute hit" << endl; ++cnt;
                missiles.erase(it_miss);
                it_parach->position.x = -5000 + rand() % 5000;
                it_parach->position.y = 100 + rand() % 400;
                it_parach->position.z = -5000 + rand() % 5000;
            }
        }
    }

}

void reset_screen() {
    float top    = screen_center_y + 40 / screen_zoom;
    float bottom = screen_center_y - 40 / screen_zoom;
    float left   = screen_center_x - 40 / screen_zoom;
    float right  = screen_center_x + 40 / screen_zoom;
    Matrices.projection = glm::perspective(100*M_PI/180, (double)1 , (double)near_pt, (double)far_pt);
}

float sq (float x) {
    return x*x;
}

float dist (float a, float b, float c, float d, float e, float f) {
    return sqrt(sq(a-d)+sq(b-e)+sq(c-f));
}

static void CursorPositionCallback (GLFWwindow *window, double xPos, double yPos) {
    if (!heli_cam_view) return;
    if (xPos - 512 > 0) {
        heli_cam_view_rotation -= 0.5;
    }
    else {
        heli_cam_view_rotation += 0.5;
    }
    if (yPos - 384 > 0) {
        heli_cam_view_elevation += 0.5;
        if (heli_cam_view_elevation > 90) heli_cam_view_elevation = 90;
    }
    else {
        heli_cam_view_elevation -= 0.5;
        if (heli_cam_view_elevation < -90) heli_cam_view_elevation = -90;
    }
    glfwSetCursorPos(window, 512, 384);
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    if (yoffset == 1 && heli_cam_view && heli_cam_view_radius > 20)
        heli_cam_view_radius -= 2;
    if (yoffset == -1 && heli_cam_view && heli_cam_view_radius<300) {
        heli_cam_view_radius += 2;
    }
    if (yoffset == 1) {
        screen_zoom += 1;
    }
    if (yoffset == -1) {
        screen_zoom -= 1;
    }
}


void display_score () {
    scr.clear();
    for (int i=0, dgt, p=10; i<4; p*=10, ++i) {
        dgt = (10 * (player_score % p)) / p;
        if (dgt == 0 || dgt == 4 || dgt == 5 || dgt == 6 || dgt == 8 || dgt == 9) {
            segment.position.x = 7+(3-i)/1.0;
            segment.position.y = -8 + 0.3;
            segment.rotation = 0;
            scr.pb(segment);
        }
        if (dgt == 0 || dgt == 2 || dgt == 6 || dgt == 8) {
            segment.position.x = 7+(3-i)/1.0;
            segment.position.y = -8;
            segment.rotation = 0;
            scr.pb(segment);
        }
        if (dgt == 0 || dgt == 2 || dgt == 3 || dgt == 5 || dgt == 6 || dgt == 7 || dgt == 8 || dgt == 9) {
            segment.position.x = 7+(3-i)/1.0+0.1;
            segment.position.y = -8 + 0.8;
            segment.rotation = 270;
            scr.pb(segment);
        }
        if (dgt == 2 || dgt == 3 || dgt == 4 || dgt == 5 || dgt == 6 || dgt == 8 || dgt == 9) {
            segment.position.x = 7+(3-i)/1.0+0.09;
            segment.position.y = -8 + 0.37;
            segment.rotation = 270;
            scr.pb(segment);
        }
        if (dgt == 0 || dgt == 2 || dgt == 3 || dgt == 5 || dgt == 6 || dgt == 8 || dgt == 9) {
            segment.position.x = 7+(3-i)/1.0+0.1;
            segment.position.y = -8;
            segment.rotation = 270;
            scr.pb(segment);
        }
        if (dgt == 0 || dgt == 1 || dgt == 2 || dgt == 3 || dgt == 4 || dgt == 7 || dgt == 8 || dgt == 9) {
            segment.position.x = 7+(3-i)/1.0+0.5;
            segment.position.y = -8 + 0.3;
            segment.rotation = 0;
            scr.pb(segment);
        }
        if (dgt == 0 || dgt == 1 || dgt == 3 || dgt == 4 || dgt == 5 || dgt == 6 || dgt == 7 || dgt == 8 || dgt == 9) {
            segment.position.x = 7+(3-i)/1.0+0.5;
            segment.position.y = -8;
            segment.rotation = 0;
            scr.pb(segment);
        }
    }
}
