#include <stdio.h>
#include <inttypes.h>

int main () {
	uint32_t nl = 0, space = 0, tab = 0, c, sym;
	for (sym = 0; (c = getchar()) != EOF; sym++) {
		if (c == '\n') {
			nl++;
		}
		if (c == ' ') {
			space++;
		}
		if (c == '\t') {
			tab++;
		}
	}
	printf("Total:\n\tSymbols: %d\n\tSpaces: %d\n\tTabs: %d\n\tLines: %d\nEND\n", sym, space, tab, nl);
	return 0;
}

