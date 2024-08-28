#ifndef ARCHIEVE_H
#define ARCHIEVE_H

#include <stdio.h>

#include "color_printf.h"

/*!
    Function that, in case of an error, prints where it occurred and terminates the program
    \param [in]  file_input - equation pointer
    \param [in] file_output - Number of input attempts
    \return Returns the number of save symbols
*/
int archive(const char *file_input, const char *file_output);

#endif // ARCHIEVE_H