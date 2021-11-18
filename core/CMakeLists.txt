add_library(core
        AppManager.cc AppManager.h
        GameWindow.h
        )


target_link_libraries(core LINK_PUBLIC graphics)

