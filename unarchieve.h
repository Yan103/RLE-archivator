#ifndef UNARCHIEVE_H
#define UNArCHIEVE_H

#include <stdio.h>

#include "color_printf.h"

/*!
    Function that, in case of an error, prints where it occurred and terminates the program
    \param [in]   file_read - equation pointer
    \param [in] file_output - Number of input attempts
    \return Returns the status of the completed coefficient entry
*/
int unarchive(const char *file_read, const char *file_output);

#endif // UNARCHIEVE_H