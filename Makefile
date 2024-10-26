# Nom de l'exécutable
TARGET = shellbrunbaix

# Compilateur
CC = gcc

# Options du compilateur
CFLAGS = -Wall -Wextra -Werror -std=c11

# Dossiers
SRCDIR = src
INCDIR = include

# Fichiers sources
SRC = $(wildcard $(SRCDIR)/*.c)

# Fichiers objets
OBJ = $(SRC:.c=.o)

# Règle par défaut
all: $(TARGET)

# Règle pour l'exécutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ $^

# Règle pour les fichiers objets
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean
