cmake_minimum_required(VERSION 3.14)
project(Realtime-video-using-FFmpeg-cpp C CXX)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/glfw)


list(APPEND SOURCES
    src/main.cpp
)

    set(CMAKE_EXE_LINKER_FLAGS "-std=gnu99 -static -static-libgcc -static-libstdc++ -lmwindow")

if(APPLE)
    list(APPEND EXTRA_LIBS
        "-framework OpenGL"
    )

    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/MacOSXBundleInfo.plist.in
        ${CMAKE_CURRENT_BINARY_DIR}/assets/MacOSXBundleInfo.plist
    )

    set_target_properties(Realtime-video-using-FFmpeg-cpp PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_BINARY_DIR}/assets/MacOSXBundleInfo.plist
    )

elseif(WIN32)
    list(APPEND EXTRA_LIBS
        "-lglu32 -lopengl32"
    )
else()
    list(APPEND EXTRA_LIBS
        "-lGL -lGLU -lX11"
    )
endif()
add_executable(Realtime-video-using-FFmpeg-cpp ${SOURCES})

target_link_libraries(Realtime-video-using-FFmpeg-cpp glfw ${EXTRA_LIBS}
     opengl32
)
