/*
Copyright 2019 Сергей Меликян АПО-12
*/

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

typedef enum mark {
    NOT_MARKED,
    ONE,
    TWO,
    TREE,
    FOUR,
    FIVE
} __attribute__((packed)) Mark;

typedef struct rate {
    unsigned user_id;
    Mark mark;
} __attribute__((packed)) Rate;

typedef struct object {
    unsigned obj_id;
    unsigned rate_size;
    unsigned rate_ptr;
    Rate* rating_array;
} __attribute__((packed)) Object;

typedef struct object_array {
    Object *array;
    unsigned size;
} Objects;

Object* create_object(unsigned id);
void free_object(Object* object);
int add_rate(Object* obj, int m, unsigned user_id);

Objects *create_objects(unsigned size);
void free_objects(Objects *objs);

#endif  //  INCLUDE_OBJECT_H_