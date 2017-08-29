//
// Created by 韩书楷 on 2017/8/28.
//

#ifndef FIO_FIO_2_2_8_KRVEN_DEBUG_H_H
#define FIO_FIO_2_2_8_KRVEN_DEBUG_H_H

#include "fio.h"

int krven_init();
int krven_print(const char *format, ...);
int krven_print_thread_data(struct thread_data *td);
int krven_print_io_u(int ret, struct io_u* io_u);

#endif //FIO_FIO_2_2_8_KRVEN_DEBUG_H_H
