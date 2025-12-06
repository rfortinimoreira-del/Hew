#pragma once

enum class GameMode {
    EXPLORING,
    BUILDING,
    PAUSED
};

class GameState {
public:
    static GameMode currentMode;
    static bool showUI;
    static int selectedBlockType;
    
    static void toggleBuildMode();
    static void selectNextBlockType();
    static void selectPreviousBlockType();
};
