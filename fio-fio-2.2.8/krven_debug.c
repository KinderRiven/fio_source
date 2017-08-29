//
// Created by 韩书楷 on 2017/8/28.
//
#include "krven_debug.h"

static int krven_debug = 1;
static int krven_debug_thread_data = 1;
static int krven_debug_io_u = 1;

int krven_init() {
    krven_debug = 0;
    krven_debug_thread_data = 0;
    krven_debug_io_u = 0;
}

int krven_print(const char *format, ...) {
    if(krven_debug) {
        char buffer[1024];
        va_list args;
        size_t len;
        va_start(args, format);
        len = vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);
        len = min(len, sizeof(buffer) - 1);
        return fwrite(buffer, len, 1, stdout);
    }
    return -1;
}

int krven_print_thread_data(struct thread_data *td) {
    if(krven_debug_thread_data) {
        //线程编号
        krven_print("[thread data]\n");
        krven_print("thread_num:[%u] ", td->thread_number);
        krven_print("io_u_queued:[%u] ", td->io_u_queued);
        krven_print("\n");
        krven_print("[thread option]\n");
        krven_print("\n");
    }
}

int krven_print_io_u(int ret, struct io_u* io_u) {
    if(krven_debug_io_u) {
        krven_print("result : [%d] ", ret);
        //krven_print("acct_ddir:[%d] ", io_u->acct_ddir);
        krven_print("size:[%lu:%llu] ", io_u->buflen, io_u->offset);
        krven_print("num:[%u] ", io_u->numberio);
        krven_print("start_time:[%ld:%d] ", io_u->start_time.tv_sec, io_u->start_time.tv_usec);
        krven_print("issue_time:[%ld:%d]", io_u->issue_time.tv_sec, io_u->issue_time.tv_usec);
        krven_print("\n");
        return 1;
    }
    return 0;
}

