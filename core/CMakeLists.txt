add_library(core
        AppManager.cc AppManager.h
        Window.h
        )


target_link_libraries(core PUBLIC graphics)

