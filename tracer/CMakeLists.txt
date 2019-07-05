set(EXE_TARGET_NAME tracer)

set(${EXE_TARGET_NAME}_SRC
        src/main.cpp
        src/camera.cpp
        src/colormap.cpp
        src/embree.cpp
        src/hit.cpp
        src/image.cpp
        src/sphere.cpp
        src/stl.cpp
        )

include_directories(src)

add_executable(${EXE_TARGET_NAME} ${${EXE_TARGET_NAME}_SRC})

install(TARGETS ${EXE_TARGET_NAME} DESTINATION bin)
