//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRoundRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);


int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRoundRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    double velocity_x = 0.0 ;
    double velocity_y = 7.0;
    
        printf(" %f " , velocity_x);        
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // Physics of the game 
        GEvent event ;
        event = getNextEvent(MOUSE_EVENT);
        
        if (event != NULL )
        {
            if ( getEventType(event) == MOUSE_MOVED)
            {
            double x = getX(event) - 50 ;
            setLocation(paddle , x , 550); 
            }
        }
        
        velocity_x = 2 * drand48();
        
        move(ball, velocity_x, velocity_y);
        
        
  

        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            velocity_x = -velocity_x;
        }

        // bounce off left edge of window
        else if (getX(ball) <= 0)
        {
            velocity_x = -velocity_x;
        }
            
        if (getY(ball) + getHeight(ball) >= getHeight(window))
        {
            GLabel marker = newGLabel("Life Lost :(") ;
            setFont(marker , "Serif-25"); 
            setLocation( marker , 150 , 400);
            add(window , marker);
            pause(1000);
            removeGWindow(window , marker);
            lives--;    
            setLocation( ball , 188 , 288);
            pause(1000);
         }
         else 
            if (getY(ball) <= 0)
            {
                velocity_y = - velocity_y;
            }
        
        
        GObject object = detectCollision(window, ball);
        
        if(object == paddle)
        {
            velocity_x = - velocity_x;
            velocity_y = - velocity_y;
        }
        else 
        if(strcmp(getType(object) , "GRect") == 0 )
        {
            
            removeGWindow(window , object);
             velocity_x = - velocity_x;
            velocity_y = - velocity_y;
            points++;
        }
        
            
        updateScoreboard(window , label , points);
        pause(10);
    
        
    }
    
    GLabel closer = newGLabel("GAME OVER ");
    
    setFont(closer, "Serif-36"); 
    setLocation (closer,  100 , 400 ); 
    
    add(window ,closer) ;
     
    pause(500);
    

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    GRect Bricks[ROWS][COLS];
    // TODO
    for (int i = 0 ; i < ROWS ; i++)
    {
 
        for ( int j = 0; j < COLS ; j++)
        {   
            Bricks[i][j] = newGRect(   80 * i , 30 + 12 * j , 75 , 10  ); 

            if (j == 0  || j == 9 )
            {
            setFilled(Bricks[i][j],true);
            setColor(Bricks[i][j], "CYAN");   
            
            }
            else
            if (j ==1  || j == 8 )
            {
            setFilled(Bricks[i][j],true);
            setColor(Bricks[i][j], "YELLOW");   
            
            }
            else
            if (j ==2  || j == 7 )
            {
            setFilled(Bricks[i][j],true);
            setColor(Bricks[i][j], "ORANGE");   
            
            }
            if (j ==3  || j == 6 )
            {
            setFilled(Bricks[i][j],true);
            setColor(Bricks[i][j], "GREEN");   
            
            }
            else
            if (j == 5 || j == 4 )
            {
            setFilled(Bricks[i][j],true);
            setColor(Bricks[i][j], "RED");   
            }
            
                      
            
            
            add(window, Bricks[i][j]);
        } 
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    GOval ball = newGOval(188,288, 25,25);
    setFilled(ball , true);
    setColor( ball , "BLACK");
    
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRoundRect initPaddle(GWindow window)
{
    // TODO
    GRoundRect paddle = newGRoundRect(150,560,100,20,0);
    
    setFilled(paddle , true);
    setColor(paddle , "RED");
    
    add(window,paddle);
     
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    GLabel label = newGLabel("");
    setFont(label , "Serif-30");
    add(window, label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
