// Copyright [2022] <griselle>

#include <stdio.h>
#include <stdarg.h>
#include "print_module.h"
#include "documentation_module.h"

void printf_availability(int avail_mask, int document_count, ...);

int main(void) {
    #ifdef PRINT_MODULE
    print_log(print_char, Module_load_success_message);
    #endif  // PRINT_MODULE

    #ifdef DOCUMENTATION_MODULE
    int availability_mask;
    availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    printf_availability(availability_mask, Documents_count, Documents);
    #endif  // DOCUMENTATION_MODULE

    return (0);
}


#ifdef DOCUMENTATION_MODULE
void printf_availability(int avail_mask, int document_count, ...) {
    int count;
    va_list args;

    avail_mask = 5;
    count = 1;
    va_start(args, document_count);
    if (document_count > 16)
        document_count = 16;
    while (count < document_count + 1) {
        printf("[%s: ", va_arg(args, char *));
        if ((avail_mask >> (Documents_count - count)) & 1)
            printf("available");
        else
            printf("unavailable");
        printf("]\n");
        count++;
    }
    va_end(args);
}
#endif  // DOCUMENTATION_MODULE
