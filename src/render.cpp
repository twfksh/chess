#include "render.hpp"

void Render::render() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if ((i + j) % 2 == 0) {
				printf("\033[47m   ");
			} else {
				printf("\033[40m   ");
			}
		}
		printf("\033[0m\n");
	}
}