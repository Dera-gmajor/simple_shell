#ifndef _SHELLY_H
#define _SHELLY_H
#define disprompt "$ "
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct line_up - linked list
 * @a: pointer
 * @b: pointer
 * @c: pointer
 */
typedef struct line_up
{
	char *a;
	char *b;
	struct line_up *c;
} line_up;

/**
 * struct cmd - structure
 * @am: string
 * @fxn: pointer
 */
typedef struct cmd
{
	char *am;
	void (*fxn)(char **, line_up **);
} cmd;

/**
 * struct sys - struct
 * @c: char
 * @fxn: pointer
 */
typedef struct sys
{
	char c;
	void (*fxn)(char *, line_up *, line_up *);
} sys;


int tiebreaker(line_up *m, char *a);
char **line_confirm(char **nm, line_up *m, char **ment);
void plus_line_up(line_up **m, char *a, char *b);
void line_release(line_up *m);
void fxn_print(line_up *m);
void root_check(char **ment, __attribute__((unused))line_up **m);
void environ_set(char **ment, __attribute__((unused))line_up **m);
void environ_unset(char **ment, __attribute__((unused))line_up **m);
void a_k_a(char **ment, line_up **m);
void quit(char **ment, line_up **m);
int execs(char **ment, line_up **m, line_up **m_asign);
char **lineexecs(char *list, line_up **m, line_up **mm);
char **string_sep(char *list, char *e);
int asnchk(char **ment, line_up **m);
int cmdchk(char **ment, line_up **m);
void cmtchk(char **list);
char **string_sep_2(char *list);
int wrdchk(char *g);
int length(char *g, size_t *x);
void tabchk(char **list);
int sepchk(char *list, line_up *m, line_up *mm);
void double_or(char *list, line_up *m, line_up *mm);
void sign_half_col(char *list, line_up *m, line_up *mm);
void double_and(char *list, line_up *m, line_up *mm);
void nwtrail(char **nm, char *v);
char *gttrail(char *nm);
char *dolgt(line_up *m, char **nm);
char **dolchk(char **ment, line_up *m);
int main(int mentcnt, char **mentnum);
char *confirm_ref(char *ment);
void mischk(char *vk, char *mentg, int v);
void scroll(char **mentnum, line_up *m, line_up *mm);
void confirm_refe(char **ment);
char *nizestrings(char **g, char *e);
int listergt(char **f, size_t y);
void prompt_display(int mentcnt);

extern char **environ;
#endif
