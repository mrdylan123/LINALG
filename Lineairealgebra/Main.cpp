#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "Graph.h"

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;

		Graph graph{};
		Vector v1{ 0, 0 };
		Vector v2{ 2, 0 };
		Vector v3{ 2, 2 };
		Vector v4{ 0, 2 };

		v1.setNext(v2);
		v2.setNext(v3);
		v3.setNext(v4);
		v4.setNext(v1);

		// Add the vectors to the list from graph, drawing them afterwards.
		graph.addVector(&v1);
		graph.addVector(&v2);
		graph.addVector(&v3);
		graph.addVector(&v4);

		Vector middle{ 1, 1 };

		graph.scaleFromPoint(2, 2, middle);

		if (SDL_CreateWindowAndRenderer(600, 600, 0, &window, &renderer) == 0) {
			SDL_bool done = SDL_FALSE;

			while (!done) {
				SDL_Event event;

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(renderer);

				graph.draw(*renderer);
				graph.drawShape(*renderer, v1);

				SDL_RenderPresent(renderer);

				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT) {
						done = SDL_TRUE;
					}
				}
			}
		}

		if (renderer) {
			SDL_DestroyRenderer(renderer);
		}
		if (window) {
			SDL_DestroyWindow(window);
		}
	}
	SDL_Quit();
	return 0;
}
