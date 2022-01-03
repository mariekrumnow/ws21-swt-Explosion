add_library(menu
        MenuWindow.cc MenuWindow.h
        MenuItem.cc MenuItem.h
        InstructionWindow.cc InstructionWindow.h
        GameOverWindow.cc GameOverWindow.h
        MainWindow.cc MainWindow.h
        )



target_link_libraries(menu PUBLIC game)