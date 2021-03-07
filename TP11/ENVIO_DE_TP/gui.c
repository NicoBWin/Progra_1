/***************************************************************************//**
  @file     +allegro.c+
  @brief    +Interfaz grafica+
  @author   +Grupo 3+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "gui.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define D_WIDTH         720
#define D_HEIGHT        480
#define LED_COUNT       8
#define LED_RAD         30.0
#define BLINK_TIME      1.0

#define BKGD_COLOR          "black"
#define LED_OFF_COLOR       "darkred"
#define LED_ON_COLOR        "red"
#define LED_BORDER_COLOR    "black"

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/
static ALLEGRO_TIMER *timer = NULL;
static ALLEGRO_BITMAP *image = NULL;
static ALLEGRO_BITMAP *image2 = NULL;
static ALLEGRO_DISPLAY *display = NULL;
static ALLEGRO_EVENT_QUEUE *event_queue = NULL;


/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
int init_all(void) 
{
// Inicializacion de Allegro
    if (!al_init()) 
    {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }
    
    if (!al_init_primitives_addon())
    {
        fprintf(stderr, "failed to initialize primitives!\n");
        return -1;
    }

    timer = al_create_timer(BLINK_TIME); //crea el timer pero NO empieza a correr
    if (!timer) 
    {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }

    if (!al_init_image_addon())
    { 
        fprintf(stderr, "failed to initialize image addon !\n");
        return -1;
    }

    image = al_load_bitmap("image.jpg");
    if (!image) {
        al_destroy_timer(timer);
        fprintf(stderr, "failed to load image !\n");
        return -1;
    }

/*
    if (!al_init_video_addon())
    { 
        fprintf(stderr, "failed to initialize video addon !\n");
        return -1;
    }
    video = al_start_video(ALLEGRO_VIDEO *video, ALLEGRO_MIXER *mixer);
    if (!video) {
        al_destroy_timer(timer);
        fprintf(stderr, "failed to load video !\n");
        return 0;
    }
    al_close_video(ALLEGRO_VIDEO *video);
    
*/    
    image2 = al_load_bitmap("image2.jpg");
    if (!image2) {
        al_destroy_timer(timer);
        al_destroy_bitmap(image);
        fprintf(stderr, "failed to load image2 !\n");
        return -1;
    }

    display = al_create_display(D_WIDTH, D_HEIGHT);
    if (!display) 
    {
        al_shutdown_primitives_addon();
        al_destroy_timer(timer);
        al_destroy_bitmap(image);
        al_destroy_bitmap(image2);
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    event_queue = al_create_event_queue();
    if (!event_queue)
    {
        al_destroy_timer(timer);
        al_shutdown_primitives_addon();
        al_destroy_display(display);
        al_destroy_bitmap(image);
        al_destroy_bitmap(image2);
        fprintf(stderr, "failed to create event_queue!\n");
        return -1;
    }

    al_draw_scaled_bitmap(image,
        0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), //imagen
        0, 0, al_get_display_width(display), al_get_display_height(display), //a que tamaño queres que se dibuje la imagen
        0);
    al_flip_display();
    al_rest(3.0);   //tiempo random

// Registro de eventos
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    return 0;
}

void destroy_all()
{
    al_draw_scaled_bitmap(image2,
        0, 0, al_get_bitmap_width(image2), al_get_bitmap_height(image2), //imagen
        0, 0, al_get_display_width(display), al_get_display_height(display), //a que tamaño queres que se dibuje la imagen
        0);
    al_flip_display();
    al_rest(3.0);   //tiempo random

    al_destroy_display(display);
    al_shutdown_primitives_addon();
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_destroy_bitmap(image);
    al_destroy_bitmap(image2);
    printf("See yu next time...\n\n");
}

void drawLEDS(bool ledState[], unsigned int nLeds)
{
// Creación de la pantalla
    al_clear_to_color(al_color_name(BKGD_COLOR));   // Limpio la pantalla
    
    for (unsigned int n = 1; n <= nLeds ; n++) {
        ALLEGRO_COLOR color = al_color_name(ledState[nLeds-n] ? LED_ON_COLOR : LED_OFF_COLOR);
        al_draw_filled_circle((D_WIDTH/(LED_COUNT+1.0))*n, D_HEIGHT/2.0, LED_RAD, color);
        al_draw_circle((D_WIDTH/(LED_COUNT+1.0))*n, D_HEIGHT/2.0, LED_RAD, al_color_name(LED_BORDER_COLOR), 3.0);
    }

    al_flip_display();      // Actualizamos la pantalla
}


// Devuelve true si desea salir del programa
/*bool al_cycle (bool ledState[], unsigned int size, bool blink) {
    bool do_exit;

    static bool preblink = false;
    if (!preblink) 
    {
////////////////////////////////////
    }

    ALLEGRO_EVENT ev;
    if (al_get_next_event(event_queue, &ev)) {
        switch (ev.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                do_exit = true;
                break;
            case ALLEGRO_EVENT_TIMER:
                if (blink) {
                    for (unsigned int i = 0; i < size; i++) {
                        ledState[i] = !ledState[i];
                    }
                }
                break;
            default:
                break;   
        }
    }
    drawLEDS(ledState, size);
}*/

bool al_cycle(bool ledState[], unsigned int size, bool blink) {
    bool do_exit = false;

    ALLEGRO_EVENT ev;
    if (al_get_next_event(event_queue, &ev)) {
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            do_exit = true;
        }
    }
    // drawLEDS(ledState, size);
    return do_exit;
}
/*
bool getTimer(bool flag) {
    static bool state;
    bool timer = false;

    if (state != flag) {        // Cambio de estado
        if (flag == true) {         // Enciendo timer
            state = true;
            al_start_timer(timer);
        }
        else {
            state = false;          // Destruyo timer
            al_destroy_timer(timer);
        }
    }

    ALLEGRO_EVENT ev;
    if (al_get_next_event(event_queue, &ev)) {
        if (ev.type == ALLEGRO_EVENT_TIMER) {
            timer = true;
        }
    }

    return timer;
}
*/