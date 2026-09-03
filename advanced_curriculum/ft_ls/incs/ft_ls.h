#ifndef FT_LS
#define FT_LS

#include "../libft/incs/libft.h"
#include <stdlib.h>

typedef struct s_flags {

    int l;  // -l : long format
    int R;  // -R : recursive
    int a;  // -a : show hidden files ex : .git
    int r;  // -r reverse order
    int t;  // -t : sort by time
   
    //BONUS
    int u;  // -u : use access time for sorting
    int f;  // -f : disable sorting, implies -a
    int g;  // -g : like -l but no owner name
    int d;  // -d : list directories themselves, not contents
    int G;  // -G : color output
} t_flags;

 
// init.c

void    init_flags(t_flags *f);


// parser.c

int set_flag(t_flags *f, char c);
int parse_flag(t_flags *f, char **argv);



#endif

