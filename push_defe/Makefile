#-----------Dichiarazione di nomi e percorsi in variabili
NAME        := push_swap
LIB        	:= ft
LIB_TARGET 	:= libft/libft.a
INCS        := \
	./include
SRC_DIR     := src
#-----------File da compilare per push_swap
SRCS        := \
				ft_push_swap.c \
				ft_check_token.c \
				ft_error.c \
				ft_last_rotate.c \
				ft_lis_crcl.c \
				ft_lis_lin.c \
				ft_lis_utils.c \
				ft_lis.c \
				main.c \
				ft_moves_p.c \
				ft_moves_r.c \
				ft_moves_s.c \
				ft_obm_score_utils.c \
				ft_obm_score.c \
				ft_push_best.c \
				ft_set_index.c \
				ft_set_list.c \
				ft_set_obm_dist_utils.c \
				ft_set_obm_dist.c \
				ft_set_swap.c \
				ft_split_input_into_token.c \
				ft_swapswap.c
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
#-----------File da compilare per checker
CHECKER		:= \
	src/ft_error.c \
	src/ft_split_input_into_token.c \
	src/ft_check_token.c \
	src/ft_set_list.c \
	src/ft_moves_p.c \
	src/ft_moves_r.c \
	src/ft_moves_s.c \
	src/bonus/ft_parse_moves.c \
	src/bonus/ft_stacks_are_cool.c \
	src/bonus/ft_checker.c

BUILD_DIR   := .build
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
#-----------tutti i file .o vengono inseriti nella cartella nascosta .build. vengono compilati anche file .d che contengono i link delle dipendenze
CC          := clang
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIB_TARGET)))
LDLIB      	:= $(addprefix -l,$(LIB))
#-----------clang alternativa a cc o gcc. il resto sono flag per includere librerie
RM          := rm -rf
MAKEFLAGS   := --no-print-directory # non stampa le entrate e le uscite dalle directory per compilazione file
DIR_DUP     = mkdir -p $(@D) #chiedere a chatgpt, lunga da spiegare

.PHONY: clean fclean re
.SILENT: #esegue il makefile in maniera silenziosa, non stampa nulla

# Rules ----------------------------------------------------------------------->

all: banner $(NAME)

$(NAME): $(OBJS) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIB) -o $(NAME)
	${info }
	${info ${BOLD}Creating  -> ${RED}$(NAME)${NO_COLOR}}
	${info }

$(LIB_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	${info ${BOLD}Compiling -> ${BLUE}$@${NO_COLOR}}

-include $(DEPS)

clean:
	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(BUILD_DIR)
	$(RM) checker.d
	${info }
	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR}}

fclean: clean
	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)
	$(RM) checker

re:
	$(MAKE) fclean
	$(MAKE) all

bonus: banner $(LIB_TARGET)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(CHECKER) $(LDFLAGS) $(LDLIB) -o checker
	${info ${BOLD}Creating  -> ${BLUE}checker${NO_COLOR}}

# Style ----------------------------------------------------------------------->

RED 		:= ${shell tput setaf 1}
YELLOW		:= ${shell tput setaf 3}
BLUE		:= ${shell tput setaf 4}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

banner:
	@echo '${RED}                                                      '
	@echo '                                      /\\\                  '
	@echo '                                      \/\\\                 '
	@echo '/\\\\\\\\\                             \/\\\                '
	@echo '/\\\/////\\\  /\\\    /\\\  /\\\\\\\\\\ \/\\\               '
	@echo '\/\\\\\\\\\\  \/\\\   \/\\\ \/\\\//////  \/\\\\\\\\\\       '
	@echo ' \/\\\//////   \/\\\   \/\\\ \/\\\\\\\\\\ \/\\\/////\\\     '
	@echo '  \/\\\         \/\\\   \/\\\ \////////\\\ \/\\\   \/\\\    '
	@echo '   \/\\\         \//\\\\\\\\\   /\\\\\\\\\\ \/\\\   \/\\\   '
	@echo '    \///           \/////////   \//////////  \///    \///   '
	@echo '                                                /\\\\\\\\\  '
	@echo '  /\\\\\\\\\\  /\\    /\\   /\\  /\\\\\\\\\     /\\\/////\\\'
	@echo '  \/\\\//////  \/\\\  /\\\\ /\\\ \////////\\\   \/\\\\\\\\\\'
	@echo '   \/\\\\\\\\\\ \//\\\/\\\\\/\\\    /\\\\\\\\\\  \/\\\//////'
	@echo '    \////////\\\  \//\\\\\/\\\\\    /\\\/////\\\  \/\\\     '
	@echo '      /\\\\\\\\\\   \//\\\\//\\\    \//\\\\\\\\/\\ \/\\\    '
	@echo '      \//////////     \///  \///      \////////\//  \///    '
	@echo ''
	@echo '            ✨ ${BOLD}push_swap ✨'
	@echo '${NO_COLOR}'

# ------------------------------------------------------------------------------

