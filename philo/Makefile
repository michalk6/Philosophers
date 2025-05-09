NAME	= philo

SRCDIR 	= srcs
INCDIR 	= inc
HEADER	= philosophers.h

SRCS	=	$(SRCDIR)/init_data \
			$(SRCDIR)/philosophers \
			$(SRCDIR)/utils \
			$(SRCDIR)/free_data \
			$(SRCDIR)/feast \
			$(SRCDIR)/feast_philo_activities \

CC 		= cc
CFLAGS	= -Wall -Wextra -Werror -I $(INCDIR) -pthread

CFILES		= $(SRCS:%=%.c)
OFILES		= $(SRCS:%=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus