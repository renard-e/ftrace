/*
** syscalls_entry.h for ftrace in /home/jeanadrien/rendu/PROJECT/PSU_2016_ftrace/include
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May  5 01:19:45 2017 Jean-Adrien Domage
** Last update Fri May  5 01:19:46 2017 Jean-Adrien Domage
*/

#ifndef SYSCALLS_ENTRY_H_
# define SYSCALLS_ENTRY_H_

# include "ftrace.h"
# include "tracer.h"

static t_syscall_tab	g_syscalls[] =
{
  { 0, "read", 3, SSIZE_T, { INT, CHAR_P, SIZE_T, 0, 0, 0 }},
  { 1, "write", 3, SSIZE_T, { INT, CONST_CHAR_P, SIZE_T, 0, 0, 0 }},
  { 2, "open", 2, INT, { CONST_CHAR_P, INT, 0, 0, 0, 0 }},
  { 3, "close", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 4, "stat", 2, INT, { CONST_CHAR_P, STRUCT_P, 0, 0, 0, 0 }},
  { 5, "fstat", 2, INT, { INT, STRUCT_STAT_P, 0, 0, 0, 0 }},
  { 6, "lstat", 2, INT, { CONST_CHAR_P, STRUCT_STAT_P, 0, 0, 0, 0 }},
  { 7, "poll", 3, INT, { STRUCT_FD_P, NFDS_T, INT, 0, 0, 0 }},
  { 8, "lseek", 3, OFF_T, { INT, OFF_T, INT, 0, 0, 0 }},
  { 9, "mmap", 6, PVOID, { VOID_P, SIZE_T, INT, INT, INT, OFF_T }},
  { 10, "mprotect", 3, INT, { VOID_P, SIZE_T, INT, 0, 0, 0 }},
  { 11, "munmap", 2, INT, { VOID_P, SIZE_T, 0, 0, 0, 0 }},
  { 12, "brk", 1, VOID_P, { VOID_P, 0, 0, 0, 0, 0 }},
  { 13, "rt_sigaction", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 14, "rt_sigprocmask", 4, INT, { INT, CONST_KERNEL_SIGSET_T_P, KERNEL_SIGSET_T_P, SIZE_T, 0, 0 }},
  { 15, "rt_sigreturn", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 16, "ioctl", 3, INT, { INT, UNSIGNED_LONG, VARGS, 0, 0, 0 }},
  { 17, "pread64", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 18, "pwrite64", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 19, "readv", 3, SSIZE_T, { INT, CONST_STRUCT_IOVEC_P, INT, 0, 0, 0 }},
  { 20, "writev", 3, SSIZE_T, { INT, CONST_STRUCT_IOVEC_P, INT, 0, 0, 0 }},
  { 21, "access", 2, INT, { CONST_CHAR_P, INT, 0, 0, 0, 0 }},
  { 22, "pipe", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 23, "select", 5, INT, { INT, FD_SET_P, FD_SET_P, FD_SET_P, STRUCT_TIMEVAL_P, 0 }},
  { 24, "sched_yield", 1, INT, { VOID, 0, 0, 0, 0, 0 }},
  { 25, "mremap", 0, PVOID, { 0, 0, 0, 0, 0, 0 }},
  { 26, "msync", 3, INT, { VOID_P, SIZE_T, INT, 0, 0, 0 }},
  { 27, "mincore", 3, INT, { VOID_P, SIZE_T, UNSIGNED_CHAR_P, 0, 0, 0 }},
  { 28, "madvise", 3, INT, { VOID_P, SIZE_T, INT, 0, 0, 0 }},
  { 29, "shmget", 3, INT, { KEY_T, SIZE_T, INT, 0, 0, 0 }},
  { 30, "shmat", 3, PVOID, { INT, CONST_VOID_P, INT, 0, 0, 0 }},
  { 31, "shmctl", 3, INT, { INT, INT, STRUCT_SHMID_DS_P, 0, 0, 0 }},
  { 32, "dup", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 33, "dup2", 2, INT, { INT, INT, 0, 0, 0, 0 }},
  { 34, "pause", 1, INT, { VOID, 0, 0, 0, 0, 0 }},
  { 35, "nanosleep", 2, INT, { CONST_STRUCT_TIMESPEC_P, STRUCT_TIMESPEC_P, 0, 0, 0, 0 }},
  { 36, "getitimer", 2, INT, { INT, STRUCT_ITIMERVAL_P, 0, 0, 0, 0 }},
  { 37, "alarm", 1, UNSIGNED_INT, { UNSIGNED_INT, 0, 0, 0, 0, 0 }},
  { 38, "setitimer", 3, INT, { INT, CONST_STRUCT_ITIMERVAL_P, STRUCT_ITIMERVAL_P, 0, 0, 0 }},
  { 39, "getpid", 1, PID_T, { VOID, 0, 0, 0, 0, 0 }},
  { 40, "sendfile", 4, SSIZE_T, { INT, INT, OFF_T_P, SIZE_T, 0, 0 }},
  { 41, "socket", 3, INT, { INT, INT, INT, 0, 0, 0 }},
  { 42, "connect", 3, INT, { INT, CONST_STRUCT_SOCKADDR_P, SOCKLEN_T, 0, 0, 0 }},
  { 43, "accept", 3, INT, { INT, STRUCT_SOCKADDR_P, SOCKLEN_T_P, 0, 0, 0 }},
  { 44, "sendto", 6, SSIZE_T, { INT, CONST_VOID_P, SIZE_T, INT, CONST_STRUCT_SOCKADDR_P, SOCKLEN_T }},
  { 45, "recvfrom", 6, SSIZE_T, { INT, VOID_P, SIZE_T, INT, STRUCT_SOCKADDR_P, SOCKLEN_T_P }},
  { 46, "sendmsg", 3, SSIZE_T, { INT, CONST_STRUCT_MSGHDR_P, INT, 0, 0, 0 }},
  { 47, "recvmsg", 3, SSIZE_T, { INT, STRUCT_MSGHDR_P, INT, 0, 0, 0 }},
  { 48, "shutdown", 2, INT, { INT, INT, 0, 0, 0, 0 }},
  { 49, "bind", 3, INT, { INT, CONST_STRUCT_SOCKADDR_P, SOCKLEN_T, 0, 0, 0 }},
  { 50, "listen", 2, INT, { INT, INT, 0, 0, 0, 0 }},
  { 51, "getsockname", 3, INT, { INT, STRUCT_SOCKADDR_P, SOCKLEN_T_P, 0, 0, 0 }},
  { 52, "getpeername", 3, INT, { INT, STRUCT_SOCKADDR_P, SOCKLEN_T_P, 0, 0, 0 }},
  { 53, "socketpair", 4, INT, { INT, INT, INT, INT, 0, 0 }},
  { 54, "setsockopt", 5, INT, { INT, INT, INT, CONST_VOID_P, SOCKLEN_T, 0 }},
  { 55, "getsockopt", 5, INT, { INT, INT, INT, VOID_P, SOCKLEN_T_P, 0 }},
  { 56, "clone", 0, INT, { 0, 0, 0, 0, 0, 0 }},
  { 57, "fork", 1, PID_T, { VOID, 0, 0, 0, 0, 0 }},
  { 58, "vfork", 1, PID_T, { VOID, 0, 0, 0, 0, 0 }},
  { 59, "execve", 3, INT, { CONST_CHAR_P, CHAR_P_CONST, CHAR_P_CONST, 0, 0, 0 }},
  { 60, "exit", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 61, "wait4", 4, PID_T, { PID_T, INT_P, INT, STRUCT_RUSAGE_P, 0, 0 }},
  { 62, "kill", 2, INT, { PID_T, INT, 0, 0, 0, 0 }},
  { 63, "uname", 1, INT, { STRUCT_UTSNAME_P, 0, 0, 0, 0, 0 }},
  { 64, "semget", 3, INT, { KEY_T, INT, INT, 0, 0, 0 }},
  { 65, "semop", 3, INT, { INT, STRUCT_SEMBUF_P, SIZE_T, 0, 0, 0 }},
  { 66, "semctl", 4, INT, { INT, INT, INT, VARGS, 0, 0 }},
  { 67, "shmdt", 1, INT, { CONST_VOID_P, 0, 0, 0, 0, 0 }},
  { 68, "msgget", 2, INT, { KEY_T, INT, 0, 0, 0, 0 }},
  { 69, "msgsnd", 4, INT, { INT, CONST_VOID_P, SIZE_T, INT, 0, 0 }},
  { 70, "msgrcv", 5, SSIZE_T, { INT, VOID_P, SIZE_T, LONG, INT, 0 }},
  { 71, "msgctl", 3, INT, { INT, INT, STRUCT_MSQID_DS_P, 0, 0, 0 }},
  { 72, "fcntl", 0, INT, { 0, 0, 0, 0, 0, 0 }},
  { 73, "flock", 2, INT, { INT, INT, 0, 0, 0, 0 }},
  { 74, "fsync", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 75, "fdatasync", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 76, "truncate", 2, INT, { CONST_CHAR_P, OFF_T, 0, 0, 0, 0 }},
  { 77, "ftruncate", 2, INT, { INT, OFF_T, 0, 0, 0, 0 }},
  { 78, "getdents", 3, INT, { UNSIGNED_INT, STRUCT_LINUX_DIRENT_P, UNSIGNED_INT, 0, 0, 0 }},
  { 79, "getcwd", 2, PCHAR, { CHAR_P, SIZE_T, 0, 0, 0, 0 }},
  { 80, "chdir", 1, INT, { CONST_CHAR_P, 0, 0, 0, 0, 0 }},
  { 81, "fchdir", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 82, "rename", 2, INT, { CONST_CHAR_P, CONST_CHAR_P, 0, 0, 0, 0 }},
  { 83, "mkdir", 2, INT, { CONST_CHAR_P, MODE_T, 0, 0, 0, 0 }},
  { 84, "rmdir", 1, INT, { CONST_CHAR_P, 0, 0, 0, 0, 0 }},
  { 85, "creat", 2, INT, { CONST_CHAR_P, MODE_T, 0, 0, 0, 0 }},
  { 86, "link", 2, INT, { CONST_CHAR_P, CONST_CHAR_P, 0, 0, 0, 0 }},
  { 87, "unlink", 1, INT, { CONST_CHAR_P, 0, 0, 0, 0, 0 }},
  { 88, "symlink", 2, INT, { CONST_CHAR_P, CONST_CHAR_P, 0, 0, 0, 0 }},
  { 89, "readlink", 3, SSIZE_T, { CONST_CHAR_P, CHAR_P, SIZE_T, 0, 0, 0 }},
  { 90, "chmod", 2, INT, { CONST_CHAR_P, MODE_T, 0, 0, 0, 0 }},
  { 91, "fchmod", 2, INT, { INT, MODE_T, 0, 0, 0, 0 }},
  { 92, "chown", 3, INT, { CONST_CHAR_P, UID_T, GID_T, 0, 0, 0 }},
  { 93, "fchown", 3, INT, { INT, UID_T, GID_T, 0, 0, 0 }},
  { 94, "lchown", 3, INT, { CONST_CHAR_P, UID_T, GID_T, 0, 0, 0 }},
  { 95, "umask", 1, MODE_T, { MODE_T, 0, 0, 0, 0, 0 }},
  { 96, "gettimeofday", 2, INT, { STRUCT_TIMEVAL_P, STRUCT_TIMEZONE_P, 0, 0, 0, 0 }},
  { 97, "getrlimit", 2, INT, { INT, STRUCT_RLIMIT_P, 0, 0, 0, 0 }},
  { 98, "getrusage", 2, INT, { INT, STRUCT_RUSAGE_P, 0, 0, 0, 0 }},
  { 99, "sysinfo", 1, INT, { STRUCT_P, 0, 0, 0, 0, 0 }},
  { 100, "times", 1, CLOCK_T, { STRUCT_TMS_P, 0, 0, 0, 0, 0 }},
  { 101, "ptrace", 4, LONG, { ENUM_REQUEST, PID_T, VOID_P, VOID_P, 0, 0 }},
  { 102, "getuid", 1, UID_T, { VOID, 0, 0, 0, 0, 0 }},
  { 103, "syslog", 3, INT, { INT, CHAR_P, INT, 0, 0, 0 }},
  { 104, "getgid", 1, GID_T, { VOID, 0, 0, 0, 0, 0 }},
  { 105, "setuid", 1, INT, { UID_T, 0, 0, 0, 0, 0 }},
  { 106, "setgid", 1, INT, { GID_T, 0, 0, 0, 0, 0 }},
  { 107, "geteuid", 1, UID_T, { VOID, 0, 0, 0, 0, 0 }},
  { 108, "getegid", 1, GID_T, { VOID, 0, 0, 0, 0, 0 }},
  { 109, "setpgid", 2, INT, { PID_T, PID_T, 0, 0, 0, 0 }},
  { 110, "getppid", 1, PID_T, { VOID, 0, 0, 0, 0, 0 }},
  { 111, "getpgrp", 0, PID_T, { 0, 0, 0, 0, 0, 0 }},
  { 112, "setsid", 1, PID_T, { VOID, 0, 0, 0, 0, 0 }},
  { 113, "setreuid", 2, INT, { UID_T, UID_T, 0, 0, 0, 0 }},
  { 114, "setregid", 2, INT, { GID_T, GID_T, 0, 0, 0, 0 }},
  { 115, "getgroups", 2, INT, { INT, GID_T, 0, 0, 0, 0 }},
  { 116, "setgroups", 2, INT, { SIZE_T, CONST_GID_T_P, 0, 0, 0, 0 }},
  { 117, "setresuid", 3, INT, { UID_T, UID_T, UID_T, 0, 0, 0 }},
  { 118, "getresuid", 3, INT, { UID_T_P, UID_T_P, UID_T_P, 0, 0, 0 }},
  { 119, "setresgid", 3, INT, { GID_T, GID_T, GID_T, 0, 0, 0 }},
  { 120, "getresgid", 3, INT, { GID_T_P, GID_T_P, GID_T_P, 0, 0, 0 }},
  { 121, "getpgid", 1, PID_T, { PID_T, 0, 0, 0, 0, 0 }},
  { 122, "setfsuid", 1, INT, { UID_T, 0, 0, 0, 0, 0 }},
  { 123, "setfsgid", 1, INT, { UID_T, 0, 0, 0, 0, 0 }},
  { 124, "getsid", 1, PID_T, { PID_T, 0, 0, 0, 0, 0 }},
  { 125, "capget", 2, INT, { CAP_USER_HEADER_T, CAP_USER_DATA_T, 0, 0, 0, 0 }},
  { 126, "capset", 2, INT, { CAP_USER_HEADER_T, CONST_CAP_USER_DATA_T, 0, 0, 0, 0 }},
  { 127, "rt_sigpending", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 128, "rt_sigtimedwait", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 129, "rt_sigqueueinfo", 3, INT, { PID_T, INT, SIGINFO_T_P, 0, 0, 0 }},
  { 130, "rt_sigsuspend", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 131, "sigaltstack", 2, INT, { CONST_STACK_T_P, STACK_T_P, 0, 0, 0, 0 }},
  { 132, "utime", 2, INT, { CONST_CHAR_P, CONST_STRUCT_UTIMBUF_P, 0, 0, 0, 0 }},
  { 133, "mknod", 3, INT, { CONST_CHAR_P, MODE_T, DEV_T, 0, 0, 0 }},
  { 134, "uselib", 1, INT, { CONST_CHAR_P, 0, 0, 0, 0, 0 }},
  { 135, "personality", 1, INT, { UNSIGNED_LONG, 0, 0, 0, 0, 0 }},
  { 136, "ustat", 2, INT, { DEV_T, STRUCT_P, 0, 0, 0, 0 }},
  { 137, "statfs", 2, INT, { CONST_CHAR_P, STRUCT_P, 0, 0, 0, 0 }},
  { 138, "fstatfs", 2, INT, { INT, STRUCT_STATFS_P, 0, 0, 0, 0 }},
  { 139, "sysfs", 2, INT, { INT, CONST_CHAR_P, 0, 0, 0, 0 }},
  { 140, "getpriority", 2, INT, { INT, ID_T, 0, 0, 0, 0 }},
  { 141, "setpriority", 3, INT, { INT, ID_T, INT, 0, 0, 0 }},
  { 142, "sched_setparam", 2, INT, { PID_T, CONST_STRUCT_SCHED_PARAM_P, 0, 0, 0, 0 }},
  { 143, "sched_getparam", 2, INT, { PID_T, STRUCT_SCHED_PARAM_P, 0, 0, 0, 0 }},
  { 144, "sched_setscheduler", 3, INT, { PID_T, INT, CONST_STRUCT_SCHED_PARAM_P, 0, 0, 0 }},
  { 145, "sched_getscheduler", 1, INT, { PID_T, 0, 0, 0, 0, 0 }},
  { 146, "sched_get_priority_max", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 147, "sched_get_priority_min", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 148, "sched_rr_get_interval", 2, INT, { PID_T, STRUCT_TIMESPEC_P_, 0, 0, 0, 0 }},
  { 149, "mlock", 2, INT, { CONST_VOID_P, SIZE_T, 0, 0, 0, 0 }},
  { 150, "munlock", 2, INT, { CONST_VOID_P, SIZE_T, 0, 0, 0, 0 }},
  { 151, "mlockall", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 152, "munlockall", 1, INT, { VOID, 0, 0, 0, 0, 0 }},
  { 153, "vhangup", 1, INT, { VOID, 0, 0, 0, 0, 0 }},
  { 154, "modify_ldt", 3, INT, { INT, VOID_P, UNSIGNED_LONG, 0, 0, 0 }},
  { 155, "pivot_root", 2, INT, { CONST_CHAR_P, CONST_CHAR_P, 0, 0, 0, 0 }},
  { 156, "_sysctl", 1, INT, { STRUCT_ARGS_P, 0, 0, 0, 0, 0 }},
  { 157, "prctl", 5, INT, { INT, UNSIGNED_LONG, UNSIGNED_LONG, UNSIGNED_LONG, UNSIGNED_LONG, 0 }},
  { 158, "arch_prctl", 2, INT, { INT, UNSIGNED_LONG, 0, 0, 0, 0 }},
  { 159, "adjtimex", 1, INT, { STRUCT_TIMEX_P, 0, 0, 0, 0, 0 }},
  { 160, "setrlimit", 2, INT, { INT, CONST_STRUCT_RLIMIT_P, 0, 0, 0, 0 }},
  { 161, "chroot", 1, INT, { CONST_CHAR_P, 0, 0, 0, 0, 0 }},
  { 162, "sync", 1, VOID, { VOID, 0, 0, 0, 0, 0 }},
  { 163, "acct", 1, INT, { CONST_CHAR_P, 0, 0, 0, 0, 0 }},
  { 164, "settimeofday", 2, INT, { CONST_STRUCT_TIMEVAL_P, CONST_STRUCT_TIMEZONE_P, 0, 0, 0, 0 }},
  { 165, "mount", 5, INT, { CONST_CHAR_P, CONST_CHAR_P, CONST_CHAR_P, UNSIGNED_LONG, CONST_VOID_P, 0 }},
  { 166, "umount2", 2, INT, { CONST_CHAR_P, INT, 0, 0, 0, 0 }},
  { 167, "swapon", 2, INT, { CONST_CHAR_P, INT, 0, 0, 0, 0 }},
  { 168, "swapoff", 1, INT, { CONST_CHAR_P, 0, 0, 0, 0, 0 }},
  { 169, "reboot", 4, INT, { INT, INT, INT, VOID_P, 0, 0 }},
  { 170, "sethostname", 2, INT, { CONST_CHAR_P, SIZE_T, 0, 0, 0, 0 }},
  { 171, "setdomainname", 2, INT, { CONST_CHAR_P, SIZE_T, 0, 0, 0, 0 }},
  { 172, "iopl", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 173, "ioperm", 3, INT, { UNSIGNED_LONG, UNSIGNED_LONG, INT, 0, 0, 0 }},
  { 174, "create_module", 2, CADDR_T, { CONST_CHAR_P, SIZE_T, 0, 0, 0, 0 }},
  { 175, "init_module", 3, INT, { VOID_P, UNSIGNED_LONG, CONST_CHAR_P, 0, 0, 0 }},
  { 176, "delete_module", 2, INT, { CONST_CHAR_P, INT, 0, 0, 0, 0 }},
  { 177, "get_kernel_syms", 1, INT, { STRUCT_KERNEL_SYM_P, 0, 0, 0, 0, 0 }},
  { 178, "query_module", 5, INT, { CONST_CHAR_P, INT, VOID_P, SIZE_T, SIZE_T_P, 0 }},
  { 179, "quotactl", 4, INT, { INT, CONST_CHAR_P, INT, CADDR_T, 0, 0 }},
  { 180, "nfsservctl", 3, LONG, { INT, STRUCT_NFSCTL_ARG_P, UNION_NFSCTL_RES_P, 0, 0, 0 }},
  { 181, "getpmsg", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 182, "putpmsg", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 183, "afs_syscall", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 184, "tuxcall", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 185, "security", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 186, "gettid", 1, PID_T, { VOID, 0, 0, 0, 0, 0 }},
  { 187, "readahead", 3, SSIZE_T, { INT, OFF64_T, SIZE_T, 0, 0, 0 }},
  { 188, "setxattr", 5, INT, { CONST_CHAR_P, CONST_CHAR_P, CONST_VOID_P, SIZE_T, INT, 0 }},
  { 189, "lsetxattr", 5, INT, { CONST_CHAR_P, CONST_CHAR_P, CONST_VOID_P, SIZE_T, INT, 0 }},
  { 190, "fsetxattr", 5, INT, { INT, CONST_CHAR_P, CONST_VOID_P, SIZE_T, INT, 0 }},
  { 191, "getxattr", 4, SSIZE_T, { CONST_CHAR_P, CONST_CHAR_P, VOID_P, SIZE_T, 0, 0 }},
  { 192, "lgetxattr", 4, SSIZE_T, { CONST_CHAR_P, CONST_CHAR_P, VOID_P, SIZE_T, 0, 0 }},
  { 193, "fgetxattr", 4, SSIZE_T, { INT, CONST_CHAR_P, VOID_P, SIZE_T, 0, 0 }},
  { 194, "listxattr", 3, SSIZE_T, { CONST_CHAR_P, CHAR_P, SIZE_T, 0, 0, 0 }},
  { 195, "llistxattr", 3, SSIZE_T, { CONST_CHAR_P, CHAR_P, SIZE_T, 0, 0, 0 }},
  { 196, "flistxattr", 3, SSIZE_T, { INT, CHAR_P, SIZE_T, 0, 0, 0 }},
  { 197, "removexattr", 2, INT, { CONST_CHAR_P, CONST_CHAR_P, 0, 0, 0, 0 }},
  { 198, "lremovexattr", 2, INT, { CONST_CHAR_P, CONST_CHAR_P, 0, 0, 0, 0 }},
  { 199, "fremovexattr", 2, INT, { INT, CONST_CHAR_P, 0, 0, 0, 0 }},
  { 200, "tkill", 2, INT, { INT, INT, 0, 0, 0, 0 }},
  { 201, "time", 1, TIME_T, { T_T_P, 0, 0, 0, 0, 0 }},
  { 202, "futex", 0, INT, { 0, 0, 0, 0, 0, 0 }},
  { 203, "sched_setaffinity", 3, INT, { PID_T, SIZE_T, CONST_CPU_SET_T_P, 0, 0, 0 }},
  { 204, "sched_getaffinity", 3, INT, { PID_T, SIZE_T, CPU_SET_T_P, 0, 0, 0 }},
  { 205, "set_thread_area", 1, INT, { STRUCT_USER_DESC_P, 0, 0, 0, 0, 0 }},
  { 206, "io_setup", 2, INT, { UNSIGNED, AIO_CONTEXT_T_P, 0, 0, 0, 0 }},
  { 207, "io_destroy", 1, INT, { AIO_CONTEXT_T, 0, 0, 0, 0, 0 }},
  { 208, "io_getevents", 5, INT, { AIO_CONTEXT_T, LONG, LONG, STRUCT_IO_EVENT_P, STRUCT_TIMESPEC_P, 0 }},
  { 209, "io_submit", 3, INT, { AIO_CONTEXT_T, LONG, STRUCT_IOCB_P, 0, 0, 0 }},
  { 210, "io_cancel", 3, INT, { AIO_CONTEXT_T, STRUCT_IOCB_P, STRUCT_IO_EVENT_P, 0, 0, 0 }},
  { 211, "get_thread_area", 1, INT, { STRUCT_USER_DESC_P, 0, 0, 0, 0, 0 }},
  { 212, "lookup_dcookie", 3, INT, { U64, CHAR_P, SIZE_T, 0, 0, 0 }},
  { 213, "epoll_create", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 214, "epoll_ctl_old", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 215, "epoll_wait_old", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 216, "remap_file_pages", 5, INT, { VOID_P, SIZE_T, INT, SIZE_T, INT, 0 }},
  { 217, "getdents64", 3, INT, { UNSIGNED_INT, STRUCT_LINUX_DIRENT64_P, UNSIGNED_INT, 0, 0, 0 }},
  { 218, "set_tid_address", 1, LONG, { INT_P, 0, 0, 0, 0, 0 }},
  { 219, "restart_syscall", 1, INT, { VOID, 0, 0, 0, 0, 0 }},
  { 220, "semtimedop", 4, INT, { INT, STRUCT_SEMBUF_P, SIZE_T, CONST_STRUCT_TIMESPEC_P, 0, 0 }},
  { 221, "fadvise64", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 222, "timer_create", 3, INT, { CLOCKID_T, STRUCT_SIGEVENT_P, TIMER_T_P, 0, 0, 0 }},
  { 223, "timer_settime", 4, INT, { TIMER_T, INT, CONST_STRUCT_ITIMERSPEC_P, STRUCT_ITIMERSPEC_P, 0, 0 }},
  { 224, "timer_gettime", 2, INT, { TIMER_T, STRUCT_ITIMERSPEC_P, 0, 0, 0, 0 }},
  { 225, "timer_getoverrun", 1, INT, { TIMER_T, 0, 0, 0, 0, 0 }},
  { 226, "timer_delete", 1, INT, { TIMER_T, 0, 0, 0, 0, 0 }},
  { 227, "clock_settime", 2, INT, { CLOCKID_T, CONST_STRUCT_TIMESPEC_P, 0, 0, 0, 0 }},
  { 228, "clock_gettime", 2, INT, { CLOCKID_T, STRUCT_TIMESPEC_P, 0, 0, 0, 0 }},
  { 229, "clock_getres", 2, INT, { CLOCKID_T, STRUCT_TIMESPEC_P, 0, 0, 0, 0 }},
  { 230, "clock_nanosleep", 4, INT, { CLOCKID_T, INT, CONST_STRUCT_TIMESPEC_P, STRUCT_TIMESPEC_P, 0, 0 }},
  { 231, "exit_group", 1, VOID, { INT, 0, 0, 0, 0, 0 }},
  { 232, "epoll_wait", 4, INT, { INT, STRUCT_EPOLL_EVENT_P, INT, INT, 0, 0 }},
  { 233, "epoll_ctl", 4, INT, { INT, INT, INT, STRUCT_EPOLL_EVENT_P, 0, 0 }},
  { 234, "tgkill", 3, INT, { INT, INT, INT, 0, 0, 0 }},
  { 235, "utimes", 2, INT, { CONST_CHAR_P, CONST_STRUCT_TIMEVAL, 0, 0, 0, 0 }},
  { 236, "vserver", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 237, "mbind", 6, LONG, { VOID_P, UNSIGNED_LONG, INT, CONST_UNSIGNED_LONG_P, UNSIGNED_LONG, UNSIGNED }},
  { 238, "set_mempolicy", 3, LONG, { INT, CONST_UNSIGNED_LONG_P, UNSIGNED_LONG, 0, 0, 0 }},
  { 239, "get_mempolicy", 5, INT, { INT_P, UNSIGNED_LONG_P, UNSIGNED_LONG, VOID_P, UNSIGNED_LONG, 0 }},
  { 240, "mq_open", 2, MQD_T, { CONST_CHAR_P, INT, 0, 0, 0, 0 }},
  { 241, "mq_unlink", 1, INT, { CONST_CHAR_P, 0, 0, 0, 0, 0 }},
  { 242, "mq_timedsend", 5, INT, { MQD_T, CONST_CHAR_P, SIZE_T, UNSIGNED_INT, CONST_STRUCT_TIMESPEC_P, 0 }},
  { 243, "mq_timedreceive", 5, SSIZE_T, { MQD_T, CHAR_P, SIZE_T, UNSIGNED_INT_P, CONST_STRUCT_TIMESPEC_P, 0 }},
  { 244, "mq_notify", 2, INT, { MQD_T, CONST_STRUCT_SIGEVENT_P, 0, 0, 0, 0 }},
  { 245, "mq_getsetattr", 3, INT, { MQD_T, STRUCT_MQ_ATTR_P, STRUCT_MQ_ATTR_P, 0, 0, 0 }},
  { 246, "kexec_load", 4, LONG, { UNSIGNED_LONG, UNSIGNED_LONG, STRUCT_KEXEC_SEGMENT_P, UNSIGNED_LONG, 0, 0 }},
  { 247, "waitid", 4, INT, { IDTYPE_T, ID_T, SIGINFO_T_P, INT, 0, 0 }},
  { 248, "add_key", 5, KEY_SERIAL_T, { CONST_CHAR_P, CONST_CHAR_P, CONST_VOID_P, SIZE_T, KEY_SERIAL_T, 0 }},
  { 249, "request_key", 4, KEY_SERIAL_T, { CONST_CHAR_P, CONST_CHAR_P, CONST_CHAR_P, KEY_SERIAL_T, 0, 0 }},
  { 250, "keyctl", 2, LONG, { INT, VARGS, 0, 0, 0, 0 }},
  { 251, "ioprio_set", 3, INT, { INT, INT, INT, 0, 0, 0 }},
  { 252, "ioprio_get", 2, INT, { INT, INT, 0, 0, 0, 0 }},
  { 253, "inotify_init", 1, INT, { VOID, 0, 0, 0, 0, 0 }},
  { 254, "inotify_add_watch", 3, INT, { INT, CONST_CHAR_P, UINT32_T, 0, 0, 0 }},
  { 255, "inotify_rm_watch", 2, INT, { INT, INT, 0, 0, 0, 0 }},
  { 256, "migrate_pages", 4, LONG, { INT, UNSIGNED_LONG, CONST_UNSIGNED_LONG_P, CONST_UNSIGNED_LONG_P, 0, 0 }},
  { 257, "openat", 3, INT, { INT, CONST_CHAR_P, INT, 0, 0, 0 }},
  { 258, "mkdirat", 3, INT, { INT, CONST_CHAR_P, MODE_T, 0, 0, 0 }},
  { 259, "mknodat", 4, INT, { INT, CONST_CHAR_P, MODE_T, DEV_T, 0, 0 }},
  { 260, "fchownat", 5, INT, { INT, CONST_CHAR_P, UID_T, GID_T, INT, 0 }},
  { 261, "futimesat", 3, INT, { INT, CONST_CHAR_P, CONST_STRUCT_TIMEVAL, 0, 0, 0 }},
  { 262, "newfstatat", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 263, "unlinkat", 3, INT, { INT, CONST_CHAR_P, INT, 0, 0, 0 }},
  { 264, "renameat", 4, INT, { INT, CONST_CHAR_P, INT, CONST_CHAR_P, 0, 0 }},
  { 265, "linkat", 5, INT, { INT, CONST_CHAR_P, INT, CONST_CHAR_P, INT, 0 }},
  { 266, "symlinkat", 3, INT, { CONST_CHAR_P, INT, CONST_CHAR_P, 0, 0, 0 }},
  { 267, "readlinkat", 4, SSIZE_T, { INT, CONST_CHAR_P, CHAR_P, SIZE_T, 0, 0 }},
  { 268, "fchmodat", 4, INT, { INT, CONST_CHAR_P, MODE_T, INT, 0, 0 }},
  { 269, "faccessat", 4, INT, { INT, CONST_CHAR_P, INT, INT, 0, 0 }},
  { 270, "pselect6", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 271, "ppoll", 4, INT, { STRUCT_POLLFD_P, NFDS_T, CONST_STRUCT_TIMESPEC_P, CONST_SIGSET_T_P, 0, 0 }},
  { 272, "unshare", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 273, "set_robust_list", 2, LONG, { STRUCT_ROBUST_LIST_HEAD_P, SIZE_T, 0, 0, 0, 0 }},
  { 274, "get_robust_list", 3, LONG, { INT, STRUCT_ROBUST_LIST_HEAD_P, SIZE_T_P, 0, 0, 0 }},
  { 275, "splice", 6, SSIZE_T, { INT, LOFF_T_P, INT, LOFF_T_P, SIZE_T, UNSIGNED_INT }},
  { 276, "tee", 4, SSIZE_T, { INT, INT, SIZE_T, UNSIGNED_INT, 0, 0 }},
  { 277, "sync_file_range", 4, INT, { INT, OFF64_T, OFF64_T, UNSIGNED_INT, 0, 0 }},
  { 278, "vmsplice", 4, SSIZE_T, { INT, CONST_STRUCT_IOVEC_P, UNSIGNED_LONG, UNSIGNED_INT, 0, 0 }},
  { 279, "move_pages", 6, LONG, { INT, UNSIGNED_LONG, VOID_P, CONST_INT_P, INT_P, INT }},
  { 280, "utimensat", 4, INT, { INT, CONST_CHAR_P, CONST_STRUCT_TIMESPEC, INT, 0, 0 }},
  { 281, "epoll_pwait", 5, INT, { INT, STRUCT_EPOLL_EVENT_P, INT, INT, CONST_SIGSET_T_P, 0 }},
  { 282, "signalfd", 3, INT, { INT, CONST_SIGSET_T_P, INT, 0, 0, 0 }},
  { 283, "timerfd_create", 2, INT, { INT, INT, 0, 0, 0, 0 }},
  { 284, "eventfd", 2, INT, { UNSIGNED_INT, INT, 0, 0, 0, 0 }},
  { 285, "fallocate", 4, INT, { INT, INT, OFF_T, OFF_T, 0, 0 }},
  { 286, "timerfd_settime", 4, INT, { INT, INT, CONST_STRUCT_ITIMERSPEC_P, STRUCT_ITIMERSPEC_P, 0, 0 }},
  { 287, "timerfd_gettime", 2, INT, { INT, STRUCT_ITIMERSPEC_P, 0, 0, 0, 0 }},
  { 288, "accept4", 4, INT, { INT, STRUCT_SOCKADDR_P, SOCKLEN_T_P, INT, 0, 0 }},
  { 289, "signalfd4", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 290, "eventfd2", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 291, "epoll_create1", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 292, "dup3", 3, INT, { INT, INT, INT, 0, 0, 0 }},
  { 293, "pipe2", 2, INT, { INT, INT, 0, 0, 0, 0 }},
  { 294, "inotify_init1", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 295, "preadv", 4, SSIZE_T, { INT, CONST_STRUCT_IOVEC_P, INT, OFF_T, 0, 0 }},
  { 296, "pwritev", 4, SSIZE_T, { INT, CONST_STRUCT_IOVEC_P, INT, OFF_T, 0, 0 }},
  { 297, "rt_tgsigqueueinfo", 4, INT, { PID_T, PID_T, INT, SIGINFO_T_P, 0, 0 }},
  { 298, "perf_event_open", 5, INT, { STRUCT_PERF_EVENT_ATTR_P, PID_T, INT, INT, UNSIGNED_LONG, 0 }},
  { 299, "recvmmsg", 5, INT, { INT, STRUCT_MMSGHDR_P, UNSIGNED_INT, UNSIGNED_INT, STRUCT_TIMESPEC_P, 0 }},
  { 300, "fanotify_init", 2, INT, { UNSIGNED_INT, UNSIGNED_INT, 0, 0, 0, 0 }},
  { 301, "fanotify_mark", 5, INT, { INT, UNSIGNED_INT, UINT64_T, INT, CONST_CHAR_P, 0 }},
  { 302, "prlimit64", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 303, "name_to_handle_at", 5, INT, { INT, CONST_CHAR_P, STRUCT_FILE_HANDLE_P, INT_P, INT, 0 }},
  { 304, "open_by_handle_at", 3, INT, { INT, STRUCT_FILE_HANDLE_P, INT, 0, 0, 0 }},
  { 305, "clock_adjtime", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 306, "syncfs", 1, INT, { INT, 0, 0, 0, 0, 0 }},
  { 307, "sendmmsg", 4, INT, { INT, STRUCT_MMSGHDR_P, UNSIGNED_INT, UNSIGNED_INT, 0, 0 }},
  { 308, "setns", 2, INT, { INT, INT, 0, 0, 0, 0 }},
  { 309, "getcpu", 3, INT, { UNSIGNED_P, UNSIGNED_P, STRUCT__CACHE_P, 0, 0, 0 }},
  { 310, "process_vm_readv", 6, SSIZE_T, { PID_T, CONST_STRUCT_IOVEC_P, UNSIGNED_LONG, CONST_STRUCT_IOVEC_P, UNSIGNED_LONG, UNSIGNED_LONG }},
  { 311, "process_vm_writev", 6, SSIZE_T, { PID_T, CONST_STRUCT_IOVEC_P, UNSIGNED_LONG, CONST_STRUCT_IOVEC_P, UNSIGNED_LONG, UNSIGNED_LONG }},
  { 312, "kcmp", 5, INT, { PID_T, PID_T, INT, UNSIGNED_LONG, UNSIGNED_LONG, 0 }},
  { 313, "finit_module", 3, INT, { INT, CONST_CHAR_P, INT, 0, 0, 0 }},
  { 314, "sched_setattr", 3, INT, { PID_T, STRUCT_SCHED_ATTR_P, UNSIGNED_INT, 0, 0, 0 }},
  { 315, "sched_getattr", 4, INT, { PID_T, STRUCT_SCHED_ATTR_P, UNSIGNED_INT, UNSIGNED_INT, 0, 0 }},
  { 316, "renameat2", 5, INT, { INT, CONST_CHAR_P, INT, CONST_CHAR_P, UNSIGNED_INT, 0 }},
  { 317, "seccomp", 3, INT, { UNSIGNED_INT, UNSIGNED_INT, VOID_P, 0, 0, 0 }},
  { 318, "getrandom", 3, INT, { VOID_P, SIZE_T, UNSIGNED_INT, 0, 0, 0 }},
  { 319, "memfd_create", 2, INT, { CONST_CHAR_P, UNSIGNED_INT, 0, 0, 0, 0 }},
  { 320, "kexec_file_load", 5, LONG, { INT, INT, UNSIGNED_LONG, CONST_CHAR_P, UNSIGNED_LONG, 0 }},
  { 321, "bpf", 3, INT, { INT, UNION__ATTR_P, UNSIGNED_INT, 0, 0, 0 }},
  { 322, "execveat", 5, INT, { INT, CONST_CHAR_P, CHAR_P_CONST, CHAR_P_CONST, INT, 0 }},
  { 323, "userfaultfd", 6, 0, { 0, 0, 0, 0, 0, 0 }},
  { 324, "membarrier", 2, INT, { INT, INT, 0, 0, 0, 0 }},
  { 325, "mlock2", 3, INT, { CONST_VOID_P, SIZE_T, INT, 0, 0, 0 }},
  { 326, "copy_file_range", 6, SSIZE_T, { INT, LOFF_T_P, INT, LOFF_T_P, SIZE_T, UNSIGNED_INT }},
  { 327, "preadv2", 5, SSIZE_T, { INT, CONST_STRUCT_IOVEC_P, INT, OFF_T, INT, 0 }},
  { 328, "pwritev2", 5, SSIZE_T, { INT, CONST_STRUCT_IOVEC_P, INT, OFF_T, INT, 0 }},
  { 329, "pkey_mprotect", 4, INT, { VOID_P, SIZE_T, INT, INT, 0, 0 }},
  { 330, "pkey_alloc", 2, INT, { UNSIGNED_LONG, UNSIGNED_LONG, 0, 0, 0, 0 }},
  { 331, "pkey_free", 1, INT, { INT, 0, 0, 0, 0, 0 }},
};

#endif /* !SYSCALLS_ENTRY_H_ */
