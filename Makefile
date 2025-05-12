# Compiler
CC = g++

# Flags für Include- und Library-Pfade --> Durch eure ändern (ab dem SDL2 Ordner sollte es gleich sein)
CFLAGS = -I M:\SDL2-devel-2.30.8-mingw\x86_64-w64-mingw32\include
LDFLAGS = -L M:\SDL2-devel-2.30.8-mingw\x86_64-w64-mingw32\lib

# Libraries und Optionen
LIBS = -static -lmingw32 -lSDL2main -lSDL2 -Wl,--no-undefined -lm \
       -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 \
       -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc -lhid -lsetupapi

# Code Dateien, nur die erste Datei vom Namen ändern --> NAME.CPP
# Für Unterordner einfach das Makefile in den Ordner packen wo die Ordner alle sind
# Dann einfach wie hier im Beispiel den Ordner und die Datei angeben. Die .exe wird jedoch in einen output-ordner erstellt.
SRCS = src/main.cpp

# Output-Verzeichnis
OUTPUT_DIR = output

# Ziel-Datei --> NAME.exe
TARGET = $(OUTPUT_DIR)/$(basename $(notdir $(firstword $(SRCS)))).exe

# output/NAME.exe wird die Datei
all: $(OUTPUT_DIR) $(TARGET)

# Output Ordner erstellen
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Regel zum Erstellen des Targets
$(TARGET): $(SRCS)
	@echo "Erstelle $(TARGET)..."
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(SRCS) $(LIBS)

# Bereinigt die erzeugten Dateien
clean:
	rm -f $(TARGET)

# Neu bauen
rebuild: clean all
