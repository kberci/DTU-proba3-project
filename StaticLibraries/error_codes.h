#pragma once

#define EOK 1

#define ENOTOK -1
#define EARGS -2
#define ESHAPE -3

typedef int ERROR;

inline ERROR ERREVAL(const ERROR ERR) {
	return ERR == EOK ? 0 : 1;
}

inline void EPRINT(const ERROR ERR) {
	switch (ERR) {
	case EARGS:
		printf("ERROR: Invalid arguments provided to function call!");
		break;
	case ESHAPE:
		printf("ERROR: Source and target shapes do not match!");
		break;
	default:
		printf("ERROR");
		break;
	}
}