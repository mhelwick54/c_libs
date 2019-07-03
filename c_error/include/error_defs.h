#ifndef ERROR_DEFS_H
#define ERROR_DEFS_H

/*******************************************************************************
 *	Error code constants
 *		add defs for any error types
 *		FATAL_LIMIT is the highest error number used to indicate a fatal error,
 *		and terminates the program
 ******************************************************************************/

#define FATAL_LIMIT -10

//fatal
#define MALLOC -2

//non-fatal
#define MEM_BOUND -11
#define UNKNOWN_TYPE -12

#endif
