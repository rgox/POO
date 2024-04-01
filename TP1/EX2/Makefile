# Nom du fichier exécutable
TARGET = Ex2

# Compilateur
CC = g++

# Options de compilation
CFLAGS = -Wall -Wextra -std=c++11

# Fichiers source
SRC = image.cpp main.cpp filtreAddition.cpp filtre.cpp filtreMoyenne.cpp suiteDeFiltre.cpp

# Règle de construction par défaut
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Nettoyage
clean:
	rm -f $(TARGET)
