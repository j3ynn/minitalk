NAME_CLIENT = client
# NAME_SERVER = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = ./
SRC_DIR = ./talk/
UTILS_DIR = ./utils/

SRC_CLIENT = $(SRC_DIR)client.c
SRC_SERVER = $(SRC_DIR)server.c
UTILS = $(UTILS_DIR)ft_for_nbr.c $(UTILS_DIR)ft_for_str.c $(UTILS_DIR)ft_printf.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_UTILS = $(UTILS:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS)
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(OBJ_UTILS)
	@echo "$(GREEN)Client compilato con successo!$(RESET)"

$(NAME_SERVER): $(OBJ_SERVER) $(OBJ_UTILS)
	@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(OBJ_UTILS)
	@echo "$(GREEN)Server compilato con successo!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
	@echo "$(YELLOW)Compilazione di $<...$(RESET)"

clean:
	@rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_UTILS)
	@echo "$(GREEN)Pulizia dei file oggetto completata.$(RESET)"

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@echo "$(GREEN)Pulizia degli eseguibili completata.$(RESET)"

re: fclean all

.PHONY: all clean fclean re