monna:
	@echo '                                  _______'
	@echo '                           _,,ad8888888888bba,_'
	@echo '                        ,ad88888I888888888888888ba,'
	@echo '                      ,88888888I88888888888888888888a,'
	@echo '                    ,d888888888I8888888888888888888888b,'
	@echo '                   d88888PP"""" ""YY88888888888888888888b,'
	@echo '                 ,d88""__,,--------,,,,.;ZZZY8888888888888,'
	@echo '                ,8IIl"                ;;l"ZZZIII8888888888,'
	@echo '               ,I88l;;                  ;lZZZZZ888III8888888,'
	@echo '             ,II88Zl;.                  ;llZZZZZ888888I888888,'
	@echo '            ,II888Zl;.                .;;;;;lllZZZ888888I8888b'
	@echo '           ,II8888Z;;                 `;;;;;""llZZ8888888I8888,'
	@echo '           II88888Z;;                        .;lZZZ8888888I888b'
	@echo '           II88888Z; _,aaa,      .,aaaaa,__.l;llZZZ88888888I888'
	@echo '           II88888IZZZZZZZZZ,  .ZZZZZZZZZZZZZZ;llZZ88888888I888,'
	@echo '           II88888IZZ<"(@@>Z|  |ZZZ<"(@@>ZZZZ;;llZZ888888888I88I'
	@echo '          ,II88888;   `""" ;|  |ZZ; `"""     ;;llZ8888888888I888'
	@echo '          II888888l            `;;          .;llZZ8888888888I888,'
	@echo '         ,II888888Z;           ;;;        .;;llZZZ8888888888I888I'
	@echo '         III888888Zl;    ..,   `;;       ,;;lllZZZ88888888888I888'
	@echo '         II88888888Z;;...;(_    _)      ,;;;llZZZZ88888888888I888,'
	@echo '         II88888888Zl;;;;;"" `--"Z;.   .,;;;;llZZZZ88888888888I888b'
	@echo '         ]I888888888Z;;;;""   ";llllll;..;;;lllZZZZ88888888888I8888,'
	@echo '         II888888888Zl.;;"Y88bd888P";;,..;lllZZZZZ88888888888I8888I'
	@echo '         II8888888888Zl;.; `"PPP";;;,..;lllZZZZZZZ88888888888I88888'
	@echo '         II888888888888Zl;;. `;;;l;;;;lllZZZZZZZZW88888888888I88888'
	@echo '         `II8888888888888Zl;.    ,;;lllZZZZZZZZWMZ88888888888I88888'
	@echo '          II8888888888888888ZbaalllZZZZZZZZZWWMZZZ8888888888I888888,'
	@echo '          `II88888888888888888b"WWZZZZZWWWMMZZZZZZI888888888I888888b'
	@echo '           `II88888888888888888;ZZMMMMMMZZZZZZZZllI888888888I8888888'
	@echo '            `II8888888888888888 `;lZZZZZZZZZZZlllll888888888I8888888,'
	@echo '             II8888888888888888, `;lllZZZZllllll;;.Y88888888I8888888b,'
	@echo '            ,II8888888888888888b   .;;lllllll;;;.;..88888888I88888888b,'
	@echo '            II888888888888888PZI;.  .`;;;.;;;..; ...88888888I8888888888,'
	@echo '            II888888888888PZ;; ;;.   ;. .;.  .;. .. Y8888888I88888888888b,'
	@echo '           ,II888888888PZ;;                         `8888888I8888888888888b,'
	@echo '           II888888888                               888888I8888888888888888b'
	@echo '          ,II888888888                              ,888888I88888888888888888'
	@echo '         ,d88888888888                              d888888I8888888888ZZZZZZZ'
	@echo '      ,ad888888888888I                              8888888I8888ZZZZZZZZZZZZZ'
	@echo '    ,d888888888888888                               888888IZZZZZZZZZZZZZZZZZZ'
	@echo '  ,d888888888888P 8P                                Y888ZZZZZZZZZZZZZZZZZZZZZ'
	@echo ' ,8888888888888,  "                                 ,ZZZZZZZZZZZZZZZZZZZZZZZZ'
	@echo 'd888888888888888,                                ,ZZZZZZZZZZZZZZZZZZZZZZZZZZZ'
	@echo '888888888888888888a,      _                    ,ZZZZZZZZZZZZZZZZZZZZ888888888'
	@echo '888888888888888888888ba,_d                   ,ZZZZZZZZZZZZZZZZZ88888888888888'
	@echo '8888888888888888888888888888bbbaaa,,,______,ZZZZZZZZZZZZZZZ888888888888888888'
	@echo '88888888888888888888888888888888888888888ZZZZZZZZZZZZZZZ888888888888888888888'
	@echo '8888888888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888'
	@echo '888888888888888888888888888888888888888ZZZZZZZZZZZZZZ888888888888888888888888'
	@echo '8888888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888888'
	@echo '88888888888888888888888888888888888ZZZZZZZZZZZZZZ8888888888888888888888888888'
	@echo '8888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888888888'
	@echo '88888888888888888888888888888888ZZZZZZZZZZZZZZ8888888888888888888888888888888'
	@echo '8888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888888888888'
	@echo ''