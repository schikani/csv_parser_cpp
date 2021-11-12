set(EXEC app)

include_directories(./inc)

file(GLOB SOURCES_C ./src/*.c)
file(GLOB SOURCES_CPP ./src/*.cpp)


add_executable(${EXEC} ${SOURCES_C} ${SOURCES_CPP})





