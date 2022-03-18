CC	=	g++
# Adapt the variables below to your needs:
EXE	=	asteroid
CPP	=	main.cpp	playground.cpp	player.cpp	asteroid.cpp	missile.cpp
HPP	=	playground.hpp	player.hpp	asteroid.hpp	missile.hpp	constants.hpp

# The default is build the executable file:
default: $(EXE)

# The executable file must be rebuilt if source files changed:
$(EXE): $(CPP) $(HPP)
	$(CC) $(CPP) -o $(EXE)

# Run of the (always up-to-date) executable:
run: $(EXE)
	./$(EXE)

# Count the number of lines of code:
nblines:
	@wc -l $(CPP) $(HPP)
