/*
 * events-waitevent-keyboard.c
 *
 * WaitEvent:
 * Waits indefinitely for the next available event, returning 0 if there was an error
 * while waiting for events, 1 otherwise.
 * If event is not NULL, the next event is removed from the queue and stored in that area.
 * As this function implicitly calls SDL_PumpEvents, you can only call this function
 * in the thread that set the video mode.
 */
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

void print_kmod(int modifier)
{
   printf("LSHIFT=%d ", modifier & KMOD_LSHIFT);
   printf("RSHIFT=%d ", modifier & KMOD_RSHIFT);
   printf("LCTRL=%d ", modifier & KMOD_LCTRL);
   printf("RCTRL=%d ", modifier & KMOD_RCTRL);
   printf("LALT=%d ", modifier & KMOD_LALT);
   printf("RALT=%d ", modifier & KMOD_RALT);
   printf("LMETA=%d ", modifier & KMOD_LMETA);
   printf("RMETA=%d ", modifier & KMOD_RMETA);
   printf("NUM=%d ", modifier & KMOD_NUM);
   printf("CAPS=%d ", modifier & KMOD_CAPS);
   printf("MODE=%d\n", modifier & KMOD_MODE);
}

int main()
{
   SDL_Surface *screen;
   SDL_Event event;

   if (SDL_Init(SDL_INIT_VIDEO) != 0) {
	  printf("Unable to initialize SDL: %s\n", SDL_GetError());
	  return 1;
   }

   atexit(SDL_Quit);

   /* Attempt to set a 256x256 hicolor (16-bit) video mode. */
   screen = SDL_SetVideoMode(256, 256, 16, 0);
   if (screen == NULL) {
      printf("Unable to set video mode: %s\n", SDL_GetError());
      return 2;
   }

   printf("Press 'Q' to quit.\n");

   /* Start the event loop. Keep reading events until there
      is an error, or the user presses a mouse button. */
   while (SDL_WaitEvent(&event) != 0) {
      SDL_keysym keysym;

      /* SDL_WaitEvent has filled in our event structure
         with the next event. We check its type field to
         find out what happened. */
      switch (event.type) {

         case SDL_KEYDOWN:
            printf("Key pressed (state = %d). ", event.key.state);
            keysym = event.key.keysym;
            printf("SDL keysym is %i. ", keysym.sym);
            printf("(%s) ", SDL_GetKeyName(keysym.sym));

            /* Report the left shift modifier */
            print_kmod(event.key.keysym.mod);

            /* Did the user press Q? */
            if (keysym.sym == SDLK_q) {
               printf("'Q' pressed, exiting.\n");
               exit(0);
            }
            break;

         case SDL_KEYUP:
            printf("Key released (state = %d). ", event.key.state);
            printf("SDL keysym is %i. ", keysym.sym);
            printf("(%s) ", SDL_GetKeyName(keysym.sym));

            print_kmod(event.key.keysym.mod);
            break;

         case SDL_QUIT:
            printf("Quit event. Bye.\n");
            exit(0);
      }
   }

   return 0;
}

