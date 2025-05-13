# Compiler
CXX = g++

# Paths
SDL2_PATH = C:\Library\SDL2-2.30.8\x86_64-w64-mingw32

# Flags für Include- und Library-Pfade
CFLAGS = -I $(SDL2_PATH)/include
LDFLAGS = -L $(SDL2_PATH)/lib

# Libraries und Optionen
LIBS = -static -lmingw32 -lSDL2main -lSDL2 -Wl,--no-undefined -lm \
	   -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 \
	   -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc -lhid -lsetupapi

# Code Dateien
SRCS = src/main.cpp

# Output-Verzeichnis
OUTPUT_DIR = output

# Ziel-Datei
TARGET = $(OUTPUT_DIR)/$(basename $(notdir $(firstword $(SRCS)))).exe

# output/NAME.exe wird die Datei
all: $(OUTPUT_DIR) $(TARGET)

# Output Ordner erstellen
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Regel zum Erstellen des Targets
$(TARGET): $(SRCS) $(DEPS)
	@echo "Erstelle $(TARGET)..."
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(SRCS) $(LIBS)

# Abhängigkeiten (Dependencies)
DEPS = $(SRCS:.cpp=.d)

%.d: %.cpp
	@$(CXX) $(CFLAGS) -MM $< > $@

-include $(DEPS)

# Bereinigt die erzeugten Dateien
clean:
	rm -f $(TARGET) $(DEPS)

# Neu bauen
rebuild: clean all