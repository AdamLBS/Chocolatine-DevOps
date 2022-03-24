/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** pushswap.c
*/

#include<stdio.h>
#include<stdlib.h>
#include "my.h"

int compute(values *my_val, int i)
{
    if ((my_val->l_a->data >> i & 1)) {
        move_end(&my_val->l_a, &my_val->tail);
        write(1, "ra ", 3);
    } else {
        do_pb(&my_val->l_b, &my_val->l_a, &my_val->tail);
        write(1, "pb ", 3);
        my_val->count++;
    }
}

int radix_binary(values my_val, int size)
{
    int switch_list = 0, count = 0;
    for (int i = 0 ; i <= 31; i++) {
        for (int tmp = size; tmp != 0; tmp--) {
            compute(&my_val, i);
        }
        for (; my_val.count != 0; my_val.count--) {
            do_pa(&my_val.l_a, &my_val.l_b, &my_val.tail);
            write(1, "pa ", 3);
        }
    }
    manage_neg(my_val, size);
}

int manage_neg(values my_val, int size)
{
    while (size != 0) {
        if ((my_val.l_a->data >> 31 == 0)) {
            move_end(&my_val.l_a, &my_val.tail);
            write(1,"ra ", 3);
            size--;
        } else
            size--;
    }
}
