#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>
#include "Graph.h"

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;

		Graph graph{};
		Vector v1{ 3, 3 };
		Vector v2{ 2, -2 };
		Vector v3{ -7, -8 };
		Vector v4{ 0, 0 };
		v3.add(v1); // Add v1 to v3 (-4, -5)
		v4.subtract(v1); // Subtract v1 from v4 (-3, -3)
		v2.Multiply(2); // Multiply by 2 (4, -4)

		// Add the vectors to the list from graph, drawing them afterwards.
		graph.addVector(&v1);
		graph.addVector(&v2);
		graph.addVector(&v3);
		graph.addVector(&v4);

		if (SDL_CreateWindowAndRenderer(600, 600, 0, &window, &renderer) == 0) {
			SDL_bool done = SDL_FALSE;

			while (!done) {
				SDL_Event event;

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(renderer);

				graph.draw(*renderer);

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
