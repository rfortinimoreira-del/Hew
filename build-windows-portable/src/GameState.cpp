#include "GameState.h"
#include "Block.h"

GameMode GameState::currentMode = GameMode::EXPLORING;
bool GameState::showUI = true;
int GameState::selectedBlockType = static_cast<int>(BlockType::STONE);

void GameState::toggleBuildMode() {
    if (currentMode == GameMode::EXPLORING) {
        currentMode = GameMode::BUILDING;
    } else if (currentMode == GameMode::BUILDING) {
        currentMode = GameMode::EXPLORING;
    }
}

void GameState::selectNextBlockType() {
    selectedBlockType++;
    if (selectedBlockType > static_cast<int>(BlockType::GLOWING)) {
        selectedBlockType = static_cast<int>(BlockType::STONE);
    }
}

void GameState::selectPreviousBlockType() {
    selectedBlockType--;
    if (selectedBlockType < static_cast<int>(BlockType::STONE)) {
        selectedBlockType = static_cast<int>(BlockType::GLOWING);
    }
}
