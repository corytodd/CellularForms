set(EXE_TARGET_NAME cli)

set(${EXE_TARGET_NAME}_SRC
        main.cpp
        gui.cpp
        index.cpp
        model.cpp
        program.cpp
        sphere.cpp
        stl.cpp
        triangle.cpp
        util.cpp
        )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Binary ------------------------------------------------------
add_executable(${EXE_TARGET_NAME} ${${EXE_TARGET_NAME}_SRC})

set(LINKED_LIBS)

# Windows OpenGL compat ----------------------------------------
if(WIN32)
    find_package(glad CONFIG REQUIRED)
    set(LINKED_LIBS ${LINKED_LIBS} glad::glad)
endif(WIN32)

# Dependencies -------------------------------------------------
find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(Boost REQUIRED REQUIRED)

target_link_libraries(${EXE_TARGET_NAME} PRIVATE
        glm
        glfw
        ${Boost_LIBRARIES}
        ${LINKED_LIBS}
        )
target_include_directories(${EXE_TARGET_NAME} PRIVATE ${Boost_INCLUDE_DIRS})

install(TARGETS ${EXE_TARGET_NAME} DESTINATION bin)
