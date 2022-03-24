// Copyright [2022] <griselle>

#ifndef SRC_DOCUMENTATION_MODULE_H_

#define SRC_DOCUMENTATION_MODULE_H_
#define Documents "Linked lists", "Queues", "Maps", "Binary Trees"
#define Available_document "Binary Trees"
#define Documents_count 4

int check_available_documentation_module(int (*validate)(char*), int document_count, ...);
int validate(char *data);
#endif  // SRC_DOCUMENTATION_MODULE_H_
